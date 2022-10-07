#include <iostream>
#include "Stack.h"
#include "Queue.h"

void TestStack() {
    Stack<int> st(1);
    st.Push(2);
    st.Push(3);
    st.Push(4);
    st.Push(5);
    Stack<int> a(st);
    st.SetFront(-1);
    st.PrintNods();
    a.PrintNods();
}

void TestQueue() {
    Queue<int> queue(1);
    queue.PushBack(2);
    queue.PrintNods();
    queue.PopFront();
    queue.PrintNods();
    Queue<int> q2(queue);
    q2.PopFront();
    std::cout << "q2 empty: " << q2.IsEmpty();
}

int main() {
    TestQueue();

}
