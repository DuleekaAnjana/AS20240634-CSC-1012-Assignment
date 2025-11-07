#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_CITIES 30
#define NAME_LEN 50
#define MAX_VEHITYPES 3
#define FUEL_PRICE 310.0
#define MAX_DELIVERIES 50

 //Function Pototypes
      // City Management
void addCity(char cities[MAX_CITIES][NAME_LEN], int* cityCount);
void renameCity(char cities[MAX_CITIES][NAME_LEN], int cityCount);
void removeCity(char cities[MAX_CITIES][NAME_LEN], int* cityCount);
void displayCities(char cities[MAX_CITIES][NAME_LEN], int cityCount);

      // Distance Management
void inputDistance(int distance[MAX_CITIES][MAX_CITIES], char cities[][NAME_LEN], int cityCount);
void displayDistances(int distance[MAX_CITIES][MAX_CITIES], char cities[][NAME_LEN], int cityCount);

      // Delivery Requests
int getVehicleType(char vehicleType[MAX_VEHITYPES][10], int capacity[], int *selectVehicleType, char selectVehicleTypeStr[10]);
int getWeight(int *selectVehicleType, char vehicleType[MAX_VEHITYPES][10], int capacity[], char selectVehicleTypeStr[10], int *weight);
int getLocations(int *source, int *destination, char cities[MAX_CITIES][NAME_LEN], int cityCount);
void validateStatus(char deliveryStatus[MAX_DELIVERIES][10], float actualDeliveryTimes[MAX_DELIVERIES], int deliveryCount);
void handleDeliveryRequest(
    int cityCount,
    char vehicleType[MAX_VEHITYPES][10],
    int capacity[],
    char cities[MAX_CITIES][NAME_LEN],
    int *selectVehicleType,
    char selectVehicleTypeStr[10],
    int *source,
    int *destination,
    int *weight,
    int *deliveryCount,
    int sourceArr[MAX_DELIVERIES],
    int destinationArr[MAX_DELIVERIES],
    int weightArr[MAX_DELIVERIES],
    int vehicleArr[MAX_DELIVERIES],
    char deliveryStatus[MAX_DELIVERIES][10],
    float actualDeliveryTimes[MAX_DELIVERIES]
);

  // Calculate Cost
        // Least Distance
int calculatePairDistance (int distance[MAX_CITIES][MAX_CITIES], int source, int city1, int city2, int destination);
int calculateSingleDistance(int distance[MAX_CITIES][MAX_CITIES], int source, int city, int destination);
int findLeastCostRoute(
    int distance[MAX_CITIES][MAX_CITIES],
    int cityList[],
    int cityCount,
    int* routeSize,
    int source,
    int destination,
    int* minDist,
    int bestPair[2],
    int deliveryCount,
    int minDistanceTable[MAX_DELIVERIES][3],
    int* bestOrder
);
       // Calculate Cost
void calculateDeliveryCost(
    int distance[MAX_CITIES][MAX_CITIES],
    char vehicleType[MAX_VEHITYPES][10],
    int cityCount,
    int selectVehicleType,
    int source,
    int destination,
    int weight,
    int capacity[],
    int ratePerKm[],
    int avgSpeed[],
    int fuelEfficiency[],
    int* deliveryCount,
    int deliveryDistances[],
    float deliveryTimes[],
    float deliveryRevenues[],
    float deliveryProfits[],
    int cityList[MAX_CITIES],
    int *routeSize,
    int minDistanceTable[MAX_DELIVERIES][3],
    int bestPair[2],
    int *minDist,
    int *bestOrder,
    float* deliveryCost,
    float* timeHrs,
    int* fuelUsed,
    float* fuelCost,
    float* totalCost,
    float* profit,
    float* customerCharge
);





  // Reports
        // Display Estimation
