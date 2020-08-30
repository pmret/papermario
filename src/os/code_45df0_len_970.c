#include "common.h"

INCLUDE_ASM("os/code_45df0_len_970", func_8006A9F0);

INCLUDE_API_ASM("os/code_45df0_len_970", osExceptionPreamble);

INCLUDE_API_ASM("os/code_45df0_len_970", savecontext);

INCLUDE_API_ASM("os/code_45df0_len_970", savercp);

INCLUDE_API_ASM("os/code_45df0_len_970", endrcp);

INCLUDE_ASM("os/code_45df0_len_970", handle_interrupt);

INCLUDE_ASM("os/code_45df0_len_970", next_interrupt);

INCLUDE_ASM("os/code_45df0_len_970", IP6_Hdlr);

INCLUDE_ASM("os/code_45df0_len_970", IP7_Hdlr);

INCLUDE_API_ASM("os/code_45df0_len_970", counter);

INCLUDE_API_ASM("os/code_45df0_len_970", cart);

INCLUDE_API_ASM("os/code_45df0_len_970", rcp);

INCLUDE_ASM("os/code_45df0_len_970", sp_other_break);

INCLUDE_API_ASM("os/code_45df0_len_970", vi);

INCLUDE_API_ASM("os/code_45df0_len_970", ai);

INCLUDE_API_ASM("os/code_45df0_len_970", si);

INCLUDE_API_ASM("os/code_45df0_len_970", pi);

INCLUDE_API_ASM("os/code_45df0_len_970", dp);

INCLUDE_API_ASM("os/code_45df0_len_970", NoMoreRcpInts);

INCLUDE_API_ASM("os/code_45df0_len_970", prenmi);

INCLUDE_API_ASM("os/code_45df0_len_970", firstnmi);

INCLUDE_API_ASM("os/code_45df0_len_970", sw2);

INCLUDE_API_ASM("os/code_45df0_len_970", sw1);

INCLUDE_ASM("os/code_45df0_len_970", handle_break);

INCLUDE_API_ASM("os/code_45df0_len_970", redispatch);

INCLUDE_API_ASM("os/code_45df0_len_970", enqueueRunning);

INCLUDE_API_ASM("os/code_45df0_len_970", panic);

INCLUDE_ASM("os/code_45df0_len_970", send_mesg);

INCLUDE_ASM("os/code_45df0_len_970", send_done);

INCLUDE_ASM("os/code_45df0_len_970", handle_CPU);

INCLUDE_API_ASM("os/code_45df0_len_970", osEnqueueAndYield);

INCLUDE_API_ASM("os/code_45df0_len_970", noEnqueue);

INCLUDE_API_ASM("os/code_45df0_len_970", osEnqueueThread);

INCLUDE_API_ASM("os/code_45df0_len_970", osPopThread);

INCLUDE_API_ASM("os/code_45df0_len_970", osNop);

INCLUDE_API_ASM("os/code_45df0_len_970", osDispatchThread);

INCLUDE_API_ASM("os/code_45df0_len_970", osDispatchThreadSave);

void INCLUDE_ASM("os/code_45df0_len_970", osCleanupThread, void);
