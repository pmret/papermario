#define ALVoice   		N_ALVoice
#define ALSynth 		N_ALSynth
#define ALGlobals 		N_ALGlobals

#define alSynAddPlayer( a, b)         n_alSynAddPlayer( b)
#define alSynAllocFX( a, b, c, d)     n_alSynAllocFX( b, c, d)
#define alSynAllocVoice( a, b, c)     n_alSynAllocVoice( b, c)
#define alSynDelete( a)               n_alSynDelete()
#define alSynFreeVoice( a, b)         n_alSynFreeVoice( b)
#define alSynGetFXRef( a, b, c)       n_alSynGetFXRef( b, c)
#define alSynGetPriority( a, b)       n_alSynGetPriority( b)
#define alSynRemovePlayer( a, b)      n_alSynRemovePlayer( b)
#define alSynSetFXMix( a, b, c)       n_alSynSetFXMix( b, c)
#define alSynSetFXParam( a, b, c, d)  n_alSynSetFXParam( b, c, d)
#define alSynFreeFX( a, b)            n_alSynFreeFX( b)
#define alSynSetPan( a, b, c)         n_alSynSetPan( b, c)
#define alSynSetPitch( a, b, c)       n_alSynSetPitch( b, c)
#define alSynSetPriority( a, b, c)    n_alSynSetPriority( b, c)
#define alSynSetVol( a, b, c, d)      n_alSynSetVol( b, c, d)
#define alSynStartVoice( a, b, c)     n_alSynStartVoice( b, c)
#define alSynStartVoiceParams( a, b, c, d, e, f, g, h) \
                                      n_alSynStartVoiceParams( b, c, d, e, f, g, h)
#define alSynStopVoice( a, b)         n_alSynStopVoice( b)
#define alSynNew( a, b)               n_alSynNew( b)

#define alInit 			n_alInit
#define alClose 		n_alClose
#define alAudioFrame 		n_alAudioFrame

#define ALVoiceState            N_ALVoiceState
#define ALSeqPlayer             N_ALSeqPlayer
#define ALCSPlayer              N_ALCSPlayer

#define alSeqNextEvent		n_alSeqNextEvent
#define alSeqNewMarker		n_alSeqNewMarker

#define alCSeqNew		n_alCSeqNew
#define alCSeqNextEvent		n_alCSeqNextEvent
#define alCSeqNewMarker		n_alCSeqNewMarker

#define alSeqpNew		n_alSeqpNew
#define alSeqpDelete		n_alSeqpDelete
#define alSeqpGetChlVol		n_alSeqpGetChlVol
#define alSeqpGetChlFXMix	n_alSeqpGetChlFXMix
#define alSeqpGetChlPan		n_alSeqpGetChlPan
#define alSeqpGetChlPriority	n_alSeqpGetChlPriority
#define alSeqpGetChlProgram	n_alSeqpGetChlProgram
#define alSeqpGetSeq		n_alSeqpGetSeq
#define alSeqpGetState		n_alSeqpGetState
#define alSeqpGetTempo		n_alSeqpGetTempo
#define alSeqpGetVol		n_alSeqpGetVol
#define alSeqpPlay		n_alSeqpPlay
#define alSeqpSendMidi		n_alSeqpSendMidi
#define alSeqpSetBank		n_alSeqpSetBank
#define alSeqpSetChlVol		n_alSeqpSetChlVol
#define alSeqpSetChlFXMix	n_alSeqpSetChlFXMix
#define alSeqpSetChlPan		n_alSeqpSetChlPan
#define alSeqpSetChlPriority	n_alSeqpSetChlPriority
#define alSeqpSetChlProgram	n_alSeqpSetChlProgram
#define alSeqpSetSeq		n_alSeqpSetSeq
#define alSeqpSetTempo		n_alSeqpSetTempo
#define alSeqpSetVol		n_alSeqpSetVol
#define alSeqpStop		n_alSeqpStop
#define alSeqpLoop		n_alSeqpLoop

#define alCSPNew		n_alCSPNew
#define alCSPDelete		n_alCSPDelete
#define alCSPGetChlVol		n_alCSPGetChlVol
#define alCSPGetChlFXMix	n_alCSPGetChlFXMix
#define alCSPGetChlPan		n_alCSPGetChlPan
#define alCSPGetChlPriority	n_alCSPGetChlPriority
#define alCSPGetChlProgram	n_alCSPGetChlProgram
#define alCSPGetSeq		n_alCSPGetSeq
#define alCSPGetState		n_alCSPGetState
#define alCSPGetTempo		n_alCSPGetTempo
#define alCSPGetVol		n_alCSPGetVol
#define alCSPPlay		n_alCSPPlay
#define alCSPSendMidi		n_alCSPSendMidi
#define alCSPSetBank		n_alCSPSetBank
#define alCSPSetChlVol		n_alCSPSetChlVol
#define alCSPSetChlFXMix	n_alCSPSetChlFXMix
#define alCSPSetChlPan		n_alCSPSetChlPan
#define alCSPSetChlPriority	n_alCSPSetChlPriority
#define alCSPSetChlProgram	n_alCSPSetChlProgram
#define alCSPSetSeq		n_alCSPSetSeq
#define alCSPSetTempo		n_alCSPSetTempo
#define alCSPSetVol		n_alCSPSetVol
#define alCSPStop		n_alCSPStop

#define ALSoundState            N_ALSoundState
#define ALSndpEvent             N_ALSndpEvent
#define ALSndPlayer             N_ALSndPlayer

#define alSndpNew( a, b)	        n_alSndpNew( a, b)
#define alSndpDelete( a)	        n_alSndpDelete()
#define alSndpAllocate( a, b)	        n_alSndpAllocate( b)
#define alSndpDeallocate( a, b)	        n_alSndpDeallocate( b)
#define alSndpGetState( a)	        n_alSndpGetState()
#define alSndpPlay( a)		        n_alSndpPlay()
#define alSndpPlayAt( a, b)	        n_alSndpPlayAt( b)
#define alSndpSetFXMix( a, b)	        n_alSndpSetFXMix( b)
#define alSndpSetPan( a, b)	        n_alSndpSetPan( b)
#define alSndpSetPitch( a, b)	        n_alSndpSetPitch( b)
#define alSndpSetPriority( a, b, c)	n_alSndpSetPriority( b, c)
#define alSndpSetVol( a, b)	        n_alSndpSetVol( b)
#define alSndpStop( a)		        n_alSndpStop()
#define alSndpGetSound( a)	        n_alSndpGetSound()
#define alSndpSetSound( a, b)	        n_alSndpSetSound( b)

#define alEvtqNew		n_alEvtqNew
#define alEvtqNextEvent		n_alEvtqNextEvent
#define alEvtqPostEvent		n_alEvtqPostEvent
#define alEvtqFlushType		n_alEvtqFlushType
#define alEvtqPrintEvtQueue	n_alEvtqPrintEvtQueue
#define alEvtqPrintAllocEvts	n_alEvtqPrintAllocEvts





