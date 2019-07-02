// Name: KARA PRIYANKA Roll no.: 03  Batch: A1
// Assignment 3: String Operations with pointers.
#include<stdio.h>
void display(char *);// Displays the String.
int length(char *);// Finds the length of the string.
void reverse(char *,int ,char *);// Reverses the string.
void palin(char *,int,char *);// Checks for palindrome.
int comp(char *,char *);//Compares two string.
void copy(char *,char *);// Copies the string.
void substring(char *);// Finds a string.
void concatenate(char *,char *,char *);// Joins the two string.
// Starting of the Main().
void main()
{
  char s[20],r[20];
  char rev[20],rev1[20],h[20],con[20];
  int len,len1;
  int n;
  printf("Enter the 1st string to be worked out :\n");
  scanf("%s",s);
  printf("Enter the 2nd string to be worked out:\n");
  scanf("%s",r);
  do// BEginning of do... while loop.
  {
    printf("\n1.Length of the string\n2.Check for pallindrome\n3.String comparision\n4.String Copy\n5.String Reverse\n6.Find Substring\n7.Concatenate the strings\n8.Display\n9.exit\n");
    scanf("%d",&n);
    switch(n)// Beginning of switch case.
    {
      case 1:
        {
          display(s);
          len=length(s);
          printf("\nThe length of the 1st string is %d\n",len);
          display(r);
          len1=length(r);
          printf("\nThe length of the 2nd string is %d\n",len1);
          break;
        }
      case 2:
        {
          int len=length(s);
          int len1=length(r);
          reverse(s,len,rev);
          printf("checked 1st string:\n");
          palin(s,len,rev);
          reverse(r,len1,rev1);
          printf("checked 2nd string:\n");
          palin(r,len1,rev1);
          break;
        }
      case 3:
        {
         int ch=compare(s,r);
         if(ch>0)
            printf("String 1 is greater\n");
		 else if(ch==0)
		    printf("Strings are equal\n");
		 else
		    printf("string 2 is greater\n");
         break;
        }
      case 4:
        {
          int e;
          do
          {
             printf("Choose the string to be Copied:\n1.String 1\n2.String 2\n3.None\n ");
             scanf("%d",&e);
             switch(e)
             {
               case 1:
                 printf("Enter the String to be copied:\n");
                 scanf("%s",h);
                 copy(s,h);
                 printf("Copied string is: %s\n",s);
                 break;
               case 2:
                 printf("Enter the String to be copied:\n");
                 scanf("%s",h);
                 copy(r,h);
                 printf("Copied String is: %s\n",r);
                 break;
             }
          }while(e!=3);
          break;
        }
      case 5:
        {
          len=length(s);
          len1=length(r);
          reverse(s,len,rev);
          display(rev);
          printf("\n");
          reverse(r,len1,rev1);
          display(rev1);
          printf("\n");
          break;
        }
      case 6:
        {
          int u;
          do
          {
            printf("\nSearch in \n1.String 1\n2.String 2\n3.EXIT\n");
            scanf("%d",&u);
            switch(u)
            {
               case 1:
                 substring(s);
                 break;
               case 2:
                 substring(r);
                 break;
            }// end of inner switch.
          }while(u!=3);// end of inner do...while loop.
          break;
        }// End of case 6
      case 7:
       {
         concatenate(s,r,con);
         printf("The Concatenated String is :\n%s\n",con);
         break;
       }
      case 8:
        {
            display(s);
            display(r);
            break;
        }
    }// END of switch case.
  }while(n!=9);// end of do...while loop.
}// end of Main().

// Display function.
void display(char *s)
{
  printf("\nthe entered string is %s\n",s);
}

// Length function.
int length(char *s)
{
  int l=0;
  while(*(s+l)!='\0')
    l++;
  return l;
}

//Reverse function.
void reverse(char *s,int len,char *m)
{
  int i,j;
  for(i=(len-1),j=0;i>=0;i--,j++)
  {
    *(m+j)=*(s+i);
  }
 *(m+j)='\0';
}

// Palindrome function.
void palin(char *s,int len,char *m)
{
  int i,l=0;
  for(i=0;i<len;i++)// len=3 i=1 I=2
   {
     if(*(s+i)==*(m+i))
     {
       l++;
     }
   }

   if(l==(len))
   printf("The string is a palindrome\n");
   else
   printf("It is not a palindrome\n");
}

//Comparison Function.
int compare(char *s,char *r)
{
	int c1,c2,d,i,l1,l2;
	l1=length(s);
	l2=length(r);
	if(l1==l2)
	{
		for(i=0;i<l1;i++)
		{
			c1=(int)*(s+i);
			c2=(int)*(r+i);
			d=c1-c2;
		 	if(d!=0)
		 	{
		 		return d;
		 	}
		}
		if(i==l1)
		return 0;
	}
	else if(l1>l2)
	return 1;
	else
	return -1;
}

