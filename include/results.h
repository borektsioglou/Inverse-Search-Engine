#ifndef RESULTS_H
#define	RESULTS_H


#ifdef	__cplusplus
extern "C" {
#endif


typedef struct ResultsTable ResultsTable;

/*
 * This structure holds a docs results
 */
typedef struct Results_struct Results_struct;
//------------------------------------------------------------------------------

void CreateResultsTable(ResultsTable* restable);

void AddResult(ResultsTable* restable,QueryID* results,int size,int pos);

void GetResults(ResultsTable* restable,QueryID** results,unsigned int*  p_num_res,int pos);

void DestroyResultsTable(ResultsTable* restable);


#ifdef __cplusplus
}
#endif

#endif	//RESULTS_H