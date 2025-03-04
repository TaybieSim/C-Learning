#include <stdio.h>

struct EmployeeAddress{
    char *name;
    char StreetName[100];
};



// To use pointer for struct, all variable must allocate memory, cannot use char* if not allocate memory
struct Employee{
    int EmployeeId;
    char EmployeeName[20];
    char Department[20];
};

void InstanceStruct();
void AllocateMemoryStruct();
void ArrayOfStruct();

int main(){

    printf("\nPointer : Show the usage of pointer to instance of the structure :\n");
    InstanceStruct();

    printf("\nPointer : Show the usage of pointer to structure :\n");
    AllocateMemoryStruct();

    printf("\nPointer : Show the usage of pointer to structure array:\n");
    ArrayOfStruct();



    return 0;
}



void InstanceStruct()
{
    // Initialize struct with string literals
    struct EmployeeAddress employee = {"John Alter", "Court Street \n"};
    struct EmployeeAddress *pt = &employee;
    

    printf("Before change:\n Name: %s \n Address: %s \n", pt->name, (*pt).StreetName);

    //
    // Cannot use scanf to modify the name in struct as the pointer not pointing to a valid memory location
    //
    //// printf("Enter the new employee's name: ");
    //// scanf("%[^\n]s", employee.name);

    pt->name = "Taylor Alter";

    // Printing employee details after change
    printf("After change:\n Name: %s \n Address: %s \n", pt->name, (*pt).StreetName);

    return;

}

void AllocateMemoryStruct()
{

    
    int num;
    
    // Get number of employee

    printf("Enter the number of employee: ");
    scanf("%d", &num);

    struct EmployeeAddress employee[num];
    // Pointer point to the first array of EmployeeData 
    
    while (getchar() != '\n');
    // Enter data
    for (int i = 0; i < num; i++){

        // Allocate Memory to char* name in struct
        employee[i].name = (char*) malloc(20* sizeof(char));

        if (employee[i].name == NULL) {
            printf("Memory allocation failed!\n");
            return; // Exit if memory allocation fails
        }

        printf("\nEnter the employee's name: ");
        fgets(employee[i].name, 20, stdin);
        employee[i].name[strcspn(employee[i].name, "\n")] = '\0';

        printf("Enter the employee's address: ");
        fgets(employee[i].StreetName, 100, stdin);
        employee[i].StreetName[strcspn(employee[i].StreetName, "\n")] = '\0';
    }
    
    struct EmployeeAddress *pt = employee;
    
    // Display Data
    int count = 1;
    while (count <= num){
        printf("\nEmployee %d's Data: \n", count);
        printf("Name: %s\n", pt->name);
        printf("Adress: %s\n", pt->StreetName);

        pt++;

        count++;
    }

    // Free dynamically allocated memory
    for (int i = 0; i < num; i++){

        free(employee[i].name);
    }

    return;

}

void ArrayOfStruct()
{
   
    int num;
    
    // Get number of employee

    printf("Enter the number of employee: ");
    scanf("%d", &num);

    struct Employee EmployeeData[num];
    

    // Enter data
    for (int i = 0; i < num; i++){

        printf("Enter the employee Id: ");
        scanf("%d", &(EmployeeData[i].EmployeeId));
        while (getchar() != '\n');
        printf("Enter the employee's name: ");
        scanf("%[^\n]s", EmployeeData[i].EmployeeName);
        while (getchar() != '\n');
        printf("Enter the employee's department: ");
        scanf("%[^\n]s", EmployeeData[i].Department);
        while (getchar() != '\n');
    }

    // Pointer point to the first array of EmployeeData 
    struct Employee *EmployeeDataPtr = EmployeeData; // &EmployeeData[0]
    // Display Data
    int count = 1;
    while (count <= num){
        printf("\nEmployee %d's Data: \n", count);
        printf("Name: %s\n", EmployeeDataPtr->EmployeeName);
        printf("Id: %d\n", EmployeeDataPtr->EmployeeId);
        printf("Department: %s\n", EmployeeDataPtr->Department);

        EmployeeDataPtr++;

        count++;
    }
}
