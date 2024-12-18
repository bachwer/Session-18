#include <stdio.h>
#include <string.h>
struct information {
    int id;
    char name[50];
    int age;
    char phoneNumber[50];
};
void changeInformation(struct information person[], int id);
int main(void) {
    int idPerson;
    struct information person[5];
    strcpy(person[0].name, "nguyen van A"); person[0].age = 18; strcpy(person[0].phoneNumber, "+84 91 555 1234");
    strcpy(person[1].name, "nguyen van B"); person[1].age = 19; strcpy(person[1].phoneNumber, "+84 98 555 6789");
    strcpy(person[2].name, "nguyen van C"); person[2].age = 20; strcpy(person[2].phoneNumber, "+84 90 555 4567");
    strcpy(person[3].name, "nguyen van D"); person[3].age = 22; strcpy(person[3].phoneNumber, "+84 96 555 7890");
    strcpy(person[4].name, "nguyen van E"); person[4].age = 24; strcpy(person[4].phoneNumber, "+84 93 555 1122");

    for(int i = 0; i < 5; i ++) {
        person[i].id = i + 1;
        printf("Person id %d\n", person[i].id);
        printf("Name: %s", person[i].name);
        printf("Age: %d\n", person[i].age);
        printf("Phone number: %s\n", person[i].phoneNumber);
        printf("-----------------------\n");
    }
    do {
        printf("Enter the id want to change information: ");
        scanf("%d", &idPerson);
    }while (idPerson > 5 || idPerson < 1);
    idPerson--;
    changeInformation(person, idPerson);
    printf("Person id %d\n", person[idPerson].id);
    printf("Name: %s", person[idPerson].name);
    printf("Age: %d\n", person[idPerson].age);
    printf("Phone number: %s\n", person[idPerson].phoneNumber);


}
void changeInformation(struct information person[], int id){
    printf("\n");
    printf("Change information for person\n");
    printf("Enter name: ");
    fflush(stdin);
    fgets(person[id].name, sizeof(person[id].name), stdin);
    printf("Enter Age: ");
    scanf("%d", &person[id].age);
    fflush(stdin);
    printf("Enter phone number: ");
    fgets(person[id].phoneNumber, sizeof(person[id].phoneNumber), stdin);
    fflush(stdin);
    printf("\n");
    printf("success!!!!\n");
}
