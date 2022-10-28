//
// Created by Jfr on 28/10/2022.
//

#include "CQhead.h"
CorruptQueue::RegularQueue tmpQ;
CorruptQueue::VIPStack tmpS;
CorruptQueue::Pointer *head = NULL;
CorruptQueue::Pointer *tail = NULL;

void push_back(CorruptQueue::RegularQueue r) {
    CorruptQueue::Pointer *tmp = new CorruptQueue::Pointer;

    tmp->setRegQ(r);

    if(head == NULL) {
        tmp->nxt = NULL;
        tmp->prv = NULL;
        head = tmp;
        tail = tmp;
    } else {
        tmp->nxt = head;
        tmp->prv = NULL;
        tail->nxt = tmp;
        tail = tmp;
    }
}

void pop_front() {
    CorruptQueue::Pointer *tmp;
    tmp = head;
    head = head->nxt;
    head->prv = NULL;
    delete tmp;
}

CorruptQueue::RegularQueue front_queue() {
    return head->getRegQ();
}

CorruptQueue::RegularQueue back_queue() {
    return tail->getRegQ();
}

/*
 *  Simulation Class
 */

class SQSimulation {
private:

public:
    string  svStatus = "leave";
    SQSimulation() {}

    // lineup part
    SQSimulation(string s1, string s2, string s3) {
        string type = s3;

        if(svStatus == "leave") {
            if(type == "regular") {
                tmpQ.inData(s2);
                push_back(tmpQ);
                cout << "Regular client " << s2 << " lines up at RegularQueue" << endl;
            } else if(type == "VIP") {
                tmpS.pushStack(s2);
                cout << "VIP client " << s2 << " lines up at VIPStack" << endl;
            }
        } else if(svStatus == "arrive") {
            if(type == "regular") {
                tmpQ.inData(s2);
                push_back(tmpQ);
                cout << "Regular client " << s2 << " lines up at RegularQueue" << endl;
            } else if(type == "VIP") {
                tmpQ.inData(s2);
                push_back(tmpQ);
                cout << "VIP client " << s2 << " lines up at RegularQueue" << endl;
            }
        }
    }

    // Serve part
    SQSimulation(string s1) {
        string value = s1;
        if (value == "serve") {
            if(tmpS.isEmpty() == 1) {
                tmpQ = head->getRegQ();
                cout << "Now serving ";
                tmpQ.outData();
                cout << " from RegularQueue" << endl;
                pop_front();
            } else {
                cout << "Now serving ";
                tmpS.topStack();
                cout << " from VIPStack" << endl;
                tmpS.popStack();
            }
        }
    }

    SQSimulation(string s1, string s2) {
        string value = s1;

        if(value == "arrive") {
            CorruptQueue::VIPStack tmp;
            if(tmp.isEmpty() == 0) {
                while(tmp.isEmpty() == 0) {
                    CorruptQueue::RegularQueue tmpQ;
                    tmpQ.inData(tmp.popStack());
                    push_back(tmpQ);
                    tmp.popStack();
                }
            }
            svStatus = "arrive";
            cout << "Supervisor present" << endl;
        } else if(value == "leave") {
            svStatus = "leave";
            cout << "Supervisor not here" << endl;
        }
    }
};

/*
 *  End of Simulation Class
 */