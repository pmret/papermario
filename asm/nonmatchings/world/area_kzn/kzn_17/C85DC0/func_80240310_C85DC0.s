.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_C85DC0
/* C85DC0 80240310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C85DC4 80240314 AFB10014 */  sw        $s1, 0x14($sp)
/* C85DC8 80240318 0080882D */  daddu     $s1, $a0, $zero
/* C85DCC 8024031C AFBF0018 */  sw        $ra, 0x18($sp)
/* C85DD0 80240320 AFB00010 */  sw        $s0, 0x10($sp)
/* C85DD4 80240324 8E300148 */  lw        $s0, 0x148($s1)
/* C85DD8 80240328 0C00EABB */  jal       get_npc_unsafe
/* C85DDC 8024032C 86040008 */   lh       $a0, 8($s0)
/* C85DE0 80240330 24030001 */  addiu     $v1, $zero, 1
/* C85DE4 80240334 0040202D */  daddu     $a0, $v0, $zero
/* C85DE8 80240338 AE03006C */  sw        $v1, 0x6c($s0)
/* C85DEC 8024033C 8482008C */  lh        $v0, 0x8c($a0)
/* C85DF0 80240340 14400009 */  bnez      $v0, .L80240368
/* C85DF4 80240344 24020002 */   addiu    $v0, $zero, 2
/* C85DF8 80240348 96030072 */  lhu       $v1, 0x72($s0)
/* C85DFC 8024034C AE02006C */  sw        $v0, 0x6c($s0)
/* C85E00 80240350 A483008E */  sh        $v1, 0x8e($a0)
/* C85E04 80240354 8E0200CC */  lw        $v0, 0xcc($s0)
/* C85E08 80240358 8C420020 */  lw        $v0, 0x20($v0)
/* C85E0C 8024035C AC820028 */  sw        $v0, 0x28($a0)
/* C85E10 80240360 2402001F */  addiu     $v0, $zero, 0x1f
/* C85E14 80240364 AE220070 */  sw        $v0, 0x70($s1)
.L80240368:
/* C85E18 80240368 8FBF0018 */  lw        $ra, 0x18($sp)
/* C85E1C 8024036C 8FB10014 */  lw        $s1, 0x14($sp)
/* C85E20 80240370 8FB00010 */  lw        $s0, 0x10($sp)
/* C85E24 80240374 03E00008 */  jr        $ra
/* C85E28 80240378 27BD0020 */   addiu    $sp, $sp, 0x20
