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
//
// struct definitions 
//
#ifndef MARMOSET_TESTING

enum TaskType{LAUNDRY, DISHES, MAKE_BED, VACUUM, MOP_FLOOR, MOW_LAWN};

struct Task 
{
	TaskType type; // Laundry, dishes, etc.
	int taskID;
	char* description;
};

struct TaskQueue
{
	Task* task;
	TaskQueue* nextInQueue;
};

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
//

bool enqueue(TaskQueue*& queue, const Task& task);
const Task* dequeue(TaskQueue*& queue);

//////////////////////////////////////////////////////////////
//
// Function definitions. PLEASE USE HELPER FUNCTIONS
//

bool enqueue(TaskQueue*& queue, const Task& task)
{
	if(task.description[0] == 0)
		return false;
	
	
TaskQueue* temppointer = new TaskQueue;
Task* curr = new Task;

curr->taskID = task.taskID;
curr->type = task.type;
curr->description = task.description;

temppointer->task = curr;
temppointer->nextInQueue = NULL;



if(temppointer){
	
if(queue == NULL || queue->task == NULL){
	queue = temppointer;

	return true;
}




else
{
	TaskQueue* traverse  = queue;
	
	
	while((traverse!=NULL))
		{
		if ((traverse->task->taskID == task.taskID)&&(traverse->task->type == task.type))
			return false;
		traverse = traverse->nextInQueue;
	}
	TaskQueue* current = queue;
	
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

const Task* dequeue(TaskQueue*& queue)
{
	if(queue == NULL)
	{
		return NULL;
	}
	
	Task* t = queue->task;
	TaskQueue* temppointer = queue;
	queue = queue->nextInQueue;
	
	//delete temppointer;
	return t;
}

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
	
	
	TaskQueue* p_queue = new TaskQueue;
	p_queue->task = NULL;
	p_queue->nextInQueue = NULL;

	
	bool enqueueSuccess = enqueue(p_queue, task1);
	if(enqueueSuccess)
		cout << "task1 enqueued successfully" << endl << endl;
	else
		cout << "enqueue() failed" << endl << endl; 
	const Task* p_firstTaskInQueue = dequeue(p_queue);
	
	
	if (p_firstTaskInQueue)
	{
		cout << "Dequeue successful..." << endl;
		cout << "Type: " << p_firstTaskInQueue->type << endl;
		cout << "Task ID: " << p_firstTaskInQueue->taskID << endl;
		cout << "Description: " << p_firstTaskInQueue->description << endl;
	}
	else
		cout << "dequeue() failed" << endl;

		
	Task task2 =
	{
		.type = DISHES,
		.taskID = 2,
		.description = sampleDescription
	};


	bool enqueueSuccess2 = enqueue(p_queue, task2);
	
	if(enqueueSuccess2)
		cout << "task2 enqueued successfully" << endl << endl;
	else
		cout << "enqueue() failed" << endl << endl; 
	
	
	
	const Task* p_secondTaskInQueue = dequeue(p_queue);
	
	
	if (p_secondTaskInQueue)
	{
		cout << "Dequeue successful..." << endl;
		cout << "Type: " << p_secondTaskInQueue->type << endl;
		cout << "Task ID: " << p_secondTaskInQueue->taskID << endl;
		cout << "Description: " << p_secondTaskInQueue->description << endl;
	}
	else
		cout << "dequeue() failed" << endl;

	delete p_queue;
	
	return 0;
}
#endif

