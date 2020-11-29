.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416A4_C72B24
/* C72B24 802416A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C72B28 802416A8 AFB00010 */  sw        $s0, 0x10($sp)
/* C72B2C 802416AC 0080802D */  daddu     $s0, $a0, $zero
/* C72B30 802416B0 AFBF0014 */  sw        $ra, 0x14($sp)
/* C72B34 802416B4 8E020148 */  lw        $v0, 0x148($s0)
/* C72B38 802416B8 0C00EABB */  jal       get_npc_unsafe
/* C72B3C 802416BC 84440008 */   lh       $a0, 8($v0)
/* C72B40 802416C0 9443008E */  lhu       $v1, 0x8e($v0)
/* C72B44 802416C4 C440003C */  lwc1      $f0, 0x3c($v0)
/* C72B48 802416C8 24640001 */  addiu     $a0, $v1, 1
/* C72B4C 802416CC 00031C00 */  sll       $v1, $v1, 0x10
/* C72B50 802416D0 00031B83 */  sra       $v1, $v1, 0xe
/* C72B54 802416D4 A444008E */  sh        $a0, 0x8e($v0)
/* C72B58 802416D8 3C018024 */  lui       $at, %hi(D_80244DA0)
/* C72B5C 802416DC 00230821 */  addu      $at, $at, $v1
/* C72B60 802416E0 C4224DA0 */  lwc1      $f2, %lo(D_80244DA0)($at)
/* C72B64 802416E4 8443008E */  lh        $v1, 0x8e($v0)
/* C72B68 802416E8 46020000 */  add.s     $f0, $f0, $f2
/* C72B6C 802416EC 28630005 */  slti      $v1, $v1, 5
/* C72B70 802416F0 14600003 */  bnez      $v1, .L80241700
/* C72B74 802416F4 E440003C */   swc1     $f0, 0x3c($v0)
/* C72B78 802416F8 2402000C */  addiu     $v0, $zero, 0xc
/* C72B7C 802416FC AE020070 */  sw        $v0, 0x70($s0)
.L80241700:
/* C72B80 80241700 8FBF0014 */  lw        $ra, 0x14($sp)
/* C72B84 80241704 8FB00010 */  lw        $s0, 0x10($sp)
/* C72B88 80241708 03E00008 */  jr        $ra
/* C72B8C 8024170C 27BD0018 */   addiu    $sp, $sp, 0x18
