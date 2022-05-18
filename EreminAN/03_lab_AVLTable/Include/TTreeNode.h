#pragma once
#include "Table.h"



//Звено девера;
template <typename TableKey, typename TableData>
class  TTreeNode : public TabRecord<TableKey, TableData>
{
public:
	// указатели на поддеревья:
	TTreeNode* pLeft, *pRight, *pParent;


	TTreeNode(TableKey key_, TableData data_, TTreeNode* pL = nullptr, TTreeNode* pR = nullptr, TTreeNode* pP = nullptr) :
		TabRecord<TableKey, TableData>(key_, data_), pLeft(pL), pRight(pR), pParent(pP) {};
	TTreeNode(const TTreeNode& tNode_) :
		TabRecord<TableKey, TableData>(tNode_.Key, tNode_.Data), pLeft(nullptr), pRight(nullptr), pParent(nullptr) {}
	~TTreeNode();

	TTreeNode* GetLeft() const { return pLeft; }      // указатель на левое поддерево;
	TTreeNode* GetRight() const { return pRight; }    // указатель на правое поддерево;
	TTreeNode* GetParent()const { return pParent; }   // указатель на родителя;

};

template <typename TableKey, typename TableData>
TTreeNode<TableKey, TableData>::~TTreeNode()
{
	if (pLeft)
		delete pLeft;
	if (pRight)
		delete pRight;
	if (pParent)
		delete pParent;
}