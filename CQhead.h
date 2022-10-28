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

class CorruptQueue;

class CorruptQueue {
protected:
    string sv_status = "leave";


public:
    class RegularQueue {
    private:
        string name;

    public:
        RegularQueue() {}
        RegularQueue(string nm) : name(nm) {}
        void inData(string n) {
            name = n;
        }

        void outData() {
            cout << name;
        }
    };

    class Pointer {
    private:
        RegularQueue rq;

    public:
        Pointer *nxt;
        Pointer *prv;

        void setRegQ(RegularQueue r1) {
            rq = r1;
        }

        RegularQueue getRegQ() {
            return rq;
        }
    };


    /*
     *  VIP Stack class
     */

    class VIPStack {
        int top;

    protected:
        string name = "";

    public:
        string vip_client[3];

        VIPStack() {
            top = -1;
        }

        void pushStack(string x) {
            if(top >= 20) {
                cout << "Stack overflow" << endl;
            } else {
                vip_client[++top] = x;
            }
        }

        string popStack() {
            if(top < 0) {
                cout << "Stack underflow" << endl;
            } else {
                string d = vip_client[top--];
                return d;
            }
        }

        void topStack() {
            cout << vip_client[top];
        }

        void size_stack() {
            cout << top + 1 << endl;
        }

        bool isEmpty() {
            if(top < 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    };
};

#endif //CORRUPTQUEUE_CQHEAD_H
