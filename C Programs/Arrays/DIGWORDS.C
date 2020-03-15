/* String - Program to read a positive integer and print its digits in words. For example, if the input is 126 the o/p should be One Two Six */

#include  <stdio.h>
#include  <conio.h>

void main()
{
  char  n[20] ;	 
  int i;

  clrscr();

  printf("Enter a positive integer: ");
  gets(n);

  printf("%s in words: " , n);
  for(i=0 ; n[i]!='\0' ; i++)
  {
    switch(n[i])  
    {
      case '0': printf("Zero "); 		break;
      case '1': printf("One "); 		break;
      case '2': printf("Two "); 		break;
      case '3': printf("Three ");	break;
      case '4': printf("Four "); 		break;
      case '5': printf("Five "); 		break;
      case '6': printf("Six "); 		break;
      case '7': printf("Seven "); 	break;
      case '8': printf("Eight ");		break;
      case '9': printf("Nine "); 		break;
    }
  }

  getch();
}

/*
Output:

Enter a positive integer: 1760
1760 in words: One Seven Six Zero 
*/

