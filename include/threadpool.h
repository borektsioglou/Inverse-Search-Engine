#ifndef THREADPOOL_H
#define	THREADPOOL_H


#ifdef	__cplusplus
extern "C" {
#endif

#include <pthread.h>
#include <semaphore.h>
	
#define NUM_OF_THREADS 12

// the job structure
typedef struct Job Job;

//the jobqueue structure
typedef struct Job_Queue Job_Queue;

//the thread pool structure
typedef struct Thread_Pool Thread_Pool;

//the thread data
typedef struct thread_data thread_data;
//----------------------------- THREAD POOL ----------------------------------//
//----------------------------------------------------------------------------//


void ThPool_Wait(Thread_Pool* threadpool);


Thread_Pool* Initialize_ThPool(int num_of_threads);


void Worker_Thread(thread_data* tdata);


void ThPool_AddJob(Thread_Pool* threadpool, 
									void *(*function)(void*), 
									void* args);


void ThPool_Destroy(Thread_Pool* threadpool);



//----------------------------- JOB QUEUE ------------------------------------//
//----------------------------------------------------------------------------//


void Initialize_JobQueue(Thread_Pool* threadpool);

void JobQueue_Add(Thread_Pool* threadpool, Job* job);

void JobQueue_Removefirst(Thread_Pool* threadpool);

Job* JobQueue_Getfirst(Thread_Pool* threadpool);

void JobQueue_Destroy(Thread_Pool* threadpool);

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//


#ifdef	__cplusplus
}
#endif

#endif	/* THREADPOOL_H */
