#include "course.h"

typedef struct course {
	int course_number;
	char* course_name;
	int semester_number;
}course;

void course_create(int course_number, char* course_name, int semester_number)
{
	course *course1 = alloc();
	course1->course_number = course_number;
	course1->course_name = course_name;
	course1->semester_number = semester_number;
}
static void* alloc(void) {
	course* temp=(course *)malloc(sizeof(course));
	return temp;
}
void print_course()
{
	course course1;
	char* temp = course1.course_name;
	printf("%d ", course1.course_number);
	while (temp != 0)
	{
		printf("%c", temp);
		temp=temp + 1;
	}
	printf(" %d\n", course1.semester_number);

}