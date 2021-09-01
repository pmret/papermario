.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802193F0_624F90
/* 624F90 802193F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 624F94 802193F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 624F98 802193F8 0080802D */  daddu     $s0, $a0, $zero
/* 624F9C 802193FC AFBF0018 */  sw        $ra, 0x18($sp)
/* 624FA0 80219400 AFB10014 */  sw        $s1, 0x14($sp)
/* 624FA4 80219404 8E040148 */  lw        $a0, 0x148($s0)
/* 624FA8 80219408 0C09A75B */  jal       get_actor
/* 624FAC 8021940C 8E11000C */   lw       $s1, 0xc($s0)
/* 624FB0 80219410 0200202D */  daddu     $a0, $s0, $zero
/* 624FB4 80219414 8E250000 */  lw        $a1, ($s1)
/* 624FB8 80219418 0C0B1EAF */  jal       evt_get_variable
/* 624FBC 8021941C 8C500090 */   lw       $s0, 0x90($v0)
/* 624FC0 80219420 AE020010 */  sw        $v0, 0x10($s0)
/* 624FC4 80219424 8FBF0018 */  lw        $ra, 0x18($sp)
/* 624FC8 80219428 8FB10014 */  lw        $s1, 0x14($sp)
/* 624FCC 8021942C 8FB00010 */  lw        $s0, 0x10($sp)
/* 624FD0 80219430 24020002 */  addiu     $v0, $zero, 2
/* 624FD4 80219434 03E00008 */  jr        $ra
/* 624FD8 80219438 27BD0020 */   addiu    $sp, $sp, 0x20
