// With love by @iyer3142

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main() {
    char  hexNum[100] = {0};
    char  BIN_pool[100] = {0};
    int   mant_counter = 0;
    int   BIN_pool_d[100] = {0};
    int   exponent_bits[8], mantissa_bits[23], exponent_value = 0, j = 0;
    float mantissa_value = 0;
    float man_f, man_f1, result;

    long int count = 0;

    printf("Enter a hexadecimal number To Convet it into Binary : ");
    scanf("%s", hexNum);
    // size = sizeof(hexNum);
    while (hexNum[count]) {
        switch (hexNum[count]) {
            case '0':
                strcat(BIN_pool, "0000");
                break;
            case '1':
                strcat(BIN_pool, "0001");
                break;
            case '2':
                strcat(BIN_pool, "0010");
                break;
            case '3':
                strcat(BIN_pool, "0011");
                break;
            case '4':
                strcat(BIN_pool, "0100");
                break;
            case '5':
                strcat(BIN_pool, "0101");
                break;
            case '6':
                strcat(BIN_pool, "0110");
                break;
            case '7':
                strcat(BIN_pool, "0111");
                break;
            case '8':
                strcat(BIN_pool, "1000");
                break;
            case '9':
                strcat(BIN_pool, "1001");
                break;
            case 'A':
                strcat(BIN_pool, "1010");
                break;
            case 'B':
                strcat(BIN_pool, "1011");
                break;
            case 'C':
                strcat(BIN_pool, "1100");
                break;
            case 'D':
                strcat(BIN_pool, "1101");
                break;
            case 'E':
                strcat(BIN_pool, "1110");
                break;
            case 'F':
                strcat(BIN_pool, "1111");
                break;
            case 'a':
                strcat(BIN_pool, "1010");
                break;
            case 'b':
                strcat(BIN_pool, "1011");
                break;
            case 'c':
                strcat(BIN_pool, "1100");
                break;
            case 'd':
                strcat(BIN_pool, "1101");
                break;
            case 'e':
                strcat(BIN_pool, "1110");
                break;
            case 'f':
                strcat(BIN_pool, "1111");
                break;
            default:;
        }
        count++;
    }

    for (int i = 0; i < 32; i++) {
        BIN_pool_d[i] = BIN_pool[i] - 48;
    }

    // printf("\nValue\t=  %s", BIN_pool);
    printf("\nInt array Value\t= ");
    for (int i = 0; i < 32; i++) {
        printf("%d", BIN_pool_d[i]);
    }

    printf("\nSign-bit: \t%d\t", BIN_pool_d[0]);
    if (BIN_pool_d[0] == 0) {
        printf("+ve");
    } else {
        printf("-ve");
    }
    printf("\nExponent Bits:\t");
    for (int i = 0; i < 8; i++) {
        exponent_bits[i] = BIN_pool_d[i + 1];
        printf("%d", exponent_bits[i]);
    }

    for (int i = 0, j = 7; i < 8, j >= 0; i++, j--) {
        exponent_value += (exponent_bits[j] * pow(2, i));
    }
    exponent_value = pow(2, (exponent_value - 127));
    printf("\nExponent Value:\t%d", exponent_value);
    /* ----------------------------------------*/

    printf("\nMantissa Bits:\t");
    for (int i = 0; i < 23; i++) {
        mantissa_bits[i] = BIN_pool_d[i + 9];
        printf("%d", mantissa_bits[i]);
    }

    for (int i = 0; i < 23; i++) {
        mantissa_value += (mantissa_bits[i] * (1.0 / pow(2, (i + 1))));
    }
    printf("\nMantissa Value:\t%f", mantissa_value);

    man_f = mantissa_value;
    man_f1 = man_f;

    man_f1 = 1 + man_f1;
    printf("\nMantissa Value:\t%f", man_f1);
    result = man_f1 * exponent_value;

    printf("\n\nRESULT:\t\t%f", result);

    return 0;
}
