#include <stdio.h>
#define Max 3
int q[Max];
int front=-1;
int rear=-1;
void insert(int data){
    if((rear+1)%Max==front){
        printf("Queue Overflow\n");
    }
    
    else{
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%Max;
        q[rear]=data;
    }
}
int delete(){
    if(front==-1){
        printf("Queue Underflow\n");
        return -1;
    }
    else{
        int val=q[front];
        printf("Deleted Value = %d \n",val);
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%Max;
        }
        return val;
    }
}
void display(){
    if(front==-1){
        printf("Queue is empty\n");
    }
    else{
        int i;
        printf("Queue values:\n");
        for(i=front;i!=rear;i=(i+1)%Max){
            printf("%d ",q[i]);
        }
        printf("%d ",q[i]);
        printf("\n");
    }
}
int main() {
    int task,a,x;
    task=0;
    while(task!=4){
        printf("press 1 to insert\n");
        printf("press 2 to delete\n");
        printf("press 3 to display\n");
        printf("press 4 to Exit\n");
        scanf("%d",&task);
        switch(task){
            case 1: printf("Enter Number\n");
                    scanf("%d",&a);
                    insert(a);
                    break;
            case 2: x=delete();
                    break;
            case 3: display();
                    break;
            case 4: printf("Exit\n");
                    break;
        }
    }
    return 0;
}