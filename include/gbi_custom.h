#ifndef _GBI_CUSTOM_H_
#define _GBI_CUSTOM_H_

#include "ultra64.h"

#define	gDPScrollMultiTile2_4b(pkt, timg, fmt, width, height,	\
		uls, ult, lrs, lrt, pal,				\
		cms, cmt, masks, maskt, shifts, shiftt,\
    scrolls, scrollt)			\
{									\
	gDPSetTextureImage(pkt, fmt, G_IM_SIZ_8b, ((width)>>1), timg);	\
	gDPSetTile(pkt, fmt, G_IM_SIZ_8b, 			        \
		   (((((lrs)-(uls)+1)>>1)+7)>>3), 0,			\
		   G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks,	\
		   shifts);						\
	gDPLoadSync(pkt);						\
	gDPLoadTile(	pkt, G_TX_LOADTILE,				\
			(uls)<<(G_TEXTURE_IMAGE_FRAC-1),		\
			(ult)<<(G_TEXTURE_IMAGE_FRAC),			\
			(lrs)<<(G_TEXTURE_IMAGE_FRAC-1),		\
			(lrt)<<(G_TEXTURE_IMAGE_FRAC));			\
	gDPPipeSync(pkt);						\
	gDPSetTile(pkt, fmt, G_IM_SIZ_4b, 				\
		   (((((lrs)-(uls)+1)>>1)+7)>>3), 0,			\
		   G_TX_RENDERTILE + 1, 0, cmt, maskt, shiftt, cms, masks,		\
		   shifts);						\
	gDPSetTileSize(pkt, G_TX_RENDERTILE + 1,					\
			(uls + scrolls)<<G_TEXTURE_IMAGE_FRAC,			\
			(ult + scrollt)<<G_TEXTURE_IMAGE_FRAC,			\
			(lrs + scrolls)<<G_TEXTURE_IMAGE_FRAC,			\
			(lrt + scrollt)<<G_TEXTURE_IMAGE_FRAC)			\
	gDPSetTile(pkt, fmt, G_IM_SIZ_4b, 				\
		   (((((lrs)-(uls)+1)>>1)+7)>>3), 0,			\
		   G_TX_RENDERTILE + 0, 1, cmt, maskt, shiftt, cms, masks,		\
		   shifts);						\
}


#define	gDPScrollTextureTile_4b(pkt, timg, fmt, width, height,	\
		uls, ult, lrs, lrt, pal,				\
		cms, cmt, masks, maskt, shifts, shiftt, \
    scrolls, scrollt)			\
							\
	gDPSetTextureImage(pkt, fmt, G_IM_SIZ_8b, ((width)>>1), timg);	\
	gDPSetTile(pkt, fmt, G_IM_SIZ_8b, 			        \
		   (((((lrs)-(uls)+1)>>1)+7)>>3), 0,			\
		   G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks,	\
		   shifts);						\
	gDPLoadSync(pkt);						\
	gDPLoadTile(	pkt, G_TX_LOADTILE,				\
			(uls)<<(G_TEXTURE_IMAGE_FRAC-1),		\
			(ult)<<(G_TEXTURE_IMAGE_FRAC),			\
			(lrs)<<(G_TEXTURE_IMAGE_FRAC-1),		\
			(lrt)<<(G_TEXTURE_IMAGE_FRAC));			\
	gDPPipeSync(pkt);						\
	gDPSetTile(pkt, fmt, G_IM_SIZ_4b, 				\
		   (((((lrs)-(uls)+1)>>1)+7)>>3), 0,			\
		   G_TX_RENDERTILE, 0, cmt, maskt, shiftt, cms, masks,		\
		   shifts);						\
	gDPSetTileSize(pkt, G_TX_RENDERTILE,					\
			(uls + scrolls)<<G_TEXTURE_IMAGE_FRAC,			\
			(ult + scrollt)<<G_TEXTURE_IMAGE_FRAC,			\
			(lrs + scrolls)<<G_TEXTURE_IMAGE_FRAC,			\
			(lrt + scrollt)<<G_TEXTURE_IMAGE_FRAC)			\


