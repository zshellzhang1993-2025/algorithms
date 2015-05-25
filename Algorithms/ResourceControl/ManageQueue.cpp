#include <Task.cpp>
#include <math.h>
#include <map>
#include <queue>

/**
 * @class BaseQueue
 * @author Zhi
 * @date 25/04/2015
 * @file ManageQueue.cpp
 * @brief the base working queue for the system
 */

class BaseQueue {
public:
    void setUserid ( int userid ) {
        this->userid = userid;
    }

    int getUserid() {
        return userid;
    }

    bool isEmpty() {
        return waitingQueue.empty();
    }

    Task getNextResource() {
        Task result = waitingQueue.front();
        waitingQueue.pop();
        return result;
    }

    void Push ( Task task ) {
        waitingQueue.push ( task );
    }
public:
    BaseQueue *next;        //just like B+Tree to make a circle link on the base structure
    int userid;
private:
    queue<Task> waitingQueue;
};

/**
 * @class MiddleQueue
 * @author Zhi
 * @date 25/04/2015
 * @file ManageQueue.cpp
 * @brief
 */

class MiddleQueue {
public:
    MiddleQueue ( int userid, int size ) {
        this->size = size;
        currentQueue = 0;
        queue = new BaseQueue[size];
        for ( int i = 0; i < size; i++ )
            queue[i].setUserid ( userid );
    }

    void allocateResource ( Task task ) {
        currentQueue = ( currentQueue++ ) % size;
        queue[currentQueue].Push ( task );
    }

    BaseQueue* getBaseQueue() {
        return this->queue;
    }

private:
    BaseQueue *queue;
    int size;
    int currentQueue;
};

/**
 * @class ManageQueue
 * @author Zhi
 * @date 24/04/15
 * @file ManageQueue.cpp
 * @brief the core control component to manage the resource distribution
 */

class ManageQueue {
public:
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

    void execute ( BaseQueue* queue ) {
        Task task;
        int *tags = new int[count];
        while ( 1 ) {
            if ( !queue->isEmpty() ) {
                task = queue->getNextResource();
                task.run();
                tags[task.getID()]++;
                for ( int i = 0; i < count; i++ )
                    cout << "user " << i << ":" << tags[i] << ";";
                cout << endl;
            }
            queue = queue->next;
        }
        delete tags;
    }

private:
    Task *tasks;
    int *occupies;
    int count;
};
