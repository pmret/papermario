.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419F4_D8EC44
/* D8EC44 802419F4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D8EC48 802419F8 AFB10014 */  sw        $s1, 0x14($sp)
/* D8EC4C 802419FC 0080882D */  daddu     $s1, $a0, $zero
/* D8EC50 80241A00 AFBF001C */  sw        $ra, 0x1c($sp)
/* D8EC54 80241A04 AFB20018 */  sw        $s2, 0x18($sp)
/* D8EC58 80241A08 AFB00010 */  sw        $s0, 0x10($sp)
/* D8EC5C 80241A0C 8E300148 */  lw        $s0, 0x148($s1)
/* D8EC60 80241A10 86040008 */  lh        $a0, 8($s0)
/* D8EC64 80241A14 0C00EABB */  jal       get_npc_unsafe
/* D8EC68 80241A18 00A0902D */   daddu    $s2, $a1, $zero
/* D8EC6C 80241A1C 8E0300D0 */  lw        $v1, 0xd0($s0)
/* D8EC70 80241A20 8E240078 */  lw        $a0, 0x78($s1)
/* D8EC74 80241A24 8C630000 */  lw        $v1, ($v1)
/* D8EC78 80241A28 0083182A */  slt       $v1, $a0, $v1
/* D8EC7C 80241A2C 10600013 */  beqz      $v1, .L80241A7C
/* D8EC80 80241A30 0040302D */   daddu    $a2, $v0, $zero
/* D8EC84 80241A34 00041040 */  sll       $v0, $a0, 1
/* D8EC88 80241A38 00441021 */  addu      $v0, $v0, $a0
/* D8EC8C 80241A3C 00022880 */  sll       $a1, $v0, 2
.L80241A40:
/* D8EC90 80241A40 8E0300D0 */  lw        $v1, 0xd0($s0)
/* D8EC94 80241A44 C4C2003C */  lwc1      $f2, 0x3c($a2)
/* D8EC98 80241A48 00A31021 */  addu      $v0, $a1, $v1
/* D8EC9C 80241A4C C4400008 */  lwc1      $f0, 8($v0)
/* D8ECA0 80241A50 46800020 */  cvt.s.w   $f0, $f0
/* D8ECA4 80241A54 4602003E */  c.le.s    $f0, $f2
/* D8ECA8 80241A58 00000000 */  nop       
/* D8ECAC 80241A5C 45020003 */  bc1fl     .L80241A6C
/* D8ECB0 80241A60 24840001 */   addiu    $a0, $a0, 1
/* D8ECB4 80241A64 0809069F */  j         .L80241A7C
/* D8ECB8 80241A68 AE240078 */   sw       $a0, 0x78($s1)
.L80241A6C:
/* D8ECBC 80241A6C 8C620000 */  lw        $v0, ($v1)
/* D8ECC0 80241A70 0082102A */  slt       $v0, $a0, $v0
/* D8ECC4 80241A74 1440FFF2 */  bnez      $v0, .L80241A40
/* D8ECC8 80241A78 24A5000C */   addiu    $a1, $a1, 0xc
.L80241A7C:
/* D8ECCC 80241A7C C6400000 */  lwc1      $f0, ($s2)
/* D8ECD0 80241A80 E4C00018 */  swc1      $f0, 0x18($a2)
/* D8ECD4 80241A84 8E0200CC */  lw        $v0, 0xcc($s0)
/* D8ECD8 80241A88 8C420004 */  lw        $v0, 4($v0)
/* D8ECDC 80241A8C ACC20028 */  sw        $v0, 0x28($a2)
/* D8ECE0 80241A90 24020001 */  addiu     $v0, $zero, 1
/* D8ECE4 80241A94 AE200074 */  sw        $zero, 0x74($s1)
/* D8ECE8 80241A98 AE220070 */  sw        $v0, 0x70($s1)
/* D8ECEC 80241A9C 8FBF001C */  lw        $ra, 0x1c($sp)
/* D8ECF0 80241AA0 8FB20018 */  lw        $s2, 0x18($sp)
/* D8ECF4 80241AA4 8FB10014 */  lw        $s1, 0x14($sp)
/* D8ECF8 80241AA8 8FB00010 */  lw        $s0, 0x10($sp)
/* D8ECFC 80241AAC 03E00008 */  jr        $ra
/* D8ED00 80241AB0 27BD0020 */   addiu    $sp, $sp, 0x20
