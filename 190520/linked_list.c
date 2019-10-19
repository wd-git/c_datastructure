#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//노드 하나 struct
typedef struct node{
	void * dataptr;
	struct node *next;
}NODE;

//리스트 구조
typedef struct{
	int count;
	NODE *front;
	NODE *rear;
	NODE *pos;
}LIST;

LIST *create_list();
bool add_node(LIST *,int,void *);
void *del_node(LIST *,int);
void del_duplication(LIST *);
void destroy_list(LIST *);

// 리스트 생성
LIST *create_list(){
	LIST *new_list;

	new_list = (LIST *)malloc(sizeof(LIST));
	if( new_list == NULL ){
		perror("create list error\n");
		exit(EXIT_FAILURE);
	}

	new_list->front = NULL;
	new_list->rear = NULL;
	new_list->pos = NULL;
	new_list->count = 0;

	return new_list;
}

// 노드 추가
bool add_node(LIST *list_head,int index,void *factor){
	int itr;
	NODE *new_node;
	
	new_node = (NODE *)malloc(sizeof(NODE));
	if( new_node == NULL ){
		perror("create new node error\n");
		return false;
	}

	new_node->dataptr = factor;
	new_node->next = NULL;

	if( index > (list_head->count) ){
		printf("index is over\n");
		return false;
	}

	if( list_head->count == 0 ){
		list_head->front = new_node;
		list_head->rear = new_node;
		(list_head->count)++;
		return true;
	}
	
	if( index == 0 ){
		new_node->next = list_head->front;
		list_head->front = new_node;
		(list_head->count)++;
		return true;
	}

	itr = 1;
	list_head->pos = list_head->front;
	while( itr != index ){
		itr++;
		list_head->pos = list_head->pos->next;
	}

	if( itr == list_head->count ){
		list_head->rear->next = new_node;
		list_head->rear = new_node;
		(list_head->count)++;
	}
	else{
		new_node->next = list_head->pos->next;
		list_head->pos->next = new_node;
		(list_head->count)++;
	}
	return true;
}

// 노드 삭제
void *del_node(LIST *list_head,int index){
	int itr;
	void *del_dataptr;
	NODE *del_node;
	NODE *pre_node;

	if( list_head->count == 0 ){
		printf("no data in list\n");
		return false;
	}

	if( index >= (list_head->count) ){
		printf("index is over\n");
		return false;
	}

	if( list_head->count == 1 ){
		del_node = list_head->front;
		del_dataptr = del_node->dataptr;
		list_head->front = list_head->rear = NULL;
		free(del_node);
		(list_head->count)--;
		return del_dataptr;
	}
		
	if( index == 0 ){
		del_node = list_head->front;
		del_dataptr = del_node->dataptr;
		list_head->front = del_node->next;
		free(del_node);
		(list_head->count)--;
		return del_dataptr;
	}

	itr = 1;
	pre_node = list_head->front;
	del_node = pre_node->next;

	while( itr != index ){
		itr++;
		pre_node = del_node;
		del_node = pre_node->next;
	}

	if( itr == (list_head->count-1) ){
		del_dataptr = del_node->dataptr;
		list_head->rear = pre_node;
		pre_node->next = NULL;
		free(del_node);
		(list_head->count)--;
	}
	else{
		del_dataptr = del_node->dataptr;
		pre_node->next = del_node->next;
		free(del_node);
		(list_head->count)--;
	}
	return del_dataptr;
}

//중복 (값) 제거 처리
void del_duplication(LIST *list_head){
	int value;
	int cmp_value;
	NODE *value_node;
	NODE *pre_cmp_node;
	NODE *cmp_node;
	
	value_node = list_head->front;
	while( value_node != NULL ){
		value = *((int *)value_node->dataptr);
		pre_cmp_node = value_node;
		cmp_node = pre_cmp_node->next;
		while( cmp_node != NULL){
			cmp_value = *((int *)cmp_node->dataptr);
			if( value == cmp_value ){
				pre_cmp_node->next = cmp_node->next;
				free(cmp_node->dataptr);
				free(cmp_node);
				(list_head->count)--;
				cmp_node = pre_cmp_node->next;
			}
			else{
				pre_cmp_node = cmp_node;
				cmp_node = pre_cmp_node->next;
			}
		}
		value_node = value_node->next;
	}
}

// 리스트 전체 삭제
void destroy_list(LIST *list_head){
	NODE *del_node;

	while( list_head->front != NULL ){
		del_node = list_head->front;
		list_head->front = del_node->next;
		free(del_node->dataptr);
		free(del_node);
	}

	free(list_head);
}



