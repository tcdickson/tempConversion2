//	(Packing Characters into an Integer) The left-shift operator can be used to pack four character values into a four-byte unsigned int variable. Write a program that inputs four characters from the keyboard and passes them to function packCharacters. To pack four characters into an unsigned int variable, assign the first character to the unsigned int variable, shift the unsigned int variable left by 8 bit positions and combine the unsigned variable with the second character using the bitwise inclusive OR operator. Repeat this process for the third and fourth characters. The program should output the characters in their bit format before and after they’re packed into the unsigned int to prove that the characters are in fact packed correctly in the unsigned int variable.

// C Libraries
#include <stdio.h>
// function prototype
unsigned int packCharacters(int x, int y, int j, int z);
void displayBits(unsigned int value);
int main()
{
    //defining variables and prints instructions
    unsigned int x, y, j, z;
    printf("enter 4 non negative integers: ");
    //takes inputed values
    scanf("%d%d%d%d", &x, &y, &j, &z);

    //setting the user inputted packCharacters to unsigned int variable packed. 
    unsigned int packed = packCharacters(x, y, j, z);
    puts("output of characters before packing:");
    //showing the packed value based on the numbers inputted
    printf("%d, %d, %d, and %d = %u packed\n",x,y,j,z, packed);
    puts("Binary form: \n");
    //showing the bit form of each number for comparison
    displayBits(x);
    displayBits(y);
    displayBits(j);
    displayBits(z);

    puts("\noutput of characters after packing into unsigned int:\n");
    //entering the packed value of whatever the user inputted shown in bits
    displayBits(packed);

    return 0;
}
// this function takes 4 values and uses left shift operator to shift the value from the rightmost bit to the left by 8 for each variable
unsigned int packCharacters(int x, int y, int j, int z)
{
    unsigned int t = x;
    t = (y << 8) | t;
    t = (j << 8) | t;
    t = (z << 8) | t;
    return t;
}
// I took this function from the assigned reading. It essentially combines the value variable - which is the user inputted number - to the displayMask variable. This allows you to get a number in bits.
void displayBits(unsigned int value)
{
    // define displayMask and left shift 31 bits
    unsigned int displayMask = 1 << 31;

    printf("%10u = ", value);

    // loop through bits
    for (unsigned int c = 1; c <= 32; ++c)
    {
        //determines whether a 1 or 0 should be printed out for the current leftmost bit of variable value
        putchar(value & displayMask ? '1' : '0');
        // shift value left of operand by 1
        value <<= 1; 
        // output a space after every 8 bits
        if (c % 8 == 0)
        { 
            putchar(' ');
        }
    }
    putchar('\n');
}