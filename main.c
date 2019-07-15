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
	
	IT8951DisplayExample();
	IT8951DisplayExample2();
	printf("IT8951_GUI_Example\n");
	IT8951_GUI_Example();
	
	
	if (argc != 4)
	{
		printf("Error: argc!=4.\n");
		exit(1);
	}

	uint32_t x,y;
	sscanf(argv[1],"%d",&x);
	sscanf(argv[2],"%d",&y);

	IT8951_BMP_Example(x,y,argv[3]);

	EPD_Text(0,  0, (uint8_t*)"hello world",0x00, 0xff);

	IT8951WaitForDisplayReady();
	
	//Setting Load image information
	stLdImgInfo.ulStartFBAddr    = (uint32_t)gpFrameBuf;
	stLdImgInfo.usEndianType     = IT8951_LDIMG_L_ENDIAN;
	stLdImgInfo.usPixelFormat    = IT8951_8BPP; 
	stLdImgInfo.usRotate         = IT8951_ROTATE_0;
	stLdImgInfo.ulImgBufBaseAddr = gulImgBufAddr;
	//Set Load Area
	stAreaImgInfo.usX      = 0;
	stAreaImgInfo.usY      = 0;
	stAreaImgInfo.usWidth  = 200;
	stAreaImgInfo.usHeight = 200;
	
	//Load Image from Host to IT8951 Image Buffer
	IT8951HostAreaPackedPixelWrite(&stLdImgInfo, &stAreaImgInfo);//Display function 2
	
	IT8951DisplayArea(0,0, gstI80DevInfo.usPanelW, gstI80DevInfo.usPanelH, 2);

	IT8951_Cancel();

	return 0;
}


