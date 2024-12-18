#include <stdio.h>

int main(void) {
    struct information {
        char name[50];
        int age;
        char phoneNumber[10];
    };
    struct information person1;
    printf("Enter your name: ");
    fgets(person1.name, sizeof(person1.name), stdin);
    printf("Enter your age: ");
    scanf("%d", &person1.age);
    fflush(stdin);
    printf("Enter your phone number: ");
    fgets(person1.phoneNumber, sizeof(person1.phoneNumber), stdin);
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Phone number: %s\n", person1.phoneNumber);
    return 0;
}
