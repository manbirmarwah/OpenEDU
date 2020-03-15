/* Calculator - Write a complete C program to simulate the 4 - function calculator. The functions are +,-,*,/ and Q to quit. The program must be menu driven*/

#include  <stdio.h>
#include  <conio.h>

void  addition(float  a , float  b);
void  subtraction(float  a , float  b);
void  multiplication(float  a , float  b);
void  division(float  a , float  b);

void main()
{
  char  choice ;
  float  a ,b ;

  clrscr() ;

  do
  {
    printf("\n   Menu: \n") ;
    printf("+ : Addition \n") ; 
    printf("- : Subtraction \n") ;
    printf("* : Multiplication \n") ;
    printf("/ : Division \n") ;
    printf("Q : Quit \n") ;
    printf("Enter your choice: ") ;
    scanf(" %c" , &choice) ;

    if(choice=='+' || choice=='-' || choice=='*' || choice=='/')
    {
      printf("Enter 2 numbers: ") ;
      scanf("%f %f" , &a , &b); 
    }

    switch(choice)
    {
      case  '+' :  addition(a,b);   break;
      case  '-' :   subtraction(a,b);   break;
      case  '*' :  multiplication(a,b);   break;
      case  '/' :  division(a,b);   break;
      case 'q' : break;
      case 'Q' : break;  
      default : printf("Invalid Choice. Enter again.\n");
    }   
  }
  while(choice!='q' && choice!='Q');

  getch() ;
}

void  addition(float  a , float  b)
{
   printf("Sum of two numbers is: %f \n" , a+b) ;
}

void  subtraction(float  a , float  b)
{
   printf("Diffrence of two numbers is: %f \n" , a-b) ;
}

void  multiplication(float  a , float  b)
{
   printf("Product of two numbers is: %f \n" , a*b) ;
}

void  division(float  a , float  b)
{
   printf("Result of division is: %f \n" , a/b) ;
}


/*
Output:

   Menu: 
+ : Addition 
- : Subtraction 
* : Multiplication 
/ : Division 
Q : Quit 
Enter your choice: +
Enter 2 numbers: 2 5
Sum of two numbers is: 7.000000 

   Menu: 
+ : Addition 
- : Subtraction 
* : Multiplication 
/ : Division 
Q : Quit 
Enter your choice: -
Enter 2 numbers: 2 5
Diffrence of two numbers is: -3.000000 

   Menu: 
+ : Addition 
- : Subtraction 
* : Multiplication 
/ : Division 
Q : Quit 
Enter your choice: *
Enter 2 numbers: 2 5
Product of two numbers is: 10.000000 

   Menu: 
+ : Addition 
- : Subtraction 
* : Multiplication 
/ : Division 
Q : Quit 
Enter your choice: /
Enter 2 numbers: 2 5
Result of division is: 0.400000 

   Menu: 
+ : Addition 
- : Subtraction 
* : Multiplication 
/ : Division 
Q : Quit 
Enter your choice: %
Invalid Choice. Enter again.

   Menu: 
+ : Addition 
- : Subtraction 
* : Multiplication 
/ : Division 
Q : Quit 
Enter your choice: Q
*/