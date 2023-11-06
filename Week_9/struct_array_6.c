#include <stdio.h>

// Define a constant for the number of grades and number of students
#define NUM_GRADES 4
#define NUM_STUDENTS 2

// Define a Student struct with an array inside it to hold grades
struct Student
{
    char name[50]; // Student's name
    int id; // Student's ID
    float grades[NUM_GRADES]; // Array to hold student's grades
};

// Function prototypes
void printStudent(struct Student student); // Pass by value
void fillGrades(struct Student* student, float grades[], int size); // Pass by address
void printAllStudents(struct Student students[], int size); // Pass array of structs by value

int main(void) {
    // Declare an array of structures
    struct Student classroom[NUM_STUDENTS] = {
        {"John Doe", 123, {0}}, // Initialize the first student
        {"Jane Smith", 456, {0}} // Initialize the second student
    };

    // New grades to be filled for both students
    float newGradesJohn[NUM_GRADES] = { 85.5, 92.3, 76.9, 88.1 };
    float newGradesJane[NUM_GRADES] = { 89.5, 90.0, 93.2, 87.4 };

    // Fill grades for John (pass by address)
    fillGrades(&classroom[0], newGradesJohn, NUM_GRADES);

    // Fill grades for Jane (pass by address)
    fillGrades(&classroom[1], newGradesJane, NUM_GRADES);

    // Print all students (pass array of structs by value)
    printAllStudents(classroom, NUM_STUDENTS);

    return 0;
}

// Fill grades for a student (pass by address)
void fillGrades(struct Student* student, float grades[], int size) {
    for (int i = 0; i < size; i++) {
        student->grades[i] = grades[i]; // Use arrow operator to access members of a struct through a pointer
    }
}

// Print a student's data (pass by value)
void printStudent(struct Student student) {
    printf("Student ID: %d\n", student.id);
    printf("Student Name: %s\n", student.name);
    printf("Grades: ");
    for (int i = 0; i < NUM_GRADES; i++) {
        printf("%.2f ", student.grades[i]);
    }
    printf("\n");
}

// Print all students (pass array of structs by value)
void printAllStudents(struct Student students[], int size) {
    for (int i = 0; i < size; i++) {
        printStudent(students[i]); // Pass each struct by value to the printStudent function
        printf("\n");
    }
}
