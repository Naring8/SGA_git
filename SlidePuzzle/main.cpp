#include "Framework.h"
#define SIZE 4

int arr[SIZE][SIZE] =
{
	{1, 2, 3, 4},
	{5, 6, 7, 8},
	{9, 10, 11, 12},
	{13, 14, 15, 0}
};

struct Point
{
	int x;
	int y;
} point;

enum Arrow
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void PrintArr(int arr[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (arr[i][j] == 0)
			{
				cout << "   ";
				continue;
			}
			printf("%2d ", arr[i][j]);
		}
		cout << endl;
	}
}

int CmpArr(int arr1[SIZE][SIZE], int arr2[SIZE][SIZE])
{
	int same = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (arr1[i][j] == arr2[i][j])
				same++;
		}
	}
	return same;
}

void FindBlank(int arr[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (arr[i][j] == 0)
			{
				point.x = i;
				point.y = j;
			}
		}
	}
}

Arrow returnState() 
{
	int i = _getch();

	if (i == 224) 
	{
		i = _getch();

		switch (i) 
		{
		case 75:
			return Arrow::LEFT;
		case 77:
			return Arrow::RIGHT;
		case 72:
			return Arrow::UP;
		case 80:
			return Arrow::DOWN;
		}
	}
}

int main()
{
	int same = 0;

	int myArr[SIZE][SIZE] =
	{
		{ 1,  2,  3,  4},
		{ 5,  6,  7,  8},
		{ 9, 10, 11, 12},
		{13, 14, 15,  0}
	};		// 비어있는 배열 -> arr에서 랜덤으로 받아 순서대로 채워넣는 걸로 변경

	srand(time(NULL));

	PrintArr(myArr);

	cout << "아무 키나 입력하시오." << endl;
	while (_getch() != 0)
	{
		printf(" 시 작 !!");
		Sleep(1000);
		system("cls");
		break;
	}

	//SetPuzzle - 랜덤으로 위치 변경
	for (int i = 0; i < 100; i++)
		Swap(myArr[rand() % 4][rand() % 4], myArr[rand() % 4][rand() % 4]);
		
	
	PrintArr(myArr);

	while (same < 16)
	{
		Arrow state = returnState();

		FindBlank(myArr);

		switch (state)
		{
		case LEFT:
			if ((point.y) - 1 < 0)
				break;
			Swap(myArr[point.x][point.y], myArr[point.x][(point.y) - 1]);
			break;
		case RIGHT:
			if ((point.y) + 1 > 3)
				break;
			Swap(myArr[point.x][point.y], myArr[point.x][(point.y) + 1]);
			break;
		case UP:
			if ((point.x) - 1 < 0)
				break;
			Swap(myArr[point.x][point.y], myArr[(point.x) - 1][point.y]);
			break;
		case DOWN:
			if ((point.x) + 1 > 3)
				break;
			Swap(myArr[point.x][point.y], myArr[(point.x) + 1][point.y]);
			break;
		}

		system("cls");
		PrintArr(myArr);
		cout << "방향키로 빈 칸을 이동시켜 순서를 완성시키세요" << endl;
		same = CmpArr(arr, myArr);
	}
	cout << "Clear!" << endl;

	return 0;
}
