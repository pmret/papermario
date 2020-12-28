#include "common.h"
#include "nu/nusys.h"

void nuContPakMgrInit(void) {
    nuSiCallBackAdd(&nuContCallBack);
}

void nuContPakMgrRemove(void) {
    nuSiCallBackRemove(&nuContCallBack);
}

s32 contPakOpen(NUSiCommonMesg* mesg) {
    s32 err;
    NUContPakFile* file = (NUContPakFile*) mesg->dataPtr;

    file->type = NU_CONT_PAK_TYPE_NONE;
    err = osPfsInitPak(&nuSiMesgQ, file->pfs, file->pfs->channel);

    if (err == 0) {
        file->type = NU_CONT_PAK_TYPE_PAK;
    }

    return err;
}

s32 contPakFree(NUSiCommonMesg* mesg) {
    NUContPakFreeMesg* freeMesg = (NUContPakFreeMesg*) mesg->dataPtr;

    return osPfsFreeBlocks(freeMesg->file->pfs, &freeMesg->size);
}

s32 contPakFileReadWrite(NUSiCommonMesg* mesg) {
    NUContPakFileRWMesg* rwMesg = (NUContPakFileRWMesg*) mesg->dataPtr;

    return osPfsReadWriteFile(rwMesg->file->pfs, rwMesg->file->file_no, rwMesg->mode, rwMesg->offset, rwMesg->size,
                              rwMesg->buf);
}

s32 contPakFileOpen(NUSiCommonMesg* mesg) {
    NUContPakFileOpenMesg* openMesg = mesg->dataPtr;
    NUContPakFile* file = openMesg->file;
    s32 err;

    err = osPfsFindFile(file->pfs, nuContPakCompanyCode, nuContPakGameCode, openMesg->noteName, openMesg->extName,
                        &file->file_no);
    if (err == PFS_ERR_INVALID) {
        if (openMesg->mode == NU_CONT_PAK_MODE_CREATE) {
            err = osPfsAllocateFile(file->pfs, nuContPakCompanyCode, nuContPakGameCode, openMesg->noteName, openMesg->extName,
                                    openMesg->size, &file->file_no);
        }
    }
    return err;
}

s32 contPakFileDelete(NUSiCommonMesg* mesg) {
    NUContPakFileOpenMesg* openMesg = (NUContPakFileOpenMesg*) mesg->dataPtr;

    return osPfsDeleteFile(openMesg->file->pfs, nuContPakCompanyCode, nuContPakGameCode, openMesg->noteName,
                           openMesg->extName);
}

s32 contPakFileState(NUSiCommonMesg* mesg) {
    NUContPakFileStateMesg* state = (NUContPakFileStateMesg*) mesg->dataPtr;

    return osPfsFileState(state->file->pfs, state->file->file_no, state->state);
}

s32 contPakFileNum(NUSiCommonMesg* mesg) {
    NUContPakFileNumMesg* fileNum = (NUContPakFileNumMesg*) mesg->dataPtr;

    return osPfsNumFiles(fileNum->file->pfs, fileNum->max_files, fileNum->used_files);
}

s32 contPakRepairId(NUSiCommonMesg* mesg) {
    NUContPakFile* file = (NUContPakFile*) mesg->dataPtr;

    return osPfsRepairId(file->pfs);
}
