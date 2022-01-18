#include <stdio.h>

void push(int a[],int *top,int element){

	if(*top==5){
		printf("stack is full");
	}
	else{
		*top=*top+1;
		a[*top]=element;
		
	}

}
int pop(int a[],int *top){
	int data;
	if(*top==-1){
		printf("stack is empty");
	}
	else{
		data=a[*top];
		*top=*top-1;
	}
	return data;
}
void main(){
int a[5];
int top=-1;
push(a,&top,3);
push(a,&top,6);
push(a,&top,8);
printf("Stack elements are:");
printf("%d ",pop(a,&top));
printf("%d ",pop(a,&top));


}