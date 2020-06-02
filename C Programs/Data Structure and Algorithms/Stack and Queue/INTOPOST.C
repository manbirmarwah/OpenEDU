/* Postfix Infix -  Program to convert given infix expression to postfix expression*/

/* We assume that the operators are + , - , * , / , $ and operands are digits or alphabets */

#include  <stdio.h>
#include  <conio.h>
#define  STACKSIZE  50

struct  stack
{
  int  top ;
  char  items[STACKSIZE] ;  
} ;

void  postfix(char  ie[ ] , char  oe[ ]) ;
int  isoperand(char  c) ;
int  prcd(char  st , char  cs) ;
int  empty(struct  stack  *ps) ;
char  pop(struct  stack  *ps) ;
void  push(struct  stack  *ps , char  x) ;
char  stacktop(struct  stack  s) ;

void  main()
{
  char  ie[50] , oe[50] ;
  clrscr() ;
  printf("Enter the expression in infix form:\n") ;
  gets(ie) ;
  postfix(ie,oe) ;
  printf("Equivqlent postfix expression is:\n%s",oe) ;
  getch() ;
}

/* This function will store the resultant postfix expression in oe */
/* ie - input expression , oe- output expression */
void  postfix(char  ie[ ] , char  oe[ ])
{
  int  i , j ;
  char  ts , cs ;

  struct  stack  s ;
  s.top=-1 ;

  j=0;
  for(i=0 ; (cs=ie[i])!='\0' ; i++)
    if(isoperand(cs))
      oe[j++]=cs ;
    else
    {
        while( !empty(&s) && prcd(stacktop(s),cs) )
        {
	    ts=pop(&s) ;
	    oe[j++]=ts ;
        }

        if(empty(&s)||cs!=')')
	     push(&s,cs) ;
        else
	     ts=pop(&s) ;
    }

  while(!empty(&s))
  {
    ts=pop(&s) ;
    oe[j++]=ts ;
  }

  oe[j]='\0' ;
}

/* This function will return true if the given character is an operand */
int  isoperand(char  c)
{
  if(c>='A'&&c<='Z'||c>='a'&&c<='z'||c>='0'&&c<='9')
    return  1 ;
  else
    return  0 ;
}

/*
prcd(st,cs) is a function which returns true
1) if st has higher precedence than cs
2) if precedence is same the assosiativity is considered
   Hence prcd(*,+)=1 , prcd(+,+)=prcd(+,-)=...=1
	     prcd(+,*)=0   prcd($,$) = 0
*/

int  prcd(char  st , char  cs)
{
  switch(st)
  {
    case '+':
    case '-':
    if(cs=='+'||cs=='-'||cs==')')  return  1 ;
    if(cs=='*'||cs=='/'||cs=='$'||cs=='(')  return  0 ;

    case '*':
    case '/':
    if(cs=='+'||cs=='-'||cs=='*'||cs=='/'||cs==')')  return  1 ;
    if(cs=='$'||cs=='(')  return  0 ;

    case '$':
    if(cs=='+'||cs=='-'||cs=='*'||cs=='/'||cs==')')  return  1 ;
    if(cs=='$'||cs=='(')  return  0 ;

    case '(':
    return  0 ;

    default:printf("\nIllegal Operation.") ;
	          getch() ;
	          exit(1) ;
  }
}

int  empty(struct  stack  *ps)
{
  if(ps->top==-1)
    return  1 ;
  else
    return  0 ;
}

char  pop(struct  stack  *ps)
{
  return  (ps->items[(ps->top)--]) ;
}

char  stacktop(struct  stack  s)
{
  return  (s.items[s.top]) ;
}

void  push(struct  stack  *ps , char  x)
{
  if(ps->top==STACKSIZE-1)
  {
    printf("Stack Overflow. Cannot push \n") ;
    getch() ;
    exit(1) ;
  }
  ps->items[++(ps->top)]=x ;
}

/*
Limitations of this program are:
1) It does not check the validity  of the infix expression
2) It allows only digits and alphabets to be operands.

Note:
The stacktop() and pop() functions need not have provision for checking whether the stack is empty since postfix() takes care of this before calling them.
*/




