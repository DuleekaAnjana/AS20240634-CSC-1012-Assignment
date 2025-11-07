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

//---------------------------------------------------------------------------------------------------------------------------------------------
  // City Management
      // Add Cities
void addCity(char cities[MAX_CITIES][NAME_LEN], int *cityCount) {
    char newCity[NAME_LEN];
    char choice;

    do{
        printf("\t\t|==> Add new City\n");
        printf("\tEnter city name: ");
        scanf(" %s", newCity);

        for (int i = 0; i < *cityCount; i++) {
        if (strcmp(cities[i], newCity) == 0) {
            printf("\tCity already exists! Please enter a different name.\n");
            return;
            }
        }

        strcpy(cities[*cityCount], newCity);
        (*cityCount)++;

        printf("\tCity added successfully.\n");

        printf("\tDo you want to add another city? (y/n): ");
        scanf(" %c", &choice);

    }while (choice == 'y' || choice == 'Y');
}


      // Rename City
void renameCity(char cities[MAX_CITIES][NAME_LEN], int cityCount) {
    char choice;

    do{
        printf("\t\t|==> Rename City\n");
        displayCities(cities, cityCount);

        int index;
        printf("\tEnter city number to rename (1-%d): ", cityCount);
        scanf("%d", &index);

        if (index > 0 && index <= cityCount) {
            printf("\tEnter new name: ");
            scanf("%s", cities[index - 1]);

            printf("\tCity renamed successfully.\n");
        }else{
            printf("\tInvalid city number! Please enter remainig city number\n");
        }

        printf("\tDo you want to rename another city? (y/n): ");
        scanf(" %c", &choice);

    }while (choice == 'y' || choice == 'Y');
}

      // Remove City
void removeCity(char cities[MAX_CITIES][NAME_LEN], int *cityCount) {
    char choice;

    do{
        printf("\t\t|==> Remove City\n");
        displayCities(cities, *cityCount);

        int index;
        printf("\tEnter city number to remove (1-%d): ", *cityCount);
        scanf("%d", &index);

        if (index > 0 && index <= *cityCount) {
            for (int i = index - 1; i < *cityCount - 1; i++) {
            strcpy(cities[i], cities[i + 1]);
            }

            (*cityCount)--;
            printf("\tCity removed successfully.\n");
        }else{
            printf("\tInvalid city number! Please enter remainig city number\n");
        }

        printf("\tDo you want to remove another city? (y/n): ");
        scanf(" %c", &choice);

    }while (choice == 'y' || choice == 'Y');
}


      // Display Cities
void displayCities(char cities[MAX_CITIES][NAME_LEN], int cityCount) {
    printf("\tRemaining Cities:\n");
    for (int i = 0; i < cityCount; i++) {
        printf("\t\t%d. %s\n", i + 1, cities[i]);
    }
}



//-----------------------------------------------------------------------------------------------------------------------------------------------
  // Distance Management
      // Enter or Edit Distances