#define	gDPScrollTextureBlock_4b(pkt, timg, fmt, width, height,		\
		pal, cms, cmt, masks, maskt, shifts, shiftt, scrolls, scrollt)		\
{									\
	gDPSetTextureImage(pkt, fmt, G_IM_SIZ_16b, 1, timg);		\
	gDPSetTile(pkt, fmt, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0,	\
		cmt, maskt, shiftt, cms, masks, shifts);		\
	gDPLoadSync(pkt);						\
	gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0,				\
		(((width)*(height)+3)>>2)-1,				\
		CALC_DXT_4b(width)); 					\
	gDPPipeSync(pkt);						\
	gDPSetTile(pkt, fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), 0,	\
		G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks,	\
		shifts);						\
	gDPSetTileSize(pkt, G_TX_RENDERTILE,\
        (scrolls) << G_TEXTURE_IMAGE_FRAC,\
        (scrollt) << G_TEXTURE_IMAGE_FRAC,			\
		((width)-1 + scrolls) << G_TEXTURE_IMAGE_FRAC,			\
		((height)-1 + scrollt) << G_TEXTURE_IMAGE_FRAC)			\
}

#define	gDPScrollMultiTile_4b(pkt, timg, tmem, rtile, fmt, width, height,	\
		uls, ult, lrs, lrt, pal,				\
		cms, cmt, masks, maskt, shifts, shiftt,\
    scrolls, scrollt)			\
{									\
	gDPSetTextureImage(pkt, fmt, G_IM_SIZ_8b, ((width)>>1), timg);	\
	gDPSetTile(pkt, fmt, G_IM_SIZ_8b, 			        \
		   (((((lrs)-(uls)+1)>>1)+7)>>3), tmem,			\
		   G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks,	\
		   shifts);						\
	gDPLoadSync(pkt);						\
	gDPLoadTile(	pkt, G_TX_LOADTILE,				\
			(uls)<<(G_TEXTURE_IMAGE_FRAC-1),		\
			(ult)<<(G_TEXTURE_IMAGE_FRAC),			\
			(lrs)<<(G_TEXTURE_IMAGE_FRAC-1),		\
			(lrt)<<(G_TEXTURE_IMAGE_FRAC));			\
	gDPPipeSync(pkt);						\
	gDPSetTile(pkt, fmt, G_IM_SIZ_4b, 				\
		   (((((lrs)-(uls)+1)>>1)+7)>>3), tmem,			\
		   rtile, pal, cmt, maskt, shiftt, cms, masks,		\
		   shifts);						\
	gDPSetTileSize(pkt, rtile,					\
			((uls)<<G_TEXTURE_IMAGE_FRAC) + scrolls,			\
			((ult)<<G_TEXTURE_IMAGE_FRAC) + scrollt,			\
			((lrs)<<G_TEXTURE_IMAGE_FRAC) + scrolls,			\
			((lrt)<<G_TEXTURE_IMAGE_FRAC) + scrollt);      \
}

