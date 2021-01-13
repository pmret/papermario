.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240468_D7F1C8
/* D7F1C8 80240468 8C820084 */  lw        $v0, 0x84($a0)
/* D7F1CC 8024046C 2442005A */  addiu     $v0, $v0, 0x5a
/* D7F1D0 80240470 AC82009C */  sw        $v0, 0x9c($a0)
/* D7F1D4 80240474 8C820098 */  lw        $v0, 0x98($a0)
/* D7F1D8 80240478 8C83009C */  lw        $v1, 0x9c($a0)
/* D7F1DC 8024047C 2442005A */  addiu     $v0, $v0, 0x5a
/* D7F1E0 80240480 00621823 */  subu      $v1, $v1, $v0
/* D7F1E4 80240484 04620001 */  bltzl     $v1, .L8024048C
/* D7F1E8 80240488 00031823 */   negu     $v1, $v1
.L8024048C:
/* D7F1EC 8024048C AC8200A0 */  sw        $v0, 0xa0($a0)
/* D7F1F0 80240490 2402010E */  addiu     $v0, $zero, 0x10e
/* D7F1F4 80240494 1462000C */  bne       $v1, $v0, .L802404C8
/* D7F1F8 80240498 AC8300A4 */   sw       $v1, 0xa4($a0)
/* D7F1FC 8024049C 8C85009C */  lw        $a1, 0x9c($a0)
/* D7F200 802404A0 8C8300A0 */  lw        $v1, 0xa0($a0)
/* D7F204 802404A4 2402005A */  addiu     $v0, $zero, 0x5a
/* D7F208 802404A8 AC8200A4 */  sw        $v0, 0xa4($a0)
/* D7F20C 802404AC 0065102A */  slt       $v0, $v1, $a1
/* D7F210 802404B0 50400004 */  beql      $v0, $zero, .L802404C4
/* D7F214 802404B4 2462FE98 */   addiu    $v0, $v1, -0x168
/* D7F218 802404B8 24A2FE98 */  addiu     $v0, $a1, -0x168
/* D7F21C 802404BC 08090132 */  j         .L802404C8
/* D7F220 802404C0 AC82009C */   sw       $v0, 0x9c($a0)
.L802404C4:
/* D7F224 802404C4 AC8200A0 */  sw        $v0, 0xa0($a0)
.L802404C8:
/* D7F228 802404C8 3C03B60B */  lui       $v1, 0xb60b
/* D7F22C 802404CC 8C8200A4 */  lw        $v0, 0xa4($a0)
/* D7F230 802404D0 346360B7 */  ori       $v1, $v1, 0x60b7
/* D7F234 802404D4 00430018 */  mult      $v0, $v1
/* D7F238 802404D8 00003010 */  mfhi      $a2
/* D7F23C 802404DC 00C21821 */  addu      $v1, $a2, $v0
/* D7F240 802404E0 00031983 */  sra       $v1, $v1, 6
/* D7F244 802404E4 000217C3 */  sra       $v0, $v0, 0x1f
/* D7F248 802404E8 00621823 */  subu      $v1, $v1, $v0
/* D7F24C 802404EC 00031080 */  sll       $v0, $v1, 2
/* D7F250 802404F0 00431021 */  addu      $v0, $v0, $v1
/* D7F254 802404F4 00021080 */  sll       $v0, $v0, 2
/* D7F258 802404F8 AC8200A4 */  sw        $v0, 0xa4($a0)
/* D7F25C 802404FC 03E00008 */  jr        $ra
/* D7F260 80240500 24020002 */   addiu    $v0, $zero, 2
/* D7F264 80240504 00000000 */  nop
/* D7F268 80240508 00000000 */  nop
/* D7F26C 8024050C 00000000 */  nop
