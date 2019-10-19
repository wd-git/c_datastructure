#include <stdio.h>
#include <stdlib.h>

/* 
2019.05.29

이중 연결리스트는 무엇인가?
지금까지 이런 리스트는 없었다.
뒷노트 뿐만아니라 앞노드도 멤버변수로 갖는 리스트
 
접근성 편리 -> 지금까지는 뒷노드를 알아야지 삽입 삭제가 가능했다.
https://doublesprogramming.tistory.com/229
*/

typedef struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
}node;

node *head, *tail;

/// head, tail 초기화! 익숙함에 속아 초기화를 잊지말자
void init(){
	 head = (node*)malloc(sizeof(node));
	 tail = (node*)malloc(sizeof(node));

	 head->data=0;
	 tail->data=0;
	 
	 head->next = tail;
	 head->prev = head;
	 tail->prev = head;
	 tail->next = tail;
}

//새 노드 할당
node* makeNewNode (int data)
{
	node * p =(node*)malloc(sizeof(node));
	p->data =data;
	p->next =NULL;
	p->prev =NULL;
	return p;
}

//프린트
void print() {
	node * p;
	p = head->next;

	while(p->next != tail ) {
		printf("%d--",p->data);
		p=p->next;
	}

	printf("%d",p->data);
}

// 연결리스트 생성(추가해야할 데이터를 입력받음) //??? 가변인자?
void create(){

}

node* search(int index){
	int count = 0;
	node *target = head->next;

	while(count != index){
		target = target->next;
		count ++;
	}
	
	return target;
}

// add 1-> 맨앞에 추가
void addFirstNode(int data){
	node *newNode = makeNewNode(data);

	node *temp = head->next;
	temp->prev = newNode;

	newNode->next = temp;
	newNode->prev = head;

	head->next = newNode;

	if(newNode->next  == NULL){
		tail = newNode;
	}
}

// add 2 -> 특정 위치에 추가 ?? 인덱스로 추가? ->> 문제 있음 prev 제대로 구현 안됨
void add(int index, int data){
	node* target = search(index);
	node* tempPrev = target->prev;
	node* newNode = makeNewNode(data);
	tempPrev->next = newNode;

	newNode->prev = tempPrev;
	newNode->next = target;

	if(newNode->next == NULL){
		tail = newNode;
	}
}

// remove1 -> 특정인덱스 삭제
void remove_s(int index){
	node* target = search(index);

	node* temp =  target->prev;
	temp->next = target->next;

	temp = target->next;
	temp->prev = target->prev;
}

// remove2 -> 내용으로 삭제
void removeByData(int data){
	int count = 0;
	node *target = head->next;

	while(target->data != data ){
		target = target -> next;
	}
	node* temp =  target->prev;
	temp->next = target->next;

	temp = target->next;
	temp->prev = target->prev;

}

// data값을 비교해 data갑으로 mul의 배수를 가진 녀석들을 모조리 삭제 
void removeMul(int mul){
	node *target = head->next;

	while(target->next != tail) {
		if(target->data % mul == 0){
		 	removeByData(target->data);
		 }
		 target = target->next;
	 }
}

void swap(int a,  int b) {
	node* node1 = search(a);
	node* node2 = search(b);

	// 얘들 앞뒤 애들도 바꿔줘야 돼.. 근데 잠와서 못하겠엉.. 수고링 zzz
	node *temp = node1->next;
	node1->next = node2->next;
	node2->next = temp;

	printf("%d",node1->next->data);
	printf("%d",node2->next->data);
	

	temp = node1->prev;
	node1->prev = node2->prev;
	node2->prev = temp;

	printf("%d",node1->prev->data);
	printf("%d",node2->prev->data);
	
	
	temp = node1->prev;
	temp->next = node1;

	temp = node2->prev;
	temp->next = node2;

	
	printf("%d",search(3)->prev->data);
	
	
}
void printRe(){
	node * p;
	p = tail->prev;

	while(p->prev != head ) {
		printf("%d--",p->data);
		p=p->prev;
	}

	printf("%d",p->data);
}

void reverse() {
	node *start = makeNewNode(0);
	node *mid = makeNewNode(0);
	node *end = makeNewNode(0);
    
	start = head->next;
    while (start != NULL) {
    	end = mid; // 트레일은 미들을 따라감
        mid = start; // 미들은 리드를 따라감 (첫 노드부터 시작)
        start = start->next; // 리드는 자신의 뒷 노드를 따라감
        mid->next = end; // 미들은 트레일을 가리킴

    }
}

void main(){
	init();

	addFirstNode(5);
	addFirstNode(4);
	addFirstNode(3);
	addFirstNode(2);
	addFirstNode(1);

	add(1,9);
	add(2,6);
	add(3,10);
	print();

	printf("\n remove_s(3) \n");
	remove_s(3);
	print();

	printf("\n removeByData(6) \n");
	removeByData(6);
	print();
	printf("\n re :");
	printRe();

	printf("\n removeMul(2) \n");
	removeMul(2);
	print();

	printf("\n 7 9 first add \n");
	addFirstNode(7);
	addFirstNode(9);
	printf("\n");
	print();
	printf("\n re : ");
	printRe();

	printf("\n swap(0,2) \n");	
	swap(0,2);
	printf("\n");
	print();
	printf("\n re : ");
	printRe();

	printf("\n reverse() \n");
	reverse();
	printf("\n");
	printRe();
	
	getchar();
}
