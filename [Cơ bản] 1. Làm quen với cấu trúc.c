#include <stdio.h>

int main(void) {
    struct information {
        char name[50];
        int age;
        char phoneNumber[10];
    };
    struct information person1 = {
        "Nguyen van A",
        18,
        "090123456"
    };
    
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Phone number: %s\n", person1.phoneNumber);
    return 0;
}
