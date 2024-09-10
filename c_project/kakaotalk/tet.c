#include <stdio.h>

int compare_strings(const char *str1, const char *str2) {
    int i = 0;

    // 문자열의 끝까지 또는 두 문자열이 다른 문자를 가질 때까지 비교
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0; // 두 문자가 다르면 0 반환 (같지 않음)
        }
        i++;
    }

    // 문자열이 끝나고 나서도 길이가 다르면 같지 않음
    if (str1[i] != '\0' || str2[i] != '\0') {
        return 0; // 한쪽만 끝났으면 같지 않음
    }

    return 1; // 두 문자열이 같음
}

int main() {
    const char *str1 ;
    const char *str2 ;
    printf("문자를 입력핫이ㅗ");
    scanf("%d", *str1);
    printf("222문자를 입력핫이ㅗ");
    scanf("%d", *str2);




    if (compare_strings(str1, str2)) {
        printf("문자열이 같습니다.\n");
    } else {
        printf("문자열이 다릅니다.\n");
    }

    return 0;
}