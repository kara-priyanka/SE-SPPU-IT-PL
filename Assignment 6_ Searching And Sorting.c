//Name: KARA PRIYANKA     Roll no.: 03     Batch: A1
// Assignment 6: Searching and Sorting
#include<stdio.h>
#include<string.h>
void accept(char [][10],int);
void display(char [][10],int);
void bubblesort(char [][10],int);
void selectionsort(char [][10],int);
void insertionsort(char [][10],int);
int binary_search_rec(char [][10],int,int,char [10]);
void binary_search_nonrec(char [][10],int,int,char [10]);
void main()
{
  int q,n,y;
  char s[10][10],m[10][10],bin[10];// S[i][j]= i= rows i.e the  number of strings to be present.
  //j= columns that is the maximum size of the string that could be written in the row.
  do
  {
     printf("\n\n*******MENU*******\n1.Accept\n2.Display\n3.Bubble Sort\n4.Selection Sort\n5.Insertion Sort\n6.Binary Search Recursive\n7.Binary Search Non-Recursive\n8.EXIT\n");
     scanf("%d",&n);
     switch(n)
     {
        case 1:
            {
               printf("Enter number of strings to be entered:\n");
               scanf("%d",&q);
               accept(s,q);
               break;
            }
        case 2:
            {
               display(s,q);
               break;
            }
        case 3:
            {
               bubblesort(s,q);
               printf("\nBubble Sorted strings:\n");
               display(s,q);
               break;
            }
        case 4:
            {
              selectionsort(s,q);
              printf("\nSelection Sorted strings:\n");
              display(s,q);
              break;
            }
        case 5:
            {
               insertionsort(s,q);
               printf("\nInsertion Sorted strings:\n");
               display(s,q);
               break;
            }
        case 6:
            {
                printf("\nEnter the String to be searched:\n");
                scanf("%s",bin);
                bubblesort(s,q);// Arranged in ascending order.
                printf("\nSorted strings:\n");
                display(s,q);
                y=binary_search_rec(s,0,(q-1),bin);
                if(y==-1)
                   printf("\nThe string is not present\n");
                else
                   printf("\nElement is present at index %d\n", y+1);
                break;
            }
        case 7:
            {
                printf("\nEnter the String to be searched:\n");
                scanf("%s",bin);
                bubblesort(s,q);// Arranged in ascending order.
                printf("\nSorted strings:\n");
                display(s,q);
                binary_search_nonrec(s,0,(q-1),bin);
                break;
            }
    }
  }while(n!=8);
}
// Accepts the strings.
void accept(char s[][10],int q)
{
  int i;
  for(i=0;i<q;i++)
  {
    printf("Enter the string:\n");
    scanf("%s",s[i]);
  }
}
// Displays the strings.
void display(char s[][10],int q)
{
  int i,j;
  for(i=0;i<q;i++)
  {
    printf("\nthe string: %s\n",s[i]);
  }
}
// Bubble sort of the strings.
void bubblesort(char s[][10],int q)
{
  int i,j;
  char temp[10];
  for(i=0;i<(q);i++)// s[0]=kara   s[1]=priyanka  s[2]=hello  q=3
  {
    for(j=0;j<(q-1);j++)//j=0   s[0]=kara
    {
      if(strcmp(s[j],s[j+1])>0)
         {
            strcpy(temp,s[j]);// Compared according to the ASCII value.
            strcpy(s[j],s[j+1]);
            strcpy(s[j+1],temp);
         }// End of if.
     }// End of j for.
  }// end of i for
}
// Selection sort .
void selectionsort(char s[][10],int q) // Arranges in Descending order.
{
  int i,j,ps;
  char max[10],temp[10];
  for(i=0;i<q;i++)
  {
    strcpy(max,s[i]);
    for(j=i+1;j<q;j++)
    {
       if(strcmp(s[j],max)>0)
       {
          strcpy(max,s[j]);
          ps=j;
          strcpy(temp,s[i]);// Compared according to the ASCII value.// h k p
          strcpy(s[i],s[ps]);
          strcpy(s[ps],temp);
       }// End of if.
    }// end of j for loop.
   }// End of i for loop.
}
// Insertion Sort.
void insertionsort(char s[][10],int n)
{
    int k,i;
    char y[10];
    for(k=0;k<n;k++)
    {
        strcpy(y,s[k]);
        for(i=k-1;i>=0&&(strcmp(y,s[i])>0);i--)
        {
            strcpy(s[i+1],s[i]);
            strcpy(s[i],y);
        }
    }
}
// Recursive Binary Search.
int binary_search_rec(char s[][10],int l,int r,char key[10])
{
  if (r >= l)
   {
        int mid = (l+r)/2;

        // If the element is present at the middle itself
        if (strcmp(s[mid],key)==0) return mid;

        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (strcmp(s[mid],key)>0) return binary_search_rec(s, l, mid-1, key);
        if(strcmp(key,s[mid])>0)        // Else the element can only be present in right subarray
        return binary_search_rec(s, mid+1, r, key);
   }
   return -1;// We reach here when element is not present in array
}
// Non-Recursive Binary Search.
void binary_search_nonrec(char s[][10],int l,int r,char key[10])
{
  int flag=0;
  while(r>=l)
  {
      int mid=(l+r)/2;
      if(strcmp(s[mid],key)==0)
        {
         printf("\nThe string is present at %d\n",mid+1);
         flag=1;
         break;
        }
      else if(strcmp(key,s[mid])>0)
        l=mid+1;
      else
        r=mid-1;
  }// End of while loop
  if(flag==0)
    printf("\nString not present\n");
}


