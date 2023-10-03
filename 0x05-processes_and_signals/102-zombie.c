#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * infinite_while - entry point to the program
 *
 * Return: 0
 */

int infinite_while(void)
{
	while (1)
		sleep(1);

	return (0);
}

/**
 * main - the main entry point
 *
 * Return: 0
 */

int main(void)
{
	pid_t child;
	int j = 0;

	while (j < 5)
	{
		child = fork();

		if (child == 0)
			exit(0);
		else
			printf("Zombie process created, PID: %d\n", child);
		j++;
	}

	infinite_while();

	return (0);
}
