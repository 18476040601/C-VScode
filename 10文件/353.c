/*
    在磁盘上存入10个学生的数据。要求将第1.3.5.7.9个学生数据输入计算机并显示出来
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void save(); // 定义函数 save 。向文件输出SIZE个学生的信息
void load(); // load 函数将文件随机读取并显示出来

struct Student_type
{
    int num;
    char name[10];
    int age;
    char addr[20];

} stud[SIZE];

/*****************************向文件输入信息********************************/
void save() // 定义函数 save 。向文件输出SIZE个学生的信息
{
    FILE *fp;
    int i;

    if (!(fp = fopen("stu.dat", "wb"))) // 打开输出文件，以只写二进制的模式
    {
        printf("cannot open file !!!\n");
        return;
    }

    printf("Please enter data of students : \n");
    printf("(num / name / age / addr)\n");

    for (i = 0; i < SIZE; i++)
    {
        scanf("%d %s %d %s", &stud[i].num, stud[i].name, &stud[i].age, stud[i].addr);

        if (fwrite(&stud[i], sizeof(struct Student_type), 1, fp) != 1) // 写数据stu[i]输入文件中
        {
            printf("file write error !!!");
            fclose(fp);
        }
    }

    fclose(fp);
}
/****************************************************************************/

/*****************************文件随机读取并显示*******************************/
void load() // load 函数将文件读取并显示出来
{
    FILE *fp;
    int i;

    if (!(fp = fopen("stu.dat", "rb"))) // 打开输出文件，以只写二进制的模式
    {
        printf("cannot open file !!!\n");
        return;
    }

    printf("\nThe data of students :\n");
    printf("\nnum / name   /   age / addr\n");

    for (i = 0; i < SIZE; i += 2)
    {
        // 移动文件位置标记，i * sizeof(struct Student_type)表示移动字节数，表示移动了i个数据块
        // 0 表示从文件开始位置 ，1 表示文件当前位置 ，2 表示文件末尾位置
        fseek(fp, i * sizeof(struct Student_type), 0);

        fread(&stud[i], sizeof(struct Student_type), 1, fp); // 从文件中读取数据stu[i]

        printf("%-5d %-10s %-5d %-15s\n", stud[i].num, stud[i].name, stud[i].age, stud[i].addr);
    }

    fclose(fp);
}
/****************************************************************************/

int main()
{
    save();
    load();

    return 0;
}

/*****************************拓展函数****************************************
rewind(fp) ;  // 将文件位置标记返回到文件开头

int m ;
m = ftell(fp) ; // 变量m存放文件当前位置，fetell 函数的作用是得到流式文件中文件位置标记的当前位置
if (m == -1L)   // 如果调用函数时出错(如不存在fp所指向的文件)，fetell 函数返回值为 —1L .
printf ("error\n") ;


//   ferror 函数 : 在调用各种输入输出函数时，如果出现错误，可以用ferror 函数检查   
ferror (fp) ; // 如果ferror的返回值为 0 ，表示未出错 ；如果返回非零值，表示出错
注意 ：对同一个文件每一次调用输入输出函数，都会产生一个新的ferror函数值，因此，
      应当在调用一个输入输出函数后立即检查ferror函数的值，否则信息会丢失。
          在执行fopen函数时，ferror函数的初始值自动置为 0 。


// clearerr 函数 ：作用是使文件出错标志和文件结束标志置为 0 ；
假设调用一个输入输出函数时出现错误，ferror 函数值为非零值。应该立即调用clearerr(fp),
使ferror(fp) 的值变成 0 ；以便进行下一次的检测。


/****************************************************************************/