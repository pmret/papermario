/*======================================================================*/
/*		NuSYS	Audio Library for SGI Library & naudio		*/
/*		nualsgi.h						*/
/*									*/
/*		Copyright (C) 1997, NINTENDO Co,Ltd.			*/
/*									*/
/*	$Id: nualsgi.h,v 1.10 1999/01/14 05:45:36 ohki Exp ohki $	*/
/*======================================================================*/
#ifndef _NUALSGI_H_
#define _NUALSGI_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*	DEFINE								*/
/*----------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/* AUDIO  MANAGER DEFINE							*/
/*----------------------------------------------------------------------*/
/*	AUDIO HEAP calculation					*/
/*									*/
/*  (1) alInit heap size							*/
/* AUDIO HEAP calls the function alHeapAlloc to allocate heap memory when synthesizer, 	*/
/* sequence, or sound drivers are initialized. 					*/
/* The size of the alHeap area required is determined as follows. 			*/
/*									*/
/*									*/
/*  144 + maxPVoices * 432 + 32 * maxUPdates + FxType			*/
/*									*/
/* FxType varies with the type of effect and takes the following values. */
/* AL_FX_NONE		0						*/
/* AL_FX_SMALLROOM	8192						*/
/* AL_FX_BIGROOM	8224						*/
/* AL_FX_ECHO		1640						*/
/* AL_FX_CHORUS		304						*/
/* AL_FX_FLANGE		304						*/
/*									*/
/*  (2) Heap size for alSeqpNew and alCSPNew					*/
/* 									*/
/* maxChannels * 16 + maxVoices * 64 + maxEvents * 32			*/
/*									*/
/* (3)Heap size for alSndpNew						*/
/*									*/
/* maxSounds * 48 + maxEvents * 32					*/
/*									*/
/*----------------------------------------------------------------------*/
/*--------------------------------------*/
/* SYNTHE DEFINE			*/
/*--------------------------------------*/
#define	NU_AU_SYN_VVOICE_MAX	64	/* Maximum number of virtual voices (Not actually used).*/
#define NU_AU_SYN_PVOICE_MAX	32	/* Maximum number of physical voices. */
#define NU_AU_SYN_UPDATE_MAX	128	/* Maximum number of synthesizer parameter updates*/
#define	NU_AU_SYN_HEAP_SIZE	(144+NU_AU_SYN_PVOICE_MAX*432+32*NU_AU_SYN_UPDATE_MAX+0x2000)

/*--------------------------------------*/
/* SEQUENCE DEFINE			*/
/*--------------------------------------*/
#define NU_AU_SEQ_VOICE_MAX	24      /* Maximum number of voices*/
#define NU_AU_SEQ_EVENT_MAX	48      /* Number of events */
#define NU_AU_SEQ_CHANNEL_MAX	16      /* Number of MIDI channels (typically 16) */
#define	NU_AU_SEQ_HEAP_SIZE	(16*NU_AU_CHANNEL_MAX+32*NU_AU_EVENT_MAX)
#define NU_AU_SEQ_PLAYER0	0
#define NU_AU_SEQ_PLAYER1	1
#define	NU_AU_SEQ_MODE_FADEOUT		0x0001
#define	NU_AU_SEQ_MODE_PLAYPENDING	0x0002


/*--------------------------------------*/
/* SOUND DEFINE				*/
/*--------------------------------------*/
#define NU_AU_SND_SOUND_MAX	8     /* Maximum number of sounds*/
#define NU_AU_SND_EVENT_MAX	(NU_AU_SND_SOUND_MAX*2)   /* Maximum number of events */
#define NU_AU_SND_HEAP_SIZE	(NU_AU_SND_SOUND_MAX*48+NU_AU_SND_EVENT*64)

/*--------------------------------------*/
/* AUDIO DMA DEFINE			*/
/*--------------------------------------*/
#define	NU_AU_DMA_BUFFER_NUM	64	/* Number of DMA transfer buffers */
#define	NU_AU_DMA_BUFFER_SIZE	1024    /* Size of the DMA buffer	*/
#define NU_AU_BUFFER_USE_FRAME  1	/* Frame interval for the cleared DMA buffer */

/*--------------------------------------*/
/* SOUND DEFINE				*/
/*--------------------------------------*/
#define	NU_AU_MGR_THREAD_PRI	70
#define	NU_AU_MGR_THREAD_ID	6
#define NU_AU_STACK_SIZE	0x2000
#define	NU_AU_CLIST_LEN		0x800
#define	NU_AU_CLIST_SIZE	(NU_AU_CLIST_LEN*sizeof(Acmd))    /* Buffer size for the command list */

