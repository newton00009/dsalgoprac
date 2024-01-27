#include <stdio.h>
int size;
struct s
{
    int stack[100];
    int top;
}st;
void push();
void pop();
void show();
int main()
{
    st.top=-1;
  int d=0;
    printf("Enter the stack size \n");
    scanf("%d",&size);
    while(d!=4) {
        printf(" \nMENU \n");
        printf("Press 1> TO PUSH \n");
        printf("Press 2> TO POP \n");
        printf("Press 3> TO ShOW \n");
        printf("Press 4> TO END \n");
        printf("Enter the choice: ");
        scanf("%d",&d);
        switch (d) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                show();
                break;}
    }
}
void push()
{
    int item;
    if(st.top==size-1)
    {
        printf("Stack is Full");
    }
    else
    { printf("Enter the Number: ");
        scanf("%d",&item);
        st.top=st.top+1;
        st.stack[st.top]=item;
    }
}

void pop()
{
    if(st.top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        st.top--;
    }
}

void show()
{
    for(int i=0;i<=st.top;i++)
    {
        printf("%d \n",st.stack[i]);
    }
}
