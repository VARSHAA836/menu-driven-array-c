#include <stdio.h>
#include <conio.h>
#define MAX 100

int arr[MAX];
int n = 0;  // current number of elements

void display() {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insert() {
    if (n >= MAX) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    int value;
    printf("Enter element to insert: ");
    scanf("%d", &value);
    arr[n++] = value;
    printf("%d inserted successfully.\n", value);
}

void deleteElement() {
    if (n == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    int value, index = -1;
    printf("Enter element to delete: ");
    scanf("%d", &value);
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("%d not found in the array.\n", value);
        return;
    }
    
    for (int i = index; i < n - 1; i++)
        arr[i] = arr[i + 1];
    
    n--;
    printf("%d deleted successfully.\n", value);
}

void search() {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    int value, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &value);
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            printf("%d found at position %d.\n", value, i + 1);
            found = 1;
            break;
        }
    }
    
    if (!found)
        printf("%d not found in the array.\n", value);
}

int main() {
    int choice;
    
    do {
        printf("\n===== MENU =====\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Search element\n");
        printf("4. Display array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: insert(); break;
            case 2: deleteElement(); break;
            case 3: search(); break;
            case 4: display(); break;
            case 5: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}
