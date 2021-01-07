.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241AE4_BE5294
/* BE5294 80241AE4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BE5298 80241AE8 AFB00010 */  sw        $s0, 0x10($sp)
/* BE529C 80241AEC 0080802D */  daddu     $s0, $a0, $zero
/* BE52A0 80241AF0 AFBF0014 */  sw        $ra, 0x14($sp)
/* BE52A4 80241AF4 8E020148 */  lw        $v0, 0x148($s0)
/* BE52A8 80241AF8 0C00EABB */  jal       get_npc_unsafe
/* BE52AC 80241AFC 84440008 */   lh       $a0, 8($v0)
/* BE52B0 80241B00 9443008E */  lhu       $v1, 0x8e($v0)
/* BE52B4 80241B04 C440003C */  lwc1      $f0, 0x3c($v0)
/* BE52B8 80241B08 24640001 */  addiu     $a0, $v1, 1
/* BE52BC 80241B0C 00031C00 */  sll       $v1, $v1, 0x10
/* BE52C0 80241B10 00031B83 */  sra       $v1, $v1, 0xe
/* BE52C4 80241B14 A444008E */  sh        $a0, 0x8e($v0)
/* BE52C8 80241B18 3C018024 */  lui       $at, %hi(D_802436DC)
/* BE52CC 80241B1C 00230821 */  addu      $at, $at, $v1
/* BE52D0 80241B20 C42236DC */  lwc1      $f2, %lo(D_802436DC)($at)
/* BE52D4 80241B24 8443008E */  lh        $v1, 0x8e($v0)
/* BE52D8 80241B28 46020000 */  add.s     $f0, $f0, $f2
/* BE52DC 80241B2C 28630005 */  slti      $v1, $v1, 5
/* BE52E0 80241B30 14600003 */  bnez      $v1, .L80241B40
/* BE52E4 80241B34 E440003C */   swc1     $f0, 0x3c($v0)
/* BE52E8 80241B38 2402000C */  addiu     $v0, $zero, 0xc
/* BE52EC 80241B3C AE020070 */  sw        $v0, 0x70($s0)
.L80241B40:
/* BE52F0 80241B40 8FBF0014 */  lw        $ra, 0x14($sp)
/* BE52F4 80241B44 8FB00010 */  lw        $s0, 0x10($sp)
/* BE52F8 80241B48 03E00008 */  jr        $ra
/* BE52FC 80241B4C 27BD0018 */   addiu    $sp, $sp, 0x18
