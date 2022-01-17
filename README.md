# Data-structure
## Index([git](https://github.com/yashrasniya/Data-structure))

[TOC]

![image-20220117144747189](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220117144747189.png)

------



### 1. Program to Implement Array ADT.

```c
#include<stdio.h>


void main(){
	int array[]={2,6,78,23,12,22,4,8};

	for(int i=0;i<8;i++){
		printf("array element no %d is %d \n",i,array[i]);
	}
}


```



![](C:\Users\Administrator\Documents\yash data structure file\1.jpg)

### 2. Program to implement String ADT.

```c
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
```

![](C:\Users\Administrator\Documents\yash data structure file\2.jpg)







### 3. Program to implement stack using array.

```c
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
print("Stack elements are:");
printf("%d ",pop(a,&top));
printf("%d ",pop(a,&top));


}
```

![image-20220117110613532](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220117110613532.png)

------



### 4. Program to implement Queue using array.

```c
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
```

![image-20220117111153935](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220117111153935.png)

### 5. Program for Circular Queues using array.

```c
    #include <stdio.h>  
      
    # define max 6  
    int queue[max];  
    int front=-1;  
    int rear=-1;  

    void enqueue(int element)  
    {  
        if(front==-1 && rear==-1)   
        {  
            front=0;  
            rear=0;  
            queue[rear]=element;  
        }  
        else if((rear+1)%max==front) 
        {  
            printf("Queue is overflow..");  
        }  
        else  
        {  
            rear=(rear+1)%max;        
            queue[rear]=element;    
    }  
      
     
    int dequeue()  
    {  
        if((front==-1) && (rear==-1)) 
        {  
            printf("\nQueue is underflow..");  
        }  
     else if(front==rear)  
    {  
       printf("\nThe dequeued element is %d", queue[front]);  
       front=-1;  
       rear=-1;  
    }   
    else  
    {  
        printf("\nThe dequeued element is %d", queue[front]);  
       front=(front+1)%max;  
    }  
    }  

    void display()  
    {  
        int i=front;  
        if(front==-1 && rear==-1)  
        {  
            printf("\n Queue is empty..");  
        }  
        else  
        {  
            printf("\nElements in a Queue are :");  
            while(i<=rear)  
            {  
                printf("%d,", queue[i]);  
                i=(i+1)%max;  
            }  
        }  
    }  
    int main()  
    {  
        int choice=1,x; 
          
        while(choice<4 && choice!=0)   
        {  
        printf("\n Press 1: Insert an element");  
        printf("\nPress 2: Delete an element");  
        printf("\nPress 3: Display the element");  
        printf("\nEnter your choice");  
        scanf("%d", &choice);  
          
        switch(choice)  
        {  
              
            case 1:  
          
            printf("Enter the element which is to be inserted");  
            scanf("%d", &x);  
            enqueue(x);  
            break;  
            case 2:  
            dequeue();  
            break;  
            case 3:  
            display();  
      
        }}  
        return 0;  
    }  
```

![image-20220117111615499](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220117111615499.png)

### 6. Program to convert an infix expression into postfix and postfix evaluation.

```c

#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);

    e = exp;
    
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        printf("%c ",pop());
    }return 0;
}
```

![image-20220117111924281](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220117111924281.png)

### 7. Program to implement singly linked list.

```c
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

```

![image-20220117140027232](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220117140027232.png)

### 8. Program to implement stack using linked list.

