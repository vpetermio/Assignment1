#include "student.h"

typedef struct student {
	int student_number;
	char *first_name;
}student;

void *student_create(int student_number, char* first_name)
{
	student *st = (student *)malloc(sizeof(student));
	st->student_number = student_number;
	st->first_name = first_name;
	return st;
}



/*void print()
{
	student *st;
	printf("%d ", st->student_number);
	char *temp = st->first_name;
	while (temp!=0)
	{
		printf("%c", temp);
		temp++;
	}
	printf("\n");
}*/