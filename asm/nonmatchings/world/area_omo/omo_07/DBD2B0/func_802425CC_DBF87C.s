.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802425CC_DBF87C
/* DBF87C 802425CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DBF880 802425D0 AFB00010 */  sw        $s0, 0x10($sp)
/* DBF884 802425D4 0080802D */  daddu     $s0, $a0, $zero
/* DBF888 802425D8 AFBF0014 */  sw        $ra, 0x14($sp)
/* DBF88C 802425DC 8E020148 */  lw        $v0, 0x148($s0)
/* DBF890 802425E0 0C00EABB */  jal       get_npc_unsafe
/* DBF894 802425E4 84440008 */   lh       $a0, 8($v0)
/* DBF898 802425E8 9443008E */  lhu       $v1, 0x8e($v0)
/* DBF89C 802425EC C440003C */  lwc1      $f0, 0x3c($v0)
/* DBF8A0 802425F0 24640001 */  addiu     $a0, $v1, 1
/* DBF8A4 802425F4 00031C00 */  sll       $v1, $v1, 0x10
/* DBF8A8 802425F8 00031B83 */  sra       $v1, $v1, 0xe
/* DBF8AC 802425FC A444008E */  sh        $a0, 0x8e($v0)
/* DBF8B0 80242600 3C018024 */  lui       $at, 0x8024
/* DBF8B4 80242604 00230821 */  addu      $at, $at, $v1
/* DBF8B8 80242608 C4223A14 */  lwc1      $f2, 0x3a14($at)
/* DBF8BC 8024260C 8443008E */  lh        $v1, 0x8e($v0)
/* DBF8C0 80242610 46020000 */  add.s     $f0, $f0, $f2
/* DBF8C4 80242614 28630005 */  slti      $v1, $v1, 5
/* DBF8C8 80242618 14600003 */  bnez      $v1, .L80242628
/* DBF8CC 8024261C E440003C */   swc1     $f0, 0x3c($v0)
/* DBF8D0 80242620 2402000C */  addiu     $v0, $zero, 0xc
/* DBF8D4 80242624 AE020070 */  sw        $v0, 0x70($s0)
.L80242628:
/* DBF8D8 80242628 8FBF0014 */  lw        $ra, 0x14($sp)
/* DBF8DC 8024262C 8FB00010 */  lw        $s0, 0x10($sp)
/* DBF8E0 80242630 03E00008 */  jr        $ra
/* DBF8E4 80242634 27BD0018 */   addiu    $sp, $sp, 0x18
