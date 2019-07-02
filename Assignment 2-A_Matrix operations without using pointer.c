// Name: KARA PRIYANKA  Roll no.: 03  Batch: A1
//Matrix operations without pointers.
#include<stdio.h>
void accept(int [10][10],int ,int);
void display(int[10][10],int ,int);
int validate(int,int);
void add(int[10][10],int[10][10],int[10][10],int,int);// Only possible when the number of rows and columns are equal.
void multi(int[10][10],int,int,int[10][10],int,int[10][10]);//m1(r1Xc1) and m2(r2Xc2) then c1=r2 for multiplication to occur
void trans(int [10][10],int,int);
void saddle(int [10][10],int,int);// Element highest in column and lowest in the row.
void main()
{
int m1[10][10],m2[10][10],m3[10][10],r1,c1,n,r,c,r2,c2,f;
do
{
  printf("\n1.Accept The Matrix's\n2.Display The Matrix's\n3.Add\n4.Multiplication\n5.Transpose\n6.Finding Saddle Point\n7.EXIT\n");
  scanf("%d",&n);
  switch(n)
  {
    case 1:
        {
               printf("\n");
               printf("enter the number of rows and columns of the 1st matrix respectively:\n");
               scanf("%d\n%d",&r1,&c1);
               f=validate(r1,c1);
               while(f==0)
                {
                  printf("enter the number of rows and columns of the 1st matrix respectively again:\n");
                  scanf("%d\n%d",&r1,&c1);
                   f=validate(r1,c1);
                };
               printf("enter the elements:\n");
               accept(m1,r1,c1);
               printf("enter the number of rows and columns of the 2nd matrix respectively:\n");
               scanf("%d\n%d",&r2,&c2);
               f=validate(r2,c2);
               while(f==0)
                {
                  printf("enter the number of rows and columns of the 2nd matrix respectively again:\n");
                  scanf("%d\n%d",&r2,&c2);
                  f=validate(r2,c2);
                };
               printf("enter the elements:\n");
               accept(m2,r2,c2);
               break;
            }
    case 2:
        {
             printf("The 1st Matrix:\n");
             display(m1,r1,c1);
             printf("\n");
             printf("The 2nd Matrix:\n");
             display(m2,r2,c2);
             break;

        }
    case 3:
         { 

           if(r1==r2&&c1==c2)
           {
           add(m1,m2,m3,r1,c1);
           printf("Addition of the Matrices:\n");
           display(m3,r1,c1);
           }
           else
           printf("Addition is not possible\n");
           break;
         }
    case 4:
         { 
           printf("\n");
           if(c1==r2)
           {
           multi(m1,r1,c1,m2,c2,m3);
           printf("Multiplication of Matrices:\n");
           display(m3,r1,c2);
           }
           else
           printf("multiplication not possible\n");
           break;
         }
    case 5:
         {
           printf("\n");
           if(r1==c1)
            {
              trans(m1,r1,c1);
              printf("transpose of set 1 is :\n");
              display(m1,r1,c1);
            }
           if(r2==c2)
           {
              trans(m2,r2,c2);
              printf("transpose of set 2 is :\n");
              display(m2,r2,c2);
           }
           printf("\n");
           break;
          }
    case 6:
          {
            printf("\n");
            saddle(m1,r1,c1);
            saddle(m2,r2,c2);
            printf("\n");
            break;        
          }
  }
 }while(n!=7);
}
// Function to Validate the entered data.
int validate(int n,int k)
{
  int flag=0;
  if(n<=10&&k<=10)
  {
   flag=1;
  }
  else
   {
     printf("error\n");
   }
 return flag;
}
// Accepting the elements of matrix.
void accept(int m[][10],int r,int c)
{
  int i,j;
  for(i=0;i<r;i++)
  {
    printf("enter the elements of row:\n");
    for(j=0;j<c;j++)
     {
       scanf("%d",&m[i][j]);
     }
  }
}
// Displaying the matrix.
void display(int m[][10],int r,int c)
{
int i,j;
  for(i=0;i<r;i++)
  { printf("[");
    for(j=0;j<c;j++)
     {
       printf("%d",m[i][j]);
       if(j<(c-1))
       {
           printf("\t");
       }
     }
    printf("]");
    printf("\n");
  }
}
// Addition of two matrices.
void add(int m1[][10],int m2[][10],int m3[][10],int r,int c)
{
  int i,j;
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      m3[i][j]=m1[i][j]+m2[i][j];
    }
  }
}
// Multiplication of two matrices.
void multi(int m1[][10],int r1,int c1,int m2[][10],int c2,int m3[][10])
{
  int i,j,k;
  for(i=0;i<r1;i++)
  {
    for(j=0;j<c2;j++)
    {
      m3[i][j]=0; 
      for(k=0;k<c1;k++)
      {
        m3[i][j]=m1[i][k]*m2[k][j]+m3[i][j];       
      }
    }
  }
}
// Transpose of matrix.
void trans(int m1[][10],int r1,int c1)
{
  int i,j,temp;
  for(i=0;i<c1;i++)
   {
     for(j=i;j<r1;j++)
      {
        temp=m1[i][j];
        m1[i][j]=m1[j][i];
        m1[j][i]=temp;
      }
   }
}
// Finding the saddle point.
void saddle(int m[][10],int r,int c)
{
  int i,j,k,min,max,rowpos=0,colpos,f=0;
  for(i=0;i<r;i++)
  {
    colpos=0;
    min=m[i][0];
    for(j=0;j<c;j++)
    {
      if(m[i][j]<min)
      {
        min=m[i][j];
        colpos=j;
      }
    }
    max=m[0][colpos];
    for(k=0;k<r;k++)
    {
      if(m[k][colpos]>max)
      {
      max=m[k][colpos];
      rowpos=k;     
      }
    }
    if(i==rowpos)
    {
       f=1;
       printf("The saddle point of given matrix is at %dX%d\n",rowpos+1,colpos+1);
    }
  }
  if(f==0)
  {
     printf("There is no saddle point in the given matrix\n");
  }
}
/*
OUTPUT:
[student@localhost Downloads]$ gcc A2.c
[student@localhost Downloads]$ ./a.out

1.Accept The Matrix's
2.Display The Matrix's
3.Add
4.Multiplication
5.Transpose
6.Finding Saddle Point
7.EXIT
1

enter the number of rows and columns of the 1st matrix respectively:
3
3
enter the elements:
enter the elements of row:
1
2
3
enter the elements of row:
4
5
6
enter the elements of row:
7
8
9
enter the number of rows and columns of the 2nd matrix respectively:
3
3
enter the elements:
enter the elements of row:
1
2
0
enter the elements of row:
4
5
7
enter the elements of row:
2
3
0

1.Accept The Matrix's
2.Display The Matrix's
3.Add
4.Multiplication
5.Transpose
6.Finding Saddle Point
7.EXIT
2
The 1st Matrix:
[1	2	3]
[4	5	6]
[7	8	9]

The 2nd Matrix:
[1	2	0]
[4	5	7]
[2	3	0]

1.Accept The Matrix's
2.Display The Matrix's
3.Add
4.Multiplication
5.Transpose
6.Finding Saddle Point
7.EXIT
3
Addition of the Matrices:
[2	4	3]
[8	10	13]
[9	11	9]

1.Accept The Matrix's
2.Display The Matrix's
3.Add
4.Multiplication
5.Transpose
6.Finding Saddle Point
7.EXIT
4

Multiplication of Matrices:
[15	21	14]
[36	51	35]
[57	81	56]

1.Accept The Matrix's
2.Display The Matrix's
3.Add
4.Multiplication
5.Transpose
6.Finding Saddle Point
7.EXIT
5

transpose of set 1 is :
[1	4	7]
[2	5	8]
[3	6	9]
transpose of set 2 is :
[1	4	2]
[2	5	3]
[0	7	0]


1.Accept The Matrix's
2.Display The Matrix's
3.Add
4.Multiplication
5.Transpose
6.Finding Saddle Point
7.EXIT
6

The saddle point of given matrix is at 3X1
The saddle point of given matrix is at 2X1


1.Accept The Matrix's
2.Display The Matrix's
3.Add
4.Multiplication
5.Transpose
6.Finding Saddle Point
7.EXIT
7
[student@localhost Downloads]$ 
*/
