#pragma once
#include <stack>
#include "TTreeNode.h"

// Класс Бинарное поисковое дерево
template <typename TableKey, typename TableData>
class BinarySearchTree
{
protected:
	TTreeNode<TableKey, TableData>* pRoot;  // указатель на корень дерева (корневой узел);
public:
	// Конструкторы, деструктор:
	BinarySearchTree() { pRoot = nullptr; }
	~BinarySearchTree();

	//Методы:
	TTreeNode<TableKey, TableData>* FindRecord(TableKey key_) const;                          // Поиск записи с заданным ключом;
	TTreeNode<TableKey, TableData>* FindMin(TTreeNode<TableKey, TableData>* node_) const;     // Поиск узла с минимальным ключом;
	TTreeNode<TableKey, TableData>* FindMax(TTreeNode<TableKey, TableData>* node_) const;     // Поиск узла с максимальным ключом;
	TTreeNode<TableKey, TableData>* FindNext(TTreeNode<TableKey, TableData>* node_) const;    // Поиск узла со следующим ключом;
	TTreeNode<TableKey, TableData>* FindPrev(TTreeNode<TableKey, TableData>* node_) const;    // Поиск узла с предыдущем ключом;

	virtual void Insert(const TableKey key_, const TableData data_);    // Вставка узла;               <<<==<<<==<<<====-------------------------------------------------------------------------------------------<<<----
	virtual void Delete(const TableKey key_);                           // Удаление узла;
};

template <typename TableKey, typename TableData>
BinarySearchTree<TableKey, TableData>::~BinarySearchTree()
{
	stack<TTreeNode<TableKey, TableData>*> S1;
	TTreeNode<TableKey, TableData>* n = pRoot;
	while (S1.size() != 0 || n != nullptr)
	{
		if (n != nullptr)
		{
			S1.push(n);
			n = n->pLeft;
		}
		else
		{
			n = S1.top();
			S1.pop();
			Delete(n->GetKey());
			n = n->pRight;
		}
	}
}


template <typename TableKey, typename TableData>
TTreeNode<TableKey, TableData>* BinarySearchTree<TableKey, TableData>::FindRecord(TableKey key_) const
{
	TTreeNode<TableKey, TableData>* tmp = pRoot;
	while ((tmp != nullptr) && (tmp->GetKey() != key_))
	{
		if (key_ < tmp->GetKey())
		{
			tmp = tmp->pLeft;
		}
		else
		{
			tmp = tmp->pRight;
		}
	}
	return tmp;
}

template <typename TableKey, typename TableData>
TTreeNode<TableKey, TableData>* BinarySearchTree<TableKey, TableData>::FindMin(TTreeNode<TableKey, TableData>* node_) const
{
	TTreeNode<TableKey, TableData>* tmp = node_;
	while (tmp->pLeft != nullptr)
	{
		tmp = tmp->pLeft;
	}
	return tmp;
}

template <typename TableKey, typename TableData>
TTreeNode<TableKey, TableData>* BinarySearchTree<TableKey, TableData>::FindMax(TTreeNode<TableKey, TableData>* node_) const
{
	TTreeNode<TableKey, TableData>* tmp = node_;
	while (tmp->pRight != nullptr)
	{
		tmp = tmp->pRight;
	}
	return tmp;
}

template <typename TableKey, typename TableData>
TTreeNode<TableKey, TableData>* BinarySearchTree<TableKey, TableData>::FindNext(TTreeNode<TableKey, TableData>* node_) const
{
	TTreeNode<TableKey, TableData>* res = nullptr;
	if (node_->pRight != nullptr)
		return FindMin(node_->pRight);

	res = node_->pParent;
	TTreeNode<TableKey, TableData>* tmp = node_;
	while ((res != nullptr) && (tmp == res->pRight))
	{
		tmp = res;
		res = res->pParent;
	}
	return res;
}

template <typename TableKey, typename TableData>
TTreeNode<TableKey, TableData>* BinarySearchTree<TableKey, TableData>::FindPrev(TTreeNode<TableKey, TableData>* node_) const
{
	TTreeNode<TableKey, TableData>* res = nullptr;
	if (node_->pLeft != nullptr)
		return FindMax(node_->pLeft);

	res = node_->pParent;
	TTreeNode<TableKey, TableData>* tmp = node_;
	while ((res != nullptr) && (tmp == res->pLeft))
	{
		tmp = res;
		res = res->pParent;
	}
	return res;
}

template <typename TableKey, typename TableData>
void BinarySearchTree<TableKey, TableData>::Insert(const TableKey key_, const TableData data_)
{
	if (FindRecord(key_) != nullptr)
		throw 1;

	if (pRoot == nullptr) //вставка корня
	{
		pRoot = new TTreeNode<TableKey, TableData>(key_, data_);
		return;
	}

	TTreeNode<TableKey, TableData>* x = pRoot;
	TTreeNode<TableKey, TableData>* y;
	while (x != nullptr)
	{
		y = x;
		if (key_ < x->GetKey())
			x = x->pLeft;
		else
			x = x->pRight;
	}
	if (key_ < y->GetKey())
	{
		y->pLeft = new TTreeNode<TableKey, TableData>(key_, data_, y);
	}
	else
	{
		y->pRight = new TTreeNode<TableKey, TableData>(key_, data_, y);
	}
}

template <typename TableKey, typename TableData>
void BinarySearchTree<TableKey, TableData>::Delete(const TableKey key_)
{
	TTreeNode<TableKey, TableData>* z = FindRecord(key_);

	if (FindRecord(key_) == nullptr) // удаление не существующего элемента 
		throw "Error";

	TTreeNode<TableKey, TableData>* y = (z->pLeft != nullptr && z->pRight != nullptr) ? FindNext(z) : z;
	TTreeNode<TableKey, TableData>* x = (y->pLeft != nullptr) ? y->pLeft : y->pRight;

	if (x != nullptr)      // меняем указатель родителя у потомка
		x->pParent = y->pParent;
	if (y->pParent != nullptr)   //1,3 случай
	{
		if (y == y->pParent->pLeft)
			y->pParent->pLeft = x;
		else
			y->pParent->pRight = x;
	}
	if (y != z)   //2 случай
	{
		z->SetKey(y->GetKey());
		z->SetData(*(y->GetData()));
	}
	//удаление корня, если это единственный узел
	if (z == pRoot && z->pLeft == nullptr && z->pRight == nullptr)
		pRoot = nullptr;

}