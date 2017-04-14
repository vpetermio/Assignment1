#include "database.h"
#include "student.h"
#include "teacher.h"
#include "course.h"
#include "assignment.h"
#include "enrolment.h"
#include "list.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

list_p student_list;
list_p teacher_list;
list_p course_list;
list_p assignment_list;
list_p enrolment_list;

//Function to create database.
void create_db(char a)
{
	if (a== 'S')
	{
		list_create(&student_list);
	}
	else if (a == 'T')
	{
		list_create(&teacher_list);
	}
}

//Adds a student to the list.
void* add_student(int student_number,char* first_name)
{
	void* st = student_create(student_number, first_name);
	
	add_item(&student_list, st);
	return st;
}

//Adds teacher to the list.
void* add_teacher(int teacher_number, char* first_name)
{

	void* t = teacher_create(teacher_number, first_name);

	add_item(&teacher_list, t);
	return t;
}

//Adds course to the list.
void* add_course(int course_number, char* course_name, int semester_number)
{
	void* c = course_create(course_number, course_name, semester_number);

	add_item(&course_list, c);
	return c;
}

//Adds assignment to the list.
void* add_assignment(int teacher_number,int course_number)
{
	void* a = assignment_create(teacher_number, course_number);

	add_item(&assignment_list, a);
	return a;
}

//Adds enrolment to the list.
void* add_enrolment(int student_number, int course_number)
{
	void* e = enrolment_create(student_number, course_number);

	add_item(&enrolment_list, e);
	return e;
}

//Checks if a student excists in the list.
static int find_student(int student_number)
{
	int size = no_of_items(&student_list);
	int i = 0;
	while (i<size)
	{
		student *st = (student*)get_item(&student_list, i);
		if (check_student_number(st, student_number) == 0)
		{
			return 0;
		}
		i++;
	}
	return -1;
}

//Checks if a student excists in the list and if it does return its student number.
static int check_student(int student_number)
{
	int size = no_of_items(&student_list);
	int i = 0;
	while (i<size)
	{
		student *st = (student*)get_item(&student_list, i);
		if (check_student_number(st, student_number) == 0)
		{
			return student_number;
		}
		i++;
	}
	return -1;
}

//Checks if a course excists in the list.
static int find_course(int course_number)
{
	int size = no_of_items(&course_list);
	int i = 0;
	while (i<size)
	{
		course *c = (course*)get_item(&course_list, i);
		if (check_course_number(c, course_number) == 0)
		{
			return 0;
		}
		i++;
	}
	return -1;
}

//Checks if a course excists in the list and if it does return its course number.
static int check_course(int course_number)
{
	int size = no_of_items(&course_list);
	int i = 0;
	while (i<size)
	{
		course *c = (course*)get_item(&course_list, i);
		if (check_course_number(c, course_number) == 0)
		{
			return course_number;
		}
		i++;
	}
	return -1;
}

//Checks if a teacher excists in the list.
static int find_teacher(int teacher_number)
{
	int size = no_of_items(&teacher_list);
	int i = 0;
	while (i<size)
	{
		teacher *t = (teacher*)get_item(&teacher_list, i);
		if (check_teacher_number(t, teacher_number) == 0)
		{
			return 0;
		}
		i++;
	}
	return -1;
}

//Checks if a teacher excists in the list and if it does return its course number.
static int check_teacher(int teacher_number)
{
	int size = no_of_items(&teacher_list);
	int i = 0;
	while (i<size)
	{
		teacher *st = (teacher*)get_item(&teacher_list, i);
		if (check_teacher_number(st, teacher_number) == 0)
		{
			return teacher_number;
		}
		i++;
	}
	return -1;
}

//Checks if a enrolment excists in the list.
static int find_enrolment(int student_number)
{
	int size = no_of_items(&enrolment_list);
	int i = 0;
	while (i<size)
	{
		enrolment *e = (enrolment*)get_item(&enrolment_list, i);
		if (check_student_number_enrolment(e, student_number) == 0)
		{
			return 0;
		}
		i++;
	}
	return -1;
}

