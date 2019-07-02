// Name: KARA PRIYANKA   Roll no.: 03   Batch: A1
// Assignment 8: Sparse Matrix

#include<stdio.h>

int accept(int [][10],int ,int);
void display(int [][10],int,int);
void convert(int [][10],int,int,int [][10],int);
int add_sparse(int [][10],int [][10],int [][10]);
void tanspose(int [][10],int [][10]);
void fast_transpose(int [][10],int [][10]);

void main()
{
  int m[10][10],m1[10][10],s[10][10],s1[10][10],add[10][10],ts[10][10],ts1[10][10],fs[10][10],fs1[10][10],rm,cm,r1,c1,count,count1,n,f,rows,rows1,k;// S's column ==3 because there are 3 columns only in it 1st column: rows, 2nd column: columns, 3rd column: number of nonzero elements in the matrix.

  do
  {
     printf("\n********MENU**********\n1.Accept The Matrix\n2.Display The Matrix\n3.Convert to Sparse Matrix\n4.Addition of sparse matrices\n5.Transpose of the Matrices\n6.Fast Transpose\n7.EXIT\n");
     scanf("%d",&n);

     switch(n)
     {
        case 1:
        {
               printf("\n");
               printf("enter the number of rows and columns of 1st the matrix respectively:\n");
               scanf("%d\n%d",&rm,&cm);
               f=validate(rm,cm);
               while(f==0)
                {
                  printf("enter the number of rows and columns of 1st the matrix respectively again:\n");
                  scanf("%d\n%d",&rm,&cm);
                   f=validate(rm,cm);
                };
               printf("enter the elements:\n");
               count=accept(m,rm,cm);
               printf("the number of non-zero elements in 1st matrix are: %d\n",count);
               printf("\n");
               // 2nd matrix input.
               printf("enter the number of rows and columns of the 2nd matrix respectively:\n");
               scanf("%d\n%d",&r1,&c1);
               f=validate(r1,c1);
               while(f==0)
                {
                  printf("enter the number of rows and columns of the 2nd matrix respectively again:\n");
                  scanf("%d\n%d",&r1,&c1);
                   f=validate(r1,c1);
                };
               printf("enter the elements:\n");
               count1=accept(m1,r1,c1);
               printf("the number of non-zero elements in 2nd matrix are: %d\n",count1);
               break;
        }

        case 2:
        {
             printf("The 1st Matrix:\n");
             display(m,rm,cm);
             printf("\nThe number of non-zero elements in 1st matrix are: %d\n",count);
             printf("\n");
             printf("The 2nd Matrix:\n");
             display(m1,r1,c1);
             printf("\nThe number of non-zero elements in 2nd matrix are: %d\n",count1);
             printf("\n");
             break;

        }

        case 3:
        {
             printf("\nConverted 1st matrix to  sparse matrix :\n");
             convert(m,rm,cm,s,count);
             printf("\n");
             rows=count+1;
             display(s,rows,3);

             printf("\nConverted 2nd matrix to  sparse matrix :\n");
             convert(m1,r1,c1,s1,count1);
             printf("\n");
             rows1=count1+1;
             display(s1,rows1,3);
             break;
        }

        case 4:
        {
             k=add_sparse(s,s1,add);
             if(k!=0)
             {
                 printf("\nThe Addition of the two matrices is :\n");
                 display(add,k,3);
             }
             else
                printf("\nAddition is not possible\n");
             break;
        }

        case 5:
        {
           transpose(s,ts);
           printf("\n1st matrix :\n");
           display(s,rows,3);
           printf("\nIts Transpose using simple transpose :\n");
           display(ts,rows,3);

           transpose(s1,ts1);
           printf("\n2nd matrix: \n");
           display(s1,rows1,3);
           printf("\nIts Transpose using simple transpose :\n");
           display(ts1,rows1,3);
           break;
        }

        case 6:
        {
            fast_transpose(s,fs);
            printf("\n1st matrix :\n");
            display(s,rows,3);
            printf("\nTranspose of the 1st matrix using fast transpose:\n");
            display(fs,rows,3);

            fast_transpose(s1,fs1);
            printf("\n2nd matrix: \n");
            display(s1,rows1,3);
            printf("\nTranspose of the 2nd matrix using fast transpose:\n");
            display(fs1,rows1,3);
            break;
        }
     }// end of switch case.
   }while(n!=7);// end of do.... while loop
}// end of main function.


