#include "IT8951.h"

int main (int argc, char *argv[])
{
	/*
	printf("ReadReg = 0x%x\n",IT8951ReadReg(LISAR));
	IT8951WriteReg(LISAR,0x1234);
	printf("ReadReg = 0x%x\n",IT8951ReadReg(LISAR));
	*/

	if(IT8951_Init())
	{
		printf("IT8951_Init error \n");
		return 1;
	}
	
	/*
	IT8951DisplayExample();
	IT8951DisplayExample2();
	printf("IT8951_GUI_Example\n");
	IT8951_GUI_Example();
	*/
	
	if (argc != 4)
	{
		printf("Error: argc!=4.\n");
		exit(1);
	}

	uint32_t x,y;
	sscanf(argv[1],"%d",&x);
	sscanf(argv[2],"%d",&y);

	IT8951_BMP_Example(x,y,argv[3]);

	IT8951_RIPPLE_Info(10,10,"Ripple Test",2);
	IT8951_RIPPLE_Info(10,30,"Hoi Koen",2);
	IT8951_RIPPLE_Info(10,50,"en",2);
	IT8951_RIPPLE_Info(10,70,"Rogier!",2);

	IT8951_Cancel();

	return 0;
}


