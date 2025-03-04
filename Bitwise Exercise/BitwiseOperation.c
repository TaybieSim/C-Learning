#include <stdio.h>
void CheckLSB(int num);
void CheckMSB(int num);
void SetNbit(int num);
void ClearNbit(int num);
void ToggleNbit(int num);
void GetHighestOrderBit(int num);
void GetLowestOrderBit(int num);
void GetTrailingZero(int num);
void GetLeadingZero(int num);
void FlipBits(int num);
void CountOneZero(int num);
void ConvertToBinary(int num);
void CheckOddEven(int num);
void RotateBits(int num);

int main(){

    printf("Bitwise Operation:\n");


    int operation ;
    printf("Enter the operation to show:");
    scanf("%d", &operation);

    int num;
    printf("Enter the number:");
    scanf("%d", &num);

    switch (operation)
    {
    case 0:
        CheckLSB(num);
        break;
    case 1:
        CheckMSB(num);
        break;
    case 2:
        SetNbit(num);
        break;
    case 3:
        ClearNbit(num);
        break;
    case 4:
        ToggleNbit(num);
        break;
    case 5:
        GetHighestOrderBit(num);
        break;
    case 6:
        GetLowestOrderBit(num);
        break;
    case 7:
        GetTrailingZero(num);
        break;
    case 8:
        GetLeadingZero(num);
        break;
    case 9:
        FlipBits(num);
        break;
    case 10:
        CountOneZero(num);
        break;
    case 11:
        ConvertToBinary(num);
        break;
    case 12:
        CheckOddEven(num);
        break;
    case 13:
        RotateBits(num);
        break;
    
    default:
        printf("Invalid operation.");
        break;
    }
    
}

void CheckLSB(int num)
{
    int LSB = 0;
    if (num & 0){
        LSB = 0;
    }
    else if (num & 1){
        LSB =1;
    }

    printf("Least Significant Bit of %d is %d.", num, LSB);
}

void CheckMSB(int num)
{
    int MSB = 0;

    int bit = 1 << ((sizeof(int)*8) - 1);
    if (num & bit){
        MSB = 1;
    }
    else {
        MSB =0;
    }

    printf("Most Significant Bit of %d is %d.", num, MSB);
}

void SetNbit(int num)
{
    int NBit ;
    printf("Enter the n th of bit to set:");

    scanf("%d", &NBit);

    int OriginalBit;

    OriginalBit = (num >> NBit) & 1;

    printf("The original bit at position %d = %d.\n", NBit, OriginalBit);

    

    num = num | (1 << NBit);

    printf("The number after set bit %d = %d.\n", NBit, num);

}

void ClearNbit(int num)
{
    int NBit ;
    printf("Enter the n th of bit to clear:");

    scanf("%d", &NBit);

    int OriginalBit;

    OriginalBit = (num >> NBit) & 1;

    printf("The original bit at position %d = %d.\n", NBit, OriginalBit);

    num = num & ~(1<<NBit);

    printf("The number after clear bit %d = %d.\n", NBit, num);

}

void ToggleNbit(int num)
{
    int NBit ;
    printf("Enter the n th of bit to toggle:");

    scanf("%d", &NBit);

    int OriginalBit;

    OriginalBit = (num >> NBit) & 1;

    printf("The original bit at position %d = %d.\n", NBit, OriginalBit);

    num = num ^ (1 << NBit);

    printf("The number after toggle bit %d = %d.\n", NBit, num);
}

void GetHighestOrderBit(int num)
{
    // Find the highest order of bit (highest position of 1 from left)

    int temp = num;
    int order = 0;
    if (temp == 0){
        printf("No bits set in %d.\n", num);
    }
    while (temp > 1){

        temp >>= 1;
        order++;

    }

    printf("The highest order of bit set in %d is %d.\n", num, order);



}

void GetLowestOrderBit(int num)
{
    // Find the lowest order of bit (lowest position of 1 from right)
    int temp = num;
    int order = 0 ;
    if (temp == 0){
        printf("No bits set in %d.\n", num);
    }
    while (!((temp >> order++) & 1));
    printf("The lowest order of bit set in %d is %d.\n", num, order - 1);

}

void GetTrailingZero(int num)
{
    int temp = num;
    int count = 8*sizeof(int);
    int order = 0;
    while (!(temp & 1) && order < count){

        order++;
        temp >>= 1;
    }

    
    printf("The number of trailing zero in %d is %d.\n", num, order);
}

void GetLeadingZero(int num)
{
    int temp = num;
    int count = 8*sizeof(int);
    int msb = 1 << (count - 1);
    int order = 0;
    while (!(temp & msb) && (order < count)){

        order++;
        temp <<= 1;
    }

    printf("The number of leading zero in %d is %d.\n", num, order);
}


void FlipBits(int num)
{
    int mask = -1; // FFFF FFFF

    int flipNum = num ^ mask;

    //int flipNum = ~num;

    printf("%d after flip = %d.\n", num, flipNum);


}

void CountOneZero(int num)
{
    int TotalBit = 8*sizeof(int);

    int i = 0;
    int one = 0, zero = 0;
    while (i < TotalBit){

        if (num & 1){
            one++;
        }
        else{
            zero++;
        }

        num >>= 1;

        i++;
    }

    printf("Total number of zero bit = %d\n", zero);
    printf("Total number of one bit = %d\n", one);

}

void ConvertToBinary(int num)
{
    int TotalBit = 8*sizeof(int);
    int binary[TotalBit];

    int i = 0;
    int one = 0, zero = 0;
    while (i < TotalBit){

        binary[i] = (num >> i) & 1;

        i++;
    }
    
    printf("The binary number of %d = ", num);
    for (int i = TotalBit-1; i >=0 ; i--){
        printf("%d", binary[i]);
    }
    
}

void CheckOddEven(int num)
{
    if (num & 0){
        printf("%d is even number.", num);
    }
    else{
        printf("%d is odd number.", num);
    }
}

void RotateBits(int num){

    int TotalBit = 8*sizeof(int);
    unsigned int rotation;
    printf("Enter number of rotation: ");
    scanf("%u", &rotation);

    // Get 
    rotation %= TotalBit;

    int LeftRotatedNum = num, RightRotatedNum = num;

    int MSB, LSB;

    int i = rotation;
    
    while (i > 0){

        // Left Rotation

        MSB = (LeftRotatedNum >> (TotalBit - 1)) & 1;

        LeftRotatedNum = (LeftRotatedNum << 1 | MSB);

        // Right Rotation

        LSB = RightRotatedNum & 1;

        // Clear the MSB of right shifted number
        RightRotatedNum = (RightRotatedNum >> 1 ) & ~(1 << (TotalBit - 1));
            
        RightRotatedNum = (RightRotatedNum | (LSB << (TotalBit - 1)));

        i--;
    }

    printf("%d shift left by %d times = %d\n", num, rotation, LeftRotatedNum);
    printf("%d shift right by %d times = %d\n", num, rotation, RightRotatedNum);


}