#define	NU_AU_BUFFER_MAX	0x1000 /* Size of the buffer for the synthesizer */
#define	NU_AU_OUTPUT_RATE	32000   /* Set the frequency. */
#define	NU_AU_MESG_MAX		8
#define	NU_AU_HEAP_MIN_SIZE	(NU_AU_SND_HEAP_SIZE+NU_AU_SEQ_HEAP_SIZE+NU_AU_SYN_HEAP_SIZE+NU_AU_DMA_BUFFER_NUM*NU_AU_DMA_BUFFER_SIZE+NU_AU_CLIST_SIZE*2)
#define NU_AU_HEAP_SIZE		0x50000	/* Default HEAP size */
#define NU_AU_HEAP_ADDR		(NU_GFX_FRAMEBUFFER_ADDR - NU_AU_HEAP_SIZE)

#ifdef N_AUDIO
#define	NU_AU_AUDIO_SAMPLES	184	/* Sample number is a multiple of 16. */
#else
#define	NU_AU_AUDIO_SAMPLES	16	/* Sample number is a multiple of 16. */
#endif	/* N_AUDIO */

#define NU_AU_AUDIO_EXTRASMP	0	/* Number of extra samples		*/

#define NU_AU_TASK_STOP		0	/* Stop audio task execution. */
#define NU_AU_TASK_RUN		1	/* Allow audio task execution. */

#define NU_AU_AI_FIFO_MSG	0x100	/* AI event  message	*/
#define NU_AU_AI_DEBUG_MSG	0x1000	/* For AI debugging		*/

#define	NU_AU_FRAMERATE_NTSC	60	/* NTSC/MPAL		*/
#define	NU_AU_FRAMERATE_PAL	50	/* PAL			*/

/*--------------------------------------*/
/* DEBUG & PERFORMANCE			*/
/*--------------------------------------*/
#define	NU_AU_DEBUG_NORMAL	0x00000001	/* warning & error 	*/
#define	NU_AU_DEBUG_DISABLEDMA	0x00010000	/* disable dma callback	*/
#define	NU_AU_DEBUG_DISABLEAI	0x00020000	/* disable set AI	*/
#define	NU_AU_DEBUG_DISABLETASK	0x00040000	/* disable task		*/
#define	NU_AU_DEBUG_FIFOOFF	0x00080000	/* FIFO EVENT OFF	*/
#define	NU_AU_DEBUG_RETRACEOFF	0x00100000	/* RETRACE EVENT OFF	*/

#define NU_AU_DEBUG_NODMABUF	0x00000001		/* No DMA Buffer 	*/
#define NU_AU_DEBUG_ACMDBUFOVER 0x00000002		/* Acmd buffer is small */
#define NU_AU_DEBUG_DMABUFSIZE	0x00000004	/* dma buffer size is small */
#define	NU_AU_DEBUG_DMANOTCOMPLETE    0x00000008 /* dma not completed 	*/

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)
#include <ultra64.h>
#ifdef	N_AUDIO
#include <PR/n_libaudio.h>
#include <PR/n_libaudio_s_to_n.h>
#else	/* N_AUDIO */
#include <PR/libaudio.h>
#endif	/* N_AUDIO */

/*--------------------------------------*/
/* audio typedef			*/
/*--------------------------------------*/
/*--------------------------------------*/
/* DMA BUFFER STRUCT			*/
/*--------------------------------------*/
typedef struct {
    ALLink	node;		/* Pointer to the linked list*/
    s32		startAddr;		/* Address in data ROM */
    s32		frameCnt;		/* Buffer frame counter */
    char*	ptr;			/* Value of the pointer to buffer */
} NUDMABuffer;
/*--------------------------------------*/
/* DMA callback for the Sequence Player	*/
/* DMA status used by the routines	*/
/* Structure that stores the use status of the DMABuffer*/
/*--------------------------------------*/
typedef struct {
    u8		initialized;  /* Flag indicating whether the structure has been initialized */
    NUDMABuffer* firstUsed;   /* Start of the DMA Buffer linked list being used */
    NUDMABuffer* firstFree;   /* Start of the free DMA Buffer linked list */
} NUDMAState;

/* Sequence Display structure*/
typedef struct st_Seqence{
    ALCSPlayer	player;     	/* Sequence Display structure */
    ALCSeq	sequence;
    u8*		data_ptr;       /* Sequence data */
    s32		seqno;          /* Sequence No. */
    u32		mode;		/* Control extension */
    u16		counter;
    u16		speed;
} NUAuSeqPlayer;

typedef struct st_SndState {
    ALSndId*	Id;
    u8		flag;
} NUAuSndId;


