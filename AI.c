#include <stdio.h>
#include <string.h>

// Định nghĩa cấu trúc Sinh viên
typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

// Hàm in danh sách sinh viên
void printStudents(Student students[], int currentLength) {
    printf("Danh sách sinh viên:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n", 
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
    printf("\n");
}

// Hàm xóa sinh viên theo ID
void deleteStudentById(Student students[], int *currentLength, int idToDelete) {
    int foundIndex = -1;

    // Tìm vị trí sinh viên cần xóa
    for (int i = 0; i < *currentLength; i++) {
        if (students[i].id == idToDelete) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Không tìm thấy sinh viên với ID: %d\n", idToDelete);
        return;
    }

    // Dịch chuyển các phần tử phía sau lên
    for (int i = foundIndex; i < *currentLength - 1; i++) {
        students[i] = students[i + 1];
    }

    // Giảm số lượng sinh viên
    (*currentLength)--;
    printf("Đã xóa sinh viên với ID: %d\n", idToDelete);
}

// Hàm main
int main() {
    // Khai báo mảng sinh viên và gán giá trị
    Student students[5] = {
        {1, "Nguyen Van A", 20, "0123456789"},
        {2, "Tran Thi B", 21, "0987654321"},
        {3, "Le Van C", 22, "0111222333"},
        {4, "Pham Thi D", 19, "0222333444"},
        {5, "Hoang Van E", 23, "0333444555"}
    };

    int currentLength = 5;

    // In danh sách sinh viên ban đầu
    printStudents(students, currentLength);

    // Xóa sinh viên
    int idToDelete;
    printf("Nhập ID sinh viên cần xóa: ");
    scanf("%d", &idToDelete);

    deleteStudentById(students, &currentLength, idToDelete);

    // In danh sách sau khi xóa
    printStudents(students, currentLength);

    return 0;
}
4799786f-408b-469c-ad5d-98787e41b486
