#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "database.h"



void main()
{

	create_db("S");
	add_student(00000, "Adam");
	print_student_list();

}