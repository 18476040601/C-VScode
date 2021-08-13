#include <stdio.h>
#include <string.h>

int main()

{

#if (0) //括号里为0，则注释与最近一个#endif内的内容。如果为1，则取消注释。

    char a[] = {"China good!"};           //字符串
    char c[] = {'c', 'h', 'i', 'n', 'a'}; // 字符
    printf("%c\n", c[1]);                 //%c字符
    printf("%s\n", a);                    //%s字符串(string)

#endif

#if (0)

    char b[10]; //后面如果没有赋值给字符数组的话，方括号里面应该要有数字，不能为空。
    printf("请输入字符串:\n");
    /*
        scanf函数中的输入项如果是字符数组名，不要再加地址符&，
        因为在C语言中数组名代表该数组第一个元素的地址。
    */
    scanf("%s", b);
    printf("%s\n", b);

#endif

#if (0)

    char str1[5], str2[5], str3[5];
    printf("请输入字符串:\n");
    /*
        空格为分割字符，由于有空格字符分割，作为3个字符串输入。
    */
    scanf("%s%s%s", str1, str2, str3); // 输入"How are you?""
    printf("%s %s %s\n", str1, str2, str3);

#endif

#if (0)

    char str[100];
    printf("请输入字符串:\n");
    /*
        不能使用空格来输入数据的空格，空格作为分割符，在输入How之后输入空格，
        只将空格前的字符"How"送到str中，后面不会再输出。
    */
    scanf("%s", str); // 输入"How are you?""
    printf("%s\n", str);

#endif

//strcat函数————字符串连接函数
#if (0)

    char str4[30] = {"China"};
    char str5[] = {"good"};

    /*
        将字符数组str5连在str4后面，中间没有空格。结果放在字符数组str4里。
        字符数组str4应该足够大，以便容纳连接后的新字符串。
    */
    printf("%s\n", strcat(str4, str5));

#endif

//strcpy和strncpy函数————字符串复制函数
#if (0)

    char str1[30] = {"Chinagopy"};
    char str2[] = {"good"};
    /*
        将字符数组str2复制给str1，str1的字符串会被str2的字符串取代
        字符数组str1应该足够大，以便容纳被复制的字符串2。
    */
    printf("%s\n", strcpy(str1, str2));

    char str3[30] = {"Chinagopy"};
    char str4[] = {"good"};
    /*
        如果想把str4字符串前面n个字符复制到str3字符串中，可以用strncpy函数。
        将str4最前面2个字符复制到str1中，取代str3中原有的最前面2个字符。
        但复制的字符个数n不应多于str3中原有的字符(不包括'\0')。
    */
    printf("%s\n", strncpy(str3, str4, 2));

#endif

// strlen————测字符串长度的函数(不包括'\0'在内)
#if(1)

    char str[10] = "China" ;
    printf ("%ld\n" , strlen(str)) ;  //输出结果为5，也可直接写为 strlen("China" ) ;

#endif

    return 0;
}