#include <libmath.h>
void error(char* error_message){
	printf("ERROR: %s\n", error_message);
	SystemError('A', 44);
}