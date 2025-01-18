#ifndef EDITOR_H
#define EDITOR_H

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <stdbool.h>

/**
 * struct line - line of text
 * @data: charcter to write
 * @prev: previous char
 * @next: next char
 */
typedef struct line
{
	char *data;
	struct line *prev;
	struct line *next;
} Line;

bool file_exists(const char *filename);

#endif
