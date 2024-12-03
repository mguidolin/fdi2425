#include <stdio.h>
#include <string.h>

typedef struct
{
    char first_name[50];
    char last_name[50];
    int id;
    float grade_average;
} Student;

void printStudent(Student s);

int main()
{
    // Init by assignment operator
    Student mattia;
    strcpy(mattia.first_name, "Mattia");
    strcpy(mattia.last_name, "Guidolin");
    mattia.id = 654321;
    mattia.grade_average = 27.5;
    printStudent(mattia);

    printf("----\n");

    // Init with initialization list
    Student maria = { "Maria", "Rossi", 121212, 29.1 };
    printStudent(maria);

    printf("----\n");

    // Init with designated initialization list
    Student mario = { .last_name = "Bianchi", .first_name = "Mario", .grade_average = 25.0, .id = 132435 };
    printStudent(mario);

    return 0;
}

void printStudent(Student s)
{
    printf("Name:          %s\n", s.first_name);
    printf("Surname:       %s\n", s.last_name);
    printf("ID:            %d\n", s.id);
    printf("Grade average: %.2f\n", s.grade_average);
}
