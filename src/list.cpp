#include <iostream>
#include <string>
#include <cstddef>

template<typename T>
class Node {
public:
	T data;
	Node* next;
	
	Node(T data, Node* next) : data{data}, next{next} {}
};

template<typename T>
class List {
private:
	Node<T>* head_;
	size_t size_;

public:
	List() : head_{nullptr}, size_{0} {
		std::cout << "List constructor called" << std::endl;
	}; // constructor
	
	~List() {
		auto ptr = this->head_;
		while(ptr != nullptr) {
			auto next = ptr->next;
			delete ptr;
			ptr = next;
		}	
		std::cout << "List destructor called" << std::endl;
	} // destructor

	List(const List& other) {
		auto ptr = other.head_;
		while(ptr != nullptr) {
			this->pushBack(ptr->data);
			ptr = ptr->next;
		}
		std::cout << "List copy constructor called" << std::endl;
	} // copy constructor

	List& operator=(const List& other) {
		if (this == &other) {
			return *this;
		}
		auto ptr = other.head_;
		while(ptr != nullptr) {
			this->pushBack(ptr->data);
			ptr = ptr->next;
		}
		std::cout << "List copy assignment operator called" << std::endl;
		return *this;
	} // copy assignment operator
	
	List(List&& other): head_{other.head_}, size_{other.size_} {
		other.head_ = nullptr;
		other.size_ = 0;
		std::cout << "List move constructor called" << std::endl;
	} // move constructor
	
	List& operator=(List&& other) {
		if (this == &other) {
			return *this;
		}
		this->head_ = other.head_;
		this->size_ = other.size_;
		other.head_ = nullptr;
		other.size_ = 0;
		std::cout << "List move assignment operator called" << std::endl;
		return *this;
	} // move assignment operator

	Node<T>* getHead() const;
	Node<T>* getTail() const;
	size_t getSize() const;
	void pushFront(const T& data);
	void pushBack(const T& data);
	// void popFront();
	// void popBack();
	// void insert(int data, size_t index);
	// void erase(size_t index);
	// void reverse();
	// void sort();
	// void remove(int data);
	// void unique();
	// void splice(size_t index, List& other);
	// void swap(List& other);

	List& operator+(const List& other);
	List& operator+=(const List& other);

	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const List<U>& list);
};

template<typename T>
Node<T>* List<T>::getHead() const {
	return this->head_;
}

template<typename T>
Node<T>* List<T>::getTail() const {
	auto ptr = this->head_;
	if (ptr == nullptr) {
		return nullptr;
	}
	while(ptr->next != nullptr) {
		ptr = ptr->next;
	}
	return ptr;
}

template<typename T>
size_t List<T>::getSize() const {
	return this->size_;
}

template<typename T>
void List<T>::pushFront(const T& data) {
	auto new_node = new Node<T>{data, this->head_};
	this->head_ = new_node;
	return;
}

template<typename T>
void List<T>::pushBack(const T& data) {
	if (this->head_ == nullptr) {
		this->pushFront(data);
		return;
	}
	auto tail = this->getTail();
	auto new_node = new Node<T>{data, nullptr};
	tail->next = new_node;
	return;
}

// void insert(int data, size_t index);
// void erase(size_t index);
// void reverse();
// void sort();
// void remove(int data);
// void unique();
// void splice(size_t index, List& other);
// void swap(List& other);

template<typename T>
List<T>& List<T>::operator+(const List<T>& other) {
	auto tail = this->getTail();
	tail->next = std::move(other.head_);
	return *this;
}

template<typename T>
List<T>& List<T>::operator+=(const List<T>& other) {
	auto tail = this->getTail();
	tail->next = std::move(other.head_);
	return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const List<T>& list) {
	auto ptr = list.head_;
	while(ptr != nullptr) {
		os << ptr->data << " ";
		ptr = ptr->next;
	}
	return os;
}


int main() {
	List<std::string> list1, list2;
	list1.pushBack("Hi there |");
	list2.pushBack("How are you?");
	list1 += list2;
	std::cout << list1<< std::endl;

	return 0;
}