void displayDeliveryEstimation(
    char cities[MAX_CITIES][NAME_LEN],
    int source,
    int destination,
    int selectVehicleType,
    char vehicleType[MAX_VEHITYPES][10],
    int weight,
    int minDist,
    float deliveryCost,
    float fuelUsed,
    float fuelCost,
    float totalCost,
    float profit,
    float customerCharge,
    float timeHrs
);
        // Display Least Cost Route after Estimation Report
void displayLeastCostRoute(int source, int destination, int routeSize, int minDist, int bestPair[2], int bestOrder);  //// need to update
        // Display Performance Report
void displayDeliverySummary(int deliveryCount, int deliveryDistances[], float deliveryTimes[], float actualDeliveryTimes[], float deliveryRevenues[], float deliveryProfits[], int minDistanceTable[MAX_DELIVERIES][3], char cities[MAX_CITIES][NAME_LEN]);



  // Remaining All Delivery Status
void displayAllDeliveries (int sourceArr[], int destinationArr[], int weightArr[], int vehicleArr[], char vehicleType[][10], int deliveryCount, char deliveryStatus[MAX_DELIVERIES][10]);
void displayAllStoredLeastDistances(int minDistanceTable[MAX_DELIVERIES][3], int deliveryCount, char cities[MAX_CITIES][NAME_LEN]);
void remainAllDeliveryStatus(int sourceArr[], int destinationArr[], int weightArr[], int vehicleArr[], char vehicleType[][10],
char deliveryStatus[MAX_DELIVERIES][10], int deliveryCount, int minDistanceTable[MAX_DELIVERIES][3], char cities[MAX_CITIES][NAME_LEN]);


  //
