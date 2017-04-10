#include "enrolment.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void* enrolment_create(int student_number, int course_number)
{
	enrolment* er = (enrolment *)malloc(sizeof(enrolment));
	er->student_number = student_number;
	er->course_number = course_number;
	return er;
}

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

void print_enrolment(enrolment *e)
{
	printf("%d ", e->student_number);
	printf("%d\n", e->course_number);
}