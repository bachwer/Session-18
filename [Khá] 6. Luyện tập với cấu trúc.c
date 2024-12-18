#include <stdio.h>
struct information {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};
void informationInput(struct information studen[], int studenNum);
void informationOutput(struct information studen[], int studenNum);
int main(void) {
    int studenNum = 5;
    struct information studen[5];
    informationInput(studen, studenNum);
    informationOutput(studen, studenNum);
}
void informationInput(struct information studen[], int studenNum) {
    for(int i = 0; i < studenNum; i++) {
        printf("- - - - - - -Studen: %d- - - - - - -\n", i + 1);
        printf("Enter id studen: ");
        scanf("%d", &studen[i].id);
        fflush(stdin);

        printf("Enter name studen: ");
        fgets(studen[i].name, sizeof(studen[i].name), stdin);
        fflush(stdin);

        printf("Enter age studen: ");
        scanf("%d", &studen[i].age);
        fflush(stdin);

        printf("Enter your phone number: ");
        fgets(studen[i].phoneNumber, sizeof(studen[i].phoneNumber), stdin);
        fflush(stdin);
    }
}

void informationOutput(struct information studen[], int studenNum) {
    for(int i = 0; i < studenNum; i++) {
        printf("- - - - - - -Studen: %d- - - - - - -\n", i + 1);
        printf("ID: %d\n", studen[i].id);
        printf("Name: %s", studen[i].name);
        printf("Age: %d\n", studen[i].age);
        printf("Phone: %s\n", studen[i].phoneNumber);
    }
}
