.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415C4_8ED3E4
/* 8ED3E4 802415C4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8ED3E8 802415C8 0000202D */  daddu     $a0, $zero, $zero
/* 8ED3EC 802415CC 240503E8 */  addiu     $a1, $zero, 0x3e8
/* 8ED3F0 802415D0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8ED3F4 802415D4 0C01559B */  jal       func_8005566C
/* 8ED3F8 802415D8 2406003F */   addiu    $a2, $zero, 0x3f
/* 8ED3FC 802415DC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8ED400 802415E0 24020002 */  addiu     $v0, $zero, 2
/* 8ED404 802415E4 03E00008 */  jr        $ra
/* 8ED408 802415E8 27BD0018 */   addiu    $sp, $sp, 0x18
