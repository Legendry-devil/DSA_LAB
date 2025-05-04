#include <iostream>
#include <cstdlib>
#include "roundrobin.h"  

using namespace std;

int main() {
    int fixedTime;
    printf("Enter the fixed time for process execution: ");
    scanf("%d", &fixedTime);

    list queue(fixedTime);

    int choice, time;
    do {
        printf("\n1. Insert Process\n2. Execute\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter process time: ");
                scanf("%d", &time);
                queue.insertProcess(time);
                break;
            case 2:
                queue.execute();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
