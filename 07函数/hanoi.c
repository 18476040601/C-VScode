/*
Hanoi(汉诺)塔问题；
    古代有一座塔，塔内有3个座 A，B，C。开始时A座上有64个盘子，盘子大小不等，大的在下，小的在上。
    有一个老和尚想把这64个盘子从A座移到C座，但规定每次只允许移动一个盘，且在移动过程中在3个座上都
    始终保持大盘在下，小盘在上。在移动过程中可以利用B座。
【解题思路】
    A——>C , A——>B , C——>B , A——>C , B——>A , B——>C , A——>C ;
    共经历7步。移动n个盘子要经历(2^n - 1)步

*/

#include <stdio.h>

// 定义 move 函数
void move(char x, char y)
{
    printf("%c-->%c\n", x, y);
}

// 定义 hanoi 函数
void hanoi(int n, char one, char two, char three)

// 将n个盘子从one座借助two座，移到three座
{
    void move(char x, char y);
    if (n == 1)
        move(one, three);
    else
    {
        hanoi(n - 1, one, three, two);
        move(one, three);
        hanoi(n - 1, two, one, three);
    }
}


int main()
{
    void hanoi(int n, char one, char two, char three);
    int m;
    printf("input the number of disks:");
    scanf("%d", &m);
    printf("The step to move %d disks:\n", m);
    hanoi(m, 'A', 'B', 'C');
}
