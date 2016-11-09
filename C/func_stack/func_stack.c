int print_out(int begin, int end)
{
     printf("%d ", begin++);
      int *p;
       p = (int*)(int(&begin) - 4);
        if(begin <= end)
              *p -= 5;
         return 1;
}
 
int add(int a, int b)
{
     return a+b;
}
 
int pass(int a, int b, int c) {
     char buffer[4] = {0};
      int sum = 0;
       int *ret;
        ret = (int*)(buffer+28);
         sum = a + b + c;
          return sum;
}
 
int main()
{
     print_out(0, 2);
      printf("\n");
       int a = 1;
        int b = 2;
         int c;
          c = add(a, b);
           pass(a, b, c);
            int __sum;
             __asm
                  {
                        mov __sum, eax
                             }
              printf("%d\n", __sum);
               system("pause");
}
