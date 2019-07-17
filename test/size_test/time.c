/*=============================================================================
#     FileName: test.cpp
#     Disection Test for Jemalloc
=============================================================================*/
#include <malloc.h>
#include <stdio.h>
#include <sys/time.h>
#include <jemalloc/jemalloc.h>

static const int n=1000000;
static const int msecond=1000000;

int main(){
    void * p[n];
    struct timeval t_start,t_end;
    float timeuse;
    gettimeofday(&t_start,NULL);
    for(int i=0;i<n;i++){
        p[i]=malloc(117000);
    }

    gettimeofday(&t_end,NULL);
    timeuse=msecond*(t_end.tv_sec-t_start.tv_sec)+t_end.tv_usec-t_start.tv_usec;
    printf("malloc use time:%f microseconds for %d number of malloc\r\n",timeuse,n);
    gettimeofday(&t_start,NULL);
    for(int i=0;i<n;i++){
        p[i]=realloc(p[i],1843200);
    }
    gettimeofday(&t_end,NULL);
    timeuse=msecond*(t_end.tv_sec-t_start.tv_sec)+t_end.tv_usec-t_start.tv_usec;
    printf("realloc use time:%f microseconds for %d number of realloc\r\n",timeuse,n);
    return 0;
}
