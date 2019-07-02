// Name: KARA PRIYANKA     Roll no.: 03     Batch: A1
//Assignment 5: File Handling.
#include<stdio.h>
struct student
{
  int flag;
  int rollno;
  char name[30];
  int age;
};

void accept();
void display();
void search(int);
void modify(int);
void delete(int);

void main()
{
  int q,n,i,no,key;
  do
  {
    printf("\n******MENU******\n1.Creating the data\n2.Displaying data\n3.Insert\n4.Search\n5.Modify\n6.Delete\n7.EXIT\n");
    scanf("%d",&q);
    switch(q)
    {
       case 1:
           printf("Enter number of data to be entered:\n ");
           scanf("%d",&n);
           for(i=0;i<n;i++)
           {
              accept();
           }
           break;
       case 2:
           printf("\nRollno\t\t\t\tName\t\t\t\tAge\n");
           display();
           break;
       case 3:
           printf("\nNumber of data you want to insert:\n");
           scanf("%d",&no);
           for(i=0;i<no;i++)
           {
             accept();
           }
           break;
       case 4:
           printf("\nEnter the roll no. to be searched:\n");
           scanf("%d",&key);
           search(key);
           break;
       case 5:
           printf("\nEnter the roll no. to be Modified:\n");
           scanf("%d",&key);
           modify(key);
           break;
       case 6:
           printf("\nEnter the roll no. to be Delete:\n");
           scanf("%d",&key);
           delete(key);
           break;
     }// end of switch.
  }while(q!=7);
}

//Accepting The Records.
void accept()
{
  struct student s;
  FILE *fp;
  fp=fopen("student_data.txt","a+");
  if(fp==NULL)
  {
     printf("\nError!!!\n");
     return;
  }
  int i,n;
  s.flag=1;
  printf("\nenter the data:\n");
  printf("Enter the roll number:\n");
  scanf("%d",&s.rollno);
  printf("Enter name:\n");
  scanf("%s",&s.name);
  printf("Enter age:\n");
  scanf("%d",&s.age);
  fwrite(&s,sizeof(s),1,fp);
  fclose(fp);
}

//Display's the Record.
void display()
{
   struct student s;
   FILE *fp;
   fp=fopen("student_data.txt","r");
   if(fp==NULL)
   {
     printf("Error!!");
     return;
   }
   while(fread(&s,sizeof(s),1,fp)==1)
   {
     if(s.flag==1)
     {
      printf("%d\t\t\t\t",s.rollno);
      printf("%s\t\t\t\t",s.name);
      printf("%d\n",s.age);
     }
   }
   printf("Above is the data\n");
   fclose(fp);
}

//Searches the Record according to the Roll number.
void search(int key)
{
   struct student s;
   FILE *fp;
   fp=fopen("student_data.txt","r");
   if(fp==NULL)
   {
     printf("Error!!");
     return;
   }
   while(fread(&s,sizeof(s),1,fp)==1)
   {
     if(s.rollno==key&&s.flag==1)
     {
      printf("Rollno\t\t\t\tName\t\t\t\tAge\n");
      printf("%d\t\t\t\t",s.rollno);
      printf("%s\t\t\t\t",s.name);
      printf("%d\n",s.age);
      fclose(fp);
      return;
     }
   }
   printf("Data not found!!\n");
}

// Modifies the Record.
void modify(int key)
{
  struct student s;
   FILE *fp;
   int q;
   fp=fopen("student_data.txt","r+");
   if(fp==NULL)
   {
     printf("Error!!");
     return;
   }
   while(fread(&s,sizeof(s),1,fp)==1)
   {
     if(key==s.rollno&&s.flag==1)
    {
      printf("Rollno\t\t\t\tName\t\t\t\tAge\n");
      printf("%d\t\t\t\t",s.rollno);
      printf("%s\t\t\t\t",s.name);
      printf("%d\n",s.age);
      do
      {
        printf("\n1.Modify Name\n2.Modify Age\n3.exit\n");
        scanf("%d",&q);
        switch(q)
        {
          case 1:
          {
             printf("Enter name:\n");
             scanf("%s",&s.name);
             break;
          }
          case 2:
          {
             printf("Enter age:\n");
             scanf("%d",&s.age);
             break;
          }
        }// end of switch.
       }while(q!=3);// end of do... while
       fseek(fp,-(sizeof(s)),SEEK_CUR); // -sizeof(s) because we need to move to the previous record as the fp has moved to the next record than the desired one.
       fwrite(&s,sizeof(s),1,fp);
       fclose(fp);
       return;
     }//end of if
   }// enf of main while.
     printf("Data not found!!\n");
}