```c
#include <stdio.h>  
#include <stdlib.h>  
void push();  
void pop();  
void display();  
struct node   
{  
int val;  
struct node *next;  
};  
struct node *head;  
  
void main ()  
{  
    int choice=0;     
    printf("\n*********Stack operations using linked list*********\n");  
    printf("\n----------------------------------------------\n");  
    while(choice != 4)  
    {  
        printf("\n\nChose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
        printf("\n Enter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                display();  
                break;  
            }  
            case 4:   
            {  
                printf("Exiting....");  
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
    };  
}  
}  
void push ()  
{  
    int val;  
    struct node *ptr = (struct node*)malloc(sizeof(struct node));   
    if(ptr == NULL)  
    {  
        printf("not able to push the element");   
    }  
    else   
    {  
        printf("Enter the value");  
        scanf("%d",&val);  
        if(head==NULL)  
        {         
            ptr->val = val;  
            ptr -> next = NULL;  
            head=ptr;  
        }   
        else   
        {  
            ptr->val = val;  
            ptr->next = head;  
            head=ptr;  
               
        }  
        printf("Item pushed");  
          
    }  
}  
  
void pop()  
{  
    int item;  
    struct node *ptr;  
    if (head == NULL)  
    {  
        printf("Underflow");  
    }  
    else  
    {  
        item = head->val;  
        ptr = head;  
        head = head->next;  
        free(ptr);  
        printf("Item popped");  
          
    }  
}  
void display()  
{  
    int i;  
    struct node *ptr;  
    ptr=head;  
    if(ptr == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {  
        printf("Printing Stack elements \n");  
        while(ptr!=NULL)  
        {  
            printf("%d\n",ptr->val);  
            ptr = ptr->next;  
        }  
    }  
}  
```

![image-20220117140400387](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220117140400387.png)

### 9. Program to implement queue using linked list .

```c
#include<stdio.h>   
#include<stdlib.h>  
struct node   
{  
    int data;   
    struct node *next;  
};  
struct node *front;  
struct node *rear;   
void insert();  
void delete();  
void display();  
void main ()  
{  
    int choice;   
    while(choice != 4)   
    {     

        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");  
        printf("\nEnter your choice ?");  
        scanf("%d",& choice);  
        switch(choice)  
        {  
            case 1:  
            insert();  
            break;  
            case 2:  
            delete();  
            break;  
            case 3:  
            display();  
            break;  
            case 4:  
            exit(0);  
            break;  
            default:   
            printf("\nEnter valid choice??\n");  
        }  
    }  
}  
void insert()  
{  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    else  
    {   
        printf("\nEnter value?\n");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}     
void delete ()  
{  
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
}  
void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nprinting values .....\n");  
        while(ptr != NULL)   
        {  
            printf("\n%d\n",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
}
```

![image-20220117140931681](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220117140931681.png)

### 10. The Doubly Linked List.

```c

#include <stdio.h>
#include <stdlib.h>


struct node {
	int info;
	struct node *prev, *next;
};
struct node* start = NULL;


void traverse()
{

	if (start == NULL) {
		printf("\nList is empty\n");
		return;
	}
	
	struct node* temp;
	temp = start;
	while (temp != NULL) {
		printf("Data = %d\n", temp->info);
		temp = temp->next;
	}
}


void insertAtFront()
{
	int data;
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temp->info = data;
	temp->prev = NULL;


	temp->next = start;
	start = temp;
}


void insertAtEnd()
{
	int data;
	struct node *temp, *trav;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temp->info = data;
	temp->next = NULL;
	trav = start;


	if (start == NULL) {

		start = temp;
	}


	else {
		while (trav->next != NULL)
			trav = trav->next;
		temp->prev = trav;
		trav->next = temp;
	}
}


void insertAtPosition()
{
	int data, pos, i = 1;
	struct node *temp, *newnode;
	newnode = malloc(sizeof(struct node));
	newnode->next = NULL;
	newnode->prev = NULL;

	printf("\nEnter position : ");
	scanf("%d", &pos);
	


	if (start == NULL) {
		start = newnode;
		newnode->prev = NULL;
		newnode->next = NULL;
	}


	else if (pos == 1) {

	insertAtFront();
	}


	else {
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	newnode->info = data;
	temp = start;
		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next = newnode;
		temp->next->prev = newnode;
	}
}


void deleteFirst()
{
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		temp = start;
		start = start->next;
		if (start != NULL)
			start->prev = NULL;
		free(temp);
	}
}


void deleteEnd()
{
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	temp = start;
	while (temp->next != NULL)
		temp = temp->next;
	if (start->next == NULL)
		start = NULL;
	else {
		temp->prev->next = NULL;
		free(temp);
	}
}

void deletePosition()
{
	int pos, i = 1;
	struct node *temp, *position;
	temp = start;


	if (start == NULL)
		printf("\nList is empty\n");


	else {
		// Position to be deleted
		printf("\nEnter position : ");
		scanf("%d", &pos);


		if (pos == 1) {
			deleteFirst(); 
			if (start != NULL) {
				start->prev = NULL;
			}
			free(position);
			return;
		}


		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}

		position = temp->next;
		if (position->next != NULL)
			position->next->prev = temp;
		temp->next = position->next;


		free(position);
	}
}


int main()
{
	int choice;
	while (1) {

		printf("\n\t1 To see list\n");
		printf("\t2 For insertion at"
			" starting\n");
		printf("\t3 For insertion at"
			" end\n");
		printf("\t4 For insertion at "
			"any position\n");
		printf("\t5 For deletion of "
			"first element\n");
		printf("\t6 For deletion of "
			"last element\n");
		printf("\t7 For deletion of "
			"element at any position\n");
		printf("\t8 To exit\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			traverse();
			break;
		case 2:
			insertAtFront();
			break;
		case 3:
			insertAtEnd();
			break;
		case 4:
			insertAtPosition();
			break;
		case 5:
			deleteFirst();
			break;
		case 6:
			deleteEnd();
			break;
		case 7:
			deletePosition();
			break;

		case 8:
			exit(1);
			break;
		default:
			printf("Incorrect Choice. Try Again \n");
			continue;
		}
	}
	return 0;
}

```

