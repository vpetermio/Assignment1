#include "assignment.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
/*
@file assignment.c
@brief Manages assignments.
@author Adam Szekely and Peter Varanic
*/

/*@brief Create an assignment.
@return The created assignment.
@param[in] teacher_number the teacher number.
@param[in] course_number the course number.*/
void* assignment_create(int teacher_number, int course_number)
{
	assignment* as = (assignment *)malloc(sizeof(assignment));
	as->teacher_number = teacher_number;
	as->course_number = course_number;
	return as;
}

/*@brief Return the course number from an assignment of a specific teacher.
@return The course number; -1:the teacher does not exist.
@param[in] a pointer to an assignment.
@param[in] teacher_number the teacher number.*/
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

/*@brief Return the teacher number from an assignment of a specific course.
@return The teacher number; -1:the course does not exist.
@param[in] a pointer to an assignment.
@param[in] course_number the course number.*/
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
 /*@brief Print a specific assignment.
 @param[in] a pointer to an assignment.*/
void print_assignment(assignment *a)
{
	printf("%d ", a->teacher_number);
	printf("%d\n", a->course_number);
}