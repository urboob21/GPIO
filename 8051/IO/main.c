#include <REGX52.H>
//port 1 2 3 mac dinh la keo len ~ gia tri ban dau la 1
void delay( int t);
	int i=1;
int main(void)
{
	while(1)
	{

		if(P1_1==0)
		{
			delay(5000000); //scale 20ms
				if(P1_1==0)
				{
					if(i==1)
						{
							P2_0=0;	
							i=0;
						}
					else if(i==0)
						{	
							P2_0=1;
							i=1;
						}
				}
		}
	}
}

void delay(int t)
{
while(t>0)
	t--;
}