.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1848_71EE98
/* 71EE98 802A1848 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 71EE9C 802A184C AFB3001C */  sw        $s3, 0x1c($sp)
/* 71EEA0 802A1850 3C13800E */  lui       $s3, %hi(gBattleStatus+0xD8)
/* 71EEA4 802A1854 8E73C148 */  lw        $s3, %lo(gBattleStatus+0xD8)($s3)
/* 71EEA8 802A1858 AFBF0024 */  sw        $ra, 0x24($sp)
/* 71EEAC 802A185C AFB40020 */  sw        $s4, 0x20($sp)
/* 71EEB0 802A1860 AFB20018 */  sw        $s2, 0x18($sp)
/* 71EEB4 802A1864 AFB10014 */  sw        $s1, 0x14($sp)
/* 71EEB8 802A1868 AFB00010 */  sw        $s0, 0x10($sp)
/* 71EEBC 802A186C F7B60030 */  sdc1      $f22, 0x30($sp)
/* 71EEC0 802A1870 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 71EEC4 802A1874 54A00001 */  bnel      $a1, $zero, .L802A187C
/* 71EEC8 802A1878 AC800070 */   sw       $zero, 0x70($a0)
.L802A187C:
/* 71EECC 802A187C 0000902D */  daddu     $s2, $zero, $zero
/* 71EED0 802A1880 8262040C */  lb        $v0, 0x40c($s3)
/* 71EED4 802A1884 1840002C */  blez      $v0, .L802A1938
/* 71EED8 802A1888 0240A02D */   daddu    $s4, $s2, $zero
/* 71EEDC 802A188C 3C0143B4 */  lui       $at, 0x43b4
/* 71EEE0 802A1890 4481A000 */  mtc1      $at, $f20
/* 71EEE4 802A1894 3C014204 */  lui       $at, 0x4204
/* 71EEE8 802A1898 4481B000 */  mtc1      $at, $f22
/* 71EEEC 802A189C 02721021 */  addu      $v0, $s3, $s2
.L802A18A0:
/* 71EEF0 802A18A0 8043040D */  lb        $v1, 0x40d($v0)
/* 71EEF4 802A18A4 00031080 */  sll       $v0, $v1, 2
/* 71EEF8 802A18A8 00431021 */  addu      $v0, $v0, $v1
/* 71EEFC 802A18AC 00021080 */  sll       $v0, $v0, 2
/* 71EF00 802A18B0 2442022C */  addiu     $v0, $v0, 0x22c
/* 71EF04 802A18B4 02628821 */  addu      $s1, $s3, $v0
/* 71EF08 802A18B8 0C09A75B */  jal       get_actor
/* 71EF0C 802A18BC 86240000 */   lh       $a0, ($s1)
/* 71EF10 802A18C0 0040802D */  daddu     $s0, $v0, $zero
/* 71EF14 802A18C4 12000017 */  beqz      $s0, .L802A1924
/* 71EF18 802A18C8 00000000 */   nop
/* 71EF1C 802A18CC 86250002 */  lh        $a1, 2($s1)
/* 71EF20 802A18D0 0C099117 */  jal       get_actor_part
/* 71EF24 802A18D4 0200202D */   daddu    $a0, $s0, $zero
/* 71EF28 802A18D8 82030218 */  lb        $v1, 0x218($s0)
/* 71EF2C 802A18DC 14600011 */  bnez      $v1, .L802A1924
/* 71EF30 802A18E0 00000000 */   nop
/* 71EF34 802A18E4 8C42007C */  lw        $v0, 0x7c($v0)
/* 71EF38 802A18E8 30420020 */  andi      $v0, $v0, 0x20
/* 71EF3C 802A18EC 1440000D */  bnez      $v0, .L802A1924
/* 71EF40 802A18F0 00000000 */   nop
/* 71EF44 802A18F4 C600018C */  lwc1      $f0, 0x18c($s0)
/* 71EF48 802A18F8 4614003C */  c.lt.s    $f0, $f20
/* 71EF4C 802A18FC 00000000 */  nop
/* 71EF50 802A1900 45000008 */  bc1f      .L802A1924
/* 71EF54 802A1904 00000000 */   nop
/* 71EF58 802A1908 46160000 */  add.s     $f0, $f0, $f22
/* 71EF5C 802A190C 4600A03E */  c.le.s    $f20, $f0
/* 71EF60 802A1910 00000000 */  nop
/* 71EF64 802A1914 45000002 */  bc1f      .L802A1920
/* 71EF68 802A1918 E600018C */   swc1     $f0, 0x18c($s0)
/* 71EF6C 802A191C E614018C */  swc1      $f20, 0x18c($s0)
.L802A1920:
/* 71EF70 802A1920 24140001 */  addiu     $s4, $zero, 1
.L802A1924:
/* 71EF74 802A1924 8262040C */  lb        $v0, 0x40c($s3)
/* 71EF78 802A1928 26520001 */  addiu     $s2, $s2, 1
/* 71EF7C 802A192C 0242102A */  slt       $v0, $s2, $v0
/* 71EF80 802A1930 1440FFDB */  bnez      $v0, .L802A18A0
/* 71EF84 802A1934 02721021 */   addu     $v0, $s3, $s2
.L802A1938:
/* 71EF88 802A1938 2E820001 */  sltiu     $v0, $s4, 1
/* 71EF8C 802A193C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 71EF90 802A1940 8FB40020 */  lw        $s4, 0x20($sp)
/* 71EF94 802A1944 8FB3001C */  lw        $s3, 0x1c($sp)
/* 71EF98 802A1948 8FB20018 */  lw        $s2, 0x18($sp)
/* 71EF9C 802A194C 8FB10014 */  lw        $s1, 0x14($sp)
/* 71EFA0 802A1950 8FB00010 */  lw        $s0, 0x10($sp)
/* 71EFA4 802A1954 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 71EFA8 802A1958 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 71EFAC 802A195C 00021040 */  sll       $v0, $v0, 1
/* 71EFB0 802A1960 03E00008 */  jr        $ra
/* 71EFB4 802A1964 27BD0038 */   addiu    $sp, $sp, 0x38
/* 71EFB8 802A1968 00000000 */  nop
/* 71EFBC 802A196C 00000000 */  nop
