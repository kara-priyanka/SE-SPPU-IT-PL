// Name: KARA PRIYANKA   Roll no.: 03    Batch: A1
// Menu driven accepting,displaying,finding intersection,union,difference and symmetry of two sets.
#include<stdio.h>
void accept(int [],int);// For accepting the sets.
void display(int [],int);// For displaying the sets.
int validate(int [],int);// Ensuring no repeating of the data in set.
int inter(int [],int,int[],int ,int[]);// elements present in common in both the sets.
int union1(int[],int,int[],int,int[]);// elements present in both the sets.
int differ(int[],int,int[],int,int[]);// A-B or B-A
int sym(int [],int,int [],int,int[]);//  symmetric difference = Union of two sets - Intersection of the set
void main()
{
  int r,n,f,a[10],b[10],c[10],n3,q,n4,y[10],n5,t[10],m;
  printf("enter number of array elements to be entered in 1st set:\n");
  scanf("%d",&n);
  printf("enter number of array elements to be entered in 2nd set:\n");
  scanf("%d",&m);
  do
  {
    printf("\n1.accept\n2.display\n3.intersection\n4.union\n5.difference\n6.symmetric difference\n7.exit\n");
    scanf("%d",&r);
    printf("\n");
    switch(r)
    {
      case 1:
      {
        printf("enter the values of 1st set:\n");
        accept(a,n);
        f=validate(a,n);
        while(f==0)
        {
          printf("enter another set:\n");
          accept(a,n);
          f=validate(a,n);
        };
        printf("enter the 2nd set:\n");
        accept(b,m);
        f=validate(b,m);
        while(f==0)
        {
          printf("enter another set:");
          accept(b,m);
          f=validate(b,m);
        };
        printf("\n");
        break;
      }
    case 2:
    {
        printf("set 1:");
        display(a,n);
        printf("\n");
        printf("set 2:");
        display(b,m);
        printf("\n");
        break;
    }
    case 3:
    {
        n3=inter(a,n,b,m,c);
        printf("intersection set:");
        display(c,n3);
        printf("\n");
        break;
    }
    case 4:
    {
        n3=union1(a,n,b,m,c);
        printf("union set:");
        display(c,n3);
        printf("\n");
        break;
    }
    case 5:
    {
       n3=differ(a,n,b,m,c);
       printf("\n Set 1- Set2=\n");
       display(c,n3);
       n4=differ(b,m,a,n,y);
       printf("\n Set2- Set1=\n");
       display(y,n4);
       printf("\n");
       break;
    }
    case 6:
    {
       n3=union1(a,n,b,m,c);
       n4=inter(a,n,b,m,y);
       n5=sym(c,n3,y,n4,t);
       printf("symmetric set:\t");
       display(t,n5);
       printf("\n");
       break;
    }
  }
 }while(r!=7);
  printf("Operations performed successfully!!\n");
}
// Function to accept data from user.
void accept(int p[],int n)
{
  int i;
  for(i=0;i<n;i++)
  scanf("%d",&p[i]);
}
// Function to display the data.
void display(int p[],int n)
{
  int i;
  printf("{");
  for (i=0;i<n;i++)
  {
    printf("%d",p[i]);
    if(i<(n-1))
    {
        printf(",");
    }
   }

    printf("}");
    printf("\n");
}
// Function to validate the elements of the set.
int validate(int b[],int n)
{
   int i,j;
   for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
     {
       if(b[i]==b[j]&&i!=j)
        {
          return 0;
        }
     }
   }
   return 1;
}
// Function to find intersection.
int inter(int a[],int n,int b[],int m,int c[])
{
  int i,j;
  int n3=0;
  for(i=0;i<n;i++)
     for(j=0;j<m;j++)
     {
       if (a[i]==b[j])
       {
         c[n3]=a[i];
         n3++;
       }
     }
  return n3;
}
// Function to find union.
int union1(int a[],int n,int b[],int m,int c[])
{
  int i,j,n3;
  for(i=0;i<n;i++)
  {
      c[i]=a[i];
      n3=n;
  }
  for(i=0;i<m;i++)
  {
      for(j=0;j<n3;j++)
      {
        if(b[i]==c[j])
        {
          break;
        }
      }
     if(j==n3)
     {
        c[n3]=b[i];
        n3++;
     }
  }
   return n3;
}
// Function to find difference between two sets.
int differ(int a[],int n,int b[],int m,int c[])
{
   int i,j;
   int n3=0;
   for(i=0;i<n;i++) //a=1,2,3  b=1,4,5
   {
     for(j=0;j<m;j++)
     {
      if(a[i]==b[j])
        {
          break;
        }
     }
   if(j==m)
    {
      c[n3]=a[i];
      n3++;//1
    }
   }
    return n3;
}
//Function to find symmetry .
int sym(int a[],int n,int b[],int k,int c[])
{
  int i,j;
  int n3=0;
  for(i=0;i<n;i++) //a=1,2,3  b=1,4,5
  {
    for(j=0;j<k;j++)
    {
      if(a[i]==b[j])
        {
          break;
        }
    }
    if(j==k)
    {
      c[n3]=a[i];
      n3++;//1
    }
  }
  return n3;
}
/*
OUTPUT:
[student@localhost ~]$ cd Downloads
[student@localhost Downloads]$ gcc A1.c
[student@localhost Downloads]$ ./a.out
enter number of array elements to be entered in 1st set:
3 
enter number of array elements to be entered in 2nd set:
4

1.accept
2.display
3.intersection
4.union
5.difference
6.symmetric difference
7.exit
1

enter the values of 1st set:
1
2
3
enter the 2nd set:
1
1
5
4
enter another set:1
2
5
6


1.accept
2.display
3.intersection
4.union
5.difference
6.symmetric difference
7.exit
2

set 1:{1,2,3}

set 2:{1,2,5,6}


1.accept
2.display
3.intersection
4.union
5.difference
6.symmetric difference
7.exit
3

intersection set:{1,2}


1.accept
2.display
3.intersection
4.union
5.difference
6.symmetric difference
7.exit
4

union set:{1,2,3,5,6}


1.accept
2.display
3.intersection
4.union
5.difference
6.symmetric difference
7.exit
5


 Set 1- Set2=
{3}

 Set2- Set1=
{5,6}


1.accept
2.display
3.intersection
4.union
5.difference
6.symmetric difference
7.exit
6

symmetric set:	{3,5,6}


1.accept
2.display
3.intersection
4.union
5.difference
6.symmetric difference
7.exit
7

Operations performed successfully!!
[student@localhost Downloads]$
*/
