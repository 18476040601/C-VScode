/*
    一个学习小组由5人，每人3门功课成绩，将各个数据保存到二维数组a[5][3]中，
    并求全组分科的平均成绩和总平均成绩（average：平均成绩）
*/

#include <stdio.h>

int main()

{
    int a[5][3] = {{80, 75, 92}, {61, 65, 71}, {59, 63, 70}, {85, 87, 90}, {76, 77, 85}};
    int i, j  ;
    double sum, average , v[3];
    printf("全组的分科平均成绩分别为：\n");
    for (j = 0; j < 3; j++)       //表示科目
    {
        for (i = 0; i < 5; i++)   //表示学生
        {
            sum += a[i][j];     //5个人每一科成绩相加
        }
        v[j] = sum / 5 ;        //每一科平均成绩
        sum = 0;
        average += v[j] / 3;   //5个人3科成绩相加
    }
    printf("math : %lf\nC languag: %lf\nFoxpro :%lf\n" , v[0] , v[1] , v[2] );
    printf("总平均成绩为：%lf\n", average );
    return 0;
}
