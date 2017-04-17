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
/*
@file database.c
@brief Database for storing and handling students, teaachers, courses, assignments and enrolments.
@author Adam Szekely and Peter Varanic
*/
list_p student_list;
list_p teacher_list;
list_p course_list;
list_p assignment_list;
list_p enrolment_list;

/*@brief Create a database.
@param[in] a S for a student database, T for a teacher database.*/
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

/*@brief Add a student to the student list.
@return The created student.
@param[in] student_number the student number.
@param[in] first_name the first name.*/
void* add_student(int student_number,char* first_name)
{
	void* st = student_create(student_number, first_name);
	
	add_item(&student_list, st);
	return st;
}

/*@brief Add a teacher to the teacher list.
@return The created teacher.
@param[in] teacher_number the teacher number.
@param[in] first_name the first name.*/
void* add_teacher(int teacher_number, char* first_name)
{

	void* t = teacher_create(teacher_number, first_name);

	add_item(&teacher_list, t);
	return t;
}

/*@brief Add a course to the course list.
@return The created course.
@param[in] course_number the course number.
@param[in] course_name the course name.
@param[in] semester_number the semester number.*/
void* add_course(int course_number, char* course_name, int semester_number)
{
	void* c = course_create(course_number, course_name, semester_number);

	add_item(&course_list, c);
	return c;
}

/*@brief Add an assignment to the assignment list.
@return The created assignment.
@param[in] teacher_number the teacher number.
@param[in] course_number the course number.
*/
void* add_assignment(int teacher_number,int course_number)
{
	void* a = assignment_create(teacher_number, course_number);

	add_item(&assignment_list, a);
	return a;
}

/*@brief Add an enrolment to the enrolment list.
@return The created enrolment.
@param[in] student_number the student number.
@param[in] course_number the course number.
*/
void* add_enrolment(int student_number, int course_number)
{
	void* e = enrolment_create(student_number, course_number);

	add_item(&enrolment_list, e);
	return e;
}

/*@brief Check if a student exists in the student list.
@return int 0: OK student is in the list; -1: Student is not in the list.
@param[in] student_number the student number*/
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

/*@brief Check if a student exists in the student list.
@return The student number; -1: Student is not in the list.
@param[in] student_number the student number*/
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

/*@brief Check if a course exists in the course list.
@return int 0: OK course is in the list; -1: course is not in the list.
@param[in] course_number the course number*/
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

/*@brief Check if a course exists in the course list.
@return The course number; -1: course is not in the list.
@param[in] course_number the course number*/
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

/*@brief Check if a teacher exists in the teacher list.
@return int 0: OK teacher is in the list; -1: teacher is not in the list.
@param[in] teacher_number the teacher number*/
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

/*@brief Check if a teacher exists in the teacher list.
@return The teacher number; -1: teacher is not in the list.
@param[in] teacher_number the teacher number*/
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

/*@brief Check if a student exists in the enrolment list.
@return int 0: OK student is in the list; -1: student is not in the list.
@param[in] student_number the student number*/
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

/*@brief Assign a teacher to a course.
@return The created assignment; NULL: teacher/course does not exist.
@param[in] teacher_number the teacher number.
@param[in] course_number the course number.*/
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

/*@brief Enrol a student to a course.
@return The created enrolment; NULL: student/course does not exist.
@param[in] student_number the student number.
@param[in] course_number the course number.*/
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

/*@brief Return a course by a course number.
@return The course node; NULL:the course does not exist.
@param[in] course_number the course number.*/
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

/*@brief Return a student by a student number.
@return The student node; NULL:the student does not exist.
@param[in] student_number the student number.*/
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

/*@brief Return a teacher by a teacher number.
@return The teacher node; NULL:the teacher does not exist.
@param[in] teacher_number the teacher number.*/
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

/*@brief Return an array of courses for a specific student.
@return The array of courses a specific student is enroled in.
@param[in] student_number the student number*/
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

/*@brief Print the courses a specific student is enroled in.
@param[in] student_number the student number.*/
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

/*@brief Print the courses a specific teacher is assigned.
@param[in] teacher_number the teacher number.*/
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

/*@brief Print the students which are enroled in a specific course.
@param[in] course_number the course number.*/
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

/*@brief The amount of courses a specific student is enroled in.
@return The number of courses.
@param[in] student_number the student number*/
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

/*@brief Return the teachers which are assigned to a specific course.
@return The teachers; NULL:there are not teachers assigned to this course.
@param[in] course_number the course number*/
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

/*@brief Print the teachers a specific student has.
@param[in] student_number the student number.*/
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

/*@brief Remove a specific student from the enrolment list.
@return 0:OK the student has been removed; -1:the student does not exist.
@param[in] student_number the student number.*/
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

/*@brief Remove a specific student from the student list.
@return 0:OK the student has been removed; -1:the student does not exist.
@param[in] student_number the student number.*/
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

/*@brief Print the student list.*/
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

/*@brief Print the teacher list.*/
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

/*@brief Print the course list.*/
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

/*@brief Print the assignment list.*/
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

/*@brief Print the enrolment list.*/
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
