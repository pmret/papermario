.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD2D8
/* 318028 802BD2D8 2402001C */  addiu     $v0, $zero, 0x1c
/* 31802C 802BD2DC A48200A8 */  sh        $v0, 0xa8($a0)
/* 318030 802BD2E0 24020018 */  addiu     $v0, $zero, 0x18
/* 318034 802BD2E4 A48200A6 */  sh        $v0, 0xa6($a0)
/* 318038 802BD2E8 3C01802C */  lui       $at, 0x802c
/* 31803C 802BD2EC AC20E928 */  sw        $zero, -0x16d8($at)
/* 318040 802BD2F0 3C01802C */  lui       $at, 0x802c
/* 318044 802BD2F4 AC20E924 */  sw        $zero, -0x16dc($at)
/* 318048 802BD2F8 03E00008 */  jr        $ra
/* 31804C 802BD2FC 00000000 */   nop      
