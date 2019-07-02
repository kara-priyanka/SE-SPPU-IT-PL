// Name: KARA PRIYANKA    Roll no.: 03   Batch: A1
// Assignment 12: Generalized Linked List

#include<stdio.h>
#include<stdlib.h>

/*--------------------------------------------------------------------------------------------------------------------------------
                                                  Union
----------------------------------------------------------------------------------------------------------------------------------*/
union data
{
  char c;
  struct node *down;
};

/*--------------------------------------------------------------------------------------------------------------------------------
                                                 Node Structure
----------------------------------------------------------------------------------------------------------------------------------*/
typedef struct node
{
  int flag;
  union data data ;
  struct node *next;
}gll;


gll* create(char *);
void display(gll * );

/*--------------------------------------------------------------------------------------------------------------------------------
                                                Beginning of main
----------------------------------------------------------------------------------------------------------------------------------*/
void main()
{
  gll *head=NULL;
  char s[100];
  int n;
  do
  {
    printf("\n*****MENU*****\n1.Create\n2.Display\n3.EXIT\n");
    scanf("%d",&n);
    switch(n)
    {
      case 1:
       printf("\nEnter the Data:\n");
       scanf("%s",s);
       head=create(s);
       break;
      case 2:
       display(head);
       break;
    }// end of Switch


  }while(n!=3);// end of do while
}// main function


/*--------------------------------------------------------------------------------------------------------------------------------
                                                 Create Function
----------------------------------------------------------------------------------------------------------------------------------*/
gll * create(char *s)
 {
    static int i=0;
    gll *new1=NULL;

    if(s[i]=='\0')
    return NULL;

    while(s[i]==',' || s[i]==' ')
    i++;

    new1=(gll*)malloc(sizeof(gll*));
    new1->next=NULL;

      if(s[i]=='(')
      {
     new1->flag=1;
     i++;
     new1->data.down=create(s);

        if(s[i]!='\0')
        new1->next=create(s);

     }
    else
    {
    if(s[i]!=')' && s[i]!=',')
     {
     new1->flag=0;
     new1->data.c=s[i];
     i++;
     new1->next=create(s);
     }
    else
     {
    if(s[i]==')')
     {   i++;
        free(new1);
        return NULL;
     }
     }
  }
  return new1;
}


/*--------------------------------------------------------------------------------------------------------------------------------
                                                  Display Function
----------------------------------------------------------------------------------------------------------------------------------*/
void display(gll *head)
{
  if(head==NULL)
  return;

  if(head->flag==1)
  {
    printf("(");
    display(head->data.down);
    printf("),");

    if(head->next!=NULL)
       display(head->next);
  }
  else
  {
    printf("%c,",head->data.c);
    display(head->next);
  }

}

/*--------------------------------------------------------------------------------------------------------------------------------
                                                      OUTPUT
----------------------------------------------------------------------------------------------------------------------------------

*****MENU*****
1.Create
2.Display
3.EXIT
1

Enter the Data:
A,B,C,(a,b,c),D,(d,e,f),E

*****MENU*****
1.Create
2.Display
3.EXIT
2
A,B,C,(a,b,c,),D,(d,e,f,),E,
*****MENU*****
1.Create
2.Display
3.EXIT
3

Process returned 3 (0x3)   execution time : 28.780 s
Press any key to continue.

----------------------------------------------------------------------------------------------------------------------------------*/