void inputDistance(int distance[MAX_CITIES][MAX_CITIES], char cities[][NAME_LEN], int cityCount) {
    int i, j, d;
    char choice;

    do{
        printf("\t  |==> Enter or Edit Distances Between Cities ---\n");

        printf("\n\t\t|==> Display Cities\n");
        printf("\t\t");
        displayCities(cities, cityCount);

        displayDistances(distance, cities, cityCount);

        if (cityCount < 2) {
            printf("\tAt least two cities required to enter distances.\n");
            printf("\tChoose Choice No 1 from main menu and Enter at least 2 cities.\n");
            return;
        }

        printf("\n\tEnter city numbers to update distance (e.g. 1 or 2)\\/\n");

        printf("\tEnter 1'st City NO=> From : ");
        scanf("%d", &i);

        printf("\tEnter 2'nd City NO=> To   : ");
        scanf("%d", &j);

        /*
        if (i == 0 && j == 0)
            break;
        */

        if (i < 1 || i > cityCount || j < 1 || j > cityCount) {
            printf("\tInvalid city numbers!\n");
            printf("\tPlease reenter valied 2 different cities\n");

            printf("\tDo you want to continoue? (y-for enter distance/n-for return to main menu): ");
            scanf(" %c", &choice);

            if (choice == 'y' || choice == 'Y')
                continue;
            else{
                printf("\tReturned to main menu--->");
                return;
            }
        }

        if (i == j) {
            printf("\tDistance from a city to itself must be 0.! Please reenter valied another 2 different cities\n");

            printf("\tDo you want to continoue? (y-for enter distance/n-for return to main menu): ");
            scanf(" %c", &choice);

            if (choice == 'y' || choice == 'Y')
                continue;
            else{
                printf("\tReturned to main menu--->");
                return;
            }
        }
//
        if (distance[i - 1][j - 1] != 0) {
            printf("\tDistance between %s and %s is already entered (%d km).\n", cities[i - 1], cities[j - 1], distance[i - 1][j - 1]);
            //printf("\tPlease re-enter another 2 different cities for distance.\n");

            printf("\tDo you want to edit them? (y-for enter distance/n-for return to main menu): ");
            scanf(" %c", &choice);

            if (choice == 'y' || choice == 'Y'){
                printf("\tEnter new distance between %s and %s: ", cities[i - 1], cities[j - 1]);
                scanf("%d", &d);

                distance[i - 1][j - 1] = d;
                distance[j - 1][i - 1] = d;

                printf("\n\tUpdated: %s <=> %s = %d km\n", cities[i - 1], cities[j - 1], d);

                printf("\n\tUpdated distance table:-->\n");
                displayDistances(distance, cities, cityCount);

                printf("\tDo you want to Enter or Edit Distances Between another Cities? (y/n): ");
                scanf(" %c", &choice);

                if (choice == 'y' || choice == 'Y')
                    continue;
                else{
                    printf("\tReturned to main menu--->");
                    return;
                }
            }else{
                printf("\tDo you want to Enter or Edit Distances Between another Cities? (y/n): ");
                scanf(" %c", &choice);

                if (choice == 'y' || choice == 'Y')
                    continue;
                else{
                    printf("\tReturned to main menu--->");
                    return;
                }
            }
        }

        printf("\tEnter distance between %s and %s: ", cities[i - 1], cities[j - 1]);
        scanf("%d", &d);

        distance[i - 1][j - 1] = d;
        distance[j - 1][i - 1] = d;

        printf("\n\tUpdated: %s <=> %s = %d km\n", cities[i - 1], cities[j - 1], d);

        printf("\n\tUpdated distance table:-->\n");
        displayDistances(distance, cities, cityCount);

        printf("\tDo you want to Enter or Edit Distances Between another Cities? (y/n): ");
        scanf(" %c", &choice);

        printf("\n\n");

    }while (choice == 'y' || choice == 'Y');
}


void displayDistances(int distance[MAX_CITIES][MAX_CITIES], char cities[][NAME_LEN], int cityCount) {
    if (cityCount == 0) {
        printf("\tNo cities to display.\n");
        return;
    }

    /*
    printf("\n\t\t|==> Display Cities\n");
    printf("\t\t");
    displayCities(cities, cityCount);
    */

    printf("\n");

    printf("\n\t%-15s", "City");
    for (int i = 0; i < cityCount; i++)
        printf("%-15s", cities[i]);

    printf("\n");

    for (int i = 0; i < cityCount; i++) {
        printf("\t%-15s", cities[i]);
        for (int j = 0; j < cityCount; j++) {
            if (i == j)
                printf("%-15d", 0);
            else
                printf("%-15d", distance[i][j]);
        }
        printf("\n");
    }
}





//----------------------------------------------------------------------------------------------------------------------------------------
  // Delivery Request Management
    // To add new request
int getVehicleType(char vehicleType[MAX_VEHITYPES][10], int capacity[], int* selectVehicleType, char selectVehicleTypeStr[10]) {
    char retryVehicle = 'y';

    do {
        printf("\n\tAvailable vehicle types & Max Capacities:\n");
        for (int i = 0; i < MAX_VEHITYPES; i++) {
            printf("\t  %d. %-10s : %-5d\n", i + 1, vehicleType[i], capacity[i]);
        }

        printf("\n\tEnter vehicle type (1=Van, 2=Truck, 3=Lorry): ");
        scanf("%d", selectVehicleType);

        if (*selectVehicleType < 1 || *selectVehicleType > MAX_VEHITYPES) {
            printf("\tInvalid vehicle type number!\n");
            printf("\tDo you want to try again? (y/n): ");
            scanf(" %c", &retryVehicle);
            /*if (retryVehicle == 'n' || retryVehicle == 'N') {
                printf("\tReturned to main menu--->\n");
                return -1; // cancelled
            }*/
        } else {
            // Valid vehicle — copy its name and return
            strcpy(selectVehicleTypeStr, vehicleType[*selectVehicleType - 1]);
            return *selectVehicleType;
        }

    } while (retryVehicle == 'y' || retryVehicle == 'Y');

    //printf("\n\tReturned to main menu--->\n");
    return -1;
}

