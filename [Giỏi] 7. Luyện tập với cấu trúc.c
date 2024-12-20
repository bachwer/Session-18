#include <stdio.h>
#include <string.h>
//
void arrDelete();
struct information {
    int id;
    char name[50];
    int age;
    char phone[20];
};
    struct information person[50];

int main(void) {
    char name[50];

    person[0].id = 123; strcpy(person[0].name,"Nguyen Van A"); person[0].age = 18; strcpy(person[0].phone,"84+ 703 583 234");
    person[1].id = 234; strcpy(person[1].name,"Nguyen Van B"); person[1].age = 19; strcpy(person[1].phone,"84+ 712 123 543");
    person[2].id = 321; strcpy(person[2].name,"Nguyen Van C"); person[2].age = 18; strcpy(person[2].phone,"84+ 323 111 224");
    person[3].id = 454; strcpy(person[3].name,"Nguyen Van D"); person[3].age = 20; strcpy(person[3].phone,"84+ 923 583 234");
    person[4].id = 512; strcpy(person[4].name,"Nguyen Van E"); person[4].age = 18; strcpy(person[4].phone,"84+ 123 583 234");

    printf("Enter the name to delete: ");
    fgets(name, 50, stdin);
    name[strlen(name) - 1] = '\0';
    arrDelete(person, name);

}




void arrDelete(struct information person[], char name[]) {
    int i = 0;
    int check = 0;
    while (person[i + 1].name[0] != '\0') {
        if(strcmp(person[i].name, name) == 0 ) {
            while (person[i].name[0] != '\0') {
                person[i].id = person[i + 1].id;
                person[i].age = person[i + 1].age;
                strcpy(person[i].name, person[i + 1].name);
                strcpy(person[i].phone, person[i + 1].name);
                i++;
            }
            check = 1;
            break;
        }
        i++;
    }
    if (check == 0) {
        printf("There is nothing to delete\n");
    }else {
        i = 0;
        while (person[i].name[0] != '\0') {
            printf("-----------------------");
            printf("ID: %d\n", person[i].id);
            printf("Name: %s\n", person[i].name);
            printf("Age: %d\n", person[i].age);
            printf("Phone: %s\n", person[i].phone);
            i++;
        }
    }
}


