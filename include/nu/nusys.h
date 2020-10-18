/*======================================================================*/
/*		NuSYS 							*/
/*		nusys.h							*/
/*									*/
/*		Copyright (C) 1997, NINTENDO Co,Ltd.			*/
/*									*/
/*----------------------------------------------------------------------*/
/* Ver 1.0	97/10/09	Created  by Kensaku Ohki(SLANP)		*/
/* Ver 1.2	98/07/12	Modified by Kensaku Ohki(SLANP)		*/
/* Ver 2.0	90/01/23	Modified by Kensaku Ohki(SLANP)		*/
/*----------------------------------------------------------------------*/
/* $Id: nusys.h,v 1.26 1999/05/07 08:23:45 ohki Exp ohki $		*/
/*======================================================================*/
#ifndef _NUSYS_H_
#define _NUSYS_H_

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

#ifndef F3DEX_GBI
#define	F3DEX_GBI
#endif	/* F3DEX_GBI */

#include <ultra64.h>
#include <PR/gs2dex.h>
#endif

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/*----------------------------------------------------------------------*/    
/*----------------------------------------------------------------------*/
/*	DEFINE								*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
#define NU_VERSION		"2.05"

/*--------------------------------------*/
/* NuSystem spec define			*/
/*--------------------------------------*/
#define NU_SPEC_BOOT_STACK_SIZE	0x2000
#define	NU_SPEC_BOOT_ADDR	0x80025c00
#define NU_SPEC_BOOT_STACK	nuMainStack + NU_SPEC_BOOT_STACK_SIZE

/*--------------------------------------*/
/* Thread ID for DEBUG 	(a precaution)	*/
/*--------------------------------------*/
#define NU_IDLE_THREAD_ID	1
#define NU_RMON_THREAD_ID	2	/* no use */
#define NU_MAIN_THREAD_ID	3

									
/*--------------------------------------*/
/* NuSYS Thread Priority		*/
/*--------------------------------------*/
#define NU_IDLE_THREAD_PRI	OS_PRIORITY_IDLE	/* Idle thread	*/
#define NU_RMON_THREAD_PRI	OS_PRIORITY_RMON	/* no use	*/
#define NU_MAIN_THREAD_PRI	10			/* main thread	*/
    
/*--------------------------------------*/
/* NUSYS STACK SIZE			*/
/*--------------------------------------*/
#define NU_IDLE_STACK_SIZE	0x2000			/* Idle thread */
#define	NU_RMON_STACK_SIZE	0x2000			/* Rmon thread */
#define NU_MAIN_STACK_SIZE	NU_SPEC_BOOT_STACK_SIZE	/* Main thread */




/*----------------------------------------------------------------------*/
/* SCHEDULER DEFINE							*/
/*----------------------------------------------------------------------*/
#define NU_SC_STACK_SIZE	0x2000		/*  Thread stack size */
#define NU_SC_NOSWAPBUFFER	0x0000		/* No swap */
#define NU_SC_SWAPBUFFER	0x0001		/* Swap frame buffer */
#define NU_SC_NORDP		0x0002		/* Do not wait for RDP finish	*/
#define	NU_SC_UCODE_XBUS	0x0004		/* XBUS Ucode		*/
#define	NU_SC_TASK_YIELDED	(OS_TASK_YIELEDE<<16)
#define	NU_SC_TASK_DP_WAIT	(OS_TASK_DP_WAIT<<16)	/* RDP WAIT	*/
#define	NU_SC_TASK_LODABLE	(OS_TASK_LOADBLE<<16)	/* LOADABLE	*/     
#define	NU_SC_TASK_SP_ONLY	(OS_TASK_SP_ONLY<<16)	/* SP ONLY	*/

							   
#define NU_SC_RETRACE_MSG	0x0001		/* Retrace message */
#define NU_SC_PRENMI_MSG	0x0002		/* NMI message */
#define NU_SC_SWAPBUFFER_MSG	0x0004	/* Swap frame buffer message*/ 
#define NU_SC_GTASKEND_MSG	0x0008	/* Task finished message */
#define NU_SC_MAX_MESGS		8	/* Message buffer size */

#define NU_SC_HANDLER_PRI	120	/* EVENT HANDLER THREAD PRORITY */
#define NU_SC_AUDIO_PRI		110	/* AUDIO DISPATCHER THREAD PRORITY */
#define NU_SC_GRAPHICS_PRI	100	/* GFX DISPATCHER THREAD PRORITY */
#define NU_SC_HANDLER_THREAD_ID	19
#define NU_SC_AUDIO_THREAD_ID	18
#define NU_SC_GRAPHICS_THREAD_ID 17   
#define	NU_SC_PRENMI_YET	0	/* PRE NMI has not occurred. */
#define	NU_SC_PRENMI_GET	1	/* PRE NMI received flag */
#define	NU_SC_BEFORE_RESET 	2	/* Pre-RESET flag for frame before reset  */
#define	NU_SC_BEFORE_RESET_FRAME 2	/* Number of frames before reset where BEFORE_RESET flag is set. */
/*----------------------------------------------------------------------*/
/* GRAFIC THREAD DEFINE							*/
/*----------------------------------------------------------------------*/
#define NU_GFX_THREAD_ID	4	
#define NU_GFX_TASKMGR_THREAD_ID 5
#define NU_GFX_STACK_SIZE	0x2000			/* Thread stack size */
#define	NU_GFX_MESGS		8		/* GFX message queue*/
#define NU_GFX_TASKMGR_STACK_SIZE 0x2000	/* Stack size */
#define	NU_GFX_TASKMGR_MESGS	8		/*Task Manager queue*/
#define NU_GFX_THREAD_PRI	50			/* GFX thread priority */
#define NU_GFX_TASKMGR_THREAD_PRI 60		/* Task Manager priority */

/*----------------------------------------------------------------------*/
/* GRAFIC MANEGER DEFINE						*/
/*----------------------------------------------------------------------*/
#ifdef F3DEX_GBI_2
#define	NU_GFX_UCODE_F3DEX2	0		/* F3DEX microcode  */
#define	NU_GFX_UCODE_F3DEX2_NON	1		/* F3DEX.NoN microcode  */
#define	NU_GFX_UCODE_F3DEX2_REJ	2		/* F3DEX.NoN microcode  */
#define	NU_GFX_UCODE_F3DLX2_REJ	3		/* F3DEX.ReJ microcode  */
#define	NU_GFX_UCODE_L3DEX2	4		/* L3DEX microcode  */
#define	NU_GFX_UCODE_S2DEX2	5		/* S2DEX microcode  */
    
