// Online C compiler to run C program online
#include <stdio.h>

#include <stdio.h>
int stack[5];
int top=-1;
void push(int a){
if(top==sizeof(stack)/sizeof(stack[0])-1){
   printf("stack is full\n");
   }
   else{
    stack[++top]=a;
   }
}
int pop(){
    if(top==-1){
        printf("Stack underflow\n");
        return -1;
    }
    else{
        return stack[top--];
    }
}
void display(){
    if(top==-1){
        printf("Stack underflow\n");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}
void main(){
    int n,a,task;
    int t=1;
    while(t!=0){
        printf("Enter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 3 to display\n");
        printf("Enter 4 to exit\n");
        printf("Enter the task\n");
        scanf("%d",&task);
        switch(task){
        case 1:
            printf("Enter the value\n");
            scanf("%d",&a);
            push(a);
            break;
        case 2:
             int b=pop();
            printf("pop value = %d\n",b);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("closing\n");
            t=0;
            break;
    }
}
}
