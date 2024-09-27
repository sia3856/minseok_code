import random as rd

num_list = [i for i in range(0, 10)]

test = rd.sample(num_list, 3)

print(test[0])
print(test[1])
print(test[2])
print(test)
c = 0
in_list = []

while True:
    print("1.이지모드 2.노말모드 3.하드모드")
    b = int(input("입력:"))
    if b == 1:
        print("이지모드를 선택하셧습니다.")
        c= 20
        break
    elif b == 2:
        print("노말모드를 선택하셧습니다.")
        c = 15
        break
    elif b == 3:
        print("하드모드를 선택하셧습니다.")
        c = 10
        break
    else:
        print("잘못된 입력입니다.")
        continue


for i in range(0, c+1, 1):
    print("라운드: ", i+1)
    num1, num2, num3 =input("입력(숫자1 숫자2 숫자3)형식 : ").split()
    in_list = [int(num1), int(num2), int(num3)]
    strike = 0
    ball = 0

    for j in range(0,3,1):
        if in_list[j] == test[j]:
            strike += 1
    for u in range(1,3,1):
        if in_list[0] == test[u]:
           ball += 1
    if in_list[1] == test[0] or in_list[1] == test[2]:
        ball +=1
    if in_list[2] == test[0] or in_list[2] == test[1]:
        ball +=1

    print("스트라이크:",strike,"볼",ball)

    if strike == 3:
        print("라운드:",i+1,"에서 우승하셧습니다.")
        break
    else:
        continue


