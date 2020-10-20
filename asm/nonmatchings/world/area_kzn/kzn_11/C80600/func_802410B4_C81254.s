.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802410B4_C81254
/* C81254 802410B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C81258 802410B8 AFB00010 */  sw        $s0, 0x10($sp)
/* C8125C 802410BC 0080802D */  daddu     $s0, $a0, $zero
/* C81260 802410C0 AFBF0014 */  sw        $ra, 0x14($sp)
/* C81264 802410C4 8E020148 */  lw        $v0, 0x148($s0)
/* C81268 802410C8 0C00EABB */  jal       get_npc_unsafe
/* C8126C 802410CC 84440008 */   lh       $a0, 8($v0)
/* C81270 802410D0 9443008E */  lhu       $v1, 0x8e($v0)
/* C81274 802410D4 C440003C */  lwc1      $f0, 0x3c($v0)
/* C81278 802410D8 24640001 */  addiu     $a0, $v1, 1
/* C8127C 802410DC 00031C00 */  sll       $v1, $v1, 0x10
/* C81280 802410E0 00031B83 */  sra       $v1, $v1, 0xe
/* C81284 802410E4 A444008E */  sh        $a0, 0x8e($v0)
/* C81288 802410E8 3C018024 */  lui       $at, 0x8024
/* C8128C 802410EC 00230821 */  addu      $at, $at, $v1
/* C81290 802410F0 C42236D0 */  lwc1      $f2, 0x36d0($at)
/* C81294 802410F4 8443008E */  lh        $v1, 0x8e($v0)
/* C81298 802410F8 46020000 */  add.s     $f0, $f0, $f2
/* C8129C 802410FC 28630005 */  slti      $v1, $v1, 5
/* C812A0 80241100 14600003 */  bnez      $v1, .L80241110
/* C812A4 80241104 E440003C */   swc1     $f0, 0x3c($v0)
/* C812A8 80241108 2402000C */  addiu     $v0, $zero, 0xc
/* C812AC 8024110C AE020070 */  sw        $v0, 0x70($s0)
.L80241110:
/* C812B0 80241110 8FBF0014 */  lw        $ra, 0x14($sp)
/* C812B4 80241114 8FB00010 */  lw        $s0, 0x10($sp)
/* C812B8 80241118 03E00008 */  jr        $ra
/* C812BC 8024111C 27BD0018 */   addiu    $sp, $sp, 0x18