/*--------------------------------------*/
/* CALL BACK Function	typedef		*/
/*--------------------------------------*/
typedef void (*NUAuPreNMIFunc)(NUScMsg,u32);	/* PRENMI callback function */
typedef void (*NUAuMgrFunc)(void);		/* Acmd callback function */

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/* extern variables 							*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*--------------------------------------*/
/*  audio variables 			*/
/*--------------------------------------*/
extern u64*		nuAuMgrStack;
extern NUScTask		nuAuTask;		/* Audio task buffer*/
extern s16*		nuAuBuffer_ptr[];		/* Audio buffer */
extern NUScClient	nuAuClient;
extern OSThread		nuAuMgrThread;
extern u32		nuAuFrameCounter;		/* Frame counter */
extern ALHeap		nuAuHeap;		/* Heap structure */
extern NUAuSeqPlayer	nuAuSeqPlayer[];
extern u8*		nuAuSeqData;
extern ALBankFile*	nuAuSeqBank_ptr;
extern ALSeqFile*	nuAuSeqFile_ptr;
extern ALSndPlayer	nuAuSndPlayer;
extern ALBankFile*	nuAuSndBank_ptr;
extern ALSndId*       	nuAuSndId;
extern ALSynConfig	nuAuSynConfig;
extern ALSeqpConfig	nuAuSeqpConfig;
extern ALSndpConfig	nuAnSndpConfig;
extern u8		nuAuTaskStop;
extern u8		nuAuPreNMI;
extern NUAuPreNMIFunc	nuAuPreNMIFunc;
extern NUAuMgrFunc	nuAuMgrFunc;
extern OSMesgQueue	nuAuMesgQ;	/* Audio Manager queue	*/
extern ALGlobals	nuAuGlobal;
extern s16		nuAuDmaBufNum;
extern s16		nuAuDmaBufSize;
extern NUDMAState	nuAuDmaState;
extern NUDMABuffer*	nuAuDmaBuf;
extern Acmd*		nuAuCmdListBuf; 	/* pointer of command list */
extern u32		nuAuAcmdLen;
extern u8		nuAuRetraceCount;


extern u32		nuAuDebFlag;
extern u32		nuAuDebStatus;		/* Status flag		*/
extern u32		nuAuDebDmaCount;	/* Total number of PI-DMAs		*/
extern u32		nuAuDebDmaFrame;	/* DMA counter	*/
extern u32		nuAuDebDmaMax;	/* Maximum number of PI-DMAs	*/
extern u32		nuAuDebDmaBufMaxUse;/* Maximum number of DMA buffers used */
extern u32		nuAuDebDmaCallbackCount;/* Total number of DMA callbacks	*/
extern u32		nuAuDebDmaCallbackFrame;/* Number of DMA callbacks	*/
extern u32		nuAuDebDmaCallbackMax; /* Maximum number of DMA callbacks*/
extern u32		nuAuDebAcmdLenMax;	/* Maximum length of the audio command list */

extern s16		nuAuFrameSampleSize;	/* Number of samples created at one time */
extern s16		nuAuExtraSampleSize;	/* Number of extra samples */
extern ALSynConfig	nuAuSynConfig;
extern ALSeqpConfig	nuAuSeqpConfig;
extern ALSndpConfig	nuAuSndpConfig;

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/* Global Function 							*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*--------------------------------------*/
/* audio  Manager function		*/
/*--------------------------------------*/
extern s32 nuAuInit(void);
extern s32 nuAuInitEx(void);
extern s32 nuAuMgrInit(void* heap_ptr, u32 size, ALSynConfig* synconfig);
extern s32 nuAuMgrInitEx(void* heap_ptr, u32 size, ALSynConfig* synConfig);

extern void nuAuSeqPlayerInit(ALSeqpConfig* seqpconfig, u32 size, u32 player_no);
extern void nuAuSeqPlayerBankSet(u8* bank_addr, u32 bank_size, u8* table_addr);
extern void nuAuSeqPlayerPlay(u32 player_no);
extern void nuAuSeqPlayerSeqSet(u8* seq_addr);
extern void nuAuSeqPlayerSetNo(u32 player_no ,u32 seq_no);
extern void nuAuSeqPlayerFadeOut(u32 player_no ,u32 speed);
extern void nuAuSeqPlayerControl(void);

extern void nuAuSndPlayerInit(ALSndpConfig* sndconfig);
extern void nuAuSndPlayerBankSet(u8* bank_addr, u32 bank_size, u8* table_addr);
extern ALSndId nuAuSndPlayerPlay(u32 sndNo);
extern void nuAuPreNMIFuncSet(NUAuPreNMIFunc func);
extern void nuAuPreNMIProc(NUScMsg mesg_type, u32 frameCounter);
extern void nuAuMgrFuncSet(NUAuMgrFunc func);
extern ALDMAproc nuAuDmaNew(NUDMAState **state);
extern void	nuAuCleanDMABuffers(void);

