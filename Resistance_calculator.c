#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int resistor_value(char color[10]);

int main() {
    char color1[10], color2[10], color3[10], color4[10], color5[10];
    int a, b, c, z, band;
    float tolerance = -1.0; 
    char repeat;
    int invalidFlag = 0; 

    do {
        invalidFlag = 0; 

        printf("Number of color bands in your resistor: ");
        scanf("%d", &band);

        if (band == 4 || band == 5) {
            printf("\n\t\t\t\t\t|values  Colours|    Multiplier           |Tolerance\n\t\t\t\t\t|0      BLACK|       10^0 |1 \n\t\t\t\t\t|1      BROWN|       10^1 |10             |1.0\n\t\t\t\t\t|2      RED|         10^2 |100            |2.0 \n\t\t\t\t\t|3      ORANGE|      10^3 |1000\n\t\t\t\t\t|4      YELLOW|      10^4 |10000 \n\t\t\t\t\t|5      GREEN|       10^5 |100000         |0.5\n\t\t\t\t\t|6      BLUE|        10^6 |1000000        |0.25\n\t\t\t\t\t|7      VIOLET|      10^7 |10000000       |0.10\n\t\t\t\t\t|8      GRAY|        10^8 |100000000      |0.05\n\t\t\t\t\t|9      WHITE|       10^9 |1000000000\n\t\t\t\t\t");
            if (band == 4) {
                printf("\nEnter four colors of your resistor:\n");
                scanf("%s %s %s %s", color1, color2, color3, color4);

                // Converting string to integer
                a = resistor_value(color1);
                b = resistor_value(color2);
                c = resistor_value(color3);

                if (a == -1 || b == -1 || c == -1) {
                    printf("\nInvalid color entered.\n");
                    invalidFlag = 1;
                } else {
                    z = (10 * a + b) * pow(10, c); // Calculation
                    printf("\nResistance: %d ohms\n", z);
                }
            } else {
                printf("\nEnter five colors of your resistor:\n");
                scanf("%s %s %s %s %s", color1, color2, color3, color4, color5);

                // Converting string to integer
                a = resistor_value(color1);
                b = resistor_value(color2);
                c = resistor_value(color3);
                int d = resistor_value(color4);

                if (a == -1 || b == -1 || c == -1 || d == -1) {
                    printf("\nInvalid color entered.\n");
                    invalidFlag = 1;
                } else {
                    z = (100 * a + 10 * b + c) * pow(10, d); // Calculation
                    tolerance = resistor_value(color5);

                    if (tolerance == -1.0) {
                        printf("\nInvalid tolerance color entered.\n");
                        invalidFlag = 1;
                    } else {
                        printf("\nResistance: %d ohms with tolerance %.2f%%\n", z, tolerance);
                    }
                }
            }
        } else {
            printf("\nInvalid number of bands entered. Please enter either 4 or 5.\n");
            break;
        }

        if (!invalidFlag) {
            printf("Do you want to repeat? (Y/N): ");
            scanf(" %c", &repeat);
        }
    } while (!invalidFlag && (repeat == 'Y' || repeat == 'y'));

    return 0;
}

// assigning values
int resistor_value(char color[10]) {
    int color_value;

    if (strcmp(color, "BLACK") == 0) {
        color_value = 0;
    } else if (strcmp(color, "BROWN") == 0) {
        color_value = 1;
    } else if (strcmp(color, "RED") == 0) {
        color_value = 2;
    } else if (strcmp(color, "ORANGE") == 0) {
        color_value = 3;
    } else if (strcmp(color, "YELLOW") == 0) {
        color_value = 4;
    } else if (strcmp(color, "GREEN") == 0) {
        color_value = 5;
    } else if (strcmp(color, "BLUE") == 0) {
        color_value = 6;
    } else if (strcmp(color, "VIOLET") == 0) {
        color_value = 7;
    } else if (strcmp(color, "GREY") == 0) {
        color_value = 8;
    } else if (strcmp(color, "WHITE") == 0) {
        color_value = 9;
    } else {
        color_value = -1; 
    }

    return color_value;
}
