

/************************************************************************************
    Implementation of Binary Search Tree Look-Up (Search) Algorithms
    Author:             Ashis Kumar Das
    Email:              akd.bracu@gmail.com
    GitHub:             https://github.com/AKD92
*************************************************************************************/






#include "bst.h"








BNode * bst_binarySearch(const BisTree *pTree, const void *key, BNode *pStartNode) {
    
    register int opCompareKey;
    register BNode *pNode;
    
    pNode = pStartNode;
    while (bst_isExternal(pNode) != 1) {
        
        opCompareKey = pTree->fpCompareKey((const void *) key, (const void *) pNode->pKey);
        if (opCompareKey == 0) {
            break;
        }
        else if (opCompareKey < 0) {
            pNode = bst_leftChild(pNode);
        }
        else if (opCompareKey > 0) {
            pNode = bst_rightChild(pNode);
        }
    }
    
    return pNode;
}





int bst_search(const BisTree *pTree, const void *pKey, void **pRealKey, void **pElem) {
    
    int iRetVal;
    BNode *pTarget;
    
    pTarget = bst_binarySearch(pTree, pKey, bst_root((BisTree *) pTree));
    
    if (bst_isInternal(pTarget) == 1) {
        if (pElem != 0)
            *pElem = pTarget->pElement;
		if (pRealKey != 0)
			*pRealKey = pTarget->pKey;
        iRetVal = 0;
    }
    else if (bst_isExternal(pTarget) == 1) {
        iRetVal = -1;
    }
    
    return iRetVal;
}

