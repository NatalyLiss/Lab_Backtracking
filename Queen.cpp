#include "stdafx.h"
#include "Queen.h"

const int SIZE = 4;
int board[SIZE][SIZE];//ìàòðèöà ÿ÷ååê
int resultsCount = 0;
int quantity = 0;


void setQueen(int i, int j)//ñòàâèì ôåðçÿ è çàïîëíÿåì ÿ÷åéêè, êîòîðûå ôåðçü áóäåò áèòü
{
	for (int x = 0; x < SIZE; ++x)
	{
		++board[x][j];//ïðèáàâëÿåì ïî ãîðèçîíòàëè
		++board[i][x];//ïðèáàâëÿåì ïî âåðòèêàëè
		int foo;
		foo = j - i + x;
		if (foo >= 0 && foo < SIZE)//ïðèáàâëÿåì ïî äèàãîíàëè
			++board[x][foo];
		foo = j + i - x;
		if (foo >= 0 && foo < SIZE)
			++board[x][foo];
	}
	board[i][j] = -1;//-1 îçíà÷àåò, ÷òî òàì ñòîèò ôåðçü
}

void resetQueen(int i, int j)//óäàëÿåì ôåðçÿ
{
	for (int x = 0; x < SIZE; ++x)
	{
		--board[x][j];//îòíèìàåì ïî ãîðèçîíòàëè
		--board[i][x];//îòíèìàåì ïî âåðòèêàëè
		int foo;
		foo = j - i + x;//ïî ãîðèçîíòàëè
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

void tryQueen(int i)//ïûòàåòñÿ ïîñòàâèòü ôåðçÿ íà i-ûé ñòîëáåö, åñëè ýòî óäàñòüñÿ , òî âîçâðàùàåò true 
{
	int j = 0;

	if (quantity == SIZE)//çíà÷èò âñåõ ôåðçåé ïîñòàâèëè
	{
		resultQueen();
		return;
	}

	for (j = 0; j < SIZE; ++j)
	{
		if (board[i][j] == 0)//íèêòî íå áüåò ýòó ÿ÷åéêó
		{
			setQueen(i, j);

			quantity++;
			tryQueen(i + 1);//åñëè íå óäàëîñü ïîñòàâèòü ôåðçÿ íà ñëåäóþùèé ñòîëáåö
			resetQueen(i, j);
			quantity--;
		}
		/*if (result)// óäàëîñü ïîñòàâèòü ôåðçÿ
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
				cout << " ! ";//ôåðçü
			else
				cout << " . "; //îòñóòñòâèå ôåðçÿ
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