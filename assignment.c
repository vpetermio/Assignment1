#include "assignment.h"

typedef struct assignment {
	int teacher_number;
	int course_number;
}assignment;

void assigment_create(int teacher_number, int course_number)
{
	assignment *as = alloc();
	as->teacher_number = teacher_number;
	as->course_number = course_number;
}
static void* alloc(void) {
	assignment* temp = (assignment *)malloc(sizeof(assignment));
	return temp;
}
void print_assignment()
{
	assignment as;
	printf("%d %d",as.teacher_number, as.course_number);
}