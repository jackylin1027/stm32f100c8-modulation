#include <stdio.h>
#pragma pack(1)

typedef struct
{
    unsigned short	ID;					// 0x00 BM means for 'Windows 9x/Nt...
    unsigned int	FileSize;			// 0x02
    unsigned int	Reserved1;			// 0x06
    unsigned int	DataOffset;			// 0x0A
    unsigned int	HeaderSize;			// 0x0E
    unsigned int	Width;				// 0x12
    unsigned int	Height;				// 0x16
    unsigned short	Class;				// 0x1A   default->1   , Picture
    unsigned short	BPP;					// 0x1C	  Bits Per Pixel 1->Black/White / 4-> 16 colors / 8-> 256 colors / 16 / 24
    unsigned int	CompressType;		// 0x1E   0 -> No / 1 -> BI_RLE8 / 2-> BI_RLE4 / 3-> BI_BITFIELDS
    unsigned int	BitsSize;			// 0x22	  It must to be 4x
    unsigned int	HResolution;		// 0x26
    unsigned int	VResolution;		// 0x2A
    unsigned int	ColorUse;			// 0x2E	  0xff -> 8 bits color
    unsigned int	ImportantColor; 	// 0x32	  0 or number of palette means all important  (r,g,b,0)
} BITMAP_HEADER;

void info()
{
    printf("Bitmap file to binary array\n");
    printf("example:  c:\\b2b.exe abc.bmp\n");
    printf("\nAll CopyRight by Uni.Co,Ltd. 2008\n");
}



int main(int argc,char*argv[])
{
    FILE *src;
    unsigned long len,w,h,data,col_cnt,data_w,invert_data,start_addr,addw;
    char *buf;
    int inter_h;
    BITMAP_HEADER *bmp;
    info();
    if (argc<2)
        return 0;
    src=fopen(argv[1],"rb");
    if (src==NULL)
    {
        printf("Can't open %s\n",argv[1]);
        return 0;
    }
    fseek(src,0,SEEK_END);
    len=ftell(src);
    rewind(src);
    buf=(char*)malloc(len);
    fread(buf,1,len,src);
    fclose(src);
    bmp=(BITMAP_HEADER*)buf;

    printf("filename: %s\n",argv[1]);
    printf("BMP ID: 0x%X\n",bmp->ID);
    printf("BMP FileSize: 0x%X\n",bmp->FileSize);
    printf("Data Offset:0x%X\n",bmp->DataOffset);
    printf("Width: %d\n",bmp->Width);
    printf("Height:%d\n",bmp->Height);
    printf("BitsSize:%d\n",bmp->BitsSize);
    printf("CompressType:%d\n",bmp->CompressType);
    printf("FileType: %d bits colors\n",bmp->BPP);
    if (bmp->BPP !=8)
    {
        printf("We just support 8 bits colors BMP file\n");
        free(buf);
        return 0;
    }

    data_w=bmp->Width;
    addw=0;
    for (; ((addw+data_w)%4); addw++);		// for align 4x Width
    printf("data_w:%d\n",data_w);
    printf("plus_w:%d\n",addw);
    printf("output[]=\n");
    printf("{\n\t");

    for (col_cnt=0,h=0; h<bmp->Height; h+=8)
    {
        for (w=(data_w+addw); w>addw; w--)
        {
            start_addr=len-w-h*(data_w+addw);

            for (data=0,inter_h=7; inter_h>=0; inter_h--)
            {
                data<<=1;

                if ((buf[start_addr-(inter_h*(data_w+addw))]&0xff)!=0)
                    data|=0x01;
                //data|=((buf[start_addr-(inter_h*(data_w+addw))])&0x01);
            }
            //printf("0x%02X,",(~data)&0xff);
            printf("0x%02X,",(~data&0xff));

            if (!(++col_cnt%16))
                printf("\n\t");
        }
    }

    printf("\n}\n");
    free(buf);
}
