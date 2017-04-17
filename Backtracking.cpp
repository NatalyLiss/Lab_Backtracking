// Backtracking.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Queen.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << " Лабораторная №2. Задача о ферзях." << endl;
	cout << " Нужно расставить ферзей на доске так, чтобы они не били друг друга. " << endl;
	cleanQueen();
	tryQueen(0);
	system("pause");
	return 1;
}


