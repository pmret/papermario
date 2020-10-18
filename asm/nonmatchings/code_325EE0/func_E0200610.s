.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200610
/* 3260E0 E0200610 3C01E020 */  lui       $at, 0xe020
/* 3260E4 E0200614 8C210714 */  lw        $at, 0x714($at)
/* 3260E8 E0200618 00200008 */  jr        $at
/* 3260EC E020061C 00000000 */   nop      
