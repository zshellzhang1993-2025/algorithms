#include <iostream>
using namespace std;

/**
 * @class Task
 * @author Zhi
 * @date 24/04/2015
 * @file Task.cpp
 * @brief class with its userid and task content encapsulated in method run();
 */

class Task {
public:
    Task() {}

    Task ( int userid ) {
        this->userid = userid;
    }

    virtual void run() {}

    int getID() {
        return this->userid;
    }

    void setID ( int userid ) {
        this->userid = userid;
    }

private:
    int userid;
};

//the following classes are dereived from base class Task with virtual function run()
//which can implement polymorphism in C++

class TaskA1: Task {
public:
    TaskA1 ( int userid ) : Task ( userid ) {}

    virtual void run() {
        cout << "user A is runing Task A1!" << endl;
    }
};

class TaskA2: Task {
public:
    TaskA2 ( int userid ) : Task ( userid ) {}

    virtual void run() {
        cout << "user A is runing Task A2!" << endl;
    }
};

class TaskB: Task {
public:
    TaskB ( int userid ) : Task ( userid ) {}

    virtual void run() {
        cout << "user B is runing Task B!" << endl;
    }
};

class TaskC: Task {
public:
    TaskC ( int userid ) : Task ( userid ) {}

    virtual void run() {
        cout << "user C is runing Task C!" << endl;
    }
};
