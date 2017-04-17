#include "course.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
/*
@file course.c
@brief Manages courses.
@author Adam Szekely and Peter Varanic
*/

/*@brief Create a course.
@return The created course.
@param[in] course_number the course number.
@param[in] course_name the course name.
@param[in] semester_number the semester number.*/
void* course_create(int course_number, char* course_name, int semester_number)
{
	course* course1 = (course *)malloc(sizeof(course));
	course1->course_number = course_number;
	course1->course_name = _strdup(course_name);
	course1->semester_number = semester_number;
	return course1;
}

/*@brief Check if a given course number matches a course number from a specific course.
@return 0:OK the course numbers match; -1:the course numbers do not match.
@param[in] c pointer to a course.
@param[in] course_number the course number.*/
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

/*@brief Return a course if a given course number matches a specific course.
@return The course; NULL:the course does not exist.
@param[in] c pointer to a course.
@param[in] course_number the course number.*/
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

/*@brief Print a specific course.
@param[in] c pointer to a course.*/
void print_course(course *c)
{
	printf("%d ", c->course_number);
	printf("%s ", c->course_name);
	printf("%d\n", c->semester_number);
}