int getWeight(int *selectVehicleType, char vehicleType[MAX_VEHITYPES][10], int capacity[], char selectVehicleTypeStr[10], int* weight){

    char retryWeight;

    do {
        printf("\tEnter parcel weight (in kg --> round nearest kg): ");
        scanf("%d", weight);

        if (*weight <= 0) {
            printf("\tWeight must be greater than 0!\n");
            printf("\tDo you want to re-enter weight? (y/n): ");
            scanf(" %c", &retryWeight);
            continue;
        }
        else if (*weight > capacity[*selectVehicleType - 1]) {
            printf("\t\tWeight exceeds the capacity for this vehicle type (%s -->max %d kg).\n",
                   selectVehicleTypeStr, capacity[*selectVehicleType - 1]);

            printf("\tDo you want to change (1) Vehicle or (2) Weight? Enter 1 or 2: ");
            int option;
            scanf("%d", &option);

            if (option == 1) {
                // Change vehicle type
                int newType = getVehicleType(vehicleType, capacity, selectVehicleType, selectVehicleTypeStr);
                if (newType == -1) {
                    //printf("\tReturned to main menu--->\n");
                    return -1;
                }
                *selectVehicleType = newType;
                retryWeight = 'y';
                continue; // check weight again for new vehicle
            }
            else if (option == 2) {
                retryWeight = 'y';
                continue; // re-enter weight
            }
            else {
                //printf("\tInvalid choice! Returning to main menu.\n");
                return -1;
            }
        }
        else {
            // Valied Weight
            return *weight;
        }

    } while (retryWeight == 'y' || retryWeight == 'Y');

    return -1;
}

int getLocations(int *source, int *destination, char cities[MAX_CITIES][NAME_LEN], int cityCount) {
    char retryCities = 'n';

    if (cityCount < 2) {
        printf("\tAt least two cities are required to select source and destination.\n");
        return 0;
    }

    do {

        printf("\n\t\t|==> Display Cities\n");
        displayCities(cities, cityCount);

        printf("\n\tEnter source city index (1-%d): ", cityCount);
        scanf("%d", source);
        printf("\tEnter destination city index (1-%d): ", cityCount);
        scanf("%d", destination);

        // Validation 1: same city
        if (*source == *destination) {
            printf("\t\tSource and destination cannot be the same!\n");
            printf("\tDo you want to try another two cities? (y/n): ");
            scanf(" %c", &retryCities);
            if (retryCities == 'y' || retryCities == 'Y')
                continue;
            else {
                //printf("\tReturned to main menu--->\n");
                return 0; // user give up
            }
        }

        // Validation 2: out of range
        if (*source < 1 || *source > cityCount || *destination < 1 || *destination > cityCount) {
            printf("\t\tInvalid city numbers!\n");
            printf("\tDo you want to try another two cities? (y/n): ");
            scanf(" %c", &retryCities);
            if (retryCities == 'y' || retryCities == 'Y')
                continue;
            else {
                //printf("\tReturned to main menu--->\n");
                return 0; // user give up
            }
        }

    } while (retryCities == 'y' || retryCities == 'Y');

    // reset
    *source -= 1;
    *destination -= 1;

    return 1; // success
}

void validateStatus(char deliveryStatus[MAX_DELIVERIES][10], float actualDeliveryTimes[MAX_DELIVERIES], int deliveryCount) {
    if (deliveryCount == 0) {
        printf("\n\tNo deliveries to update!\n");
        return;
    }

    printf("\n\t\t=== Validate Delivery Status ===\n");

        // Ask for status
    printf("\tEnter status (1=Ongoing, 2=Completed): ");
    int statusChoice;
    scanf("%d", &statusChoice);

    int i = 0;
    if (statusChoice == 1) {
        strcpy(deliveryStatus[i], "Ongoing");
            //deliveryTimes[i] = 0;  // No time yet
    }else if (statusChoice == 2) {
        strcpy(deliveryStatus[i], "Completed");
        printf("\tEnter actual delivery time (in hours): ");
        scanf(" %f", &actualDeliveryTimes[i]);

    }else {
        printf("\tInvalid choice! Marked as Ongoing by default.\n");
        strcpy(deliveryStatus[i], "Ongoing");
            //deliveryTimes[i] = 0;
    }

    printf("\n\tDelivery statuses updated successfully!\n");
}






