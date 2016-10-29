#ifndef CACHE_H
#define	CACHE_H


#ifdef	__cplusplus
extern "C" {
#endif


#include "defn.h"
#include "index.h"

#define CACHE_SIZE 200

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

typedef struct Cache_Entry Cache_Entry;

typedef struct Cache_Queue Cache_Queue;

typedef struct Cache Cache;

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

void Initialize_Cache(Cache* cache,int queue_size);

void Destroy_Cache(Cache* cache);

int Search_Cache(	Cache* cache,
									Word word,
									EntryList* edit_results,
									unsigned int* lru_bucket);

void Update_Cache(	Cache* cache,
										Word word,
										EntryList* edit_results,
                    unsigned int lru_bucket,
                    int found_in_cache);

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//




#ifdef	__cplusplus
}
#endif

#endif	/* CACHE_H */
