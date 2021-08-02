.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_EA0C10
/* EA0C10 80240310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EA0C14 80240314 AFB10014 */  sw        $s1, 0x14($sp)
/* EA0C18 80240318 0080882D */  daddu     $s1, $a0, $zero
/* EA0C1C 8024031C AFBF0018 */  sw        $ra, 0x18($sp)
/* EA0C20 80240320 AFB00010 */  sw        $s0, 0x10($sp)
/* EA0C24 80240324 8E300148 */  lw        $s0, 0x148($s1)
/* EA0C28 80240328 0C00F92F */  jal       dead_get_npc_unsafe
/* EA0C2C 8024032C 86040008 */   lh       $a0, 8($s0)
/* EA0C30 80240330 24030001 */  addiu     $v1, $zero, 1
/* EA0C34 80240334 0040202D */  daddu     $a0, $v0, $zero
/* EA0C38 80240338 AE03006C */  sw        $v1, 0x6c($s0)
/* EA0C3C 8024033C 8482008C */  lh        $v0, 0x8c($a0)
/* EA0C40 80240340 14400009 */  bnez      $v0, .L80240368
/* EA0C44 80240344 24020002 */   addiu    $v0, $zero, 2
/* EA0C48 80240348 96030072 */  lhu       $v1, 0x72($s0)
/* EA0C4C 8024034C AE02006C */  sw        $v0, 0x6c($s0)
/* EA0C50 80240350 A483008E */  sh        $v1, 0x8e($a0)
/* EA0C54 80240354 8E0200CC */  lw        $v0, 0xcc($s0)
/* EA0C58 80240358 8C420020 */  lw        $v0, 0x20($v0)
/* EA0C5C 8024035C AC820028 */  sw        $v0, 0x28($a0)
/* EA0C60 80240360 2402001F */  addiu     $v0, $zero, 0x1f
/* EA0C64 80240364 AE220070 */  sw        $v0, 0x70($s1)
.L80240368:
/* EA0C68 80240368 8FBF0018 */  lw        $ra, 0x18($sp)
/* EA0C6C 8024036C 8FB10014 */  lw        $s1, 0x14($sp)
/* EA0C70 80240370 8FB00010 */  lw        $s0, 0x10($sp)
/* EA0C74 80240374 03E00008 */  jr        $ra
/* EA0C78 80240378 27BD0020 */   addiu    $sp, $sp, 0x20
