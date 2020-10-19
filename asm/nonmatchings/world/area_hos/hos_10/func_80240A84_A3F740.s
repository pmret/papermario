.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A84_A401C4
/* A401C4 80240A84 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* A401C8 80240A88 AFB10014 */  sw        $s1, 0x14($sp)
/* A401CC 80240A8C 0080882D */  daddu     $s1, $a0, $zero
/* A401D0 80240A90 AFBF001C */  sw        $ra, 0x1c($sp)
/* A401D4 80240A94 AFB20018 */  sw        $s2, 0x18($sp)
/* A401D8 80240A98 AFB00010 */  sw        $s0, 0x10($sp)
/* A401DC 80240A9C F7B60028 */  sdc1      $f22, 0x28($sp)
/* A401E0 80240AA0 F7B40020 */  sdc1      $f20, 0x20($sp)
/* A401E4 80240AA4 8E30000C */  lw        $s0, 0xc($s1)
/* A401E8 80240AA8 8E050000 */  lw        $a1, ($s0)
/* A401EC 80240AAC 0C0B1EAF */  jal       get_variable
/* A401F0 80240AB0 26100004 */   addiu    $s0, $s0, 4
/* A401F4 80240AB4 8E050000 */  lw        $a1, ($s0)
/* A401F8 80240AB8 26100004 */  addiu     $s0, $s0, 4
/* A401FC 80240ABC 0220202D */  daddu     $a0, $s1, $zero
/* A40200 80240AC0 0C0B1EAF */  jal       get_variable
/* A40204 80240AC4 0040902D */   daddu    $s2, $v0, $zero
/* A40208 80240AC8 8E050000 */  lw        $a1, ($s0)
/* A4020C 80240ACC 26100004 */  addiu     $s0, $s0, 4
/* A40210 80240AD0 4482B000 */  mtc1      $v0, $f22
/* A40214 80240AD4 00000000 */  nop       
/* A40218 80240AD8 4680B5A0 */  cvt.s.w   $f22, $f22
/* A4021C 80240ADC 0C0B1EAF */  jal       get_variable
/* A40220 80240AE0 0220202D */   daddu    $a0, $s1, $zero
/* A40224 80240AE4 8E050000 */  lw        $a1, ($s0)
/* A40228 80240AE8 4482A000 */  mtc1      $v0, $f20
/* A4022C 80240AEC 00000000 */  nop       
/* A40230 80240AF0 4680A520 */  cvt.s.w   $f20, $f20
/* A40234 80240AF4 0C0B1EAF */  jal       get_variable
/* A40238 80240AF8 0220202D */   daddu    $a0, $s1, $zero
/* A4023C 80240AFC 8E43000C */  lw        $v1, 0xc($s2)
/* A40240 80240B00 E4760004 */  swc1      $f22, 4($v1)
/* A40244 80240B04 8E43000C */  lw        $v1, 0xc($s2)
/* A40248 80240B08 E4740008 */  swc1      $f20, 8($v1)
/* A4024C 80240B0C 8E43000C */  lw        $v1, 0xc($s2)
/* A40250 80240B10 44820000 */  mtc1      $v0, $f0
/* A40254 80240B14 00000000 */  nop       
/* A40258 80240B18 46800020 */  cvt.s.w   $f0, $f0
/* A4025C 80240B1C E460000C */  swc1      $f0, 0xc($v1)
/* A40260 80240B20 8FBF001C */  lw        $ra, 0x1c($sp)
/* A40264 80240B24 8FB20018 */  lw        $s2, 0x18($sp)
/* A40268 80240B28 8FB10014 */  lw        $s1, 0x14($sp)
/* A4026C 80240B2C 8FB00010 */  lw        $s0, 0x10($sp)
/* A40270 80240B30 D7B60028 */  ldc1      $f22, 0x28($sp)
/* A40274 80240B34 D7B40020 */  ldc1      $f20, 0x20($sp)
/* A40278 80240B38 24020002 */  addiu     $v0, $zero, 2
/* A4027C 80240B3C 03E00008 */  jr        $ra
/* A40280 80240B40 27BD0030 */   addiu    $sp, $sp, 0x30
