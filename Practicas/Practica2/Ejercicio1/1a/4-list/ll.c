/* RPC client for simple addition example */

#include <stdio.h>
#include <stdlib.h>

struct foo {
	int x;
	struct foo *next;
};
typedef struct foo foo;

void printnums( foo *f) {
  
  while (f) {
    printf("%d ",f->x);
    f=f->next;
  }
  printf("\n");
}

int *
sum_1(foo *argp)
{
  static int  result;

  result=0;
  while (argp) {
    result += argp->x;
    argp = argp->next;
  }

  return (&result);
}

void print_sum( foo *head) {
  int *result;

  result = sum_1(head);
    
  printf("Sum is %d\n",*result); 
}

int main( int argc, char *argv[]) {
  int n,i;
  foo *f;
  foo *head;
  foo *prev;

  if (argc<3) {
    fprintf(stderr,"Usage: %s hostname num1 num2 ...\n",argv[0]);
    exit(0);
  }

  n = argc-2;
  f = head = (foo *) malloc(sizeof(foo));
  for (i=0;i<n;i++) {
    f->x = atoi(argv[i+2]);
    f->next = (foo *) malloc(sizeof(foo));
    prev=f;
    f = f->next;
  }

  free(prev->next);
  prev->next=NULL;

  printnums(head);
  print_sum(head);
  return(0);
}