#define	gDPScrollMultiTile(pkt, timg, tmem, rtile, fmt, siz, width, height,\
		uls, ult, lrs, lrt, pal,				\
		cms, cmt, masks, maskt, shifts, shiftt, scrolls, scrollt)			\
{									\
	gDPSetTextureImage(pkt, fmt, siz, width, timg);			\
	gDPSetTile(pkt, fmt, siz,					\
		(((((lrs)-(uls)+1) * siz##_TILE_BYTES)+7)>>3), tmem,	\
		G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks,	\
		shifts);						\
	gDPLoadSync(pkt);						\
	gDPLoadTile(	pkt, G_TX_LOADTILE,				\
			(uls)<<G_TEXTURE_IMAGE_FRAC,			\
			(ult)<<G_TEXTURE_IMAGE_FRAC,			\
			(lrs)<<G_TEXTURE_IMAGE_FRAC,			\
			(lrt)<<G_TEXTURE_IMAGE_FRAC);			\
	gDPPipeSync(pkt);						\
	gDPSetTile(pkt, fmt, siz,					\
		(((((lrs)-(uls)+1) * siz##_LINE_BYTES)+7)>>3), tmem,	\
		rtile, pal, cmt, maskt, shiftt, cms, masks,		\
		shifts);						\
	gDPSetTileSize(pkt, rtile,					\
			((uls)<<G_TEXTURE_IMAGE_FRAC) + scrolls,			\
			((ult)<<G_TEXTURE_IMAGE_FRAC) + scrollt,			\
			((lrs)<<G_TEXTURE_IMAGE_FRAC) + scrolls,			\
			((lrt)<<G_TEXTURE_IMAGE_FRAC) + scrollt);      \
}

#define	gDPScrollTextureBlockHalfHeight(pkt, timg, fmt, siz, width, height,		\
		pal, cms, cmt, masks, maskt, shifts, shiftt, scrolls, scrollt, shifts2, shiftt2)		\
{									\
	gDPSetTextureImage(pkt, fmt, siz##_LOAD_BLOCK, 1, timg);	\
	gDPSetTile(pkt, fmt, siz##_LOAD_BLOCK, 0, 0, G_TX_LOADTILE, 	\
		0 , cmt, maskt, shiftt, cms, masks, shifts);		\
	gDPLoadSync(pkt);						\
	gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, 				\
		(((width)*(height) + siz##_INCR) >> siz##_SHIFT) -1,	\
		CALC_DXT(width, siz##_BYTES)); 				\
	gDPPipeSync(pkt);						\
	gDPSetTile(pkt, fmt, siz,					\
		(((width) * siz##_LINE_BYTES)+7)>>3, 0,			\
		G_TX_RENDERTILE, pal, cmt, maskt - 1, shiftt, cms, masks,	\
		shifts);						\
	gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0,			\
		((width)-1) << G_TEXTURE_IMAGE_FRAC,			\
		(((height) >> 1)-1) << G_TEXTURE_IMAGE_FRAC)			\
    gDPSetTile(pkt, fmt, siz,					\
		(((width) * siz##_LINE_BYTES)+7)>>3, \
        (((width) * ((height) >> 1) * siz##_LINE_BYTES)+7)>>3,			\
		G_TX_RENDERTILE + 1, pal, cmt, maskt - 1, shiftt2, cms, masks,	\
		shifts2);						\
	gDPSetTileSize(pkt, G_TX_RENDERTILE + 1,			\
        (scrolls),\
        (scrollt),			\
		(((width)-1) << G_TEXTURE_IMAGE_FRAC) + (scrolls),			\
		((((height) >> 1)-1) << G_TEXTURE_IMAGE_FRAC)  + (scrollt)	);		\
}

#define	gDPScrollTextureBlockHalfHeight_4b(pkt, timg, fmt, width, height,		\
		pal, cms, cmt, masks, maskt, shifts, shiftt, scrolls, scrollt, shifts2, shiftt2)		\
{									\
	gDPSetTextureImage(pkt, fmt, G_IM_SIZ_16b, 1, timg);		\
	gDPSetTile(pkt, fmt, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0,	\
		cmt, maskt, shiftt, cms, masks, shifts);		\
	gDPLoadSync(pkt);						\
	gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0,				\
		(((width)*(height)+3)>>2)-1,				\
		CALC_DXT_4b(width)); 					\
	gDPPipeSync(pkt);						\
	gDPSetTile(pkt, fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), 0,	\
		G_TX_RENDERTILE, pal, cmt, maskt - 1, shiftt, cms, masks,	\
		shifts);						\
	gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0,			\
		((width)-1) << G_TEXTURE_IMAGE_FRAC,			\
		(((height) >> 1)-1) << G_TEXTURE_IMAGE_FRAC)			\
    gDPSetTile(pkt, fmt, G_IM_SIZ_4b,					\
		(((width)>>1)+7)>>3, \
        (((width) * ((height) >> 1) / 2)+7)>>3,			\
		G_TX_RENDERTILE + 1, pal, cmt, maskt - 1, shiftt2, cms, masks,	\
		shifts2);						\
	gDPSetTileSize(pkt, G_TX_RENDERTILE + 1,			\
        scrolls,\
        scrollt,			\
		(((width)-1) << G_TEXTURE_IMAGE_FRAC) + scrolls,			\
		((((height) >> 1)-1) << G_TEXTURE_IMAGE_FRAC)  + scrollt)		\
}

#endif
