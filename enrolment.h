typedef struct enrolment {
	int student_number;
	int course_number;
}enrolment;

void* enrolment_create(int student_number, int course_number);
int get_course_number_from_enrolment(enrolment* e, int student_number);
int get_student_number_from_enrolment(enrolment* e, int course_number);
int check_student_number_enrolment(enrolment* e, int student_number);
void print_enrolment(enrolment*e);