![image-20220117140717345](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220117140717345.png)

### 11. Program for all operations on circular linked list.

```c

#include <stdio.h>
#include <stdlib.h>


struct node {
	int info;
	struct node* next;
};


struct node* last = NULL;

void insertAtFront()
{

	int data;


	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));

	printf("\nEnter data to be "
		"inserted: \n");
	scanf("%d", &data);


	if (last == NULL) {
		temp->info = data;
		temp->next = temp;
		last = temp;
	}

	else {
		temp->info = data;
		temp->next = last->next;


		last->next = temp;
	}
}


void viewList()
{

	if (last == NULL)
		printf("\nList is empty\n");


	else {
		struct node* temp;
		temp = last->next;


		do {
			printf("\nData = %d", temp->info);
			temp = temp->next;
		} while (temp != last->next);
	}
}


int main()
{

	insertAtFront();
	insertAtFront();
	insertAtFront();


	viewList();

	return 0;
}

```

![image-20220117141250243](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220117141250243.png)

### 12. Implementing hash table.

```c
#include <stdio.h>
#include <stdlib.h>

struct set
{
  int key;
  int data;
};
struct set *array;
int capacity = 10;
int size = 0;

int hashFunction(int key)
{
  return (key % capacity);
}
int checkPrime(int n)
{
  int i;
  if (n == 1 || n == 0)
  {
  return 0;
  }
  for (i = 2; i < n / 2; i++)
  {
  if (n % i == 0)
  {
    return 0;
  }
  }
  return 1;
}
int getPrime(int n)
{
  if (n % 2 == 0)
  {
  n++;
  }
  while (!checkPrime(n))
  {
  n += 2;
  }
  return n;
}
void init_array()
{
  capacity = getPrime(capacity);
  array = (struct set *)malloc(capacity * sizeof(struct set));
  for (int i = 0; i < capacity; i++)
  {
  array[i].key = 0;
  array[i].data = 0;
  }
}

void insert(int key, int data)
{
  int index = hashFunction(key);
  if (array[index].data == 0)
  {
  array[index].key = key;
  array[index].data = data;
  size++;
  printf("\n Key (%d) has been inserted \n", key);
  }
  else if (array[index].key == key)
  {
  array[index].data = data;
  }
  else
  {
  printf("\n Collision occured  \n");
  }
}

void remove_element(int key)
{
  int index = hashFunction(key);
  if (array[index].data == 0)
  {
  printf("\n This key does not exist \n");
  }
  else
  {
  array[index].key = 0;
  array[index].data = 0;
  size--;
  printf("\n Key (%d) has been removed \n", key);
  }
}
void display()
{
  int i;
  for (i = 0; i < capacity; i++)
  {
  if (array[i].data == 0)
  {
    printf("\n array[%d]: / ", i);
  }
  else
  {
    printf("\n key: %d array[%d]: %d \t", array[i].key, i, array[i].data);
  }
  }
}

int size_of_hashtable()
{
  return size;
}

int main()
{
  int choice, key, data, n;
  int c = 0;
  init_array();

  do
  {
  printf("1.Insert item in the Hash Table"
     "\n2.Remove item from the Hash Table"
     "\n3.Check the size of Hash Table"
     "\n4.Display a Hash Table"
     "\n\n Please enter your choice: ");

  scanf("%d", &choice);
  switch (choice)
  {
  case 1:

    printf("Enter key -:\t");
    scanf("%d", &key);
    printf("Enter data -:\t");
    scanf("%d", &data);
    insert(key, data);

    break;

  case 2:

    printf("Enter the key to delete-:");
    scanf("%d", &key);
    remove_element(key);

    break;

  case 3:

    n = size_of_hashtable();
    printf("Size of Hash Table is-:%d\n", n);

    break;

  case 4:

    display();

    break;

  default:

    printf("Invalid Input\n");
  }

  printf("\nDo you want to continue (press 1 for yes): ");
  scanf("%d", &c);

  } while (c == 1);
}
```

