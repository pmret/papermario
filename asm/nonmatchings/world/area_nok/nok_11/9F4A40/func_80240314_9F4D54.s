.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240314_9F4D54
/* 9F4D54 80240314 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9F4D58 80240318 AFB10014 */  sw        $s1, 0x14($sp)
/* 9F4D5C 8024031C 0080882D */  daddu     $s1, $a0, $zero
/* 9F4D60 80240320 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9F4D64 80240324 AFB00010 */  sw        $s0, 0x10($sp)
/* 9F4D68 80240328 8E300148 */  lw        $s0, 0x148($s1)
/* 9F4D6C 8024032C 0C00EABB */  jal       get_npc_unsafe
/* 9F4D70 80240330 86040008 */   lh       $a0, 8($s0)
/* 9F4D74 80240334 0040202D */  daddu     $a0, $v0, $zero
/* 9F4D78 80240338 9482008E */  lhu       $v0, 0x8e($a0)
/* 9F4D7C 8024033C 24030003 */  addiu     $v1, $zero, 3
/* 9F4D80 80240340 24420001 */  addiu     $v0, $v0, 1
/* 9F4D84 80240344 A482008E */  sh        $v0, 0x8e($a0)
/* 9F4D88 80240348 00021400 */  sll       $v0, $v0, 0x10
/* 9F4D8C 8024034C 00021403 */  sra       $v0, $v0, 0x10
/* 9F4D90 80240350 14430003 */  bne       $v0, $v1, .L80240360
/* 9F4D94 80240354 00000000 */   nop      
/* 9F4D98 80240358 96020086 */  lhu       $v0, 0x86($s0)
/* 9F4D9C 8024035C A48200A8 */  sh        $v0, 0xa8($a0)
.L80240360:
/* 9F4DA0 80240360 8482008E */  lh        $v0, 0x8e($a0)
/* 9F4DA4 80240364 8E030080 */  lw        $v1, 0x80($s0)
/* 9F4DA8 80240368 0043102A */  slt       $v0, $v0, $v1
/* 9F4DAC 8024036C 14400004 */  bnez      $v0, .L80240380
/* 9F4DB0 80240370 00000000 */   nop      
/* 9F4DB4 80240374 96020086 */  lhu       $v0, 0x86($s0)
/* 9F4DB8 80240378 A48200A8 */  sh        $v0, 0xa8($a0)
/* 9F4DBC 8024037C AE200070 */  sw        $zero, 0x70($s1)
.L80240380:
/* 9F4DC0 80240380 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9F4DC4 80240384 8FB10014 */  lw        $s1, 0x14($sp)
/* 9F4DC8 80240388 8FB00010 */  lw        $s0, 0x10($sp)
/* 9F4DCC 8024038C 03E00008 */  jr        $ra
/* 9F4DD0 80240390 27BD0020 */   addiu    $sp, $sp, 0x20
