
#include <stdio.h>

#define FILE_FUNC_LINE __FILE__, __FUNCTION__, __LINE__

#define LOGD(fmt, ...)   printf("[debug][%s-%s-%d]"fmt, FILE_FUNC_LINE, ##__VA_ARGS__)

int main(int argc, char* argv[])
{
    LOGD("debug msg\n");
    LOGD("i=%d, s=%s\n", 10, "qiaozhenghui");

    return 0;
}


