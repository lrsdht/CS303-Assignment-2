#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H
#include <iostream>
#include <iomanip>
#include <cstddef>  // for size_t

using namespace std;

template <typename Item_Type>
class Single_Linked_List {
private:
    struct Node {
        Item_Type data;
        Node* next;

        Node(const Item_Type& item) : data(item), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t num_items;

public:
    Single_Linked_List();
    ~Single_Linked_List();

    // Member functions
    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    void pop_front();
    void pop_back();
    Item_Type& front();
    Item_Type& back();
    bool empty() const;
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item) const;
};