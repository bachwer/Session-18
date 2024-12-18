#include <stdio.h>

int main(void) {
    struct information {
        int id;
        char name[50];
        int age;
        char phoneNumber[10];
    };

    struct information person[4];
    for(int i = 0; i < 5; i++) {
        person[i].id = i + 1;
        printf("Enter name(person %d): ", i + 1);
        fgets(person[i].name, sizeof(person[i].name), stdin);
        printf("Enter Age(person %d): ", i + 1);
        scanf("%d", &person[i].age);
        fflush(stdin);
        printf("Enter phone number(person %d): ", i + 1);
        fgets(person[i].phoneNumber, sizeof(person[i].phoneNumber), stdin);
        fflush(stdin);
        printf("-----------------------\n");
    }

    for(int i = 0; i < 5; i ++) {
        printf("Person id %d\n", person[i].id);
        printf("Name: %s", person[i].name);
        printf("Age: %d\n", person[i].age);
        printf("Phone number: %s\n", person[i].phoneNumber);
        printf("-----------------------\n");
    }
}
