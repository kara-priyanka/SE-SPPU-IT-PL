// Name: KARA PRIYANKA      Batch: A1     Roll no.: 03
// Assignment 8: Doubly Linked List

#include<stdio.h>
#include<stdlib.h>

typedef struct DLLnode
{
	int rollno;
	char name[20];
	float marks;
	struct DLLnode *next;
	struct DLLnode *pre;
}*NODE;


NODE accept();
NODE insert(NODE head);
void display(NODE head);
int search(NODE head,int key);
NODE modify(NODE head,int key);
NODE del(NODE head,int key);


int main()
{
	int ch,no,key,ser;
	NODE head=NULL;
	do
	{
		printf("Enter a choice:\n1: Accept\n2: Display\n3: Search\n4: Modify\n5: Delelte\n6: Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				head = insert(head);

			break;

			case 2:
				display(head);
			break;

			case 3:
				printf("Enter roll number to be searched:\n");
				scanf("%d",&key);
				ser = search(head,key);
				if(ser!=-1)
				{
					printf("Given record found at pos: %d\n");
				}
				else
				{
					printf("Record not found!! \n");
				}
			break;

			case 4:
				printf("Enter roll number to be modify:\n");
				scanf("%d",&key);
				head = modify(head,key);
				display(head);
			break;

			case 5:
				printf("Enter roll number to be deleted:\n");
				scanf("%d",&key);
				head = del(head,key);
		}
	}while(ch!=6);
}


NODE accept()								//function for accepting data
{
	NODE temp;
	temp = (NODE)malloc(sizeof(struct DLLnode));
	printf("Enter roll number of student :\n");
	scanf("%d",&temp->rollno);
	printf("Enter student's name of student :\n");
	scanf("%s",temp->name);
	printf("Enter marks obtained of student :\n");
	scanf("%f",&temp->marks);
	temp-> next = NULL;
	temp-> pre = NULL;
	return temp;
}

NODE insert(NODE head)
{
	NODE temp,newnode;
	newnode=accept();
	if(head==NULL)
	{
		head=newnode;
		return head;
	}

	temp=head;
	if(newnode->rollno < head->rollno && temp!=NULL)
	{
		newnode -> next = head;
		head -> pre= newnode;
		head = newnode;
		return head;
	}


	while(newnode->rollno > temp->rollno && temp->next!=NULL)
	{
		temp=temp->next;
	}

	if(newnode->rollno < temp->rollno && temp!=NULL)
	{
		newnode->next=temp;
		newnode->pre=temp->pre;
		temp->pre->next=newnode;
		temp->pre=newnode;
		return head;
	}

	if(temp->next==NULL)
	{
		newnode->pre=temp;
		temp->next=newnode;
		return head;
	}

}



void display(NODE head)							//function for displaying data
{
	NODE temp;
	temp = head;

	while(temp!=NULL)
	{
		printf("%d\t%s\t%.2f\n",temp->rollno,temp->name,temp->marks);
		temp=temp->next;
	}
	printf("\n");
}



int search(NODE head,int key)
{
	int ser=1;
	NODE temp;
	temp=head;
	if(head==NULL)
	{
		return -1;
	}
	while(temp->rollno!=key)
	{
		temp=temp->next;
		ser++;
		if(temp==NULL)
		{
			return -1;
		}
	}

	return ser;
}


NODE modify(NODE head,int key)
{
	int pos;
	NODE temp;
	temp=head;
	pos = search(head,key);
	if(pos!=-1)
	{
		while(temp->rollno!=key)
		{
			temp=temp->next;
		}
		printf("Enter student's name of student :\n");
		scanf("%s",temp->name);
		printf("Enter marks obtained of student :\n");
		scanf("%f",&temp->marks);
		return head;
	}
	else
	{
		printf("Record not found!!\n");
		return head;
	}
}


NODE del(NODE head,int key)
{
	int pos;
	NODE temp;
	temp=head;

	pos = search(head,key);
	if(pos==-1)
	{
		printf("Element not found!\n");
	}

	if(head==NULL)
	{
		return NULL;
	}

	if(head->next==NULL)
	{
		return NULL;
	}

	while(temp->rollno!=key && temp->next!=NULL)
	{
		temp=temp->next;
	}
	if(pos==1)
	{
		head=temp->next;
		temp->next->pre=NULL;
		temp->next=NULL;
		free(temp);
		return head;
	}
	if(temp->next==NULL)
	{
		temp->pre->next=NULL;
		temp->pre=NULL;
		free(temp);
		return head;
	}
	else
	{
		temp->pre->next=temp->next;
		temp->next->pre=temp->pre;
		temp->next=NULL;
		temp->pre=NULL;
		free(temp);
		return head;
	}
}


/*
Output:
Enter a choice:
1: Accept
2: Display
3: Search
4: Modify
5: Delelte
6: Exit
1
Enter roll number of student :
3
Enter student's name of student :
q
Enter marks obtained of student :
12
Enter a choice:
1: Accept
2: Display
3: Search
4: Modify
5: Delelte
6: Exit
1
Enter roll number of student :
1
Enter student's name of student :
a
Enter marks obtained of student :
23
Enter a choice:
1: Accept
2: Display
3: Search
4: Modify
5: Delelte
6: Exit
1
Enter roll number of student :
2
Enter student's name of student :
z
Enter marks obtained of student :
34
Enter a choice:
1: Accept
2: Display
3: Search
4: Modify
5: Delelte
6: Exit
1
Enter roll number of student :
5
Enter student's name of student :
d
Enter marks obtained of student :
43
Enter a choice:
1: Accept
2: Display
3: Search
4: Modify
5: Delelte
6: Exit
1
Enter roll number of student :
4
Enter student's name of student :
r
Enter marks obtained of student :
21
Enter a choice:
1: Accept
2: Display
3: Search
4: Modify
5: Delelte
6: Exit
2
1	a	23.00
2	z	34.00
3	q	12.00
4	r	21.00
5	d	43.00
Enter a choice:
1: Accept
2: Display
3: Search
4: Modify
5: Delelte
6: Exit
3
Enter roll number to be searched:
3
Given record found at pos: 3
Enter a choice:
1: Accept
2: Display
3: Search
4: Modify
5: Delelte
6: Exit
4
Enter roll number to be modify:
2
Enter student's name of student :
g
Enter marks obtained of student :
45
1	a	23.00
2	g	45.00
3	q	12.00
4	r	21.00
5	d	43.00

Enter a choice:
1: Accept
2: Display
3: Search
4: Modify
5: Delelte
6: Exit
5
Enter roll number to be deleted:
5
Enter a choice:
1: Accept
2: Display
3: Search
4: Modify
5: Delelte
6: Exit
2
1	a	23.00
2	g	45.00
3	q	12.00
4	r	21.00

Enter a choice:
1: Accept
2: Display
3: Search
4: Modify
5: Delelte
6: Exit
6

*/
