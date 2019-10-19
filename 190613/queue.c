#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 190613 큐 구현

// 공백 큐 확인
int isEmpty(int, int);

// 큐가 가득 찼는지 확인
int isFull(int front, int rear, int q_size);

// 큐에 추가
void en_queue(int *queue, int *rear, int q_size, int data);

// 큐에서 제거
void de_queue(int *queue, int *, int q_size);

// 큐 전체 출력
void printAll(int *, int);

// 테스트용 메인 함수
int main()
{
	int q_size, num_of_instruction, i, data;
	int front = 0, rear = 0;
	int *queue;
	char instruction;

	scanf("%d", &q_size); getchar();
	scanf("%d", &num_of_instruction); getchar();

	queue = (int *)calloc(q_size, sizeof(int)); // calloc 으로 바꾸기

	for (i = 0; i < num_of_instruction; i++)
	{
		scanf("%c", &instruction); getchar();

		if (instruction == 'I')
		{
			scanf("%d", &data); getchar();
			if (q_size == 0)
			{
				printf(" overflow");
				return 0;
			}
			if (isFull(front, rear, q_size) == 1)
			{
				printf(" overflow");
				printAll(queue, q_size);
				return 0;
			}
			else
			{
				en_queue(queue, &rear, q_size, data);
				//printf("AFTER EN-QUEUE %d %d\n", rear, queue[rear]);
			}
		}
		else if (instruction == 'D')
		{
			if (q_size == 0)
			{
				printf(" underflow");
				return 0;
			}
			if (isEmpty(front, rear) == 1)
			{
				printf(" underflow");
				//printAll(queue, q_size);
				return 0;
			}
			else
			{
				de_queue(queue, &front, q_size);
				//printAll(queue, q_size);
			}
		}
		else if (instruction == 'P')
		{
			//printf("%d %d\n", queue[0], queue[1]);
			printAll(queue, q_size);
		}
	}


	return 0;
}

int isEmpty(int front, int rear)
{
	if (rear == front) // 비었으면 1 반환
	{
		return 1;
	}
	else
		return 0;
}

int isFull(int front, int rear, int q_size)
{
	if ((front % q_size) == ((rear + 1) % q_size)) // 꽉 찼으면 1 반환
	{
		return 1;
	}
	else
		return 0;
}

void en_queue(int *queue, int *rear, int q_size, int data)
{
	//printf("en_queue rear = %d ", *rear);
	*rear = (*(rear)+1) % q_size;
	queue[*rear] = data;
	//printf("en_queue rear after = %d\n", *rear);
}

void de_queue(int *queue, int *front, int q_size)
{
	// 삭제시 프론트값 하나 증가시킨후 그 값 0으로 바꿔넣음
	*front = (*(front)+1) % q_size;
	queue[*front] = 0;
}

void printAll(int *queue, int q_size)
{
	int i = 0;
	for (i = 0; i < q_size; i++)
	{
		printf(" %d", queue[i]);
	} printf("\n");
}