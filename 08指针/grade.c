/*
题目：
    有a个学生，每个学生有b门课程的成绩。要求用户在输入学生序号以后，
    能输出该学生的全部成绩。用指针函数来实现(*函数名(参数表列))
解题思路：
    定义一个二维数组score，用来存放学生成绩（设a为3，b为4.）定义一个查询学生成绩的函数search，
    它是一个返回指针的函数，形参是指向一维数组的指针变量和整型变量n，从主函数将数组名score和要找
    的学生号k传递给形参。
*/

#include <stdio.h>

float *search(float (*pointer)[4], int n) // 形参pointer是指向一维数组的指针变量
{
    float *pt;
    pt = *(pointer + n); // pt的值是&score[k][0]
    return pt;
}

int main()

{
    float score[][4] = {{60, 70, 80, 90}, {56, 66, 76, 86}, {34, 78, 90, 66}};

    float *p;
    int i, k;

    printf("enter the number of student : ");
    scanf("%d", &k); // 输入要找的学生序列号

    printf("The scores of No.%d are :\n", k);

    p = search(score, k - 1);
    for (i = 0; i < 4; i++)
        printf("%5.2f\t", *(p + i));
    printf("\n");

    return 0;
}
