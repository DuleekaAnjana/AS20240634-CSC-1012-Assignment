#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 30
#define NAME_LEN 50



 //Function Pototypes
      // City Management
void addCity(char cities[MAX_CITIES][NAME_LEN], int *count);

int main()
{
    char cities[MAX_CITIES][NAME_LEN];
    int count = 0;

    int choice;

    do {

        printf("\n===== Logistics Management System =====\n");
        printf("1. City Management\n");
        printf("2. Distance Management\n");
        printf("3. Delivery Request Handling\n");
        printf("4. Option 4 \n");
        printf("5. Option 5 \n");
        printf("6. Option 6 \n");
        printf("7. Option 7 \n");
        printf("8. Exit Program\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                int choice;
                do {

                    printf("\n\t|``  \t=== City Management ===\t  ``|\n\n");
                    printf("\t| 1. Add new City                   |\n");
                    printf("\t| 2. Rename City                    |\n");
                    printf("\t| 3. Remove City                    |\n");
                    printf("\t| 4. Display Cities                 |\n");
                    printf("\t| 5. Exit                           |\n");

                    printf("\t``````````````````\\ /````````````````\n");

                    printf("\tEnter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {

                        case 1:
                            addCity(cities, &count);
                            break;
                        case 2:
                            //
                            break;
                        case 3:
                            //
                            break;
                        case 4:
                            //
                            break;
                        case 5:
                            //
                            break;
                        default:
                            //

                    }

                 } while (choice != 5);
                 break;

            case 2:
                //
                break;

            case 3:
                //

            case 4:
                //code
                break;

            case 5:
                //code
                break;

            case 6:
                //code
                break;

            case 7:
                //code
                break;

            case 8:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");

        }

    } while (choice != 8);

    return 0;
}

  // City Management
      // Add Cities
void addCity(char cities[MAX_CITIES][NAME_LEN], int *count) {
    char newCity[NAME_LEN];
    int choice;

    do{
        printf("\t\t|==> Add new City\n");
        printf("\tEnter city name: ");
        scanf(" %s", newCity);

        for (int i = 0; i < *count; i++) {
        if (strcmp(cities[i], newCity) == 0) {
            printf("\tCity already exists! Please enter a different name.\n");
            return;
            }
        }

        strcpy(cities[*count], newCity);
        (*count)++;

        printf("\tCity added successfully.\n");

        printf("\tDo you want to add another city? (y/n): ");
        scanf(" %c", &choice);

    }while (choice == 'y' || choice == 'Y');
}

