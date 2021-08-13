// 删除str中值为ch的所有字符

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct
{
	char* ch;
	int length;
}Str;
 
void Delete(Str* str, char ch)
{
	int i, count;
 
	count = 0;
	for (i = 0; i < str->length; ++i)
	{
		if (str->ch[i] == ch)
			++count;
		else
			str->ch[i - count] = str->ch[i];
	}
 
	str->length -= count;
	str->ch[str->length] = '\0';
}
 
int main()
{
	Str str;
	char s[100] = "abc3dae3fg44a3d3433g";
	int len = strlen(s);
	//初始化测试串
	str.ch = (char*)malloc(sizeof(char)*(len + 1));
	strcpy(str.ch, s);
	str.length = len;
	//执行删除操作
	char ch = '3';
	Delete(&str, ch);
 
	//打印输出
	puts(str.ch);
	printf("\nLength:%d", str.length);
 
	return 0;
}
