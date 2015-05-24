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
