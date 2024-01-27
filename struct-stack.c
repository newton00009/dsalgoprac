#include<stdio.h>
 
#define MAX 10
 
/* declaration*/
typedef struct
{
    int ele[MAX];
    int TOP;
}STACK;
 

/* function: pushItem( ), to insert an item into stack. */
void pushItem(STACK *s,int ITEM)
{
    if(s->TOP==MAX-1)
     { printf("\nSTACK is FULL.\n"); return;   }
   
    s->ele[++s->TOP]=ITEM;
    printf("\nITEM inserted successfully.\n");
}
 
/* function: popItem( ), to delete an item from stack. */
void popItem(STACK *s)
{
 
    int itm;
    if(s->TOP==-1)   
	{ printf("\nSTACK is empty.\n"); return; }
   
    itm=s->ele[s->TOP];
    s->TOP--;
    printf("\nItem removed : %d\n",itm);    
}
 
/* function: dispItem( ), to display stack elements. */
void dispItems(STACK *s)
{
    int i;
    if(s->TOP == -1) 
    { printf("STACK IS EMPTY."); return; }
    
	for(i=s->TOP;i>=0;i--)
        printf("%d->",s->ele[i]);
 
    printf("\n");
}
 
/*** main function **/
void main()
{
    int num,ch;
 	STACK *s;
    /** initialisation**/
     s=(STACK*)malloc(sizeof(STACK));
    s->TOP=-1;
    while(1) 
    {
	
	    printf("\nSTACK OPTIONS \n1: Push\n2: Pop\n3:Display\n4:Exit\nEnter choice ::");
	    scanf("%d",&ch);
	 
	    switch(ch)
	    {
	     
	        case 1:
	            printf("\nEnter an item to insert:");
	            scanf("%d",&num);
	            pushItem(s,num);
	        break;
	 
	        case 2:
	            popItem(s);
	        break;
	        case 3:
	            dispItems(s);
	        break;
			case 4:
	            exit(1);
	        break;
	 
	        default:
	            printf("\nAn Invalid Choice !!!");
	        break;
	 
	    }

	}
}
