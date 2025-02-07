#include <iostream>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

void* malloc(size_t size) {
    void *ptr;
    ptr = sbrk(0);

    if (sbrk(size) == (void*) - 1) return nullptr;
    return ptr;
}



int main() {
    auto p = malloc(5);
    cout << p << endl;
    return 0;
}
