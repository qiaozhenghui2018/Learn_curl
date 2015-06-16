#include "Environment.h"

#ifndef _LIST_H_
#define _LIST_H_

/*
typedef struct _NodeData_S
{

}NodeData_S;
*/

typedef DWORD NodeData_S;

typedef struct _Node_S
{
	NodeData_S 	m_sData;
	struct _Node_S* m_psNext;
}Node_S;

int MakeNode(Node_S **psListHead);

INT IsEmpty(Node_S *psHeadNode);

INT IsLastNode(Node_S *psNode);

Node_S* FindNode(NodeData_S sData, Node_S *psHead);

INT DeleteNode(NodeData_S sData, Node_S *psHead);

int InsertNode(NodeData_S sData, Node_S *psHead, Node_S *psNode);

#endif/*end of _LIST_H_*/

	
