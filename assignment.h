typedef struct assignment {
	int teacher_number;
	int course_number;
}assignment;

void* assignment_create(int teacher_number, int course_number);
int get_course_number_from_assignment(assignment* a, int teacher_number);
int get_teacher_number_from_assignment(assignment* a, int course_number);
void print_assignment(assignment*a);
