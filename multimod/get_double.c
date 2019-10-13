#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
static int main(int argc, char** argv)
{
    assert(argc==2);
    double x = atof(argv[1]);
    printf("%.0f\n",x);
}