//Assigns teacher to a course.
void* assign_teacher(int teacher_number, int course_number)
{
	if (find_teacher(teacher_number) == 0 && find_course(course_number) == 0)
	{
		void* a = assignment_create(teacher_number, course_number);
		if (check_teacher(teacher_number) == teacher_number && check_course(course_number) == course_number)
		{
			printf("Teacher is already assigned in this course!\n");
		}
		else
		{
			add_item(&assignment_list, a);
		}
		return a;
	}
	else
	{
		printf("Teacher/course does not exist!\n");
		return NULL;
	}
}

//Enrols student to a course.
void* enrol_student(int student_number, int course_number)
{
	if (find_student(student_number) == 0 && find_course(course_number) == 0)
	{
		void* e = enrolment_create(student_number, course_number);
		if (check_student(student_number) == student_number && check_course(course_number) == course_number)
		{
			printf("Student is already enrolled in this course!\n");
		}
		else
		{
			add_item(&enrolment_list, e);
		}
		return e;
	}
	else
	{
		printf("Student/course does not exist!\n");
		return NULL;
	}
}

//Returns course node by course number.
static void* get_course_by_course_number(int course_number)
{
	int size = no_of_items(&course_list);
	int i = 0;
	while (i<size)
	{
		course *c = (course*)get_item(&course_list, i);

		void* temp = get_course(c, course_number);
		if (temp != NULL)
		{
			return temp;
		}
		i++;
	}
	return NULL;
}

//Returns student node by student number.
static void* get_student_by_student_number(int student_number)
{
	int size = no_of_items(&student_list);
	int i = 0;
	while (i<size)
	{
		student *c = (student*)get_item(&student_list, i);

		void* temp = get_student(c, student_number);
		if (temp != NULL)
		{
			return temp;
		}
		i++;
	}
	return NULL;
}

//Returns teacher by teacher number.
static void* get_teacher_by_teacher_number(int teacher_number)
{
	int size = no_of_items(&teacher_list);
	int i = 0;
	while (i<size)
	{
		teacher *c = (teacher*)get_item(&teacher_list, i);

		void* temp = get_teacher(c, teacher_number);
		if (temp != NULL)
		{
			return temp;
		}
		i++;
	}
	return NULL;
}

//Returns courses by student number in an array.
static int* get_courses_by_student_number_in_array(int student_number)
{
	int size = no_of_items(&enrolment_list);
	int i = 0;
	int k = 0;
	int courses[255] = { NULL };
	int *newArray = malloc(sizeof(courses));
	newArray = courses;

	while (i<size)
	{
		enrolment *e = (enrolment*)get_item(&enrolment_list, i);
		int course_number = get_course_number_from_enrolment(e, student_number);
		if (course_number != -1)
		{
			course* c = get_course_by_course_number(course_number);
			courses[k] = c->course_number;
			k++;
		}
		i++;
	}
	return (newArray);
}

//Prints courses by student number.
void get_courses_by_student_number(int student_number)
{
	int size = no_of_items(&enrolment_list);
	int i = 0;
	while (i<size)
	{
		enrolment *e = (enrolment*)get_item(&enrolment_list, i);
		int course_number = get_course_number_from_enrolment(e, student_number);
		if (course_number != -1)
		{
		void* c=get_course_by_course_number(course_number);
		print_course(c);
		}	
		i++;
	}
}

//Prints courses by teacher number.
void get_courses_by_teacher_number(int teacher_number)
{
	int size = no_of_items(&assignment_list);
	int i = 0;
	while (i<size)
	{
		assignment *a = (assignment*)get_item(&assignment_list, i);
		int course_number = get_course_number_from_assignment(a, teacher_number);
		if (course_number != -1)
		{
			void* c = get_course_by_course_number(course_number);
			print_course(c);
		}
		i++;
	}
}

//Prints students by course number.
void get_students_by_course_number(int course_number)
{
	int size = no_of_items(&enrolment_list);
	int i = 0;
	while (i<size)
	{
		enrolment *e = (enrolment*)get_item(&enrolment_list, i);
		int student_number = get_student_number_from_enrolment(e, course_number);
		if (student_number != -1)
		{
			void* s = get_student_by_student_number(student_number);
			print_student(s);
		}
		i++;
	}
}

