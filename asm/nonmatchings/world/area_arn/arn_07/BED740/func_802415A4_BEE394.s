.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415A4_BEE394
/* BEE394 802415A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BEE398 802415A8 AFB00010 */  sw        $s0, 0x10($sp)
/* BEE39C 802415AC 0080802D */  daddu     $s0, $a0, $zero
/* BEE3A0 802415B0 AFBF0014 */  sw        $ra, 0x14($sp)
/* BEE3A4 802415B4 8E020148 */  lw        $v0, 0x148($s0)
/* BEE3A8 802415B8 0C00EABB */  jal       get_npc_unsafe
/* BEE3AC 802415BC 84440008 */   lh       $a0, 8($v0)
/* BEE3B0 802415C0 9443008E */  lhu       $v1, 0x8e($v0)
/* BEE3B4 802415C4 C440003C */  lwc1      $f0, 0x3c($v0)
/* BEE3B8 802415C8 24640001 */  addiu     $a0, $v1, 1
/* BEE3BC 802415CC 00031C00 */  sll       $v1, $v1, 0x10
/* BEE3C0 802415D0 00031B83 */  sra       $v1, $v1, 0xe
/* BEE3C4 802415D4 A444008E */  sh        $a0, 0x8e($v0)
/* BEE3C8 802415D8 3C018024 */  lui       $at, %hi(D_80243BC0)
/* BEE3CC 802415DC 00230821 */  addu      $at, $at, $v1
/* BEE3D0 802415E0 C4223BC0 */  lwc1      $f2, %lo(D_80243BC0)($at)
/* BEE3D4 802415E4 8443008E */  lh        $v1, 0x8e($v0)
/* BEE3D8 802415E8 46020000 */  add.s     $f0, $f0, $f2
/* BEE3DC 802415EC 28630005 */  slti      $v1, $v1, 5
/* BEE3E0 802415F0 14600003 */  bnez      $v1, .L80241600
/* BEE3E4 802415F4 E440003C */   swc1     $f0, 0x3c($v0)
/* BEE3E8 802415F8 2402000C */  addiu     $v0, $zero, 0xc
/* BEE3EC 802415FC AE020070 */  sw        $v0, 0x70($s0)
.L80241600:
/* BEE3F0 80241600 8FBF0014 */  lw        $ra, 0x14($sp)
/* BEE3F4 80241604 8FB00010 */  lw        $s0, 0x10($sp)
/* BEE3F8 80241608 03E00008 */  jr        $ra
/* BEE3FC 8024160C 27BD0018 */   addiu    $sp, $sp, 0x18
