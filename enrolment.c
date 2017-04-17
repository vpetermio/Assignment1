#include "enrolment.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
/*
@file enrolment.c
@brief Manages enrolments.
@author Adam Szekely and Peter Varanic
*/

/*@brief Create an enrolment.
@return The created enrolment.
@param[in] student_number the student number.
@param[in] course_number the course number.*/
void* enrolment_create(int student_number, int course_number)
{
	enrolment* er = (enrolment *)malloc(sizeof(enrolment));
	er->student_number = student_number;
	er->course_number = course_number;
	return er;
}

/*@brief Return the course number from an enrolment of a specific student.
@return The course number; -1:the student does not exist.
@param[in] a pointer to an enrolment.
@param[in] student_number the student number.*/
int get_course_number_from_enrolment(enrolment* e, int student_number)
{
	if (e->student_number == student_number)
	{
		return e->course_number;
	}
	else
	{
		return -1;
	}
}

/*@brief Return the student number from an enrolment of a specific course.
@return The student number; -1:the student does not exist.
@param[in] a pointer to an enrolment.
@param[in] course_number the course number.*/
int get_student_number_from_enrolment(enrolment* e, int course_number)
{
	if (e->course_number == course_number)
	{
		return e->student_number;
	}
	else
	{
		return -1;
	}
}

/*@brief Check if a student number is in a specific enrolment.
@return 0:OK the student number exists; -1:the student number does not exist.
@param[in] e pointer to an enrolment.
@param[in] student_number the student number.*/
int check_student_number_enrolment(enrolment* e, int student_number)
{
	if (e->student_number == student_number)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

/*@brief Print a specific enrolment.
@param[in] e pointer to an enrolment.*/
void print_enrolment(enrolment *e)
{
	printf("%d ", e->student_number);
	printf("%d\n", e->course_number);
}