/* Doubly Linked List (Basic Operations) - Program to create a doubly linked list abstract data type and perform various operations on it (Variables first and last declared globally) */

#include  <stdio.h>
#include  <conio.h>
#include  <stdlib.h>
#define  NULL  0

/* Assume that the data portion of each node consists of only an integer. */
struct  node
{
  int  data ;
  struct  node  *next , *prev ;
};

struct  node  *first=NULL ;
struct  node  *last=NULL ;

/* first and last are global variables and need not be passed to any function. Any changes made to variables first and last by any of the functions in the program will be permanent and will be reflected in the entire program */

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

    if(first==NULL)
    {
	 pnode->prev=pnode->next=NULL ;
      first=last=pnode ;
    }
    else
    {
	pnode->next=NULL ;
	pnode->prev=last ;
	last->next=pnode ;
	last=pnode ;    /* last keeps track of last node */
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
    p=p->next ;

  }

  /* p becomes NULL when required data is not found */
  if(p==NULL)
     printf("Required node not found.\n") ;
  else
  {
    pnode->data=x ;

    /* actual insertion */
    if(p==last)       /* inserting after last node */
    {
	 pnode->next=NULL ;
	 pnode->prev=last ;
	 last->next=pnode ;
	 last=pnode ;
    }
    else  /* inserting after any other node */
    {
	 pnode->next=p->next ;
	 pnode->prev=p ;
	 p->next->prev=pnode ;
	 p->next=pnode ;
    }
  }
}


/* This function will insert a new node with value x before a node with value K in an already existing Linked List */
void  insertbefore(int  x , int  k)
{
  struct  node  *pnode , *p ;

  pnode=(struct node*)malloc(sizeof(struct node)) ;
  if(pnode==NULL)
  {
    printf("Memory overflow. Unable to create.\n");
    return;
  }

  /* searching the required node */
  p=first ;
  while(p!=NULL)
  {
    if(p->data==k)
	  break ;
    p=p->next ;
  }

  /* p becomes NULL when required data is not found */
  if(p==NULL)
     printf("Required node not found.\n") ;
  else
  {
    pnode->data=x ;

    /* actual insertion */
    if(p==first)
    {              /* inserting before first node */
	 pnode->prev=NULL ;
	 pnode->next=first ;
	 first->prev=pnode ;
	 first=pnode ;
    }
    else    /* inserting before any other node */
    {
	 pnode->prev=p->prev ;
	 pnode->next=p ;
	 p->prev->next=pnode ;
	 p->prev=pnode ;
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

  if(first==NULL)
  {
    pnode->prev=pnode->next=NULL ;
    first=last=pnode ;
  }
  else
  {
    pnode->prev=NULL ;
    pnode->next=first ;
    first->prev=pnode ;
    first=pnode ;
  }
}

/* This function will insert a new node with value x at the end of EXISTING Linked List */
void  insertend(int  x)
{
  struct  node  *pnode ;
  pnode=(struct node*)malloc(sizeof(struct node)) ;

  if(pnode==NULL)
  {
    printf("Memory overflow. Unable to create.\n") ;
    return ;
  }

  pnode->data=x ;

  pnode->next=NULL ; /* pnode is now the last node */
  pnode->prev=last ;
  last->next=pnode ;
  last=pnode ;
}


/* This function will delete a node with value k from the Linked List if such a node exists */
void  deletenode(int  k)
{
  struct  node  *p ;

  /* searching the required node */
  p=first ;
  while(p!=NULL)
  {
    if(p->data==k)
	  break ;
    p=p->next ;
  }

  /* p becomes NULL when required data is not found */
  if(p==NULL)
     printf("Required node not found.\n") ;
  else
  {
    /* actual deletion */
    if(p==first&&p==last) /* deleting one and only node */
      first=last=NULL ;
    else if(p==first)    /* deleting first node */
    {
      first=first->next ;
      first->prev=NULL ;
    }
    else if(p==last)   /* deleting last node */
    {
      last=last->prev ;
      last->next=NULL ;
    }
    else           /* deleting any other node */
    {
      p->prev->next=p->next ;
      p->next->prev=p->prev ;
    }

    free(p) ;        /* DON'T FORGET */
  }
}

/* This function will search a node with value k in the Linked List */
void  search(int  k)
{
  struct  node  *p ;

  /* searching the required node */
  p=first ;
  while(p!=NULL)
  {
    if(p->data==k)
	  break ;
    p=p->next ;
  }

  /* p becomes NULL when required data is not found */
  if(p==NULL)
     printf("Required node not found.\n") ;
  else
    printf("Required node is present at address %X \n",p) ;
}

/* This function goes through all the nodes of Linked List from left to right exactly once and will display data value of each node */
void  traverse_right()
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

/* This function goes through all the nodes of Linked List from right to left exactly once and will display data value of each node */
void  traverse_left()
{
  struct node *p ;

  if(last==NULL)
    printf("Linked List Empty") ;
  else
  {
    printf("Linked List is as shown: \n") ;

    p=last ;
    while(p!=NULL)
    {
      printf("%d ",p->data) ;
      p=p->prev ;
    }

    printf("\n") ;
  }
}

/* count() exactly same as SLL */

/* This function will make the Linked List empty. */
void  destroylist()
{
  first=last=NULL ;
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
    printf("6:Delete Node \n") ;
    printf("7:Search Node \n") ;
    printf("8:Traverse Right \n") ;
    printf("9:Traverse left \n") ;
    printf("10:Destroy List \n") ;
    printf("11:Exit \n") ;

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
      printf("Enter the data value of the node to be deleted: ") ;
      scanf("%d",&k) ;
      deletenode(k) ;
      break ;

      case 7:
      printf("Enter the data value of the node to be searched: ") ;
      scanf("%d",&k) ;
      search(k) ;
      break ;

      case 8:
      traverse_right() ;
      break ;

      case 9:
      traverse_left() ;
      break ;

      case 10:
      destroylist() ;
      break ;

      case 11:
      break ;
    }
  }
  while(ch!=11) ;

  getch() ;
}











