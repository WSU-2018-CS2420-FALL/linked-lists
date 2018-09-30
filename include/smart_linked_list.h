#ifndef _SMART_LINKED_LIST_H
#define _SMART_LINKED_LIST_H
#include <iostream>
#include <memory>

template <typename T>
struct Node {
    T info;
    std::shared_ptr<Node<T>> link;
    Node(T info): info(info){
        std::cout << "Creating " << info << std::endl;
    }
    ~Node() {
        std::cout << "Destroying " << info << std::endl;
    }
};

template <typename T>
struct List {
    int count;
    std::shared_ptr<Node<T>> first;
    std::shared_ptr<Node<T>> last;
    List(): count(0){}
    ~List() {}
};

template<typename T>
void add(List<T>& list, T info){
    auto newNode = std::make_shared<Node<T>>(info);
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
        list.count--;
    } else {
        auto current = list.first->link;
        auto beforeCurrent = list.first;

        while(current){
            if(current->info == info){
                beforeCurrent->link = current->link;
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