#define	NU_GFX_UCODE_F3DEX	0		/*  For compatibility		*/
#define	NU_GFX_UCODE_F3DEX_NON	1		/*  For compatibility		*/
#define	NU_GFX_UCODE_F3DLX	0		/*  For compatibility		*/
#define	NU_GFX_UCODE_F3DLX_NON	1		/*  For compatibility		*/
#define	NU_GFX_UCODE_F3DLX_REJ	4		/*  For compatibility		*/
#define	NU_GFX_UCODE_F3DLP_REJ	3		/*  For compatibility		*/
#define	NU_GFX_UCODE_L3DEX	4		/*  For compatibility		*/
#define	NU_GFX_UCODE_S2DEX	5		/*  For compatibility		*/
#define	NU_GFX_UCODE_S2DEX_D	5		/*  For compatibility		*/

#else    
#define	NU_GFX_UCODE_F3DEX	0		/* F3DEX microcode  */
#define	NU_GFX_UCODE_F3DEX_NON	1		/* F3DEX.NoN microcode  */
#define	NU_GFX_UCODE_F3DLX	2		/* F3DLX microcode  */
#define	NU_GFX_UCODE_F3DLX_NON	3		/* F3DLX.NoN microcode  */
#define	NU_GFX_UCODE_F3DLX_REJ	4		/* F3DEX.ReJ microcode  */
#define	NU_GFX_UCODE_F3DLP_REJ	5		/* F3DLP.Rej microcode  */
#define	NU_GFX_UCODE_L3DEX	6		/* L3DEX microcode  */
#define	NU_GFX_UCODE_S2DEX	7		/* S2DEX microcode  */
#define	NU_GFX_UCODE_S2DEX_D	8		/* S2DEX microcode  */
#endif /* F3DEX_GBI_2 */

    
/*----------------------------------------------*/
/* The number of graphics task structures	*/
/* should be set to a value at least as large as*/
/* the Scheduler 				*/
/* message buffer size.				*/
/* Otherwise, a task structure in use may 	*/
/* be used.					*/
/*----------------------------------------------*/
#define NU_GFX_TASK_NUM		10   /* Number of graphics task structures */
#define	NU_GFX_RDP_OUTPUTBUFF_SIZE	0x20000	/* fifo buffer size	*/

/*--------------------------------------*/
/* Default frame buffer		*/
/* The default frame buffer	*/
/* is the 320x240 16-bit triple	 */
/* xxbuffer in the high-order		*/
/* area of RDRAM.xx		*/
/*--------------------------------------*/
#define NU_GFX_FRAMEBUFFER_NUM		3
#define NU_GFX_FRAMEBUFFER_ADDR		(0x80400000-320*240*2*3)
#define NU_GFX_FRAMEBUFFER0_ADDR	(NU_GFX_FRAMEBUFFER_ADDR)
#define NU_GFX_FRAMEBUFFER1_ADDR	(NU_GFX_FRAMEBUFFER0_ADDR+320*240*2)
#define NU_GFX_FRAMEBUFFER2_ADDR	(NU_GFX_FRAMEBUFFER1_ADDR+320*240*2)

#define NU_GFX_INIT_SCREEN_WD		320
#define NU_GFX_INIT_SCREEN_HT		240

/*--------------------------------------*/
/* Default Z -buffer is located in		*/
/* xxlow-order memory.xx	*/
/*--------------------------------------*/    
#define NU_GFX_ZBUFFER_ADDR		0x80000400
					   
#define	NU_GFX_DISPLAY_OFF		0	/* No display */    
#define	NU_GFX_DISPLAY_ON		1	/* Display */
#define	NU_GFX_DISPLAY_ON_TRIGGER	0x80	/* Trigger		*/

#define NU_GFX_YIELD_BUF_SIZE		(OS_YIELD_DATA_SIZE + 0x10)
					   
/*----------------------------------------------------------------------*/
/* SI MANAGER DEFINE							*/
/*----------------------------------------------------------------------*/
#define	NU_SI_STACK_SIZE		NU_CONT_STACK_SIZE
#define	NU_SI_THREAD_ID			NU_CONT_THREAD_ID
#define NU_SI_THREAD_PRI		NU_CONT_THREAD_PRI
#define NU_SI_MESG_MAX			NU_CONT_MESG_MAX
#define NU_SI_CALLBACK_END		1
#define NU_SI_CALLBACK_CONTINUE		0
#define	NU_SI_SC_MAJOR_NO		0x0000
#define	NU_SI_MSG_MAJOR_NO_MASK		0xff00
#define	NU_SI_MSG_MINOR_NO_MASK		0x00ff

#define	NU_SI_MAJOR_NO_CONT		0x0100
#define	NU_SI_MAJOR_NO_PAK		0x0200
#define	NU_SI_MAJOR_NO_RMB		0x0300
#define	NU_SI_MAJOR_NO_EEPROM		0x0400
#define	NU_SI_MAJOR_NO_GBPAK		0x0500
#define	NU_SI_MAJOR_NO_VRS		0x0600
#define	NU_SI_STOP_MGR_MSG		0x7F00

/*----------------------------------------------------------------------*/
/* CONTROLLER MANEGER DEFINE						*/
/*----------------------------------------------------------------------*/
#define NU_CONT_MAXCONTROLLERS		MAXCONTROLLERS
#define	NU_CONT_STACK_SIZE		0x2000
#define	NU_CONT_MESG_MAX		8
#define NU_CONT_THREAD_ID		6
#define NU_CONT_THREAD_PRI		115
#define	NU_CONT_DATA_UNLOCK		0
#define	NU_CONT_DATA_LOCK		1


/*----------------------------------------------------------------------*/
/* Define messages sent to the Controller Manager				*/
/*----------------------------------------------------------------------*/
#define	NU_CONT_MSG_BASE		NU_SI_MAJOR_NO_CONT
#define	NU_CONT_RETRACE_MSG		(NU_CONT_MSG_BASE+0)
#define NU_CONT_READ_MSG		(NU_CONT_MSG_BASE+1)
#define NU_CONT_READ_NW_MSG		(NU_CONT_MSG_BASE+2)
#define NU_CONT_QUERY_MSG		(NU_CONT_MSG_BASE+3)


#define	NU_CONT_PAK_MSG_BASE		NU_SI_MAJOR_NO_PAK
#define	NU_CONT_PAK_RETRACE_MSG		(NU_CONT_PAK_MSG_BASE+0)
#define NU_CONT_PAK_OPEN_MSG		(NU_CONT_PAK_MSG_BASE+1)
#define NU_CONT_PAK_FREE_MSG		(NU_CONT_PAK_MSG_BASE+2)
#define NU_CONT_PAK_FOPEN_MSG		(NU_CONT_PAK_MSG_BASE+3)
#define NU_CONT_PAK_READWRITE_MSG	(NU_CONT_PAK_MSG_BASE+4)
#define NU_CONT_PAK_FILEDELETE_MSG	(NU_CONT_PAK_MSG_BASE+5)
#define NU_CONT_PAK_FILESTATE_MSG	(NU_CONT_PAK_MSG_BASE+6)
#define NU_CONT_PAK_FILENUM_MSG		(NU_CONT_PAK_MSG_BASE+7)
#define NU_CONT_PAK_REPAIRID_MSG	(NU_CONT_PAK_MSG_BASE+8)

