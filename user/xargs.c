#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/param.h"  // MAXARG

int main(int argc, char *argv[]){
	char buf[2048], ch;
	char *p = buf;
	char *v[MAXARG];  // argv   pointer to char array
	int c;
	int blanks = 0;
	int offset = 0;

	// if(argc <= 1){
	// 	fprintf(2, "usage: xargs <command> [argv...]\n");
	// 	exit(1);
	// }
    // printf("%d",argc); 
	for (c = 1; c < argc; c++) {
		v[c-1] = argv[c];
	}
	--c;

	while (read(0, &ch, 1) > 0) {  // read from stdin
		if (ch == ' ' || ch == '\t') {
			blanks++; //add
			continue;
		}

		if (blanks) {  // if there exists blank before
			buf[offset++] ='\0';

			v[c++] = p;
			p = buf + offset;
            //printf("%s\n",buf,buf + offset);
			blanks = 0;  // reset
		}

		if (ch != '\n') {
			buf[offset++] = ch;
		} else {  // end of line exec
			v[c++] = p;
			p = buf + offset;
            // int j=0;
            // while(*v[j]!='\0'){
            //     printf("%c\n",*v[j++]);
            // }
            //  printf("%d,%s\n",offset,buf,buf + offset);
            c++;
			if (!fork()) { // child
                // exec("echo", v);
				exit(exec(v[0], v));
                exit(0);
			}
			wait(0);
			
			c = argc - 1;  // reset to previous one
		}
	}

	exit(0);
}