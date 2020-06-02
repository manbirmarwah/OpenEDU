/* Singly Linked List (Basic Operations) - Program to create a linked list abstract data type and perform various operations on it (Variable first declared globally) */

#include  <stdio.h>
#include <conio.h>
#include  <stdlib.h>
#define  NULL 0

/* Assume that the data portion of each node consists of ONLY an integer.*/
struct  node
{
  int  data ;
  struct  node  *next ;
} ;

struct  node  *first=NULL ;

/* first is a global variable and need not be passed to any function. Any changes made to variable first by any of the functions in the program will be permanent and will be reflected in the entire program */

/* This function is responsible for creating the Linked List right from the BEGINING. */
void  create()
{
  int  i , n ;
  struct  node  *pnode , *p ;

  printf("Enter the number of nodes required:\n") ;
  scanf("%d",&n) ;

  printf("Enter the data value of each node:\n") ;
  for(i=1 ; i<=n ; i++)
  {
    pnode=(struct node*)malloc(sizeof(struct node)) ;

    if(pnode==NULL)
    {
      printf("Memory overflow. Unable to create.\n") ;
      return ;
    }

    scanf("%d",&pnode->data) ;

    /* New node will be the last node */
    pnode->next=NULL ;  

    if(first==NULL)
    	 first=p=pnode ;
    else
    {
	    p->next=pnode ;
	    p=pnode ;   /* p keeps track of last node */
    }
  }
}


/* This function will insert a new node with value x after a node with value K in an already existing Linked List */
void  insertafter(int  x , int  k)
{
  struct  node  *pnode , *p ;
  pnode=(struct node*)malloc(sizeof(struct node)) ;

  if(pnode==NULL)
  {
    printf("Memory overflow. Unable to create.\n") ;
    return ;
  }

  /* searching the required node */
  p=first ;
  while(p!=NULL)
  {
	if(p->data==k)
	  break ;
    p=p->next ;  }

  /* p becomes NULL when required data is not found */
  if(p==NULL)
     printf("Required node not found.\n") ;
  else
  {
    pnode->data=x ;

    /* actual insertion */
    pnode->next=p->next ;
    p->next=pnode ;
  }
}

/* This function will insert a new node with value x before a node with value K in an already existing Linked List */
void  insertbefore(int  x , int  k)
{
  struct  node  *pnode , *p , *follow ;

  pnode=(struct node*)malloc(sizeof(struct node)) ;
  if(pnode==NULL)
  {
    printf("Memory overflow. Unable to create.\n") ;
    return ;
  }

  /* searching the required node */
  p=first ;
  follow=NULL ;
  while(p!=NULL)
  {
	if(p->data==k)
	  break ;
    follow=p ;
    p=p->next ;
  }

  if(p==NULL)
    printf("Required node not found.\n") ;
  else
  {
    pnode->data=x ;

    /* actual insertion */

    if(p==first) /* inserting before the first node */
    {
      pnode->next=first ;
      first=pnode ;
    }
    else          /* inserting before any other node */
    {
      follow->next=pnode ;
      pnode->next=p ;
    }
  }
}

/* This function will insert a new node with value x at the begining of Linked List */
void  insertbegining(int  x)
{
  struct  node  *pnode , *p ;
  pnode=(struct node*)malloc(sizeof(struct node)) ;

  if(pnode==NULL)
  {
    printf("Memory overflow. Unable to create.\n") ;
    return ;
  }

  pnode->data=x ;

  pnode->next=first ;
  first=pnode ;
  /* The above two statements will work even if the linked list is empty i.e. first=NULL */
}

/* This function will insert a new node with value x at the end of EXISTING Linked List */
void  insertend(int  x)
{
  struct  node  *pnode , *p , *follow ;
  pnode=(struct node*)malloc(sizeof(struct node)) ;

  if(pnode==NULL)
  {
    printf("Memory overflow. Unable to create.\n") ;
    return ;
  }

  pnode->data=x ;
  
  /* Locating the last node */
  p=first ;
  follow=NULL ;
  while(p!=NULL)
  {
    follow=p ;
    p=p->next ;
  }
  /* When the loop stops, follow is at the last node */

  follow->next=pnode ;
  pnode->next=NULL ; /* pnode is now the last node */
}

/* This function will insert a new node with value x at a particular position in a Linked List */
void  insertposition(int  x , int  k)
{
  int  i ;
  struct  node  *pnode , *p ;

  pnode=(struct node*)malloc(sizeof(struct node)) ;
  if(pnode==NULL)
  {
    printf("Memory overflow. Unable to create.\n") ;
    return ;
  }

  pnode->data=x ;

  if(k==1)
  {
    pnode->next=first ;
    first=pnode ;
  }
  else
  {      
    /* searching the required position */
    p=first ;
    i=1 ;
    while(i!=k-1&&p!=NULL)
    {
      p=p->next ;
      i++ ;
    }  
  
    if(p==NULL)
      printf("Required position exceeds the length of linked list.\n") ;
    else
    {
      /* actual insertion */
      pnode->next=p->next ;
      p->next=pnode ;
    }
  }
}


