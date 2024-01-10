
#define ZOOM			1
#define UINT16			unsigned short
#define UINT32			unsigned long
#define UINT8			unsigned char

typedef struct
{
    UINT16	ID;					// 0x00 BM means for 'Windows 9x/Nt...
    UINT32	FileSize;			// 0x02
    UINT32	Reserved1;			// 0x06
    UINT32	DataOffset;			// 0x0A
    UINT32	HeaderSize;			// 0x0E
    UINT32	Width;				// 0x12
    UINT32	Height;				// 0x16
    UINT16	Class;				// 0x1A   default->1   , Picture
    UINT16	BPP;				// 0x1C	  Bits Per Pixel 1->Black/White / 4-> 16 colors / 8-> 256 colors / 16 / 24
    UINT32	CompressType;		// 0x1E   0 -> No / 1 -> BI_RLE8 / 2-> BI_RLE4 / 3-> BI_BITFIELDS
    UINT32	BitsSize;			// 0x22	  It must to be 4x
    UINT32	HResolution;		// 0x26
    UINT32	VResolution;		// 0x2A
    UINT32	ColorUse;			// 0x2E	  0xff -> 8 bits color
    UINT32	ImportantColor; 	// 0x32	  0 or number of palette means all important  (r,g,b,0)
} BITMAP_HEADER;

typedef struct
{
    UINT8 b;
    UINT8 g;
    UINT8 r;
    UINT8 Reserved;
} STC_OUTPUT_PAL;

int main()
{
    BITMAP_HEADER *bmp;
    unsigned char *bmpdata;
    unsigned long w=PIC_W*ZOOM,h=PIC_H*ZOOM,len,addw;
    unsigned long x,y,i,j,bytex,bytey,zoomx,zoomy;
    unsigned char byterow=PIC_H/8;
    if (PIC_H%8)
        byterow++;
    FILE *src;
    addw=0;
    for (; (w+addw)%4; addw++) ;
    /* malloc bmp size */
    len=sizeof(BITMAP_HEADER)+256*sizeof(STC_OUTPUT_PAL)+(w+addw)*h;
    bmpdata=(unsigned char*)malloc(len);
    bmp=(BITMAP_HEADER*)bmpdata;

    memset(bmpdata,0,len);
    /* Make BMP Header */
    bmp->ID=0x4D42;  // 'BM'
    bmp->FileSize=(UINT32)len;
    bmp->DataOffset=0x436;
    bmp->HeaderSize=0x28;
    bmp->Width=w;
    bmp->Height=h;
    bmp->Class=1;
    bmp->BPP=8;
    bmp->CompressType=0;
    bmp->BitsSize=(w+addw)*h;
    bmp->HResolution=0x0EC4;
    bmp->VResolution=0x0EC4;
    bmp->ColorUse=0;
    bmp->ImportantColor=0;



    /* fill palette */
    for (i=0; i<3; i++)
        bmpdata[sizeof(BITMAP_HEADER)+i]=0xff;

    /* fill pixel */

    for (bytex=0; bytex<PIC_W; bytex++)
    {
        for (bytey=0; bytey<byterow; bytey++)
        {
            unsigned char signal=data[bytex+PIC_W*bytey];
            unsigned char mask;
            for (i=0,mask=0x01; i<8; i++,mask<<=1)
            {
                UINT32 reverse=w+addw-bytex*ZOOM;
                for (zoomx=0; zoomx<ZOOM; zoomx++)
                {
                    for (zoomy=0; zoomy<ZOOM; zoomy++)
                    {
                        bmpdata[len-reverse+zoomx-(PIC_W*ZOOM+addw)*bytey*8*ZOOM-(PIC_W*ZOOM+addw)*i*ZOOM-(PIC_W*ZOOM+addw)*zoomy]=(signal&mask);
                    }
                }
            }
        }
    }




    src=fopen(FILENAME,"wb");
    if (src==NULL)
    {
        printf("Can't Open %s\n",FILENAME);
        return ;
    }
    fwrite(bmpdata,1,len,src);
    fclose(src);
    free(bmp);
    return ;
}
