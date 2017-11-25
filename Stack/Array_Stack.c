#include <stdio.h>
#include <stdlib.h>

char stack[5];
int top = -1;

void Pop(){

	if(top==-1){
		printf("Stack UnderFlow\n\n");
		return ;
	}

	stack[top] = "";
	top--;

}

void Push(){

	if(top == 4){
		printf("Stack OverFlow\n\n");
		return ;
	}

	char data;
	printf("Push data : ");
	scanf(" %c",&data);
	printf("\n");
	top++;
	stack[top] = data;

}

void Peek(){
	if(top==-1){
		printf("NO DATA\n\n");
		return ;
	}
	printf("TOP : %c \n\n",stack[top]);
}

void View(){

	if(top==-1){
		printf("NO DATA\n\n");
		return ;
	}

	int i = 0;
	for(i = top; i >=  0; i--){
		printf("-----\n");
		printf("  %c   \n",stack[i]);
	}
	printf("-----\n\n");
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