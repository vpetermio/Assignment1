#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

void main()
{
	char name_buff[255];
	char *s_name=name_buff;
	char *t_name = name_buff;
	char *c_name = name_buff;
	int s_number, t_number, c_number, sem_number;
	
	create_db("S");
	create_db("T");
	create_db("C");
	create_db("A");
	create_db("E"); 

	FILE *db;
	char buff[255];
	db = fopen("C:/Users/Szekely Adam/Documents/ICT 3. semester/CAL/Database.txt", "r");

	if (NULL == db) 
		perror("opening database file");
	

	while (!feof(db))
	{
		fgets(buff, 255, (FILE*)db);

		
		if (sscanf(buff, "S %d %s", &s_number, s_name) == 2)
			add_student(s_number, s_name);

		else if (sscanf(buff, "T %d %s", &t_number, t_name) == 2)
			add_teacher(t_number, t_name);

		else if (sscanf(buff, "C %d %s %d", &c_number, c_name, &sem_number) == 3)
			add_course(c_number, c_name, sem_number);

		else if (sscanf(buff, "A %d %d", &t_number, &c_number) == 2)
			add_assignment(t_number, c_number);

		else if (sscanf(buff, "E %d %d", &s_number, &c_number) == 2)
			add_enrolment(s_number, c_number);


		/*Second method for reading from file
		fscanf(db, "%s", buff);
		if (strcmp(buff, "S") == 0)
		{
			fgets(buff, 255, (FILE*)db);
			number=strtok(buff, " ");
			name = strtok(NULL, " ");
			add_student(atoi(number),name);
		}*/
	}
	printf("Teacher list:\n");
	print_teacher_list();
	printf("---------\nCourse list:\n");
	print_course_list();
	printf("---------\nStudent list:\n");
	print_student_list();
	printf("---------\nEnrolment list:\n");
	print_enrolment_list();
	printf("---------\nAssignment list:\n");
	print_assignment_list();

	add_teacher(222222, "Ib");

	add_course(41, "SGM3", 3);

	add_student(111111, "Adam");
	
	add_enrolment(111111, 41);

	add_assignment(222222, 41);

	remove_student(123456);

	printf("---------\nNew teacher list:\n");
	print_teacher_list();
	printf("---------\nNew course list:\n");
	print_course_list();
	printf("---------\nNew student list:\n");
	print_student_list();
	printf("---------\nNew enrolment list:\n");
	print_enrolment_list();
	printf("---------\nNew assignment list:\n");
	print_assignment_list();

	printf("---------\nTeachers by student number:\n");
	get_teachers_by_student_number(111111);
	printf("---------\nList of students on a given course:\n");
	get_students_by_course_number(41);
	printf("---------\nList of courses that a given student is enrolled into:\n");
	get_courses_by_student_number(654321);
	printf("---------\nList of courses that a given teacher is assigned to:\n");
	get_courses_by_teacher_number(123457);

}