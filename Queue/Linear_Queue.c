#include <stdio.h>
char queue[5];
int front = 0 , rear = 0;

void Insert(){

	if(rear==5){
		printf("Queue OverFlow\n\n");
		return ;
	}

	char data;

	printf("Push data : ");
	scanf(" %c",&data);
	printf("\n");
	queue[rear] = data;;
	rear++;
}

void Delete(){
	if(rear==front){
		printf("Queue UnderFlow\n\n");
		return ;
	}

	queue[front] = "";
	front++;
}

void View(){
	if(rear==front){
		printf("No Data\n\n");
		return ;
	}

	int i;
	printf("| ");

	for(i = 0; i<front; i++){
		printf("■ | ");
	}
	for(i = front; i<rear; i++){
		printf("%c | ",queue[i]);
	}
	for(i = rear; i<5; i++){
		printf(" | ");
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