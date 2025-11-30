//1
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



//2
#include <iostream>
using namespace std;

#define MAX_SIZE 10

class CircularQueue {
private:
    int q[MAX_SIZE];
    int front;
    int rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "\nQueue Overflow.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        q[rear] = x;
        cout << "\nEnqueued " << x << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "\nQueue Underflow.\n";
            return;
        }
        cout << "\nDequeued element: " << q[front] << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
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
        int i = front;
        while (true) {
            cout << q[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue myQueue;
    int choice, value;

    do {
        cout << "\n--- CIRCULAR QUEUE MENU ---";
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



//3
#include <iostream>
#include <queue>
using namespace std;

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    cout << "Original Queue: ";
    printQueue(q);

    queue<int> firstHalf;
    queue<int> secondHalf;

    int halfSize = q.size() / 2;

    for (int i = 0; i < halfSize; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!q.empty()) {
        secondHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty() && !secondHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(secondHalf.front());
        secondHalf.pop();
    }

    cout << "Interleaved Queue: ";
    printQueue(q);

    return 0;
}




//4
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    string s = "aabc";
    cout << "Input String: " << s << endl;
    cout << "Output Stream: ";

    int freq[26] = {0};
    queue<char> q;

    for (int i = 0; i < s.length(); i++) {
        char currentChar = s[i];
        q.push(currentChar);
        freq[currentChar - 'a']++;

        while (!q.empty()) {
            if (freq[q.front() - 'a'] > 1) {
                q.pop();
            } else {
                break;
            }
        }

        if (q.empty()) {
            cout << -1 << " ";
        } else {
            cout << q.front() << " ";
        }
    }

    cout << endl;
    return 0;
}


//5

//using 2 queues

#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues {
private:
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        cout << "Pushed " << x << " onto the stack." << endl;
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty, nothing to pop." << endl;
            return;
        }
        cout << "Popped " << q1.front() << " from the stack." << endl;
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty right now." << endl;
            return -1;
        }
        return q1.front();
    }

    bool isEmpty() {
        return q1.empty();
    }

    void display() {
        if (q1.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements (top to bottom): ";
        queue<int> temp = q1;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingTwoQueues s;
    int choice, value;

    do {
        cout << endl << "--- STACK USING TWO QUEUES ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                value = s.top();
                if (value != -1)
                    cout << "Top element is " << value << "." << endl;
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting now." << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 5);

    return 0;
}


//using 1 queue
#include <iostream>
#include <queue>
using namespace std;

class StackUsingOneQueue {
private:
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << "Pushed " << x << " onto the stack." << endl;
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty, nothing to pop." << endl;
            return;
        }
        cout << "Popped " << q.front() << " from the stack." << endl;
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty right now." << endl;
            return -1;
        }
        return q.front();
    }

    bool isEmpty() {
        return q.empty();
    }

    void display() {
        if (q.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements (top to bottom): ";
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingOneQueue s;
    int choice, value;

    do {
        cout << endl << "--- STACK USING ONE QUEUE ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                value = s.top();
                if (value != -1)
                    cout << "Top element is " << value << "." << endl;
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting now." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}



