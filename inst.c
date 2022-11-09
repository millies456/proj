// Online C compiler to run C program online
#include <stdio.h>
struct Node{
void*frame;
void*stack;
void* callerid;
void* function;
void*begin;
void*end;
clock_t timestamp;
clock_t start;
clock_t end;
}
void __cyg_profile_func_enter(void *this_fn, void *call_site){
n1 = malloc(sizeof(struct node));
n1-> function=__builtin_frame_address(1);
n1-> frame =__builtin_frame_address(0);
n1->begin =__builtin_frame_address(1) + 2 * sizeof(void *);

}
void __cyg_profile_func_exit(void *this_fn, void *call_site){
n1 = malloc(sizeof(struct node));
n1-> function=__builtin_frame_address(1);
n1-> frame =__builtin_frame_address(0);
n1->end= __builtin_frame_address(0) + 4 * sizeof(void *);


}
int main() {
void __cyg_profile_func_enter(void *this_fn, void *call_site);

    return 0;
}
