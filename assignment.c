#include "assignment.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void* assignment_create(int teacher_number, int course_number)
{
	assignment* as = (assignment *)malloc(sizeof(assignment));
	as->teacher_number = teacher_number;
	as->course_number = course_number;
	return as;
}

int get_course_number_from_assignment(assignment* a, int teacher_number)
{
	if (a->teacher_number == teacher_number)
	{
		return a->course_number;
	}
	else
	{
		return -1;
	}
}

int get_teacher_number_from_assignment(assignment* a, int course_number)
{
	if (a->course_number == course_number)
	{
		return a->teacher_number;
	}
	else
	{
		return -1;
	}
}

void print_assignment(assignment *a)
{
	printf("%d ", a->teacher_number);
	printf("%d\n", a->course_number);
}