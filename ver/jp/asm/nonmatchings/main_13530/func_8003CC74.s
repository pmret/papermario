.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003CC74
/* 18074 8003CC74 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 18078 8003CC78 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 1807C 8003CC7C 4486D000 */  mtc1      $a2, $f26
/* 18080 8003CC80 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 18084 8003CC84 46006606 */  mov.s     $f24, $f12
/* 18088 8003CC88 AFB20018 */  sw        $s2, 0x18($sp)
/* 1808C 8003CC8C 0000902D */  daddu     $s2, $zero, $zero
/* 18090 8003CC90 AFB10014 */  sw        $s1, 0x14($sp)
/* 18094 8003CC94 0240882D */  daddu     $s1, $s2, $zero
/* 18098 8003CC98 AFB40020 */  sw        $s4, 0x20($sp)
/* 1809C 8003CC9C 3C140400 */  lui       $s4, 0x400
/* 180A0 8003CCA0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 180A4 8003CCA4 3C138000 */  lui       $s3, 0x8000
/* 180A8 8003CCA8 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 180AC 8003CCAC 4487A000 */  mtc1      $a3, $f20
/* 180B0 8003CCB0 36730004 */  ori       $s3, $s3, 4
/* 180B4 8003CCB4 AFBF0024 */  sw        $ra, 0x24($sp)
/* 180B8 8003CCB8 AFB00010 */  sw        $s0, 0x10($sp)
/* 180BC 8003CCBC F7B60030 */  sdc1      $f22, 0x30($sp)
/* 180C0 8003CCC0 4600A586 */  mov.s     $f22, $f20
.L8003CCC4:
/* 180C4 8003CCC4 3C03800A */  lui       $v1, %hi(D_8009E9A0)
/* 180C8 8003CCC8 8C63E9A0 */  lw        $v1, %lo(D_8009E9A0)($v1)
/* 180CC 8003CCCC 00111080 */  sll       $v0, $s1, 2
/* 180D0 8003CCD0 00431021 */  addu      $v0, $v0, $v1
/* 180D4 8003CCD4 8C500000 */  lw        $s0, ($v0)
/* 180D8 8003CCD8 5200001B */  beql      $s0, $zero, .L8003CD48
/* 180DC 8003CCDC 26310001 */   addiu    $s1, $s1, 1
/* 180E0 8003CCE0 8E030000 */  lw        $v1, ($s0)
/* 180E4 8003CCE4 50600018 */  beql      $v1, $zero, .L8003CD48
/* 180E8 8003CCE8 26310001 */   addiu    $s1, $s1, 1
/* 180EC 8003CCEC 00741024 */  and       $v0, $v1, $s4
/* 180F0 8003CCF0 54400015 */  bnel      $v0, $zero, .L8003CD48
/* 180F4 8003CCF4 26310001 */   addiu    $s1, $s1, 1
/* 180F8 8003CCF8 00731024 */  and       $v0, $v1, $s3
/* 180FC 8003CCFC 54400012 */  bnel      $v0, $zero, .L8003CD48
/* 18100 8003CD00 26310001 */   addiu    $s1, $s1, 1
/* 18104 8003CD04 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 18108 8003CD08 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 1810C 8003CD0C 4406C000 */  mfc1      $a2, $f24
/* 18110 8003CD10 4407D000 */  mfc1      $a3, $f26
/* 18114 8003CD14 0C00A7A5 */  jal       func_80029E94
/* 18118 8003CD18 00000000 */   nop
/* 1811C 8003CD1C 46000005 */  abs.s     $f0, $f0
/* 18120 8003CD20 4616003E */  c.le.s    $f0, $f22
/* 18124 8003CD24 00000000 */  nop
/* 18128 8003CD28 45000007 */  bc1f      .L8003CD48
/* 1812C 8003CD2C 26310001 */   addiu    $s1, $s1, 1
/* 18130 8003CD30 4614003C */  c.lt.s    $f0, $f20
/* 18134 8003CD34 00000000 */  nop
/* 18138 8003CD38 45000003 */  bc1f      .L8003CD48
/* 1813C 8003CD3C 00000000 */   nop
/* 18140 8003CD40 46000506 */  mov.s     $f20, $f0
/* 18144 8003CD44 0200902D */  daddu     $s2, $s0, $zero
.L8003CD48:
/* 18148 8003CD48 2A220040 */  slti      $v0, $s1, 0x40
/* 1814C 8003CD4C 1440FFDD */  bnez      $v0, .L8003CCC4
/* 18150 8003CD50 0240102D */   daddu    $v0, $s2, $zero
/* 18154 8003CD54 8FBF0024 */  lw        $ra, 0x24($sp)
/* 18158 8003CD58 8FB40020 */  lw        $s4, 0x20($sp)
/* 1815C 8003CD5C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 18160 8003CD60 8FB20018 */  lw        $s2, 0x18($sp)
/* 18164 8003CD64 8FB10014 */  lw        $s1, 0x14($sp)
/* 18168 8003CD68 8FB00010 */  lw        $s0, 0x10($sp)
/* 1816C 8003CD6C D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 18170 8003CD70 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 18174 8003CD74 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 18178 8003CD78 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 1817C 8003CD7C 03E00008 */  jr        $ra
/* 18180 8003CD80 27BD0048 */   addiu    $sp, $sp, 0x48
