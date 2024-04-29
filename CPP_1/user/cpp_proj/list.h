//
// Created by plato on 24-4-23.
//

#ifndef SPACE_H
#define SPACE_H

#include <string>
#include <iostream>
#include <QString>

using namespace std;

class Temp{
public:
    int isteacher;
    QString name;
    int age;
    int height;
    int weight;
    int id;
    int gender;
    int grade;
    int class_num;
    int score;
    int rank;
    int salary;
};

class person {
public:
    QString name;
    int age;
    int height;
    int weight;
    int id;
    int gender;
    int grade;
    int class_num;
};

class student : public person {
public:
    int score;
    int rank;
};

class teacher : public person {
public:
    int salary;
};

template <class T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}
    ~Node() {
        delete next;
    }
};

// 链表类
template <class T>
class List {
public:
    List() : head(nullptr) {}
    ~List() {
        head = nullptr;
    }
    void insert(T data) {
        Node<T>* newNode = new Node<T>(data, head);
        head = newNode;
    }
    void remove(T data) {
        Node<T>* current = head;
        Node<T>* prev = nullptr;

        while (current != nullptr) {
            if (current->data == data) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                current->next = nullptr; // 断开与链表的连接
                delete current; // 删除节点
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    void display() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    Node<T>* head;
};
// 派生自 List 类的 Stack 类
template <class T>
class Stack : public List<T> {
public:
    void push(T data) {
        this->insert(data);
    }

    T pop() {
        if (this->head == nullptr) {
            cerr << "Stack is empty" << endl;
            exit(EXIT_FAILURE);
        }
        Node<T>* temp = this->head;
        this->head = this->head->next;
        T data = temp->data;
        temp->next = nullptr;
        delete temp;
        return data;
    }

    T peek() {
        if (this->head == nullptr) {
            cerr << "Stack is empty" << endl;
            exit(EXIT_FAILURE);
        }
        return this->head->data;
    }
};

// 派生自 List 类的 Queue 类
template <class T>
class Queue : public List<T> {
public:
    void enqueue(T data) {
        this->insert(data);
    }

    T dequeue() {
        if (this->head == nullptr) {
            cerr << "Queue is empty" << endl;
            exit(EXIT_FAILURE);
        }
        Node<T>* current = this->head;
        this->head = this->head->next;
        T data = current->data;
        current->next = nullptr;
        delete current;
        return data;
    }

    T front() {
        if (this->head == nullptr) {
            cerr << "Queue is empty" << endl;
            exit(EXIT_FAILURE);
        }
        return this->head->data;
    }
};

// 派生自 List 类的 Set 类
template <class T>
class Set : public List<T> {
public:
    Set operator+(const Set& otherSet) const {
        Set<T> result;
        Node<T>* current = this->head;
        while (current != nullptr) {
            result.insert(current->data);
            current = current->next;
        }
        current = otherSet.head;
        while (current != nullptr) {
            result.insert(current->data);
            current = current->next;
        }
        return result;
    }

    Set operator-(const Set& otherSet) const {
        Set<T> result;
        Node<T>* current = this->head;
        while (current != nullptr) {
            if (!otherSet.contains(current->data)) {
                result.insert(current->data);
            }
            current = current->next;
        }
        return result;
    }

    Set intersection(const Set& otherSet) const {
        Set<T> result;
        Node<T>* current = this->head;
        while (current != nullptr) {
            if (otherSet.contains(current->data)) {
                result.insert(current->data);
            }
            current = current->next;
        }
        return result;
    }

    bool contains(T data) const {
        Node<T>* current = this->head;
        while (current != nullptr) {
            if (current->data == data) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};




#endif //SPACE_H
