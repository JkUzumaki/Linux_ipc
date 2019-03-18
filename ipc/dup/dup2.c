#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd, fd1;
    int p[2];
    pipe(p);
    if( fork() ){
	// To close std input
	close(0);
	// To manipulte read
	dup(p[0]);
	// Close the write 
	close(p[1]);
	// system call
	system("wc");
    } else {
	// To close std output
	close(1);
	// To manipulate write
	dup(p[1]);
	// Close the read
	close(p[0]);
	// Syetem call
	system("ls");
    }
    return 0;
}
