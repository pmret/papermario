.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411A4_D21034
/* D21034 802411A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D21038 802411A8 AFB00010 */  sw        $s0, 0x10($sp)
/* D2103C 802411AC 0080802D */  daddu     $s0, $a0, $zero
/* D21040 802411B0 AFBF0014 */  sw        $ra, 0x14($sp)
/* D21044 802411B4 8E020148 */  lw        $v0, 0x148($s0)
/* D21048 802411B8 0C00EABB */  jal       get_npc_unsafe
/* D2104C 802411BC 84440008 */   lh       $a0, 8($v0)
/* D21050 802411C0 9443008E */  lhu       $v1, 0x8e($v0)
/* D21054 802411C4 C440003C */  lwc1      $f0, 0x3c($v0)
/* D21058 802411C8 24640001 */  addiu     $a0, $v1, 1
/* D2105C 802411CC 00031C00 */  sll       $v1, $v1, 0x10
/* D21060 802411D0 00031B83 */  sra       $v1, $v1, 0xe
/* D21064 802411D4 A444008E */  sh        $a0, 0x8e($v0)
/* D21068 802411D8 3C018024 */  lui       $at, %hi(D_802441B8)
/* D2106C 802411DC 00230821 */  addu      $at, $at, $v1
/* D21070 802411E0 C42241B8 */  lwc1      $f2, %lo(D_802441B8)($at)
/* D21074 802411E4 8443008E */  lh        $v1, 0x8e($v0)
/* D21078 802411E8 46020000 */  add.s     $f0, $f0, $f2
/* D2107C 802411EC 28630005 */  slti      $v1, $v1, 5
/* D21080 802411F0 14600003 */  bnez      $v1, .L80241200
/* D21084 802411F4 E440003C */   swc1     $f0, 0x3c($v0)
/* D21088 802411F8 2402000C */  addiu     $v0, $zero, 0xc
/* D2108C 802411FC AE020070 */  sw        $v0, 0x70($s0)
.L80241200:
/* D21090 80241200 8FBF0014 */  lw        $ra, 0x14($sp)
/* D21094 80241204 8FB00010 */  lw        $s0, 0x10($sp)
/* D21098 80241208 03E00008 */  jr        $ra
/* D2109C 8024120C 27BD0018 */   addiu    $sp, $sp, 0x18
