#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "database.h"
#include "student.h"


void main()
{
	
	create_db("S");
	add_student(125, "Adam");
	//printf("%c", 'H');
	print_student_list();
	
}