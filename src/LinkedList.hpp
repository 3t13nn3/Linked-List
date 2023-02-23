#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <ostream>
#include <stdexcept>

namespace linked {
template <typename T> class LinkedList {

	struct Node {
		T data_;
		Node *previous_;
		Node *next_;
	};

  public:
	LinkedList();

	~LinkedList();

	size_t Size();

	void Push(T data);

	void Insert(T data, size_t index);

	T Remove(size_t index);

	bool Empty();

	void Clear();

	T &operator[](size_t index);

	void Swap(size_t index1, size_t index2);

	void Reverse();

	// Define Iterator to browse our list
	class Iterator {
	  private:
		Node *current_;

	  public:
		Iterator(Node *current) : current_(current) {}

		bool operator!=(const Iterator &other) const {
			return current_ != other.current_;
		}

		T &operator*() const { return current_->data_; }

		Iterator &operator++() {
			current_ = current_->next_;
			return *this;
		}
	};

	Iterator begin() const;

	Iterator end() const;

	std::ostream &operator<<(std::ostream &os);

  private:
	Node *root_;
	Node *tail_;
	size_t size_;
};

// Constructor
template <typename T>
LinkedList<T>::LinkedList()
	: root_{new Node{T(), nullptr, nullptr}}, tail_{root_}, size_{0} {}

// Destructor
template <typename T> LinkedList<T>::~LinkedList() {
	this->Clear();
	delete root_;
}

// Methods
template <typename T> size_t LinkedList<T>::Size() { return size_; }

template <typename T> void LinkedList<T>::Push(T data) {
	Node *new_node = new Node{data, tail_, nullptr};
	if (root_->next_ == nullptr) {
		root_->next_ = new_node;
	} else {
		tail_->next_ = new_node;
	}
	tail_ = new_node;
	++size_;
}

template <typename T> void LinkedList<T>::Insert(T data, size_t index) {
	if (index > this->Size()) {
		throw std::out_of_range("Index out of range during insertion");
	}

	// Browse our list until we are to the index position
	Node *current = root_;
	for (size_t i = 0; i < index; ++i) {
		current = current->next_;
	}
	Node *new_node = new Node{data, current, current->next_};

	current->next_ = new_node;

	if (new_node->next_ == nullptr) {
		tail_ = new_node;
	} else {
		new_node->next_->previous_ = new_node;
	}
	++size_;
}

template <typename T> T LinkedList<T>::Remove(size_t index) {
	if (index >= size_) {
		throw std::out_of_range("Index out of range during removing");
	}

	// Browse our list until we are to the index position
	Node *current = root_;
	for (size_t i = 0; i < index + 1; ++i) {
		current = current->next_;
	}

	if (current == tail_) {
		tail_ = current->previous_;
	}

	current->previous_->next_ = current->next_;
	if (current->next_ != nullptr) {
		current->next_->previous_ = current->previous_;
	}

	T data = current->data_;
	delete current;
	--size_;

	return data;
}

template <typename T> bool LinkedList<T>::Empty() {
	return size_ > 0 ? false : true;
}

template <typename T> void LinkedList<T>::Clear() {
	Node *current = root_->next_;
	while (current != nullptr) {
		Node *temp = current;
		current = current->next_;
		delete temp;
	}
	root_->next_ = nullptr;
	tail_ = nullptr;
	size_ = 0;
}

template <typename T> T &LinkedList<T>::operator[](size_t index) {
	if (index >= size_) {
		throw std::out_of_range("Index out of range during removing");
	}

	Node *current = root_;
	for (size_t i = 0; i < index + 1; ++i) {
		current = current->next_;
	}
	return current->data_;
}

template <typename T> void LinkedList<T>::Swap(size_t index1, size_t index2) {
	if (index1 >= size_ || index2 >= size_) {
		throw std::out_of_range("Index out of range during swapping");
	}
	T temp = (*this)[index1];
	(*this)[index1] = (*this)[index2];
	(*this)[index2] = temp;
}

template <typename T> void LinkedList<T>::Reverse() {
	size_t n = size_ / 2;
	for (size_t i(0); i < n; ++i) {
		this->Swap(i, size_ - i - 1);
	}
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin() const {
	return Iterator(root_->next_);
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end() const {
	return Iterator(nullptr);
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list) {
	os << "{";
	for (auto it = list.begin(); it != list.end(); ++it) {
		os << *it << ", ";
	}

	if (list.begin() != list.end()) {
		os << "\b\b";
	}
	os << "}";

	return os;
}

} // namespace linked

#endif
