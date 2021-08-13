/*
    有n个学生的信息（学号、姓名、成绩），要求按照成绩的高低顺序输出学生的信息
*/

#include <stdio.h>

struct Student // 声明结构体类型 struct Student
{
    int num;
    char name[30];
    float score;
};

int main()
{
    // 定义结构体数组并初始化
    struct Student stu[5] =
        {
            {101, "Zhang", 78},
            {103, "Wang", 98.5},
            {105, "Kan", 86},
            {107, "Wu", 56},
            {109, "Sun", 90}    
        };

    struct Student temp; // 定义结构体变量temp，用作交换时的临时变量
    const int len = 5;   // 定义常变量 len ，在程序运行期间不能被改变
    int i, j, k;

#if (0)
    /*************************选择排序法**************************/
    printf("The order is : \n");
    for (i = 0; i < len - 1; i++) //判断i是否小于len-1，执行下面的语句
    {
        k = i; //假设此次循环中的最大值就是当前的值
        for (j = i + 1; j < len; j++)
        {
            if (stu[j].score > stu[k].score) //将假设的当前最大值与后面的值比较
            {
                k = j; //若后面的值更大，则交换下标
            }
        }
        if (k != i) //比较之后如果此次循环中最大值并非当前值
        {
            temp = stu[i]; //将此次循环中的最大值与a[k]交换
            stu[i] = stu[k];
            stu[k] = temp;
        }
    }
    for (i = 0; i < len; i++) //利用for循环将结果依次输出
    {
        printf("%6d %8s %6.2f\n", stu[i].num, stu[i].name, stu[i].score);
    }
    printf("\n");
#endif

    /*********************冒泡排序法*********************/
    printf("The order is : \n");
    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            if (stu[j + 1].score > stu[j].score)
            {
                temp = stu[j + 1];
                stu[j + 1] = stu[j];
                stu[j] = temp;
            }
        }
    }
    for (i = 0; i < len; i++) //利用for循环将结果依次输出
    {
        printf("%6d %8s %6.2f\n", stu[i].num, stu[i].name, stu[i].score);
    }
    printf("\n");

    return 0;
}
