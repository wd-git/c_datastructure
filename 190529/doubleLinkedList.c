#include <stdio.h>
#include <stdlib.h>

/* 
2019.05.29

���� ���Ḯ��Ʈ�� �����ΰ�?
���ݱ��� �̷� ����Ʈ�� ������.
�޳�Ʈ �Ӹ��ƴ϶� �ճ�嵵 ��������� ���� ����Ʈ
 
���ټ� �� -> ���ݱ����� �޳�带 �˾ƾ��� ���� ������ �����ߴ�.
https://doublesprogramming.tistory.com/229
*/

typedef struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
}node;

node *head, *tail;

/// head, tail �ʱ�ȭ! �ͼ��Կ� �Ӿ� �ʱ�ȭ�� ��������
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

//�� ��� �Ҵ�
node* makeNewNode (int data)
{
	node * p =(node*)malloc(sizeof(node));
	p->data =data;
	p->next =NULL;
	p->prev =NULL;
	return p;
}

//����Ʈ
void print() {
	node * p;
	p = head->next;

	while(p->next != tail ) {
		printf("%d--",p->data);
		p=p->next;
	}

	printf("%d",p->data);
}

// ���Ḯ��Ʈ ����(�߰��ؾ��� �����͸� �Է¹���) //??? ��������?
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

// add 1-> �Ǿտ� �߰�
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

// add 2 -> Ư�� ��ġ�� �߰� ?? �ε����� �߰�? ->> ���� ���� prev ����� ���� �ȵ�
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

// remove1 -> Ư���ε��� ����
void remove_s(int index){
	node* target = search(index);

	node* temp =  target->prev;
	temp->next = target->next;

	temp = target->next;
	temp->prev = target->prev;
}

// remove2 -> �������� ����
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

// data���� ���� data������ mul�� ����� ���� �༮���� ������ ���� 
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

	// ��� �յ� �ֵ鵵 �ٲ���� ��.. �ٵ� ��ͼ� ���ϰھ�.. ���� zzz
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
    	end = mid; // Ʈ������ �̵��� ����
        mid = start; // �̵��� ���带 ���� (ù ������ ����)
        start = start->next; // ����� �ڽ��� �� ��带 ����
        mid->next = end; // �̵��� Ʈ������ ����Ŵ

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
