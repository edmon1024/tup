#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "dir_mutex.h"

int readlinkat(int dirfd, const char *pathname, char *buf, size_t bufsiz)
{
	int rc;
	int cwd;

	cwd = dir_mutex_lock(dirfd);
	rc = readlink(pathname, buf, bufsiz);
	dir_mutex_unlock(cwd);
	return rc;
}
