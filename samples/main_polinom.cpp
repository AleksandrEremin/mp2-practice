
#include "monom.h"
#include "polinom.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define RANDOM 100
void menu() {
	cout << "����:\n" << endl;
	cout << "1.������ ��������..." << endl;
	cout << "2.������� ��������..." << endl;
	cout << "3.������� �������� ��������..." << endl;
	cout << "4.������� �������� ��������..." << endl;
	cout << "5.�������� �������� ��������..." << endl;
	cout << "6.��������� ��������� ����������" << endl;
	cout << "7.��������� ������� � ��������� x,y,z" << endl;
	cout << "-------------------------------------" << endl;
	cout << "���.�����:" << endl;
	cout << "8.����� ������� ����������� �� �" << endl;
	cout << "9.����� ������� ����������� �� y" << endl;
	cout << "10.����� ������� ����������� �� z" << endl;
	cout << "11.������������������� ��������" << endl;
	cout << "__________________________________________________WARNING____________________________________________________________" << endl;
	cout << "1)���� �� �� ����� ��������, �� ������ 2-5 ����� ������������� ������������� ��������" << endl;
	cout << "2)���� �������� ������������� ���������� ��������� ���� 2x^4y^5z^6,��� ����� ��������� ����������� " << endl;
	cout << "  ��������, � ����� ����� �������� ����������� ������������� ����� ���������� ����� '+','-'." << endl;
	cout << "3)��������� ���������� ��������� �� �������� � ������� ����������� ������� ����: (5x^2y^2z^3+123x^4) - (69x^3y^4z^9)." << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "0.Exit " << endl;
	cout << ">>";
}

