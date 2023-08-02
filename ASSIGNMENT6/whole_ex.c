// Refer : https://www.win.tue.nl/~aeb/linux/lk/lk-6.html
/* mkhole.c */
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

main(int argc, char **argv){
        char *filename = "AB.txt";
        int fd = open(filename, O_RDWR|O_CREAT|O_TRUNC, 0666);
        int offset = (argc > 1) ? atoi(argv[1]) : 1000000;
        struct stat statbuf;

        write(fd, "A", 1);
        lseek(fd, offset, SEEK_SET);
        write(fd, "B", 1);
        close(fd);
        stat(filename, &statbuf);
        printf("The file %s has size %lld and takes %lld sectors\n", filename,
               (long long) statbuf.st_size, (long long) statbuf.st_blocks);
        return 0;
}