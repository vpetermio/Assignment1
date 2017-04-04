#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "database.h"
#include "student.h"


void main()
{
	
	create_db("S");
	add_student(125, "Adam");
	add_student(126, "Peter");
	add_student(185, "Mio");
	//printf("%c", 'H');
	
	print_student_list();
	
}