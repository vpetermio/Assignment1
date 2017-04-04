#include "database.h"
#include "student.h"
#include "list.h"

list_p student_list;
/*list_p teacher_list;
list_p course_list;
list_p assignment_list;
list_p enrolment_list;*/
void create_db(char a)
{
	if (a== 'S')
	{
		list_create(&student_list);
	}
/*	else if (a == 'T')
	{
		list_create(&teacher_list);
	}*/
}

void add_student(int student_number,char* first_name)
{
	void* st = student_create(student_number, first_name);
	
	add_item(&student_list, st);
}
void add_teacher(void* teacher)
{

}

void print_student_list()
{
	int size = no_of_items(&student_list);
	printf("%d", size);
	int i = 0;
	while (i<size)
	{
		student *st = (student*)get_item(&student_list, i);
		print(st);
		i++;
	}
		
	
}

