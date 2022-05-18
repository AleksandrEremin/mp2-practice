#pragma once
#include "TTreeNode.h"


//С индексом балансировки, для АВЛ дерева;
template <typename TableKey, typename TableData>
class  TBalanceNode : public TTreeNode<TableKey, TableData>
{
protected:
	int Balance; // индекс балансировки вершины (-1,0,1);
public:

	TBalanceNode(TableKey key_, TableData data_, TTreeNode* pL = nullptr, TTreeNode* pR = nullptr, TTreeNode* pP = nullptr, int bal_ = 0) : 
		TTreeNode<TableKey, TableData>(key_, data_, pL, pR, pP),Balance(bal_) {};                                                               // конструктор;
	
	int GetBalance(void) const { return Balance; }
	void SetBalance(int bal) { Balance = bal; }

};



