
#include <iostream>

using namespace std;

class ConstructionTest
{
    /*static */int i;
    public:
	ConstructionTest()
	{
        i=0;
        i++;
		cout<<"qiaozhenghui created"<<"  i=%d"<<i<<endl;
	};

	ConstructionTest(ConstructionTest &Test)
	{
        i++;
		cout<<"qiaozhenghui copy"<<"   i=%d"<<i<<endl;	
	};

    ~ConstructionTest()
	{
		cout<<"remove"<<endl;	
	};
    private:
	string m_sName;
};

int main(void)
{
	ConstructionTest Test1;
	ConstructionTest Test2 = Test1;
	ConstructionTest Test(Test1);
    
    string s1 = "qiaozhenghui";
    cout<<"sizeof string="<<s1  
	return 0;
	
}
