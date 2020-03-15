/* Palindrome Number - Write a function to check whether a given number is a palindrome or not  , for example 1234321 */

#include  <stdio.h>
#include  <conio.h>

int  palindrome(int  n)
{
  int  r , rev=0 , temp ;

  temp=n ;
  while(n!=0)
  {
    r=n%10 ;
    rev=rev*10+r ;
    n=n/10 ;
  }

  if(rev==temp)
     return  1 ;
  else
     return  0 ;
}

void main()
{
  int  n , flag ;

  clrscr() ;
  printf("Enter a number: ") ;
  scanf("%d" , &n) ;
  flag=palindrome(n) ;
  if(flag==1)
    printf("%d is a palindrome" , n) ;
  else
    printf("%d is not a palindrome" , n) ;
  getch() ;
}

/*
Output1:

Enter a number: 24542
24542 is a palindrome

Output2:

Enter a number: 2464
2464 is not a palindrome
*/

