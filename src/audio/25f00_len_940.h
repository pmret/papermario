void create_audio_system(void);
//void nuAuPreNMIFuncSet(NUAuPreNMIFunc func);
void nuAuMgr(void* arg);
s32 nuAuDmaCallBack(s32 addr, s32 len, void *state, u8 arg3);
//ALDMAproc nuAuDmaNew(NUDMAState** state);
//void nuAuCleanDMABuffers(void);
void func_8004B328(NUScMsg mesg_type, u32 frameCounter);
//void alLink(ALLink* element, ALLink* after);
//void alUnlink(ALLink* element);
