// oop2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>

const int N = 8;

struct spis{
	int data;
	spis *next;
};

int obhod(spis* head){
	spis* p = head->next;
	int calc = 0;
	while(p){
		p=p->next;
		calc++;
	}
	return calc;
}

spis* search_prev(spis* head,int key) {
	spis* p=head;
	while(p->next)
		if(p->next->data==key) return p;
		else p=p->next;
		return NULL;
}

spis* search(spis* head, int key){
	spis* p = head;
	while(p)
		if (p->data == key) return p;
		else p = p->next;
	return NULL;
}

void add(spis* head){
	spis* p;
	system("cls");
	int after, what;
	printf("After which one?\n");
	scanf_s("%i", &after);
	spis* k = search(head, after);
	if (k == NULL) { printf("Wrong element K\n"); system("pause&&cls"); return; }
	printf("Enter data to add\n");
	scanf_s("%i",&what);
	spis* temp;	
	temp = k->next;
	p = new spis;
	p->data = what;
	k->next = p;
	p->next = temp;	
	system("cls");
}

void del(spis* head){
	int key;
	system("cls");
	printf("Which element delete?");
	scanf_s("%i",&key);
	spis* p = search_prev(head,key);
	if (p == NULL) return;
	spis* temp = p->next;
	if (p->next->next) p->next = p->next->next;
	else p->next = NULL;
	delete (temp);
}

void printSpis(spis* head){
	spis* p = head->next;
	while(p){
		if (p->next != NULL) printf("%i -> ",p->data);
		else printf("%i",p->data);
		p = p->next;
	}
}

void move(spis* head){
	spis *p, *q;
	int what, where;
	printf("What to move?\n");
	scanf_s("%i",&what);
	printf("Where move?");
	scanf_s("%i",&where);
	p = search_prev(head,what);
	q = search_prev(head, where);
	if (q->next == p || p->next == q){
		if (q->next == p){ 
			spis* temp = q->next->next;
			q->next = p->next;
			p->next = q->next->next;
			q->next->next = p;
		}
		if (p->next == q){
			spis* temp=q->next->next;
			p->next=q->next;
			q->next=p->next->next;
			p->next->next = q;
		}
	}
	else{
		spis* temp = q->next->next;
		q->next->next = p->next->next;
		p->next->next=temp;
		temp = q->next;
		q->next = p->next;
		p->next = temp;
	}
}

int main()
{
	spis* head, *p;
	head=new spis;
	p = head;
	for (int i = 0; i < N; i++){
		p->next = new spis;
		p = p->next;
		p->data = rand()%100 + 100;
		p->next = NULL;

	}
	
	int key = 0;
	while(1){
		printSpis(head);
		printf("\nLab 1-2\n1. Add after K-element \n2. Delete element K\n3. Calculate N elements\n4. Move element P into K\n5. Exit\n");
		scanf_s("%i",&key);
		switch(key)
		{
		case 1:
			add(head);
			break;
		case 2:
			del(head);
			break;
		case 3:
			system("cls");
			printf("Vsego %i elementov v spiske\n",obhod(head));
			system("pause&&cls");
			break;
		case 4:
			system("cls");
			printSpis(head);
			move(head);
			break;
		case 5:
			return 0; 
		default:
			system("cls");
			break;
		}
	
	}

    return 1;
}

