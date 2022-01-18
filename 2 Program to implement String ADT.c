//Program to implement String ADT
#include<stdio.h>


void main(){
	char array[]="Yash Rasniya";
	int i=0;
	printf("%s\n ",array);
	while(array[i]!='\0'){
		printf("%c, ",array[i]);
		i++;
	}
}