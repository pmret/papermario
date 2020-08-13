.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel noEnqueue
.L8006B16C:
/* 04656C 8006B16C 0801AC75 */  j     osDispatchThread
/* 046570 8006B170 00000000 */   nop   

