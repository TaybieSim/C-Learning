
#include <stdio.h>
#include <stdlib.h>


// list with data and next

typedef struct list{
    int data;
    struct list* next;
    
} list;

int RandomNumber(int num);
list * CreateNode(int num);
list * AppendNode(list *, list *);
void SortList(list*);
void DisplayList(list *);


#define SIZE 100
int main(void) {
    
    list *IntList, *EndPtr, *ptr;
    IntList=NULL;
    
    int num;
    // Create link list with 100 integers
    for(int i =0; i <= SIZE; i++){
        num = RandomNumber(100);
        // create link node
        ptr = CreateNode(num);
        
        // Append to the IntList
        if (IntList == NULL){
            // Link IntList to first ptr
            IntList = ptr;
            
            // EndPtr stores the address of ptr for next
            EndPtr = ptr;
            
        }else{
            // Link previous EndPtr to ptr
            // and return ptr to EndPtr
            EndPtr = AppendNode(EndPtr, ptr);
        }

        
    }
    
    // Sort the link list
    SortList(IntList);
    
    //Print in row of 5
    DisplayList(IntList);
    
    return 0;
}

int RandomNumber(int num){
    int n;
    
    n = (rand() % 
        (num - 0 + 1)) + 0; 
    
    return n;
}


list * CreateNode(int num){
    list *ptr;
    ptr = malloc(sizeof(list));
    ptr->data = num;
    ptr->next = NULL; 
    return ptr;
}



list* AppendNode(list* Endptr, list* ptr){
    
    Endptr->next= ptr;
    return Endptr->next;
}

void SortList(list* ptr){
    // Bubble Sort
    list * Node = ptr;
    list *NextNode;
    for (int i =0; i <= SIZE-1; i++){
        NextNode = Node->next;
        
        for (int j=i+1; j <= SIZE; j++){
            
            if (Node->data > NextNode->data){
                // Swap
                int temp = Node->data;
                Node -> data = NextNode->data;
                NextNode->data= temp;
            }
            
            
            NextNode = NextNode->next;
        }
        
        Node = Node->next;
        
    }
    
    
}


void DisplayList(list *header){
    list * ptr = header;
    int i =0;
    while (ptr->next != NULL){
        
        printf("%d\t", ptr->data);
        ptr = ptr->next;
        i++;
        
        if (i%5==0){
            printf("\n");
        }
        
    }
    
}


