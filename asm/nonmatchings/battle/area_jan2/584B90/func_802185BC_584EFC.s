.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802185BC_584EFC
/* 584EFC 802185BC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 584F00 802185C0 AFB10014 */  sw        $s1, 0x14($sp)
/* 584F04 802185C4 0080882D */  daddu     $s1, $a0, $zero
/* 584F08 802185C8 AFB20018 */  sw        $s2, 0x18($sp)
/* 584F0C 802185CC 3C128011 */  lui       $s2, %hi(gPlayerData)
/* 584F10 802185D0 2652F290 */  addiu     $s2, $s2, %lo(gPlayerData)
/* 584F14 802185D4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 584F18 802185D8 AFB00010 */  sw        $s0, 0x10($sp)
/* 584F1C 802185DC 8E30000C */  lw        $s0, 0xc($s1)
/* 584F20 802185E0 82460000 */  lb        $a2, ($s2)
/* 584F24 802185E4 8E050000 */  lw        $a1, ($s0)
/* 584F28 802185E8 0C0B2026 */  jal       set_variable
/* 584F2C 802185EC 26100004 */   addiu    $s0, $s0, 4
/* 584F30 802185F0 8E050000 */  lw        $a1, ($s0)
/* 584F34 802185F4 82460001 */  lb        $a2, 1($s2)
/* 584F38 802185F8 0C0B2026 */  jal       set_variable
/* 584F3C 802185FC 0220202D */   daddu    $a0, $s1, $zero
/* 584F40 80218600 8FBF001C */  lw        $ra, 0x1c($sp)
/* 584F44 80218604 8FB20018 */  lw        $s2, 0x18($sp)
/* 584F48 80218608 8FB10014 */  lw        $s1, 0x14($sp)
/* 584F4C 8021860C 8FB00010 */  lw        $s0, 0x10($sp)
/* 584F50 80218610 24020002 */  addiu     $v0, $zero, 2
/* 584F54 80218614 03E00008 */  jr        $ra
/* 584F58 80218618 27BD0020 */   addiu    $sp, $sp, 0x20
