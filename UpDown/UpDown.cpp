#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 101

/*
UP DOWN 게임

0~100까지 랜덤 숫자가 정해지고

사용자가 숫자를 입력할 때 마다

UP/DOWN 표시가 출력이 된다

숫자를 맞출 때 까지 진행

입력할 때 마다 입력한 숫자를 배열에 추가하고,

맨 마지막에 입력한 순서대로 출력

​
TIP : 배열의 크기를 넉넉하게 잡아 둘 것(ex. 100)
*/

int main()
{	
	// 랜덤 숫자 생성
	srand(time(NULL));
	int num = rand() % 101;

	// 크기가 100인 배열 생성 ,  전부 0으로 초기화
	int arr[MAX_SIZE] = {};

	// for문을 돌릴 크기 (입력받은 값의 총 개수)
	int size = 0;

	// 입력받은 숫자를 저장할 변수
	int input = 101;
	
	printf("숫자를 입력하시오.(0 ~ 100 사이의 정수) : ");
	scanf_s("%d", &input);

	while (num != input)
	{
		if (input >= 0 && input <= 100)
		{
			arr[size] = input;
			size++;
			if (input > num)
			{
				printf("DOWN\n");
			}
			else
			{
				printf("UP\n");
			}
		}
		else
		{
			printf("정확한 숫자를 입력하시오.(0 ~ 100 사이의 정수) : ");
			scanf_s("%d", &input);
			continue;
		}
		printf("숫자를 입력하시오.(0 ~ 100 사이의 정수) : ");
		scanf_s("%d", &input);
	}

	printf("\n정답입니다!\n");
	printf("[지금까지 입력한 숫자]\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\"%d\"\n", input);

	return 0;
}
