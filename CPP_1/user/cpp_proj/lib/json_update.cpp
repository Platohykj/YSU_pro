#include <iostream>
#include <curl/curl.h>
#include <string>

int main() {
    // 初始化 libcurl
    curl_global_init(CURL_GLOBAL_ALL);

    // 创建 libcurl 句柄
    CURL *curl = curl_easy_init();
    if (curl) {
        // 设置请求 URL
        curl_easy_setopt(curl, CURLOPT_URL, "127.0.0.1:5000/receive_json");

        // 设置 POST 请求
        curl_easy_setopt(curl, CURLOPT_POST, 1L);

        // 创建 JSON 数据
        std::string json_data = "{\"key1\": \"value1\", \"key2\": \"value2\"}";

        // 设置请求主体数据
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data.c_str());

        // 设置请求头
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // 执行 HTTP 请求
        CURLcode res = curl_easy_perform(curl);

        // 检查是否发生错误
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        // 清理 libcurl 资源
        curl_easy_cleanup(curl);

        // 清理请求头资源
        curl_slist_free_all(headers);
    }

    // 清理 libcurl 全局资源
    curl_global_cleanup();

    return 0;
}
