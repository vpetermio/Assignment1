#include "assignment.h"

typedef struct assignment {
	int teacher_number;
	int course_number;
}assignment;

void assigment_create(int teacher_number, int course_number)
{
	assignment* as = (assignment *)malloc(sizeof(assignment));
	as->teacher_number = teacher_number;
	as->course_number = course_number;
}

/*void print_assignment()
{
	assignment as;
	printf("%d %d",as.teacher_number, as.course_number);
}*/