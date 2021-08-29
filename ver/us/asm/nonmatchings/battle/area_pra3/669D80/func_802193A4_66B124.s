.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802193A4_66B124
/* 66B124 802193A4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 66B128 802193A8 AFB00010 */  sw        $s0, 0x10($sp)
/* 66B12C 802193AC 0080802D */  daddu     $s0, $a0, $zero
/* 66B130 802193B0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 66B134 802193B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 66B138 802193B8 8E040148 */  lw        $a0, 0x148($s0)
/* 66B13C 802193BC 0C09A75B */  jal       get_actor
/* 66B140 802193C0 8E11000C */   lw       $s1, 0xc($s0)
/* 66B144 802193C4 0200202D */  daddu     $a0, $s0, $zero
/* 66B148 802193C8 8E250000 */  lw        $a1, ($s1)
/* 66B14C 802193CC 0C0B1EAF */  jal       evt_get_variable
/* 66B150 802193D0 8C500090 */   lw       $s0, 0x90($v0)
/* 66B154 802193D4 AE02000C */  sw        $v0, 0xc($s0)
/* 66B158 802193D8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 66B15C 802193DC 8FB10014 */  lw        $s1, 0x14($sp)
/* 66B160 802193E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 66B164 802193E4 24020002 */  addiu     $v0, $zero, 2
/* 66B168 802193E8 03E00008 */  jr        $ra
/* 66B16C 802193EC 27BD0020 */   addiu    $sp, $sp, 0x20
