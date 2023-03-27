#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }};

class Queue {
private:
    Node* front;
    Node* rear;
    int qSize;
public:
    Queue() {
        front = rear = NULL;
        qSize = 0;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        qSize++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            qSize--;
        }
    }

    int top() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        } else {
            return front->data;
        }
    }

    int size() {
        return qSize;
    }
};

int main() {
    Queue q;
    q.enqueue(10);

    q.enqueue(20);

    q.enqueue(30);

    q.enqueue(40);

    cout << "The queue size is: " << q.size() << endl;
    cout << "The front element is: " << q.top() << endl;

    q.dequeue();
    q.dequeue();

    cout << "The queue size is: " << q.size() << endl;
    cout << "The front element is: " << q.top() << endl;

    q.enqueue(50);

    cout << "The queue size is : " << q.size() << endl;
    cout << "The front element is: " << q.top() << endl;

    return 0;
}
