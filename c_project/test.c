#include <stdio.h>

#define i_ehn 11   // 강화 단계의 개수
#define i_tier 4   // 티어의 개수
#define i_type 6   // 장비 타입의 개수

struct enhance_sta {
    int star;
    double mgnf;    
};

struct weapon {
    char* name;
    int w_tier;
    int w_atk;
    int w_cost;
    int w_cnt;
    struct enhance_sta w_sta;
};

// 함수 선언
void initializeWeapons(struct weapon* w_list);
void initializeEnhanceStages(struct enhance_sta* e_s);
void initializeBag(int bag[i_ehn][i_tier][i_type]);
void addItem(int bag[i_ehn][i_tier][i_type], struct weapon* w_list, struct enhance_sta* e_s, int tier, int enhancement, int item_type);

int main(void) {
    struct weapon w_list[4];
    struct enhance_sta e_s[11];
    int bag[i_ehn][i_tier][i_type] = {0};  // 인벤토리 초기화 (모두 0)

    // 초기화 함수 호출
    initializeWeapons(w_list);
    initializeEnhanceStages(e_s);
    initializeBag(bag);  // 1티어 0강 장비를 하나씩 제공

    int tier, enhancement, item_type;

    // 사용자 입력
    printf("티어를 입력하시오 (1-4): ");
    scanf("%d", &tier);
    printf("강화 단계를 입력하시오 (0-10): ");
    scanf("%d", &enhancement);
    printf("아이템 타입을 입력하시오 (1:무기, 2:갑옷, 3:신발, 4:장갑, 5:망토, 6:마스크): ");
    scanf("%d", &item_type);

    // 아이템 추가 함수 호출
    addItem(bag, w_list, e_s, tier, enhancement, item_type);

    return 0;
}

// 무기 초기화 함수
void initializeWeapons(struct weapon* w_list) {
    w_list[0] = (struct weapon){"기본검 +", 1, 2, 50, 1};
    w_list[1] = (struct weapon){"장검 +", 2, 5, 0, 0};
    w_list[2] = (struct weapon){"일본도 +", 3, 10, 0, 0};
    w_list[3] = (struct weapon){"싸울아비검 +", 2, 20, 0, 0};
}

// 강화 단계 초기화 함수
void initializeEnhanceStages(struct enhance_sta* e_s) {
    for (int i = 0; i < 11; i++) {
        e_s[i] = (struct enhance_sta){i, 1.0 + 0.1 * i};
    }
}

// 인벤토리 초기화 함수 (1티어 0강 장비를 하나씩 제공)
void initializeBag(int bag[i_ehn][i_tier][i_type]) {
    for (int i = 0; i < i_type; i++) {
        bag[0][0][i] = 1;  // 0강, 1티어, 각 타입에 하나씩 설정
    }
}

// 아이템 추가 및 출력 함수
void addItem(int bag[i_ehn][i_tier][i_type], struct weapon* w_list, struct enhance_sta* e_s, int tier, int enhancement, int item_type) {
    double all_atk;

    if (tier >= 1 && tier <= 4 && enhancement >= 0 && enhancement <= 10 && item_type >= 1 && item_type <= 6) {
        all_atk = (w_list[tier - 1].w_atk * e_s[enhancement].mgnf);

        // 아이템 개수 추가
        if (bag[enhancement][tier - 1][item_type - 1] > 0) {
            bag[enhancement][tier - 1][item_type - 1]++;
            printf("아이템 추가 완료!\n");
        } else {
            printf("해당 위치에 아이템이 없습니다. 새로 추가합니다.\n");
            bag[enhancement][tier - 1][item_type - 1] = 1;
        }

        // 출력
        printf("이름 : %s%d\n", w_list[tier - 1].name, enhancement);
        printf("공격력 : %.1lf\n", all_atk);
        printf("현재 아이템 개수: %d\n", bag[enhancement][tier - 1][item_type - 1]);
    } else {
        printf("잘못된 입력입니다.\n");
    }
}
