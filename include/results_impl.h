#ifndef RESULTS_UTILS_IMPL_H
#define	RESULTS_UTILS_IMPL_H

#include "core.h"
#include "results.h"

#ifdef __cplusplus
extern "C" {
#endif

struct Results_struct{
	int cur;
	QueryID* id_results;
};


struct ResultsTable{

	int max_size;
	int size;
	QueryID** id_results;
	int* sizes;
};


#ifdef __cplusplus
}
#endif

#endif	//RESULTS_UTILS_IMPL_H