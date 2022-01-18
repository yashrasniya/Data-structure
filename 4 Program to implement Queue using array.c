#include<stdio.h>
int size=10;
int f=-1;
int r=-1;
void inseart(int a[],int element){
	if(r==size){

		printf("Queue is overflow" );
	}
	else{
		r++;
		a[r]=element;
	}
}

void delete(int a[]){
	if((f==-1)&& (r==-1)){
		printf("Queue is empty");
	}
	else if(f==r){
		printf("%d ",a[f]);
		f=-1;
		r=-1;
	}
	else{
		printf("%d ", a[f]);
		f++;
	}
}

void display(int a[]){
	int i = f;
	if ((f==-1)&&(r==-1)){
		printf(" Queue is empty ");

	}else{
		printf("element are : ");
		while(i<=r){
			printf("%d ",a[i]);
			i++;
		}

	}
}

int main(){
	int choice=1,x;
	int a[size];

	while(choice<4 && choice>0){
		printf("\nPress 1: Insert an element\nPress 2:Delete an element\nPress 3: display the element\nEnter your choice: ");
		scanf("%d",&choice);

		switch(choice){
			case 1:
			printf("enter a number for insert: ");
			scanf("%d",&x);
			inseart(a,x);
			break;
			case 2:
			delete(a);
			break;
			case 3:
			display(a);
			break;
		}
	}
	return 0;
}