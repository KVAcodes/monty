#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[128] = "push 1 push 0 onto the stack\0";
	char *tmp = strstr(buf, "push");
	char *ptr;

	while (*tmp)
	{
		if (*tmp >= '0' && *tmp <= '9')
		{
			ptr = tmp;
			tmp++;
			while (*tmp >= '0' && *tmp <= '9')
				tmp++;
			*tmp = '\0';
			break;
		}
		tmp++;
	}
	printf("%s\n", ptr);
	printf("%d\n", atoi(ptr));
	return (0);
}
