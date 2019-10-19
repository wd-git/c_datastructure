#include <stdio.h>
#define MAX 20
// QUEUE

int queue[MAX];
int front, rear = 0;

int put(int k){
	if((rear+1) % MAX == front) {
		printf("�̳༮��� ���� �÷ο��!\n\n");
		return -1;
	} else {
		queue[rear] = k;
		rear = ++rear % MAX;
		return 1;
	}
}

int get(){
	int k;
	if(front == rear) {
		printf("�̳༮��� ��� �÷ο��!\n\n");
		return -1;
	} else {
		k = queue[front];
		front = ++front % MAX;
		return k;
	}
}

void radix_sort(int array[], int size){
	int max = array[0]; // �ִ밪 ����
	int digit = 0; // �ڸ��� ����
	int factor = 1; // �ڸ����� ��Ÿ���� ����, 1���� 10�� ���ϸ鼭 ���

	// ���� ū �� ã��
	for(int i=1; i<size; i++){
		if(max<array[i]) max = array[i];
	}

	// ���� ū ���� �ڸ��� ã��
	for(int i=max; i>0;i/=10){
		digit++;
	}

	for(int i =0; i<digit; i++){ // �ڸ��� ��ŭ �ݺ�
		for(int j=0; j<10; j++){ // 0~9 ���� �ݺ�
			for(int k=0; k<size; k++){ // �迭 ���� ��ŭ �ݺ�
				if((array[k]/factor)%10==j){
					put(array[k]);
				}
			}
		}
		factor *=10;
		
		for(int i=front; i!=rear; i++){
			array[i] =get();
		}

		front=0;
		rear=0;
	}
}
