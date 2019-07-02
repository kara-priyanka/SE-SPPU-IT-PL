// Name: KARA PRIYANKA     Batch: A1    Roll no.: 03
// Assignment 10 : Circularly linked list

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct CLLnode
{
	int pow,coef;
	struct CLLnode *next;
}*NODE;


NODE insert(NODE head,int p,int c);
NODE create();
void display(NODE head);
NODE add( NODE, NODE);
NODE mult (NODE, NODE);
int eval (NODE, int x);



int main()
{
	int ch;
	NODE poly1, poly2,poly3,poly4;
	int x1,ans1,x2,ans2;

	do
	{
		printf("Enter your choice:\n1: Accept\n2: Display\n3: Addition\n4: multiplication\n5: Evaluate\n6: Exit\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: printf("Enter the details for polynomial 1:\n");
				poly1=create();
				printf("Enter the details for polynomial 2:\n");
				poly2=create();
			break;

			case 2: printf("The polynomial 1:\n");
				display(poly1);
				printf("The polynomial 2:\n");
				display(poly2);
			break;

			case 3: poly3 = add(poly1, poly2);
				printf("The Addition of polynomial is:\n");
				display(poly3);
			break;

			case 4: poly4 = mult(poly1,poly2);
				printf("The multiplication of polynomial is:\n");
				display(poly4);
			break;

			case 5: printf("Enter the value for x\n");
				scanf("%d",&x1);
				ans1= eval(poly1,x1);
				printf("The evaluation of x in polynomial 1 is:%d\n", ans1);


				ans2= eval(poly2,x1);
				printf("The evaluation of x in polynomial 2 is:%d\n", ans2);
		}
	}while(ch!=6);
}




NODE insert(NODE head,int pow1,int coef1)
{
	NODE p,q;
	p = (NODE)malloc(sizeof(struct CLLnode));
	p->pow=pow1;
	p->coef=coef1;
	p->next=NULL;
	if(head==NULL)
	{
		head=p;
		head->next=head;
		return head;
	}

	if(pow1 < head->pow)
	{
		p->next=head->next;
		head->next=p;
		head=head->next;
		return head;
	}

	if(pow1 == head->pow)
	{
		head->coef = coef1 + head->coef;
		return head;
	}

	q = head;

	while(q->next!=head && pow1 <= q->next->pow)
	{
		q=q->next;
	}
	if(pow1 == q->pow)
	{
		q->coef=q->coef+coef1;
	}
	else
	{
		p->next=q->next;
		q->next=p;
	}
	return head;
}


NODE create()
{

	int i,num,p,c;
	NODE head=NULL;
	printf("Enter total number of terms:\n");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("Enter coefficient:\n");
		scanf("%d",&c);
		printf("Enter power:\n");
		scanf("%d",&p);
		head = insert(head,p,c);
	}
	return head;
}


void display(NODE head)
{

	NODE temp;
	temp = head->next;

	do
	{
		printf("%d(X)^%d",temp->coef,temp->pow);
		temp=temp->next;
		printf("    +    ");
	}while(temp!=head);
	printf("%d(X)^%d\t = 0",temp->coef,temp->pow);
	printf("\n");
}

NODE add( NODE poly1, NODE poly2)
{

    NODE temp, poly3;
    poly3=NULL;
    temp= poly1->next;
    do
    {
     poly3= insert(poly3, temp->pow, temp->coef);
     temp=temp->next;
    }
    while(temp!=poly1->next);
    temp= poly2->next;


    do
    {
     poly3 = insert(poly3, temp->pow, temp->coef);
     temp=temp->next;
    }while(temp!=poly2->next);

    return poly3;
}


NODE mult( NODE poly1, NODE poly2)
{
  NODE temp1, temp2, poly3;
  poly3=NULL;
  temp1= poly1->next;
   temp2= poly2->next;
  do{
      	do{
      	    	poly3 = insert(poly3,(temp1->pow + temp2->pow), (temp1->coef * temp2->coef)) ;
      	    	temp2=temp2->next;
      	   }
      	    while(temp2!=poly2->next);

      	    temp1=temp1->next;
    }
    while(temp1!=poly1->next);

    return poly3;

 }

int eval(NODE poly, int x)
{
   NODE temp;
   int sum=0;
   temp=poly->next;
   do{
   	sum= sum + (temp->coef * (pow(x,temp->pow)));
   	}
   	while(temp!=poly->next);

   	return sum;
}
/*
Enter your choice:
1: Accept
2: Display
3: Addition
4: multiplication
5: Evaluate
6: Exit
1
Enter the details for polynomial 1:
Enter total number of terms:
3
Enter coefficient:
1
Enter power:
2
Enter coefficient:
2
Enter power:
3
Enter coefficient:
3
Enter power:
4
Enter the details for polynomial 2:
Enter total number of terms:
2
Enter coefficient:
3
Enter power:
3
Enter coefficient:
4
Enter power:
4
Enter your choice:
1: Accept
2: Display
3: Addition
4: multiplication
5: Evaluate
6: Exit
2
The polynomial 1:
3(X)^4    +    2(X)^3    +    1(X)^2     = 0
The polynomial 2:
4(X)^4    +    3(X)^3    = 0
Enter your choice:
1: Accept
2: Display
3: Addition
4: multiplication
5: Evaluate
6: Exit
2
The polynomial 1:
3(X)^4    +    2(X)^3    +    1(X)^2     = 0
The polynomial 2:
4(X)^4    +    3(X)^3    = 0
Enter your choice:
1: Accept
2: Display
3: Addition
4: multiplication
5: Evaluate
6: Exit
3
The Addition of polynomial is:
7(X)^4    +    5(X)^3    +    1(X)^2     = 0
Enter your choice:
1: Accept
2: Display
3: Addition
4: multiplication
5: Evaluate
6: Exit
4
The multiplication of polynomial is:
12(X)^8    +    17(X)^7    +    10(X)^6    +    3(X)^5   = 0
Enter your choice:
1: Accept
2: Display
3: Addition
4: multiplication
5: Evaluate
6: Exit
5
Enter the value for x
1
The evaluation of x in polynomial 1 is:3
The evaluation of x in polynomial 2 is:4
Enter your choice:
1: Accept
2: Display
3: Addition
4: multiplication
5: Evaluate
6: Exit
6

Process returned 6 (0x6)   execution time : 63.757 s
Press any key to continue.
