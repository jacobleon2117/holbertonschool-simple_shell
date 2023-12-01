int main(void)
{
 /* declares a variable buffersize of type of size_t */
	size_t buffersize = 1024;
	
/* This line declares a pointer to a character buffer and assigns it the address of a block of memory that's been dynamically allocated. */
	char *buffer = malloc(buffersize * sizeof(char));
	
/* this line declares a pointer to a character path and assigns it the address of a block of memory that's been dynamically allocated. */
	char *path = malloc(buffersize * sizeof(char)):
/* This line declares a pointer to a pointer to a character paths. This can be used to point to an array of character pointers, i.e., an array of strings. */	
	char **paths;	
/* this line declares a pointer to a pointer to a character tokens. This can also be used to point to an array of character pointers, i.e., an array of strings.*/
	char **tokens;
/* This line declares an external variable environ which is a pointer to a pointer to a character. This variable is typically used in C programs to access the environment variables of the process. */
	extern char **environ;
}
	
