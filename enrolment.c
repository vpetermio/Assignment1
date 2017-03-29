#include "enrolment.h"

typedef struct enrolment {
	int student_number;
	int course_number;
}enrolment;

void enrolment_create(int student_number, int course_number)
{
	enrolment* er = (enrolment *)malloc(sizeof(enrolment));
	er->student_number = student_number;
	er->course_number = course_number;
}

/*void print_assignment()
{
	enrolment *er;
	printf("%d %d", er->student_number, er->course_number);
}*/