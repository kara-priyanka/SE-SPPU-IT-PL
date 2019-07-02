// Name: KARA PRIYANKA  Roll no.: 03   Batch: A1
// Matrix operations using pointers.
#include<stdio.h>
#include<stdlib.h>
int** accept(int,int);
void display(int**,int,int);
int** add(int**,int**,int,int);// Only possible when the number of rows and columns are equal.
int** multi(int**,int,int,int**,int);//m1(r1Xc1) and m2(r2Xc2) then c1=r2 for multiplication to occur
void trans(int**,int,int);
void saddlepoint(int**,int ,int);// Element highest in column and lowest in the row.
void main()
{
  int **m1,**m2,**m3,r1,c1,r2,c2,n;
  do  
  {
    printf("\n1.Accept The Matrix's\n2.Display The Matrix's\n3.Add\n4.Multiplication\n5.Transpose\n6.Finding Saddle Point\n7.EXIT\n\n");
    scanf("%d",&n);
    printf("\n");
    switch(n)
    {
      case 1:
           {
             printf("enter the rows and columns of the 1st matrix\n");
             scanf("%d\n%d",&r1,&c1);
             m1=accept(r1,c1);  
             printf("\nenter the rows and columns of the 2nd matrix:\n");   
             scanf("%d\n%d",&r2,&c2); 
             m2=accept(r2,c2);
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
           m3=add(m1,m2,r1,c1);
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
           m3=multi(m1,r1,c1,m2,c2);
           printf("Multiplication of the Matrices:\n");
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
            printf("the saddle point of Matrix 1: ");
            trans(m1,r1,c1);
            saddlepoint(m1,r1,c1);
	    printf("the saddle point of Matrix 2: ");
	    trans(m1,r1,c1);
	    saddlepoint(m2,r2,c2);
	    break;
         }
       
    }
   }while(n!=7);
}
// Accepting the Matrix.
int** accept(int r,int c)
{
  int **m,i,j;
  m=(int**)malloc(r*sizeof(int*));
  for(i=0;i<r;i++)
  {
     *(m+i)=(int*)malloc(c*sizeof(int*));
  }
  printf("enter the elements:\n");
  for(i=0;i<r;i++)
  {  printf("enter the row elements:\n");
     for(j=0;j<c;j++)
     scanf("%d",(*(m+i)+j));
  }
 return m;
}
// Displaying the matrix.
void display (int **m,int r,int c)
{
   int i,j;
   for(i=0;i<r;i++)
  {
    printf("[");
    for(j=0;j<c;j++)
      {
        printf("%d",*(*(m+i)+j));
        if(j<(c-1))
         {
           printf("\t");
         }
      }
    printf("]");
    printf("\n");
  }
}
// Addition Function with pointers.
int** add(int **m1,int **m2,int r,int c)
{
  int i,j,**m3;
  m3=(int**)malloc(r*sizeof(int*));
  for(i=0;i<r;i++)
  {
     *(m3+i)=(int*)malloc(c*sizeof(int*));
  }                                                //memory allocating to add array.
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      *(*(m3+i)+j)=*(*(m1+i)+j)+*(*(m2+i)+j);
    }
  }
  return m3;
}
// Multiplication Function with pointer.
int** multi(int **m1,int r1,int c1,int **m2,int c2)
{
  int **m3,i,j,k;
  m3=(int **)malloc(r1* sizeof(int*));   /*Memory allocation for matrix m3*/
  for(i=0;i<r1;i++)
   {
     *(m3+i)=(int *)malloc(c2* sizeof(int));
   }
  for(i=0;i<r1;i++)
  {
    for(j=0;j<c2;j++)
     {
       *(*(m3+i)+j)=0;
       for(k=0;k<c1;k++)
       {
         (*(*(m3+i)+j))=(*(*(m1+i)+k))*(*(*(m2+k)+j))+(*(*(m3+i)+j));
       }
     }
  }
return m3;
}
// Transpose with pointers
void trans(int **m1,int r1,int c1)
{
  int i,j,temp;
  for(i=0;i<c1;i++)
   {
     for(j=i;j<r1;j++)
      {
       temp=*(*(m1+i)+j);
       *(*(m1+i)+j)=*(*(m1+j)+i);
       *(*(m1+j)+i)=temp;
      }
   }
}
// Finding Saddle point in a Matrix.
void saddlepoint(int **m1,int r1, int c1)
{
  int i,j,k,min,max,colpos,rowpos=0,f=0;
  for (i=0;i<r1;i++)
  {
    colpos=0;			
    min=*(*(m1+i)+0);
    for (j=0;j<c1;j++)
    {
       if(*(*(m1+i)+j)<min)
	{
	   min=*(*(m1+i)+j);
	   colpos=j;
	}
    }
    max=*(*(m1+0)+colpos);
    for (k=0;k<r1;k++)
    {
     if((*(*(m1+k)+colpos))>max)
     {
	max=(*(*(m1+k)+colpos));
	rowpos=k;
     }
    }
    if(i==rowpos)
    {
      f=1;
      printf("saddle point present at %dX%d\n",rowpos+1,colpos+1);
    }
  }
  if (f==0)
  {
     printf("No saddle point\n");
  }
}
/*
OUTPUT:
[student@localhost Downloads]$ gcc A2b.c
[student@localhost Downloads]$ ./a.out

1.Accept The Matrix's
2.Display The Matrix's
3.Add
4.Multiplication
5.Transpose
6.Finding Saddle Point
7.EXIT

1

enter the rows and columns of the 1st matrix
3
3
enter the elements:
enter the row elements:
1
2
3
enter the row elements:
4
5
6
enter the row elements:
7
8
9

enter the rows and columns of the 2nd matrix:
3
3
enter the elements:
enter the row elements:
1
2
3
enter the row elements:
0
9
8
enter the row elements:
5
4
3

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
[1	2	3]
[0	9	8]
[5	4	3]

1.Accept The Matrix's
2.Display The Matrix's
3.Add
4.Multiplication
5.Transpose
6.Finding Saddle Point
7.EXIT

3

Addition of the Matrices:
[2	4	6]
[4	14	14]
[12	12	12]

1.Accept The Matrix's
2.Display The Matrix's
3.Add
4.Multiplication
5.Transpose
6.Finding Saddle Point
7.EXIT

4


Multiplication of the Matrices:
[16	32	28]
[34	77	70]
[52	122	112]

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
[1	0	5]
[2	9	4]
[3	8	3]


1.Accept The Matrix's
2.Display The Matrix's
3.Add
4.Multiplication
5.Transpose
6.Finding Saddle Point
7.EXIT

6

the saddle point of Matrix 1: saddle point present at 3X1
the saddle point of Matrix 2: saddle point present at 3X1

1.Accept The Matrix's
2.Display The Matrix's
3.Add
4.Multiplication
5.Transpose
6.Finding Saddle Point
7.EXIT

7
*/
