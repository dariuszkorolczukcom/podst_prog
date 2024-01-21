#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nazwisko[30];
    char imie[15];
    char przedmiot[21];
    float ocena;
} Student;

Student* readData(char* filename, int* count);
void addStudent(Student** students, int* count);
void editStudent(Student* students, int count);
void displayStudents(Student* students, int count);
void displaySubject(Student* students, int count, char* przedmiot);
void displayGrade(Student* students, int count, float ocena);
void calculateAverage(Student* students, int count);
void writeData(char* filename, Student* students, int count);

int main() {
    int choice, count = 0;
    Student* students = readData("uczniowie.txt", &count);
    char przedmiot[21];
    float ocena;
    do {
        printf("1. Dodaj nowy wpis\n2. Edytuj wpis\n3. Wyswietl wszystkich studentow\n4. Wyswietl po przedmiocie\n5. Wyswietl po ocenie\n6. Wyswietl srednie\n7. Wyjscie\n");
        scanf("%d", &choice);
            switch(choice) {
            case 1:
                addStudent(&students, &count);
                break;
            case 2:
                editStudent(students, count);
                break;
            case 3:
                displayStudents(students, count);
                break;
            case 4:
                printf("Podaj przedmiot: ");
                scanf("%20s", przedmiot);
                displaySubject(students, count, przedmiot);
                break;
            case 5:
                printf("Podaj ocene: ");
                scanf("%f", &ocena);
                displayGrade(students, count, ocena);
                break;
            case 6:
                calculateAverage(students, count);
                break;
            case 7:
                writeData("uczniowie.txt", students, count);
                free(students);
                return 0;
            default:
                printf("Nieprawidlowa opcja.\n");
            }
            choice = 0;
    } while(choice != 7);

    writeData("uczniowie.txt", students, count);
    free(students);
    return 0;
}

Student* readData(char* filename, int* count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Nie udalo sie otworzyc pliku");
        return NULL;
    }

    Student* students = NULL;
    *count = 0;
    Student temp;
    while (fscanf(file, "%30s %15s %20s %f", temp.nazwisko, temp.imie, temp.przedmiot, &temp.ocena) == 4) {
        students = realloc(students, (*count + 1) * sizeof(Student));
        students[*count] = temp;
        (*count)++;
    }

    fclose(file);
    return students;
}


void addStudent(Student** students, int* count) {
    *students = realloc(*students, (*count + 1) * sizeof(Student));
    printf("Podaj nazwisko, imie, przedmiot i ocene: ");
    scanf("%30s %15s %20s %f", (*students)[*count].nazwisko,(*students)[*count].imie,  (*students)[*count].przedmiot, &((*students)[*count].ocena));
    (*count)++;
}

void editStudent(Student* students, int count) {
    int index;
    printf("Podaj numer studenta ktorego chcesz edytowac (0 to %d): ", count - 1);
    scanf("%d", &index);
    if(index >= 0 && index < count) {
        printf("Podaj nazwisko, imie, przedmiot i ocene: ");
        scanf("%30s %15s %20s %f", students[index].nazwisko, students[index].imie, students[index].przedmiot, &students[index].ocena);
    }
}

void displayStudents(Student* students, int count) {
    for(int i = 0; i < count; i++) {
        printf("%s %s %s %.1f\n", students[i].nazwisko, students[i].imie,  students[i].przedmiot, students[i].ocena);
    }
}

void displaySubject(Student* students, int count, char* przedmiot) {
    for(int i = 0; i < count; i++) {
        if(strcmp(students[i].przedmiot, przedmiot) == 0) {
            printf("%s %s %s %.1f\n", students[i].nazwisko, students[i].imie, students[i].przedmiot, students[i].ocena);
        }
    }
}

void displayGrade(Student* students, int count, float ocena) {
    for(int i = 0; i < count; i++) {
        if(students[i].ocena == ocena) {
            printf("%s %s %s %.1f\n", students[i].nazwisko, students[i].imie, students[i].przedmiot, students[i].ocena);
        }
    }
}

void calculateAverage(Student* students, int count) {
    float total = 0;
    for(int i = 0; i < count; i++) {
        total += students[i].ocena;
    }
    printf("Srednia ocena: %f\n", total / count);
}

void writeData(char* filename, Student* students, int count) {
    FILE* file = fopen(filename, "w");
    if(file != NULL) {
        for(int i = 0; i < count; i++) {
            fprintf(file, "%s %s %s %.1f\n", students[i].nazwisko, students[i].imie, students[i].przedmiot, students[i].ocena);
        }
        fclose(file);
    }
}