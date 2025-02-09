/*

Option 1:
Write enumerated types that supports dates such as december 12. 
Then add a function that produces a next day.  
So nextday(date) of december 12 is december 13. 
Also write a function printdate(date) that 
prints a date legibly.The function can assume that February has 28 days 
and it most know how many days are in each month. 
Use a struct with two members; 
one is the month and the second is the day of the month an int (or short).

*/
#include <stdio.h>

struct point{
double x;
double y;
} p1;

// List of month
typedef enum{ 
    jan=1, feb, mar,
    apr, may, jun,
    july, aug, sep,
    oct, nov, dec
} month; // the enum variable name

// Input from users
typedef struct{ 
    month m; 
    int d;
} date; 

void printdate(month mth, int);
void nextdate(month*, int*);
int maxDay(month mth);

int main(void) {
    // Write C code here
    int dt;
    month mth;
    printf("Please enter the date and month (dd mth):");
    scanf("%d %d", &dt, &mth);
    
    if (dt > maxDay(mth)){
        printf("Error! Please enter a valid date for respective month\n");
        return 0;
    }
    
    printf("Date entered = ");
    printdate(mth,dt);
    
    // Get next date
    nextdate(&mth,&dt);
    printf("Next day = ");
    printdate(mth,dt);

    return 0;
}

// Get last date for each month
int maxDay(month mth){
    int LastDate = 0;
    switch (mth){
        case feb:{
            LastDate = 28;
            break;
        }
        case jan:
        case mar:
        case may:
        case july:
        case aug:
        case oct:
        case dec:{
            LastDate = 31;
            break;
        }
        case apr:
        case jun:
        case sep:
        case nov:{
            LastDate = 30;
            break;
        }
        
    }
    
    return LastDate;
    
}


// Function printdate: print the date
void printdate(month mth, int dt){
    char *m;
    switch(mth){
        case jan:{
            m = "January";
            break;
        }
        case feb:{
            m = "February";
            break;
        }
        case mar:{
            m = "March";
            break;
        }
        case apr:{
            m = "April";
            break;
        }
        case may:{
            m = "May";
            break;
        }
        case jun:{
            m = "June";
            break;
        }
        case july:{
            m = "July";
            break;
        }
        case aug:{
            m = "August";
            break;
        }
        case sep:{
            m = "September";
            break;
        }
        case oct:{
            m = "October";
            break;
        }
        case nov:{
            m = "November";
            break;
        }
        case dec:{
            m = "December";
            break;
        }
    }
    printf("%s %d\n",m, dt );
    
}

// Function nextdate: get the next date by passing value in argument
void nextdate(month *mth, int *dt){
    
    *dt += 1;
    
    // If date exceed the maxDay in each month, move to next month
    if (*dt > maxDay(*mth)){
        *dt = 1;
        *mth = ((*mth)%12) +1;
    }
    
}