int main()
{
    char cities[MAX_CITIES][NAME_LEN];
    int cityCount = 0;

    int distance[MAX_CITIES][MAX_CITIES] = {0};

        // Vehicle Management Details
    char vehicleType[MAX_VEHITYPES][10] = {"Van", "Truck", "Lorry"};
    int capacity[] = {1000, 5000, 10000};
    int ratePerKm[] = {30, 40, 80};
    int avgSpeed[] = {60, 50, 45};
    int fuelEfficiency[] = {12, 6, 4};

    // int vechicleDetails[3][4] = {{1000, 30, 60, 12}, {5000, 40, 50, 6}, {10000, 80, 45, 4}};

        //  Delivery Request Handling
    int source, destination, selectVehicleType, weight;
    char selectVehicleTypeStr[10];

        // Calculations
    float deliveryCost;
    float timeHrs;
    int fuelUsed;
    float fuelCost;
    float totalCost;
    float profit;
    float customerCharge;

        // Delivery record arrays
    int deliveryCount = 0;
    int sourceArr[MAX_DELIVERIES];
    int destinationArr[MAX_DELIVERIES];
    int weightArr[MAX_DELIVERIES];
    int vehicleArr[MAX_DELIVERIES];

    int deliveryDistances[MAX_DELIVERIES];
    float deliveryTimes[MAX_DELIVERIES];
    float deliveryRevenues[MAX_DELIVERIES];
    float deliveryProfits[MAX_DELIVERIES];
    char deliveryStatus[MAX_DELIVERIES][10];
    float actualDeliveryTimes[MAX_DELIVERIES];

        // Find Least Cost Route
    int minDist = INT_MAX;
    int bestPair[2] = {-1, -1};
    int bestOrder = 0;
    int minDistanceTable[MAX_DELIVERIES][3];
    int cityList[MAX_CITIES];
    int routeSize = 0;

    int choice;

    do {

        printf("\n===== Logistics Management System =====\n");
        printf("1. City Management\n");
        printf("2. Distance Management\n");
        printf("3. Delivery Request Handling\n");
        printf("4. Delivery Cost Estimation\n");
        printf("5. Display Distance Table\n");
        printf("6. Display Summary of All Diivaries (Performance)\n");
        printf("7. Display Status of all remain Delivaries\n");
        printf("8. Exit Program\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                int cityMenuChoice;
                do {
                    printf("\n\t|``  \t=== City Management ===\t  ``|\n\n");
                    printf("\t| 1. Add new City                   |\n");
                    printf("\t| 2. Rename City                    |\n");
                    printf("\t| 3. Remove City                    |\n");
                    printf("\t| 4. Display Cities                 |\n");
                    printf("\t| 5. Exit                           |\n");

                    printf("\t``````````````````\\ /````````````````\n");

                    printf("\tEnter your choice: ");
                    scanf("%d", &cityMenuChoice);

                    switch (cityMenuChoice) {

                        case 1:
                            addCity(cities, &cityCount);
                            break;
                        case 2:
                            renameCity(cities, cityCount);
                            break;
                        case 3:
                            removeCity(cities, &cityCount);
                            break;
                        case 4:
                            printf("\t\t|==> Display Cities\n");
                            displayCities(cities, cityCount);
                            break;
                        case 5:
                            printf("\t\t|==> Exiting to main menu.\n");
                            break;
                        default:
                            printf("Invalid choice! Please try again.\n");

                    }

                 } while (cityMenuChoice != 5);
                 break;

            case 2:
                printf("\n\t|``  \t=== Distance Management ===\t  ``|\n");
                inputDistance(distance, cities, cityCount);
                break;

            case 3:
                printf("\n\t|``  \t=== Delivery Request ===\t  ``|\n");
            //  handleDeliveryRequest(cityCount, vehicleType, cities, &selectVehicleType, selectVehicleTypeStr, &source, &destination, &weight, &deliveryCount, sourceArr, destinationArr, weightArr, vehicleArr);
            //  handleDeliveryRequest(cityCount, vehicleType, capacity, cities, &selectVehicleType, selectVehicleTypeStr, &source, &destination, &weight, &deliveryCount, sourceArr, destinationArr, weightArr, vehicleArr);
                handleDeliveryRequest(
                    cityCount,
                    vehicleType,
                    capacity,
                    cities,
                    &selectVehicleType,
                    selectVehicleTypeStr,
                    &source,
                    &destination,
                    &weight,
                    &deliveryCount,
                    sourceArr,
                    destinationArr,
                    weightArr,
                    vehicleArr,
                    deliveryStatus,
                    actualDeliveryTimes
                );

                if (deliveryCount > 0) {
                    calculateDeliveryCost(
                        distance,
                        vehicleType,
                        cityCount,
                        selectVehicleType,
                        source,
                        destination,
                        weight,
                        capacity,
                        ratePerKm,
                        avgSpeed,
                        fuelEfficiency,
                        &deliveryCount,
                        deliveryDistances,
                        deliveryTimes,
                        deliveryRevenues,
                        deliveryProfits,
                        cityList,
                        &routeSize,
                        minDistanceTable,
                        bestPair,
                        &minDist,
                        &bestOrder,
                        &deliveryCost,
                        &timeHrs,
                        &fuelUsed,
                        &fuelCost,
                        &totalCost,
                        &profit,
                        &customerCharge
                    );
                }

                break;

            case 4:
                printf("\n\t|``  \t=== DELIVERY COST ESTIMATION ===\t  ``|\n");
                char reportChoice;
                printf("\tDo you want to see DELIVERY COST ESTIMATION REPORT (y/n): ");
                scanf(" %c", &reportChoice);

                if (reportChoice == 'y' || reportChoice == 'Y'){
                    displayDeliveryEstimation(cities, source, destination, selectVehicleType, vehicleType,
                            weight, minDist, deliveryCost, fuelUsed, fuelCost,
                                totalCost, profit, customerCharge, timeHrs);
                    displayLeastCostRoute(source, destination, routeSize, minDist, bestPair, bestOrder);
                }else{
                    printf("\tReturned to main menu--->");
                    choice = 8;
                    continue;
                }
                break;
                                      ////////////////////////////////////////////////////////// above for user
            case 5:
                printf("\n\t|``  \t=== Distance Table ===\t  ``|");
                displayDistances(distance, cities, cityCount);
                break;
                                      ////////////////////////////////////////////////////////// below for admin
            case 6:
                printf("\n\t|``  \t=== PERFORMANCE REPORT ===\t  ``|\n");
                displayDeliverySummary(deliveryCount, deliveryDistances, deliveryTimes,
                       actualDeliveryTimes, deliveryRevenues, deliveryProfits,
                       minDistanceTable, cities);

                break;

            case 7:
                // not in question                                      ///////////////////////////////////////////////// fix later
                // Display details about all remain dilivaries and show all minimum distances between 2 cities
                printf("\n\t|``  \t=== All Delivery Status Details===\t  ``|\n");
                remainAllDeliveryStatus(sourceArr, destinationArr, weightArr, vehicleArr, vehicleType, deliveryStatus, deliveryCount, minDistanceTable, cities);
                break;

            case 8:
                printf("\n\t|``  \t=== Exiting Logistics Management System ===\t  ``|\n");
                printf("\t  Tank for connecting with us!\n");
                printf("\t  Press Any key to Exit!\n");
                break;

            default:
                printf("\n\t|``  \t=== Invalid Choice Entered! ===\t  ``|\n");
                printf("\t  Please try again. Enter Valid Choice*\n");
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

void handleDeliveryRequest(
    int cityCount,
    char vehicleType[MAX_VEHITYPES][10],
    int capacity[],
    char cities[MAX_CITIES][NAME_LEN],
    int* selectVehicleType,
    char selectVehicleTypeStr[10],
    int* source,
    int* destination,
    int* weight,
    int* deliveryCount,
    int sourceArr[MAX_DELIVERIES],
    int destinationArr[MAX_DELIVERIES],
    int weightArr[MAX_DELIVERIES],
    int vehicleArr[MAX_DELIVERIES],
    char deliveryStatus[MAX_DELIVERIES][10],     // store delivery status ("Completed"/"Ongoing")
    float actualDeliveryTimes[MAX_DELIVERIES]      // store actual delivery times if completed ---> use for performance report
    ){


    if (cityCount < 2) {
        printf("\tAt least two cities are required to place a delivery order.\n");
        return;
    }

    if (*deliveryCount >= MAX_DELIVERIES) {
        printf("\nCannot add more deliveries. Maximum reached (%d)\n", MAX_DELIVERIES);
        return;
    }
    // used  ----->
    //int source, destination, selectVehicleType, weight;
    //char selectVehicleTypeStr[10];

    printf("\n\t\t--- Delivery Request ---\n");

    int selctVehiTyp = getVehicleType(vehicleType, capacity, selectVehicleType, selectVehicleTypeStr);
    if (selctVehiTyp == -1){
        printf("\tReturned to main menu--->\n");
        return; // user cancelled
    }
    *selectVehicleType = selctVehiTyp;
    // (*selectVehicleType)--


    int entrWeight = getWeight(selectVehicleType, vehicleType, capacity, selectVehicleTypeStr, weight);
    if (entrWeight == -1){
        printf("\tReturned to main menu--->\n");
        return; // user cancelled
    }
    *weight = entrWeight;

    if (!getLocations(source, destination, cities, cityCount)){
        printf("\tReturned to main menu--->\n");
        return; // user returned to main menu
    }

            // store delivery data in arrays
    sourceArr[*deliveryCount] = *source;
    destinationArr[*deliveryCount] = *destination;
    weightArr[*deliveryCount] = *weight;
    vehicleArr[*deliveryCount] = *selectVehicleType - 1;

    (*deliveryCount)++;

    printf("\n\t\t===Delivery request accepted!===\n");
    printf("\tDelivery added successfully! Total deliveries: %d\n", *deliveryCount);
    printf("\t\t->From City #%d %s => City #%d %s\n", *source + 1, cities[*source],  *destination + 1, cities[*destination]);
    printf("\t\t->Weight: %d kg\n", *weight);
    printf("\t\t->Vehicle Type: %s\n", selectVehicleTypeStr);

    char choice;
    printf("\tDo you want to Update Delivery Status? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y')
         ////////// call for Validate Delivery Status
        validateStatus(deliveryStatus, actualDeliveryTimes, *deliveryCount);
}





//-------------------------------------------------------------------------------------------------------------------------------------------------
   // Cost Calculations
     // Least Distance
         // Calculate distance for route: source -> city 1 -> city 2 -> destination
int calculatePairDistance(int distance[MAX_CITIES][MAX_CITIES], int source, int city1, int city2, int destination) {
    return distance[source][city1] + distance[city1][city2] + distance[city2][destination];
}

        // Calculate distance for one-stop route: source -> city -> destination
int calculateSingleDistance(int distance[MAX_CITIES][MAX_CITIES], int source, int city, int destination) {
    return distance[source][city] + distance[city][destination];
}

       //function to find least-cost (least-distance) route
int findLeastCostRoute(
    int distance[MAX_CITIES][MAX_CITIES],
    int cityList[],
    int cityCount,
    int* routeSize,
    int source,
    int destination,
    int* minDist,
    int bestPair[2],
    int deliveryCount,
    int minDistanceTable[MAX_DELIVERIES][3],
    int* bestOrder
    ){

    for (int i = 0; i < deliveryCount; i++) {
        int storedSrc = minDistanceTable[i][0];
        int storedDst = minDistanceTable[i][1];
        int storedDist = minDistanceTable[i][2];

        if ((storedSrc == source && storedDst == destination) || (storedSrc == destination && storedDst == source)) {
            *minDist = storedDist;
            return *minDist;   //
        }
    }

   /* int bestCity = -1;
      bestOrder      // if (remain only 2 cities) ---------> 0 = direct
                       // if (remain only 3 cities) ---------> 0 = direct / 1 = source -> Only 1 intermediate city -> destrination
                       // if (remain more than 3 cities) ----> 0 = direct / 1 = source -> city1 -> city2 ->  destrination / 2 = source -> city2 -> city1 ->  destrination   */


    *routeSize = 0;
    for (int i = 0; i < cityCount; i++) {
        if (i != source && i != destination) {
            cityList[(*routeSize)++] = i;
        }
    }

    int directDist = distance[source][destination];
    *minDist = directDist;
    //bestOrder = 0;


    if (*routeSize == 1) {
        int city = cityList[0];
        int oneDist = calculateSingleDistance(distance, source, city, destination);

        if (oneDist < *minDist) {
            *minDist = oneDist;
            bestPair[0] = city;
            //bestOrder = 1;
        }
    }else if (*routeSize >= 2) {
        for (int i = 0; i < *routeSize; i++) {
            for (int j = i + 1; j < *routeSize; j++) {
                int city1 = cityList[i];
                int city2 = cityList[j];

                int d1 = calculatePairDistance(distance, source, city1, city2, destination);
                int d2 = calculatePairDistance(distance, source, city2, city1, destination);

                if (d1 < *minDist) {
                    *minDist = d1;
                    bestPair[0] = city1;
                    bestPair[1] = city2;
                    *bestOrder = 1;
                }
                if (d2 < *minDist) {
                    *minDist = d2;
                    bestPair[0] = city2;
                    bestPair[1] = city1;
                    *bestOrder = 2;
                }
            }
        }
    }

    if (deliveryCount < MAX_DELIVERIES) {
        minDistanceTable[deliveryCount][0] = source;
        minDistanceTable[deliveryCount][1] = destination;
        minDistanceTable[deliveryCount][2] = *minDist;
        //(*deliveryCount)++;
    }

    return *minDist;
}


      // Calculate Delivery Cost
void calculateDeliveryCost(
    int distance[MAX_CITIES][MAX_CITIES],
    char vehicleType[MAX_VEHITYPES][10],
    int cityCount,
    int selectVehicleType,
    int source,
    int destination,
    int weight,
    int capacity[],
    int ratePerKm[],
    int avgSpeed[],
    int fuelEfficiency[],
    int* deliveryCount,
    int deliveryDistances[],
    float deliveryTimes[],
    float deliveryRevenues[],
    float deliveryProfits[],
    int cityList[MAX_CITIES],
    int* routeSize,
    int minDistanceTable[MAX_DELIVERIES][3],
    int bestPair[2],
    int* minDist,
    int* bestOrder,
    float* deliveryCost,
    float* timeHrs,
    int* fuelUsed,
    float* fuelCost,
    float* totalCost,
    float* profit,
    float* customerCharge
    ) {

    int index = selectVehicleType - 1;

    if (index < 0 || index >= MAX_VEHITYPES) {
        printf("\tInvalid vehicle type!\n");
        return;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////// check if delivery count zero


    // int D = distance[source][destination]; // previous

    int leastDist = findLeastCostRoute(distance, cityList, cityCount, routeSize, source, destination, minDist, bestPair, *deliveryCount, minDistanceTable, bestOrder);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////  fix it later
    /* -------------------------------------------------
    if (leastDist <= 0) {
        printf("\tInvalid or missing distance between these cities!-->Can't Calculate cost!\n");
        return;
    }
   ------------------------------------------------------- */

    int D = leastDist;
    int W = weight;
    int R = ratePerKm[index];
    int E = fuelEfficiency[index];
    int S = avgSpeed[index];

            // calculations

        // Delivery Cost:
    *deliveryCost = D * R * (1 + (W / 10000.0));

        // Estimated Delivery Time
    *timeHrs = (float)D / S;

        // Fuel Used
    *fuelUsed = D / E;

        // Fuel Cost
    *fuelCost = *fuelUsed * FUEL_PRICE;

        // Total Cost
    *totalCost = *deliveryCost + *fuelCost;

        // profit
    *profit = *deliveryCost * 0.25;

        // Customer Carge
    *customerCharge = *totalCost + *profit;

        // --- Store results ---                    )
    int rsltStoreIdx = *deliveryCount - 1;
    if (rsltStoreIdx >= 0 && rsltStoreIdx < MAX_DELIVERIES) {
        deliveryDistances[rsltStoreIdx] = D;
        deliveryTimes[rsltStoreIdx] = *timeHrs;
        deliveryRevenues[rsltStoreIdx] = *customerCharge;
        deliveryProfits[rsltStoreIdx] = *profit;
    } else {
        printf("\n \tWarning: cannot store delivery results (invalid index %d)\n \tCheck DeliveryCount %d\n", rsltStoreIdx, *deliveryCount);
    }

}
    /*
        // Display Results------>

    printf("\n\t\t--- Delivery Delivery Summary ---\n");
    printf("\t\t=========================\n");
    printf("Vehicle Type: %s\n", vehicleType[index]);
    printf("Distance (km): %d\n", D);
    printf("Weight (kg): %d\n", W);
    printf("Rate per km: %d LKR\n", ratePerKm[index]);
    printf("Speed: %d km/h\n", S);
    printf("Efficiency: %d km/l\n", E);
    printf("Fuel Price: %.2f LKR/liter\n", FUEL_PRICE);
    printf("-------------------------------------------\n");
    printf("Delivery Cost: %.2f LKR\n", deliveryCost);
    printf("Fuel Used: %d liters\n", fuelUsed);
    printf("Fuel Cost: %.2f LKR\n", fuelCost);
    printf("Total Operational Cost: %.2f LKR\n", totalCost);
    printf("Profit (25/%): %.2f LKR\n", profit);
    printf("Final Customer Charge: %.2f LKR\n", customerCharge);
    printf("Estimated Delivery Time: %.2f hours\n", timeHrs);
    */



 //-----------------------------------------------------------------------------------------------------------------------------------------------------
    // Reports
void displayDeliveryEstimation(
    char cities[MAX_CITIES][NAME_LEN],
    int source,
    int destination,
    int selectVehicleType,
    char vehicleType[MAX_VEHITYPES][10],
    int weight,
    int minDist,
    float deliveryCost,
    float fuelUsed,
    float fuelCost,
    float totalCost,
    float profit,
    float customerCharge,
    float timeHrs
    ) {
        /////////////////////////////////////////////////////////////////////// wants to add checkings citycount > 2 and delivery count < 0
    printf("\n\t======================================================\n");
    printf("\t\tDELIVERY COST ESTIMATION\n");
    printf("\t------------------------------------------------------\n");
    printf("\tFrom: %s\n", cities[source]);
    printf("\tTo: %s\n", cities[destination]);
    printf("\tMinimum Distance: %d km\n", minDist);
    printf("\tVehicle: %s\n", vehicleType[selectVehicleType - 1]);
    printf("\tWeight: %d kg\n", weight);
    printf("\t------------------------------------------------------\n");
    printf("\tBase Cost: %.2f LKR\n", deliveryCost);
    printf("\tFuel Used: %.2f L\n", fuelUsed);
    printf("\tFuel Cost: %.2f LKR\n", fuelCost);
    printf("\tOperational Cost: %.2f LKR\n", totalCost);
    printf("\tProfit: %.2f LKR\n", profit);
    printf("\tCustomer Charge: %.2f LKR\n", customerCharge);
    printf("\tEstimated Time: %.2f hours\n", timeHrs);
    printf("\t======================================================\n");
}

            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////// need to update
    // Display minimum Distant
void displayLeastCostRoute(int source, int destination, int routeSize, int minDist, int bestPair[2], int bestOrder){

    printf("\n\t\t===== Least-Cost Route =====\n");
    printf("\tMinimum Distance: %d\n", minDist);

    if (routeSize == 0)
        printf("\tBest Route: %d => %d\n", source + 1, destination + 1);
    else if (routeSize == 1)
        printf("\tBest Route: %d => %d => %d\n", source + 1, bestPair[0] + 1, destination + 1);
    else if (routeSize >= 2) {
        if (bestOrder == 1)
            printf("\tBest Route: %d => %d => %d => %d\n", source + 1, bestPair[0] + 1, bestPair[1] + 1, destination + 1);
        else
            printf("\tBest Route: %d => %d => %d => %d\n", source + 1, bestPair[1] + 1, bestPair[0] + 1, destination + 1);
    }
}





//----------------------------------------------------------------------------------------------------------------------------------------------------
    // Performance Report
void displayDeliverySummary(int deliveryCount, int deliveryDistances[], float deliveryTimes[], float actualDeliveryTimes[], float deliveryRevenues[], float deliveryProfits[], int minDistanceTable[MAX_DELIVERIES][3], char cities[MAX_CITIES][NAME_LEN]) {

    if (deliveryCount == 0) {
        printf("\n\tNo deliveries have been completed yet.\n");
        return;
    }

    int totalDistance = 0;
    float estTotalTime = 0.0, actualTotalTime = 0.0;
    float totalRevenue = 0.0, totalProfit = 0.0;
    int longest = 0, shortest = INT_MAX;
    int longSrc = -1, longDst = -1, shortSrc = -1, shortDst = -1;

    for (int i = 0; i < deliveryCount; i++) {
        totalDistance += deliveryDistances[i];
        estTotalTime += deliveryTimes[i];
        actualTotalTime += actualDeliveryTimes[i];
        totalRevenue += deliveryRevenues[i];
        totalProfit += deliveryProfits[i];

        int src = minDistanceTable[i][0];
        int dst = minDistanceTable[i][1];
        int dist = minDistanceTable[i][2];

        if (dist > longest) {
            longest = dist;
            longSrc = src;
            longDst = dst;
        }
        if (dist < shortest) {
            shortest = dist;
            shortSrc = src;
            shortDst = dst;
        }
    }

    float avgEstTime = estTotalTime / deliveryCount;
    float avgActualTime = actualTotalTime / deliveryCount;


    printf("\n\t\t===== Overall Delivery Performance Summary =====\n");

    printf("\tTotal Deliveries Completed  : %d\n", deliveryCount);
    printf("\tTotal Distance Covered      : %d km\n", totalDistance);
    printf("\tAverage Estimated Time      : %.2f hours\n", avgEstTime);
    printf("\tAverage Actual Time         : %.2f hours\n", avgActualTime);
    printf("\tTotal Revenue               : Rs. %.2f\n", totalRevenue);
    printf("\tTotal Profit                : Rs. %.2f\n", totalProfit);

    if (longSrc != -1 && longDst != -1)
        printf("\tLongest Route               : %s => %s  (%d km)\n", cities[longSrc], cities[longDst], longest);

    if (shortSrc != -1 && shortDst != -1)
        printf("\tShortest Route              : %s => %s  (%d km)\n", cities[shortSrc], cities[shortDst], shortest);

    printf("\t\t=================================================\n");
}


  // Display Renaining All Delivery Status
      // Function to display all deliveries
void displayAllDeliveries(int sourceArr[], int destinationArr[], int weightArr[], int vehicleArr[], char vehicleType[][10], int deliveryCount, char deliveryStatus[MAX_DELIVERIES][10]) {

    if (deliveryCount == 0) {
        printf("\n\tNo deliveries recorded yet.\n");
        return;
    }


    printf("\n\t%-5s %-10s %-12s %-8s %-10s %-12s\n", "No", "Source", "Destination", "Weight", "Vehicle", "Status");
    printf("\t--------------------------------------------------------------------------\n");


    for (int i = 0; i < deliveryCount; i++) {
        printf("\t%-5d %-10d %-12d %-8d %-10s %-12s\n",
               i + 1,
               sourceArr[i],
               destinationArr[i],
               weightArr[i],
               vehicleType[vehicleArr[i]],
               deliveryStatus[i]);
    }
}
      // Display All Least Distances
void displayAllStoredLeastDistances(int minDistanceTable[MAX_DELIVERIES][3], int deliveryCount, char cities[MAX_CITIES][NAME_LEN]) {

    printf("\n\t\t===== Stored Minimum Distances =====\n");

    if (deliveryCount == 0) {
        printf("\tNo stored routes found!\n");
        return;
    }

    printf("\t%-5s %-20s %-20s %-10s\n", "No.", "Source City", "Destination City", "Min Dist (km)");
    printf("\t---------------------------------------------------------------\n");

    for (int i = 0; i < deliveryCount; i++) {
        int src = minDistanceTable[i][0];
        int dst = minDistanceTable[i][1];
        int dist = minDistanceTable[i][2];

        printf("\t%-5d %-20s (%2d) %-20s (%2d) %-10d\n",
               i + 1,
               cities[src], src + 1,
               cities[dst], dst + 1,
               dist);
    }

    printf("\t---------------------------------------------------------------\n");
}

      // // Renaining All Delivery Status Using above 2
void remainAllDeliveryStatus(int sourceArr[], int destinationArr[], int weightArr[], int vehicleArr[], char vehicleType[][10],
    char deliveryStatus[MAX_DELIVERIES][10], int deliveryCount, int minDistanceTable[MAX_DELIVERIES][3], char cities[MAX_CITIES][NAME_LEN]) {

    printf("\n\t\t===== REMAINING DELIVERY STATUS =====\n");

    if (deliveryCount == 0) {
        printf("\tNo deliveries available to display.\n");
        return;
    }


    printf("\n\t--- Delivery Records ---\n");
    displayAllDeliveries(
        sourceArr,
        destinationArr,
        weightArr,
        vehicleArr,
        vehicleType,
        deliveryCount,
        deliveryStatus
    );


    printf("\n\t--- Stored Minimum Distances ---\n");
    displayAllStoredLeastDistances(
        minDistanceTable,
        deliveryCount,
        cities
    );

    printf("\n\t===== End of Delivery Summary =====\n");
}






//







