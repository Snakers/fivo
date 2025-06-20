#pragma once
#include "../../core/commandBase.hpp"
#include <iostream>
#include <curl/curl.h>
#include <sstream>

class Http : public Command<Http> {
public:
    void execute(const std::vector<std::string>& args) const {
        if (args.size() < 2) {
            std::cerr << "Usage:\n"
                      << "  http get <url>\n"
                      << "  http post <url> <json_body>\n"
                      << "  http put <url> <json_body>\n"
                      << "  http delete <url>\n";
            return;
        }

        std::string method = args[0];
        std::string url = args[1];
        std::string data = (args.size() > 2) ? args[2] : "";

        CURL* curl = curl_easy_init();
        if (!curl) {
            std::cerr << "Failed to initialize curl\n";
            return;
        }

        std::ostringstream response;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Set write callback
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, +[](char* ptr, size_t size, size_t nmemb, void* userdata) {
            std::ostringstream* stream = static_cast<std::ostringstream*>(userdata);
            stream->write(ptr, size * nmemb);
            return size * nmemb;
        });
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        if (method == "post") {
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        } else if (method == "put") {
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        } else if (method == "delete") {
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
        } else if (method != "get") {
            std::cerr << "Unknown method: " << method << "\n";
            curl_easy_cleanup(curl);
            return;
        }

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "Request failed: " << curl_easy_strerror(res) << "\n";
        } else {
            std::cout << "[Response]:\n" << response.str() << "\n";
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    static std::string command_name() { return "http"; }
    static std::string command_help() { return "Performs HTTP GET/POST/PUT/DELETE. Usage: http get|post|put|delete <url> [data]"; }
};
