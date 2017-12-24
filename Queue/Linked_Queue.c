#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	int data;
	struct Node * next;
}Node;

Node * Queue;

void Insert(){

	int data;
	printf("Insert data : ");
	scanf("%d",&data);
	printf("\n");

	Node * NewNode;
	NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = data;
	NewNode->next = NULL;

	if(Queue == NULL)
		Queue = NewNode;

	else{
		Node * Temp;
		Temp = Queue;
		while(Temp->next != NULL){
			Temp = Temp->next;
		}
		Temp->next = NewNode;
		
	}
	
}

void Delete(){

	if(Queue == NULL)
		return;

	Node * DeleteNode;
	DeleteNode = Queue;
	Queue = Queue->next;
	free(DeleteNode);

}

void View(){

	Node * Temp;
	Temp = Queue;

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