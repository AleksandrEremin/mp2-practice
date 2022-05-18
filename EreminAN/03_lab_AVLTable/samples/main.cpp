//main
#pragma once
#include <string>
#include "ScanTable.h"
#include "TArrayHash.h"
#include "Polynom.h"
#include "SortTable.h"
#include "BinarySearchTree.h"

using namespace std;
#define SP <string, Polynom>

void menu(int i)
{
	if (i == 1) {
		cout << "\t      ===== � � � � ===== " << endl;
		cout << "\t1. �������� ������� � �������;" << endl;
		cout << "\t2. ������� ������� �� �������;" << endl;
		cout << "\t3. �������� � ����������;" << endl;
		cout << "\t4. �������� �������;" << endl;
		cout << "\t5. �������� �������;" << endl;
		cout << "\t0. --> �����;" << endl;
		cout << "\t------------------------------" << endl << endl;
	}
	if (i == 2)
	{
		cout << "\t --- �������� ������� ---" << endl;
		cout << "\t1. ScanTable;" << endl;
		cout << "\t2. SortTable;" << endl;
		cout << "\t3. HashTable;" << endl;
		cout << "\t4. ��� �������;" << endl;
	}
	if (i == 3)
	{
		cout << "\t --- �������� ������� ---" << endl;
		cout << "\t1. ScanTable;" << endl;
		cout << "\t2. SortTable;" << endl;
		cout << "\t3. HashTable;" << endl;
	}

}

template <typename Tab>
void PolynomTable(int IndexMenu, Tab& Table_, string PolString, int TableSize = 0)
{
	try {
		switch (IndexMenu)
		{
		case 1: // ������;
		{
			Polynom P(PolString);
			Table_.InsRecord(PolString, P);
			break;
		}
		case 2: // ��������;
		{
			cout << Table_ << endl;
			cout << "������ �������:" << endl;;
			cin >> PolString;
			Table_.DelRecord(PolString);
			break;
		}
		default:
			break;
		}
	}
	catch (const char* exception)
	{
		std::cerr << "Error: " << exception << '\n';
	}
}

template <typename Tab>
int check(Tab& Table_, string key_) 
{
	if (Table_.FindRecord(key_) == nullptr)
		return 0;
	return 1;
}

Polynom operation(Table SP& ScanTable, Table SP& SortTable, Table SP& HashTable, int indexP, int indexQ)
{
	Polynom A;
	std::string KeyA;
	// ������������ ������ ��� ��������;
	if (indexP == 1 || indexQ == 1) cout << "ScanTable: " << endl << ScanTable << endl << endl;
	if (indexP == 2 || indexQ == 2) cout << "SortTable: " << endl << SortTable << endl << endl;
	if (indexP == 3 || indexQ == 3) cout << "HashTable: " << endl << HashTable << endl << endl;
	if (indexP != 0)
	{
		cout << endl << "������� ������� P:" << endl;
	}
	else cout << endl << "������� ������� Q:" << endl;
	//����� ��������� ������;
	cin >> KeyA;
	if (indexP == 1 || indexQ == 1)
	{
		if (check(ScanTable, KeyA) == 0) throw "ScanTable - ������ �� �������."; //��������, �.�. ����� ��������� nullptr, ���� �� �����;
		A = *(ScanTable.FindRecord(KeyA));
	}
	else
	{
		if (indexP == 2 || indexQ == 2)
		{
			if (check(SortTable, KeyA) == 0)  throw "SortTable - ������ �� �������.";
			A = *(SortTable.FindRecord(KeyA));
		}
		else
		{
			if (check(HashTable, KeyA) == 0)  throw "HashTable - ������ �� �������.";
			A = *(HashTable.FindRecord(KeyA));
		}
	}
	return  A;
}