//Physical Deletion of record.
void delete(int key)
{
   struct student s;
   FILE *fp;
   fp=fopen("student_data.txt","r+");
   if(fp==NULL)
   {
     printf("Error!!");
     return;
   }
   while(fread(&s,sizeof(s),1,fp)==1)
   {
     if(s.rollno==key)
     {
      s.flag=0;
      fseek(fp,-(sizeof(s)),SEEK_CUR);
      fwrite(&s,sizeof(s),1,fp);
      fclose(fp);
      printf("\nData Deleted!!!\n");
      return;
     }
   }
   printf("Data not found!!\n");
}


/*
OUTPUT:

******MENU******
1.Creating the data
2.Displaying data
3.Insert
4.Search
5.Modify
6.Delete
7.EXIT
1
Enter number of data to be entered:
 2

enter the data:
Enter the roll number:
1
Enter name:
kara
Enter age:
18

enter the data:
Enter the roll number:
2
Enter name:
priyanka
Enter age:
18

******MENU******
1.Creating the data
2.Displaying data
3.Insert
4.Search
5.Modify
6.Delete
7.EXIT
2

Rollno                          Name                            Age
1                               kara                            18
2                               priyanka                                18
Above is the data

******MENU******
1.Creating the data
2.Displaying data
3.Insert
4.Search
5.Modify
6.Delete
7.EXIT
3

Number of data you want to insert:
3

enter the data:
Enter the roll number:
3
Enter name:
naina
Enter age:
19

enter the data:
Enter the roll number:
4
Enter name:
ketaki
Enter age:
18

enter the data:
Enter the roll number:
5
Enter name:
ritu
Enter age:
18

******MENU******
1.Creating the data
2.Displaying data
3.Insert
4.Search
5.Modify
6.Delete
7.EXIT
2

Rollno                          Name                            Age
1                               kara                            18
2                               priyanka                                18
3                               naina                           19
4                               ketaki                          18
5                               ritu                            18
Above is the data

******MENU******
1.Creating the data
2.Displaying data
3.Insert
4.Search
5.Modify
6.Delete
7.EXIT
4

Enter the roll no. to be searched:
3
Rollno                          Name                            Age
3                               naina                           19

******MENU******
1.Creating the data
2.Displaying data
3.Insert
4.Search
5.Modify
6.Delete
7.EXIT
5

Enter the roll no. to be Modified:
4
Rollno                          Name                            Age
4                               ketaki                          18

1.Modify Name
2.Modify Age
3.exit
2
Enter age:
19

1.Modify Name
2.Modify Age
3.exit
3

******MENU******
1.Creating the data
2.Displaying data
3.Insert
4.Search
5.Modify
6.Delete
7.EXIT
2

Rollno                          Name                            Age
1                               kara                            18
2                               priyanka                                18
3                               naina                           19
4                               ketaki                          19
5                               ritu                            18
Above is the data

******MENU******
1.Creating the data
2.Displaying data
3.Insert
4.Search
5.Modify
6.Delete
7.EXIT
6

Enter the roll no. to be Delete:
4

Data Deleted!!!

******MENU******
1.Creating the data
2.Displaying data
3.Insert
4.Search
5.Modify
6.Delete
7.EXIT
2

Rollno                          Name                            Age
1                               kara                            18
2                               priyanka                                18
3                               naina                           19
5                               ritu                            18
Above is the data

******MENU******
1.Creating the data
2.Displaying data
3.Insert
4.Search
5.Modify
6.Delete
7.EXIT
7

Process returned 7 (0x7)   execution time : 89.305 s
Press any key to continue.

*/
