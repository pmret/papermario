.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E10F4
/* 102974 802E10F4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 102978 802E10F8 AFB10014 */  sw        $s1, 0x14($sp)
/* 10297C 802E10FC 0080882D */  daddu     $s1, $a0, $zero
/* 102980 802E1100 AFBF0018 */  sw        $ra, 0x18($sp)
/* 102984 802E1104 AFB00010 */  sw        $s0, 0x10($sp)
/* 102988 802E1108 8E300040 */  lw        $s0, 0x40($s1)
/* 10298C 802E110C 86020004 */  lh        $v0, 4($s0)
/* 102990 802E1110 24420006 */  addiu     $v0, $v0, 6
/* 102994 802E1114 44826000 */  mtc1      $v0, $f12
/* 102998 802E1118 00000000 */  nop
/* 10299C 802E111C 0C00A6C9 */  jal       clamp_angle
/* 1029A0 802E1120 46806320 */   cvt.s.w  $f12, $f12
/* 1029A4 802E1124 4600008D */  trunc.w.s $f2, $f0
/* 1029A8 802E1128 44021000 */  mfc1      $v0, $f2
/* 1029AC 802E112C 0220202D */  daddu     $a0, $s1, $zero
/* 1029B0 802E1130 0C0B8D94 */  jal       func_802E3650
/* 1029B4 802E1134 A6020004 */   sh       $v0, 4($s0)
/* 1029B8 802E1138 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1029BC 802E113C 8FB10014 */  lw        $s1, 0x14($sp)
/* 1029C0 802E1140 8FB00010 */  lw        $s0, 0x10($sp)
/* 1029C4 802E1144 03E00008 */  jr        $ra
/* 1029C8 802E1148 27BD0020 */   addiu    $sp, $sp, 0x20