// Copy function.
void copy(char *c,char *s)
{
  int i;
  int l=length(s);
  for(i=0;*(s+i)!='\0';i++)
  {
      *(c+i)=*(s+i);
  }
  *(c+i)='\0';
}

// Substring function.
void substring(char *str)
{
	int i,j,f,lsub,ls,cnt;
	char subs[20];
	hey:
	printf("Enter the sub-string to be found out:\n ");
	scanf("%s",subs);
	lsub=length(subs);
	ls=length(str);
	if(lsub<ls)
	{
		for(i=0;i<ls;i++)
		{
		    cnt=0;
			f=i;
			for(j=0;j<lsub;j++)
			{
				if(*(subs+j)==*(str+f))
				{
				    f++;
				    cnt++;
				}
				else
				break;
			}
			if((f-i)==(lsub))
			{
			printf("the string is present at %d\n",i);
			}
        }
     return;
	}
	else goto hey;
}

// Concatenation function.
void concatenate(char *s,char *r,char *con)
{
    int i,j;
    int l=length(s);
    int l1=length(r);
    for(i=0;i<l;i++)// K A R A
    {               // 0 1 2 3 =4=l
        *(con+i)=*(s+i);//K A R A " " l=5
    }               //0 1 2 3  4
    // total no. of terms in con=l+1
    for(j=0;j<l1;j++)
    {
        *(con+l+j)=*(r+j);
    }
    *(con+l+l1)='\0';
}
/*
OUTPUT:
Enter the 1st string to be worked out :
priyanka
Enter the 2nd string to be worked out:
kara

1.Length of the string
2.Check for pallindrome
3.String comparision
4.String Copy
5.String Reverse
6.Find Substring
7.Concatenate the strings
8.Display
9.exit
1

the entered string is priyanka

The length of the 1st string is 8

the entered string is kara

The length of the 2nd string is 4

1.Length of the string
2.Check for pallindrome
3.String comparision
4.String Copy
5.String Reverse
6.Find Substring
7.Concatenate the strings
8.Display
9.exit
2
checked 1st string:
It is not a palindrome
checked 2nd string:
It is not a palindrome

1.Length of the string
2.Check for pallindrome
3.String comparision
4.String Copy
5.String Reverse
6.Find Substring
7.Concatenate the strings
8.Display
9.exit
3
String 1 is greater

1.Length of the string
2.Check for pallindrome
3.String comparision
4.String Copy
5.String Reverse
6.Find Substring
7.Concatenate the strings
8.Display
9.exit
4
Choose the string to be Copied:
1.String 1
2.String 2
3.None
 1
Enter the String to be copied:
kara
Copied string is: kara
Choose the string to be Copied:
1.String 1
2.String 2
3.None
 2
Enter the String to be copied:
priyanka
Copied String is: priyanka
Choose the string to be Copied:
1.String 1
2.String 2
3.None
 3

1.Length of the string
2.Check for pallindrome
3.String comparision
4.String Copy
5.String Reverse
6.Find Substring
7.Concatenate the strings
8.Display
9.exit
8

the entered string is kara

the entered string is priyanka

1.Length of the string
2.Check for pallindrome
3.String comparision
4.String Copy
5.String Reverse
6.Find Substring
7.Concatenate the strings
8.Display
9.exit
5

the entered string is arak


the entered string is aknayirp


1.Length of the string
2.Check for pallindrome
3.String comparision
4.String Copy
5.String Reverse
6.Find Substring
7.Concatenate the strings
8.Display
9.exit
6

Search in
1.String 1
2.String 2
3.EXIT
1
Enter the sub-string to be found out:
 yan

Search in
1.String 1
2.String 2
3.EXIT
1
Enter the sub-string to be found out:
 ar
the string is present at 1

Search in
1.String 1
2.String 2
3.EXIT
2
Enter the sub-string to be found out:
 yan
the string is present at 3

Search in
1.String 1
2.String 2
3.EXIT
3

1.Length of the string
2.Check for pallindrome
3.String comparision
4.String Copy
5.String Reverse
6.Find Substring
7.Concatenate the strings
8.Display
9.exit
7
The Concatenated String is :
karapriyanka

1.Length of the string
2.Check for pallindrome
3.String comparision
4.String Copy
5.String Reverse
6.Find Substring
7.Concatenate the strings
8.Display
9.exit
8

the entered string is kara

the entered string is priyanka

1.Length of the string
2.Check for pallindrome
3.String comparision
4.String Copy
5.String Reverse
6.Find Substring
7.Concatenate the strings
8.Display
9.exit
9

Process returned 9 (0x9)   execution time : 99.132 s
Press any key to continue.


*/
