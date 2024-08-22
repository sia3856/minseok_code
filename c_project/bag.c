#include<stdio.h>

// item 구조체 정의
struct item {
    char* name;
    int atk;
    int cost;
};

// monster 구조체 정의
struct monster {
    char* name;
    int atk;
    int hp;
};

// sta 구조체 정의
struct sta {
    int atk;
    int hp;
};

// battle 함수 선언
int battle(int playerAtk, struct item selectedItem, struct monster* targetMonster);

// stat 함수 선언
void stat(struct sta* playerStats);

int main() {
    // sta 구조체 초기화
    struct sta playerStats = {9, 0};  // 초기 공격력은 9, 체력은 0

    // stat 함수를 호출하여 플레이어의 공격력과 체력 설정
    stat(&playerStats);

    // item 구조체 초기화
    struct item t1 = {"sword", 100, 100};
    struct item t2 = {"s_sword", 300, 300};

    // monster 구조체 초기화
    struct monster t3 = {"바보", 100, 1000};

    // t1 아이템을 사용하여 t3 몬스터와 전투
    int remainingHp = battle(playerStats.atk, t1, &t3);

    // 아이템 정보 출력
    printf("사용한 아이템: %s, 공격력: %d, 비용: %d\n", t1.name, t1.atk, t1.cost);

    // 전투 결과 출력
    printf("몬스터 %s의 남은 체력은: %d\n", t3.name, remainingHp);

    return 0;
}

// battle 함수 정의
int battle(int playerAtk, struct item selectedItem, struct monster* targetMonster) {
    // 총 공격력 = 플레이어 기본 공격력 + 선택된 아이템의 공격력
    int totalAtk = playerAtk + selectedItem.atk;

    // 몬스터의 체력에서 총 공격력을 뺌
    targetMonster->hp -= totalAtk;

    // 남은 몬스터 체력을 반환
    return targetMonster->hp;
}

// stat 함수 정의
void stat(struct sta* playerStats) {
    // 플레이어의 공격력과 체력을 설정
    playerStats->atk += 150;
    playerStats->hp = 1000;
}
