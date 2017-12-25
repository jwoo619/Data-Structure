#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	int data;
	struct Node * pre;
	struct Node * next;
}Node;

Node * Head;
Node * Tail;

void Insert(){

	int data;
	printf("Insert data : ");
	scanf("%d",&data);
	printf("\n");

	Node * NewNode;
	NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = data;
	NewNode->pre = NULL;
	NewNode->next = NULL;

	if(Head == NULL)
		Head = NewNode;

	else if(Tail == NULL){
		Tail = NewNode;
		Head->next = Tail;
		Tail->pre  = Head;
	}

	else{
		NewNode->pre = Tail;
		Tail->next = NewNode;
		Tail = NewNode;
	}
	
}

void Delete(){

	if(Head == NULL)
		return;

	int key;
	printf("Delete Node Data : ");
	scanf("%d",&key);

	Node * DeleteNode;

	if(Head->data == key){
		DeleteNode = Head;
		Head = Head->next;
		free(DeleteNode);
	}
	else if(Tail->data == key){
		DeleteNode = Tail;
		Tail = Tail->pre;
		Tail->next = NULL;
		free(DeleteNode);
	}
	else{
		Node * Temp;
		Temp = Head->next;
		while(Temp->next != NULL){
			if(Temp->data == key){
				DeleteNode = Temp;
				Temp->pre->next = Temp->next;
				Temp->next->pre = Temp->pre;
				free(DeleteNode);
				return;
			}
			Temp = Temp->next;
		}
	}

	printf("No Data\n\n");


}

void View(){

	Node * Temp;
	Temp = Head;

	while(Temp!=NULL){
		printf("  %d\n",Temp->data);
		printf("-----\n");
		Temp = Temp->next;
	}
	printf("\n\n");

}

int main(){

	

	int key = 0;
	while(1){
		printf("0 : Insert\n");
		printf("1 : Delete\n");
		printf("2 : View\n");
		printf("3 : EXIT\n");

		printf("INPUT : ");
		scanf("%d",&key);
		printf("\n");

		switch(key){
			case 0: Insert();break;
			case 1: Delete();break;
			case 2: View();break;
			case 3: exit(0);break;
			default: printf("INPUT ERROR!\n");break;
		}
	}

}