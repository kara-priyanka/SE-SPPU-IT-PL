// Name: KARA PRIYANKA     Roll no.: 03    Batch: A1
// Assignment 9: Singly Linked List

#include <stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *next;
};

struct node *getnode()
{
  struct node *nn;
  nn=(struct node *) malloc(sizeof(struct node));

  printf("\n enter data for node-->");
  scanf("%d",&nn->data);

  nn->next=NULL;
  return nn;
}


struct node *insertbegin(struct node *head)
{
  struct node *nn;
  nn=getnode();

  if(head==NULL)
   head=nn;

  else
  {
    nn->next=head;
    head=nn;
  }
  return head;
}


void display(struct node *head)
{
  struct node *p;
  if(head==NULL)
   printf("\nempty linked list");

  else
  {
    p=head;
    while(p!=NULL)
    {
      printf("\t%d",p->data);
      p=p->next;
    }
  }
}

struct node *insertend(struct node *head)
{
  struct node *nn,*p;
  nn=getnode();

  if(head==NULL)
   head=nn;

  else
  { p=head;
    while(p->next!=NULL)
    {
      p=p->next;
    }
    p->next=nn;

  }
  return head;
}


struct node *insertmid(struct node *head)
{
  int key;
  struct node *nn,*p,*q;
  nn=getnode();

  if(head==NULL)
   head=nn;

  else
  {
     printf("\nEnter the key after which node to insert-->");
     scanf("%d",&key);

     p=head;
     while( p!=NULL && p->data!=key)
     {
        p=p->next;
     }

     if(p==NULL)
     {
        printf("no such key in sll");
     }
     else
     {
        q=p->next;
        p->next=nn;
        nn->next=q;
     }
   }

    return head;
}


struct node *deletebegin(struct node *head)
{
  struct node *p;

  if(head==NULL)
  {
    printf("\n sll is empty so can't delete");
  }

  else
  {
     p=head;
     head=head->next;
     printf("\n deleted node data-->%d\n",p->data);
     free(p);
  }
  return head;
}


struct node *deleteend(struct node *head)
{
  struct node *p,*q;

  if(head==NULL)
  {
    printf("\n sll is empty so can't delete");
  }

  else if(head->next==NULL)
  {
     p=head;
     head=NULL;
     printf("\ndeleted node-->%d",p->data);
     free(p);
  }

  else
  {
     p=head;
     while(p->next!=NULL)
     {
       q=p;
       p=p->next;
     }
      q->next=NULL;

     free(p);
   }
    return head;
}


struct node *deletemid(struct node *head)
{
  int key;
  struct node *p,*nn,*q;

  printf("\n enter data of node for deletion-->");
  scanf("%d",&key);

  if(head==NULL)
  {
    printf("\n sll is empty so can't delete");
  }

   else if(head->next==NULL)
  {
     p=head;
     head=NULL;
     printf("\ndeleted node-->%d",p->data);
     free(p);
  }

  else if(head->data==key) //del begin
  {
     p=head;
     head=head->next;
     printf("\ndeleted node-->%d",p->data);
     free(p);
  }

  else //any position
  {

     p=head;
     while(p->data!=key && p!=NULL)
     {
       q=p;
       p=p->next;
     }

     if(p==NULL)
      printf("no such key in sll");
     else
     {
        q->next=p->next;
        free(p);
     }
   }
     return head;
}


struct node *reverse(struct node *head)
{
   struct node *t1,*t2;
   t1=head;
   t2=head->next;
   head=t2->next;
   t1->next=NULL;

   while(t2!=NULL)
   {
     t2->next=t1;
     t1=t2;
     t2=head;

     if(head!=NULL)
     head=head->next;
   }

    head=t1;
    return head;
}



int main()
{
   struct node *head=NULL;
   int ch,rept;

do
 {
   printf("\n1.insert at begin\n2.display\n3.insert at end\n4.insert at mid\n5.delete from begin\n6.delete from end\n7.delete from mid\n8.reverse\n9.EXIT\n");
   scanf("%d",&ch);

  switch(ch)
   {
      case 1:head=insertbegin(head);
             display(head);
             printf("\n");
             break;

      case 2:display(head);
             break;

      case 3:head=insertend(head);
             display(head);
             printf("\n");
             break;

      case 4:head=insertmid(head);
             display(head);
             printf("\n");
             break;

      case 5:head=deletebegin(head);
             display(head);
             printf("\n");
             break;

      case 6:head=deleteend(head);
             display(head);
             printf("\n");
             break;

      case 7:head=deletemid(head);
             display(head);
             printf("\n");
             break;

      case 8:head=reverse(head);
             display(head);
             printf("\n");
             break;
   }


 }while(ch!=9);
  return 0;
 }











/*1.insert at begin
2.display
3.insert at end
4.insert at mid
5.delete from begin
6.delete from end
7.delete from mid
8.reverse

 enter ur choice-->1

 enter data for node-->2
        2

 do u want to continue-->1

1.insert at begin
2.display
3.insert at end
4.insert at mid
5.delete from begin
6.delete from end
7.delete from mid
8.reverse

 enter ur choice-->1

 enter data for node-->3
        3       2

 do u want to continue-->1

1.insert at begin
2.display
3.insert at end
4.insert at mid
5.delete from begin
6.delete from end
7.delete from mid
8.reverse

 enter ur choice-->3

 enter data for node-->4
        3       2       4

 do u want to continue-->1

1.insert at begin
2.display
3.insert at end
4.insert at mid
5.delete from begin
6.delete from end
7.delete from mid
8.reverse

 enter ur choice-->3

 enter data for node-->5
        3       2       4       5

 do u want to continue-->1

1.insert at begin
2.display
3.insert at end
4.insert at mid
5.delete from begin
6.delete from end
7.delete from mid
8.reverse

 enter ur choice-->4

 enter data for node-->6

Enter the key after which node to insert-->4
        3       2       4       6       5

 do u want to continue-->1

1.insert at begin
2.display
3.insert at end
4.insert at mid
5.delete from begin
6.delete from end
7.delete from mid
8.reverse

 enter ur choice-->4

 enter data for node-->7

Enter the key after which node to insert-->6
        3       2       4       6       7       5

 do u want to continue-->1

1.insert at begin
2.display
3.insert at end
4.insert at mid
5.delete from begin
6.delete from end
7.delete from mid
8.reverse

 enter ur choice-->2
        3       2       4       6       7       5
 do u want to continue-->1

1.insert at begin
2.display
3.insert at end
4.insert at mid
5.delete from begin
6.delete from end
7.delete from mid
8.reverse

 enter ur choice-->5

 deleted node data-->3
        2       4       6       7       5

 do u want to continue-->1

1.insert at begin
2.display
3.insert at end
4.insert at mid
5.delete from begin
6.delete from end
7.delete from mid
8.reverse

 enter ur choice-->6
        2       4       6       7

 do u want to continue-->1

1.insert at begin
2.display
3.insert at end
4.insert at mid
5.delete from begin
6.delete from end
7.delete from mid
8.reverse

 enter ur choice-->7

 enter data of node for deletion-->4
        2       6       7

 do u want to continue-->1

1.insert at begin
2.display
3.insert at end
4.insert at mid
5.delete from begin
6.delete from end
7.delete from mid
8.reverse

 enter ur choice-->8
        7       6       2 */
