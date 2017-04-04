#include "student.h"
#include <stdio.h>
#include <stdlib.h>

void* student_create(int student_number1, char* first_name1)
{
	
	student *st =(student*) malloc(sizeof(student));
	
	st->student_number = student_number1;
	//st->first_name = strdup(first_name1);
	st->first_name =first_name1;
	return st;

}

void print(student *s)
{
	printf("%d ", s->student_number);
	printf("%s\n", s->first_name);
}