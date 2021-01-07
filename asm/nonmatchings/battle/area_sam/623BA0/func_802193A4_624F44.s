.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802193A4_624F44
/* 624F44 802193A4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 624F48 802193A8 AFB00010 */  sw        $s0, 0x10($sp)
/* 624F4C 802193AC 0080802D */  daddu     $s0, $a0, $zero
/* 624F50 802193B0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 624F54 802193B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 624F58 802193B8 8E040148 */  lw        $a0, 0x148($s0)
/* 624F5C 802193BC 0C09A75B */  jal       get_actor
/* 624F60 802193C0 8E11000C */   lw       $s1, 0xc($s0)
/* 624F64 802193C4 0200202D */  daddu     $a0, $s0, $zero
/* 624F68 802193C8 8E250000 */  lw        $a1, ($s1)
/* 624F6C 802193CC 0C0B1EAF */  jal       get_variable
/* 624F70 802193D0 8C500090 */   lw       $s0, 0x90($v0)
/* 624F74 802193D4 AE02000C */  sw        $v0, 0xc($s0)
/* 624F78 802193D8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 624F7C 802193DC 8FB10014 */  lw        $s1, 0x14($sp)
/* 624F80 802193E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 624F84 802193E4 24020002 */  addiu     $v0, $zero, 2
/* 624F88 802193E8 03E00008 */  jr        $ra
/* 624F8C 802193EC 27BD0020 */   addiu    $sp, $sp, 0x20
