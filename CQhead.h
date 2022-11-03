//
// Created by Jfr on 26/10/2022.
//

#ifndef CORRUPTQUEUE_CQHEAD_H
#define CORRUPTQUEUE_CQHEAD_H
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <list>
using namespace std;

struct Node {
    string data;
    Node* nxt = nullptr;
    Node() = default;
};

class CorruptQueue {

protected:
    bool svStat = false;

public:

    CorruptQueue() = default;

     void change_stat(const string& xx) {
        if(xx == "arrive") {
            svStat = true;
            cout << "Supervisor present" << endl;
        } else {
            svStat = false;
            cout << "Supervisor not here" << endl;
        }
    }

    bool isArrive() const {

        if(svStat){
            return true;
        } else {
            return false;
        }
    }
};

/*
    *  RegularQueue
    */

class RegularQueue : public CorruptQueue {
protected:

public:
    Node *front, *back;
    RegularQueue() : front(nullptr), back(nullptr) {}

    virtual void insertQueue(const string &qnm) {
        Node* insertNode = new Node;
        insertNode->data = qnm;
        if(back == nullptr) {
            front = insertNode;
            back = insertNode;
        } else {
            back->nxt = insertNode;
            back = insertNode;
        }
    }

    virtual void popQueue() {
        if(front == nullptr) {
            cout << "Nothing to pop" << endl;
        } else {
            Node* popNode = front;
            front = front->nxt;

            if(front == nullptr) {
                back = nullptr;
            }

            delete popNode;
        }
    }

    virtual void frontQueue() const {
        cout << front->data;
    }

    virtual void backQueue() const {
        cout << back->data;
    }
};

/*
*  VIP Stack class
*/

class VIPStack : public CorruptQueue {

public:
    Node *top;
    VIPStack() : top(nullptr) {}

    virtual void pushStack(const string &nm) {
        Node* pushNode = new Node;
        pushNode->data = nm;
        pushNode->nxt = nullptr;
        if(top != nullptr) {
            pushNode->nxt = top;
            top = pushNode;
        } else {
            top = pushNode;
            pushNode->nxt = nullptr;
        }
    }

    virtual void popStack() {
        Node* popStackNode;
        if(top == nullptr) {
            cout << "Stack is empty" << endl;
        } else {
            popStackNode = top;
            top = top->nxt;
            delete popStackNode;
        }
    }

    virtual void topStack() const {
        Node* topNode;
        if(top == nullptr) {
            cout << "Stack is empty" << endl;
        } else {
            topNode = top;
            cout << topNode->data;
        }
    }

    virtual void size_stack() {
        Node* sizeNode;
        int i = 0;
        if(top != nullptr) {
            sizeNode = top;
            while(sizeNode) {
                i++;
                sizeNode = sizeNode->nxt;
            }
            cout << i << endl;
        } else {
            cout << "Stack is empty" << endl;
        }
    }

    virtual bool isEmpty() {
        Node *checker;
        checker = top;
        if(checker == nullptr) {
            return true;
        } else {
            return false;
        }
    }
};

RegularQueue regular_client;
VIPStack vip_client;
CorruptQueue sup_stat;

class CQSimulation {
    public:

    CQSimulation() = default;

    // without using object

    CQSimulation(const string &s_1, const string &s_2, const string &s_3) {
        if(sup_stat.isArrive()) {
            if(s_3 == "regular") {
                regular_client.insertQueue(s_2);
                cout << "Regular client " << s_2 << " lines up at RegularQueue" << endl;
            } else if(s_3 == "VIP") {
                regular_client.insertQueue(s_2);
                cout << "VIP client " << s_2 << " lines up at RegularQueue" << endl;
            }
        } else {
            if(s_3 == "regular") {
                regular_client.insertQueue(s_2);
                cout << "Regular client " << s_2 << " lines up at RegularQueue" << endl;
            } else if(s_3 == "VIP") {
                vip_client.pushStack(s_2);
                cout << "VIP client " << s_2 << " lines up at VIPStack" << endl;
            }
        }
    }

    CQSimulation(const string &s_1, const string &s_2) {
        sup_stat.change_stat(s_1);
        if(sup_stat.isArrive()) {
            while(!vip_client.isEmpty()) {
                Node *temp = new Node;
                temp = vip_client.top;
                regular_client.insertQueue(temp->data);
                vip_client.popStack();
            }
        }
    }

    explicit CQSimulation(const string &s_1) {
        if(sup_stat.isArrive()) {
            cout << "Now serving ";
            regular_client.frontQueue();
            cout << " from RegularQueue" << endl;
            regular_client.popQueue();
        } else {
            if(!vip_client.isEmpty()) {
                cout << "Now serving ";
                vip_client.topStack();
                cout << " from VIPStack" << endl;
                vip_client.popStack();
            } else {
                cout << "Now serving ";
                regular_client.frontQueue();
                cout << " from RegularQueue" << endl;
                regular_client.popQueue();
            }
        }
    }

    // Using object

    void lineup(const string &s_1, const string &s_2, const string &s_3) {
        if(sup_stat.isArrive()) {
            if(s_3 == "regular") {
                regular_client.insertQueue(s_2);
                cout << "Regular client " << s_2 << " lines up at RegularQueue" << endl;
            } else if(s_3 == "VIP") {
                regular_client.insertQueue(s_2);
                cout << "VIP client " << s_2 << " lines up at RegularQueue" << endl;
            }
        } else {
            if(s_3 == "regular") {
                regular_client.insertQueue(s_2);
                cout << "Regular client " << s_2 << " lines up at RegularQueue" << endl;
            } else if(s_3 == "VIP") {
                vip_client.pushStack(s_2);
                cout << "VIP client " << s_2 << " lines up at VIPStack" << endl;
            }
        }
    }

    void supervisor_status(const string &s_1, const string &s_2) {
        sup_stat.change_stat(s_1);
        if(sup_stat.isArrive()) {
            while (!vip_client.isEmpty()) {
                Node *temp = new Node;
                temp = vip_client.top;
                regular_client.insertQueue(temp->data);
                vip_client.popStack();
            }
        }
    }

    void serve(const string &s_1) {
        if(sup_stat.isArrive()) {
            cout << "Now serving ";
            regular_client.frontQueue();
            cout << " from RegularQueue" << endl;
            regular_client.popQueue();
        } else {
            if(!vip_client.isEmpty()) {
                cout << "Now serving ";
                vip_client.topStack();
                cout << " from VIPStack" << endl;
                vip_client.popStack();
            } else {
                cout << "Now serving ";
                regular_client.frontQueue();
                cout << " from RegularQueue" << endl;
                regular_client.popQueue();
            }
        }
    }
};

#endif //CORRUPTQUEUE_CQHEAD_H
