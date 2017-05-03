#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static int Plugin_ca_tf_convertchar(char* str/*in/out*/, int len)
{
    if(!str)
    {
        return -1;
    }
    
    do
    {
        char* p_str = calloc(1, 2048);
        char* s_tmp = p_str;
        char* d_tmp = str;
        if(!p_str) break;
    
        while(*d_tmp != '\0')
        {
            switch(*d_tmp)
            {
                case '\n':
                {
                    *s_tmp++ = '\\';
					*s_tmp++ = '\\';
                    *s_tmp++ = 'n';
					d_tmp++;
                }break;
                case '\r':
                {
                    *s_tmp++ = '\\';
					*s_tmp++ = '\\';
                    *s_tmp++ = 'r';
					d_tmp++;
                }break;
                default : *s_tmp++ = *d_tmp++;break;
            }
        }
    
        memcpy(str, p_str, strlen(p_str)>len?len:strlen(p_str));
        free(p_str);
        p_str = NULL;
    }while(0);

    return 0;
}

int main(int argc, char* argv[])
{
	char str[2048] = {0};

	strcpy(str, "{\"frequency\":0,\"tsId\":0,\"serviceId\":0,\"position\":\"top\",\"osdType\":0,\"controlType\":\"cak\",\"count\":0,\"timeout\":0,\"showType\":0,\"fontSize\":0,\"bgArea\":0,\"isShowCardId\":0,\"cardid\":\"\",\"fontColor\":\"\",\"bgColor\":\"\",\"content\":\"1234567890-=  QWERTYUIOP\r\nASDFGHJKL:\" asdfghjkl;''\r\n\r\nZXCVBNMN<>?   zxcvbnm,./\"}");
	printf("1str = %s\n", str);
	Plugin_ca_tf_convertchar(str, strlen(str));
	
	printf("2str = %s\n", str);
}