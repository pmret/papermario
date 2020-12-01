.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241474_C6F7A4
/* C6F7A4 80241474 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C6F7A8 80241478 AFB00010 */  sw        $s0, 0x10($sp)
/* C6F7AC 8024147C 0080802D */  daddu     $s0, $a0, $zero
/* C6F7B0 80241480 AFBF0014 */  sw        $ra, 0x14($sp)
/* C6F7B4 80241484 8E020148 */  lw        $v0, 0x148($s0)
/* C6F7B8 80241488 0C00EABB */  jal       get_npc_unsafe
/* C6F7BC 8024148C 84440008 */   lh       $a0, 8($v0)
/* C6F7C0 80241490 9443008E */  lhu       $v1, 0x8e($v0)
/* C6F7C4 80241494 C440003C */  lwc1      $f0, 0x3c($v0)
/* C6F7C8 80241498 24640001 */  addiu     $a0, $v1, 1
/* C6F7CC 8024149C 00031C00 */  sll       $v1, $v1, 0x10
/* C6F7D0 802414A0 00031B83 */  sra       $v1, $v1, 0xe
/* C6F7D4 802414A4 A444008E */  sh        $a0, 0x8e($v0)
/* C6F7D8 802414A8 3C018024 */  lui       $at, %hi(D_80242B90)
/* C6F7DC 802414AC 00230821 */  addu      $at, $at, $v1
/* C6F7E0 802414B0 C4222B90 */  lwc1      $f2, %lo(D_80242B90)($at)
/* C6F7E4 802414B4 8443008E */  lh        $v1, 0x8e($v0)
/* C6F7E8 802414B8 46020000 */  add.s     $f0, $f0, $f2
/* C6F7EC 802414BC 28630005 */  slti      $v1, $v1, 5
/* C6F7F0 802414C0 14600003 */  bnez      $v1, .L802414D0
/* C6F7F4 802414C4 E440003C */   swc1     $f0, 0x3c($v0)
/* C6F7F8 802414C8 2402000C */  addiu     $v0, $zero, 0xc
/* C6F7FC 802414CC AE020070 */  sw        $v0, 0x70($s0)
.L802414D0:
/* C6F800 802414D0 8FBF0014 */  lw        $ra, 0x14($sp)
/* C6F804 802414D4 8FB00010 */  lw        $s0, 0x10($sp)
/* C6F808 802414D8 03E00008 */  jr        $ra
/* C6F80C 802414DC 27BD0018 */   addiu    $sp, $sp, 0x18