#define NU_CONT_PAK_MODE_NOCREATE	0
#define NU_CONT_PAK_MODE_CREATE		1
#define	NU_CONT_PAK_TYPE_NONE		0
#define	NU_CONT_PAK_TYPE_PAK		1	/* Controller Pak 	*/
#define	NU_CONT_PAK_TYPE_RUMBLE		2	/* Rumble Pak  		*/
#define	NU_CONT_PAK_TYPE_GBPAK		3	/* 64GB Pak		*/
#define NU_CONT_PAK_READ		PFS_READ
#define	NU_CONT_PAK_WRITE		PFS_WRITE

/*----------------------------------------------------------------------*/
/* Rumble Pak control 							*/
/*----------------------------------------------------------------------*/
#define NU_CONT_RMB_STATE_STOP		0x00
#define NU_CONT_RMB_STATE_STOPPING	0x01
#define NU_CONT_RMB_STATE_STOPPED	0x02
#define NU_CONT_RMB_STATE_RUN		0x03
#define NU_CONT_RMB_STATE_FORCESTOP	0x04
#define NU_CONT_RMB_MODE_DISABLE	0x00
#define	NU_CONT_RMB_MODE_ENABLE		0x01
#define NU_CONT_RMB_MODE_AUTORUN	0x02
#define NU_CONT_RMB_MODE_PAUSE		0x80
#define NU_CONT_RMB_AUTO_SEARCH		0x00
#define	NU_CONT_RMB_AUTO_FIND		0x01
#define NU_CONT_RMB_AUTO_SEARCHTIME	(60*5)
#define NU_CONT_RMB_MSG_BASE		NU_SI_MAJOR_NO_RMB
#define NU_CONT_RMB_RETRACE_MSG		(NU_CONT_RMB_MSG_BASE+0)
#define NU_CONT_RMB_CHECK_MSG		(NU_CONT_RMB_MSG_BASE+1)
#define NU_CONT_RMB_START_MSG		(NU_CONT_RMB_MSG_BASE+2)
#define NU_CONT_RMB_STOP_MSG		(NU_CONT_RMB_MSG_BASE+3)	   
#define	NU_CONT_RMB_FORCESTOP_MSG	(NU_CONT_RMB_MSG_BASE+4)
#define	NU_CONT_RMB_FORCESTOPEND_MSG	(NU_CONT_RMB_MSG_BASE+5)

/*----------------------------------------------------------------------*/
/* EEPROM								*/
/*----------------------------------------------------------------------*/
#define NU_EEPROM_MSG_BASE		NU_SI_MAJOR_NO_EEPROM
#define NU_EEPROM_RETRACE_MSG		(NU_EEPROM_MSG_BASE+0)
#define NU_EEPROM_CHECK_MSG		(NU_EEPROM_MSG_BASE+1)
#define	NU_EEPROM_READ_MSG		(NU_EEPROM_MSG_BASE+2)
#define NU_EEPROM_WRITE_MSG		(NU_EEPROM_MSG_BASE+3)


/*----------------------------------------------------------------------*/
/* 64GB Pack  Manager							*/
/*----------------------------------------------------------------------*/
#define NU_CONT_GBPAK_MSG_BASE		NU_SI_MAJOR_NO_GBPAK
#define NU_CONT_GBPAK_RETRACE_MSG	(NU_CONT_GBPAK_MSG_BASE+0)
#define NU_CONT_GBPAK_OPEN_MSG		(NU_CONT_GBPAK_MSG_BASE+1)
#define NU_CONT_GBPAK_STATUS_MSG	(NU_CONT_GBPAK_MSG_BASE+2)
#define NU_CONT_GBPAK_POWER_MSG		(NU_CONT_GBPAK_MSG_BASE+3)
#define NU_CONT_GBPAK_READID_MSG	(NU_CONT_GBPAK_MSG_BASE+4)
#define NU_CONT_GBPAK_READWRITE_MSG	(NU_CONT_GBPAK_MSG_BASE+5)
#define NU_CONT_GBPAK_CHECKCONNECTOR_MSG (NU_CONT_GBPAK_MSG_BASE+6)
    
#define NU_CONT_GBPAK_POWER_OFF		OS_GBPAK_POWER_OFF
#define NU_CONT_GBPAK_POWER_ON		OS_GBPAK_POWER_ON
#define	NU_CONT_GBPAK_MBC_RAM_ENABLE_CODE	0x0a
#define	NU_CONT_GBPAK_MBC_RAM_DISABLE_CODE	0x00
#define	NU_CONT_GBPAK_MBC_RAM_REG0_ADDR		0x0000

#define NU_CONT_GBPAK_MBC_REG0_ADDR		0x0000	/* Register 0	*/
#define NU_CONT_GBPAK_MBC_REG1_ADDR		0x2100	/* Register 1	*/
#define NU_CONT_GBPAK_MBC_REG2_ADDR		0x4000	/* Register 2	*/
#define NU_CONT_GBPAK_MBC_REG3_ADDR		0x6000	/* Register 3	*/

/*----------------------------------------------------------------------*/
/*  Voice Recognition System Manager						*/
/*----------------------------------------------------------------------*/
#define NU_VRS_MSG_BASE			NU_SI_MAJOR_NO_VRS
#define	NU_VRS_RETRACE_MSG		(NU_VRS_MSG_BASE+0)
#define	NU_VRS_OPEN_MSG			(NU_VRS_MSG_BASE+1)
#define	NU_VRS_CLEAR_DICTIONARY_MSG	(NU_VRS_MSG_BASE+2)
#define	NU_VRS_SET_WORD_MSG		(NU_VRS_MSG_BASE+3)
#define	NU_VRS_MASK_DICTIONARY_MSG	(NU_VRS_MSG_BASE+4)
#define	NU_VRS_START_READ_DATA_MSG	(NU_VRS_MSG_BASE+5)
#define	NU_VRS_GET_READ_DATA_MSG	(NU_VRS_MSG_BASE+6)
#define	NU_VRS_STOP_READ_DATA_MSG	(NU_VRS_MSG_BASE+7)
#define	NU_VRS_CONTROL_GAIN_MSG		(NU_VRS_MSG_BASE+8)
					   
/*----------------------------------------------------------------------*/
/* PI DEFINE								*/
/*----------------------------------------------------------------------*/
#define	NU_PI_MESG_NUM			50	/* PI message buffer size */
#define	NU_PI_CART_BLOCK_READ_SIZE	0x4000	/* cart read block size	*/

