#include <iostream>
#include <vector>
using namespace std;

class Queue {
private:
    vector<int> q;
    int front, rear, size, count;

public:
    Queue(int c) {    
        size = c;
        q.resize(size);
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isFull(){
        return (count == size);
    }

    bool isEmpty(){
        return (count == 0);
    }

    int Front(){
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1; // Return -1 to indicate the queue is empty
        }
        return q[front];
    }

    int Rear(){
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1; // Return -1 to indicate the queue is empty
        }
        return q[rear];
    }

    bool enQueue(int value){
        if(isFull()){
            cout << "Queue is full" << endl;
            return false;
        }

        rear = (rear + 1) % size;
        q[rear] = value;
        count++;
        return true;
    }

    bool deQueue(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return false;
        }

        front = (front + 1) % size;
        count--;
        return true;
    }
};