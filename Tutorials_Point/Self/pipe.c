#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int pp2c[2];
	int pc2p[2];
	pipe(pp2c);
	pipe(pc2p);
	switch(fork()){
		case -1:
			break;
		case 0:
			//Connect pp2c to stdin
			close(pp2c[1]);
			dup2(pp2c[0], STDIN_FILENO);
			close(pp2c[0]);
			//Connect pc2p to stdout
			close(pc2p[0]);
			dup2(pc2p[1], STDOUT_FILENO);
			close(pc2p[1]);

			execlp("rev", "rev", (char*) NULL);

			perror("exec failed");
			exit(127);
			break;
		default:
			close(pp2c[0]);
			close(pc2p[1]);
			//Open pipe as stream
			FILE *out = fdopen(pp2c[1], "w");
			FILE *in = fdopen(pc2p[0],"r");

			char word[1024];
			while(scanf("%s", word) != EOF){
				fprintf(out, "%s\n", word);
			}
			fclose(out);
			//read child process
			while(fscanf(in, "%s", word) != EOF){
				printf("%s\n", word);
			}
			fclose(in);

			wait(NULL);
			break;
	}

	return 0;
}
