#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
int main() {
  //Creates the struct stat you get information from and gets the information
  char *fd = "file.txt";
  struct stat *buf;
  buf = malloc(sizeof(struct stat));
  stat(fd, buf);
  //Prints out the file size
  long size = buf->st_size;
  if (size > 1024)
    printf("File size: %ld KB\n", size / 1024);
  else if (size > 1024 * 1024)
    printf("File size: %ld MB\n", size / (1024 * 1024));
  else if (size > 1024 * 1024 * 1024)
    printf("File size: %ld GB\n", size/ (1024 * 1024 * 1024));
  else
    printf("File size: %lld bytes\n", buf->st_size);
  //Prints out the permissions
  char fullmode[11] = "";
  int m = buf->st_mode;
  if (S_ISDIR(buf->st_mode)) {
    fullmode[0] = 'd';
  }
  else {
    fullmode[0] = '-';
  }
  if (m & S_IRUSR) {
    fullmode[1] = 'r';
  }
  else {
    fullmode[1] = '-';
  }
  if (m & S_IWUSR) {
    fullmode[2] = 'w';
  }
  else {
    fullmode[2] = '-';
  }
  if (m & S_IXUSR) {
    fullmode[3] = 'x';
  }
  else {
    fullmode[3] = '-';
  }
  if (m & S_IRGRP) {
    fullmode[4] = 'r';
  }
  else {
    fullmode[4] = '-';
  }
  if (m & S_IWGRP) {
    fullmode[5] = 'w';
  }
  else {
    fullmode[5] = '-';
  }
  if (m & S_IXGRP) {
    fullmode[6] = 'x';
  }
  else {
    fullmode[6] = '-';
  }
  if (m & S_IROTH) {
    fullmode[7] = 'r';
  }
  else {
    fullmode[7] = '-';
  }
  if (m & S_IWOTH) {
    fullmode[8] = 'w';
  }
  else {
    fullmode[8] = '-';
  }
  if (m & S_IXOTH) {
    fullmode[9] = 'x';
  }
  else {
    fullmode[9] = '-';
  }
  printf("Permissions (mode): %s\n", fullmode);
  //Prints out the time
  char *ct = ctime(&buf->st_atime);
  printf("Time of last access: %s", ct);
  close(*fd);
  return 0;
}