/* This function will delete a node with value k from the Linked List if such a node exists */
void  deletenode(int  k)
{
  struct  node  *p , *follow ;

  /* searching the node to be deleted */
  p=first ;
  follow=NULL ;
  while(p!=NULL)
  {
	if(p->data==k)
	  break ;  
    follow=p ;
    p=p->next ;
  }

  if(p==NULL)
     printf("Required node not found.\n") ;
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

/* This function will search a node with value k in the Linked List */
void  search(int  k)
{
  struct  node  *p ;

  p=first ;
  while(p!=NULL)
  {
	if(p->data==k)
	  break ;
  	p=p->next ;  }

  if(p==NULL)
     printf("Required node not found.\n") ;
  else
    printf("Required node is present at address %X \n",p) ;
}

/* This function go through all the nodes of Linked List exactly once and will display data value of each node */
void  traverse()
{
  struct  node  *p ;
  if(first==NULL)
    printf("Linked List Empty") ;
  else
  {
    printf("Linked List is as shown: \n") ;

    p=first ;
    while(p!=NULL)
    {
      printf("%d ",p->data) ;
      p=p->next ;
    }
    printf("\n") ;
  }
}

/* This function will count the number nodes in Linked List */
void count()
{
  int  n=0 ;
  struct  node  *p ;

  p=first ;
  while(p!=NULL)
  {
    n++ ;
    p=p->next ;
  }

  printf("Number of nodes in Linked List is %d \n",n) ;
}

/* This function will reverse a given linked list without using additional memory allocation */
void  reverse()
{
  struct  node  *p , *follow , *ahead ;

  p=first ;
  follow=ahead=NULL ;
  while(p!=NULL)
  {
    ahead=p->next ;
    p->next=follow ;
    follow=p ;
    p=ahead ;
  }
  first=follow ;
}

/* This function will make the Linked List empty. */
void  destroylist()
{
  first=NULL ;
}

void  main()
{
  int  x , k , ch ;
  clrscr() ;
  do
  {
    printf("\n Menu: \n") ;
    printf("1:Create Linked List \n") ;
    printf("2:Insert After \n") ;
    printf("3:Insert Before \n") ;
    printf("4:Insert Begining \n") ;
    printf("5:Insert End \n") ;
    printf("6:Insert at a Position \n") ;
    printf("7:Delete Node \n") ;
    printf("8:Search Node \n") ;
    printf("9:Traverse \n") ;
    printf("10:Count \n") ;
    printf("11:Reverse \n") ;
    printf("12:Destroy List \n") ;
    printf("13:Exit \n") ;

    printf("\nEnter your choice: ") ;
    scanf("%d",&ch) ;

    switch(ch)
    {
      case 1:
      create() ;
      break ;

      case 2:
      printf("Enter the data value of new node: ") ;
      scanf("%d",&x) ;
      printf("Enter the data value of that node after which the new node is to be inserted: ") ;
      scanf("%d",&k) ;
      insertafter(x,k) ;
      break ;

      case 3:
      printf("Enter the data value of new node: ") ;
      scanf("%d",&x) ;
      printf("Enter the data value of that node before which the new node is to be inserted: ") ;
      scanf("%d",&k) ;
      insertbefore(x,k) ;
      break ;

      case 4:
      printf("Enter the data value of new node: ") ;
      scanf("%d",&x) ;
      insertbegining(x) ;
      break ;

      case 5:
      printf("Enter the data value of new node: ") ;
      scanf("%d",&x) ;
      insertend(x) ;
      break ;

      case 6:
      printf("Enter the data value of new node: ") ;
      scanf("%d",&x) ;
      printf("Enter the position at which the new node is to be inserted: ") ;
      printf("Position Number starts at 1: ") ;
      scanf("%d",&k) ;
      insertposition(x,k) ;
      break ;

      case 7:
      printf("Enter the data value of the node to be deleted: ") ;
      scanf("%d",&k) ;
      deletenode(k) ;
      break ;

      case 8:
      printf("Enter the data value of the node to be searched: ") ;
      scanf("%d",&k) ;
      search(k) ;
      break ;

      case 9:
      traverse() ;
      break ;

      case 10:
      count() ;
      break ;

      case 11:
      reverse() ;
      break ;

      case 12:
      destroylist() ;
      break ;

      case 13:
      break ;
    }
  }
  while(ch!=13) ;

  getch() ;
}







