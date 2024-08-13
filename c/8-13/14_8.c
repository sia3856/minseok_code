#include<stdio.h>
#include<string.h>
#define NLEN 30

struct namect
{
    char fname[NLEN];
    char lname[NLEN];
    int letters;
};

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);
char *s_gets(char *st, int n);

int main(void)
{
    struct namect person;

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);

    return 0;
}

void getinfo(struct namect *pst)
{
    printf("이름을 입력하시오.\n");
    s_gets(pst -> fname,NLEN);
    printf("성씨를 입력하시오.\n");
    s_gets(pst -> lname,NLEN);
}

void makeinfo(struct namect *pst)
{
    pst -> letters = strlen(pst->fname) +strlen(pst->lname);
}

void showinfo(const struct namect *pst)
{
    printf("%s %s, 당신의 성명은 %d개의 글자를 가지고 있습니다.\n", pst -> fname, pst -> lname, pst -> letters);
}

char *s_gets(char *st, int n)

{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if(ret_val)
    {
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
            continue;
    }
    return ret_val;
}