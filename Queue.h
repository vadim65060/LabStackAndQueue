//
// Created by vadim on 30.09.2022.
//

#ifndef LABSTACKANDQUEUE_QUEUE_H
#define LABSTACKANDQUEUE_QUEUE_H

#include "Node.h"
#include "iostream"

template<class T>
class Queue {
public:
    Queue() = default;

    explicit Queue(T data) {
        PushBack(data);
    }

    Queue(const Queue<T> &queue) noexcept {
        QueueCopy(queue);
    }

    Queue<T>(Queue<T> &&queue) noexcept: nodeHead(queue.nodeHead), nodeTail(queue.nodeTail) {
        queue.nodeHead = nullptr;
        queue.nodeTail = nullptr;
    }

    ~Queue() {
        Del();
    }

    enum ERR_CODE {
        Queue_EMPTY
    };

    void PushBack(T data) {
        if (nodeTail != nullptr) {
            nodeTail->connectedNode = new Node<T>(data);
            nodeTail = nodeTail->connectedNode;
        } else {
            nodeTail = new Node<T>(data);
            nodeHead = nodeTail;
        }
    }

    T PopFront() {
        if (nodeHead == nullptr)
            throw Queue_EMPTY;
        Node<T> *tempNode = nodeHead;
        T nodeData;
        nodeData = nodeHead->data;
        nodeHead = nodeHead->connectedNode;
        if (nodeHead == nullptr)
            nodeTail = nullptr;

        delete tempNode;
        return nodeData;
    }

    const T &GetFront() const {
        if (nodeHead == nullptr)
            throw Queue_EMPTY;
        return nodeHead->data;
    }

    const T &GetBack() const {
        if (nodeTail == nullptr)
            throw Queue_EMPTY;
        return nodeTail->data;
    }

    bool IsEmpty() const {
        return nodeTail == nullptr;
    }

    Queue<T> &operator=(Queue<T> &&queue) noexcept {
        if (&queue == this)
            return *this;
        this->Del();
        nodeTail = queue.nodeTail;
        nodeHead = queue.nodeHead;
        queue.nodeHead = nullptr;
        queue.nodeTail = nullptr;
        return *this;
    }

    Queue<T> &operator=(const Queue<T> &queue) {
        if (&queue == this)
            return *this;
        this->Del();
        QueueCopy(queue);
        return *this;
    }

    void PrintNods() {
        Node<T> *itNode = nodeHead;
        while (itNode) {
            std::cout << itNode->data << ' ';
            itNode = itNode->connectedNode;
        }
        std::cout << "\n";
    }

private:
    Node<T> *nodeHead = nullptr;
    Node<T> *nodeTail = nullptr;

    void QueueCopy(const Queue<T> &queue) {
        Node<T> *itNode = queue.nodeHead;
        while (itNode) {
            this->PushBack(itNode->data);
            itNode = itNode->connectedNode;
        }
    }

    void Del() {
        while (nodeHead != nullptr) {
            this->PopFront();
        }
        nodeTail = nullptr;
    }
};


#endif //LABSTACKANDQUEUE_QUEUE_H
