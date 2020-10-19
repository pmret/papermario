.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240160_BDD310
/* BDD310 80240160 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BDD314 80240164 AFB10014 */  sw        $s1, 0x14($sp)
/* BDD318 80240168 0080882D */  daddu     $s1, $a0, $zero
/* BDD31C 8024016C AFBF001C */  sw        $ra, 0x1c($sp)
/* BDD320 80240170 AFB20018 */  sw        $s2, 0x18($sp)
/* BDD324 80240174 AFB00010 */  sw        $s0, 0x10($sp)
/* BDD328 80240178 8E320148 */  lw        $s2, 0x148($s1)
/* BDD32C 8024017C 0C00EABB */  jal       get_npc_unsafe
/* BDD330 80240180 86440008 */   lh       $a0, 8($s2)
/* BDD334 80240184 0040802D */  daddu     $s0, $v0, $zero
/* BDD338 80240188 0C00EAFF */  jal       disable_npc_shadow
/* BDD33C 8024018C 0200202D */   daddu    $a0, $s0, $zero
/* BDD340 80240190 24020016 */  addiu     $v0, $zero, 0x16
/* BDD344 80240194 A60200A8 */  sh        $v0, 0xa8($s0)
/* BDD348 80240198 24020018 */  addiu     $v0, $zero, 0x18
/* BDD34C 8024019C A60200A6 */  sh        $v0, 0xa6($s0)
/* BDD350 802401A0 AE200074 */  sw        $zero, 0x74($s1)
/* BDD354 802401A4 A600008E */  sh        $zero, 0x8e($s0)
/* BDD358 802401A8 8E4200CC */  lw        $v0, 0xcc($s2)
/* BDD35C 802401AC 8C420020 */  lw        $v0, 0x20($v0)
/* BDD360 802401B0 AE020028 */  sw        $v0, 0x28($s0)
/* BDD364 802401B4 24020001 */  addiu     $v0, $zero, 1
/* BDD368 802401B8 AE220070 */  sw        $v0, 0x70($s1)
/* BDD36C 802401BC 8FBF001C */  lw        $ra, 0x1c($sp)
/* BDD370 802401C0 8FB20018 */  lw        $s2, 0x18($sp)
/* BDD374 802401C4 8FB10014 */  lw        $s1, 0x14($sp)
/* BDD378 802401C8 8FB00010 */  lw        $s0, 0x10($sp)
/* BDD37C 802401CC 03E00008 */  jr        $ra
/* BDD380 802401D0 27BD0020 */   addiu    $sp, $sp, 0x20
