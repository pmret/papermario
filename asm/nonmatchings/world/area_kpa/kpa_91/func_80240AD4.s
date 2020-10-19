.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AD4
/* A87524 80240AD4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A87528 80240AD8 AFB10014 */  sw        $s1, 0x14($sp)
/* A8752C 80240ADC 0080882D */  daddu     $s1, $a0, $zero
/* A87530 80240AE0 AFBF001C */  sw        $ra, 0x1c($sp)
/* A87534 80240AE4 AFB20018 */  sw        $s2, 0x18($sp)
/* A87538 80240AE8 AFB00010 */  sw        $s0, 0x10($sp)
/* A8753C 80240AEC 8E300148 */  lw        $s0, 0x148($s1)
/* A87540 80240AF0 86040008 */  lh        $a0, 8($s0)
/* A87544 80240AF4 0C00EABB */  jal       get_npc_unsafe
/* A87548 80240AF8 00A0902D */   daddu    $s2, $a1, $zero
/* A8754C 80240AFC 8E0300D0 */  lw        $v1, 0xd0($s0)
/* A87550 80240B00 8E240078 */  lw        $a0, 0x78($s1)
/* A87554 80240B04 8C630000 */  lw        $v1, ($v1)
/* A87558 80240B08 0083182A */  slt       $v1, $a0, $v1
/* A8755C 80240B0C 10600013 */  beqz      $v1, .L80240B5C
/* A87560 80240B10 0040302D */   daddu    $a2, $v0, $zero
/* A87564 80240B14 00041040 */  sll       $v0, $a0, 1
/* A87568 80240B18 00441021 */  addu      $v0, $v0, $a0
/* A8756C 80240B1C 00022880 */  sll       $a1, $v0, 2
.L80240B20:
/* A87570 80240B20 8E0300D0 */  lw        $v1, 0xd0($s0)
/* A87574 80240B24 C4C2003C */  lwc1      $f2, 0x3c($a2)
/* A87578 80240B28 00A31021 */  addu      $v0, $a1, $v1
/* A8757C 80240B2C C4400008 */  lwc1      $f0, 8($v0)
/* A87580 80240B30 46800020 */  cvt.s.w   $f0, $f0
/* A87584 80240B34 4602003E */  c.le.s    $f0, $f2
/* A87588 80240B38 00000000 */  nop       
/* A8758C 80240B3C 45020003 */  bc1fl     .L80240B4C
/* A87590 80240B40 24840001 */   addiu    $a0, $a0, 1
/* A87594 80240B44 080902D7 */  j         .L80240B5C
/* A87598 80240B48 AE240078 */   sw       $a0, 0x78($s1)
.L80240B4C:
/* A8759C 80240B4C 8C620000 */  lw        $v0, ($v1)
/* A875A0 80240B50 0082102A */  slt       $v0, $a0, $v0
/* A875A4 80240B54 1440FFF2 */  bnez      $v0, .L80240B20
/* A875A8 80240B58 24A5000C */   addiu    $a1, $a1, 0xc
.L80240B5C:
/* A875AC 80240B5C C6400000 */  lwc1      $f0, ($s2)
/* A875B0 80240B60 E4C00018 */  swc1      $f0, 0x18($a2)
/* A875B4 80240B64 8E0200CC */  lw        $v0, 0xcc($s0)
/* A875B8 80240B68 8C420004 */  lw        $v0, 4($v0)
/* A875BC 80240B6C ACC20028 */  sw        $v0, 0x28($a2)
/* A875C0 80240B70 24020001 */  addiu     $v0, $zero, 1
/* A875C4 80240B74 AE200074 */  sw        $zero, 0x74($s1)
/* A875C8 80240B78 AE220070 */  sw        $v0, 0x70($s1)
/* A875CC 80240B7C 8FBF001C */  lw        $ra, 0x1c($sp)
/* A875D0 80240B80 8FB20018 */  lw        $s2, 0x18($sp)
/* A875D4 80240B84 8FB10014 */  lw        $s1, 0x14($sp)
/* A875D8 80240B88 8FB00010 */  lw        $s0, 0x10($sp)
/* A875DC 80240B8C 03E00008 */  jr        $ra
/* A875E0 80240B90 27BD0020 */   addiu    $sp, $sp, 0x20
