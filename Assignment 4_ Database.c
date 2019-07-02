//Name: KARA PRIYANKA   Roll no.: 03   Batch: A1
// Assignment 4: Database.
#include<stdio.h>
#include<string.h>
struct student 
{
  int flag;
  int rollno;
  char name[30];
  int age;
};
void create(struct student [30],int);// Helps in creating the data base.
void bubblesort(struct student [30],int);// Sorts the data according the roll number.
void display(struct student [30], int);// displays the data base as a table.
int insert(struct student [30],int);// inserts data at the end of the database.
void search(struct student [30],int);// Searches the data. 
void modify(struct student [30],int);//Modifies the data.
void delete(struct student [30],int);// deletes the data. 
void main()
{
  struct student s[30];
  int n,q,m,flag;
  do
  {
    printf("\n1.Creating the data\n2.Displaying data\n3.Insert\n4.Search\n5.Modify\n6.Delete\n7.EXIT\n");
    scanf("%d",&q);
    switch(q)
    {
      case 1:
        {
          do
          {
            printf("Enter the number of data to be entered:\n");
            scanf("%d",&n);
            if(n<=30)
            {
             create(s,n); 
             flag=1;
            }
            else
              flag=0;
          }while(flag==0);
          break;       
        }
      case 2:
        {
          bubblesort(s,n);
          display(s,n);
          break;        
        }
      case 3:
        {
           n=insert(s,n);
           printf("Total number of data present now is %d\n",n);
           break;
        }
      case 4:
        {
          search(s,n);
          break;        
        }
      case 5:
        {
          modify(s,n);
          printf("Data modified successfully!!\n");
          display(s,n);
          break;
        }
      case 6:
        {
          delete(s,n);
          printf("Data deleted successfully!!\n");
          display(s,n);
          break;
        }
    }
  }while(q!=7);
}
// Creating the Database.
void create(struct student s[30],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
     s[i].flag=1;
     printf("\nenter the data:\n");
     printf("Enter the roll number:\n");
     scanf("%d",&s[i].rollno);
     printf("Enter name:\n");
     scanf("%s",&s[i].name);
     printf("Enter age:\n");
     scanf("%d",&s[i].age);
  }
  printf("Database successfully created!!\n");
}
// Displaying the Database.
void display(struct student s[30],int n)
{
  int i;
  printf("Rollno\t\t\t\tName\t\t\t\tAge\n");
  for(i=0;i<n;i++)
  {
    if(s[i].flag==1)
    {
      printf("%d\t\t\t\t",s[i].rollno);
      printf("%s\t\t\t\t",s[i].name);
      printf("%d\n",s[i].age);
    }
  }
  printf("the above is the data entered!!\n");
}
// Inserting another data.
int insert(struct student s[30],int n)
{
    int i,m;
    printf("How many data you have to enter?");
    scanf("%d",&m);
    for(i=n;i<(m+n);i++)
    {
       s[i].flag=1;
       printf("\nenter the data:\n");
       printf("Enter the roll number:\n");
       scanf("%d",&s[i].rollno);
       printf("Enter name:\n");
       scanf("%s",&s[i].name);
       printf("Enter age:\n");
       scanf("%d",&s[i].age);
    }
    return n+m;
}
// Searching the data.
void search(struct student s[30],int n)
{
  int i,j;
  printf("enter the roll number of the student whose data is to be found :\n");
  scanf("%d",&i);
  for(j=0;j<n;j++)
  {
    if(i==s[j].rollno&&s[j].flag==1)
    {
      printf("%d\t\t\t\t",s[j].rollno);
      printf("%s\t\t\t\t",s[j].name);
      printf("%d\n",s[j].age);
      break;
    }  
  }
  if(j==n)
  {
    printf("error!!!entered roll number data is not present\n"); 
  }
}
// Modifies the data.
void modify(struct student s[30],int n)
{
  int u,i,q;
   printf("Enter the roll number whose data is to be Modified:\n");
  scanf("%d",&u);
  for(i=0;i<n;i++)
  {
    if(u==s[i].rollno&&s[i].flag==1)
    {
      do 
      {
        printf("\n1.Modify Name\n2.Modify Age\n3.exit\n");
        scanf("%d",&q);
        switch(q)
        {
          case 1: 
          {
             printf("Enter name:\n");
             scanf("%s",&s[i].name);
             break;
          }
          case 2:
          {
             printf("Enter age:\n");
             scanf("%d",&s[i].age);
             break;          
          }
        }
      }while(q!=3);
      break;
    } 
  }
  if(i==n)
  {
    printf("error!!!entered roll number data is not present\n"); 
  }
}
// Deleting the data.
void delete(struct student s[30],int n)
{
  int u,i;
  printf("Enter the roll number whose data is to be deleted:\n");
  scanf("%d",&u);
  for(i=0;i<n;i++)
  {
    if(u==s[i].rollno)
    {
      s[i].flag=0;  
      break;
    } 
  }
  if(i==n)
  {
    printf("error!!!entered roll number data is not present\n"); 
  }
}
// Sorts the data accourding to increasing order of rollno.
void bubblesort(struct student s[30],int n)
{
  int i,j;
  struct student e;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(s[i].rollno<s[j].rollno)
      {
         e=s[i];
         s[i]=s[j];
         s[j]=e;
      }
    }
  }
}
/*
  OUTPUT:
[student@localhost Documents]$ gcc q.c
[student@localhost Documents]$ ./a.out

1.Creating the data
2.Displaying data
3.Insert
4.Search
5.Modify
6.Delete
7.EXIT
1
Enter the number of data to be entered:
2

enter the data:
Enter the roll number:
3
Enter name:
kara
Enter age:
19

enter the data:
Enter the roll number:
2
Enter name:
priyanka
Enter age:
19
Database successfully created!!

1.Creating the data
2.Displaying data
3.Insert
4.Search
5.Modify
6.Delete
7.EXIT
2
Rollno				Name				Age
2				priyanka				19
3				kara				19
the above is the data entered!!

1.Creating the data
2.Displaying data
3.Insert
4.Search
5.Modify
6.Delete
7.EXIT
3
How many data you have to enter?2

enter the data:
Enter the roll number:
5
Enter name:
uttu
Enter age:
18

enter the data:
Enter the roll number:
4
Enter name:
gibran
Enter age:
19
Total number of data present now is 4

1.Creating the data
2.Displaying data
3.Insert
4.Search
5.Modify
6.Delete
7.EXIT
2
Rollno				Name				Age
2				priyanka				19
3				kara				19
4				gibran				19
5				uttu				18
the above is the data entered!!

1.Creating the data
2.Displaying data
3.Insert
4.Search
5.Modify
6.Delete
7.EXIT
4
enter the roll number of the student whose data is to be found :
4
4				gibran				19

1.Creating the data
2.Displaying data
3.Insert
4.Search
5.Modify
6.Delete
7.EXIT
5
Enter the roll number whose data is to be Modified:
2

1.Modify Name
2.Modify Age
3.exit
1
Enter name:
Priyanka

1.Modify Name
2.Modify Age
3.exit
3
Data modified successfully!!
Rollno				Name				Age
2				Priyanka				19
3				kara				19
4				gibran				19
5				uttu				18
the above is the data entered!!

1.Creating the data
2.Displaying data
3.Insert
4.Search
5.Modify
6.Delete
7.EXIT
4
enter the roll number of the student whose data is to be found :
6
error!!!entered roll number data is not present

1.Creating the data
2.Displaying data
3.Insert
4.Search
5.Modify
6.Delete
7.EXIT
6
Enter the roll number whose data is to be deleted:
3
Data deleted successfully!!
Rollno				Name				Age
2				Priyanka				19
4				gibran				19
5				uttu				18
the above is the data entered!!

1.Creating the data
2.Displaying data
3.Insert
4.Search
5.Modify
6.Delete
7.EXIT
7
[student@localhost Documents]$ 
*/
