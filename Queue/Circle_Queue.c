#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char queue[5];
int front = 0 , rear = -1;

void Insert(){

	rear++;

	if(strcmp(&queue[rear%5],"")!=0){
		printf("Queue OverFlow\n\n");
		rear--;
		return ;
	}

	rear = rear%5;

	char data;

	printf("Push data : ");
	scanf(" %c",&data);
	printf("\n");
	queue[rear] = data;
}

void Delete(){

	if(strcmp(&queue[front],"")==0){
		printf("Queue UnderFlow\n\n");
		return ;
	}

	strncpy(&queue[front], "", 1);
	front++;
	front = front%5;

}

void View(){
	if(strcmp(&queue[front],"")==0){
		printf("No Data\n\n");
		return ;
	}

	int i;
	for(i = 0; i<5; i++){
		printf("%c | ",queue[i]);
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