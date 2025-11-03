#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main()
{


    int choice;

    do {

        printf("\n===== Logistics Management System =====\n");
        printf("1. City Management\n");
        printf("2. Distance Management\n");
        printf("3. Delivery Request Handling\n");
        printf("4. Option three \n");
        printf("5. Option three \n");
        printf("6. Option three \n");
        printf("7. Option three \n");
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
                            renameCity(cities, count);
                            break;
                        case 3:
                            removeCity(cities, &count);
                            break;
                        case 4:
                            printf("\t\t|==> Display Cities\n");
                            displayCities(cities, count);
                            break;
                        case 5:
                            printf("\t\t|==> Exiting to main menu.\n");
                            break;
                        default:
                            printf("Invalid choice! Please try again.\n");

                    }

                 } while (choice != 5);
                 break;

            case 2:
                printf("\n\t|``  \t=== Distance Management ===\t  ``|\n");
                inputDistance(distance, cities, count);
                break;

            case 3:
                printf("\n\t|``  \t=== Delivery Request Handling ===\t  ``|\n");
                handleDeliveryRequest(count, vehicleType, capacity, cities, source, destination, selectVehicleType, weight, selectVehicleTypeStr);
                break;

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
