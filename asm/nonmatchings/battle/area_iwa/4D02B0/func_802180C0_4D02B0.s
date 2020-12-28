.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802180C0_4D02B0
/* 4D02B0 802180C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4D02B4 802180C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 4D02B8 802180C8 0080882D */  daddu     $s1, $a0, $zero
/* 4D02BC 802180CC AFBF0018 */  sw        $ra, 0x18($sp)
/* 4D02C0 802180D0 AFB00010 */  sw        $s0, 0x10($sp)
/* 4D02C4 802180D4 8E30000C */  lw        $s0, 0xc($s1)
/* 4D02C8 802180D8 8E050000 */  lw        $a1, ($s0)
/* 4D02CC 802180DC 0C0B1EAF */  jal       get_variable
/* 4D02D0 802180E0 26100004 */   addiu    $s0, $s0, 4
/* 4D02D4 802180E4 0220202D */  daddu     $a0, $s1, $zero
/* 4D02D8 802180E8 8E050000 */  lw        $a1, ($s0)
/* 4D02DC 802180EC 0C0B1EAF */  jal       get_variable
/* 4D02E0 802180F0 0040802D */   daddu    $s0, $v0, $zero
/* 4D02E4 802180F4 0200202D */  daddu     $a0, $s0, $zero
/* 4D02E8 802180F8 0C00A3C2 */  jal       start_rumble
/* 4D02EC 802180FC 0040282D */   daddu    $a1, $v0, $zero
/* 4D02F0 80218100 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4D02F4 80218104 8FB10014 */  lw        $s1, 0x14($sp)
/* 4D02F8 80218108 8FB00010 */  lw        $s0, 0x10($sp)
/* 4D02FC 8021810C 24020002 */  addiu     $v0, $zero, 2
/* 4D0300 80218110 03E00008 */  jr        $ra
/* 4D0304 80218114 27BD0020 */   addiu    $sp, $sp, 0x20
/* 4D0308 80218118 00000000 */  nop       
/* 4D030C 8021811C 00000000 */  nop       
