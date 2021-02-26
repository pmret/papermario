.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80039A64
/* 14E64 80039A64 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 14E68 80039A68 AFB10014 */  sw        $s1, 0x14($sp)
/* 14E6C 80039A6C 0080882D */  daddu     $s1, $a0, $zero
/* 14E70 80039A70 3C03800A */  lui       $v1, %hi(D_8009A614)
/* 14E74 80039A74 8463A614 */  lh        $v1, %lo(D_8009A614)($v1)
/* 14E78 80039A78 3C04800B */  lui       $a0, %hi(D_800B1D60)
/* 14E7C 80039A7C 24841D60 */  addiu     $a0, $a0, %lo(D_800B1D60)
/* 14E80 80039A80 AFBF0018 */  sw        $ra, 0x18($sp)
/* 14E84 80039A84 AFB00010 */  sw        $s0, 0x10($sp)
/* 14E88 80039A88 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 14E8C 80039A8C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 14E90 80039A90 00031080 */  sll       $v0, $v1, 2
/* 14E94 80039A94 00431021 */  addu      $v0, $v0, $v1
/* 14E98 80039A98 00021080 */  sll       $v0, $v0, 2
/* 14E9C 80039A9C 00431023 */  subu      $v0, $v0, $v1
/* 14EA0 80039AA0 000218C0 */  sll       $v1, $v0, 3
/* 14EA4 80039AA4 00431021 */  addu      $v0, $v0, $v1
/* 14EA8 80039AA8 000210C0 */  sll       $v0, $v0, 3
/* 14EAC 80039AAC 3C03800A */  lui       $v1, %hi(D_8009A630)
/* 14EB0 80039AB0 8C63A630 */  lw        $v1, %lo(D_8009A630)($v1)
/* 14EB4 80039AB4 3063C000 */  andi      $v1, $v1, 0xc000
/* 14EB8 80039AB8 1460006C */  bnez      $v1, .L80039C6C
/* 14EBC 80039ABC 00441021 */   addu     $v0, $v0, $a0
/* 14EC0 80039AC0 C456006C */  lwc1      $f22, 0x6c($v0)
/* 14EC4 80039AC4 C62E000C */  lwc1      $f14, 0xc($s1)
/* 14EC8 80039AC8 0C00A6FA */  jal       func_80029BE8
/* 14ECC 80039ACC 4600B306 */   mov.s    $f12, $f22
/* 14ED0 80039AD0 3C01C0A0 */  lui       $at, 0xc0a0
/* 14ED4 80039AD4 44811000 */  mtc1      $at, $f2
/* 14ED8 80039AD8 46000306 */  mov.s     $f12, $f0
/* 14EDC 80039ADC 4602603C */  c.lt.s    $f12, $f2
/* 14EE0 80039AE0 00000000 */  nop
/* 14EE4 80039AE4 4500000B */  bc1f      .L80039B14
/* 14EE8 80039AE8 00000000 */   nop
/* 14EEC 80039AEC 3C01C32F */  lui       $at, 0xc32f
/* 14EF0 80039AF0 44810000 */  mtc1      $at, $f0
/* 14EF4 80039AF4 00000000 */  nop
/* 14EF8 80039AF8 460C003C */  c.lt.s    $f0, $f12
/* 14EFC 80039AFC 00000000 */  nop
/* 14F00 80039B00 45000004 */  bc1f      .L80039B14
/* 14F04 80039B04 0000802D */   daddu    $s0, $zero, $zero
/* 14F08 80039B08 44806000 */  mtc1      $zero, $f12
/* 14F0C 80039B0C 0800E6DC */  j         .L80039B70
/* 14F10 80039B10 00000000 */   nop
.L80039B14:
/* 14F14 80039B14 3C0140A0 */  lui       $at, 0x40a0
/* 14F18 80039B18 44810000 */  mtc1      $at, $f0
/* 14F1C 80039B1C 00000000 */  nop
/* 14F20 80039B20 460C003C */  c.lt.s    $f0, $f12
/* 14F24 80039B24 00000000 */  nop
/* 14F28 80039B28 4500000C */  bc1f      .L80039B5C
/* 14F2C 80039B2C 00000000 */   nop
/* 14F30 80039B30 3C01432F */  lui       $at, 0x432f
/* 14F34 80039B34 44810000 */  mtc1      $at, $f0
/* 14F38 80039B38 00000000 */  nop
/* 14F3C 80039B3C 4600603C */  c.lt.s    $f12, $f0
/* 14F40 80039B40 00000000 */  nop
/* 14F44 80039B44 45000005 */  bc1f      .L80039B5C
/* 14F48 80039B48 24100001 */   addiu    $s0, $zero, 1
/* 14F4C 80039B4C 3C014334 */  lui       $at, 0x4334
/* 14F50 80039B50 44816000 */  mtc1      $at, $f12
/* 14F54 80039B54 0800E6DC */  j         .L80039B70
/* 14F58 80039B58 00000000 */   nop
.L80039B5C:
/* 14F5C 80039B5C 8622008A */  lh        $v0, 0x8a($s1)
/* 14F60 80039B60 24100002 */  addiu     $s0, $zero, 2
/* 14F64 80039B64 44826000 */  mtc1      $v0, $f12
/* 14F68 80039B68 00000000 */  nop
/* 14F6C 80039B6C 46806320 */  cvt.s.w   $f12, $f12
.L80039B70:
/* 14F70 80039B70 0C00A6B9 */  jal       func_80029AE4
/* 14F74 80039B74 00000000 */   nop
/* 14F78 80039B78 46000506 */  mov.s     $f20, $f0
/* 14F7C 80039B7C 4600A10D */  trunc.w.s $f4, $f20
/* 14F80 80039B80 44022000 */  mfc1      $v0, $f4
/* 14F84 80039B84 00000000 */  nop
/* 14F88 80039B88 A622008A */  sh        $v0, 0x8a($s1)
/* 14F8C 80039B8C 8E220000 */  lw        $v0, ($s1)
/* 14F90 80039B90 3C030004 */  lui       $v1, 4
/* 14F94 80039B94 00431024 */  and       $v0, $v0, $v1
/* 14F98 80039B98 14400034 */  bnez      $v0, .L80039C6C
/* 14F9C 80039B9C 00000000 */   nop
/* 14FA0 80039BA0 86220088 */  lh        $v0, 0x88($s1)
/* 14FA4 80039BA4 10500016 */  beq       $v0, $s0, .L80039C00
/* 14FA8 80039BA8 24020002 */   addiu    $v0, $zero, 2
/* 14FAC 80039BAC 12020014 */  beq       $s0, $v0, .L80039C00
/* 14FB0 80039BB0 00000000 */   nop
/* 14FB4 80039BB4 12000003 */  beqz      $s0, .L80039BC4
/* 14FB8 80039BB8 A6300088 */   sh       $s0, 0x88($s1)
/* 14FBC 80039BBC 0800E6F2 */  j         .L80039BC8
/* 14FC0 80039BC0 240200B4 */   addiu    $v0, $zero, 0xb4
.L80039BC4:
/* 14FC4 80039BC4 2402FF4C */  addiu     $v0, $zero, -0xb4
.L80039BC8:
/* 14FC8 80039BC8 A622008C */  sh        $v0, 0x8c($s1)
/* 14FCC 80039BCC C62E000C */  lwc1      $f14, 0xc($s1)
/* 14FD0 80039BD0 0C00A6FA */  jal       func_80029BE8
/* 14FD4 80039BD4 4600B306 */   mov.s    $f12, $f22
/* 14FD8 80039BD8 3C0142B4 */  lui       $at, 0x42b4
/* 14FDC 80039BDC 44811000 */  mtc1      $at, $f2
/* 14FE0 80039BE0 46000005 */  abs.s     $f0, $f0
/* 14FE4 80039BE4 4600103E */  c.le.s    $f2, $f0
/* 14FE8 80039BE8 00000000 */  nop
/* 14FEC 80039BEC 45000004 */  bc1f      .L80039C00
/* 14FF0 80039BF0 00000000 */   nop
/* 14FF4 80039BF4 9622008C */  lhu       $v0, 0x8c($s1)
/* 14FF8 80039BF8 00021023 */  negu      $v0, $v0
/* 14FFC 80039BFC A622008C */  sh        $v0, 0x8c($s1)
.L80039C00:
/* 15000 80039C00 8623008C */  lh        $v1, 0x8c($s1)
/* 15004 80039C04 10600009 */  beqz      $v1, .L80039C2C
/* 15008 80039C08 9622008C */   lhu      $v0, 0x8c($s1)
/* 1500C 80039C0C 04610002 */  bgez      $v1, .L80039C18
/* 15010 80039C10 24420014 */   addiu    $v0, $v0, 0x14
/* 15014 80039C14 A622008C */  sh        $v0, 0x8c($s1)
.L80039C18:
/* 15018 80039C18 8622008C */  lh        $v0, 0x8c($s1)
/* 1501C 80039C1C 9623008C */  lhu       $v1, 0x8c($s1)
/* 15020 80039C20 18400002 */  blez      $v0, .L80039C2C
/* 15024 80039C24 2462FFEC */   addiu    $v0, $v1, -0x14
/* 15028 80039C28 A622008C */  sh        $v0, 0x8c($s1)
.L80039C2C:
/* 1502C 80039C2C 8E220000 */  lw        $v0, ($s1)
/* 15030 80039C30 3C030020 */  lui       $v1, 0x20
/* 15034 80039C34 00431024 */  and       $v0, $v0, $v1
/* 15038 80039C38 54400001 */  bnel      $v0, $zero, .L80039C40
/* 1503C 80039C3C A620008C */   sh       $zero, 0x8c($s1)
.L80039C40:
/* 15040 80039C40 8622008C */  lh        $v0, 0x8c($s1)
/* 15044 80039C44 44826000 */  mtc1      $v0, $f12
/* 15048 80039C48 00000000 */  nop
/* 1504C 80039C4C 46806320 */  cvt.s.w   $f12, $f12
/* 15050 80039C50 0C00A6B9 */  jal       func_80029AE4
/* 15054 80039C54 46146300 */   add.s    $f12, $f12, $f20
/* 15058 80039C58 0C00A6B9 */  jal       func_80029AE4
/* 1505C 80039C5C 46160301 */   sub.s    $f12, $f0, $f22
/* 15060 80039C60 46000506 */  mov.s     $f20, $f0
/* 15064 80039C64 0800E71C */  j         .L80039C70
/* 15068 80039C68 E6340034 */   swc1     $f20, 0x34($s1)
.L80039C6C:
/* 1506C 80039C6C C6340034 */  lwc1      $f20, 0x34($s1)
.L80039C70:
/* 15070 80039C70 4600A006 */  mov.s     $f0, $f20
/* 15074 80039C74 8FBF0018 */  lw        $ra, 0x18($sp)
/* 15078 80039C78 8FB10014 */  lw        $s1, 0x14($sp)
/* 1507C 80039C7C 8FB00010 */  lw        $s0, 0x10($sp)
/* 15080 80039C80 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 15084 80039C84 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 15088 80039C88 03E00008 */  jr        $ra
/* 1508C 80039C8C 27BD0030 */   addiu    $sp, $sp, 0x30
