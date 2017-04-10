#include "student.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void* student_create(int student_number1, char* first_name1)
{
	
	student *st =(student*) malloc(sizeof(student));
	
	st->student_number = student_number1;
	st->first_name = _strdup(first_name1);
	return st;

}

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

void print_student(student *s)
{
	printf("%d ", s->student_number);
	printf("%s\n", s->first_name);
}