﻿#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include "list.h"
using namespace std;

class Monom
{ public:
  double coeff; 
  unsigned int abc;
  // конструкторы
  Monom(double COEFF = 0, unsigned int ABC = 0);
  // перегрузка операций
  bool operator< (const Monom& m) const { return (abc < m.abc); }
  bool operator> (const Monom& m) const { return (abc > m.abc); }
  bool operator==(const Monom& m) const { return (abc == m.abc && coeff == m.coeff); }	
  bool operator!=(const Monom& m) const { return !(*this == m); }
  Monom& operator=(const Monom& m) { coeff = m.coeff; abc = m.abc; return *this; }
};

class Polynom 
{ protected:
  List<Monom> M1;
  public:
  // Конструкторы
  Polynom();
  Polynom(int n, const int m[][2]);
  Polynom(string S);
  Polynom(const Polynom& P) : M1(P.M1) {};  // конструктор копирования
  //Методы
  void Clean();
  double Сalculate();
  // Перегрузка операций
  Polynom operator+(const Monom& monom) const;
  Polynom operator+ (const Polynom& P) const;
  Polynom operator- (const Polynom& P) const { return (*this + P * (-1.0)); }
  Polynom operator* (const Polynom& P) const; 
  Polynom operator* (const double c) const; 
  Polynom operator* (const Monom& monom) const;
  bool operator== (const Polynom& POL) const { return M1 == POL.M1; }
  bool operator!= (const Polynom& POL) const { return M1 != POL.M1; } 
  //Перегрузка ввода и вывода
  friend ostream& operator<< (ostream& os, const Polynom& P)
  { Polynom tmp = P;
	tmp.M1.Reset();
	tmp.M1.SetNext();
	/*while (!(tmp.M1.IsEnd())) //технический вывод
	{ os << tmp.M1.GetIT()->data.coeff << " " << tmp.M1.GetIT()->data.abc << "\t";
	  tmp.M1.SetNext();
	}*/
	Node<Monom>* First =tmp.M1.GetIT();
	Node<Monom>  Mon;
	while (!(tmp.M1.IsEnd()))
	{ Mon = tmp.M1.GetIT()->data;
	  if (Mon.data.coeff > 0 && tmp.M1.GetIT() != First) // вывод + между мономов
	  { os << " + ";}
	  if (Mon.data.coeff != 1 && Mon.data.coeff != -1 && Mon.data.coeff !=0) // вывод коэффицента
	  {os << Mon.data.coeff; if (Mon.data.abc!=0){cout <<"*";} }
	  else
		{ if (Mon.data.coeff == -1 && Mon.data.abc != 0) // вывод (-1)xyz
		  { os << " - ";}
		  else 
		  { if  ((Mon.data.coeff == 1 || Mon.data.coeff == -1 )&& Mon.data.abc == 0) // вывод 1 и (-1)
		    {os << Mon.data.coeff;}   
		  }
		}
	  int f[3] = { 100,10,1 };
	  char c[3] = { 'x','y','z' };
	  for (int i = 0; i < 3; i++)
		{ if (Mon.data.abc / f[i] % 10 != 0)
		  { os << c[i];
		    if (Mon.data.abc / f[i] % 10 != 1)
			{ os << '^' << Mon.data.abc / f[i] % 10;}
		  }
		}
	  tmp.M1.SetNext();
	}
	tmp.M1.Reset();
	return os;
}
  friend istream& operator>>(istream& in, Polynom& P)
  { // Ввод строкой
	string S; 
	cout << "\t";
	in>>S;
	P = Polynom(S);
	/* 
	// Последовательный ввод мономов
    int n = 0, a, b, c, d;
    cout << "\n\tSpecify  the number of monoms to be entered.\n\tInput: ";
	in >> n; system("cls");
	if(n!=0)
	{cout << "\n\tEnter the following monomial of the polynomial: sequentially enter first the coefficient and then the degrees for the variables x,y,z. \n\t!!! Note that the degrees must be in the diopozone from 0 to 9 !!! \n\n\tInput: ";
	in >> a >> b >> c >> d; 
	if ((b > 10)||(c >10)||(d>10)|| (b < 0) || (c < 0) || (d < 0)){ throw 1; }
	Monom M(a, b * 100 + c * 10 + d);
	P = P + M;
	system("cls");}
	for (int i = 1; i < n; i++)
	{ cout  << "\n\t\tALREADY ENTERED: " << P << "\n\n\tEnter the following monomial of the polynomial : sequentially enter first the coefficientand then the degrees for the variables x, y, z. \n\t!!!Note that the degrees must be in the diopozone from 0 to 9 !!!\n\n\tInput: ";
	  in >> a >> b >> c >> d;
	  if ((b > 10) || (c > 10) || (d > 10) || (b < 0) || (c < 0) || (d < 0)) { throw 1; }
	  Monom M2(a, b * 100 + c * 10 + d);
	  P = P + M2;
	  system("cls");
	}
	cout << "\n\t\t ENTERED: " << P;*/
	return in;
  }
};

