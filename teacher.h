typedef struct teacher {
	int teacher_number;
	char *first_name;
}teacher;

void* teacher_create(int teacher_number, char *first_name);
int check_teacher_number(teacher *t, int teacher_number);
void* get_teacher(teacher *t, int teacher_number);
void print_teacher(teacher *t);