// Function to Validate the number of rows and columns.
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
int accept(int m[][10],int rm,int cm)
{
  int i,j;
  int count=0;
  for(i=0;i<rm;i++)
  {
    printf("enter the elements of row:\n");
    for(j=0;j<cm;j++)
     {
       scanf("%d",&m[i][j]);
     }//end of j for loop
  }// end of i for loop
  for(i=0;i<rm;i++)
  {
    for(j=0;j<cm;j++)
     {
       if(m[i][j]!=0)
       {
         count=count+1;
       }
     }//end of j for loop
  }// end of i for loop
  return count;
}// end of accept function.


// Displaying the matrix.
void display(int m[][10],int rm,int cm)
{
int i,j;
  for(i=0;i<rm;i++)
  { printf("[");
    for(j=0;j<cm;j++)
     {
       printf("%d",m[i][j]);
       if(j<(cm-1))
       {
           printf("\t");
       }
     }
    printf("]");
    printf("\n");
  }
}


//Converts normal matrix to sparse matrix.
void convert(int m[][10],int rm,int cm,int s[][10],int count)// count is the number of non-zero elements.
{
  int i,j;
  int row=1;
  s[0][0]=rm;
  s[0][1]=cm;
  s[0][2]=count;
  for(i=0;i<rm;i++)
  {
    for(j=0;j<cm;j++)
    {
      if(m[i][j]!=0)
      {
        s[row][0]=i;
        s[row][1]=j;
        s[row][2]=m[i][j];
        row++;
      }// end of if
     }//end of j for loop
  }//end of i for loop
}


// Adding two matrices
int add_sparse(int s[][10],int s1[][10],int add[][10])
{
  int i=1,j=1,k=1;
  if( s[0][0] != s1[0][0] || s[0][1] != s1[0][1] )
    {
        return(0);
    }

  while(i<=s[0][2] && j<=s1[0][2])
  {
      if(s[i][0]<s1[j][0])
      {
            add[k][0] = s[i][0];
			add[k][1] = s[i][1];
			add[k][2] = s[i][2];
			k++;i++;
      }
      else if( s[i][0] > s1[j][0] )
		{
			add[k][0] = s1[j][0];
			add[k][1] = s1[j][1];
			add[k][2] = s1[j][2];
			k++;j++;
		}

      else if(s[i][0]==s1[j][0])
       {
           if(s[i][1]<s1[j][1])
                {
                   add[k][0]=s[i][0];
                   add[k][1]=s[i][1];
                   add[k][2]=s[i][2];
                   i++;
                   k++;
                }
            else if (s[i][1]>s1[j][1])
            {
              add[k][0]=s1[j][0];
              add[k][1]=s1[j][1];
              add[k][2]=s1[j][2];
              j++;
              k++;
            }
            else
            {
                add[k][0]=s[i][0];
                add[k][1]=s[i][1];
                add[k][2]=s[i][2]+s1[j][2];
                i++;
                j++;
                k++;
            }
       }  // end of row if

  }// end of while.
    while ( i <=s[0][2] )
	{
		add[k][0] = s[i][0];
		add[k][1] = s[i][1];
		add[k][2] = s[i][2];
		k++;i++;
	} //while

	while ( j <= s1[0][2] )
	{
		add[k][0] = s1[j][0];
		add[k][1] = s1[j][1];
		add[k][2] = s1[j][2];
		k++;j++;
	} // while

  add[0][0]=s[0][0];
  add[0][1]=s[0][1];
  add[0][2]=k-1;
  return k;
}


// Transpose of the matrix:
void transpose(int s[][10],int ts[][10])
{
    int i,j,k,n;
    ts[0][0]=s[0][1];
    ts[0][1]=s[0][0];
    ts[0][2]=s[0][2];

    k=1;
    n=s[0][2];

    for(i=0;i<s[0][1];i++)
        for(j=1;j<=n;j++)
            if(i==s[j][1])
            {
                ts[k][0]=i;
                ts[k][1]=s[j][0];
                ts[k][2]=s[j][2];
                k++;
            }
}