/*----------------------------------------------------------------------*/
/* DEBUG 								*/
/*----------------------------------------------------------------------*/
#define NU_DEB_PERF_BUF_NUM		3
#define	NU_DEB_PERF_GFXTASK_CNT		8	/* Graphics task count  */
#define	NU_DEB_PERF_AUTASK_CNT		4	/* Audio task count	*/
#define NU_DEB_PERF_RUNNING		0	/* Sampling		*/
#define NU_DEB_PERF_STOP		1	/* Stop sampling	*/
#define NU_DEB_PERF_START		2	/* Start sampling	*/
#define NU_DEB_DP_CLOCK_CTR		0	/* RDP internal counter	*/
#define	NU_DEB_DP_CMD_CTR		1	/* CMD counter		*/
#define NU_DEB_DP_PIPE_CTR			2	/* PIPE counter	*/
#define	NU_DEB_DP_TMEM_CTR		3	/* TMEM counter		*/
#define NU_DEB_BAR_FRAME1		0	/* For the performance bar */
#define NU_DEB_BAR_FRAME2		1	/* Maximum number displayed		*/
#define NU_DEB_BAR_FRAME3		2
#define NU_DEB_BAR_FRAME4		3
#define NU_DEB_BAR_FRAME5		4
#define NU_DEB_BAR_FRAME6		5
#define NU_DEB_BAR_FRAME7		6
#define	NU_DEB_CON_ROW_MAX		40	/* Number of rows in console */
#define NU_DEB_CON_COLUMN_MAX		30 	/* Number of columns in console */
#define NU_DEB_CON_TEXT_SIZE		(NU_DEB_CON_ROW_MAX*NU_DEB_CON_COLUMN_MAX)
#define NU_DEB_CON_WIDTH		320
#define NU_DEB_CON_WINDOW_NUM		4
#define NU_DEB_CON_WINDOW0		0
#define NU_DEB_CON_WINDOW1		1
#define NU_DEB_CON_WINDOW2		2
#define NU_DEB_CON_WINDOW3		3
#define	NU_DEB_CON_TEXT_BLACK		0	/* Black */
#define NU_DEB_CON_TEXT_BLUE		1	/* Blue  */
#define NU_DEB_CON_TEXT_GREEN		2	/* Green */
#define NU_DEB_CON_TEXT_CYAN		3	/* Cyan */
#define NU_DEB_CON_TEXT_RED		4	/* Red */
#define NU_DEB_CON_TEXT_MAGENTA	5	/* Magenta  */
#define NU_DEB_CON_TEXT_YELLOW		6	/* yellow */
#define NU_DEB_CON_TEXT_WHITE		7	/* White  */
#define	NU_DEB_CON_TEXT_LIGHTBLACK	8	/* Gray */
#define NU_DEB_CON_TEXT_LIGHTBLUE	9	/* Bright Blue  */
#define NU_DEB_CON_TEXT_LIGTHBLUE	9	/* Bright Blue (misspelled) */
#define NU_DEB_CON_TEXT_LIGHTGREEN	10	/* Bright Green */
#define NU_DEB_CON_TEXT_LIGHTCYAN	11	/* Bright Cyan */
#define NU_DEB_CON_TEXT_LIGHTRED	12	/* Bright Red */
#define NU_DEB_CON_TEXT_LIGHTMAGENTA	13	/* Bright Magenta  */
#define NU_DEB_CON_TEXT_LIGHTYELLOW	14	/* Bright yellow */
#define NU_DEB_CON_TEXT_LIGHTWHITE	15	/* White  */
#define NU_DEB_CON_ATTR_NORMAL		0x0	/* No attribute*/
#define NU_DEB_CON_ATTR_BLINK		0x1	/* Blinking		*/
#define	NU_DEB_CON_ATTR_REVERSE		0x2	/* Highlight */
#define NU_DEB_CON_SCROLL_ON		1
#define NU_DEB_CON_SCROLL_OFF		0
#define NU_DEB_CON_WINDOW_OFF		0
#define NU_DEB_CON_WINDOW_ON		1    
    
#define NU_DEB_MARKER_NUM		10

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/* structer define 							*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*--------------------------------------*/
/* Scheduler sturcter			*/
/*--------------------------------------*/
typedef short	NUScMsg;		/* Scheduler message type */

typedef struct	st_SCClient {		/* Client list structure */
    struct st_SCClient*	next;		/* Pointer to next client */
    OSMesgQueue*	msgQ;		/* Message sent to client  */
    NUScMsg		msgType;	/* Type of message */
					/* NU_SC_RETRACE_MSG or*/
    					/* NU_SC_PRENMI_MSG */
} NUScClient;

typedef struct st_SCTask {		/* Task structure */
    struct st_SCTask	*next;
    u32		state;
    u32		flags;
    void	*framebuffer;		/* For graphics tasks */
    OSTask	list;
    OSMesgQueue	*msgQ;
    OSMesg	msg;
} NUScTask;

typedef struct st_Sched { /* Define the Scheduler structure. */

    /*  message */
    NUScMsg	retraceMsg;
    NUScMsg	prenmiMsg;

    /* Define the Task request queue. */
    OSMesgQueue	audioRequestMQ;
    OSMesg	audioRequestBuf[NU_SC_MAX_MESGS];
    OSMesgQueue graphicsRequestMQ;
    OSMesg	graphicsRequestBuf[NU_SC_MAX_MESGS];

    /* Define the message queue. */
    OSMesgQueue	retraceMQ;
    OSMesg	retraceMsgBuf[NU_SC_MAX_MESGS];
    OSMesgQueue	rspMQ;
    OSMesg      rspMsgBuf[NU_SC_MAX_MESGS];
    OSMesgQueue rdpMQ;
    OSMesg	rdpMsgBuf[NU_SC_MAX_MESGS];

    /* Implement wait for next retrace. */
    OSMesgQueue	waitMQ;
    OSMesg	waitMsgBuf[NU_SC_MAX_MESGS];

    /* Define threads.*/
    OSThread	schedulerThread;	/* Main thread */
    OSThread	audioThread;		/* Audio */
    OSThread	graphicsThread;		/* Graphics */

    /*  client list  */
    NUScClient	*clientList;

    /* The graphics task being executed. */
    NUScTask	*curGraphicsTask;
    NUScTask 	*curAudioTask;
    NUScTask	*graphicsTaskSuspended;

    u32		retraceCount;
    u8		frameRate;
    u8		frameBufferNum;		/* Number of frame buffers */


} NUSched;


/*--------------------------------------*/
/* ucode structure			*/
/*--------------------------------------*/
typedef struct  st_Ucode {
    u64*	ucode;	
    u64*	ucode_data;
} NUUcode;

/*--------------------------------------*/
/* CALL BACK Function	typedef		*/
/*--------------------------------------*/
typedef void (*NUIdleFunc)(void);	/* Pointer to the idle callback function */
typedef void (*NUScPreNMIFunc)(void);	/* Pointer to PRENMI callback function */
typedef void (*NUGfxFunc)(u32);		/* Pointer to the GFX retrace callback function */
typedef void (*NUGfxPreNMIFunc)(void);	/* Pointer to the GFX PRENMI callback function */

typedef void (*NUGfxSwapCfbFunc)(void*);/* Pointer to the SWAPBUF callback function */
typedef void (*NUGfxTaskEndFunc)(void*);/* Pointer to the TASKEND callback function */
typedef void (*NUContReadFunc)(u32);	/* Pointer to the Controller end-read */
					/* callback function 	*/
