#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
  struct stat *file = (struct stat*)malloc(sizeof(struct stat));
  stat("makefile",file);
  printf("size: %lld\n",file->st_size);
  printf("permissions: %o\n",(file->st_mode)%512);
  printf("last accessed: %s\n",asctime(localtime(&(file->st_atime))));
  free(file);
  return 0;
}
