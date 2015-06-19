
#include <stdio.h>

using namespace std;

class ConstructionTest
{
public
	int ConstructionTest()
	{
		cout<<"qiaozhenghui created"<<endl;;
		
		return 0;
	}

	int ConstructionTest(ConstructionTest &Test)
	{
		cout<<"qiaozhenghui copy"<<endl;	
		return 0;
	}

	void ~ConstructionTest()
	{
		cout<<"remove"<<endl;	
	}
private
	string m_sName;
};

int main(void)
{
	ConstructionTest Test1;
	ConstructionTest Test2 = Test1;
	ConstructionTest Test(3);

	return 0;
	
}
