.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241428_9F5E68
/* 9F5E68 80241428 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9F5E6C 8024142C AFB00010 */  sw        $s0, 0x10($sp)
/* 9F5E70 80241430 0080802D */  daddu     $s0, $a0, $zero
/* 9F5E74 80241434 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9F5E78 80241438 8E020148 */  lw        $v0, 0x148($s0)
/* 9F5E7C 8024143C 0C00EABB */  jal       get_npc_unsafe
/* 9F5E80 80241440 84440008 */   lh       $a0, 8($v0)
/* 9F5E84 80241444 9443008E */  lhu       $v1, 0x8e($v0)
/* 9F5E88 80241448 C440003C */  lwc1      $f0, 0x3c($v0)
/* 9F5E8C 8024144C 24640001 */  addiu     $a0, $v1, 1
/* 9F5E90 80241450 00031C00 */  sll       $v1, $v1, 0x10
/* 9F5E94 80241454 00031B83 */  sra       $v1, $v1, 0xe
/* 9F5E98 80241458 A444008E */  sh        $a0, 0x8e($v0)
/* 9F5E9C 8024145C 3C018024 */  lui       $at, %hi(D_80242888)
/* 9F5EA0 80241460 00230821 */  addu      $at, $at, $v1
/* 9F5EA4 80241464 C4222888 */  lwc1      $f2, %lo(D_80242888)($at)
/* 9F5EA8 80241468 8443008E */  lh        $v1, 0x8e($v0)
/* 9F5EAC 8024146C 46020000 */  add.s     $f0, $f0, $f2
/* 9F5EB0 80241470 28630005 */  slti      $v1, $v1, 5
/* 9F5EB4 80241474 14600003 */  bnez      $v1, .L80241484
/* 9F5EB8 80241478 E440003C */   swc1     $f0, 0x3c($v0)
/* 9F5EBC 8024147C 2402000C */  addiu     $v0, $zero, 0xc
/* 9F5EC0 80241480 AE020070 */  sw        $v0, 0x70($s0)
.L80241484:
/* 9F5EC4 80241484 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9F5EC8 80241488 8FB00010 */  lw        $s0, 0x10($sp)
/* 9F5ECC 8024148C 03E00008 */  jr        $ra
/* 9F5ED0 80241490 27BD0018 */   addiu    $sp, $sp, 0x18