Polynom operation_1(Table SP& ScanTable, Table SP& SortTable, Table SP& HashTable)
{
	system("cls");
	int index = 0, indexP = 0, indTMP = 0;
	string Task, Num;
	cout << "======== ���� ========" << endl;
	cout << "1. �������� � ����������;" << endl;
	cout << "2. �������� � ������;" << endl;
	cout << "======================" << endl;
	cin >> index;
	cout << endl;
	Polynom P, Q, Res;
	system("cls");


	if (index == 1)
	{
		while (indTMP == 0)
		{
			int indexA = -1, indexB = -1;
			menu(3);
			cout << "\t������� P ---> ";
			cin >> indexA;
			try
			{
				P = operation(ScanTable, SortTable, HashTable, indexA, 0);
				cout << endl << "\t������� Q ---> ";
				cin >> indexB;

				Q = operation(ScanTable, SortTable, HashTable, 0, indexB);

				cout << endl << "�� �������: " << endl;
				cout << P << endl;
				cout << Q << endl;
				cout << "������� ������:" << endl;
				cin >> Task;
				indTMP = 1;
			}
			catch (const char* exception)
			{
				std::cerr << "Error: " << exception << '\n';
			}
		}
	}
	else
	{
		while (indTMP == 0)
		{
			int indexP = -1;
			menu(3);
			cout << "\t������� � ---> ";
			cin >> indexP;
			try
			{
				P = operation(ScanTable, SortTable, HashTable, indexP, 0);
				cout << "������� ������:" << endl;
				cin >> Task;
				indTMP = 1;

			}
			catch (const char* exception)
			{
				std::cerr << "Error: " << exception << '\n';
			}
		}
	}
	//-------------------------// ��� ���� ���� � ������� ������������;
	int size = 0;
	switch (index)
	{
	case 1:
		indexP = 0;
		while (size <= Task.size())
		{
			if (Task[size] == ' ')
				size++;
			else
			{
				if (Task[size] == 'P')
				{
					size++;
					indexP = 1;
				}
				if (Task[size] == '+' || Task[size] == '*')
				{
					if (Task[size] == '+')
						Res = P + Q;
					else Res = P * Q;
					size = Task.size();
				}
				if (Task[size] == '-')
				{
					if (indexP == 1)
						Res = P - Q;
					else Res = Q - P;
					size = Task.size();
				}
				size++;
			}
		}
		break;
	case 2:
		int size2;
		while (size <= Task.size())
		{
			if (Task[size] == ' ')
				size++;
			else
			{
				if (Task[size] == 'P')
				{
					size++;
					indexP = 1;
				}
				size2 = size;
				while (size2 <= Task.size())
				{
					if (isdigit(Task[size2]))
					{
						while (isdigit(Task[size2]))
						{
							Num += Task[size2];
							size2++;
						}
					}
					size2++;
				}
				if (Task[size] == '+' || Task[size] == '*')
				{
					double N = atof(Num.c_str());
					if (Task[size] == '+')
						Res = P + N;
					else Res = P * N;
					size = Task.size();
				}
				if (Task[size] == '-')
				{
					double N = atof(Num.c_str());
					if (indexP == 1)
						Res = P - N;
					else Res = (P * (-1)) + N;
					size = Task.size();
				}
				size++;
			}
		}
		break;
	default:
		cout << "�������� ����� ����" << endl;
		throw "error";
	}
	Res.cancellation();
	cout << "���������:" << endl;
	cout << Task << " = " << Res << endl << endl;
	return Res;
}






void main()
{

	setlocale(LC_ALL, "Russian");
	int IndexMenu = -1, TableSize = -1, TableIndex = -1;

	cout << "������� ������ ��� ������: " << endl;
	cin >> TableSize;
	if (TableSize <= 0)
		throw "Error";
	system("cls");
	menu(1);
	cin >> IndexMenu;
	ScanTable SP ScanTable(TableSize);
	SortTable SP SortTable(TableSize);
	TArrayHash SP HashTable(TableSize);

	while (IndexMenu != 0)
	{
		std::string PolString = "";
		switch (IndexMenu)
		{
		case 1: case 2: 
		{
			menu(2);
			cin >> TableIndex;
			if (TableIndex <= 0 || TableIndex >= 5)
			{
				cout << "�������� ������;" << endl; break;
			}
			system("cls");
			if (IndexMenu == 1)
			{
				cout << "������� �������: " << endl;
				cin >> PolString;
			}
			if (TableIndex == 1 || TableIndex == 4) PolynomTable(IndexMenu, ScanTable, PolString);
			if (TableIndex == 2 || TableIndex == 4) PolynomTable(IndexMenu, SortTable, PolString);
			if (TableIndex == 3 || TableIndex == 4) PolynomTable(IndexMenu, HashTable, PolString);
			break;
		}
		case 3: 
		{
			Polynom Res;
			Res = operation_1(ScanTable, SortTable, HashTable);
			cout << "C�������� ���������;" << endl;
			menu(2);
			cout << "\t5. �� ���������;" << endl;
			cin >> TableIndex;
			if (TableIndex == 1 || TableIndex == 4) ScanTable.InsRecord(Res.Pstring(), Res);
			if (TableIndex == 2 || TableIndex == 4) SortTable.InsRecord(Res.Pstring(), Res);
			if (TableIndex == 3 || TableIndex == 4) HashTable.InsRecord(Res.Pstring(), Res);
			system("cls");
			break;

		}
		case 4: 
		{
			system("cls");
			menu(2);
			cin >> TableIndex;
			if (TableIndex <= 0 || TableIndex >= 5)
			{
				cout << "�������� ������;" << endl; break;
			}
			cout << endl;
			if (TableIndex == 1 || TableIndex == 4) cout << "ScanTable: " << endl << ScanTable << endl << endl;
			if (TableIndex == 2 || TableIndex == 4) cout << "SortTable: " << endl << SortTable << endl << endl;
			if (TableIndex == 3 || TableIndex == 4) cout << "HashTable: " << endl << HashTable << endl << endl;
			break;
		}
		case 5:
		{
			menu(2);
			cin >> TableIndex;
			if (TableIndex == 1 || TableIndex == 4) ScanTable.Deleted();
			if (TableIndex == 2 || TableIndex == 4) SortTable.Deleted();
			if (TableIndex == 3 || TableIndex == 4) HashTable.Deleted();

			break;
			system("cls");
		}

		default:
		{
			cout << "�������� ������;";
			break;
		}
		}
		cout << endl << endl;
		menu(1);
		cin >> IndexMenu;
	}
}