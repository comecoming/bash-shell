#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SBUFSIZE 1024
#define BUFS 10*1024
#define BUFN 5
#define FPS(x) do {usleep(1000000/x);} while (0);

int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDWR);
	unsigned char *_buf = malloc(BUFS*BUFN);
	unsigned char *buf = _buf;
	unsigned char *sbuf = malloc(SBUFSIZE);
	int ret;
	int i, j = 0;
	int start = 0;
	int count = 0;

	while (1) {
		ret = read(fd, sbuf+4, SBUFSIZE);

		for (i = 0; i < ret; i++) {
			if (sbuf[i] == 0)
				if (sbuf[i+1] == 0) 
					if (sbuf[i+2] == 0)
						if (sbuf[i+3] == 1)
							{
								if (start) {
								
									printf("%d bytes:\t", j);
									printf("%02x %02x %02x %02x %02x %02x %02x %02x\n", \
										buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7]);
									//send buf pointer and size;
									j = 0;
									buf = _buf+(((++count)%BUFN)*BUFS);
									FPS(15);
								} else {
									start = 1;
								}
							}

			buf[j++] = sbuf[i];
		}
		if (ret < SBUFSIZE) {
			lseek(fd, SEEK_SET, 0);
			//TODO.send out last frame who care its complete or not
			start = 0;
			continue;
		}
		memcpy(sbuf, sbuf+SBUFSIZE, 4);
	}

	return 0;
}


