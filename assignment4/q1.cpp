#include <iostream>
using namespace std;

#define MAX_SIZE 10

class Queue {
private:
    int q[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "\nQueue is full.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        q[rear] = x;
        cout << "\nEnqueued " << x << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "\nQueue is empty.\n";
            return;
        }
        cout << "\nDequeued element: " << q[front] << endl;
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
    
    void peek() {
        if (isEmpty()) {
            cout << "\nQueue is empty.\n";
            return;
        }
        cout << "\nFront element: " << q[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "\nQueue is empty.\n";
            return;
        }
        cout << "\nQueue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue myQueue;
    int choice, value;

    do {
        cout << "\n--- SIMPLE QUEUE MENU ---";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Is Empty?";
        cout << "\n6. Is Full?";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                myQueue.enqueue(value);
                break;
            case 2:
                myQueue.dequeue();
                break;
            case 3:
                myQueue.peek();
                break;
            case 4:
                myQueue.display();
                break;
            case 5:
                cout << (myQueue.isEmpty() ? "\nQueue IS empty.\n" : "\nQueue is NOT empty.\n");
                break;
            case 6:
                cout << (myQueue.isFull() ? "\nQueue IS full.\n" : "\nQueue is NOT full.\n");
                break;
            case 7:
                cout << "\nExiting.\n";
                break;
            default:
                cout << "\nInvalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}
