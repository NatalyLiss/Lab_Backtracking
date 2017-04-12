// Backtracking.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Queen.h"


int main()
{
	cleanQueen();
	tryQueen(0);
	printQueen();
	system("pause");
	return 0;
}