extern void nuAuHeapInit(ALHeap* hp, u8* base, s32 len);
extern void* nuAuHeapAlloc(s32 length);
extern s32 nuAuHeapGetFree(void);
extern s32 nuAuHeapGetUsed(void);

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/* MACRO	 							*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/* Delete the callback function */
#define nuAuPreNMIFuncRemove()	nuAuPreNMIFuncSet(NULL)
#define nuAuMgrFuncRemove()	nuAuMgrFuncSet(NULL)

#define nuAuSeqPlayerGetChlVol(player_no, chan)				\
	alCSPGetChlVol(&nuAuSeqPlayer[player_no].player, chan)
#define nuAuSeqPlayerGetChlFXMix(player_no, chan)			\
	alCSPGetChlFXMix(&nuAuSeqPlayer[player_no].player, chan)
#define nuAuSeqPlayerGetChlPan(player_no, chan)				\
	alCSPGetChlPan(&nuAuSeqPlayer[player_no].player, chan)
#define nuAuSeqPlayerGetChlPriority(player_no, chan)			\
	alCSPGetChlPriority(&nuAuSeqPlayer[player_no].player, chan)
#define nuAuSeqPlayerGetChlProgram(player_no, chan)			\
	alCSPGetChlProgram(&nuAuSeqPlayer[player_no].player, chan)
#define nuAuSeqPlayerGetSeq(player_no)				\
	alCSPGetSeq(&nuAuSeqPlayer[player_no].player)
#define nuAuSeqPlayerGetSeqno(player_no)				\
        nuAuSeqPlayer[player_no].seqno
#define nuAuSeqPlayerGetState(player_no)				\
	alCSPGetState(&nuAuSeqPlayer[player_no].player)
#define nuAuSeqPlayerGetTempo(player_no)				\
	alCSPGetTempo(&nuAuSeqPlayer[player_no].player)
#define nuAuSeqPlayerGetVol(player_no)					\
	alCSPGetVol(&nuAuSeqPlayer[player_no].player)
#define nuAuSeqPlayerStop(player_no)				\
	alCSPStop(&nuAuSeqPlayer[player_no].player)
#define nuAuSeqPlayerSetVol(player_no, vol)			\
	alCSPSetVol(&nuAuSeqPlayer[player_no].player, vol)
#define nuAuSeqPlayerSetTempo(player_no, tempo)			\
	alCSPSetTempo(&nuAuSeqPlayer[player_no].player, tempo)
#define nuAuSeqPlayerSetChlProgram(player_no, chan, prog)	\
	alCSPSetChlProgram(&nuAuSeqPlayer[player_no].player, chan, prog)
#define nuAuSeqPlayerSetChlPriority(player_no, chan, priority)	\
	alCSPSetChlPriority(&nuAuSeqPlayer[player_no].player, chan, priority)
#define nuAuSeqPlayerSetChlPan(player_no, chan, pan)	\
	alCSPSetChlPan(&nuAuSeqPlayer[player_no].player, chan, pan)
#define nuAuSeqPlayerSetChlFXMix(player_no, chan, fxmix)	\
	alCSPSetChlFXMix(&nuAuSeqPlayer[player_no].player, chan, fxmix)
#define nuAuSeqPlayerSetChlVol(player_no, chan, vol)	\
	alCSPSetChlVol(&nuAuSeqPlayer[player_no].player, chan, vol)
#define nuAuSeqPlayerSendMidi(player_no, ticks, status, byte1, byte2)	\
	alCSPSetPlayerSendMidi(&nuAuSeqPlayer[player_no].player, ticks, status, byte1, byte2)

#define nuAuSndPlayerGetState()		alSndpGetState(&nuAuSndPlayer)
#define nuAuSndPlayerPlayAt(delta)	alSndpPlayAt(&nuAuSndPlayer,delta)
#define nuAuSndPlayerSetFXMix(mix)	alSndpSetFXMix(&nuAuSndPlayer,mix)
#define nuAuSndPlayerSetPan(pan)	alSndpSetPan(&nuAuSndPlayer,pan)
#define nuAuSndPlayerSetPitch(pitch)	alSndpSetPitch(&nuAuSndPlayer,pitch)
#define nuAuSndPlayerSetPriority(id,priority)	alSndpSetPriority(&nuAuSndPlayer,id,priority)
#define nuAuSndPlayerSetVol(vol)	alSndpSetVol(&nuAuSndPlayer,vol)
#define nuAuSndPlayerStop()	alSndpStop(&nuAuSndPlayer)
#define nuAuSndPlayerSetSound(SndId)	alSndpSetSound(&nuAuSndPlayer,SndId)


/*----------------------------------------------------------------------*/
#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */
#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif
#endif /* _NUALSGI_H_ */