![image-20220117141656994](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220117141656994.png)

### 13. Insertion sort.

```c
#include <math.h>
#include <stdio.h>
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
```

![image-20220117141815236](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220117141815236.png)

### 14. Program for implementation of selection sort.

```c
#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;


    for (i = 0; i < n-1; i++)
    {

        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

 
        swap(&arr[min_idx], &arr[i]);
    }
}


void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
```

![image-20220117142031759](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220117142031759.png)

### 15. Heap Sort.

  ```c
  #include <stdio.h>
  
  
  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
  void heapify(int arr[], int n, int i) {
  
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
  
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  
  void heapSort(int arr[], int n) {
  
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
  
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
     
      heapify(arr, i, 0);
    }
  }
  void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }
  int main() {
    int arr[] = {1, 12, 9, 5, 6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
  
    heapSort(arr, n);
  
    printf("Sorted array is \n");
    printArray(arr, n);
  }
  ```

![image-20220117142126291](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220117142126291.png)

### 16. Shell Sort.

```c
#include <stdio.h>


void shellSort(int array[], int n) {

  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
  }
}


void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


int main() {
  int data[] = {9, 8, 3, 7, 5, 6, 4, 1};
  int size = sizeof(data) / sizeof(data[0]);
  shellSort(data, size);
  printf("Sorted array: \n");
  printArray(data, size);
}
```

![image-20220117142231394](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220117142231394.png)

### 17. Quick sort.

```c
#include <stdio.h>


void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}


int partition(int array[], int low, int high) {
  

  int pivot = array[high];
  

  int i = (low - 1);


  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {

      i++;
      swap(&array[i], &array[j]);
    }
  }


  swap(&array[i + 1], &array[high]);
  

  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {

    int pi = partition(array, low, high);
    

    quickSort(array, low, pi - 1);
    

    quickSort(array, pi + 1, high);
  }
}


void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


int main() {
  int data[] = {8, 7, 2, 1, 0, 9, 6};
  
  int n = sizeof(data) / sizeof(data[0]);
  
  printf("Unsorted Array\n");
  printArray(data, n);
  

  quickSort(data, 0, n - 1);
  
  printf("Sorted array in ascending order: \n");
  printArray(data, n);
}
```

![image-20220117142410053](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220117142410053.png)

### 18. Tree traversal.

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
  int item;
  struct node* left;
  struct node* right;
};


void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ->", root->item);
  inorderTraversal(root->right);
}


void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("%d ->", root->item);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}


void postorderTraversal(struct node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->item);
}


struct node* createNode(int value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}


struct node* insertLeft(struct node* root, int value) {
  root->left = createNode(value);
  return root->left;
}


