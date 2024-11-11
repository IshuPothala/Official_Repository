#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Original structure definition
struct Employee {
    int id;
    char firstName[50];
    char lastName[50];
    char designation[50];
    char address[100];
    float salary;
};

// Typedef for structure to avoid using 'struct' keyword
typedef struct Employee e1;

// Function to scan employee records
void scanEmployeeRecords(e1 employees[], int *count) {
    int n;
    printf("Enter number of employees to add: ");
    scanf("%d", &n);
    *count = n;

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &employees[i].id);
        
        printf("First Name: ");
        scanf("%s", employees[i].firstName);

        printf("Last Name: ");
        scanf("%s", employees[i].lastName);

        printf("Designation: ");
        scanf("%s", employees[i].designation);

        printf("Address: ");
        scanf(" %[^\n]", employees[i].address); // This reads the entire line including spaces

        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }
}

// Function to display employee records
void displayEmployees(e1 employees[], int count) {
    printf("\nEmployee Records:\n");
    for (int i = 0; i < count; i++) {
        printf("\nEmployee %d\n", i + 1);
        printf("ID: %d\n", employees[i].id);
        printf("Name: %s %s\n", employees[i].firstName, employees[i].lastName);
        printf("Designation: %s\n", employees[i].designation);
        printf("Address: %s\n", employees[i].address);
        printf("Salary: %.2f\n", employees[i].salary);
    }
}

// Function to search for an employee by ID
void searchById(e1 employees[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("\nEmployee Found (ID: %d):\n", id);
            printf("Name: %s %s\n", employees[i].firstName, employees[i].lastName);
            printf("Designation: %s\n", employees[i].designation);
            printf("Address: %s\n", employees[i].address);
            printf("Salary: %.2f\n", employees[i].salary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

// Function to search for an employee by Last Name
void searchByLastName(e1 employees[], int count, char lastName[]) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].lastName, lastName) == 0) {
            if (!found) {
                printf("\nEmployees with Last Name %s:\n", lastName);
            }
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s %s\n", employees[i].firstName, employees[i].lastName);
            printf("Designation: %s\n", employees[i].designation);
            printf("Address: %s\n", employees[i].address);
            printf("Salary: %.2f\n\n", employees[i].salary);
            found = 1;
        }
    }
    if (!found) {
        printf("No employees found with the last name %s.\n", lastName);
    }
}

// Function to search for employees within a salary range
void searchBySalaryRange(e1 employees[], int count, float minSalary, float maxSalary) {
    int found = 0;
    printf("\nEmployees with salary between %.2f and %.2f:\n", minSalary, maxSalary);
    for (int i = 0; i < count; i++) {
        if (employees[i].salary >= minSalary && employees[i].salary <= maxSalary) {
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s %s\n", employees[i].firstName, employees[i].lastName);
            printf("Designation: %s\n", employees[i].designation);
            printf("Address: %s\n", employees[i].address);
            printf("Salary: %.2f\n\n", employees[i].salary);
            found = 1;
        }
    }
    if (!found) {
        printf("No employees found with salary in the specified range.\n");
    }
}

// Function to update an employee's last name
void updateLastName(e1 employees[], int count, int id, char newLastName[]) {
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            strcpy(employees[i].lastName, newLastName);
            printf("Employee with ID %d has been updated. New Last Name: %s\n", id, employees[i].lastName);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

// Main function with menu-based interface
int main() {
    e1 employees[MAX_EMPLOYEES]; // Using typedef name 'e1' instead of 'struct Employee'
    int count = 0;
    int choice;
    int id;
    char lastName[50];
    char newLastName[50];
    float minSalary, maxSalary;

    do {
        printf("\nMenu:\n");
        printf("1. Scan Employee Records\n");
        printf("2. Display All Employee Records\n");
        printf("3. Search Employee by ID\n");
        printf("4. Search Employee by Last Name\n");
        printf("5. Search Employees by Salary Range (6K-10K)\n");
        printf("6. Update Employee Last Name\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanEmployeeRecords(employees, &count);
                break;
            case 2:
                displayEmployees(employees, count);
                break;
            case 3:
                printf("Enter Employee ID to search: ");
                scanf("%d", &id);
                searchById(employees, count, id);
                break;
            case 4:
                printf("Enter Last Name to search: ");
                scanf("%s", lastName);
                searchByLastName(employees, count, lastName);
                break;
            case 5:
                searchBySalaryRange(employees, count, 6000, 10000);
                break;
            case 6:
                printf("Enter Employee ID to update: ");
                scanf("%d", &id);
                printf("Enter new Last Name: ");
                scanf("%s", newLastName);
                updateLastName(employees, count, id, newLastName);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}