#ifndef INDEX_H
#define	INDEX_H

#include "core.h"
#include "defn.h"
#include "threadpool.h"

#ifdef	__cplusplus
extern "C" {
#endif


//-------------------------------external typedef-----------------------------//
typedef struct Queries Queries;
//----------------------------------------------------------------------------//

// ========================== Structures ==================================== //

/*
 * This structure holds a generic information about a particlar entry.
 */

typedef struct Payload_Member Payload_Member;

typedef struct Payload Payload;

//Payload Member holds query id and position of word in the query
struct Payload_Member { 

	int qid;
	char position;

};  

struct Payload {  //Payload holds a table of payload members

	int size;
  int max_size;
	Payload_Member* table ;

};  
  
/*
 * This structure holds information about a particlar entry.
 */  
typedef struct Entry Entry;


struct Entry {  //Struct entry points to a word and has a payload

  Word* word;
  Payload payload;
  
};

/*
 * This structure holds a list of entries.
 */
typedef struct EntryList EntryList;
//----------------------------------------------------------------------------//
/*
 * This structure holds a vp tree node.
 */
typedef struct VPTnode VPTnode;
/*
 * This structure holds the vp tree.
 */
typedef struct VP_Tree VP_Tree ;

//--------------------------     EDIT  ---------------------------------------//

/*
 * This structure holds the index for the edit distance type entries.
 */
typedef struct Edit_Index Edit_Index;

//----------------------------------------------------------------------------//

//initialize edit index
void InitializeEditIndex(Edit_Index* index);

//destroy edit index
void DestroyEditIndex(Edit_Index* index);

//build edit index given an entrylist and the match type(which should be edit)
void BuildEditIndex(Edit_Index* index,EntryList* entries);

//search the edit index and fill entrylist result with the results 
void SearchEditIndex(Edit_Index index,
                    Word word,
                    EntryList* result,
                    EntryList* result_cache);

//----------------------------------------------------------------------------//

//----------------------------   HAMMING    ----------------------------------//

/*
 * This structure holds the index for the hamming distance type entries.
 */
typedef struct Hamming_Index Hamming_Index;

//----------------------------------------------------------------------------//

//initialize hamming index
void InitializeHammingIndex(Hamming_Index* index);

//destroy hamming index
void DestroyHammingIndex(Hamming_Index* index);

//build hamming index given an entrylist 
//and the match type(which should be hamming)
void BuildHammingIndex(Hamming_Index* index,
						EntryList* entries);

//search the hamming index and fill entrylist result with the results 
void SearchHammingIndex(Hamming_Index index,
                    Word word,
                    EntryList* result);

//----------------------------------------------------------------------------//

//----------------------------  EXACT    -------------------------------------//

/*
 * This structure holds the index for the exact distance type entries.
 */
typedef struct Exact_Index Exact_Index;

//----------------------------------------------------------------------------//

//initialize exact index
void InitializeExactIndex(Exact_Index* index);

//destroy exact index
void DestroyExactIndex(Exact_Index* index);

//build exact index given an entrylist 
void BuildExactIndex(Exact_Index* index, EntryList* entries);

//search the exact index and fill entrylist result with the results 
void SearchExactIndex(Exact_Index index,
                      Word word,
                      EntryList* results);

//----------------------------------------------------------------------------//

//-------------------------    INDEXES     -----------------------------------//

/*
 * This structure holds all indexes.
 */
typedef struct Indexes Indexes;

//----------------------------------------------------------------------------//

//initialize all indexes
void InitializeIndexes(Indexes* indexes);

//destroy all indexes
void DestroyIndexes(Indexes* indexes);

//build all indexes with the given querysets(which exist inside 'queries')
void BuildIndexes(Indexes* indexes,Queries* queries);

//search all indexes for the given document id from the DocumentSet and
//return all results in the entrylists depending on the match type
void SearchIndexes( EntryList* hamming_results,
                    EntryList* edit_results,
                    EntryList* exact_results,
                    Document doc,
                    Indexes indexes,
                    int c);

//----------------------------------------------------------------------------//

//-------------------------Entry----------------------------------------------//

/*
 * Initialize the given entry with the given word.
 */
enum ErrorCode CreateEntry(const Word* word, Entry* entry);

/*
 * Destroy the given entry.
 */
enum ErrorCode DestroyEntry(Entry *entry);

/*
 * Prints the word of the given entry.
 */
void PrintEntry(Entry* entry);

/*
 * Copies the payload of entry source to payload of entries dest.
 */
void CopyPayload(Entry* dest,const Entry* source);

/*
 * Updates the payload of entry.
 */
void UpdatePayload(Entry* entry,int query_id,int position);

/*
 * Copy the entry source to the entry dest.
 */
void CopyEntry(Entry* dest,const Entry* source);

//----------------------------------------------------------------------------//
//---------------------------EntryList----------------------------------------//

/*
 * Initialize the given EntryList.
 */
enum ErrorCode CreateEntryList(EntryList* entry_list);


/*
 * Returns the number of entries of the given entryList.
 */
unsigned int GetNumberOfEntries(const EntryList* entry_list);


/*
 * Add a new entry at the given entryList.
 */
enum ErrorCode AddEntry(EntryList* entry_list, const Entry* entry);

/*
 * Copy the entrylist source to the entrylist dest.
 */
void CopyEntryList(EntryList* dest,EntryList* source,int emptydest);

/*
 * Returns the first entry of the given entryList.
 */
Entry* GetFirst(EntryList* entry_list);

/*
 * Returns the next entry of the given entryList.
 */
Entry* GetNext(EntryList* entry_list);


/*
 * Destroys the given entryList.
 */
enum ErrorCode DestroyEntryList(EntryList* entry_list);

/*
 * Prints the entries of the given entryList.
 */
void PrintEntryList(const EntryList* entryList);

/*
 * Prints the entries payload of the given entryList.
 */
void PrintEntrylistPayloads(EntryList* entries);

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//


#ifdef	__cplusplus
}
#endif

#endif	/* INDEX_H */