typedef void (*NUContPakFunc)(void*);	/* Controller Pak control function callback */
typedef void (*NUContRmbFunc)(void*);	/* Rumble Pak control function callback */
typedef s32 (*NUCallBackFunc)(void*);	/* Callback function  */


/*--------------------------------------*/
/* PI Common Message 			*/
/*--------------------------------------*/
typedef struct st_PiOverlaySegment {
    u8* romStart;		/* Segment's ROM start offset          */
    u8* romEnd;			/* Segment's ROM end offset            */
    u8*	ramStart;		/* Segment's CPU start address         */
    u8* textStart;		/* test attribute's DRAM start address */
    u8* textEnd;		/* test attribute's DRAM end address   */
    u8* dataStart;		/* data attribute's DRAM start address */
    u8* dataEnd;		/* data attribute's DRAM end address   */
    u8* bssStart;		/* bss attribute's DRAM start address  */
    u8*	bssEnd;			/* bss attribute's DRAM start address  */
} NUPiOverlaySegment;

/*--------------------------------------*/
/* SI Common  message 			*/
/*--------------------------------------*/
typedef struct st_SiCommonMesg {
    NUScMsg		mesg;
    OSMesgQueue*	rtnMesgQ;
    s32			error;
    void*		dataPtr;
} NUSiCommonMesg;

/*--------------------------------------*/
/* controller typedef			*/
/*--------------------------------------*/
typedef struct st_ContRead {
    NUScMsg	mesg;			/* Type of message */
    OSMesgQueue* rtnMesgQ;
    OSContPad*	pad;
} NUContReadMesg;

typedef struct st_ContData {
    u16	button;			/* A,B,C,Z,L,R,START,PAD ,button 	*/
    s8	stick_x;		/* Range acutally used:   -61 <= stick X <= 61	*/
    s8	stick_y;		/* Range actually used:  -63 <= stick Y <= 63	*/
    u8	errno;		/* Error				*/
    u16	trigger;		/* Button trigger data		*/
} NUContData;

typedef struct st_ContQuery {
    NUScMsg	mesg;
    OSMesgQueue* rtnMesgQ;
} NUContQueryMesg;


typedef struct st_ContPakFile {
    OSPfs	*pfs;    
    s32		file_no;
    s32		error;
    u32		type;
} NUContPakFile;


typedef struct st_ContPakFreeMesg {
    NUContPakFile*	file;
    s32			size;
} NUContPakFreeMesg;

typedef struct st_ContPakFileOpenMesg {
    NUContPakFile*	file;
    u8*			noteName;
    u8*			extName;
    s32			size;
    s32			mode;
} NUContPakFileOpenMesg;

typedef struct st_ContPakFileRWMesg {
    NUContPakFile*	file;
    s32			offset;
    s32			size;
    u8			mode;
    u8*			buf;
} NUContPakFileRWMesg;

typedef struct st_ContPakFileStateMesg {
    NUContPakFile*	file;
    OSPfsState*		state;
} NUContPakFileStateMesg;

typedef struct st_ContPakFileNumMesg {
    NUContPakFile*	file;
    s32*		max_files;
    s32*		used_files;
} NUContPakFileNumMesg;

typedef struct st_ContPakIsPlugMesg {
    NUScMsg		mesg;
    OSMesgQueue*	rtnMesgQ;
    s32			error;
    u8			bitPattern;
} NUContPakIsPlugMesg;

typedef struct st_ContRmbCtl {
    u16			freq;		/* Vibration frequency */
    u16			frame;
    u16			counter;
    u8			state;
    u8			mode;
    u8			autorun;
    u8			type;
} NUContRmbCtl;

typedef struct st_ContRmbMesg {
    u8			contNo;
    s32			error;
    void*		data;
} NUContRmbMesg;

typedef struct st_CallBackList {
    struct st_CallBackList* 	next;
    s32 			(**func)(NUSiCommonMesg*);
    u16				majorNo;
    u8    			funcNum;
} NUCallBackList;

typedef struct st_EepromMesg {
    void*		dataPtr;
    s32			error;
    u8			address;
    u16			dataLen;
} NUEepromMesg;

typedef struct st_ContGBPakMesg {
    NUContPakFile*	handle;
    s32			data[4];
} NUContGBPakMesg;

typedef OSVoiceHandle NUVrsHandle;

typedef OSVoiceData NUVrsData;

typedef struct stVrsMesg {
    NUVrsHandle*	vrsHandle;
    s32			data[2];
} NUVrsMesg;

/*--------------------------------------*/
/* Debug				*/
/*--------------------------------------*/
typedef struct st_GfxTaskTime {
    s64		rspStart;			/* RSPTask start time */
    s64		rspEnd;			/* RSPTask end time */
    s64		rdpEnd;			/* RDP end time		*/
    u32		dpCnt[4];		/* RDP internal counter	*/
} NUDebTaskTime;

typedef struct st_DebTaskPerf {
    s64		retraceTime;		/* retrace event time*/
    s64		markerTime[NU_DEB_MARKER_NUM];
    u8		gfxTaskCnt;		/* Number of graphics tasks */
    u8		auTaskCnt;		/* Number of audio tasks */
    u8		gfxTaskStart;
    NUDebTaskTime	gfxTaskTime[NU_DEB_PERF_GFXTASK_CNT];
    NUDebTaskTime	auTaskTime[NU_DEB_PERF_AUTASK_CNT];
} NUDebTaskPerf;

/* Console window structure */
typedef struct st_DebConWindow {
    u8	windowFlag;	/* On/off flag for console window display  */
    u16	scroll;		/* Scroll value				*/
    u8	scrollFlag;	/* Scrolling enabled/disabled		*/
    u8	textColor;	/* Character color				*/
    u8	attribute;	/* Attribute				*/
    u16	posX;		/* Column position for write		*/
    u16	posY;		/* Line position for write			*/
    u16	index;		/* Position for character buffer write	*/
    u16	winX;		/* x-coordinate of console window display	*/
    u16	winY;		/* y-coordinate of console window display	*/
    u16	winW;		/* Number of columns in console display	*/
    u16	winH;		/* Number of rows in console display 	*/
    u16	text[NU_DEB_CON_TEXT_SIZE];	/* Character buffer*/    
} NUDebConWindow;

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/* extern variables 							*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/    

extern u8	nuRDPOutputBuf[];
extern u8	nuDramStack[];
extern u8	nuYieldBuf[];
extern NUSched	nusched;		/* Scheduler structure */
extern OSMesgQueue nuGfxMesgQ;	/* Graphics thread queue */
extern u32	nuScRetraceCounter;    /* Retrace counter */
extern u8	nuScPreNMIFlag;
/*--------------------------------------*/
/*  graphics variables 			*/
/*--------------------------------------*/
extern NUUcode*	nuGfxUcode;	/* Pointer to GFX microcode structure */
extern u16**		nuGfxCfb;	/* Pointer to array of pointers to frame buffers */
extern u16*		nuGfxCfb_ptr;	/* Pointer to to frame buffer */
extern u32		nuGfxCfbNum;	/* Number of frame buffers */
extern u16*		nuGfxZBuffer;	/* Pointer to the Z buffer */
extern volatile u32	nuGfxTaskSpool; /* Number of tasks in queue */
extern u32		nuGfxDisplay;	/* Display on/off flag  */
extern u32		nuGfxCfbCounter; /* For frame buffer swapping */
extern OSMesgQueue	nuGfxMesgQ;
extern OSThread		nuGfxThread;			/* graphic thread */

