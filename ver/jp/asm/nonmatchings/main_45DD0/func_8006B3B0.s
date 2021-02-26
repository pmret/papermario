.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006B3B0
/* 467B0 8006B3B0 40086000 */  mfc0      $t0, $12
/* 467B4 8006B3B4 01044025 */  or        $t0, $t0, $a0
/* 467B8 8006B3B8 40886000 */  mtc0      $t0, $12
/* 467BC 8006B3BC 00000000 */  nop
/* 467C0 8006B3C0 00000000 */  nop
/* 467C4 8006B3C4 03E00008 */  jr        $ra
/* 467C8 8006B3C8 00000000 */   nop
/* 467CC 8006B3CC 00000000 */  nop
