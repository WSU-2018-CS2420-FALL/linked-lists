#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
#include <iostream>

template <typename T>
struct Node {
    T info;
    Node<T>* link;
    Node(T info): info(info), link(nullptr){
        std::cout << "Creating " << info << std::endl;
    }
    ~Node() {
        std::cout << "Destroying " << info << std::endl;
    }
};

template <typename T>
struct List {
    int count;
    Node<T>* first;
    Node<T>* last;
    List(): count(0), first(nullptr), last(nullptr){}
    ~List() {}
};

template<typename T>
void add(List<T>& list, T info){
    Node<T>* newNode = new Node<T>(info);
    if(list.first == nullptr){ // empty list
        list.first = newNode;
        list.last = newNode;
    } else {
        list.last->link = newNode;
        list.last = newNode;
    }

    list.count++;
}

template<typename T>
void remove(List<T>& list, T info){
    if(list.first == nullptr){
        std::cerr << "Empty list; nothing to remove" << std::endl;
    }else if(list.first->info == info){
        auto current = list.first;
        list.first = current->link;
        delete current;
        list.count--;
    } else {
        auto current = list.first->link;
        auto beforeCurrent = list.first;

        while(current){
            if(current->info == info){
                beforeCurrent->link = current->link;
                delete current;
                list.count--;
                return;
            }
            beforeCurrent = current;
            current = current->link;
        }

        std::cerr << "Not found" << std::endl;
    }
}

template<typename T>
void print(List<T>& list){
    auto current = list.first;
    while(current){
        std::cout << current->info << " ";
        current = current->link;
    }
    std::cout << std::endl;
}
#endif