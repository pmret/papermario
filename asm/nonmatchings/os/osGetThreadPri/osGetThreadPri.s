.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osGetThreadPri
/* 41330 80065F30 14800003 */  bnez      $a0, .L80065F40
/* 41334 80065F34 00000000 */   nop      
/* 41338 80065F38 3C048009 */  lui       $a0, %hi(D_80094660)
/* 4133C 80065F3C 8C844660 */  lw        $a0, %lo(D_80094660)($a0)
.L80065F40:
/* 41340 80065F40 03E00008 */  jr        $ra
/* 41344 80065F44 8C820004 */   lw       $v0, 4($a0)
/* 41348 80065F48 00000000 */  nop       
/* 4134C 80065F4C 00000000 */  nop       
