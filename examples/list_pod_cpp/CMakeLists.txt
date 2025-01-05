cmake_minimum_required(VERSION 3.10)
project(k8s_cpp_client)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set paths
set(KUBERNETES_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../kubernetes")
set(KUBERNETES_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../kubernetes/build")

# Find required packages
find_package(yaml-cpp REQUIRED)
find_package(LibWebsockets REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)
find_package(CURL REQUIRED)

# Add the executable
add_executable(list_pod_cpp main.cpp)

# Include directories - make sure includes work with C code
target_include_directories(list_pod_cpp 
    PRIVATE 
    ${KUBERNETES_INCLUDE_DIR}
    ${KUBERNETES_INCLUDE_DIR}/include
    ${LIBWEBSOCKETS_INCLUDE_DIRS}
)

# Link directories
link_directories(${KUBERNETES_LIB_DIR} /usr/local/lib)

# Link libraries - note order matters for static linking
target_link_libraries(list_pod_cpp 
    PRIVATE 
    -L${KUBERNETES_LIB_DIR}
    -lkubernetes
    -lyaml
    -lwebsockets
    -lcurl
    -lssl
    -lcrypto
    -lz
)

# Ensure rpath is set correctly for the executable
set_target_properties(list_pod_cpp PROPERTIES
    BUILD_WITH_INSTALL_RPATH TRUE
    INSTALL_RPATH "${KUBERNETES_LIB_DIR}:/usr/local/lib"
)

# Add compiler definitions to handle C/C++ linking properly
target_compile_definitions(list_pod_cpp PRIVATE __cplusplus)