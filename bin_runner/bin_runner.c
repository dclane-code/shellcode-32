#include <stdio.h>  //for print
#include <stdlib.h> //for exit
#include <sys/stat.h> //for stat
#include <sys/mman.h> //for mmap
#include <fcntl.h>      //for open
#include <unistd.h>     //for close


int main(int argc, char **argv)
{
	if (argc<2) {
		printf("Usage: %s <file with shellcode>\n", argv[0]);
		exit(0);
	}

	/* open the file */
	int input_file_handle = 0;
	input_file_handle = open(argv[1], O_RDONLY);
	if (input_file_handle < 0) {
		printf("opening %s failed\n", argv[1]);
		exit(0);
	}

	/* stat it (for size) */
	struct stat sb = {0};
	if (fstat(input_file_handle, &sb) == -1) {
		perror("stat");
		close(input_file_handle);
		exit(EXIT_FAILURE);
	}

	void *buffer = NULL;
	buffer = mmap(NULL, sb.st_size, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE, input_file_handle, 0);
	if (buffer == NULL) {
		perror("mmap");
		close(input_file_handle);
		exit(EXIT_FAILURE);
	}
	
	/* declare function pointer */
    int (*func)(void);

	func = (int (*)(void))buffer;
	func();
	
	/* clean up */
	free(buffer);
	close(input_file_handle);

	return 0;
}





