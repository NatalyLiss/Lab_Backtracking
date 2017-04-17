// Backtracking.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include "Queen.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << " Ëàáîðàòîðíàÿ ¹2. Çàäà÷à î ôåðçÿõ." << endl;
	cout << " Íóæíî ðàññòàâèòü ôåðçåé íà äîñêå òàê, ÷òîáû îíè íå áèëè äðóã äðóãà. " << endl;
	cleanQueen();
	tryQueen(0);
	system("pause");
	return 1;
}


