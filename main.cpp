// Experimental program for my first Github submission. Asks the user
// to enter a decimal number that then outputs its corresponding hexadecimal
// and binary format.

#include <stdio.h>
#include <stdlib.h>

void printBinary_LayoutIEEE754( unsigned long fnum )
{
    unsigned long m=0x8000000000000000;
    int i=0, j=0;
    int strlen=64+2+2; // (binary characters) + spaces + ('b' + '\0')
    char out[ strlen ];
    int offsets[] = { 1, 11, 9999 };
    int currOff = offsets[j++];

    while(m) {
        if( m & fnum)
            out[i] = '1';
        else
            out[i] = '0';

        m >>= 1;
        i++;

        if( i == currOff ) {
            out[i++] = ' ';
            currOff = offsets[j++]+i;
        }
    }

    out[ strlen-2 ] = 'b';
    out[ strlen-1 ] = 0;

    printf("%s\n", out);
}

void printBinary_GroupsOf4( unsigned long fnum )
{
    unsigned long m=0x8000000000000000;
    int i=0, j=0;
    int strlen=64+16+2; // (binary characters) + spaces + ('b' + '\0')
    char out[ strlen ];

    while(m) {
        if( m & fnum)
            out[i] = '1';
        else
            out[i] = '0';

        m >>= 1;
        i++;

        if( ++j == 4 ) {
            j = 0;
            out[i++] = ' ';
        }
    }

    out[ strlen-3 ] = 'b';
    out[ strlen-1 ] = 0;

    printf("%s\n", out);
}

int main()
{
    double dec;
    unsigned long toLong;
    char str[20];

    do {
        printf("Enter a decimal: ");
        scanf("%lf", &dec);

        toLong = *((unsigned long*) &dec);
        printf("%f\n%lXh\n", dec, toLong);
        printBinary_GroupsOf4(toLong);
        printBinary_LayoutIEEE754(toLong);

        printf("\n");
        printf("Continue? ");
        scanf("%s", str);
        printf("\n");

    } while( str[0] == 'y' );

    return 0;
}
