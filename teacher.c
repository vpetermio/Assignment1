#include "teacher.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void* teacher_create(int teacher_number, char *first_name)
{
	teacher *th = (teacher *)malloc(sizeof(teacher));
	th->first_name = _strdup(first_name);
	th->teacher_number = teacher_number;
	return th;
}

int check_teacher_number(teacher *t, int teacher_number)
{
	if (t->teacher_number == teacher_number)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}


void* get_teacher(teacher *t, int teacher_number)
{
	if (t->teacher_number == teacher_number)
	{
		return t;
	}
	else
	{
		return NULL;
	}
}

void print_teacher(teacher *t)
{
	printf("%d ", t->teacher_number);
	printf("%s\n", t->first_name);
}