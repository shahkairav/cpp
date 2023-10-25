#include <iostream>
#include <vector>
using namespace std;

class String {
    char* m_Buffer;
    size_t m_Size;

public:
    // Constructor
    String(const char* string) {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0;
    }

    // Copy constructor
    String(const String& string) : m_Size(string.m_Size) {
        cout << "Copied!" << endl;
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string.m_Buffer, m_Size + 1);
    }

    // Move constructor
    String(String&& string): m_Size(string.m_Size), m_Buffer(string.m_Buffer) {
        cout << "Moved!" << endl;
        string.m_Size = 0;
        string.m_Buffer = nullptr;
    }

    // Index operator
    char& operator[](unsigned int index) {
        return m_Buffer[index];
    }

    // Destructor    
    ~String() {
        delete[] m_Buffer;
    }

    // Output operator overloading
    friend ostream& operator<<(ostream& stream, const String& string);
};

ostream& operator<<(ostream& stream, const String& string) {
    stream << string.m_Buffer;
    return stream;
}

int main() {
    vector<String> vec;
    String s1("Hi there");
    String s2 = s1;
    s2[2] = ':';
    cout << s1 << endl;
    cout << s2 << endl;

    vec.reserve(3);
    vec.push_back(std::move(s1));
    vec.push_back(static_cast<String&&>(s2));

    return 0;
}