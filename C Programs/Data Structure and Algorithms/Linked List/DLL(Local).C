/* Doubly Linked List (Basic Operations) - Program to create a doubly linked list abstract data type and perform various operations on it (Variables first and last declared locally in main) */

#include  <stdio.h>
#include  <conio.h>
#include  <stdlib.h>
#define  NULL  0

/* Assume that the data portion of each node consists of only an integer. */
struct  node
{
  int  data ;
  struct  node  *next , *prev ;
} ;

/* This function is responsible for creating the Linked List right from the BEGINING. */
void  create(struct  node  **pfirst , struct  node  **plast)
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

    if(*pfirst==NULL)
    {
	  pnode->prev=pnode->next=NULL ;
       *pfirst=*plast=pnode ;    
    }
    else
    {   
       pnode->next=NULL ; 
       pnode->prev=*plast ;
	  (*plast)->next=pnode ;
	  *plast=pnode ;   /* *plast keeps track of last node */
    }
  }
}

/* This function will insert a new node with value x after a node with value K in an already existing Linked List */
void  insertafter(struct  node  **pfirst , struct  node  **plast , int  x , int  k)
{
  struct  node  *pnode , *p ;

  pnode=(struct node*)malloc(sizeof(struct node)) ;
  if(pnode==NULL)
  {
    printf("Memory overflow. Unable to create.\n") ;
    return ;
  }

  /* searching the required node */
  p=*pfirst ;
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
    if(p==*plast)       
    {                 /* inserting after last node */
	 pnode->next=NULL ;
	 pnode->prev=*plast ;
	 (*plast)->next=pnode ;
	 *plast=pnode ;
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
void  insertbefore(struct  node  **pfirst , int  x , int  k)
{
  struct  node  *pnode , *p ;

  pnode=(struct node*)malloc(sizeof(struct node)) ;
  if(pnode==NULL)
  {
    printf("Memory overflow. Unable to create.\n") ;
    return ;
  }

  /* searching the required node */
  p=*pfirst ;
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
    if(p==*pfirst)
    {                   /* inserting before first node */
	 pnode->prev=NULL ;
	 pnode->next=*pfirst ;
	 (*pfirst)->prev=pnode ;
	 *pfirst=pnode ;
    }
    else                /* inserting before any other node */
    {
	 pnode->prev=p->prev ;
	 pnode->next=p ;
	 p->prev->next=pnode ;
	 p->prev=pnode ;
    }
  }
}

/* This function will delete a node with value k from the Linked List if such a node exists */
void  deletenode(struct  node  **pfirst , struct  node  **plast , int  k)
{
  struct  node  *p ;

  /* searching the required node */
  p=*pfirst ;
  while(p!=NULL)
  {
    if(p->data==k)
      break ;
    p=p->next ;
  }

  if(p==NULL)
     printf("Required node not found.\n") ;
  else
  {
    /* actual deletion */
    if(p==*pfirst&&p==*plast) /* deleting one and only node */
      *pfirst=*plast=NULL ;
    else if(p==*pfirst)   /* deleting first node */
    {
      *pfirst=(*pfirst)->next ;
      (*pfirst)->prev=NULL ;
    }
    else if(p==*plast)   /* deleting last node */
    {
      *plast=(*plast)->prev ;
      (*plast)->next=NULL ;
    }
    else          /* deleting any other node */
    {
      p->prev->next=p->next ;
      p->next->prev=p->prev ;
    }

    free(p);  /* DON'T FORGET */
  }
}

/* This function will search a node with value k in the Linked List */
void  search(struct  node  *first , int  k)
{
  struct  node  *p ;

  p=first ;

  /* searching the required node */
  p=first ;
  while(p!=NULL)
  {
    if(p->data==k)
      break ;
    p=p->next ;
  }

  if(p==NULL)
     printf("Required node not found.\n") ;
  else
    printf("Required node is present at address %X \n",p) ;
}

/* This function go through all the nodes of Linked List from left to right exactly once and will display data value of each node */
void  traverse_right(struct  node  *first)
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

/* This function go through all the nodes of Linked List from right to left exactly once and will display data value of each node */
void  traverse_left(struct  node  *last)
{
  struct  node  *p ;

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
void  destroylist(struct  node  **pfirst , struct  node  **plast)
{
  *pfirst=*plast=NULL ;
}

void main()
{
  int  x , k , ch ;
  struct  node  *first=NULL ;
  struct  node  *last=NULL ;

  clrscr() ;

  do
  {
    printf("\n Menu: \n") ;
    printf("1:Create Linked List \n") ;
    printf("2:Insert After \n") ;
    printf("3:Insert Before \n") ;
    printf("4:Delete Node \n") ;
    printf("5:Search Node \n") ;
    printf("6:Traverse Right \n") ;
    printf("7:Traverse left \n") ;
    printf("8:Destroy List \n") ;
    printf("9:Exit \n") ;

    printf("\nEnter your choice: ") ;
    scanf("%d",&ch) ;

    switch(ch)
    {
      case 1:
      create(&first,&last) ;
      break ;

      case 2:
      printf("Enter the data value of new node: ") ;
      scanf("%d",&x) ;
      printf("Enter the data value of that node after which the new node is to be inserted: ") ;
      scanf("%d",&k) ;
      insertafter(&first,&last,x,k) ;
      break ;

      case 3:
      printf("Enter the data value of new node: ") ;
      scanf("%d",&x) ;
      printf("Enter the data value of that node before which the new node is to be inserted: ") ;
      scanf("%d",&k) ;
      insertbefore(&first,x,k) ;
      break ;

      case 4:
      printf("Enter the data value of the node to be deleted: ") ;
      scanf("%d",&k) ;
      deletenode(&first,&last,k) ;
      break ;

      case 5:
      printf("Enter the data value of the node to be searched: ") ;
      scanf("%d",&k) ;
      search(first,k) ;
      break ;

      case 6:
      traverse_right(first) ;
      break ;

      case 7:
      traverse_left(last) ;
      break ;

      case 8:
      destroylist(&first,&last) ;
      break ;

      case 9:
      break ;
    }
  }
  while(ch!=9) ;

  getch() ;
}











