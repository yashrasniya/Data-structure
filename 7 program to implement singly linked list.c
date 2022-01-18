
#include <stdio.h>
#include<stdlib.h>
struct node {
	int info;
	struct node* link;
};
struct node* start = NULL;
void traverse()
{
	struct node* temp;

	if (start == NULL)
		printf("\nList is empty\n");
	else {
		temp = start;
		while (temp != NULL) {
			printf("Data = %d\n",
				temp->info);
			temp = temp->link;
		}
	}
}
void insert()
{
	int data;
	struct node *temp, *head;
	temp = malloc(sizeof(struct node));
	printf("\nEnter number to"
		" be inserted : ");
	scanf("%d", &data);
	temp->link = 0;
	temp->info = data;
	head = start;
	while (head->link != NULL) {
		head = head->link;
	}
	head->link = temp;
}
void deletePosition()
{
	struct node *temp, *position;
	int i = 1, pos;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		printf("\nEnter index : ");
		scanf("%d", &pos);
		position = malloc(sizeof(struct node));
		temp = start;
		while (i < pos - 1) {
			temp = temp->link;
			i++;
		}
		position = temp->link;
		temp->link = position->link;
		free(position);
	}
}

int main()
{
	int choice;
	while (1) {

		printf("\n\t1 To see list\n");
		printf("\t2 For insertion at"
			" end\n");
		printf("\t3 For deletion of "
			"element at any position\n");
		printf("\t4 To exit\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			traverse();
			break;
		case 2:
			insert();
			break;
		case 3:
			deletePosition();
			break;
		case 4:
			exit(1);
			break;
		default:
			printf("Incorrect Choice\n");
		}
	}
	return 0;
}
