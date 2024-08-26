#include <stdio.h>
#include <string.h>

// 장비 정보를 저장할 구조체 선언
struct Equipment {
    char type[20];  // 장비 종류
    char name[20];  // 장비 이름
};

int main() {
    // 3x3x3 크기의 3중 배열을 가지는 구조체 배열 선언
    struct Equipment equipmentArray[3][3][3];

    // 배열에 값 할당
    strcpy(equipmentArray[0][0][0].type, "Laptop");
    strcpy(equipmentArray[0][0][0].name, "Dell XPS");

    strcpy(equipmentArray[0][0][1].type, "Smartphone");
    strcpy(equipmentArray[0][0][1].name, "iPhone");

    strcpy(equipmentArray[0][0][2].type, "Tablet");
    strcpy(equipmentArray[0][0][2].name, "iPad");

    // 배열 값 출력
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                printf("equipmentArray[%d][%d][%d] Type: %s, Name: %s\n", 
                        i, j, k, 
                        equipmentArray[i][j][k].type, 
                        equipmentArray[i][j][k].name);
            }
        }
    }

    return 0;
}
