/*
    对grade.c中的学生，找出其中有不及格的课程的学生及学生号
*/

#include <stdio.h>

float *search(float (*pointer)[4])
{
    int i = 0;
    float *pt;
    pt = NULL;

    for (; i < 4; i++)
    {
        if (*(*pointer + i) < 60) // 检查是否有不及格课程
        {
            pt = *pointer ; // 使pt指向 score[i][0]
        }
        //printf ("No.%d subject , " , i) ;

        return pt;
    }
}

int main()

{
    float score[][4] = {{60, 70, 80, 90}, {56, 66, 76, 86}, {34, 57, 90, 66}};

    float *p;
    int i, j;

    for (i = 0; i < 3; i++)
    {
        p = search(score + i); // 调用search函数，如有不及格返回score[i][0]的地址，否则返回NULL
        if (p == *(score + i)) // 如果返回的是score[i][0]的地址，表示p的值不是NULL
        {
            printf("No.%d score : ", i);
            for (j = 0; j < 4; j++)
                printf("%5.2f  ", *(p + j));
            printf("\n");
        }
    }

    return 0;
}