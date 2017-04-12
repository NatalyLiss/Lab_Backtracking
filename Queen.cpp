#include "stdafx.h"
#include "Queen.h"
const int SIZE = 12;
int board[SIZE][SIZE];//������� �����

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

bool tryQueen(int i)//�������� ��������� ����� �� i-�� �������, ���� ��� �������� , �� ���������� true 
{
	bool result = false;
	int j = 0;
	for (j = 0; j < SIZE; ++j)
	{
		if (board[i][j] == 0)//����� �� ���� ��� ������
		{
			setQueen(i, j);
			if (i == SIZE - 1)//������ ���� ������ ���������
				result = true;
			else
			{
				if (!(result = tryQueen(i + 1)))//���� �� ������� ��������� ����� �� ��������� �������
					resetQueen(i, j);
			}
		}
		if (result)// ������� ��������� �����
			break;
	}
	return result;
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