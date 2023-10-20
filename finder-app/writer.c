#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>
#include <fcntl.h>
#include <string.h>
#include <syslog.h>

int fd;
ssize_t writer;

int main(int argc, char *argv[]){

	if(argc != 3)
		syslog(LOG_ERR, "Invalid number of arguments: %d", argc);

	char *writepath = argv[1];
	char *str = argv[2];

	openlog(NULL, 0, LOG_USER);

	fd = open (writepath, O_RDWR | O_CREAT | O_TRUNC, 0777);

	if(fd == -1)
		syslog(LOG_ERR, "%s", "Error creating the file");
	else{

		syslog(LOG_DEBUG, "File created to %s", writepath);

		writer = write (fd, str, strlen(str));

		if(writer == -1)
			syslog(LOG_ERR, "%s", "Error writing to file");
		else
			syslog(LOG_DEBUG, "Writing %s to %s", str, writepath);
	}

	closelog();
}
