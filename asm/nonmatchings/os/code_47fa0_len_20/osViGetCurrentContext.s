.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osViGetCurrentContext
/* 47FA0 8006CBA0 3C028009 */  lui       $v0, 0x8009
/* 47FA4 8006CBA4 03E00008 */  jr        $ra
/* 47FA8 8006CBA8 8C4259D0 */   lw       $v0, 0x59d0($v0)
/* 47FAC 8006CBAC 00000000 */  nop       
/* 47FB0 8006CBB0 00000000 */  nop       
/* 47FB4 8006CBB4 00000000 */  nop       
/* 47FB8 8006CBB8 00000000 */  nop       
/* 47FBC 8006CBBC 00000000 */  nop       
