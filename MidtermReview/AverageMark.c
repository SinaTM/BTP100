#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Define a structure to represent a student
struct Student {
    char name[50];
    int age;
    double marks[3];
};

// Function to calculate and return the average marks of a student
double calculateAverageMarks(struct Student student) {
    double sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += student.marks[i];
    }
    return sum / 3.0;
}

void clearBuffer()
{
    while (getchar() != '\n');
}

int main() {
    // Declare an array of structures to store student information
    struct Student students[3];

    // Input student information
    for (int i = 0; i < 3; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        clearBuffer();
        printf("Age: ");
        scanf("%d", &students[i].age);
        clearBuffer();
        printf("Enter marks for 3 subjects: ");
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &students[i].marks[j]);
            clearBuffer();
        }
    }

    // Display student information and average marks
    printf("\nStudent Details and Average Marks:\n");
    for (int i = 0; i < 3; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2lf, %.2lf, %.2lf\n", students[i].marks[0], students[i].marks[1], students[i].marks[2]);
        double averageMarks = calculateAverageMarks(students[i]);
        printf("Average Marks: %.2lf\n", averageMarks);
        printf("\n");
    }

    return 0;
}
