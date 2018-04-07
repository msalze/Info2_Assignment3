#include <stdio.h>
#include <stdlib.h>


struct node{
	int val;
	struct node* next;
};


struct list{
	struct node* root;
};

struct list* init(){
	struct list * list = malloc(sizeof(struct list));
	list->root = NULL;
	return list;
}

void append(struct list * listA, int valA){
    struct node *p,*q;
    p = listA->root;
	if (p == NULL){
		p = malloc(sizeof(struct node));
		p->val = valA;
		p->next = NULL;
	}
	while (p != NULL){
		p = p->next;
	}
	p = p->next;
	p = malloc(sizeof(struct node));
	p->val = valA;
	p->next = NULL;
}

void reverse(struct list * listA){
	int *p,*q;
	p = listA->root;
	
}

void clear(struct list * listA){
	
}

void print(struct list * listA){
	struct node * p = listA->root;
	while (p!=NULL){
		printf("%d", p->val);
		p -> next;
	}
}

void deleteIndex(struct list * listA, int i){
	
}
void deleteLast(struct list * listA){
	
}

void max(struct list * listA){
	
}

void main(){
	struct list *list = init();
	append(list,9);
	append(list,4);
	append(list,5);
	append(list,3);
	append(list,1);
	append(list,2);
	append(list,0);
	print(list);
}

