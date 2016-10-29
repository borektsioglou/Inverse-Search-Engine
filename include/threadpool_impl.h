#ifndef THREADPOOL_IMPL_H
#define	THREADPOOL_IMPL_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "threadpool.h"


struct Job{
    
    char *path;
	//void* 	(*function)(void* args); 	// function to be called from worker
	//void*   args;     									// functions arguments
	Job*  	next;     								// pointer to next job
	Job* 		prev;     								// pointer to previous job

};


struct Job_Queue{

	Job*			head;           // head of jobqueue
	Job*			tail;          	// tail of jobqueue
	//sem_t*		jobqueue_sem;   // sem used for checking if queue is busy or not
	int  			num_of_jobs;  	// number of current jobs in queue

};



struct Thread_Pool{

	//pthread_t*       threads;         // thread pool threads
	Job_Queue* 			 jobqueue;        // thread pool jobqueue
	//int              num_of_threads;  // number of thread pool threads

};

/*struct thread_data{

	Thread_Pool* threadpool;
	int c_index;

};*/


#ifdef	__cplusplus
}
#endif

#endif	/* THREADPOOL_IMPL_H */	
