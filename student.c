#include "student.h"

typedef struct student {
	int student_number;
	char *first_name;
}student;

void student_create(int student_number, char* first_name)
{
	student *st = alloc();
	st->student_number = student_number;
	st->first_name = first_name;
}

static void *alloc(void)
{
	student *temp = (student *)malloc(sizeof(student));
	return temp;
}

void print()
{
	student st;
	printf("%d ", st.student_number);
	char *temp = st.first_name;
	while (temp!=0)
	{
		printf("%c", temp);
		temp++;
	}
	printf("\n");
}