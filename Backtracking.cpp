// Backtracking.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Queen.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << " ������������ �2. ������ � ������." << endl;
	cout << " ����� ���������� ������ �� ����� ���, ����� ��� �� ���� ���� �����. " << endl;
	cleanQueen();
	tryQueen(0);
	printQueen();
	system("pause");
	return 0;
}


