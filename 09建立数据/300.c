/*
    有3个候选人，每个选民只能投一人，要求编个程序，先后输入被选人的名字，最后输出各人的票结果
*/

#include <stdio.h>
#include <string.h>

struct Person
{
    char name[20];
    int count;

} leader[3] = {"wu", 0, "kan", 0, "sheng", 0};

int main()
{
    int i, j;
    char leader_name[20];

    printf("please enter the leader name :\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%s", leader_name);
        for (j = 0; j < 3; j++)
        {
            if (strcmp(leader_name, leader[j].name) == 0)
                leader[j].count++;
        }
    }
    printf("\nResult : \n");
    for (i = 0; i < 3; i++)
        printf("%5s : %d\n", leader[i].name, leader[i].count);

    return 0;
}
