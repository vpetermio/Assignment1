#include "student.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct student{
	int student_number;
	char* first_name;
}student;



void* student_create(int student_number1, char* first_name1)
{
	
	student *st =(student*) malloc(sizeof(student));
	
	st->student_number = student_number1;
	st->first_name = first_name1;
	return st;

}

struct student record;


void print()
{

	printf("%d %s\n", record.student_number, record.first_name);
}