#include <stdio.h>
#include <string.h>

// 1. Define a nested structure for the Date
typedef struct {
    int day;
    int month;
    int year;
} Date;

// 2. Define the main Employee structure
typedef struct {
    int id;
    char name[30];
    char department[20];
    double salary;
    Date hired; // Nested structure (Date inside Employee)
} Employee;

// Function prototype
void displayEmployees(Employee staff[], int count);

int main() {
    // Array of structures
    Employee staff[3]; 
    int count = 0;
    
    // --- Add Employee 1 ---
    staff[0].id = 1001;
    strcpy(staff[0].name, "Maria");
    strcpy(staff[0].department, "Finance");
    staff[0].salary = 18500.50;
    staff[0].hired.day = 15;
    staff[0].hired.month = 3;
    staff[0].hired.year = 2022;
    count++;
    
    // --- Add Employee 2 ---
    staff[1].id = 1002;
    strcpy(staff[1].name, "Simon");
    strcpy(staff[1].department, "HR");
    staff[1].salary = 17200.00;
    staff[1].hired.day = 10;
    staff[1].hired.month = 11;
    staff[1].hired.year = 2021;
    count++;
    
    // --- Add Employee 3 (Using scanf for input) ---
    printf("--- Enter New Employee Details ---\n");
    printf("Enter ID: ");
    scanf("%d", &staff[2].id);
    printf("Enter Name (one word): ");
    scanf("%29s", staff[2].name); // No & needed for char arrays
    printf("Enter Department: ");
    scanf("%19s", staff[2].department);
    printf("Enter Salary: ");
    scanf("%lf", &staff[2].salary);
    printf("Enter Hire Date (day month year): ");
    scanf("%d %d %d", &staff[2].hired.day, &staff[2].hired.month, &staff[2].hired.year);
    count++;
    
    // Display all employees
    displayEmployees(staff, count);

    return 0;
}

// Function definition
void displayEmployees(Employee staff[], int count) {
    printf("\n--- EMPLOYEE RECORDS ---\n");
    for (int i = 0; i < count; i++) {
        // Notice the double dot (staff[i].hired.year) for the nested struct
        printf("ID: %d | Name: %-10s | Dept: %-10s | Salary: N$%.2f | Hired: %02d/%02d/%d\n", 
               staff[i].id, 
               staff[i].name, 
               staff[i].department, 
               staff[i].salary,
               staff[i].hired.day,
               staff[i].hired.month,
               staff[i].hired.year);
    }
}