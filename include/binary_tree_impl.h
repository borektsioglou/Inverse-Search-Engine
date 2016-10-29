#ifndef BINARY_TREE_IMPL_H
#define	BINARY_TREE_IMPL_H

#include "binary_tree.h"

#ifdef	__cplusplus
extern "C" {
#endif


struct BTree_Node{	//binary tree node holds entry

	Entry entry;			
	BTree_Node * right;       
	BTree_Node * left;

};


#ifdef	__cplusplus
}
#endif


#endif		//BINARY_TREE_IMPL_H
