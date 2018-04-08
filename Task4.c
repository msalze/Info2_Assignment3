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
    
	if (listA->root == NULL){
		listA->root = malloc(sizeof(struct node));
		listA->root->val = valA;
		listA->root->next = NULL;
	}
	else{
		struct node* p;
    	p = listA->root;
		while (p->next != NULL){
			p = p->next;
		}
		p->next = malloc(sizeof(struct node));
		p->next->val = valA;
		p->next->next = NULL;
	}
}

void reverse(struct list *listA){
    // more than two nodes
    if(listA->root != NULL || listA->root->next != NULL){

	struct node *p = listA->root;
	struct node *q = p->next;
	struct node *r = q->next;

	while(q != NULL){
	    q->next = p;
	    p = q;
	    q = r;
	    if(r != NULL){
		r = r->next;
	    }
	}
	listA->root->next = NULL;
	listA->root = p;

	// only two nodes
    }else if(listA->root->next != NULL){
	struct node *p = listA->root;
	p->next->next = p;
	p = p->next;
	listA->root->next = NULL;
	listA->root = p;
    }
    
}

void clear(struct list * listA){
	struct node *p,*q;
	p = listA->root;
	q = p->next;
	while (p != NULL){
		free(p);
		p = q;
		if (q!=NULL){
			q = q->next;
		}
	}
	listA->root = malloc(sizeof(struct node));
    listA->root = NULL;
}

void print(struct list * listA){
	struct node * p = listA->root;
	if (p==NULL){
		printf("[ ]\n");
	}
	else{
		printf("[");
		while (p->next!=NULL){
			printf("%d, ", p->val);
			p=p->next;
		}
		printf("%d]\n", p->val);
	}
}

void deleteIndex(struct list * listA, int i){
	struct node *p,*q;
	p = listA->root;
	int n = 0;
	if (i==0){
		q = p->next;
		free(p);
		listA->root=q;
	}else{
		while (i-1>n && p->next !=NULL){
			p = p->next;
			n++;
		}
		if (p->next == NULL){
			free(p->next);
			p->next = NULL;
		}
		else{
		
		q = p->next;
		p->next = p->next->next;
		free(q);
		}
	}
	
}
void deleteLast(struct list * listA){
	if (listA->root !=NULL){
		struct node *p = listA->root;
		if (p->next==NULL){
			free(p);
			listA->root = NULL;
		}
		while (p->next->next !=NULL){
			p=p->next->next;
		}
		free(p->next->next);
		p->next = NULL;
	}
}

void max(struct list * listA){
	struct node *p=listA->root;
	int max = p->val;
	while (p->next !=NULL){
		p = p->next;
		if (p->val > max){
			max = p->val;
		}
	}
	printf("max = %d\n", max);
}

int main(){
    struct list *list = init();
    
    append(list,9);
    append(list,4);
    append(list,5);
    append(list,3);
    append(list,1);
    append(list,2);
    append(list,0);
    
    print(list);

    reverse(list);
    
    print(list);

    deleteIndex(list,6);
    deleteIndex(list,3);
    deleteIndex(list,0);

    print(list);

    deleteLast(list);

    print(list);

    max(list);

    clear(list);

    print(list);

    
    
    free(list);
    
    return 0;
}

