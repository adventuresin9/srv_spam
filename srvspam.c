/********************************************************/
/* by adventuresin9                                     */
/*                                                      */
/* A quick example of dropping one end of a named pipe  */
/* into the srv directory.  See 'man 3 srv'             */
/*                                                      */
/* This will post a file named "spam" into /srv, and    */
/* will loop the first argument given when the program  */
/* was started.  'cat /srv/spam' to get spammed.        */
/*                                                      */
/* It will do this till the /srv/spam file is removed   */
/*  'rm /srv/spam' to stop it.                          */
/********************************************************/





#include <u.h>
#include <libc.h>

void
main(int argc, char *argv[])
{
	int fd, p[2];
	

	pipe(p);
	fd = create("/srv/spam", OWRITE, 0666);
	fprint(fd, "%d", p[0]);
	close(fd);
	close(p[0]);

	

	while(access("/srv/spam", 0) == 0)
		fprint(p[1], "%s\n", argv[1]);
	

	print("Have a Nice Day!\n");

	exits(nil);
}
