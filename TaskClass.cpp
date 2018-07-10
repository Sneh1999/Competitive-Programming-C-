//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
using namespace std;
//////////////////////////////////////////////////////////////
//
// local #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
#endif

//////////////////////////////////////////////////////////////
// Important: do not include your struct, class into MARMOSET_TESTING!!!

//////////////////////////////////////////////////////////////
//
// struct definitions
//
enum TaskType{LAUNDRY, DISHES, MAKE_BED, VACUUM, MOP_FLOOR, MOW_LAWN};

struct Task
{
    TaskType type; // Laundry, dishes, etc.
    int taskID;
    char* description;
};

//////////////////////////////////////////////////////////////
//
// Class definitions, do not remove.
//
class TaskQueue{
public:
    TaskQueue() //it maybe a good idea to have a constructor
    {
        head = NULL;
    }

    // you can either implement your function here or below in the function definitions
    bool enqueue(const Task& task)
    {
        if(task.description[0]==0){
            return false;
        }
        Queue* temppointer = new Queue;
		Task* curr = new Task;

curr->taskID = task.taskID;
curr->type = task.type;
curr->description = task.description;

temppointer->task = curr;
temppointer->nextInQueue = NULL;



if(temppointer){
	
if(head == NULL || head->task == NULL){
	head = temppointer;

	return true;
}




else
{
	Queue* traverse  = head;
	
	
	while((traverse!=NULL))
		{
		if ((traverse->task->taskID == task.taskID)&&(traverse->task->type == task.type))
			return false;
		traverse = traverse->nextInQueue;
	}
	Queue* current = head;
	
	while(current->nextInQueue != NULL)
	{
		current = current->nextInQueue;
	}
	
	current->nextInQueue = temppointer;
	

	return true;
}
}

return false;


    }
    const Task* dequeue()
{
	if(head == NULL)
	{
		return NULL;
	}
	Queue* curr = new Queue;
	curr  = head;
	Task* t = head->task;
	head = head->nextInQueue;
	
	//delete temppointer;
	return t;
}

private:
    struct Queue
    {
        Task* task;
        Queue* nextInQueue;
    };
    Queue* head;

};




//////////////////////////////////////////////////////////////
//
// Function definitions. PLEASE USE HELPER FUNCTIONS
//


//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
//
#ifndef MARMOSET_TESTING

int main(){
    // Some test driver code here ....
    cout << endl << "Implement some more appropriate tests in main()" << endl << endl;

    char sampleDescription[] = "sample description";

    Task task1 =
    {
        .type = LAUNDRY,
        .taskID = 1,
        .description = sampleDescription
    };

    TaskQueue* taskQueue = new TaskQueue();

    bool enqueueSuccess = taskQueue->enqueue(task1);
    if(enqueueSuccess)
        cout << "task1 enqueued successfully" << endl << endl;
    else
        cout << "enqueue() failed" << endl << endl;

    const Task* p_firstTaskInQueue = taskQueue->dequeue();

    if (p_firstTaskInQueue)
        cout << "Dequeue successful..." << endl; // customize your own cout since you are customizing your private members of the class.
    else
        cout << "dequeue() failed" << endl;

    delete taskQueue;

    return 0;
}
#endif


