#include <map>
#include <mutex>
#include <string>
#include <thread>
#include <iostream>

void add_page(std::map<std::string, std::string>& g_pages, std::mutex& lock, const std::string& url) {
    std::lock_guard<std::mutex> guard(lock);
    g_pages[url] = "fake data";
    return;
}

int main() {
    std::map<std::string, std::string> g_pages;
    std::mutex lock;

    std::thread t1(add_page, std::ref(g_pages), std::ref(lock), "http://foo");
    std::thread t2(add_page, std::ref(g_pages), std::ref(lock), "http://bar");
    t1.join();
    t2.join();

    for (const auto& page: g_pages) {
        std::cout << page.first << " => " << page.second << '\n';
    }

  return 0;
}