// Forward declarations of C functions
extern "C" {
    #include <config/kube_config.h>
    #include <api/CoreV1API.h>
    #include <api/AuthenticationV1API.h>
    #include <model/v1_token_review_spec.h>
    #include <model/v1_token_review.h>
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

    std::string validateSvcAccountToken(std::string token, const std::string& namespaceName = "default") {
        // Create a non-const copy of the namespace string
        char* namespace_copy = strdup(namespaceName.c_str());
        if (!namespace_copy) {
            throw std::runtime_error("Memory allocation failed");
        }
        char *service_account_name = strdup("bookinfo-ratings");

        char *tokenn = strdup(token.c_str());
        v1_token_review_spec_t *spec = v1_token_review_spec_create(NULL, tokenn);
        
        v1_token_review_t *token_review = v1_token_review_create(NULL, NULL, NULL, spec, NULL);

        v1_token_review_t *result = AuthenticationV1API_createTokenReview(apiClient, token_review, NULL, NULL, NULL, NULL);

        // Check the result
        if (result && result->status && result->status->authenticated) {
            std::cout << "Token is valid for user " << result->status->user->username << std::endl;
        } else {
            std::cerr << "Token is invalid or authentication failed" << std::endl;
        }

        // Clean up
        free(result);
        v1_token_review_free(token_review);
        free(namespace_copy);

        return result && result->status && result->status->authenticated ? result->status->user->username : "";
    }
};



int main() {
    try {
        KubernetesClient client;
        client.listPods();
        std::string token = "eyJhbGciOiJSUzI1NiIsImtpZCI6IlpaNHVZRmE5VXBTckEzX0ZEc2NiT2Q3RTJOckFYNHVLSnlEQmp4S0RJRHcifQ.eyJhdWQiOlsiaHR0cHM6Ly9rdWJlcm5ldGVzLmRlZmF1bHQuc3ZjLmNsdXN0ZXIubG9jYWwiXSwiZXhwIjoxNzY3NjUyMjUzLCJpYXQiOjE3MzYxMTYyNTMsImlzcyI6Imh0dHBzOi8va3ViZXJuZXRlcy5kZWZhdWx0LnN2Yy5jbHVzdGVyLmxvY2FsIiwianRpIjoiNzY5MmEzZWEtMDMwZC00ZTk0LTlmOTctOWVjODc4YTc5YzE4Iiwia3ViZXJuZXRlcy5pbyI6eyJuYW1lc3BhY2UiOiJkZWZhdWx0Iiwibm9kZSI6eyJuYW1lIjoibWluaWt1YmUiLCJ1aWQiOiJmMjY4NDVhOS1jZjk0LTQ1NTMtYWJlZS1iOTg4NTMzYWY4NDgifSwicG9kIjp7Im5hbWUiOiJyYXRpbmdzLXYxLTY5NjRkNTg0ZDktcDRncjQiLCJ1aWQiOiIyM2FjZmI5NC05M2RhLTRiYzMtOTE4MS1iZmI4MjdhZmRiN2YifSwic2VydmljZWFjY291bnQiOnsibmFtZSI6ImJvb2tpbmZvLXJhdGluZ3MiLCJ1aWQiOiI5ODUwMzg1Zi04NWQ4LTQ2ZWQtYWY0My00ZmUzMWJiNWJlOTUifSwid2FybmFmdGVyIjoxNzM2MTE5ODYwfSwibmJmIjoxNzM2MTE2MjUzLCJzdWIiOiJzeXN0ZW06c2VydmljZWFjY291bnQ6ZGVmYXVsdDpib29raW5mby1yYXRpbmdzIn0.cVKmbF5fJeo07fzuQcDBZMv_rPHENn5jQVmGGsv1P0-0VcFWaraAjmSa-1WE6xHUz9JzGpRH0M9_eYT655LRtYnsEn_R9TrdjOkHSPkXGxsxKEIpqJ7N16zonUMLYICG9_AJXJmo9vm2YBvb_AsReY4aBFhuM0j-lepkU5rfFfmAyNn1ltmYF3p2dj9RlAWN15f1PB_aF8urCieJvozq0iEN2ShlLcL-XvRV7Dq1uyeelxMIfA3YRKlSNMcisVSBAfGQ-qEyCc06oCplNQhwbuptt_44zeBAfHaDw2pmOZVh9xdSSTpalpqoX7RLdcGh3jlujsGw4NHmxm6hLxPuCA";
        std::string username = client.validateSvcAccountToken(token);
        std::cout << "Validated username: " << username << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}