struct node* insertRight(struct node* root, int value) {
  root->right = createNode(value);
  return root->right;
}

int main() {
  struct node* root = createNode(1);
  insertLeft(root, 12);
  insertRight(root, 9);

  insertLeft(root->left, 5);
  insertRight(root->left, 6);

  printf("Inorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);

  printf("\nPostorder traversal \n");
  postorderTraversal(root);
}
```

![image-20220117142706303](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220117142706303.png)

### 19. AVL tree implementation.

```c
#include <stdio.h>
#include <stdlib.h>


struct Node {
  int key;
  struct Node *left;
  struct Node *right;
  int height;
};

int max(int a, int b);


int height(struct Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}


struct Node *newNode(int key) {
  struct Node *node = (struct Node *)
    malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}


struct Node *rightRotate(struct Node *y) {
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}


struct Node *leftRotate(struct Node *x) {
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}


int getBalance(struct Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}


struct Node *insertNode(struct Node *node, int key) {

  if (node == NULL)
    return (newNode(key));

  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;


  node->height = 1 + max(height(node->left),
               height(node->right));

  int balance = getBalance(node);
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);

  if (balance < -1 && key > node->right->key)
    return leftRotate(node);

  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

struct Node *minValueNode(struct Node *node) {
  struct Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}


struct Node *deleteNode(struct Node *root, int key) {

  if (root == NULL)
    return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);

  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      struct Node *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      struct Node *temp = minValueNode(root->right);

      root->key = temp->key;

      root->right = deleteNode(root->right, temp->key);
    }
  }

  if (root == NULL)
    return root;


  root->height = 1 + max(height(root->left),
               height(root->right));

  int balance = getBalance(root);
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

void printPreOrder(struct Node *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}

int main() {
  struct Node *root = NULL;

  root = insertNode(root, 2);
  root = insertNode(root, 1);
  root = insertNode(root, 7);
  root = insertNode(root, 4);
  root = insertNode(root, 5);
  root = insertNode(root, 3);
  root = insertNode(root, 8);

  printPreOrder(root);

  root = deleteNode(root, 3);

  printf("\nAfter deletion: ");
  printPreOrder(root);

  return 0;
}
```
![image-20220117142924903](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220117142924903.png)

### 20. Program to implement operation on splay tree.

```c
#include<stdio.h>
#include<stdlib.h>


struct node
{
	int key;
	struct node *left, *right;
};


struct node* newNode(int key)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}
struct node *rightRotate(struct node *x)
{
	struct node *y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}
struct node *leftRotate(struct node *x)
{
	struct node *y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}
struct node *splay(struct node *root, int key)
{

	if (root == NULL || root->key == key)
		return root;
	if (root->key > key)
	{

		if (root->left == NULL) return root;

		if (root->left->key > key)
		{

			root->left->left = splay(root->left->left, key);

			
			root = rightRotate(root);
		}
		else if (root->left->key < key) 
		{
			
			root->left->right = splay(root->left->right, key);

	
			if (root->left->right != NULL)
				root->left = leftRotate(root->left);
		}


		return (root->left == NULL)? root: rightRotate(root);
	}
	else
	{
		
		if (root->right == NULL) return root;

	
		if (root->right->key > key)
		{
			
			root->right->left = splay(root->right->left, key);

		
			if (root->right->left != NULL)
				root->right = rightRotate(root->right);
		}
		else if (root->right->key < key)
		{
			
			root->right->right = splay(root->right->right, key);
			root = leftRotate(root);
		}

		
		return (root->right == NULL)? root: leftRotate(root);
	}
}


struct node *search(struct node *root, int key)
{
	return splay(root, key);
}


void preOrder(struct node *root)
{
	if (root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}


int main()
{
	struct node *root = newNode(100);
	root->left = newNode(50);
	root->right = newNode(200);
	root->left->left = newNode(40);
	root->left->left->left = newNode(30);
	root->left->left->left->left = newNode(20);

	root = search(root, 20);
	printf("Preorder traversal of the modified Splay tree is \n");
	preOrder(root);
	return 0;
}

```

![image-20220117143108074](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220117143108074.png)
