typedef struct student {
	int student_number;
	char* first_name;
}student;

void* student_create(int student_number, char* first_name);
int check_student_number(student *s, int student_number);
void* get_student(student *s, int student_number);
void print_student(student*s);