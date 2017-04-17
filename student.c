#include "student.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
/*
@file student.c
@brief Manages teachers.
@author Adam Szekely and Peter Varanic
*/

/*@brief Create a student.
@return The created student.
@param[in] student_number1 the student number.
@param[in] first_name1 the first name.*/
void* student_create(int student_number1, char* first_name1)
{
	
	student *st =(student*) malloc(sizeof(student));
	
	st->student_number = student_number1;
	st->first_name = _strdup(first_name1);
	return st;

}

/*@brief Check if a given student number matches a student number from a specific student.
@return 0:OK the student numbers match; -1:the student numbers do not match.
@param[in] s pointer to a student.
@param[in] student_number the student number.*/
int check_student_number(student *s,int student_number)
{
	if (s->student_number == student_number)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

/*@brief Return a student if a given student number matches a specific student.
@return The student; NULL:the student does not exist.
@param[in] s pointer to a student.
@param[in] student_number the student number.*/
void* get_student(student *s, int student_number)
{
	if (s->student_number == student_number)
	{
		return s;
	}
	else
	{
		return NULL;
	}
}

/*@brief Print a specific student.
@param[in] s pointer to a student.*/
void print_student(student *s)
{
	printf("%d ", s->student_number);
	printf("%s\n", s->first_name);
}