#include "teacher.h"

typedef struct teacher {
	int teacher_number;
	char *first_name;
}teacher;

void teacher_create(int teacher_number, char *first_name)
{
	teacher *th = (teacher *)malloc(sizeof(teacher));
	th->first_name = first_name;
	th->teacher_number = teacher_number;
}



/*void print()
{
	teacher *th;
	printf("%d ", th->teacher_number);
	char *temp = th->first_name;
	while (temp != 0)
	{
		printf("%c", temp);
		temp++;
	}
	printf("\n");
}*/