// Pелизации для моноома
Monom::Monom(double COEFF, unsigned int ABC)
{ if (ABC > 999) { throw 1; }  
  coeff = COEFF; 
  abc = ABC;
}

// Pелизации для полинома
Polynom::Polynom()
{ //создание фиктивного звена
	Monom tmp;
	tmp.coeff = 0;
	tmp.abc = -1;
	M1.InsertToTail(tmp);
}
Polynom::Polynom(int n, const int M[][2])
{ //создание фиктивного звена
	Monom tmp;
	tmp.coeff = 0;
	tmp.abc = -1;
	M1.InsertToTail(tmp);
	//прибавление остальных мономов
	for (int i = 0; i < n; i++)
	{
		if ((M[i][0] > 10) || (M[i][0] < 0)) { throw 1; }
		tmp.coeff = M[i][0];
		tmp.abc = M[i][1];
		*this = *this + tmp;
	}
}
Polynom::Polynom(string S)
{ string M, P = S;
  int k = 1;
  int d[] = {100, 10, 1 };
  char c[] = { 'x', 'y', 'z'};
  Monom tmp;
  Polynom P1;
  while (P.length())
  { k = 1;  tmp.abc = 0;  tmp.coeff = 0;
	while ((P[k] != '-') && (P[k] != '+') &&( k < P.length()))
	{ k++; }
	M = P.substr(0, k);
	P.erase(0, k);
	if (M[0] == '-')
	{ tmp.coeff = -1;
	  M.erase(0, 1);
	} 
	else
	{ tmp.coeff = 1;
	  if (M[0] == '+')
	  { M.erase(0, 1);}
	}
	if (isdigit(M[0])) //isdigit - если десятичное число
	{ k = 0;
	  while ((isdigit(M[k])) || (M[k] == '.'))
	  { k++;}
	  tmp.coeff *= std::stod(M.substr(0, k));
	  M.erase(0, k);
	}
	for (int i = 0; i < 3; i++)
	{ int pos = M.find(c[i]);
	  if (pos != -1)
	  { if (M[pos + 1] == '^')
	    { tmp.abc = tmp.abc + d[i] * std::stoi(M.substr(pos + 2, 1));	}
		else
	    {tmp.abc += d[i];}
	  }
	}
	P1=P1+tmp;
  }
  *this = P1;
}
void Polynom::Clean()
{ M1.Clean();
  Monom tmp;
  tmp.coeff = 0;
  tmp.abc = -1;
  M1.InsertToTail(tmp);
}
double Polynom::Сalculate()
{   double res=0,x,y,z;
    int t;
    cout<< "\n\tEnter the values of the variables in the xyz sequence.\n\tInput: ";
	cin >> x >> y >> z;
	List<Monom>  P2 = M1;
	P2.Reset();
	P2.SetNext(); // пропускаем фиктивное звено

	while (!P2.IsEnd())
	{   t= P2.GetIT()->data.abc;
		res = res + (P2.GetIT()->data.coeff)*pow(x,t/100)*pow(y,t%100/10)*pow(z,t%10);
		P2.SetNext();
	}
	return res;
}
Polynom Polynom::operator+(const Monom& MOL) const
{	Polynom P1;
    Node <Monom>* T;
    int f = 0;
	P1.M1=M1; // присваиваем текущий список
	P1.M1.Reset(); // указатель на голову
	T = P1.M1.GetIT();
	P1.M1.SetNext(); // пропускаем фиктивное звено
	while (!P1.M1.IsEnd()) // пока списки не закончиличь идем
	{ if (P1.M1.GetIT()->data.abc > MOL.abc) //если степень больше, то идем дальше по списку
	  { T = P1.M1.GetIT();
	    P1.M1.SetNext();}
	  else 
	  { if ((P1.M1.GetIT()->data.abc < MOL.abc)) // ecли степень меньше, то вставляем моном
		{ if(MOL.coeff!=0)
		  { P1.M1.InsertAfter(T, MOL);
		    P1.M1.End();
		    f = 1;
	       }
		}
		else // случай равенства коэффицентов
		{ double cf = P1.M1.GetIT()->data.coeff + MOL.coeff;
		  if (cf) // ecли не ноль
		  { P1.M1.GetIT()->data.coeff = cf; 
		    P1.M1.End();
			f = 1;
		  }
		  else
		  { P1.M1.Delete(P1.M1.GetIT());
			P1.M1.End();
			f = 1;
		  }
		}
      }
	}
	//если полином пуст просто вставить звено
	if((f==0)&& (MOL.coeff != 0))
	{P1.M1.InsertAfter(T, MOL); }
	return P1;
}
Polynom Polynom::operator+(const Polynom& POL) const
{
	Polynom P1;
	P1.M1 = M1;
	List<Monom>  P2 = POL.M1;
	P2.Reset();
	P2.SetNext(); // пропускаем фиктивное звено

	while (!P2.IsEnd())
	{
		P1 = P1 + P2.GetIT()->data;
		P2.SetNext();
	}
	return P1;
}
Polynom Polynom::operator*(const double c) const
{ Polynom res;
  if (c)
  { res = *this;
	res.M1.Reset();
	while (!(res.M1.IsEnd()))
	{ res.M1.GetIT()->data.coeff *= c;
	  res.M1.SetNext();
	}
  }
  else
  { res.M1.Clean(); }
  return res;
}
Polynom Polynom::operator* (const Monom& MOL) const
{	Polynom res;
	Polynom P1;
	Monom tmp;
	P1.M1 = M1;
	int a;
	double c;
	P1.M1.Reset();
	P1.M1.SetNext(); 
	while (!P1.M1.IsEnd())
	{ a = P1.M1.GetIT()->data.abc;
	  c = P1.M1.GetIT()->data.coeff;
	  if ((MOL.abc % 10 + a % 10) < 10 && (MOL.abc / 10 % 10 + a / 10 % 10) < 10 && (MOL.abc / 100 + a / 100) < 10)
	  { Monom tmp;
		tmp.coeff = MOL.coeff*c;
		tmp.abc = MOL.abc+a;
		res = res + tmp;
		P1.M1.SetNext();
	  }
	  else
	  {	throw 1;}
	}
	return res;

}
Polynom Polynom::operator*(const Polynom& POL) const
{ Polynom P1, r;
  P1.M1 = M1;
  List<Monom>  P2 = POL.M1;
  P2.Reset();
  P2.SetNext(); // пропускаем фиктивное звено
  while (!P2.IsEnd())
  { r = r + P1 * P2.GetIT()->data;
	P2.SetNext(); 
  }
  return r;
}
