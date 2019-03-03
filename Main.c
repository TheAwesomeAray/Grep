#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

char line[MAXLINE];
int getline(void);

int main(int argc, char *argv[])
{
	char line[MAXLINE];
	int found = 0;

	if (argc != 2)
		printf("Usage: Find Pattern\n");
	else
		while (getline(line, MAXLINE) > 0) {
			if (strstr(line, argv[1]) != NULL) {
				printf("%s", line);
				found++;
			}
		}
	return found;
}

int getline(void)
{
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

