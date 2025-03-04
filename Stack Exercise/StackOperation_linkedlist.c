#include <stdio.h>

struct Node{
    int data;
    struct Node* nextNode;
};

struct Stack{

    struct Node* topNode;
};


struct Stack* CreateStack(){

    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->topNode = NULL;
    return stack;

}


struct Node* CreateNode(int data){

    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->nextNode = NULL;
    return node;

}


void push(struct Stack* stack, int data){

    struct Node* node = CreateNode(data);
    node->nextNode = stack->topNode;
    stack->topNode = node;
}


int pop(struct Stack* stack){

    struct Node* node = stack->topNode;
    int poppedData = node->data;
    stack->topNode = node->nextNode;
    free(node);
    return poppedData;
}

int IsEmpty(struct Stack* stack){
    
    if (stack->topNode != NULL){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){

    
    // Create stack
    struct Stack* stack = CreateStack();

    // push data
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    // Check if empty
    while (IsEmpty(stack)!= 1){

        // pop data
        int poppedData = pop(stack);

        printf("Pop Data = %d\n", poppedData);

    }

    return 0;
}