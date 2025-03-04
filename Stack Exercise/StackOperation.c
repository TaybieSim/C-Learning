#include <stdio.h>

#define MAX_SIZE 3

int* CreateStack(){

    return (int*) malloc(sizeof(int) * MAX_SIZE);
}

int IsEmpty(int top){

    if (top == -1){
        return 1;
    }
    else{
        return 0;
    }
}


int IsFull(int top){

    if (top == MAX_SIZE -1){
        return 1;
    }
    else{
        return 0;
    }
}


void push(int* stack, int* topPtr, int data){

    if (IsFull(*topPtr)){
        return;
    }

    stack[++(*topPtr)] = data;

}

int pop(int* stack, int* topPtr){

    if (IsEmpty(*topPtr)){
        return -1;
    }

    return stack[(*topPtr)--] ;
}




int main(){

    // Create stack
    int* stack = CreateStack();
    int top = -1;

    // push
    push(stack, &top, 1);
    push(stack, &top, 2);
    push(stack, &top, 3);

    // Check if empty
    while (IsEmpty(top) != 1){

        // Check if full
        if (IsFull(top)){
            printf("The stack is full.\n");
        }
        else{
            printf("The stack is not full.\n");
        }
        // pop
        printf("Pop data: %d\n", pop(stack, &top));

    }

    

    return 0;
}