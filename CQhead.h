//
// Created by Jfr on 26/10/2022.
//

#ifndef CORRUPTQUEUE_CQHEAD_H
#define CORRUPTQUEUE_CQHEAD_H
#include <iostream>
#include <string>
using namespace std;

//  Structure Node for storing the name of the client and the pointer next
struct Node {
    string data;
    Node* nxt = nullptr;
    Node() = default;
};

//  Base class, only svStat attribute for status of supervisor
class CorruptQueue {

protected:
    bool svStat = false;

public:

    CorruptQueue() = default;

    //  method of changing the svStat from true to false or vise verse depending on the state given in the input
     void change_stat(const string& xx) {
        if(xx == "arrive") {
            svStat = true;
            cout << "Supervisor present" << endl;
        } else {
            svStat = false;
            cout << "Supervisor not here" << endl;
        }
    }

    //  Boolean method for checking if supervisor is arrived
    bool isArrive() const {
        if(svStat){
            return true;
        } else {
            return false;
        }
    }
};

/*
*  RegularQueue subclass
*/

class RegularQueue : public CorruptQueue {
protected:

public:

    //  created pointer for front queue and back queue
    Node *front, *back;
    RegularQueue() : front(nullptr), back(nullptr) {}

    //  insert queue method for enqueueing client in lineup
    virtual void insertQueue(const string &reg_client_name) {
        Node* insertNode = new Node;                            //  Creating new pointer for every client to be inserted.
        insertNode->data = reg_client_name;                         //  put the client name into the data attribute of pointer.
        if(back == nullptr) {                                   //  if back is empty (meaning if the queue is empty)
            front = insertNode;                                 //  the new client is the front and back
            back = insertNode;
        } else {
            back->nxt = insertNode;                             //  else if queue is not empty, the former back 'next' pointer is pointer to
            back = insertNode;                                  //  client and the new client will be the new back
        }
    }

    virtual void popQueue() {                                   //  Deleting the front queue
        if(front == nullptr) {                                  //  if front pointer is pointing nothing...
            cout << "Nothing to pop" << endl;                   //  the queue is empty
        } else {
            Node* popNode = front;                              //  create a temporary pointer to store the front data
            front = front->nxt;                                 //  then the new front will be the next data

            if(front == nullptr) {                              //  if next pointer is pointing nothing, then
                back = nullptr;                                 //  out queue is empty.
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
    Node *top;                                                   // Pointer top.
    VIPStack() : top(nullptr) {}

    virtual void pushStack(const string &vip_client_name) {
        Node* pushNode = new Node;                              //  create new pointer for new vip client.
        pushNode->data = vip_client_name;
        pushNode->nxt = nullptr;
        if(top != nullptr) {                                    //  if the top is not empty...
            pushNode->nxt = top;                                //  the new pointer 'next' will point to the former top and
            top = pushNode;                                     //  the new pointer will be the new top
        } else {
            top = pushNode;                                     //  else (if stack is empty) the new pointer will be the top data
            pushNode->nxt = nullptr;                            //  the next pointer will point to nothing.
        }
    }

    virtual void popStack() {
        Node* popStackNode;                                     //  create a temporary pointer
        if(top == nullptr) {
            cout << "Stack is empty" << endl;
        } else {
            popStackNode = top;                                 //  is stack is not empty, store temporarily the top to the
            top = top->nxt;                                     //  then the top 'next' will be the new top
            delete popStackNode;                                //  delete the created temporary pointer
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

    virtual void Stack_size() {
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

    /*
     *      without using object
     */

    CQSimulation(const string &string1, const string &string2, const string &string3) {                      // line up method
        if(sup_stat.isArrive()) {                                                                            // if the supervisor is arrived then...
            if(string3 == "regular") {
                regular_client.insertQueue(string2);
                cout << "Regular client " << string2 << " lines up at RegularQueue" << endl;
            } else if(string3 == "VIP") {
                regular_client.insertQueue(string2);
                cout << "VIP client " << string2 << " lines up at RegularQueue" << endl;
            }
        } else {                                                                                             // if supervisor is not around then...
            if(string3 == "regular") {
                regular_client.insertQueue(string2);
                cout << "Regular client " << string2 << " lines up at RegularQueue" << endl;
            } else if(string3 == "VIP") {
                vip_client.pushStack(string2);
                cout << "VIP client " << string2 << " lines up at VIPStack" << endl;
            }
        }
    }

    CQSimulation(const string &string1, const string &string2) {                                                     // arrived or leave method
        sup_stat.change_stat(string1);
        if(sup_stat.isArrive()) {
            while(!vip_client.isEmpty()) {
                Node *temp = new Node;
                temp = vip_client.top;
                regular_client.insertQueue(temp->data);
                vip_client.popStack();
            }
        }
    }

    explicit CQSimulation(const string &string1) {                                                              //  Serving method
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

    /*
     *      Using object
     */

    void lineup(const string &string1, const string &string2, const string &string3) {                          // Lineup method
        if(sup_stat.isArrive()) {
            if(string3 == "regular") {
                regular_client.insertQueue(string2);
                cout << "Regular client " << string2 << " lines up at RegularQueue" << endl;
            } else if(string3 == "VIP") {
                regular_client.insertQueue(string2);
                cout << "VIP client " << string2 << " lines up at RegularQueue" << endl;
            }
        } else {
            if(string3 == "regular") {
                regular_client.insertQueue(string2);
                cout << "Regular client " << string2 << " lines up at RegularQueue" << endl;
            } else if(string3 == "VIP") {
                vip_client.pushStack(string2);
                cout << "VIP client " << string2 << " lines up at VIPStack" << endl;
            }
        }
    }

    void supervisor_status(const string &string1, const string &string2) {                                  //  method that checks if the supervisor is arrived
        sup_stat.change_stat(string1);
        if(sup_stat.isArrive()) {
            while (!vip_client.isEmpty()) {
                Node *temp = new Node;
                temp = vip_client.top;
                regular_client.insertQueue(temp->data);
                vip_client.popStack();
            }
        }
    }

    void serve(const string &string1) {                                                                 //  serving method
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