// Fast transpose
void fast_transpose(int s[][10],int fs[][10])
{
      int i,j,m,n,pos[3]={0,0,0},count[3]={0,0,0};
      for (i=1;i<=s[0][2];i++)
      {
         m = s[i][1];
         count[m]++;
      }
      pos[0] = 1;
      for (i=1;i<s[0][1];i++)
      {
         pos[i] = pos [i-1] + count[i-1];
      }
      for (i=1;i<=s[0][2];i++)
      {
          m = s[i][1];
          n= pos[m];
          pos[m]++;
          fs[n][0] = s[i][1];
          fs[n][1] = s[i][0];
          fs[n][2] = s[i][2];
      }
     fs[0][0] = s[0][0];
     fs[0][1] = s[0][1];
     fs[0][2] = s[0][2];
}


/*
OUTPUT:

********MENU**********
1.Accept The Matrix
2.Display The Matrix
3.Convert to Sparse Matrix
4.Addition of sparse matrices
5.Transpose of the Matrices
6.Fast Transpose
7.EXIT
1

enter the number of rows and columns of 1st the matrix respectively:
2
2
enter the elements:
enter the elements of row:
1
2
enter the elements of row:
3
0
the number of non-zero elements in 1st matrix are: 3

enter the number of rows and columns of the 2nd matrix respectively:
2
2
enter the elements:
enter the elements of row:
0
0
enter the elements of row:
1
0
the number of non-zero elements in 2nd matrix are: 1

********MENU**********
1.Accept The Matrix
2.Display The Matrix
3.Convert to Sparse Matrix
4.Addition of sparse matrices
5.Transpose of the Matrices
6.Fast Transpose
7.EXIT
2
The 1st Matrix:
[1      2]
[3      0]

The number of non-zero elements in 1st matrix are: 3

The 2nd Matrix:
[0      0]
[1      0]

The number of non-zero elements in 2nd matrix are: 1


********MENU**********
1.Accept The Matrix
2.Display The Matrix
3.Convert to Sparse Matrix
4.Addition of sparse matrices
5.Transpose of the Matrices
6.Fast Transpose
7.EXIT
3

Converted 1st matrix to  sparse matrix :

[2      2       3]
[0      0       1]
[0      1       2]
[1      0       3]

Converted 2nd matrix to  sparse matrix :

[2      2       1]
[1      0       1]

********MENU**********
1.Accept The Matrix
2.Display The Matrix
3.Convert to Sparse Matrix
4.Addition of sparse matrices
5.Transpose of the Matrices
6.Fast Transpose
7.EXIT
4

The Addition of the two matrices is :
[2      2       3]
[0      0       1]
[0      1       2]
[1      0       4]

********MENU**********
1.Accept The Matrix
2.Display The Matrix
3.Convert to Sparse Matrix
4.Addition of sparse matrices
5.Transpose of the Matrices
6.Fast Transpose
7.EXIT
5

1st matrix :
[2      2       3]
[0      0       1]
[0      1       2]
[1      0       3]

Its Transpose using simple transpose :
[2      2       3]
[0      0       1]
[0      1       3]
[1      0       2]

2nd matrix:
[2      2       1]
[1      0       1]

Its Transpose using simple transpose :
[2      2       1]
[0      1       1]

********MENU**********
1.Accept The Matrix
2.Display The Matrix
3.Convert to Sparse Matrix
4.Addition of sparse matrices
5.Transpose of the Matrices
6.Fast Transpose
7.EXIT
6

1st matrix :
[2      2       3]
[0      0       1]
[0      1       2]
[1      0       3]

Transpose of the 1st matrix using fast transpose:
[2      2       3]
[0      0       1]
[0      1       3]
[1      0       2]

2nd matrix:
[2      2       1]
[1      0       1]

Transpose of the 2nd matrix using fast transpose:
[2      2       1]
[0      1       1]

********MENU**********
1.Accept The Matrix
2.Display The Matrix
3.Convert to Sparse Matrix
4.Addition of sparse matrices
5.Transpose of the Matrices
6.Fast Transpose
7.EXIT
7

Process returned 7 (0x7)   execution time : 75.473 s
Press any key to continue.

*/