/*
OUTPUT:
[student@localhost Documents]$ gcc a5.c
[student@localhost Documents]$ ./a.out


*******MENU*******
1.Accept
2.Display
3.Bubble Sort
4.Selection Sort
5.Insertion Sort
6.Binary Search Recursive
7.Binary Search Non-Recursive
8.EXIT
1
Enter number of strings to be entered:
3
Enter the string:
k
Enter the string:
a
Enter the string:
p


*******MENU*******
1.Accept
2.Display
3.Bubble Sort
4.Selection Sort
5.Insertion Sort
6.Binary Search Recursive
7.Binary Search Non-Recursive
8.EXIT
2

the string: k

the string: a

the string: p


*******MENU*******
1.Accept
2.Display
3.Bubble Sort
4.Selection Sort
5.Insertion Sort
6.Binary Search Recursive
7.Binary Search Non-Recursive
8.EXIT
3

Bubble Sorted strings:

the string: a

the string: k

the string: p


*******MENU*******
1.Accept
2.Display
3.Bubble Sort
4.Selection Sort
5.Insertion Sort
6.Binary Search Recursive
7.Binary Search Non-Recursive
8.EXIT
4

Selection Sorted strings:

the string: p

the string: k

the string: a


*******MENU*******
1.Accept
2.Display
3.Bubble Sort
4.Selection Sort
5.Insertion Sort
6.Binary Search Recursive
7.Binary Search Non-Recursive
8.EXIT
5

Insertion Sorted strings:

the string: p

the string: k

the string: a


*******MENU*******
1.Accept
2.Display
3.Bubble Sort
4.Selection Sort
5.Insertion Sort
6.Binary Search Recursive
7.Binary Search Non-Recursive
8.EXIT
6

Enter the String to be searched:
e

Sorted strings:

the string: a

the string: k

the string: p

The string is not present


*******MENU*******
1.Accept
2.Display
3.Bubble Sort
4.Selection Sort
5.Insertion Sort
6.Binary Search Recursive
7.Binary Search Non-Recursive
8.EXIT
6

Enter the String to be searched:
p

Sorted strings:

the string: a

the string: k

the string: p

Element is present at index 3


*******MENU*******
1.Accept
2.Display
3.Bubble Sort
4.Selection Sort
5.Insertion Sort
6.Binary Search Recursive
7.Binary Search Non-Recursive
8.EXIT
7

Enter the String to be searched:
e

Sorted strings:

the string: a

the string: k

the string: p

String not present


*******MENU*******
1.Accept
2.Display
3.Bubble Sort
4.Selection Sort
5.Insertion Sort
6.Binary Search Recursive
7.Binary Search Non-Recursive
8.EXIT
7

Enter the String to be searched:
k

Sorted strings:

the string: a

the string: k

the string: p

The string is present at 2


*******MENU*******
1.Accept
2.Display
3.Bubble Sort
4.Selection Sort
5.Insertion Sort
6.Binary Search Recursive
7.Binary Search Non-Recursive
8.EXIT
8
[student@localhost Documents]$ 



*/
