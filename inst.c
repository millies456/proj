#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

struct node{
void*frame;
void*stack;
void* callerid;
void* function;
void*begin;
void*end;
clock_t timestamp;
clock_t start_t;
clock_t end_t;
};
void __cyg_profile_func_enter(void *this_fn, void *call_site){
struct node n1;
n1 =(struct node *) malloc(sizeof(struct node));
n1 -> function=__builtin_frame_address(1);
n1 -> frame =__builtin_frame_address(0);
n1- > begin =__builtin_frame_address(1) + 2 * sizeof(void *);
printf("Pointer address for map = %p\n", n1->begin);

}
void __cyg_profile_func_exit(void *this_fn, void *call_site){
struct node *n1;
n1 =(struct node *) malloc(sizeof(struct node));
n1-> function=__builtin_frame_address(1);
n1-> frame =__builtin_frame_address(0);
n1->end= __builtin_frame_address(0) + 4 * sizeof(void *);


}
int main(int argc, const char *argv[]) {
void __cyg_profile_func_enter(void *this_fn, void *call_site);

    return 0;
}

