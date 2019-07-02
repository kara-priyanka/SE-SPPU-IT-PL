// Name: KARA PRIYANKA  Roll no.: 03   Batch: A1
// Assignment 12: Generalized Linked List

#include<stdio.h>
#include<stdlib.h>
union x
{
        char c;
        struct node *down;
};
struct node
{
        int ind;
        union x data;
        struct node *next;
};
struct node *create(char *s);
void display(struct node *nm);
int main()
{
        int ch,i,no;
        struct node *nm;
        char s[100];
        do
        {
           printf("\nMENU\n1.Insert\n2.Display\n3.Exit\nEnter your choice: ");
           scanf("%d",&ch);
            switch(ch)
                {
                        case 1: printf("\nEnter the data");
                                scanf("%s",&s);
                                nm=create(s);
                                break;
                        case 2: display(nm);
                                break;
                        case 3: break;
                }
        }while(ch!=3);
        return 0;
}
struct node *create(char *s)
{
        static int i=0;
        struct node *nm;
        nm=NULL;
        if(s[i]=='\0')
        {
         return NULL;
         }
        while(s[i]==','||s[i]==' ')
        {
          i++;
         }
        nm=(struct node *)malloc(sizeof(struct node));
        nm->next=NULL;
        if(s[i]=='(')
        {
                nm->ind=1;
                i++;
                nm->data.down=create(s);
                if(s[i]!='\0')
                {
                        nm->next=create(s);
                }
        }
        else  if(s[i]!=')'&&s[i]!=',')
                {
                     nm->ind=0;
                      nm->data.c=s[i];
                     i++;
                      nm->next=create(s);
                }
         else   if(s[i]==')')
         {
             i++;
             free(nm);
             return NULL;
         }
         return nm;
}
void display(struct node *nm)
{
        struct node *p;
        if(nm!=NULL)
        {
                if(nm->ind==0)
                {
                        printf("%c,",nm->data.c);
                        display(nm->next);
                }
                else
                {
                        printf("(");
                        display(nm->data.down);
                        printf(")");
                        if(nm->next!=NULL)
                        {
                                 display(nm->next);
                        }
                }
         }
}
/*

MENU
1.Insert
2.Display
3.Exit
Enter your choice: 1

Enter the data(x,(y,z),a,b)

MENU
1.Insert
2.Display
3.Exit
Enter your choice: 2
(x,(y,z,)a,b,)
MENU
1.Insert
2.Display
3.Exit
Enter your choice: 3*/

