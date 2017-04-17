#include "stdafx.h"
#include "Queen.h"
const int SIZE = 4;
int board[SIZE][SIZE];//������� �����
int resultsCount = 0;
int quantity = 0;

void setQueen(int i, int j)//������ ����� � ��������� ������, ������� ����� ����� ����
{
	for (int x = 0; x < SIZE; ++x)
	{
		++board[x][j];//���������� �� �����������
		++board[i][x];//���������� �� ���������
		int foo;
		foo = j - i + x;
		if (foo >= 0 && foo < SIZE)//���������� �� ���������
			++board[x][foo];
		foo = j + i - x;
		if (foo >= 0 && foo < SIZE)
			++board[x][foo];
	}
	board[i][j] = -1;//-1 ��������, ��� ��� ����� �����
}

void resetQueen(int i, int j)//������� �����
{
	for (int x = 0; x < SIZE; ++x)
	{
		--board[x][j];//�������� �� �����������
		--board[i][x];//�������� �� ���������
		int foo;
		foo = j - i + x;//�� �����������
		if (foo >= 0 && foo < SIZE)
			--board[x][foo];
		foo = j + i - x;
		if (foo >= 0 && foo < SIZE)
			--board[x][foo];
	}
	board[i][j] = 0;
}

void resultQueen()
{

	cout << "Result #" << ++resultsCount << endl;
	printQueen();


}

void tryQueen(int i)//�������� ��������� ����� �� i-�� �������, ���� ��� �������� , �� ���������� true 
{
	int j = 0;

	if (quantity == SIZE)//������ ���� ������ ���������
	{
		resultQueen();
		return;
	}

	for (j = 0; j < SIZE; ++j)
	{
		if (board[i][j] == 0)//����� �� ���� ��� ������
		{
			setQueen(i, j);
			quantity++;
			tryQueen(i + 1);//���� �� ������� ��������� ����� �� ��������� �������
			resetQueen(i, j);
			quantity--;
		}
		/*if (result)// ������� ��������� �����
		break;*/
	}
}

void printQueen()
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			if (board[i][j] == -1)
				cout << " ! ";//�����
			else
				cout << " . "; //���������� �����
		}
		cout << endl;
	}
}

void cleanQueen()
{
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE; ++j)
			board[i][j] = 0;
}