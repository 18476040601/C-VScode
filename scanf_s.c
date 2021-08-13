/* This program has been altered purposefully
   so that it contains problems.
   Use the program to complete P2-Debugging a program
   Remember to take screenshots of you do the following:

   Adding a breakpoint at an appropriate point
   Stepping into functions (F11) and over each line of code (F10)
   Changing variables and altering other code, e.g. changing messages
   Watching the values of variables.
   Add comments to the code before taking screenshots.
   Fix the problems if you can. Otherwise, just add comments to the code
   indicating where you think the problems are and what the solution might be.
   Place all evidence into one Word Document and submit it.
   Can you add other improvements?
   这个程序被故意修改了  
    所以它包含了问题。  
    使用该程序来完成p2 -调试程序  
    记得截图你做以下:  
    
    在适当的点上添加断点  
    进入函数(F11)并遍历每一行代码(F10)  
    更改变量和其他代码，例如更改消息  
    观察变量的值。  
    在截图之前向代码添加注释。  
    如果可以的话，解决问题。 否则，只需向代码中添加注释  
    表明你认为问题在哪里，解决方案可能是什么。  
    将所有证据放入一个Word文档并提交。  
    你能添加其他改进吗?  
*/
#include <stdio.h>

int getOption()
{
    int option = 0, nl;
    printf("\nWelcome to the ATM\n");

    printf("\nMenu\n");
    printf("\n1. Withdraw Cash\n");
    printf("\n2. Show Balance\n");
    printf("\n3. Exit\n");
    printf("\nEnter a number from 1 to 3:");
    option = scanf_s("%d%c", &option, &nl);

    return option;
}

//function to allow you to withdraw cash
int withdrawCash()
{
    float amount;
    int nl, option;

    printf("\nHow much money do you want?");
    amount = scanf_s("%d%c", &option, &nl);
    return option;
}

//function to show you your balance
int getBalance()
{
    float balance = 10000;
    int nl, option;

    printf("\nHow much money do you want?");
    balance = scanf_s("%d%c", &option, &nl);
    return balance;
}

//function to update your balance
int updateBalance(float balance, float amount)
{
    int nl, option;
    balance = balance - amount;
    return balance;
}


// main function - start here
int main(void)
{
    int ch;
    int opt = 0;
    int amount = 0;
    int balance = 0;
    float newbal = 0.0;

    opt = getOption();
    printf("\nYou chose option %d\n", opt);
    if (opt == 1)
    {
        amount = withdrawCash();
        newbal = updateBalance(10000, amount);
        printf("\nHere is your %d, your balance is:\n", amount, newbal);
    }
    if (opt == 2)
    {
        balance = getBalance();
        printf("\nHere is your balance: %d\n", balance);
    }

    printf("\nThank you. Please take your card.\n");
    ch = getchar();

    return 0;
}