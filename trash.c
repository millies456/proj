#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
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

void __cyg_profile_func_enter (void *this_fn, void *call_site) {

    this_fn,call_site = __builtin_frame_address(0);
    //__builtin_frame_address(0)->
   // __builtin_frame_address(1)-> frame pointer address
   //// beginning address = frame pointer of profiled function + 2 * sizeof(void *);
   //ending address = frame pointer of enter/exit function + 4 * sizeof(void *);
   //running_time = (double) (finish - start) / CLOCKS_PER_SEC;
    printf( "the function entering %p\n", this_fn );
    printf( "the call site %p\n", call_site);
    printf( "function frame pointer entering %p\n", __builtin_frame_address(1));
printf("frame pointer %p\n", __builtin_frame_address(0));
    printf( "begin entering %p\n", __builtin_frame_address(1)+ 2*sizeof(this_fn));
    
}

void __cyg_profile_func_exit (void *this_fn, void *call_site) {
   
    printf( "leaving %p\n", this_fn+1 );
     printf( "begin exiting %p\n", __builtin_frame_address(0)+ 4*sizeof(this_fn));
}
int main() {
    void *this_fn;
    void *call_site;
   __cyg_profile_func_enter (this_fn,call_site);
   

    return 0;
}
