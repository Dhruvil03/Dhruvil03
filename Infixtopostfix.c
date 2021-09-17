#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 10

char stack[SIZE];
int top=(-1);

char push(char a)
{   
	if(top>=SIZE-1)
	{
		printf("Stack is Overflow\n");
		return 0;
	}
    top+=1;
    stack[top]=a;
	return stack[top];
}

char pop()
{
     char temp;
     if(top<0)
	 {
		 printf("Stack is underflow\n");
		 return 0;
	 }
     temp=stack[top];
     top-=1;
     return temp;

}

int prio(char symbol)
{
	if(symbol == '^')/* exponent operator, highest precedence*/
	{
		return 3;
	}              
	else if(symbol == '*' || symbol == '/')
	{
		return 2;  
	}
	else if(symbol == '+' || symbol == '-')          /* lowest precedence */
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void main()
{
     int i;
	 char infix[100],x,item;

	 gets(infix);
	 push('(');
	 strcmp(infix,")");
	 i=0;
	 item=infix[i];
	 while(item!='\0')
	 {
		 if(item=='(')
		 push(item);

		 else if(isalpha(item) || isdigit(item))
		 printf("%c",item);

		 else if(item==')')
		 {
			 x=pop();
			 while(x!='(')
			 {
				 printf("%c",x);
				 x=pop();
			 }
		 }
		 else
		 {   
			 x=pop();
			 while(prio(item)<=prio(x))
			 {   
				 printf("%c",x);
				 x=pop();
				
			 }
			 push(x);
             
			 push(item);
		 }
		 i+=1;
		 item=infix[i];
	 }
	 while(top!=0){
     
	 printf("%c",pop());
	 }
}
