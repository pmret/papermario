.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C10_DDD440
/* DDD440 80240C10 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DDD444 80240C14 AFB1001C */  sw        $s1, 0x1c($sp)
/* DDD448 80240C18 0080882D */  daddu     $s1, $a0, $zero
/* DDD44C 80240C1C AFBF0020 */  sw        $ra, 0x20($sp)
/* DDD450 80240C20 AFB00018 */  sw        $s0, 0x18($sp)
/* DDD454 80240C24 8E30000C */  lw        $s0, 0xc($s1)
/* DDD458 80240C28 8E050000 */  lw        $a1, ($s0)
/* DDD45C 80240C2C 0C0B1EAF */  jal       get_variable
/* DDD460 80240C30 26100004 */   addiu    $s0, $s0, 4
/* DDD464 80240C34 0C04417A */  jal       get_entity_by_index
/* DDD468 80240C38 0040202D */   daddu    $a0, $v0, $zero
/* DDD46C 80240C3C 8E100000 */  lw        $s0, ($s0)
/* DDD470 80240C40 C444004C */  lwc1      $f4, 0x4c($v0)
/* DDD474 80240C44 3C014148 */  lui       $at, 0x4148
/* DDD478 80240C48 44810000 */  mtc1      $at, $f0
/* DDD47C 80240C4C 3C013F33 */  lui       $at, 0x3f33
/* DDD480 80240C50 34213333 */  ori       $at, $at, 0x3333
/* DDD484 80240C54 44811000 */  mtc1      $at, $f2
/* DDD488 80240C58 AFA00014 */  sw        $zero, 0x14($sp)
/* DDD48C 80240C5C 46002100 */  add.s     $f4, $f4, $f0
/* DDD490 80240C60 E7A20010 */  swc1      $f2, 0x10($sp)
/* DDD494 80240C64 8C450048 */  lw        $a1, 0x48($v0)
/* DDD498 80240C68 8C470050 */  lw        $a3, 0x50($v0)
/* DDD49C 80240C6C 44062000 */  mfc1      $a2, $f4
/* DDD4A0 80240C70 0C01C5D4 */  jal       func_80071750
/* DDD4A4 80240C74 0000202D */   daddu    $a0, $zero, $zero
/* DDD4A8 80240C78 0220202D */  daddu     $a0, $s1, $zero
/* DDD4AC 80240C7C 0200282D */  daddu     $a1, $s0, $zero
/* DDD4B0 80240C80 0C0B2026 */  jal       set_variable
/* DDD4B4 80240C84 0040302D */   daddu    $a2, $v0, $zero
/* DDD4B8 80240C88 8FBF0020 */  lw        $ra, 0x20($sp)
/* DDD4BC 80240C8C 8FB1001C */  lw        $s1, 0x1c($sp)
/* DDD4C0 80240C90 8FB00018 */  lw        $s0, 0x18($sp)
/* DDD4C4 80240C94 24020002 */  addiu     $v0, $zero, 2
/* DDD4C8 80240C98 03E00008 */  jr        $ra
/* DDD4CC 80240C9C 27BD0028 */   addiu    $sp, $sp, 0x28
