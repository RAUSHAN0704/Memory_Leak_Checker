#include <stdlib.h>
#include "leak.h"
void f(void)
{
int * x = malloc(10 * sizeof(int));
x[10] = 0;
} 
int main(void)
{
f();
report_mem_leak();
return 0;
}
