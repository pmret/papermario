.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B3C_A0C82C
/* A0C82C 80240B3C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* A0C830 80240B40 F7B40020 */  sdc1      $f20, 0x20($sp)
/* A0C834 80240B44 3C01439B */  lui       $at, 0x439b
/* A0C838 80240B48 4481A000 */  mtc1      $at, $f20
/* A0C83C 80240B4C AFB00010 */  sw        $s0, 0x10($sp)
/* A0C840 80240B50 0080802D */  daddu     $s0, $a0, $zero
/* A0C844 80240B54 AFBF001C */  sw        $ra, 0x1c($sp)
/* A0C848 80240B58 AFB20018 */  sw        $s2, 0x18($sp)
/* A0C84C 80240B5C AFB10014 */  sw        $s1, 0x14($sp)
/* A0C850 80240B60 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* A0C854 80240B64 F7B80030 */  sdc1      $f24, 0x30($sp)
/* A0C858 80240B68 F7B60028 */  sdc1      $f22, 0x28($sp)
/* A0C85C 80240B6C 8E110084 */  lw        $s1, 0x84($s0)
/* A0C860 80240B70 8E12008C */  lw        $s2, 0x8c($s0)
/* A0C864 80240B74 3C0142C8 */  lui       $at, 0x42c8
/* A0C868 80240B78 4481C000 */  mtc1      $at, $f24
/* A0C86C 80240B7C 0C00A8BB */  jal       sin_deg
/* A0C870 80240B80 4600A306 */   mov.s    $f12, $f20
/* A0C874 80240B84 46180002 */  mul.s     $f0, $f0, $f24
/* A0C878 80240B88 00000000 */  nop       
/* A0C87C 80240B8C 4491B000 */  mtc1      $s1, $f22
/* A0C880 80240B90 00000000 */  nop       
/* A0C884 80240B94 4680B5A0 */  cvt.s.w   $f22, $f22
/* A0C888 80240B98 4600B000 */  add.s     $f0, $f22, $f0
/* A0C88C 80240B9C 4600008D */  trunc.w.s $f2, $f0
/* A0C890 80240BA0 E6020084 */  swc1      $f2, 0x84($s0)
/* A0C894 80240BA4 0C00A8D4 */  jal       cos_deg
/* A0C898 80240BA8 4600A306 */   mov.s    $f12, $f20
/* A0C89C 80240BAC 46180002 */  mul.s     $f0, $f0, $f24
/* A0C8A0 80240BB0 00000000 */  nop       
/* A0C8A4 80240BB4 4492A000 */  mtc1      $s2, $f20
/* A0C8A8 80240BB8 00000000 */  nop       
/* A0C8AC 80240BBC 4680A520 */  cvt.s.w   $f20, $f20
/* A0C8B0 80240BC0 3C014302 */  lui       $at, 0x4302
/* A0C8B4 80240BC4 4481D000 */  mtc1      $at, $f26
/* A0C8B8 80240BC8 4600A001 */  sub.s     $f0, $f20, $f0
/* A0C8BC 80240BCC 4600008D */  trunc.w.s $f2, $f0
/* A0C8C0 80240BD0 E6020088 */  swc1      $f2, 0x88($s0)
/* A0C8C4 80240BD4 0C00A8BB */  jal       sin_deg
/* A0C8C8 80240BD8 4600D306 */   mov.s    $f12, $f26
/* A0C8CC 80240BDC 46180002 */  mul.s     $f0, $f0, $f24
/* A0C8D0 80240BE0 00000000 */  nop       
/* A0C8D4 80240BE4 4600B580 */  add.s     $f22, $f22, $f0
/* A0C8D8 80240BE8 4600B08D */  trunc.w.s $f2, $f22
/* A0C8DC 80240BEC E602008C */  swc1      $f2, 0x8c($s0)
/* A0C8E0 80240BF0 0C00A8D4 */  jal       cos_deg
/* A0C8E4 80240BF4 4600D306 */   mov.s    $f12, $f26
/* A0C8E8 80240BF8 46180002 */  mul.s     $f0, $f0, $f24
/* A0C8EC 80240BFC 00000000 */  nop       
/* A0C8F0 80240C00 4600A501 */  sub.s     $f20, $f20, $f0
/* A0C8F4 80240C04 4600A08D */  trunc.w.s $f2, $f20
/* A0C8F8 80240C08 E6020090 */  swc1      $f2, 0x90($s0)
/* A0C8FC 80240C0C 8FBF001C */  lw        $ra, 0x1c($sp)
/* A0C900 80240C10 8FB20018 */  lw        $s2, 0x18($sp)
/* A0C904 80240C14 8FB10014 */  lw        $s1, 0x14($sp)
/* A0C908 80240C18 8FB00010 */  lw        $s0, 0x10($sp)
/* A0C90C 80240C1C D7BA0038 */  ldc1      $f26, 0x38($sp)
/* A0C910 80240C20 D7B80030 */  ldc1      $f24, 0x30($sp)
/* A0C914 80240C24 D7B60028 */  ldc1      $f22, 0x28($sp)
/* A0C918 80240C28 D7B40020 */  ldc1      $f20, 0x20($sp)
/* A0C91C 80240C2C 24020002 */  addiu     $v0, $zero, 2
/* A0C920 80240C30 03E00008 */  jr        $ra
/* A0C924 80240C34 27BD0040 */   addiu    $sp, $sp, 0x40
/* A0C928 80240C38 00000000 */  nop       
/* A0C92C 80240C3C 00000000 */  nop       
