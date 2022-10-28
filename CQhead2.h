//
// Created by Jfr on 28/10/2022.
//

#include "CQhead.h"
CorruptQueue::RegularQueue reg_client;
CorruptQueue::VIPStack vip_client;

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

    // lineup part
    SQSimulation(string s1, string s2, string s3) {
        string type = s3;

        if(svStatus == "leave") {
            if(type == "regular") {
                reg_client.inData(s2);
                push_back(reg_client);
                cout << "Regular client " << s2 << " lines up at RegularQueue" << endl;
            } else if(type == "VIP") {
                vip_client.pushStack(s2);
                cout << "VIP client " << s2 << " lines up at VIPStack" << endl;
            }
        } else if(svStatus == "arrive") {
            if(type == "regular") {
                reg_client.inData(s2);
                push_back(reg_client);
                cout << "Regular client " << s2 << " lines up at RegularQueue" << endl;
            } else if(type == "VIP") {
                reg_client.inData(s2);
                push_back(reg_client);
                cout << "VIP client " << s2 << " lines up at RegularQueue" << endl;
            }
        }
    }

    // Serve part
    SQSimulation(string s1) {
        string value = s1;
        if(vip_client.isEmpty() == true) {
            reg_client = head->getRegQ();
            cout << "Now serving ";
            reg_client.outData();
            cout << " from RegularQueue" << endl;
            pop_front();
        } else {
            string val = vip_client.popStack();
            cout << "Now serving " << val << " from VIPStack" << endl;
        }
    }

    SQSimulation(string s1, string s2) {
        string value = s1;
        if(value == "arrive") {
            if(!vip_client.isEmpty()) {
                while(!vip_client.isEmpty()) {
                    reg_client.inData(vip_client.popStack());
                    push_back(reg_client);
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