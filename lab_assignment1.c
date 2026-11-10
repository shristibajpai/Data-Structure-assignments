#include <stdio.h>


int main() {

    int marks[100], n = 0, i, choice, pos, value;

    int low, high, mid, temp, found;


    do {

        printf("\n----- MENU -----\n");

        printf("1. Insert Marks\n");

        printf("2. Delete Mark\n");

        printf("3. Display Marks\n");

        printf("4. Linear Search\n");

        printf("5. Sort and Binary Search\n");

        printf("6. Exit\n");

        printf("Enter your choice: ");

        scanf("%d", &choice);


        switch(choice) {


            case 1:

                printf("Enter number of students: ");

                scanf("%d", &n);


                printf("Enter marks:\n");

                for(i = 0; i < n; i++) {

                    scanf("%d", &marks[i]);

                }

                break;


            case 2:

                printf("Enter position to delete (1-%d): ", n);

                scanf("%d", &pos);


                if(pos < 1 || pos > n) {

                    printf("Invalid Position!\n");

                } else {

                    for(i = pos - 1; i < n - 1; i++) {

                        marks[i] = marks[i + 1];

                    }

                    n--;

                    printf("Mark deleted successfully.\n");

                }

                break;


            case 3:

                if(n == 0) {

                    printf("No marks available.\n");

                } else {

                    printf("Student Marks:\n");

                    for(i = 0; i < n; i++) {

                        printf("%d ", marks[i]);

                    }

                    printf("\n");

                }

                break;


            case 4:

                printf("Enter mark to search: ");

                scanf("%d", &value);


                found = 0;

                for(i = 0; i < n; i++) {

                    if(marks[i] == value) {

                        printf("Mark found at position %d\n", i + 1);

                        found = 1;

                        break;

                    }

                }


                if(!found)

                    printf("Mark not found.\n");

                break;


            case 5:

                // Sorting using Bubble Sort

                for(i = 0; i < n - 1; i++) {

                    int j;

                    for(j = 0; j < n - i - 1; j++) {

                        if(marks[j] > marks[j + 1]) {

                            temp = marks[j];

                            marks[j] = marks[j + 1];

                            marks[j + 1] = temp;

                        }

                    }

                }


                printf("Sorted Marks:\n");

                for(i = 0; i < n; i++) {

                    printf("%d ", marks[i]);

                }

                printf("\n");


                printf("Enter mark to search: ");

                scanf("%d", &value);


                low = 0;

                high = n - 1;

                found = 0;


                while(low <= high) {

                    mid = (low + high) / 2;


                    if(marks[mid] == value) {

                        printf("Mark found at position %d (Sorted Array)\n", mid + 1);

                        found = 1;

                        break;

                    } else if(marks[mid] < value) {

                        low = mid + 1;

                    } else {

                        high = mid - 1;

                    }

                }


                if(!found)

                    printf("Mark not found.\n");

                break;


            case 6:

                printf("Exiting Program...\n");

                break;


            default:

                printf("Invalid Choice!\n");

        }


    } while(choice != 6);


    return 0;

} 