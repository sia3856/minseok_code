#include <stdio.h>
 
void main()
{
    //  int 범위: -2,147,483,648 ~ 2,147,483,647
    //  16진수:1a2b3c4d == 10진수:   439,041,101
    //  16진수:7fffffff == 10진수: 2,147,483,647
 
//1. 16진수 0x1a2b3c4d, int 자료형 hex_8 변수에 저장
int hex_8 = 0x1a2b3c4d;
int int_max = 0x7ddddddd;
printf("1. 16진수 0x1a2b3c4d, int 자료형 hex_8 변수에 저장\n");
printf("hex_8 size: %ld Byte, int hex_8 = %x;\n\n", sizeof hex_8, hex_8);
 
 
// 2. 16진수 0x1a2b3c4d 데이터를 출력
printf("2. hex_8 값 10진수, 16진수 출력\n");
printf("hex_8 10진수 = %d, 16진수 = %x;\n\n", hex_8, hex_8);
 
 
// 3. char* 포인터 자료형 ptr 변수에 hex_8의 포인터를 저장;
char* ptr = (char*)&int_max;
printf("3. char* 포인터 자료형 ptr 변수에 hex_8의 포인터를 저장;\n");
printf("char* ptr = &hex_8;\n");
printf("char* ptr = %p;\n", ptr);
 
 
// 4. 포인터 변수 ptr 위치에 들어있는 값을 1바이트씩 16진수로 출력(1)
//    포인터 (연산)
printf("\n4. 포인터 변수 ptr 에 들어있는 1바이트씩 출력(1)\n");
printf("*(ptr+0) == %x\n", *(ptr + 0));
printf("*(ptr+1) == %x\n", *(ptr + 1));
printf("*(ptr+2) == %x\n", *(ptr + 2));
printf("*(ptr+3) == %x\n", *(ptr + 3));
 
// 4. 포인터 변수 ptr 위치에 들어있는 값을 1바이트씩 10진수로 출력(2)
//    포인터 (연산)
printf("\n4. 포인터 변수 ptr 에 들어있는 1바이트씩 출력(1)\n");
printf("*(ptr+0) == %d\n", *(ptr + 0));
printf("*(ptr+1) == %d\n", *(ptr + 1));
printf("*(ptr+2) == %d\n", *(ptr + 2));
printf("*(ptr+3) == %d\n", *(ptr + 3));
 
// 5. 포인터 변수 ptr 에 들어있는 값을 1바이트씩 16진수로 출력(3)
//    포인터 [연산]
printf("\n5. 포인터 변수 ptr 에 들어있는 1바이트씩 출력(2)\n");
printf("ptr[0] == %x\n", ptr[0]);
printf("ptr[1] == %x\n", ptr[1]);
printf("ptr[2] == %x\n", ptr[2]);
printf("ptr[3] == %x\n", ptr[3]);
 
 
// 6. int* 포인터 자료형 ptr_int 변수에 hex_8의 포인터를 저장;
//printf("\n=3번, 4번, 5번과 비교\nchar* 포인터 자료형과 int* 자료형 비교=\n");
//int* ptr_int = &hex_8;
//printf("int* ptr_int = &hex_8;\n");
//printf("int* ptr_int = %p;\n\n", ptr);
// 
//printf("ptr_int[0] == %x\n", ptr_int[0]);
//printf("ptr_int[1] == %x\n", ptr_int[1]);
//printf("ptr_int[2] == %x\n", ptr_int[2]);
//printf("ptr_int[3] == %x\n", ptr_int[3]);
 
}