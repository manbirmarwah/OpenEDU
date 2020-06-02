/* Program to create a singly linked list and perform the following operations on it
1)  Insert into the list
2)  Delete from the list
3)  Search for a data item into the list
The list stores data about the employees. Employee records are arranged into ascending order of employee no. Each employee record consists of the following fields.
1) Employee no.		4 digit positive integer.
2) Employee name		25 character string
3) Employee address	30 character string
4) Joining date			the 'date' format
*/

#include  <stdio.h>
#include  <conio.h>
#include  <stdlib.h>
#define  NULL  0

struct  date
{
  int  d , m , y ;
} ;

struct  node
{
  int  no ;
  char  name[25] ;
  char  add[30] ;
  struct  date  dt ;
  struct node  *next ;
} ;

struct node *first=NULL ;
/* first is a global variable and need not be passed to any function. Any changes made to variable first by any of the functions in the program will be reflected
in the entire program */

void  create()
{
  int  i , n ;
  struct  node  *pnode , *p , *follow ;

  printf("Enter the number of employees:\n") ;
  scanf("%d",&n) ;

  for(i=1 ; i<=n ; i++)
  {
    pnode=(struct node*)malloc(sizeof(struct node)) ;

    printf("Enter employee number, name, address and joining date of the employee: \n");
    scanf("%d %s %s %d %d %d", &pnode->no , pnode->name , pnode->add , &pnode->dt.d , &pnode->dt.m , &pnode->dt.y) ;

    /* searching the place of insertion */
    p=first;
    follow=NULL;
    while(p!=NULL)
    {
	  if(pnode->no<=p->no)
	    break ;
	  follow=p;
	  p=p->next;
    }
    /* p becomes NULL if new node is to be inserted after last node or during insertion of very first node */

    /* actual insertion */
    if(follow==NULL)     /* Insertion of very first node or insertion of node before existing first node */
    {
      pnode->next=first;
      first=pnode;
    }
    else  /* Insertion of node in middle or insertion of node after existing last node. */
    {
      follow->next=pnode;
      pnode->next=p;
    }
  }
}

void  deletenode(int  k)
{
  struct  node  *p , *follow ;

  /* searching the node to be deleted */
  p=first ;
  follow=NULL ;
  while(p!=NULL)
  {
	if(p->no==k)
	  break ;
    follow=p ;
    p=p->next ;
  }

  if(p==NULL)
     printf("Required employee not found.\n") ;
  else
  {
    /* actual deletion */
    if(p==first)   /* first node to be deleted */
      first=first->next ;
    else	   /* deleting any other node */
      follow->next=p->next ;

    free(p) ;  /* Memory De-allocation */
  }
}

void search(int  k)
{
  struct  node  *p ;

  p=first ;
  while(p!=NULL)
  {
	if(p->no==k)
	  break ;
	p=p->next ;
  }

  if(p==NULL)
     printf("Required employee not found. \n") ;
  else
  {
    printf("Required node is present. Its details are:\n") ;
    printf("%d %s %s %d %d %d \n",p->no , p->name , p->add , p->dt.d , p->dt.m , p->dt.y) ;
  }
}

void  traverse()
{
  struct  node  *p ;
  if(first==NULL)
    printf("Linked List Empty. No data to display. \n");
  else
  {
    p=first;
    while(p!=NULL)
    {
      printf("%d %s %s %d %d %d \n" , p->no , p->name , p->add , p->dt.d , p->dt.m , p->dt.y) ;
      p=p->next ;
    }
  }
}

void  main()
{
  int  k , ch ;
  clrscr() ;
  do
  {
    printf("\n Menu: \n") ;
    printf("1:Create \n") ;
    printf("2:Delete Node \n") ;
    printf("3:Search Node \n") ;
    printf("4:Traverse \n") ;
    printf("5:Exit \n") ;

    printf("\nEnter your choice: ") ;
    scanf("%d",&ch) ;

    switch(ch)
    {
      case 1:
      create() ;
      break ;

      case 2:
      printf("Enter employee number which is to be deleted: ") ;
      scanf("%d",&k) ;
      deletenode(k) ;
      break ;

      case 3:
      printf("Enter employee number which is to be searched: ") ;
      scanf("%d",&k) ;
      search(k) ;
      break ;

      case 4:
      traverse() ;
      break ;
    }
  }
  while(ch!=5) ;

  getch() ;
}








