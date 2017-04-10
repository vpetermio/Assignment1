typedef struct course {
	int course_number;
	char* course_name;
	int semester_number;
}course;

void* course_create(int course_number, char* course_name, int semester_number);
int check_course_number(course *c, int course_number);
void* get_course(course *c, int course_number);
void print_course(course*c);