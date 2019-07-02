//Name: KARA PRIYANKA     Roll no: 03   Batch: A1
// Assignment 7: Merge Sort.
#include<stdio.h>
void accept(int [20],int );
void display(int [20],int );
void merge_sort_rec(int [20],int ,int );
void merge(int [20],int ,int ,int ,int );
void merge_sort(int [20],int );
void main()
{
	int s[20];
	int ch,i,n;
	do
	{
	printf("\n*********MENU***********\n1.Accept\n2.Display\n3.Merge Sort Recursively\n4.Merge Sort Non-Recursively\n5.Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		{
			printf("Enter total no of elements:\n");
			scanf("%d",&n);
			printf("Enter an array of integers:\n");
			accept(s,n);
			break;
		}
		case 2:
		{
			display(s,n);
			break;
		}

		case 3:
		{
			merge_sort_rec(s,0,n-1);
			display(s,n);
		        break;
		}
		case 4:
		{
			merge_sort(s,n);
			display(s,n);
			break;
		}
	}
    }while(ch!=5);
}

// Accepts the elements.
void accept(int s[20],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
}

// Displays the Elements.
void display(int s[20],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d \t",s[i]);
	}
	printf("\n");
}

// Merge sort Recursive.
void merge_sort_rec(int s[20],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid= (low+high)/2;
		merge_sort_rec(s,low,mid);
		merge_sort_rec(s,mid+1,high);
		merge(s,low,mid,mid+1,high);
	}
}

// Merges two Sorted arrays with sorting them.
void merge(int s[20],int l1,int u1,int l2,int u2)
{
	int temp[20],i,j,k=0;
	i=l1;
	j=l2;
	while(i<=u1 && j<=u2)
	{
		if(s[i]<s[j])
		{
			temp[k]=s[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=s[j];
			k++;
			j++;
		}
	}
	while(i<=u1)
	{
		temp[k]=s[i];
		k++;
		i++;
	}
	while(j<=u2)
	{
		temp[k++]=s[j++];
	}
	for(i=0,j=l1;j<=u2;i++,j++)
	{
		s[j]=temp[i];
	}

}

void merge_sort(int s[20],int n)
{
	int size,i,j,k,u1,u2,l1,l2,temp[20];
	for(size=1;size<n;size=2*size)
	{
		l1=0;
		while(l1+size<n)
		{
			u1=l1+size-1;
			l2=u1+1;
			u2=l2+size-1;

			if(u2>=n)
			{
				u2=n-1;
			}
			merge(s,l1,u1,l2,u2);
			l1=u2+1;
		}
	}
}

/*
OUTPUT:


*********MENU***********
1.Accept
2.Display
3.Merge Sort Recursively
4.Merge Sort Non-Recursively
5.Exit
1
Enter total no of elements:
6
Enter an array of integers:
3
2
-6
7
4
9

*********MENU***********
1.Accept
2.Display
3.Merge Sort Recursively
4.Merge Sort Non-Recursively
5.Exit
2
3       2       -6      7       4       9

*********MENU***********
1.Accept
2.Display
3.Merge Sort Recursively
4.Merge Sort Non-Recursively
5.Exit
3
-6      2       3       4       7       9

*********MENU***********
1.Accept
2.Display
3.Merge Sort Recursively
4.Merge Sort Non-Recursively
5.Exit
4
-6      2       3       4       7       9

*********MENU***********
1.Accept
2.Display
3.Merge Sort Recursively
4.Merge Sort Non-Recursively
5.Exit
1
Enter total no of elements:
6
Enter an array of integers:
5
2
-1
6
3
8

*********MENU***********
1.Accept
2.Display
3.Merge Sort Recursively
4.Merge Sort Non-Recursively
5.Exit
2
5       2       -1      6       3       8

*********MENU***********
1.Accept
2.Display
3.Merge Sort Recursively
4.Merge Sort Non-Recursively
5.Exit
4
-1      2       3       5       6       8

*********MENU***********
1.Accept
2.Display
3.Merge Sort Recursively
4.Merge Sort Non-Recursively
5.Exit
5

Process returned 5 (0x5)   execution time : 50.814 s
Press any key to continue.





*/
