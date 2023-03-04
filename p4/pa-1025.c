#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNUM 100
#define MAXSTU 300
#define IDNUM 13

int cmp(const void *, const void *);

typedef struct student{
    char id[IDNUM+1];
    int score;
    int rank;
    int test_id;
    int test_rank;
} student;

int main(void)
{
    int i, j, k, first;
    int test_num, num, stu_num;
    char *cp;
    student students[MAXNUM * MAXSTU];

    scanf("%d", &test_num);

    for (i = 0, stu_num = 0; i < test_num; i++)
    {
        scanf ("%d", &num);
        getchar();
        for (j = 0, first = stu_num; j <num; j++)
        {
            cp = students[stu_num].id;
            for (k = 0; k < IDNUM; k++, cp++)
                scanf("%c", cp);
            *cp = '\0';
            scanf("%d", &(students[stu_num].score));
            getchar();
            students[stu_num].test_id = i + 1;
            stu_num++;
        }
        qsort(&students[first], num, sizeof(student), cmp);
        students[first].test_rank = 1;
        for (j = first+1; j < first+num; j++)
            if (students[j].score == students[j-1].score)
                students[j].test_rank = students[j-1].test_rank;
            else
                students[j].test_rank = j - first + 1;
    }
    qsort(students, stu_num, sizeof(student), cmp);
    students[0].rank = 1;
    for (i = 1; i < stu_num; i++)
        if (students[i].score == students[i-1].score)
            students[i].rank = students[i-1].rank;
        else
            students[i].rank = i + 1;
    printf("%d\n", stu_num);
    for (i = 0; i < stu_num; i++)
        printf("%s %d %d %d\n", students[i].id, students[i].rank, 
                                students[i].test_id, students[i].test_rank);
}

int cmp(const void *a, const void *b)
{
    if ( (*(student *)a).score != (*(student *)b).score )
        return (*(student *)b).score - (*(student *)a).score;
    else 
        return strcmp((*(student *)a).id, (*(student *)b).id);
}
