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
	/*printf("Student list\n");
	print_student_list();
	printf("---------\n");
	printf("Teacher list\n");
	print_teacher_list();
	printf("---------\n");
	printf("Course list\n");
	print_course_list();
	printf("---------\n");
	printf("Assignment list\n");
	print_assignment_list();
	printf("---------\n");
	printf("Enrolment list\n");
	print_enrolment_list();
	printf("---------\n");
	printf("---------\n");
	
	enrol_student(654321, 21);
	assign_teacher(123457, 11);
	printf("Student list\n");
	print_student_list();
	printf("---------\n");
	printf("Teacher list\n");
	print_teacher_list();
	printf("---------\n");
	printf("Course list\n");
	print_course_list();
	printf("---------\n");
	printf("Assignment list\n");
	print_assignment_list();
	printf("---------\n");
	printf("Enrolment list\n");
	print_enrolment_list();*/
	add_teacher(111111, "Adam");
	add_teacher(222222, "Peter");
	add_teacher(333333, "Adri");
	add_enrolment(654321, 11);
	add_enrolment(654321, 31);
	add_assignment(111111, 21);
	add_assignment(222222, 11);
	add_assignment(333333, 31);
	print_teacher_list();
	add_student(111111, "Adam");
	add_student(222222, "dam");
	add_student(333333, "am");
	add_student(444444, "m");
	add_enrolment(444444, 11);
	add_enrolment(333333, 31);
	add_enrolment(222222, 21);
	add_enrolment(444444, 21);
	print_student_list();
	print_enrolment_list();
	printf("---------\n");
    remove_student(333333);
	print_student_list();
	print_enrolment_list();
	get_teachers_by_student_number(444444);
	

}