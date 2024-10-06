#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>

int main(int ac, char *av[])
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	else
	{
		size_t i = 0;
		size_t j = 1;
		while ((int)j < ac)
		{
			i = 0;
			while (i < strlen(av[j]))
			{
				if (islower(av[j][i]))
				{
					av[j][i] = toupper(av[j][i]);
				}
				std::cout << av[j][i];
				i++;
			}
			j++;
		}
	}
	return 0;
}