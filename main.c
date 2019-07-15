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

	uint8_t scale = 2;

	IT8951_RIPPLE_Info(10,10,"Ripple Test",scale);
	IT8951_RIPPLE_Info(10,60,"Hoi Koen",scale);
	IT8951_RIPPLE_Info(10,100,"en",scale);
	IT8951_RIPPLE_Info(10,140,"Rogier!",scale);

	IT8951_RIPPLE_Info(500,300,"Motor",scale);
	IT8951_RIPPLE_Info(500,350,"Battery",scale);

	IT8951_RIPPLE_Info(500,500,"Voltage",scale);
	IT8951_RIPPLE_Info(500,550,"Current",scale);

	uint16_t j;
	char buffer [8];
	for(j=0; j<800; j++)
	{
		sprintf(buffer, "%d", j*2)
		IT8951_RIPPLE_Info(600,500,buffer
		sprintf(buffer, "%d", j),scale);
		IT8951_RIPPLE_Info(600,550,buffer,scale);

		sprintf(buffer, "%d", j*4)
		IT8951_RIPPLE_Info(600,300,buffer
		sprintf(buffer, "%d", j*3),scale);
		IT8951_RIPPLE_Info(600,350,buffer,scale);
	}

	IT8951_Cancel();

	return 0;
}


