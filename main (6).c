
#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char name[50], course[50];
    int age, n, i;
    char line[200];

    // Create and write student records
    fp = fopen("student_records.txt", "w");

    if (fp == NULL) {
        printf("Error creating file.");
        return 1;
    }

    printf("How many students do you want to record? ");
    scanf("%d", &n);
    getchar();

    for (i = 1; i <= n; i++) {
        printf("\nStudent %d\n", i);

        printf("Enter Name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        printf("Enter Age: ");
        scanf("%d", &age);
        getchar();

        printf("Enter Course: ");
        fgets(course, sizeof(course), stdin);
        course[strcspn(course, "\n")] = '\0';

        fprintf(fp, "Student %d\n", i);
        fprintf(fp, "Name: %s\n", name);
        fprintf(fp, "Age: %d\n", age);
        fprintf(fp, "Course: %s\n", course);
        fprintf(fp, "--------------------\n");
    }

    fclose(fp);

    printf("\nStudent database successfully saved to file.\n");

    // Read and display student records
    fp = fopen("student_records.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.");
        return 1;
    }

    printf("\nReading Student Database:\n\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);

    return 0;
}
