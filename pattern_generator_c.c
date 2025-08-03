#include <stdio.h>
#include <stdlib.h>

// Function declarations
void tri_num(int);
void tri_pascal(int);
void box_pattern(int, int, char);
void hollow_box(int, int, char);
void diagonal(int, int, char);
void border_diagonal(int, int, char);
void tri_right(int, int, char);
void tri_inv_right(int, char);
void tri_left(int, char);
void tri_inv_left(int, char);
void diamond(int, char);
void tri_hollow(int, char);
void pyramid(int, char);
void sandglass(int, char);

int main() {
    //In C lang. initialize variable at the time of declaration
    int choice = 0, row = 0, col = 0;  
    char repeat = 'y', symbol = '*';    

    do {
        printf("\n___________Pattern Generator Menu___________\n");
        printf("1. Number Triangle\n");
        printf("2. Pascal Triangle\n");
        printf("3. Box Pattern\n");
        printf("4. Hollow Box\n");
        printf("5. Diagonal\n");
        printf("6. Border + Diagonal\n");
        printf("7. Right Triangle\n");
        printf("8. Diamond\n");
        printf("9. Hollow Triangle\n");
        printf("10. Inverse Right Triangle\n");
        printf("11. Left Triangle\n");
        printf("12. Inverse Left Triangle\n");
        printf("13. Pyramid\n");
        printf("14. Sandglass Pattern\n");
        printf("0. Exit\n");
        printf("---------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        // Handle input for different cases 
        if (choice >= 3 && choice <= 6) {
            printf("Enter number of rows: ");
            scanf("%d", &row);
            printf("Enter number of columns: ");
            scanf("%d", &col);
            printf("Enter the symbol to print in pattern : ");
            scanf(" %c", &symbol);

        } else if ((choice >= 7 && choice <= 14)) {
            printf("Enter number of rows: ");
            scanf("%d", &row);
            printf("Enter the symbol to print in pattern: ");
            scanf(" %c", &symbol);

        } else if (choice == 1 || choice == 2) {
            printf("Enter number of rows: ");
            scanf("%d", &row);
        }

        switch (choice) {
            case 1: tri_num(row); 
                break;
            case 2: tri_pascal(row); 
                break;
            case 3: box_pattern(row, col, symbol); 
                break;
            case 4: hollow_box(row, col, symbol); 
                break;
            case 5: diagonal(row, col, symbol); 
                break;
            case 6: border_diagonal(row, col, symbol); 
                break;
            case 7: tri_right(row, col, symbol); 
                break;
            case 8: diamond(row, symbol); 
                break;
            case 9: tri_hollow(row, symbol); 
                break;
            case 10: tri_inv_right(row, symbol); 
                break;
            case 11: tri_left(row, symbol);
                break;
            case 12: tri_inv_left(row, symbol); 
                break;
            case 13: pyramid(row, symbol); 
                break;
            case 14: sandglass(row, symbol); 
                break;
            default: printf("Invalid choice. Please select a valid option.\n");
        }

        printf("\nDo you want to print another pattern? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}

void tri_num(int row) {
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= i; j++) 
            printf("%d ", j);
        printf("\n");
    }
}

void tri_pascal(int row) {
    for (int i = 0; i < row; i++) {
        int num = 1;
        for (int j = 0; j < row - i - 1; j++) 
            printf(" ");
        for (int j = 0; j <= i; j++) {
            printf("%d ", num);
            num = num * (i - j) / (j + 1);  //formula
        }
        printf("\n");
    }
}

void box_pattern(int row, int col, char ch) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) 
            printf("%c", ch);
        printf("\n");
    }
}

void hollow_box(int row, int col, char ch) {
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            if (i == 1 || i == row || j == 1 || j == col)
                printf("%c", ch);
            else
                printf(" ");
        }
        printf("\n");
    }
}

void diagonal(int row, int col, char ch) {
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            if (i == j)
                printf("%c", ch);
            else
                printf(" ");
        }
        printf("\n");
    }
}

void border_diagonal(int row, int col, char ch) {
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            if (i == 1 || j == 1 || i == row || j == col || i == j)
                printf("%c", ch);
            else
                printf(" ");
        }
        printf("\n");
    }
}

void tri_right(int row, int col, char ch) {
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= i; j++) 
            printf("%c", ch);
        printf("\n");
    }
}

void tri_inv_right(int row, char ch) {
    for (int i = row; i >= 1; i--) {
        for (int j = 1; j <= i; j++) 
            printf("%c", ch);
        printf("\n");
    }
}

void tri_left(int row, char ch) {
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= row - i; j++) 
            printf(" ");
        for (int j = 1; j <= i; j++) 
            printf("%c", ch);
        printf("\n");
    }
}

void tri_inv_left(int row, char ch) {
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j < i; j++) 
            printf(" ");
        for (int j = i; j <= row; j++) 
            printf("%c", ch);
        printf("\n");
    }
}

void diamond(int row, char ch) {
    for (int i = 1; i <= row; i++) {
        for (int j = i; j < row; j++) 
            printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++) 
            printf("%c", ch);
        printf("\n");
    }
    for (int i = row - 1; i >= 1; i--) {
        for (int j = row; j > i; j--) 
            printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++) 
            printf("%c", ch);
        printf("\n");
    }
}

void tri_hollow(int row, char ch) {
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i || i == row)
                printf("%c", ch);
            else
                printf(" ");
        }
        printf("\n");
    }
}

void pyramid(int row, char ch) {
    for (int i = 1; i <= row; i++) {
        for (int j = i; j < row; j++) 
            printf(" ");
        for (int j = 1; j <= (2*i-1); j++) 
            printf("%c", ch);
        printf("\n");
    }
}

void sandglass(int row, char ch) {
    for (int i = row; i >= 1; i--) {
        for (int j = 1; j <= row - i; j++) 
            printf(" ");
        for (int j = 1; j <= (2*i - 1); j++) 
            printf("%c", ch);
        printf("\n");
    }
    for (int i = 2; i <= row; i++) {
        for (int j = 1; j <= row - i; j++) 
            printf(" ");
        for (int j = 1; j <= (2*i - 1); j++) 
            printf("%c", ch);
        printf("\n");
    }
}
