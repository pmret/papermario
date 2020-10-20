.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E18_CC4628
/* CC4628 80240E18 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CC462C 80240E1C AFB00010 */  sw        $s0, 0x10($sp)
/* CC4630 80240E20 0080802D */  daddu     $s0, $a0, $zero
/* CC4634 80240E24 AFBF0014 */  sw        $ra, 0x14($sp)
/* CC4638 80240E28 8E020148 */  lw        $v0, 0x148($s0)
/* CC463C 80240E2C 0C00EABB */  jal       get_npc_unsafe
/* CC4640 80240E30 84440008 */   lh       $a0, 8($v0)
/* CC4644 80240E34 9443008E */  lhu       $v1, 0x8e($v0)
/* CC4648 80240E38 C440003C */  lwc1      $f0, 0x3c($v0)
/* CC464C 80240E3C 24640001 */  addiu     $a0, $v1, 1
/* CC4650 80240E40 00031C00 */  sll       $v1, $v1, 0x10
/* CC4654 80240E44 00031B83 */  sra       $v1, $v1, 0xe
/* CC4658 80240E48 A444008E */  sh        $a0, 0x8e($v0)
/* CC465C 80240E4C 3C018024 */  lui       $at, 0x8024
/* CC4660 80240E50 00230821 */  addu      $at, $at, $v1
/* CC4664 80240E54 C422412C */  lwc1      $f2, 0x412c($at)
/* CC4668 80240E58 8443008E */  lh        $v1, 0x8e($v0)
/* CC466C 80240E5C 46020000 */  add.s     $f0, $f0, $f2
/* CC4670 80240E60 28630005 */  slti      $v1, $v1, 5
/* CC4674 80240E64 14600003 */  bnez      $v1, .L80240E74
/* CC4678 80240E68 E440003C */   swc1     $f0, 0x3c($v0)
/* CC467C 80240E6C 2402000C */  addiu     $v0, $zero, 0xc
/* CC4680 80240E70 AE020070 */  sw        $v0, 0x70($s0)
.L80240E74:
/* CC4684 80240E74 8FBF0014 */  lw        $ra, 0x14($sp)
/* CC4688 80240E78 8FB00010 */  lw        $s0, 0x10($sp)
/* CC468C 80240E7C 03E00008 */  jr        $ra
/* CC4690 80240E80 27BD0018 */   addiu    $sp, $sp, 0x18
