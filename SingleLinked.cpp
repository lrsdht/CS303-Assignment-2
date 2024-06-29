#include "Single_Linked_List.h"
#include <stdexcept>

template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = tail = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
    ++num_items;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    ++num_items;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (empty()) {
        throw out_of_range("List is empty");
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    --num_items;
    if (num_items == 0) {
        tail = nullptr;
    }
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (empty()) {
        throw out_of_range("List is empty");
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    --num_items;
}

template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::front() {
    if (empty()) {
        throw out_of_range("List is empty");
    }
    return head->data;
}

template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::back() {
    if (empty()) {
        throw out_of_range("List is empty");
    }
    return tail->data;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return num_items == 0;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index > num_items) {
        index = num_items;  // Insert at the end if index is out of bounds
    }
    if (index == 0) {
        push_front(item);
    } else if (index == num_items) {
        push_back(item);
    } else {
        Node* new_node = new Node(item);
        Node* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        ++num_items;
    }
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items) {
        return false;  // Index out of bounds
    }
    if (index == 0) {
        pop_front();
    } else {
        Node* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        --num_items;
    }
    return true;
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node* current = head;
    size_t index = 0;
    while (current) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        ++index;
    }
    return num_items;  // Item not found
}
