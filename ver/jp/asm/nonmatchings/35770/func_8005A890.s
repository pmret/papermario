.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005A890
/* 35C90 8005A890 3C02800A */  lui       $v0, %hi(D_800A1FF0)
/* 35C94 8005A894 8C421FF0 */  lw        $v0, %lo(D_800A1FF0)($v0)
/* 35C98 8005A898 03E00008 */  jr        $ra
/* 35C9C 8005A89C 00000000 */   nop
