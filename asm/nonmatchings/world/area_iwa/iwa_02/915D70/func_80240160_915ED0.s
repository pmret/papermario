.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240160_915ED0
/* 915ED0 80240160 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 915ED4 80240164 AFB10014 */  sw        $s1, 0x14($sp)
/* 915ED8 80240168 0080882D */  daddu     $s1, $a0, $zero
/* 915EDC 8024016C AFBF001C */  sw        $ra, 0x1c($sp)
/* 915EE0 80240170 AFB20018 */  sw        $s2, 0x18($sp)
/* 915EE4 80240174 AFB00010 */  sw        $s0, 0x10($sp)
/* 915EE8 80240178 8E320148 */  lw        $s2, 0x148($s1)
/* 915EEC 8024017C 0C00EABB */  jal       get_npc_unsafe
/* 915EF0 80240180 86440008 */   lh       $a0, 8($s2)
/* 915EF4 80240184 0040802D */  daddu     $s0, $v0, $zero
/* 915EF8 80240188 0C00EAFF */  jal       disable_npc_shadow
/* 915EFC 8024018C 0200202D */   daddu    $a0, $s0, $zero
/* 915F00 80240190 24020016 */  addiu     $v0, $zero, 0x16
/* 915F04 80240194 A60200A8 */  sh        $v0, 0xa8($s0)
/* 915F08 80240198 24020018 */  addiu     $v0, $zero, 0x18
/* 915F0C 8024019C A60200A6 */  sh        $v0, 0xa6($s0)
/* 915F10 802401A0 AE200074 */  sw        $zero, 0x74($s1)
/* 915F14 802401A4 A600008E */  sh        $zero, 0x8e($s0)
/* 915F18 802401A8 8E4200CC */  lw        $v0, 0xcc($s2)
/* 915F1C 802401AC 8C420020 */  lw        $v0, 0x20($v0)
/* 915F20 802401B0 AE020028 */  sw        $v0, 0x28($s0)
/* 915F24 802401B4 24020001 */  addiu     $v0, $zero, 1
/* 915F28 802401B8 AE220070 */  sw        $v0, 0x70($s1)
/* 915F2C 802401BC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 915F30 802401C0 8FB20018 */  lw        $s2, 0x18($sp)
/* 915F34 802401C4 8FB10014 */  lw        $s1, 0x14($sp)
/* 915F38 802401C8 8FB00010 */  lw        $s0, 0x10($sp)
/* 915F3C 802401CC 03E00008 */  jr        $ra
/* 915F40 802401D0 27BD0020 */   addiu    $sp, $sp, 0x20