//Returns number of courses by student number.
static int number_of_courses_by_student_number(int student_number)
{
	int size = no_of_items(&enrolment_list);
	int i = 0;
	int temp = 0;
	while (i < size) {

		enrolment *e = (enrolment*)get_item(&enrolment_list, i);
		int course_number = get_course_number_from_enrolment(e, student_number);
		if (course_number != -1)
		{
			temp++;
		}
		i++;
	}
	return temp;

}

//Returns teachers by course number.
static void* get_teachers_by_course_number(int course_number)
{
	int size = no_of_items(&assignment_list);
	int i = 0;
	while (i<size)
	{
		assignment *a = (assignment*)get_item(&assignment_list, i);
		int teacher_number = get_teacher_number_from_assignment(a, course_number);
		if (teacher_number != -1)
		{
			teacher* t = get_teacher_by_teacher_number(teacher_number);
			return t;
		}
		i++;
	}
	return NULL;
}

//Prints teachers by student number.
void get_teachers_by_student_number(int student_number)
{
	
	int size = number_of_courses_by_student_number(student_number);
	int i = 0;

	int* cbsn=get_courses_by_student_number_in_array(student_number);

	while (i < size)
	{
		int temp = cbsn[i];
		teacher* teachers = get_teachers_by_course_number(temp);
		printf("%d %s\n", teachers->teacher_number, teachers->first_name);
		//for some reason this print function below prints out only the first teacher, in other functions it works
		//print_teacher(teachers);
		i++;
	}

}

//Removes student from enrolment.
static int remove_student_from_enrolment(int student_number)
{
	int size_of_enrolment_list = no_of_items(&enrolment_list);
	int i = 0;
	enrolment *e;
	while (i < size_of_enrolment_list) {
	
		e =(enrolment*)get_item(&enrolment_list, i);
			if (e->student_number == student_number)
			{
				remove_item(&enrolment_list, e);	
				size_of_enrolment_list--;
				i--;
				if (find_enrolment(student_number) == -1)
				{
					return 0;
				}
				
			}
			i++;	
		}
	return -1;
}

//Removes student from the student list.
int remove_student(int student_number)
{
	int size_of_student_list= no_of_items(&student_list);
	int i = 0;
	int removed_from_enrolment_list = remove_student_from_enrolment(student_number);
	
	while (i < size_of_student_list) {

		student *s = (student*)get_item(&student_list, i);
		if (s->student_number == student_number)
		{
			remove_item(&student_list, s);
			if (removed_from_enrolment_list == 0 )
			{
			return 0;
			}
		}
		i++;
	}
	return -1;
}

//Prints out student list.
void print_student_list()
{
	int size = no_of_items(&student_list);
	int i = 0;
	while (i<size)
	{
		student *st = (student*)get_item(&student_list, i);
		print_student(st);
		i++;
	}
}

//Prints out teacher list.
void print_teacher_list()
{
	int size = no_of_items(&teacher_list);
	int i = 0;
	while (i<size)
	{
		teacher *t = (teacher*)get_item(&teacher_list, i);
		print_teacher(t);
		i++;
	}
}

//Prints out course list.
void print_course_list()
{
	int size = no_of_items(&course_list);
	int i = 0;
	while (i<size)
	{
		course *c = (course*)get_item(&course_list, i);
		print_course(c);
		i++;
	}
}

//Prints out assignment list.
void print_assignment_list()
{
	int size = no_of_items(&assignment_list);
	int i = 0;
	while (i<size)
	{
		assignment *a = (assignment*)get_item(&assignment_list, i);
		print_assignment(a);
		i++;
	}
}

//Prints out enrolment list.
void print_enrolment_list()
{
	int size = no_of_items(&enrolment_list);
	int i = 0;
	while (i<size)
	{
		enrolment *e = (enrolment*)get_item(&enrolment_list, i);
		print_enrolment(e);
		i++;
	}
}
