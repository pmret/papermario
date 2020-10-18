.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200620
/* 3260F0 E0200620 3C01E020 */  lui       $at, 0xe020
/* 3260F4 E0200624 8C210718 */  lw        $at, 0x718($at)
/* 3260F8 E0200628 00200008 */  jr        $at
/* 3260FC E020062C 00000000 */   nop      
