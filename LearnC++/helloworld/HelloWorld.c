//#include <iostream>
#include <stdio.h>
//using namespace std;

int main(void)
{
    unsigned char a,b,c;
    
    for(a=0; a<100; a++)
    {
        for(b=0; b<100; b++)
        {
            for(c=0; c<100; c++)
            {
                if((100*a+10*b+c + 100*b+10*c+c) == 53255555)
                {
                    //cout<<"\na:%d"<<a<<"\nb:%d"<<b<<"\nc:%d"<<c<<endl;

                    printf("\na:%d, b:%d, c:%d\n", a, b, c);
                }
                //printf("\na:%d, b:%d, c:%d", a, b, c);
            }
        }
    }

    sleep(1000000);
}
