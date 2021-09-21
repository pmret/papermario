/**************************************************************************
 *
 *  $Revision: 1.4 $
 *  $Date: 1997/11/26 00:30:50 $
 *  $Source: /hosts/gate3/exdisk2/cvs/N64OS/Master/cvsmdev2/PR/include/PRimage.h,v $
 *
 **************************************************************************/

#ifndef	__GL_IMAGE_H__
#define	__GL_IMAGE_H__
#ifdef __cplusplus
extern "C" {
#endif


/*
 *	Defines for image files . . . .
 *
 *  			Paul Haeberli - 1984
 *      Look in /usr/people/4Dgifts/iristools/imgtools for example code!
 *
 */

#include <stdio.h>

#define IMAGIC 	0732

/* colormap of images */
#define CM_NORMAL		0	/* file contains rows of values which 
					 * are either RGB values (zsize == 3) 
					 * or greyramp values (zsize == 1) */
#define CM_DITHERED		1
#define CM_SCREEN		2	/* file contains data which is a screen
					 * image; getrow returns buffer which 
					 * can be displayed directly with 
					 * writepixels */
#define CM_COLORMAP		3	/* a colormap file */

#define TYPEMASK		0xff00
#define BPPMASK			0x00ff
#define ITYPE_VERBATIM		0x0000
#define ITYPE_RLE		0x0100
#define ISRLE(type)		(((type) & 0xff00) == ITYPE_RLE)
#define ISVERBATIM(type)	(((type) & 0xff00) == ITYPE_VERBATIM)
#define BPP(type)		((type) & BPPMASK)
#define RLE(bpp)		(ITYPE_RLE | (bpp))
#define VERBATIM(bpp)		(ITYPE_VERBATIM | (bpp))
#define	IBUFSIZE(pixels)	(((pixels)+((pixels)>>6))<<2)
#define	RLE_NOP			0x00

#define	ierror(p)		(((p)->flags&_IOERR)!=0)
#define	ifileno(p)		((p)->file)
#define	getpix(p)		(--(p)->cnt>=0 ? *(p)->ptr++ : ifilbuf(p))
#define putpix(p,x)		(--(p)->cnt>=0 \
				    ? ((int)(*(p)->ptr++=(unsigned)(x))) \
				    : iflsbuf(p,(unsigned)(x)))

typedef struct {
    unsigned short	imagic;		/* stuff saved on disk . . */
    unsigned short 	type;
    unsigned short 	dim;
    unsigned short 	xsize;
    unsigned short 	ysize;
    unsigned short 	zsize;
    unsigned long 	min;
    unsigned long 	max;
    unsigned long	wastebytes;	
    char 		name[80];
    unsigned long	colormap;

    long 		file;		/* stuff used in core only */
    unsigned short 	flags;
    short		dorev;
    short		x;
    short		y;
    short		z;
    short		cnt;
    unsigned short	*ptr;
    unsigned short	*base;
    unsigned short	*tmpbuf;
    unsigned long	offset;
    unsigned long	rleend;		/* for rle images */
    unsigned long	*rowstart;	/* for rle images */
    long		*rowsize;	/* for rle images */
} IMAGE;

IMAGE *icreate();
/*
 * IMAGE *iopen(char *file, char *mode, unsigned int type, unsigned int dim,
 * 		unsigned int xsize, unsigned int ysize, unsigned int zsize);
 * IMAGE *fiopen(int f, char *mode, unsigned int type, unsigned int dim,
 * 		unsigned int xsize, unsigned int ysize, unsigned int zsize);
 *
 * ...while iopen and fiopen can take an extended set of parameters, the 
 * last five are optional, so a more correct prototype would be:
 *
 */
IMAGE *iopen(char *file, char *mode, ...);
IMAGE *fiopen(int f, char *mode, ...);

/*
 * 
 * unsigned short *ibufalloc(IMAGE *image);
 * int ifilbuf(IMAGE *image);
 * int iflush(IMAGE *image);
 * unsigned int iflsbuf(IMAGE *image, unsigned int c);
 * void isetname(IMAGE *image, char *name);
 * void isetcolormap(IMAGE *image, int colormap);
 */

int iclose(IMAGE *image);
int putrow(IMAGE *image, unsigned short *buffer, unsigned int y, unsigned int z);
int getrow(IMAGE *image, unsigned short *buffer, unsigned int y, unsigned int z);

/*
IMAGE *iopen();
IMAGE *icreate();
*/

unsigned short *ibufalloc();

#define IMAGEDEF		/* for backwards compatibility */
#ifdef __cplusplus
}
#endif
#endif	/* !__GL_IMAGE_H__ */
