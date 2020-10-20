.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B84
/* ABBE14 80240B84 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* ABBE18 80240B88 AFB10014 */  sw        $s1, 0x14($sp)
/* ABBE1C 80240B8C 0080882D */  daddu     $s1, $a0, $zero
/* ABBE20 80240B90 AFBF001C */  sw        $ra, 0x1c($sp)
/* ABBE24 80240B94 AFB20018 */  sw        $s2, 0x18($sp)
/* ABBE28 80240B98 AFB00010 */  sw        $s0, 0x10($sp)
/* ABBE2C 80240B9C 8E300148 */  lw        $s0, 0x148($s1)
/* ABBE30 80240BA0 86040008 */  lh        $a0, 8($s0)
/* ABBE34 80240BA4 0C00EABB */  jal       get_npc_unsafe
/* ABBE38 80240BA8 00A0902D */   daddu    $s2, $a1, $zero
/* ABBE3C 80240BAC 8E0300D0 */  lw        $v1, 0xd0($s0)
/* ABBE40 80240BB0 8E240078 */  lw        $a0, 0x78($s1)
/* ABBE44 80240BB4 8C630000 */  lw        $v1, ($v1)
/* ABBE48 80240BB8 0083182A */  slt       $v1, $a0, $v1
/* ABBE4C 80240BBC 10600013 */  beqz      $v1, .L80240C0C
/* ABBE50 80240BC0 0040302D */   daddu    $a2, $v0, $zero
/* ABBE54 80240BC4 00041040 */  sll       $v0, $a0, 1
/* ABBE58 80240BC8 00441021 */  addu      $v0, $v0, $a0
/* ABBE5C 80240BCC 00022880 */  sll       $a1, $v0, 2
.L80240BD0:
/* ABBE60 80240BD0 8E0300D0 */  lw        $v1, 0xd0($s0)
/* ABBE64 80240BD4 C4C2003C */  lwc1      $f2, 0x3c($a2)
/* ABBE68 80240BD8 00A31021 */  addu      $v0, $a1, $v1
/* ABBE6C 80240BDC C4400008 */  lwc1      $f0, 8($v0)
/* ABBE70 80240BE0 46800020 */  cvt.s.w   $f0, $f0
/* ABBE74 80240BE4 4602003E */  c.le.s    $f0, $f2
/* ABBE78 80240BE8 00000000 */  nop       
/* ABBE7C 80240BEC 45020003 */  bc1fl     .L80240BFC
/* ABBE80 80240BF0 24840001 */   addiu    $a0, $a0, 1
/* ABBE84 80240BF4 08090303 */  j         .L80240C0C
/* ABBE88 80240BF8 AE240078 */   sw       $a0, 0x78($s1)
.L80240BFC:
/* ABBE8C 80240BFC 8C620000 */  lw        $v0, ($v1)
/* ABBE90 80240C00 0082102A */  slt       $v0, $a0, $v0
/* ABBE94 80240C04 1440FFF2 */  bnez      $v0, .L80240BD0
/* ABBE98 80240C08 24A5000C */   addiu    $a1, $a1, 0xc
.L80240C0C:
/* ABBE9C 80240C0C C6400000 */  lwc1      $f0, ($s2)
/* ABBEA0 80240C10 E4C00018 */  swc1      $f0, 0x18($a2)
/* ABBEA4 80240C14 8E0200CC */  lw        $v0, 0xcc($s0)
/* ABBEA8 80240C18 8C420004 */  lw        $v0, 4($v0)
/* ABBEAC 80240C1C ACC20028 */  sw        $v0, 0x28($a2)
/* ABBEB0 80240C20 24020001 */  addiu     $v0, $zero, 1
/* ABBEB4 80240C24 AE200074 */  sw        $zero, 0x74($s1)
/* ABBEB8 80240C28 AE220070 */  sw        $v0, 0x70($s1)
/* ABBEBC 80240C2C 8FBF001C */  lw        $ra, 0x1c($sp)
/* ABBEC0 80240C30 8FB20018 */  lw        $s2, 0x18($sp)
/* ABBEC4 80240C34 8FB10014 */  lw        $s1, 0x14($sp)
/* ABBEC8 80240C38 8FB00010 */  lw        $s0, 0x10($sp)
/* ABBECC 80240C3C 03E00008 */  jr        $ra
/* ABBED0 80240C40 27BD0020 */   addiu    $sp, $sp, 0x20
