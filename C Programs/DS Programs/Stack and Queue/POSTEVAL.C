/* Postfix Evaluation -  Program to evaluate a given postfix expression */

/* We asume that the operators are + , - , * , / , $ and operands are digits */

#include  <stdio.h>
#include  <conio.h>
#include  <math.h>

#define  STACKSIZE  50

struct  stack
{
  int  top ;
  float  items[STACKSIZE] ; 
} ;


float  evaluate(char  e[ ]) ;
int  isoperand(char  c) ;
float  oper(char  c , float  op1 , float  op2) ;
int  empty(struct  stack  *ps) ;
float  pop(struct  stack  *ps) ;
void  push(struct  stack  *ps , float  x) ;

void main()
{
  char  e[50] ;
  clrscr() ;
  printf("Enter the expression in postfix form:\n") ;
  gets(e) ;
  printf("Value of the expression is: %f",evaluate(e)) ;
  getch() ;
}

/* This function will evaluate the given postfix expression */
float  evaluate(char  e[ ])
{
  int  i ;
  float  op1 , op2 , value , x ;

  struct  stack  s ;
  s.top=-1 ;
  /* Previous 2 statements likely to be forgotten */

  for(i=0 ; e[i]!='\0' ; i++)
    if(isoperand(e[i]))
    {
	/* converting a character to a number */
      x=e[i]-'0' ;     
      /* Eg. '2' - '0' = 50-48 = 2 */
      push(&s,x) ;       
    }
    else
    {
      op2=pop(&s) ;
      op1=pop(&s) ;
      value=oper(e[i],op1,op2) ;
      push(&s,value) ;
    }

  return (pop(&s)) ;
}

/* This function will return true if the given character is an operand */
int  isoperand(char  c)
{
  if(c>='0'&&c<='9')
    return  1 ;
  else
    return  0 ;
}

/* This function will apply the operator c to operands op1 and op2 and will return the result */
float  oper(char  c , float  op1 , float  op2)
{
  switch(c)
  {
    case '+': return (op1+op2) ;  /* break not reqd ? */
    case '-': return (op1-op2) ;
    case '*': return (op1*op2) ;
    case '/': return (op1/op2) ;
    case '$': return (pow(op1,op2)) ;
    default:printf("\nIllegal Operation.") ;
	          getch() ;
	          exit(1) ;
  }
}

void  push(struct  stack  *ps , float  x)
{
  if(ps->top==STACKSIZE-1)
  {
    printf("Stack Overflow. Cannot push \n") ;
    getch() ;
    exit(1) ; /* terminates program */
  }
  ps->items[++(ps->top)]=x ;
}

int  empty(struct  stack  *ps)
{
  if(ps->top==-1)
    return  1 ;
  else
    return  0 ;
}

float  pop(struct  stack  *ps)
{
  if(empty(ps))
  {
    printf("Stack Underflow. Cannot pop \n") ;
    getch() ;
    exit(1) ;
  }
  return (ps->items[(ps->top)--]) ;
}

/*
Limitations of this program are:
1) It does not check for the validity of postfix expression.
2) It allows only digits to be operands.
*/