int  main()
{
	Polinom A;
	string STR;
	A.str_to_poly("0.5x^2z^7+20x^4");
	//A.showList2();
	Polinom B;
	B.str_to_poly("0.5x^2z^7");
	Polinom RES;
	Polinom SAVE;
	bool N1 = 0;
	bool N2 = 0;
	bool S1 = 0;
	bool S2 = 0;
	setlocale(LC_ALL, "Russian");
	int t = 999;
	cout << "����� ���������� � ������ ��������� �������� ���������!\n" << endl;

	while (t != 0)
	{
		setlocale(LC_ALL, "Russian");
		menu();
		cin >> t;
		cout << "_____________________________________________________________________________________________________________________" << endl;
		switch (t)
		{
		case 1:
		{
			int d = 0;
			do {
				cout << "�������� �������� �������:" << endl;
				cout << "��� ������ �, ������� 1" << endl;
				cout << "��� ������ B, ������� 2" << endl;
				cout << "��� ������ � �� SAVE, ������� 3" << endl;
				cout << "��� ������ B �� SAVE, ������� 4" << endl;
				cin >> d;
				if ((d > 4) || (d < 1))  cout << ("������ ������������ ����") << endl;
			} while ((d > 4) || (d < 1));
			if (d == 1) {
				cout << "������� ������� �:";
				cin >> STR;
				A *= 0;
				A.podobnyi();
				setlocale(LC_ALL, "English");
				A.str_to_poly(STR);
				setlocale(LC_ALL, "Rus");
				N1 = 1;
			}
			if (d == 2) {
				cout << "������� ������� B:";
				cin >> STR;
				B *= 0;
				B.podobnyi();
				setlocale(LC_ALL, "English");
				B.str_to_poly(STR);
				setlocale(LC_ALL, "Rus");
				N2 = 1;
			}
			if (d == 3) {
				if (S2 == 0) cout << "SAVE ������, ������� ���������� ���-������ � ���������!" << endl;
				else {
					cout << "������ A=SAVE";
					A = SAVE;
				}
			}
			if (d == 4) {
				if (S2 == 0) cout << "SAVE ������, ������� ���������� ���-������ � ���������!" << endl;
				else {
					cout << "������ B=SAVE";
					B = SAVE;
				}
			}
			break;
		}
		case 2:
		{
			int d1;
			do {
				cout << "�������� ��������� �������:" << endl;
				cout << "��� ������ �, ������� 1" << endl;
				cout << "��� ������ B, ������� 2" << endl;
				cout << "��� ������ SAVE, ������� 3" << endl;

				cin >> d1;
				if ((d1 > 3) || (d1 < 1))  cout << ("������ ������������ ����") << endl;
			} while ((d1 > 3) || (d1 < 1));
			if (d1 == 1) {
				cout << "������� �:";
				A.showList();
			}
			if (d1 == 2) {
				cout << "������� B:";
				B.showList();
			}
			if (d1 == 3) {
				if (S1 == 0) cout << "������ ��������, ������� ���������� ���-������!" << endl;
				else {
					cout << "������� SAVE:";
					SAVE.showList();
				}
			}
			break;
		}
		case 3:
		{
			if (N1 == 0) {
				cout << "____________________WARNING___________________" << endl;
				cout << "������� A ����� ������� ��������" << endl;
				cout << "A="; A.showList();
				cout << "______________________________________________" << endl;

			}
			if (N2 == 0) {
				cout << "____________________WARNING___________________" << endl;
				cout << "������� B ����� ������� ��������" << endl;
				cout << "B="; B.showList();
				cout << "______________________________________________" << endl;

			}
			int d2;
			do {
				cout << "������� �������� ��������:" << endl;
				cout << "1.���� � ������ (A+B)" << endl;
				cout << "2.������� A � �������� �������" << endl;
				cout << "3.������� B � �������� �������" << endl;
				cout << "4.������� A � �������� ��������" << endl;
				cout << "5.������� B � �������� ��������" << endl;
				cin >> d2;
				if ((d2 > 5) || (d2 < 1))  cout << ("������ ������������ ����") << endl;
			} while ((d2 > 5) || (d2 < 1));

			if (d2 == 1)
			{
				cout << "����� ��������� A � B:";
				RES = A + B;
				RES.podobnyi();
				S1 = 1;
				cout << "A+B="; A.showList3(); B.showList3(); cout << "="; RES.showList3(); cout << "\n";
				//A.showList();
			}
			if (d2 == 2)
			{
				double koef = 0;
				int x, y, z;
				cout << "������� ������� ������ a:";
				cin >> koef >> x >> y >> z;
				Node ptr(koef, x, y, z);
				RES = A + ptr;
				RES.podobnyi();
				S1 = 1;

				cout << "A+a="; RES.showList3(); cout << "\n";
			}
			if (d2 == 3)
			{
				double koef = 0;
				int x, y, z;
				cout << "������� ������� ������ a:";
				cin >> koef >> x >> y >> z;
				Node ptr(koef, x, y, z);
				RES = B + ptr;
				RES.podobnyi();
				S1 = 1;

				cout << "B+a="; RES.showList3(); cout << "\n";
			}
			if (d2 == 4)
			{
				double scalar = 0;
				cout << "������� ������:";
				cin >> scalar;
				RES = A + scalar;
				RES.podobnyi();
				S1 = 1;

				cout << "A+scalar="; RES.showList3(); cout << "\n";
			}
			if (d2 == 5)
			{
				double scalar = 0;
				cout << "������� ������:";
				cin >> scalar;
				RES = B + scalar;
				RES.podobnyi();
				S1 = 1;

				cout << "B+scalar="; RES.showList3(); cout << "\n";
			}
			break;
		}
		case 4:
		{
			if (N1 == 0) {
				cout << "____________________WARNING___________________" << endl;
				cout << "������� A ����� ������� ��������" << endl;
				cout << "A="; A.showList();
				cout << "______________________________________________" << endl;

			}
			if (N2 == 0) {
				cout << "____________________WARNING___________________" << endl;
				cout << "������� B ����� ������� ��������" << endl;
				cout << "B="; B.showList();
				cout << "______________________________________________" << endl;

			}
			int d2;
			do {
				cout << "������� �������� ��������:" << endl;
				cout << "1.���� �� ������� (A-B)" << endl;
				cout << "2.���� �� ������� (B-A)" << endl;
				cout << "3.������� A � �������� �������" << endl;
				cout << "4.������� B � �������� �������" << endl;
				cout << "5.������� A � �������� ��������" << endl;
				cout << "6.������� B � �������� ��������" << endl;
				cin >> d2;
				if ((d2 > 5) || (d2 < 1))  cout << ("������ ������������ ����") << endl;
			} while ((d2 > 5) || (d2 < 1));
			cout << "_____________________________________WARNING___________________________________" << endl;
			cout << "���������� ���������� ������� � ���������" << endl;
			cout << "���������� ������� � ����������� ������ ���� >= ���������� ������� � ����������" << endl;
			cout << "A="; A.showList();
			cout << "B="; A.showList();
			cout << "_______________________________________________________________________________" << endl;
			if (d2 == 1)
			{
				cout << "�������� ��������� A � B:";
				RES = A - B;
				RES.podobnyi();
				S1 = 1;

				cout << "A-B="; A.showList3(); cout << "-("; B.showList3(); cout << ")="; RES.showList3(); cout << "\n";
				//A.showList();
			}
			if (d2 == 2)
			{
				cout << "�������� ��������� B � A:";
				RES = B - A;
				RES.podobnyi();
				S1 = 1;

				cout << "B-A="; B.showList3(); cout << "-("; A.showList3(); cout << ")="; RES.showList3(); cout << "\n";
				//A.showList();
			}
			if (d2 == 3)
			{
				double koef = 0;
				int x, y, z;
				cout << "������� ������� ������ a:";
				cin >> koef >> x >> y >> z;
				Node ptr(koef, x, y, z);
				RES = A - ptr;
				RES.podobnyi();
				S1 = 1;

				cout << "A-a="; RES.showList3(); cout << "\n";
			}
			if (d2 == 4)
			{
				double koef = 0;
				int x, y, z;
				cout << "������� ������� ������ a:";
				cin >> koef >> x >> y >> z;
				Node ptr(koef, x, y, z);
				RES = B - ptr;
				RES.podobnyi();
				S1 = 1;

				cout << "B-a="; RES.showList3(); cout << "\n";
			}
			if (d2 == 5)
			{
				double scalar = 0;
				cout << "������� ������:";
				cin >> scalar;
				RES = A - scalar;
				RES.podobnyi();
				S1 = 1;

				cout << "A-scalar="; RES.showList3(); cout << "\n";
			}
			if (d2 == 6)
			{
				double scalar = 0;
				cout << "������� ������:";
				cin >> scalar;
				RES = B - scalar;
				RES.podobnyi();
				S1 = 1;

				cout << "B-scalar="; RES.showList3(); cout << "\n";
			}
			break;
		}
		case 5:
		{
			if (N1 == 0) {
				cout << "____________________WARNING___________________" << endl;
				cout << "������� A ����� ������� ��������" << endl;
				cout << "A="; A.showList();
				cout << "______________________________________________" << endl;

			}
			if (N2 == 0) {
				cout << "____________________WARNING___________________" << endl;
				cout << "������� B ����� ������� ��������" << endl;
				cout << "B="; B.showList();
				cout << "______________________________________________" << endl;

			}
			int d2;
			do {
				cout << "�������� ��������� ��������:" << endl;
				cout << "1.���� �� ������ A*B" << endl;
				cout << "2.������� A �� �������� �������" << endl;
				cout << "3.������� B �� �������� �������" << endl;
				cout << "4.������� A �� �������� ������" << endl;
				cout << "5.������� B �� �������� ������" << endl;
				cin >> d2;
				if ((d2 > 5) || (d2 < 1))  cout << ("������ ������������ ����") << endl;
			} while ((d2 > 5) || (d2 < 1));

			if (d2 == 1)
			{
				cout << "���� �� ������ A*B";
				RES = A * B;
				RES.podobnyi();
				S1 = 1;

				cout << "A*B="; A.showList3(); cout << "*("; B.showList3(); cout << ")="; RES.showList3(); cout << "\n";
				//A.showList();
			}
			if (d2 == 2)
			{
				double koef = 0;
				int x, y, z;
				cout << "������� ������� ������ a:";
				cin >> koef >> x >> y >> z;
				Node ptr(koef, x, y, z);
				RES = A * ptr;
				RES.podobnyi();
				S1 = 1;

				cout << "A*a="; RES.showList3(); cout << "\n";
			}
			if (d2 == 3)
			{
				double koef = 0;
				int x, y, z;
				cout << "������� ������� ������ a:";
				cin >> koef >> x >> y >> z;
				Node ptr(koef, x, y, z);
				RES = B * ptr;
				RES.podobnyi();
				S1 = 1;

				cout << "B*a="; RES.showList3(); cout << "\n";
			}
			if (d2 == 4)
			{
				double scalar = 0;
				cout << "������� ������:";
				cin >> scalar;
				RES = A * scalar;
				RES.podobnyi();
				S1 = 1;

				cout << "A*scalar="; RES.showList3(); cout << "\n";
			}
			if (d2 == 5)
			{
				double scalar = 0;
				cout << "������� ������:";
				cin >> scalar;
				RES = B * scalar;
				RES.podobnyi();
				S1 = 1;

				cout << "B*scalar="; RES.showList3(); cout << "\n";
			}
			break;
		}
		case 6:
		{
			if (S1 == 0) cout << "������ ���������, ������� ���������� ���-������!" << endl;
			else {
				SAVE = RES;
				cout << "��������� ���������� �������!0" << endl;
				S2 = 1;
			}
			break;
		}
		case 7:
		{
			double x = 0, y = 0, z = 0;
			double res = 0;
			cout << "������� ����� ������ �������� x,y,z:" << endl;
			cin >> x;
			cin >> y;
			cin >> z;
			int d3 = 0;
			do {
				cout << "�������� ��������� �������:" << endl;
				cout << "��� ������ �, ������� 1" << endl;
				cout << "��� ������ B, ������� 2" << endl;
				cout << "��� ������ SAVE, ������� 3" << endl;

				cin >> d3;
				if ((d3 > 3) || (d3 < 1))  cout << ("������ ������������ ����") << endl;
			} while ((d3 > 3) || (d3 < 1));

			if (d3 == 1) {
				auto ita = A.begin();
				do {
					ita++;
					res += ((*ita).data.coef) * (pow(x, ((*ita).data.degx))) * (pow(y, ((*ita).data.degy))) * (pow(z, ((*ita).data.degz)));
				} while ((*ita).next != NULL);
				cout << "��������� res=" << res << endl;
				res = 0;
			}
			if (d3 == 2) {
				auto itb = B.begin();
				do {
					itb++;
					res += ((*itb).data.coef) * (pow(x, ((*itb).data.degx))) * (pow(y, ((*itb).data.degy))) * (pow(z, ((*itb).data.degz)));
				} while ((*itb).next != NULL);
				cout << "��������� res=" << res << endl;
				res = 0;

			}
			if (d3 == 3) {
				if (S2 == 0) cout << "SAVE ������, ������� ���������� ���-������ � ���������!" << endl;
				else {
					auto its = SAVE.begin();
					do {
						its++;
						res += ((*its).data.coef) * (pow(x, ((*its).data.degx))) * (pow(y, ((*its).data.degy))) * (pow(z, ((*its).data.degz)));
					} while ((*its).next != NULL);
					cout << "��������� res=" << res << endl;
					res = 0;
				}
			}

			break;
		}
		//system("Pause");
		}
	}
	return 0;
}
