#include <rand.h>
#include <libetc.h>
#include "renderer.h"


GsOT myOT[2]; // ordering table header
GsOT_TAG myOT_TAG[2][1<<OT_LENGTH]; // ordering table unit
PACKET GPUPacketArea[2][PACKETMAX]; // GPU packet data

short CurrentBuffer = 0; // holds the current buffer number
struct Renderer *renderer;

void graphics()
{
	SetVideoMode(1);
	GsInitGraph(SCREEN_WIDTH, SCREEN_HEIGHT, GsINTER|GsOFSGPU, 1, 0);

	GsDefDispBuff(0, 0, 0, SCREEN_HEIGHT);
	myOT[0].length = OT_LENGTH;
	myOT[1].length = OT_LENGTH;
	myOT[0].org = myOT_TAG[0];
	myOT[1].org = myOT_TAG[1]; 
	GsClearOt(0,0,&myOT[0]);
	GsClearOt(0,0,&myOT[1]);
}
void display()
{ 
	FntFlush(-1); 
	CurrentBuffer = GsGetActiveBuff(); 
	GsSetWorkBase((PACKET*)GPUPacketArea[CurrentBuffer]); 
	GsClearOt(0,0, &myOT[CurrentBuffer]); 
	DrawSync(0); 
	VSync(0); 
	GsSwapDispBuff(); 
	GsSortClear(50,50,50, &myOT[CurrentBuffer]); 
	GsDrawOt(&myOT[CurrentBuffer]);
}
void init_renderer(){
	FntLoad(960, 256); // load the font from the BIOS into the framebuffer
	SetDumpFnt(FntOpen(5, 20, 320, 240, 0, 512)); // screen X,Y | max text length X,Y | autmatic background clear 0,1 | max characters
	renderer = (struct Renderer*) malloc(sizeof(*renderer));
	renderer->current_buffer = &CurrentBuffer;
	renderer->ordering_table = &myOT;
}
struct Renderer* get_renderer(){
	return renderer;
}