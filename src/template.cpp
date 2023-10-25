#include <vector>
#include <string>
#include <iostream>

template<typename C, typename V> 
std::vector<typename C::iterator> find_all(C& c, V v) {
    std::vector<typename C::iterator> res;
    for (auto p = c.begin(); p!=c.end(); ++p)
        if (*p == v) res.push_back(p);
    return res; 
}

int main() {
    std::string s {"Hi there"};
    auto vec = find_all(s, 'h');
    for(auto x: vec) {
        std::cout << *x << std::endl;
    }
    return 0;
}