/*--------------------------------------*/
/*  controller  Manager variables 	*/
/*--------------------------------------*/
extern OSContStatus	nuContStatus[];
extern OSContPad	nuContData[];
extern u32		nuContNum;	/* Number of controllers connected */
extern u32		nuContDataLockKey; /* Lock Controller data. */
extern OSMesgQueue	nuContWaitMesgQ; /* Wait for Controller read */
extern OSPfs		nuContPfs[];
extern NUCallBackList	nuContCallBack;
extern u16		nuContPakCompanyCode;	/* Company code */
extern u32		nuContPakGameCode;	/* Game code */
extern NUCallBackList	nuContPakCallBack;

/*--------------------------------------*/
/*  RUMBUL Manager variables 		*/
/*--------------------------------------*/
extern NUContRmbCtl	nuContRmbCtl[];
extern u32		nuContRmbSearchTime;
extern NUCallBackList	nuContRmbCallBack;


/*--------------------------------------*/
/*  EEPROM Manager variables 		*/
/*--------------------------------------*/
extern NUCallBackList	nuEepromCallBack;

/*--------------------------------------*/
/*  64GBPack Manager variables 	*/
/*--------------------------------------*/
extern NUCallBackList	nuContGBPakCallBack;

/*--------------------------------------*/
/*  VRS Manager variables 		*/
/*--------------------------------------*/
extern NUCallBackList	nuVrsCallBack;
					   
/*--------------------------------------*/
/*  si variables 			*/
/*--------------------------------------*/
extern OSMesgQueue	nuSiMesgQ;	/* SI event  message queue */
extern OSMesgQueue	nuSiMgrMesgQ;	/* SI Manager queue */
extern NUCallBackList*	nuSiCallBackList;/* Callback function list */

/*--------------------------------------*/
/*  pi variables 			*/
/*--------------------------------------*/
extern OSPiHandle*	nuPiCartHandle;
extern OSPiHandle*	nuPiSramHandle;
extern OSPiHandle*	nuPiDDRomHandle;
    
/*--------------------------------------*/
/* CALL BACK Function pointer 		*/
/*--------------------------------------*/
extern NUIdleFunc	nuIdleFunc;		/* callback func pointer */
extern NUScPreNMIFunc	nuScPreNMIFunc;		/* PRE NMI callback pointer  */
extern NUGfxSwapCfbFunc	nuGfxSwapCfbFunc; 	/* swapbuf callback pointer  */
extern NUGfxFunc	nuGfxFunc;			/* callback pointer 	*/
extern NUGfxPreNMIFunc	nuGfxPreNMIFunc;	/* Callback pointer 	*/
extern NUGfxTaskEndFunc	nuGfxTaskEndFunc; 	/* task end callback ptr */
extern NUContReadFunc	nuContReadFunc;		/* When controller read ends */
							/* Callback function */
/*--------------------------------------*/
/* Debug 		 		*/
/*--------------------------------------*/

extern NUDebTaskPerf*	nuDebTaskPerfPtr;
extern NUDebConWindow	nuDebConWin[];
extern NUDebTaskPerf	nuDebTaskPerf[];
extern u32		nuDebTaskPerfInterval;
extern volatile u32	nuDebTaskPerfCnt;
extern volatile u32	nuDebTaskPerfEnd;


/*----------------------------------------------------------------------*/    
/*----------------------------------------------------------------------*/
/* Global Function 							*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/*--------------------------------------*/
/* Boot function			*/
/*--------------------------------------*/
extern void nuIdleFuncSet(void (*func)(void));
extern void nuPreNMIFuncSet(NUScPreNMIFunc func);
/*--------------------------------------*/
/* Scheduler function			*/
/*--------------------------------------*/
extern void nuScCreateScheduler(u8 videoMode, u8 numFields);
extern void nuScAddClient(NUScClient *c, OSMesgQueue *mq, NUScMsg msgType);
extern void nuScRemoveClient(NUScClient *client);
extern void nuScResetClientMesgType(NUScClient* client, NUScMsg msgType);
extern OSMesgQueue* nuScGetGfxMQ(void);
extern OSMesgQueue* nuScGetAudioMQ(void);
extern void nuScSetFrameBufferNum(u8 frameBufferNum);
extern s32 nuScGetFrameRate(void);
					   
/*--------------------------------------*/
/* graphic(GFX)  Manager function	*/
/*--------------------------------------*/
extern void nuGfxInit(void);
extern void nuGfxInitEX2(void);
extern void nuGfxThreadStart(void);
extern void nuGfxTaskMgrInit(void);
extern void nuGfxTaskStart(Gfx *gfxList_ptr, u32 gfxListSize, u32 ucode, u32 flag);
extern void nuGfxFuncSet(NUGfxFunc func);
extern void nuGfxPreNMIFuncSet(NUGfxPreNMIFunc func);
extern void nuGfxSwapCfbFuncSet(NUGfxSwapCfbFunc func);
extern void nuGfxSetCfb(u16** framebuf, u32 framebufnum);
extern void nuGfxSwapCfb(void* framebuffer);

extern void nuGfxTaskEndFuncSet(NUGfxTaskEndFunc func);
extern void nuGfxTaskAllEndWait(void);
extern void nuGfxRetraceWait(u32 retrace_num);
extern void nuGfxDisplayOff(void);
extern void nuGfxDisplayOn(void);

#ifdef F3DEX_GBI_2
#define	nuGfxInit()	nuGfxInitEX2()
#endif /* F3DEX_GBI_2 */
/*--------------------------------------*/
/* controller  Manager function		*/
/*--------------------------------------*/
extern u8   nuContInit(void);
extern s32  nuContMgr(void* mesg);
extern u8   nuContMgrInit(void);
extern void nuContMgrRemove(void);
extern void nuContDataLock(void);
extern void nuContDataUnLock(void);
extern void nuContDataRead(OSContPad* pad);
extern void nuContDataReadWait(void);
extern void nuContDataReadStart(void);
extern void nuContDataGet(OSContPad* contdata, u32 padno);
extern void nuContDataGetAll(OSContPad* contdata);
extern void nuContDataGetEx(NUContData *contdata, u32 padno);
extern void nuContDataGetExAll(NUContData *contdata);
extern void nuContReadFuncSet(NUContReadFunc func);
extern void nuContQueryRead(void);
extern void nuContDataClose(void);
extern void nuContDataOpen(void);
    
