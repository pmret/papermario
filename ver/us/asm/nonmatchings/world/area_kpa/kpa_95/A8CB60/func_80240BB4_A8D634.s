.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kpa_95_UnkFunc16
/* A8D634 80240BB4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A8D638 80240BB8 AFB10014 */  sw        $s1, 0x14($sp)
/* A8D63C 80240BBC 0080882D */  daddu     $s1, $a0, $zero
/* A8D640 80240BC0 AFBF001C */  sw        $ra, 0x1c($sp)
/* A8D644 80240BC4 AFB20018 */  sw        $s2, 0x18($sp)
/* A8D648 80240BC8 AFB00010 */  sw        $s0, 0x10($sp)
/* A8D64C 80240BCC 8E300148 */  lw        $s0, 0x148($s1)
/* A8D650 80240BD0 86040008 */  lh        $a0, 8($s0)
/* A8D654 80240BD4 0C00EABB */  jal       get_npc_unsafe
/* A8D658 80240BD8 00A0902D */   daddu    $s2, $a1, $zero
/* A8D65C 80240BDC 8E0300D0 */  lw        $v1, 0xd0($s0)
/* A8D660 80240BE0 8E240078 */  lw        $a0, 0x78($s1)
/* A8D664 80240BE4 8C630000 */  lw        $v1, ($v1)
/* A8D668 80240BE8 0083182A */  slt       $v1, $a0, $v1
/* A8D66C 80240BEC 10600013 */  beqz      $v1, .L80240C3C
/* A8D670 80240BF0 0040302D */   daddu    $a2, $v0, $zero
/* A8D674 80240BF4 00041040 */  sll       $v0, $a0, 1
/* A8D678 80240BF8 00441021 */  addu      $v0, $v0, $a0
/* A8D67C 80240BFC 00022880 */  sll       $a1, $v0, 2
.L80240C00:
/* A8D680 80240C00 8E0300D0 */  lw        $v1, 0xd0($s0)
/* A8D684 80240C04 C4C2003C */  lwc1      $f2, 0x3c($a2)
/* A8D688 80240C08 00A31021 */  addu      $v0, $a1, $v1
/* A8D68C 80240C0C C4400008 */  lwc1      $f0, 8($v0)
/* A8D690 80240C10 46800020 */  cvt.s.w   $f0, $f0
/* A8D694 80240C14 4602003E */  c.le.s    $f0, $f2
/* A8D698 80240C18 00000000 */  nop
/* A8D69C 80240C1C 45020003 */  bc1fl     .L80240C2C
/* A8D6A0 80240C20 24840001 */   addiu    $a0, $a0, 1
/* A8D6A4 80240C24 0809030F */  j         .L80240C3C
/* A8D6A8 80240C28 AE240078 */   sw       $a0, 0x78($s1)
.L80240C2C:
/* A8D6AC 80240C2C 8C620000 */  lw        $v0, ($v1)
/* A8D6B0 80240C30 0082102A */  slt       $v0, $a0, $v0
/* A8D6B4 80240C34 1440FFF2 */  bnez      $v0, .L80240C00
/* A8D6B8 80240C38 24A5000C */   addiu    $a1, $a1, 0xc
.L80240C3C:
/* A8D6BC 80240C3C C6400000 */  lwc1      $f0, ($s2)
/* A8D6C0 80240C40 E4C00018 */  swc1      $f0, 0x18($a2)
/* A8D6C4 80240C44 8E0200CC */  lw        $v0, 0xcc($s0)
/* A8D6C8 80240C48 8C420004 */  lw        $v0, 4($v0)
/* A8D6CC 80240C4C ACC20028 */  sw        $v0, 0x28($a2)
/* A8D6D0 80240C50 24020001 */  addiu     $v0, $zero, 1
/* A8D6D4 80240C54 AE200074 */  sw        $zero, 0x74($s1)
/* A8D6D8 80240C58 AE220070 */  sw        $v0, 0x70($s1)
/* A8D6DC 80240C5C 8FBF001C */  lw        $ra, 0x1c($sp)
/* A8D6E0 80240C60 8FB20018 */  lw        $s2, 0x18($sp)
/* A8D6E4 80240C64 8FB10014 */  lw        $s1, 0x14($sp)
/* A8D6E8 80240C68 8FB00010 */  lw        $s0, 0x10($sp)
/* A8D6EC 80240C6C 03E00008 */  jr        $ra
/* A8D6F0 80240C70 27BD0020 */   addiu    $sp, $sp, 0x20
