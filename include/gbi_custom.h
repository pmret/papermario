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

#endif
