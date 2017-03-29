#include "enrolment.h"

typedef struct enrolment {
	int student_number;
	int course_number;
}enrolment;

void assigment_create(int student_number, int course_number)
{
	enrolment *er = alloc();
	er->student_number = student_number;
	er->course_number = course_number;
}
static void* alloc(void) {
	enrolment* temp = (enrolment *)malloc(sizeof(enrolment));
	return temp;
}
void print_assignment()
{
	enrolment er;
	printf("%d %d", er.student_number, er.course_number);
}