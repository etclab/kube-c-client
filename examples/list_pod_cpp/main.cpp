// Forward declarations of C functions we'll use
extern "C" {
    #include <config/kube_config.h>
    #include <api/CoreV1API.h>
}

#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstring>

class KubernetesClient {
private:
    char* basePath;
    sslConfig_t* sslConfig;
    list_t* apiKeys;
    apiClient_t* apiClient;

public:
    KubernetesClient() : basePath(nullptr), sslConfig(nullptr), apiKeys(nullptr), apiClient(nullptr) {
        int rc = load_kube_config(&basePath, &sslConfig, &apiKeys, nullptr);
        if (rc != 0) {
            throw std::runtime_error("Cannot load kubernetes configuration");
        }

        apiClient = apiClient_create_with_base_path(basePath, sslConfig, apiKeys);
        if (!apiClient) {
            free_client_config(basePath, sslConfig, apiKeys);
            throw std::runtime_error("Cannot create kubernetes client");
        }
    }

    ~KubernetesClient() {
        if (apiClient) {
            apiClient_free(apiClient);
        }
        free_client_config(basePath, sslConfig, apiKeys);
        apiClient_unsetupGlobalEnv();
    }

    void listServiceAccounts(){
        char* namespace_copy = strdup("default");
    }

    void listPods(const std::string& namespaceName = "default") {
        // Create a non-const copy of the namespace string
        char* namespace_copy = strdup(namespaceName.c_str());
        if (!namespace_copy) {
            throw std::runtime_error("Memory allocation failed");
        }

        v1_pod_list_t* pod_list = CoreV1API_listNamespacedPod(
            apiClient,
            namespace_copy,  // namespace (now non-const)
            nullptr,  // pretty
            nullptr,  // allowWatchBookmarks
            nullptr,  // continue
            nullptr,  // fieldSelector
            nullptr,  // labelSelector
            nullptr,  // limit
            nullptr,  // resourceVersion
            nullptr,  // resourceVersionMatch
            nullptr,  // sendInitialEvents
            nullptr,  // timeoutSeconds
            nullptr   // watch
        );

        // Free the copied string
        free(namespace_copy);

        std::cout << "The return code of HTTP request: " << apiClient->response_code << std::endl;

        if (pod_list) {
            std::cout << "Pod list:" << std::endl;
            listEntry_t* listEntry = nullptr;
            v1_pod_t* pod = nullptr;
            
            list_ForEach(listEntry, pod_list->items) {
                pod = static_cast<v1_pod_t*>(listEntry->data);
                std::cout << "\tPod name: " << pod->metadata->name << std::endl;
                std::cout << pod->metadata->uid << std::endl;
            }

            v1_pod_list_free(pod_list);
        } else {
            std::cout << "Cannot get any pods." << std::endl;
        }


    }
};

int main() {
    try {
        KubernetesClient client;
        client.listPods();
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}