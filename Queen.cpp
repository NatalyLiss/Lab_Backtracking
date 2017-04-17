#include "stdafx.h"
#include "Queen.h"
const int SIZE = 4;
int board[SIZE][SIZE];//матрица €чеек
int resultsCount = 0;
int quantity = 0;

void setQueen(int i, int j)//ставим ферз€ и заполн€ем €чейки, которые ферзь будет бить
{
	for (int x = 0; x < SIZE; ++x)
	{
		++board[x][j];//прибавл€ем по горизонтали
		++board[i][x];//прибавл€ем по вертикали
		int foo;
		foo = j - i + x;
		if (foo >= 0 && foo < SIZE)//прибавл€ем по диагонали
			++board[x][foo];
		foo = j + i - x;
		if (foo >= 0 && foo < SIZE)
			++board[x][foo];
	}
	board[i][j] = -1;//-1 означает, что там стоит ферзь
}

void resetQueen(int i, int j)//удал€ем ферз€
{
	for (int x = 0; x < SIZE; ++x)
	{
		--board[x][j];//отнимаем по горизонтали
		--board[i][x];//отнимаем по вертикали
		int foo;
		foo = j - i + x;//по горизонтали
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

void tryQueen(int i)//пытаетс€ поставить ферз€ на i-ый столбец, если это удастьс€ , то возвращает true 
{
	int j = 0;

	if (quantity == SIZE)//значит всех ферзей поставили
	{
		resultQueen();
		return;
	}

	for (j = 0; j < SIZE; ++j)
	{
		if (board[i][j] == 0)//никто не бьет эту €чейку
		{
			setQueen(i, j);
			quantity++;
			tryQueen(i + 1);//если не удалось поставить ферз€ на следующий столбец
			resetQueen(i, j);
			quantity--;
		}
		/*if (result)// удалось поставить ферз€
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
				cout << " ! ";//ферзь
			else
				cout << " . "; //отсутствие ферз€
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