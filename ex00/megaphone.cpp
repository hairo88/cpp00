#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>

// 小文字を大文字に変換するプログラムを作成してください。引数がない場合は、何もしません
int main(int ac, char *av[])
{
	if (ac == 1)
	{
		return 0;
	}
	else
	{
		size_t i = 0;
		while (i < strlen(av[1]))
		{
			if (islower(av[1][i]))
			{
				av[1][i] = toupper(av[1][i]);
			}
			i++;
		}
	}
	std::cout << av[1] << std::endl;
}