#include "editor.h"
/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: arguments
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	int ch;
	long unsigned int i = 0;
	int x = 0, y = 0;
	FILE *file;
	char *buff;
	size_t buff_size = 1024;

	if (argc < 2)
        {
                fprintf(stderr, "Error with file name\n");
                exit(1);
        }
        else if (argc > 2)
        {
                fprintf(stderr, "file name must NOT have spaces!\n");
                exit(1);
        }
	buff = malloc(buff_size * sizeof(char));
	if (buff == NULL)
	{
		perror("malloc");
		return (1);
	}
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	while ((ch = getch()) != 0x1B)
	{
		if (i >= buff_size - 1)
		{
			buff_size *= 2;
			buff = realloc(buff, buff_size);
			if (buff == NULL)
			{
				perror("realloc");
				return (1);
			}
		}
		switch (ch)
		{
			case KEY_LEFT:
				--x;
				move(y, x);
				break;
			case KEY_UP:
				--y;
				move(y, x);
				break;
			case KEY_RIGHT:
				++x;
				move(y, x);
				break;
			case KEY_DOWN:
				++y;
				move(y, x);
				break;
			case '\n':
				++y;
				x = 0;
				move(y, x);
				buff[i] = ch;
				++i;
				break;
			case KEY_BACKSPACE:
				if (i > 0)
				{
					--x;
					mvdelch(y, x);
					--i;
					buff[i] = '\0';
				}
				break;
			case '\t':
				x += 8;
				move(y, x);
				break;
			default:
				printw("%c", ch);
				++x;
				move(y, x);
				buff[i] = ch;
				++i;
				break;
		}
		refresh();
	}
	buff[i] = '\0';
	endwin();

	file = fopen(argv[1], "w");
	if (file == NULL)
	{
		perror("fopen");
		return (1);
	}
	fputs(buff, file);
	fclose(file);
	free(buff);
	return (0);
}
