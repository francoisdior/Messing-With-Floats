// Experimental program for my first Github submission. Asks the user
// to enter a decimal number that then outputs its corresponding hexadecimal
// and binary format.

#include <stdio.h>
#include <stdlib.h>

void printBinary( unsigned long fnum )
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

    printf("%s", out);
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
        printBinary(toLong);

        printf("\n\n");
        printf("Continue? ");
        scanf("%s", str);
        printf("\n");

    } while( str[0] == 'y' );

    return 0;
}
