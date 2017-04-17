#include "teacher.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
/*
@file teacher.c
@brief Manages teachers.
@author Adam Szekely and Peter Varanic
*/

/*@brief Create a teacher.
@return The created teacher.
@param[in] teacher_number the teacher number.
@param[in] first_name the first name.*/
void* teacher_create(int teacher_number, char *first_name)
{
	teacher *th = (teacher *)malloc(sizeof(teacher));
	th->first_name = _strdup(first_name);
	th->teacher_number = teacher_number;
	return th;
}

/*@brief Check if a given teacher number matches a teacher number from a specific teacher.
@return 0:OK the teacher numbers match; -1:the teacher numbers do not match.
@param[in] t pointer to a teacher.
@param[in] teacher_number the teacher number.*/
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

/*@brief Return a teacher if a given teacher number matches a specific teacher.
@return The teacher; NULL:the teacher does not exist.
@param[in] t pointer to a teacher.
@param[in] teacher_number the teacher number.*/
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

/*@brief Print a specific teacher.
@param[in] t pointer to a teacher.*/
void print_teacher(teacher *t)
{
	printf("%d ", t->teacher_number);
	printf("%s\n", t->first_name);
}