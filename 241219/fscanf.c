#include <stdio.h>

typedef struct
{
    char first_name[20];
    char last_name[20];
    int id;
    float avg_grade;
} Student;

void print_student(Student s);

int main()
{
    FILE* fptr;
    char file_path[] = "luigi.txt";

    fptr = fopen(file_path, "r");

    if (fptr == NULL)
    {
        printf("Error opening file %s\n", file_path);
        return 1;
    }

    Student s;
    fscanf(fptr, "%s %s %d %f", s.first_name, s.last_name, &s.id, &s.avg_grade);
    print_student(s);

    fclose(fptr);

    return 0;
}

void print_student(Student s)
{
    printf("Name:          %s\n", s.first_name);
    printf("Surname:       %s\n", s.last_name);
    printf("ID:            %d\n", s.id);
    printf("Grade average: %.2f\n", s.avg_grade);
}
