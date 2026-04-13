#include <iostream>

class MyLinkedList {
    struct Node {
        int val;
        Node* next;

        Node(int x) : val(x) { next = nullptr; }
        Node(int x, Node* next) : val(x), next(next) {}
    };

    Node *head, *tail;
    int size;

    Node* getNodeAt(int index) {

        Node* cur = head;
        for(int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur;
    }
public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~MyLinkedList(){
        Node* curr = head;
        while(curr)
        {
            Node* tmp = curr;
            curr = curr->next;
            delete tmp;
        }
    }
    
    int get(int index) {
        if(index >= 0 && index < size)
        {
            return getNodeAt(index)->val;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val, head);
        head = newNode;
        if(size == 0)
        {
            tail = newNode;
        }
        ++size;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(!size)
        {
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        ++size;
    }

    void addAtIndex(int index, int val) {
        if(index == 0) { addAtHead(val);}
        else if (index == size) { addAtTail(val);}
        else if (index > 0 && index < size) {
            Node * prev = getNodeAt(index - 1);
            Node * newNode = new Node (val, prev->next);
            prev->next = newNode;
            ++size;
        }
    }

    void deleteAtIndex(int index) {
        if(index == 0)
        {
            if(head)
            {
                Node* delNode = head;
                head = head->next;
                if(tail == delNode) tail = head;
                delete delNode;
                --size;
            }
        }else if(index > 0 && index < size)
        {
            Node *prec = getNodeAt(index - 1);
            Node *delNode = prec->next;
            prec->next = delNode->next;
            if(tail == delNode)
            {
                tail = prec;
            }
            delete delNode;
            --size;
        }
    }
};