#include <stdio.h>
#include <stdarg.h>
#include <string.h>

static void DecodeT0Byte(char t0, unsigned int  *k){
    *k = (unsigned int)(t0 & 0x0f);
}

static int VerifyATR(unsigned char* ucatr, int len)
{
	unsigned char atr[33] = {0};
	memcpy(atr, ucatr, len);
	
    if((atr[4] == 'N') && (atr[5] == 'T') && (atr[6] == 'I') && (atr[7] == 'C'))
    {
        printf("the TF CA insertd!!!\n");
		return 0;
    }
    else if((atr[4] == 'I') && (atr[5] == 'R') && (atr[6] == 'D')
         && (atr[7] == 'E') && (atr[8] == 'T') && (atr[9] == 'O'))
    {
        printf("the IRDETO CA insertd!!!\n");
		return 0;
    }
    else if((atr[5] == 'D') && (atr[6] == 'V') && (atr[7] == 'N'))
    {
        printf("the DVN CA insertd!!!\n");
		return 0;
    }
    else if((atr[0] == 0x3B) && (atr[1] == 0x02) && (len == 4))
    {
        printf("the DVT CA insertd!!!\n");
		return 0;
    }
    else if((atr[9] == 'c') && (atr[10] == 't') && (atr[11] == 'i'))
    {
        printf("the CTI CA insertd!!!\n");
		return 0;
    }
	else
	{
		return -1;
	}
#if 0
    unsigned char i = 0;
    unsigned char ActualLen = 0;
    unsigned char historybytes = 0;
    unsigned char ta1 = 0, tb1 = 0, tc1 = 0, td1 = -1;
    
    if(!atr || len>33)
    {
        printf("para error\n");
        return -1;
    }

    if(atr[i]!=0x3b && atr[i]!=0x3f)
    {
        printf("transmit direction error\n");
        return -1;
    }
    ActualLen++;
    
    i++;
    DecodeT0Byte(atr[i]/*T0*/, &historybytes);
    ActualLen++;
    
    printf("atr historybytes=%d, total len=%d\n", historybytes, len);

    reparse:
    
    if(atr[i] & 0x10)//tai exit or not
    {
        ActualLen++;
    }
    if(atr[i] & 0x20)//tbi exit or not
    {
        ActualLen++;
    }
    if(atr[i] & 0x40)//tci exit or not
    {
        ActualLen++;
    }
    if(atr[i] & 0x80)//tdi exit or not
    {
        ActualLen++;
        i = ActualLen-1;

        if((atr[i]&0x0f!=0) && (atr[i]&0x0f!=1) && (atr[i]&0x0f!=14))
        {
            printf("[%d]Invalid protocol T=%d\n", __LINE__, atr[i]&0x0f);
            return -1;
        }

        if(i < (len-historybytes))
        {
            goto reparse;
        }
        else
        {
            printf("[%d]Invalid atr i=%d\n", i);
            return -1;
        }
    }
    
    printf("atr ActualLen=%d\n", ActualLen);
    
    if(ActualLen+historybytes != len)
    {
        printf("get wrong atr\n");
        return -1;
    }
#endif
    return 0;
}

int main(int argc, char* argv[])
{
	//unsigned char atr[] = {0x3b,0x6c,0x00,0x00,0x4e,0x54,0x49,0x43,0x31,0x9c,0xc5,0x17,0x4a,0x03,0x00,0x00};
	//unsigned char atr[] = {0x3b,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,};
	unsigned char atr[] = {0x3b,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x54,0x49,0x43,0x31,0xa1,0xcd,0x17,0x4a,0x6,0x3,};
	//unsigned char atr[] = {0x3b,0x7f,0x12,0x0,0x0,0x44,0x56,0x4e,0x20,0x54,0x45,0x43,0x48,0x20,0x52,0x65,0x76,0x35,0x33,0x79};
	//unsigned char atr[] = {0x3b,0x7f,0x6c,0x00,0x00,0x4e,0x54,0x49,0x43,0x31,0x9c,0xc5,0x17,0x4a,0x03,0x00,};
	
	printf("card type=%s\n", &atr[4]);
    
	printf("VerifyATR return %d\n", VerifyATR(atr, sizeof(atr)));
	
	return 0;
}
