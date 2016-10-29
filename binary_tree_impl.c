#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree_impl.h"
#include "index_impl.h"
#include "defn_impl.h"
#include "defn.h"

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

BTree_Node* InsertEntryInBTree(BTree_Node* node, Entry entry){

	if(node == NULL){

    node = malloc(sizeof(BTree_Node));

    if(node == NULL){
      printf("Error: malloc() at 'InsertEntryInBTree'\n");fflush(stdout);}

    CopyEntry(&node->entry,&entry);
    
    node->left = NULL;
    node->right = NULL;

  }

  if(strcmp(entry.word->word_str,node->entry.word->word_str) > 0)
    node->right = InsertEntryInBTree(node->right,entry);

  if(strcmp(entry.word->word_str,node->entry.word->word_str) < 0)
    node->left = InsertEntryInBTree(node->left,entry);
  
  if(!Equal(entry.word, node->entry.word)){
    int qid = entry.payload.table[0].qid;
    int position = entry.payload.table[0].position;
    UpdatePayload(&node->entry,qid,position);

  }
    
  return node;

}

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

void ExtractEntriesFromBTree(BTree_Node* node,EntryList* entries){

  if(node == NULL)
    return;

  AddEntry(entries,&node->entry);
  ExtractEntriesFromBTree(node->left,entries);
  ExtractEntriesFromBTree(node->right,entries);

}


//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
void SearchBTree( BTree_Node* node, 
                  Word word,
                  EntryList* results){
	
	if(node == NULL)
    return;

  if(strcmp(word.word_str,node->entry.word->word_str) == 0 )
    AddEntry(results,&node->entry);
    
  
    
  else if(strcmp(word.word_str,node->entry.word->word_str) > 0)
    SearchBTree(node->right,word,results);

  else
    SearchBTree(node->left,word,results);

}
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

void DestroyBTree(BTree_Node* node){

	if(node->left != NULL)
		DestroyBTree(node->left);

	if(node->right != NULL)
		DestroyBTree(node->right);

	DestroyEntry(&node->entry);	
	free(node);

	node = NULL;

}	

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------// 
    
