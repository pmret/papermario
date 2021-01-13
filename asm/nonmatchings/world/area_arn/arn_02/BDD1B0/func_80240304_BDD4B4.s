.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240304_BDD4B4
/* BDD4B4 80240304 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BDD4B8 80240308 AFB20018 */  sw        $s2, 0x18($sp)
/* BDD4BC 8024030C 0080902D */  daddu     $s2, $a0, $zero
/* BDD4C0 80240310 AFBF001C */  sw        $ra, 0x1c($sp)
/* BDD4C4 80240314 AFB10014 */  sw        $s1, 0x14($sp)
/* BDD4C8 80240318 AFB00010 */  sw        $s0, 0x10($sp)
/* BDD4CC 8024031C 8E510148 */  lw        $s1, 0x148($s2)
/* BDD4D0 80240320 0C00EABB */  jal       get_npc_unsafe
/* BDD4D4 80240324 86240008 */   lh       $a0, 8($s1)
/* BDD4D8 80240328 0040802D */  daddu     $s0, $v0, $zero
/* BDD4DC 8024032C 9602008E */  lhu       $v0, 0x8e($s0)
/* BDD4E0 80240330 2442FFFF */  addiu     $v0, $v0, -1
/* BDD4E4 80240334 A602008E */  sh        $v0, 0x8e($s0)
/* BDD4E8 80240338 00021400 */  sll       $v0, $v0, 0x10
/* BDD4EC 8024033C 1C400012 */  bgtz      $v0, .L80240388
/* BDD4F0 80240340 00000000 */   nop
/* BDD4F4 80240344 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BDD4F8 80240348 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BDD4FC 8024034C C60C0038 */  lwc1      $f12, 0x38($s0)
/* BDD500 80240350 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BDD504 80240354 8C460028 */  lw        $a2, 0x28($v0)
/* BDD508 80240358 0C00A720 */  jal       atan2
/* BDD50C 8024035C 8C470030 */   lw       $a3, 0x30($v0)
/* BDD510 80240360 0200202D */  daddu     $a0, $s0, $zero
/* BDD514 80240364 0C00EAE8 */  jal       enable_npc_shadow
/* BDD518 80240368 E600000C */   swc1     $f0, 0xc($s0)
/* BDD51C 8024036C 8E2200CC */  lw        $v0, 0xcc($s1)
/* BDD520 80240370 8C430028 */  lw        $v1, 0x28($v0)
/* BDD524 80240374 24020008 */  addiu     $v0, $zero, 8
/* BDD528 80240378 A602008E */  sh        $v0, 0x8e($s0)
/* BDD52C 8024037C 24020003 */  addiu     $v0, $zero, 3
/* BDD530 80240380 AE030028 */  sw        $v1, 0x28($s0)
/* BDD534 80240384 AE420070 */  sw        $v0, 0x70($s2)
.L80240388:
/* BDD538 80240388 8FBF001C */  lw        $ra, 0x1c($sp)
/* BDD53C 8024038C 8FB20018 */  lw        $s2, 0x18($sp)
/* BDD540 80240390 8FB10014 */  lw        $s1, 0x14($sp)
/* BDD544 80240394 8FB00010 */  lw        $s0, 0x10($sp)
/* BDD548 80240398 03E00008 */  jr        $ra
/* BDD54C 8024039C 27BD0020 */   addiu    $sp, $sp, 0x20