/*--------------------------------------*/
/* controller pak function		*/
/*--------------------------------------*/
extern s32  nuContPakMgr(void* mesg_type);
extern void nuContPakMgrInit(void);
extern void nuContPakMgrRemove(void);
extern void nuContPakJisToN64(u8* src, u8* dest, u32 len);
extern void nuContPakN64ToJis(u8* src, u8* dest, u32 len);
extern s32  nuContPakOpen(NUContPakFile *file, u32 contNo);
extern s32  nuContPakGetFree(NUContPakFile *file);
extern void nuContPakCodeSet(u8* companyCode, u8* gameCode);
extern s32  nuContPakRepairId(NUContPakFile *file);
extern s32  nuContPakFileOpen(NUContPakFile *file,
			      u8* noteName,u8* extName, u32 mode, s32 size);
extern s32  nuContPakFileOpenJis(NUContPakFile *file,
				 u8* noteName,u8* extName, u32 mode, s32 size);
extern s32  nuContPakFileReadWrite(NUContPakFile *file,
			    s32 offset, s32 size,u8* buf, u32 mode);
extern s32  nuContPakFileDelete(NUContPakFile *file, u8* noteName, u8* extName);
extern s32  nuContPakFileDeleteJis(NUContPakFile *file, u8* noteName, u8* extName);
extern s32  nuContPakFileState(NUContPakFile *file, OSPfsState* state);
extern s32  nuContPakFileNum(NUContPakFile *file,
			     s32 *max_files, s32 *used_files);
extern s32 nuContPakFileFread(NUContPakFile *file, s32 offset, s32 size, u8* buf);

/*--------------------------------------*/
/* rumbler pak functions			*/
/*--------------------------------------*/
extern void nuContRmbMgrInit(void);
extern s32  nuContRmbMgr(void* mesg);
extern void nuContRmbMgrRemove(void);
extern void nuContRmbStart(u32 contNo, u16 freq, u16 frame);
extern void nuContRmbStop(u32 contNo);
extern s32  nuContRmbCheck(u32 contNo);
extern void nuContRmbModeSet(u32 contNo, u8 mode);
extern void nuContRmbForceStop(void);
extern void nuContRmbForceStopEnd(void);
extern void nuContRmbSearchTimeSet(u32 frame);

/*--------------------------------------*/
/* 64GB Pack functions			*/
/*--------------------------------------*/
extern s32 nuContGBPakMgr(void* mesg);
extern void nuContGBPakMgrInit(void);
extern void nuContGBPakMgrRemove(void);
extern s32 nuContGBPakOpen(NUContPakFile* handle, s32 contNo);
extern s32 nuContGBPakGetStatus(NUContPakFile* handle, u8* status);
extern s32 nuContGBPakReadID(NUContPakFile* handle, OSGbpakId* id, u8* status);
extern s32 nuContGBPakReadWrite(NUContPakFile* handle, u16 flag , u16 address, u8* buffer, u16 size);
extern s32 nuContGBPakPower(NUContPakFile* handle, s32 flag);
extern s32 nuContGBPakCheckConnector(NUContPakFile* handle, u8* status);
extern s32 nuContGBPakFread(NUContPakFile* handle, u16 address, u8* buffer, u16 size);

extern s32 nuContGBPakFwrite(NUContPakFile* handle, u16 address, u8* buffer, u16 size);
extern s32 nuContGBPakRegWrite(NUContPakFile* handle, u16 addr, u8 data);

/*--------------------------------------*/
/* eeprom functions			*/
/*--------------------------------------*/
extern void nuEepromMgrInit(void);
extern s32  nuEepromMgr(void* mesg);
extern s32  nuEepromCheck(void);
extern void nuEepromMgrRemove(void);
extern s32 nuEepromRead(u8 address, u8* buffer,u16 len);
extern s32 nuEepromWrite(u8 address, u8* buffer,u16 len);

    
/*--------------------------------------*/
/* pi functions				*/
/*--------------------------------------*/
extern void nuPiInit(void);
extern void nuPiReadRom(u32 rom_addr, void* buf_ptr, u32 size);
extern void nuPiInitSram(void);
extern void nuPiInitDDrom(void);
extern void nuPiReadWriteSram(u32 addr, void* buf_ptr, u32 size, s32 flag);
extern void nuPiReadRomOverlay(NUPiOverlaySegment* segment);

/*--------------------------------------*/
/* si functions				*/
/*--------------------------------------*/
extern u8 nuSiMgrInit(void);
extern void nuSiCallBackAdd(NUCallBackList* list);
extern void nuSiCallBackRemove(NUCallBackList* list);
extern s32 nuSiSendMesg(NUScMsg mesg, void* dataPtr);
extern void nuSiSendMesgNW(NUScMsg mesg, void* dataPtr);
extern void nuSiMgrStop(void);
extern void nuSiMgrRestart(void);
/*--------------------------------------*/
/* si functions				*/
/*--------------------------------------*/
extern s32 nuVrsMgr(void *mesg);
extern void nuVrsMgrInit(void);
extern s32 nuVrsOpen(NUVrsHandle* handle, s32 contNo);
extern s32 nuVrsClearDictionary(NUVrsHandle* handle, u8 words);
extern s32 nuVrsSetWord(NUVrsHandle* handle, u8* word);
extern s32 nuVrsStartReadData(NUVrsHandle* handle);
extern s32 nuVrsGetReadData(NUVrsHandle* handle, NUVrsData* data);
extern s32 nuVrsStopReadData(NUVrsHandle* handle);
extern s32 nuVrsControlGain(NUVrsHandle* handle, s32 analog, s32 digital);
extern s32 nuVrsMaskDictionary(NUVrsHandle* handle, u8* maskpattern, s32 size);

/*--------------------------------------*/
/* dubug functions			*/
/*--------------------------------------*/
#ifdef NDEBUG
#define nuDebTaskPerfBar0(EX0 ,EX1 ,EX2)	((void)0)
#define nuDebTaskPerfBar1(EX0 ,EX1 ,EX2)	((void)0)
#define nuDebTaskPerfBar0EX2(EX0 ,EX1 ,EX2)	((void)0)
#define nuDebTaskPerfBar1EX2(EX0 ,EX1 ,EX2)	((void)0)
#define	nuDebPerfMarkSet(EX0)			((void)0)
#define nuDebTaskPerfIntervalSet(EX0)		((void)0)
#else
extern void nuDebTaskPerfBar0(u32 frameNum, u32 y, u32 flag);
extern void nuDebTaskPerfBar1(u32 frameNum, u32 y, u32 flag);
extern void nuDebTaskPerfBar0EX2(u32 frameNum, u32 y, u32 flag);
extern void nuDebTaskPerfBar1EX2(u32 frameNum, u32 y, u32 flag);
extern u32 nuDebPerfMarkSet(s32 markNo);
extern void nuDebTaskPerfIntervalSet(u32 interval);
#ifdef F3DEX_GBI_2
#define nuDebTaskPerfBar0(a, b, c)	nuDebTaskPerfBar0EX2(a, b, c)
#define nuDebTaskPerfBar1(a, b, c)	nuDebTaskPerfBar1EX2(a, b, c)
#endif	/* F3DEX_GBI_2 */

