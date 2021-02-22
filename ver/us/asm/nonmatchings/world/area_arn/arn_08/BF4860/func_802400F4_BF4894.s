.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F4_BF4894
/* BF4894 802400F4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BF4898 802400F8 AFB00018 */  sw        $s0, 0x18($sp)
/* BF489C 802400FC AFB1001C */  sw        $s1, 0x1c($sp)
/* BF48A0 80240100 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* BF48A4 80240104 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* BF48A8 80240108 AFBF0020 */  sw        $ra, 0x20($sp)
/* BF48AC 8024010C F7B40028 */  sdc1      $f20, 0x28($sp)
/* BF48B0 80240110 10A00002 */  beqz      $a1, .L8024011C
/* BF48B4 80240114 0080802D */   daddu    $s0, $a0, $zero
/* BF48B8 80240118 AE000070 */  sw        $zero, 0x70($s0)
.L8024011C:
/* BF48BC 8024011C C622002C */  lwc1      $f2, 0x2c($s1)
/* BF48C0 80240120 3C01C120 */  lui       $at, 0xc120
/* BF48C4 80240124 44810000 */  mtc1      $at, $f0
/* BF48C8 80240128 00000000 */  nop
/* BF48CC 8024012C 4602003C */  c.lt.s    $f0, $f2
/* BF48D0 80240130 00000000 */  nop
/* BF48D4 80240134 45010013 */  bc1t      .L80240184
/* BF48D8 80240138 0000102D */   daddu    $v0, $zero, $zero
/* BF48DC 8024013C 0C038D36 */  jal       func_800E34D8
/* BF48E0 80240140 00000000 */   nop
/* BF48E4 80240144 46000506 */  mov.s     $f20, $f0
/* BF48E8 80240148 4600A306 */  mov.s     $f12, $f20
/* BF48EC 8024014C 0C038D45 */  jal       func_800E3514
/* BF48F0 80240150 27A50010 */   addiu    $a1, $sp, 0x10
/* BF48F4 80240154 E620002C */  swc1      $f0, 0x2c($s1)
/* BF48F8 80240158 C6000070 */  lwc1      $f0, 0x70($s0)
/* BF48FC 8024015C 46800020 */  cvt.s.w   $f0, $f0
/* BF4900 80240160 4600A505 */  abs.s     $f20, $f20
/* BF4904 80240164 46140000 */  add.s     $f0, $f0, $f20
/* BF4908 80240168 4600010D */  trunc.w.s $f4, $f0
/* BF490C 8024016C 44032000 */  mfc1      $v1, $f4
/* BF4910 80240170 00000000 */  nop
/* BF4914 80240174 28620033 */  slti      $v0, $v1, 0x33
/* BF4918 80240178 38420001 */  xori      $v0, $v0, 1
/* BF491C 8024017C 00021040 */  sll       $v0, $v0, 1
/* BF4920 80240180 AE030070 */  sw        $v1, 0x70($s0)
.L80240184:
/* BF4924 80240184 8FBF0020 */  lw        $ra, 0x20($sp)
/* BF4928 80240188 8FB1001C */  lw        $s1, 0x1c($sp)
/* BF492C 8024018C 8FB00018 */  lw        $s0, 0x18($sp)
/* BF4930 80240190 D7B40028 */  ldc1      $f20, 0x28($sp)
/* BF4934 80240194 03E00008 */  jr        $ra
/* BF4938 80240198 27BD0030 */   addiu    $sp, $sp, 0x30
