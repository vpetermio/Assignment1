#include "course.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


void* course_create(int course_number, char* course_name, int semester_number)
{
	course* course1 = (course *)malloc(sizeof(course));
	course1->course_number = course_number;
	course1->course_name = _strdup(course_name);
	course1->semester_number = semester_number;
	return course1;
}

int check_course_number(course *c, int course_number)
{
	if (c->course_number == course_number)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
void* get_course(course *c, int course_number)
{
	if (c->course_number == course_number)
	{
		return c;
	}
	else
	{
		return NULL;
	}
}

void print_course(course *c)
{
	printf("%d ", c->course_number);
	printf("%s ", c->course_name);
	printf("%d\n", c->semester_number);
}