#endif /* NDEBUG */

extern void nuDebConDisp(u32 flag);
extern void nuDebConDispEX2(u32 flag);
extern void nuDebConCPuts(u32 wndNo, const char *s);
extern void nuDebConInc(NUDebConWindow* conWin);
extern void nuDebConRtn(NUDebConWindow* conWin);
extern void nuDebConEsc(NUDebConWindow* conWin, char esc);
extern void nuDebConWindowSet(u32 wndNo, u32 winX , u32 winY, u32 width, u32 height);
extern void nuDebConWindowSize(u32 wndNo,  u32 width, u32 height);
extern void nuDebConWindowPos(u32 wndNo, u32 winX , u32 winY);
extern void nuDebConTextColor(u32 wndNo, u32 color);
extern void nuDebConTextAttr(u32 wndNo, u32 attr);
extern void nuDebConTextPos(u32 wndNo, u32 posX, u32 posY);
extern void nuDebConScroll(u32 wndNo, u32 flag);
extern void nuDebConWindowShow(u32 wndNo, u32 flag);
extern void nuDebConClear(u32 wndNo);
extern void nuDebConPutc(u32 wndNo, u32  c);
extern void nuDebTaskPerfLoad(void);
extern void nuDebConPrintf(u32 wndNo, const char* fmt, ...);


#ifdef F3DEX_GBI_2
#define	nuDebConDisp(flag)		nuDebConDispEX2(flag)
#endif	/* F3DEX_GBI_2 */

/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
/* MACRO	 							*/
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
/*	Registers the graphics microcode				*/
/*	IN:	Pointer to the graphics microcode NUUcode array	*/
/*----------------------------------------------------------------------*/
#define nuGfxSetUcode(ucode)						\
{									\
    nuGfxUcode = ucode;							\
}
/*----------------------------------------------------------------------*/
/*	Z buffer settings							*/
/*	IN:	Pointer to the Z buffer				*/
/*----------------------------------------------------------------------*/
#define nuGfxSetZBuffer(ZBuf_p)						\
{									\
    nuGfxZBuffer = ZBuf_p;						\
}
/*----------------------------------------------------------------------*/
/*	Remove callback functions						*/
/*	IN:	nothing							*/
/*----------------------------------------------------------------------*/
#define	nuPreNmiFuncRemove()		nuPreNmiFuncSet(NULL)
#define nuGfxFuncRemove()		nuGfxFuncSet(NULL)
#define nuGfxPreNMIFuncRemove()		nuGfxPreNMIFuncSet(NULL)
#define	nuGfxSwapCfbFuncRemove()	nuGfxSwapCfbFuncSet(NULL)
#define	nuGfxTaskEndFuncRemove()	nuGfxTaskEndFuncSet(NULL)
#define nuContReadFuncRemove()		nuContReadFuncSet(NULL)

/*----------------------------------------------------------------------*/
/*	nuContDataGet - Obtains Controller data			*/
/*	Obtains read data from the Controller Manager.		*/
/*									*/
/*	IN:	*contpad  	Pointer to the Controller structure			*/
/* 		cont_no  	Controller number				*/
/*----------------------------------------------------------------------*/
#if 0
#define	nuContDataGet(contpad, cont_no)					\
{									\
    bcopy(&nuContData[cont_no], contpad, sizeof(OSContPad));		\
}

/*----------------------------------------------------------------------*/
/*	nuContDataGetAll - Obtains Controller data			*/
/*	Obtains read data from the Controller Manager.			*/
/*	Copies all 4 buffers.			*/
/*	IN:	*contpad  Pointer to the Controller structure		*/
/* 		cont_no  Controller number				*/
/*----------------------------------------------------------------------*/
#define nuContDataGetAll(contpad)					\
{									\
    bcopy(&nuContData[0], contpad, sizeof(OSContPad)*MAXCONTROLLERS);\
}
#endif
/*----------------------------------------------------------------------*/
/*	nuContPakFileFind - Search node			*/
/*----------------------------------------------------------------------*/
#define nuContPakFileFind(file, nodeName, extName)			\
    nuContPakFileOpen(file, nodeNname, extName, NU_CONT_PAK_NOCREAT, 0)\


/*----------------------------------------------------------------------*/
/*	nuContPakFileFindJis - Search node					*/
/*----------------------------------------------------------------------*/
#define nuContPakFileFindJis(file, nodeName, extName)			\
    nuContPakFileOpenJis(file, nodeNname, extName, NU_CONT_PAK_NOCREAT, 0)\

/*----------------------------------------------------------------------*/
/*	nuContPakFileRead - Read note				*/
/*----------------------------------------------------------------------*/
#define nuContPakFileRead(file, offset, size, buf)			\
    nuContPakFileReadWrite(file, offset, size, buf, PFS_READ)		\

/*----------------------------------------------------------------------*/
/*	nuContPakFileWrite - Read note				*/
/*----------------------------------------------------------------------*/
#define nuContPakFileWrite(file, offset, size, buf)			\
    nuContPakFileReadWrite(file, offset, size, buf, PFS_WRITE)		\

/*----------------------------------------------------------------------*/
/*	nuDebConPuts - String output (with newline)				*/
/*----------------------------------------------------------------------*/
#define  nuDebConPuts(wndNo, s)						\
{									\
    nuDebConCPuts(wndNo, s);						\
    nuDebConRtn(&nuDebConWin[wndNo]);					\
}

/*----------------------------------------------------------------------*/
/*	nuContGBPakRead - Read from the GB cartridge			*/
/*----------------------------------------------------------------------*/
#define nuContGBPakRead(file, address, buf, size)			\
    nuContGBPakReadWrite(file, OS_READ, address, buf, size)

/*----------------------------------------------------------------------*/
/*	nuContGBPakWrite - Write to the GB cartridge		*/
/*----------------------------------------------------------------------*/
#define nuContGBPakWrite(file, address, buf, size)			\
    nuContGBPakReadWrite(file, OS_WRITE, address, buf, size)

/*----------------------------------------------------------------------*/
/*	nuPiReadSram - Read from SRAM				*/
/*----------------------------------------------------------------------*/
#define nuPiReadSram(addr, buf_ptr, size)				\
	nuPiReadWriteSram(addr, buf_ptr, size, OS_READ)
    
/*----------------------------------------------------------------------*/
/*	nuPiWriteSram - Write to SRAM				*/
/*----------------------------------------------------------------------*/
#define nuPiWriteSram(addr, buf_ptr, size)				\
    nuPiReadWriteSram(addr, buf_ptr, size, OS_WRITE)
	
/*----------------------------------------------------------------------*/
/*	Define voice recognition macros					*/
/*----------------------------------------------------------------------*/
#define	nuVrsCheckWord		osVoiceCheckWord
#define	nuVrsCountSyllables	osVoiceCountSyllables



#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */
#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif
#endif /* _NUSYS_H_ */
