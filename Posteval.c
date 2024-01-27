#include<stdio.h>
#include<ctype.h>

# define MAXSTACK 20       /* for max size of stack */
 # define POSTFIXSIZE 20     /* define max number of charcters in postfix expression */

int stack[MAXSTACK];
int top = -1 ;             
 
 void push(int item)
 {

	 if(top >= MAXSTACK -1)
	 {
		 printf("stack over flow");
		 return;
	 }
	 else
	 {
		 top = top + 1 ;
		 stack[top]= item;
	 }
 }

 int pop()
 {
	 int item;
	 if(top <0)
	 {
		printf("stack under flow");
	 }
	 else
	 {
		 item = stack[top];
		 top = top - 1;
		 return item;
	 }
 }

 void EvalPostfix(char postfix[])
 {

	int i ;
	char ch;
	int val;
	int A, B ;


	/* evaluate postfix expression */
	for (i = 0 ; postfix[i] != '\0'; i++)
	{
		ch = postfix[i];
		if (isdigit(ch))
		{
			push(ch - '0'); // to get digit value from ASCII
		} 
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			/* we saw an operator
			* pop top element A and next-to-top elemnet B
			* from stack and compute B operator A
			*/
			A = pop();
			B = pop();

			switch (ch) /* ch is an operator */
			{
				case '*':
				val = B * A;
				break;

				case '/':
				val = B / A;
				break;

				case '+':
				val = B + A;
				break;

				case '-':
				val = B - A;
				break;
			}

			/* push the value obtained above onto the stack */
			push(val);
		}
	}
	printf( " \n Result of expression evaluation : %d \n", pop()) ;
 }

 int main()
 {

	int i ;
	char postfix[POSTFIXSIZE];
	printf("ASSUMPTION: There are only four operators(*, /, +, -) in an expression and operand is single digit only.\n");
	
printf( " \nEnter postfix expression\n");
scanf("%s",postfix);
	
EvalPostfix(postfix);
	
	return 0;
 }

