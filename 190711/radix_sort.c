#include <stdio.h>
#define MAX 20
// QUEUE

int queue[MAX];
int front, rear = 0;

int put(int k){
	if((rear+1) % MAX == front) {
		printf("이녀석들아 오버 플로우다!\n\n");
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
		printf("이녀석들아 언더 플로우다!\n\n");
		return -1;
	} else {
		k = queue[front];
		front = ++front % MAX;
		return k;
	}
}

void radix_sort(int array[], int size){
	int max = array[0]; // 최대값 저장
	int digit = 0; // 자릿수 저장
	int factor = 1; // 자릿수를 나타내는 변수, 1부터 10씩 곱하면서 사용

	// 가장 큰 값 찾기
	for(int i=1; i<size; i++){
		if(max<array[i]) max = array[i];
	}

	// 가장 큰 값의 자릿수 찾자
	for(int i=max; i>0;i/=10){
		digit++;
	}

	for(int i =0; i<digit; i++){ // 자릿수 만큼 반복
		for(int j=0; j<10; j++){ // 0~9 까지 반복
			for(int k=0; k<size; k++){ // 배열 길이 만큼 반복
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
