#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	int data;
	struct Node * next;
}Node;

Node * Stack;

void Push(){

	int data;
	printf("Push data : ");
	scanf("%d",&data);
	printf("\n");

	Node * NewNode;
	NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = data;
	NewNode->next = NULL;

	if(Stack == NULL)
		Stack = NewNode;

	else{
		NewNode->next = Stack;
		Stack = NewNode;
	}
	
}

void Pop(){

	free(Stack);
	Stack = Stack->next;

}

void Peek(){
	printf("%d\n\n",Stack->data);
}

void View(){

	Node * Temp;
	Temp = Stack;

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
		printf("0 : PUSH\n");
		printf("1 : POP\n");
		printf("2 : PEEK\n");
		printf("3 : View\n");
		printf("4 : EXIT\n");

		printf("INPUT : ");
		scanf("%d",&key);
		printf("\n");

		switch(key){
			case 0: Push();break;
			case 1: Pop();break;
			case 2: Peek();break;
			case 3: View();break;
			case 4: exit(0);break;
			default: printf("INPUT ERROR!\n");break;
		}
	}

}