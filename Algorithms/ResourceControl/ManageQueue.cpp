#include <Task.cpp>
#include <math.h>
#include <map>

/**
 * @class ManageQueue
 * @author Zhi
 * @date 24/04/15
 * @file ManageQueue.cpp
 * @brief the core control component to manage the resource distribution
 */

class ManageQueue {
public:
    ManageQueue() {}

    ManageQueue ( map<Task, int> taskmap ) {
        this->count = taskmap.size();
        this->tasks = new Task[count];
        this->occupies = new int[count];
        map<Task, int>::iterator iter;
        int i = 0;
        for ( iter = taskmap.begin(); iter != taskmap.end(); iter++, i++ ) {
            this->tasks[i] = iter->first;
            this->occupies[i] = iter->second;
        }
    }

    int execute() {
        return 0;
    }

private:
    Task *tasks;
    int *occupies;
    int count;
};
