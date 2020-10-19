.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E90_BE8A70
/* BE8A70 80240E90 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BE8A74 80240E94 AFB20030 */  sw        $s2, 0x30($sp)
/* BE8A78 80240E98 0080902D */  daddu     $s2, $a0, $zero
/* BE8A7C 80240E9C AFBF0034 */  sw        $ra, 0x34($sp)
/* BE8A80 80240EA0 AFB1002C */  sw        $s1, 0x2c($sp)
/* BE8A84 80240EA4 AFB00028 */  sw        $s0, 0x28($sp)
/* BE8A88 80240EA8 F7B60040 */  sdc1      $f22, 0x40($sp)
/* BE8A8C 80240EAC F7B40038 */  sdc1      $f20, 0x38($sp)
/* BE8A90 80240EB0 8E500148 */  lw        $s0, 0x148($s2)
/* BE8A94 80240EB4 0C00EABB */  jal       get_npc_unsafe
/* BE8A98 80240EB8 86040008 */   lh       $a0, 8($s0)
/* BE8A9C 80240EBC 0040882D */  daddu     $s1, $v0, $zero
/* BE8AA0 80240EC0 C62C0038 */  lwc1      $f12, 0x38($s1)
/* BE8AA4 80240EC4 8E430078 */  lw        $v1, 0x78($s2)
/* BE8AA8 80240EC8 C62E0040 */  lwc1      $f14, 0x40($s1)
/* BE8AAC 80240ECC 00031040 */  sll       $v0, $v1, 1
/* BE8AB0 80240ED0 00431021 */  addu      $v0, $v0, $v1
/* BE8AB4 80240ED4 8E0300D0 */  lw        $v1, 0xd0($s0)
/* BE8AB8 80240ED8 00021080 */  sll       $v0, $v0, 2
/* BE8ABC 80240EDC 00431021 */  addu      $v0, $v0, $v1
/* BE8AC0 80240EE0 C4560004 */  lwc1      $f22, 4($v0)
/* BE8AC4 80240EE4 4680B5A0 */  cvt.s.w   $f22, $f22
/* BE8AC8 80240EE8 C454000C */  lwc1      $f20, 0xc($v0)
/* BE8ACC 80240EEC 4680A520 */  cvt.s.w   $f20, $f20
/* BE8AD0 80240EF0 4406B000 */  mfc1      $a2, $f22
/* BE8AD4 80240EF4 4407A000 */  mfc1      $a3, $f20
/* BE8AD8 80240EF8 E7AC0018 */  swc1      $f12, 0x18($sp)
/* BE8ADC 80240EFC 0C00A720 */  jal       atan2
/* BE8AE0 80240F00 E7AE0020 */   swc1     $f14, 0x20($sp)
/* BE8AE4 80240F04 8E250018 */  lw        $a1, 0x18($s1)
/* BE8AE8 80240F08 44060000 */  mfc1      $a2, $f0
/* BE8AEC 80240F0C 0220202D */  daddu     $a0, $s1, $zero
/* BE8AF0 80240F10 0C00EA95 */  jal       npc_move_heading
/* BE8AF4 80240F14 AE26000C */   sw       $a2, 0xc($s1)
/* BE8AF8 80240F18 27A50018 */  addiu     $a1, $sp, 0x18
/* BE8AFC 80240F1C 27A6001C */  addiu     $a2, $sp, 0x1c
/* BE8B00 80240F20 C6200038 */  lwc1      $f0, 0x38($s1)
/* BE8B04 80240F24 8E430078 */  lw        $v1, 0x78($s2)
/* BE8B08 80240F28 3C01447A */  lui       $at, 0x447a
/* BE8B0C 80240F2C 44812000 */  mtc1      $at, $f4
/* BE8B10 80240F30 00031040 */  sll       $v0, $v1, 1
/* BE8B14 80240F34 00431021 */  addu      $v0, $v0, $v1
/* BE8B18 80240F38 00021080 */  sll       $v0, $v0, 2
/* BE8B1C 80240F3C E7A00018 */  swc1      $f0, 0x18($sp)
/* BE8B20 80240F40 8E0300D0 */  lw        $v1, 0xd0($s0)
/* BE8B24 80240F44 C620003C */  lwc1      $f0, 0x3c($s1)
/* BE8B28 80240F48 C6220040 */  lwc1      $f2, 0x40($s1)
/* BE8B2C 80240F4C 00431021 */  addu      $v0, $v0, $v1
/* BE8B30 80240F50 C4460008 */  lwc1      $f6, 8($v0)
/* BE8B34 80240F54 468031A0 */  cvt.s.w   $f6, $f6
/* BE8B38 80240F58 27A20024 */  addiu     $v0, $sp, 0x24
/* BE8B3C 80240F5C 46060000 */  add.s     $f0, $f0, $f6
/* BE8B40 80240F60 E7A20020 */  swc1      $f2, 0x20($sp)
/* BE8B44 80240F64 E7A40024 */  swc1      $f4, 0x24($sp)
/* BE8B48 80240F68 E7A0001C */  swc1      $f0, 0x1c($sp)
/* BE8B4C 80240F6C AFA20010 */  sw        $v0, 0x10($sp)
/* BE8B50 80240F70 8E240080 */  lw        $a0, 0x80($s1)
/* BE8B54 80240F74 0C0372DF */  jal       func_800DCB7C
/* BE8B58 80240F78 27A70020 */   addiu    $a3, $sp, 0x20
/* BE8B5C 80240F7C 8E430078 */  lw        $v1, 0x78($s2)
/* BE8B60 80240F80 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* BE8B64 80240F84 00031040 */  sll       $v0, $v1, 1
/* BE8B68 80240F88 00431021 */  addu      $v0, $v0, $v1
/* BE8B6C 80240F8C 8E0300D0 */  lw        $v1, 0xd0($s0)
/* BE8B70 80240F90 00021080 */  sll       $v0, $v0, 2
/* BE8B74 80240F94 00431021 */  addu      $v0, $v0, $v1
/* BE8B78 80240F98 C4400008 */  lwc1      $f0, 8($v0)
/* BE8B7C 80240F9C 46800020 */  cvt.s.w   $f0, $f0
/* BE8B80 80240FA0 46001080 */  add.s     $f2, $f2, $f0
/* BE8B84 80240FA4 C620003C */  lwc1      $f0, 0x3c($s1)
/* BE8B88 80240FA8 3C014000 */  lui       $at, 0x4000
/* BE8B8C 80240FAC 44813800 */  mtc1      $at, $f7
/* BE8B90 80240FB0 44803000 */  mtc1      $zero, $f6
/* BE8B94 80240FB4 46001001 */  sub.s     $f0, $f2, $f0
/* BE8B98 80240FB8 E7A2001C */  swc1      $f2, 0x1c($sp)
/* BE8B9C 80240FBC 46000121 */  cvt.d.s   $f4, $f0
/* BE8BA0 80240FC0 4624303C */  c.lt.d    $f6, $f4
/* BE8BA4 80240FC4 00000000 */  nop       
/* BE8BA8 80240FC8 45000005 */  bc1f      .L80240FE0
/* BE8BAC 80240FCC E7A00024 */   swc1     $f0, 0x24($sp)
/* BE8BB0 80240FD0 C620003C */  lwc1      $f0, 0x3c($s1)
/* BE8BB4 80240FD4 46000021 */  cvt.d.s   $f0, $f0
/* BE8BB8 80240FD8 08090403 */  j         .L8024100C
/* BE8BBC 80240FDC 46260000 */   add.d    $f0, $f0, $f6
.L80240FE0:
/* BE8BC0 80240FE0 3C01C000 */  lui       $at, 0xc000
/* BE8BC4 80240FE4 44810800 */  mtc1      $at, $f1
/* BE8BC8 80240FE8 44800000 */  mtc1      $zero, $f0
/* BE8BCC 80240FEC 00000000 */  nop       
/* BE8BD0 80240FF0 4620203C */  c.lt.d    $f4, $f0
/* BE8BD4 80240FF4 00000000 */  nop       
/* BE8BD8 80240FF8 45020006 */  bc1fl     .L80241014
/* BE8BDC 80240FFC E622003C */   swc1     $f2, 0x3c($s1)
/* BE8BE0 80241000 C620003C */  lwc1      $f0, 0x3c($s1)
/* BE8BE4 80241004 46000021 */  cvt.d.s   $f0, $f0
/* BE8BE8 80241008 46260001 */  sub.d     $f0, $f0, $f6
.L8024100C:
/* BE8BEC 8024100C 46200020 */  cvt.s.d   $f0, $f0
/* BE8BF0 80241010 E620003C */  swc1      $f0, 0x3c($s1)
.L80241014:
/* BE8BF4 80241014 C62C0038 */  lwc1      $f12, 0x38($s1)
/* BE8BF8 80241018 C62E0040 */  lwc1      $f14, 0x40($s1)
/* BE8BFC 8024101C 4406B000 */  mfc1      $a2, $f22
/* BE8C00 80241020 4407A000 */  mfc1      $a3, $f20
/* BE8C04 80241024 0C00A7B5 */  jal       dist2D
/* BE8C08 80241028 00000000 */   nop      
/* BE8C0C 8024102C C6220018 */  lwc1      $f2, 0x18($s1)
/* BE8C10 80241030 4600103C */  c.lt.s    $f2, $f0
/* BE8C14 80241034 00000000 */  nop       
/* BE8C18 80241038 45010003 */  bc1t      .L80241048
/* BE8C1C 8024103C E7A00024 */   swc1     $f0, 0x24($sp)
/* BE8C20 80241040 24020002 */  addiu     $v0, $zero, 2
/* BE8C24 80241044 AE420070 */  sw        $v0, 0x70($s2)
.L80241048:
/* BE8C28 80241048 8FBF0034 */  lw        $ra, 0x34($sp)
/* BE8C2C 8024104C 8FB20030 */  lw        $s2, 0x30($sp)
/* BE8C30 80241050 8FB1002C */  lw        $s1, 0x2c($sp)
/* BE8C34 80241054 8FB00028 */  lw        $s0, 0x28($sp)
/* BE8C38 80241058 D7B60040 */  ldc1      $f22, 0x40($sp)
/* BE8C3C 8024105C D7B40038 */  ldc1      $f20, 0x38($sp)
/* BE8C40 80241060 03E00008 */  jr        $ra
/* BE8C44 80241064 27BD0048 */   addiu    $sp, $sp, 0x48
