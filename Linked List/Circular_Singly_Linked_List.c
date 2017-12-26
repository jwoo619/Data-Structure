#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	int data;
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
	NewNode->next = NULL;

	if(Head == NULL){
		Head = NewNode;
		Head->next = NewNode;
	}

	else if(Tail == NULL){
		NewNode->next = Head;
		Head->next = NewNode;
		Tail = NewNode;
	}

	else{
		Tail->next = NewNode;
		NewNode->next = Head;
		Tail = NewNode;
	}
	
}

void Middle_Insert(){

	int key;
	printf("Insert Index : ");
	scanf("%d",&key);

	if(Head == NULL || Tail == NULL){
		printf("Not Many Node\n\n");
		return ;
	}

	if(key < 2){
		printf("Please over one\n\n");
		return ;
	}

	Node * Temp;
	Node * PreTemp;
	Temp = Head;
	while(--key){
		PreTemp = Temp;
		Temp = Temp->next;
		if(PreTemp == Tail){
			printf("Don't Select OverTail or Tail\n\n");
			return ;
		}
	}

	int data;
	printf("Insert data : ");
	scanf("%d",&data);
	printf("\n");

	Node * NewNode;
	NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = data;

	PreTemp->next = NewNode;
	NewNode->next = Temp;

}

void Delete(){

	if(Head == NULL)
		return;

	int key;
	printf("Delete Node Data : ");
	scanf("%d",&key);

	Node * Temp;
	Node * PreTemp;
	Temp = Head;

	do{
		if(Temp->data == key){

			Node * DeleteNode;

			if(Temp == Head){
				Head = Head->next;
				Tail->next = Head;
			}
			else if(Temp == Tail){
				Tail = PreTemp;
				Tail->next = Head;
			}
			else
				PreTemp->next = Temp->next;

			DeleteNode = Temp;
			free(DeleteNode);
			return ;
		}
		PreTemp = Temp;
		Temp = Temp->next;
	}while(Temp!=Head);

	printf("No Data\n\n");


}

void View(){

	Node * Temp;
	Temp = Head;

	do{
		printf("  %d\n",Temp->data);
		printf("-----\n");
		Temp = Temp->next;
	} while (Temp!=Head);

	printf("\n\n");

}

int main(){

	

	int key = 0;
	while(1){
		printf("0 : Insert\n");
		printf("1 : Middle Insert\n");
		printf("2 : Delete\n");
		printf("3 : View\n");
		printf("4 : EXIT\n");

		printf("INPUT : ");
		scanf("%d",&key);
		printf("\n");

		switch(key){
			case 0: Insert();break;
			case 1: Middle_Insert();break;
			case 2: Delete();break;
			case 3: View();break;
			case 4: exit(0);break;
			default: printf("INPUT ERROR!\n");break;
		}
	}

}