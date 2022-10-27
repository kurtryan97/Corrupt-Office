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

queue<CorruptQueue> reg_client;

class CorruptQueue {
protected:
    string sv_status = "leave";


public:
    class RegQ {

    protected:
        string name = "";
        string cl_type = "";

    public:
        RegQ() {}
        RegQ(string nm , string cl = "regular") : name(nm), cl_type(cl) {}

        virtual void inData(string nm) {
            name = nm;
        }

        virtual string GetName() {
            return name;
        }

        virtual string GetType() {
            return cl_type;
        }
    };

    class Vstack {

    protected:
        string name = "";
        string cl_type = "";

    public:
        Vstack() {}
        Vstack(string nm , string cl = "regular") : name(nm), cl_type(cl) {}

        virtual void inData(string nm) {
            name = nm;
        }

        virtual string GetName() {
            return name;
        }

        virtual string GetType() {
            return cl_type;
        }
    };

    virtual CorruptQueue::RegQ GetFrontReg() {
        RegQ t;
        t.GetName();
        return t;
    }

    virtual void lineupReg(string n1) {
        RegQ tmp;
        tmp.inData(n1);
    }

    virtual void lineupVIP(string n1) {
        Vstack tmp;
        tmp.inData(n1);
    }

    virtual void serve() {

    }

    virtual void arrived(string status) {

    }

    virtual void leave(string status) {

    }
};

class SQSimulation {
private:

public:

    SQSimulation() {}

    SQSimulation(string s1, string s2, string s3) {
        string string1 = s1;
        string string2 = s2;
        string string3 = s3;

        if(string1 == "lineup") {
            if(string3 == "regular") {
                CorruptQueue tmp;
                tmp.lineupReg(string2);
                reg_client.push(tmp);
                cout << "Regular client " << string2 << " lines up at RegularQueue" << endl;
                tmp.GetFrontReg();
            }
        }
    }

    virtual CorruptQueue FrontData() {
        return reg_client.front();
    }
};

#endif //CORRUPTQUEUE_CQHEAD_H
