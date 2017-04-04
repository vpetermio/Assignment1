#pragma once

typedef struct student {
	int student_number;
	char* first_name;
}student;

void* student_create(int student_number, char* first_name);
void print();