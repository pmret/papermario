.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E153C
/* 102DBC 802E153C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 102DC0 802E1540 AFB00030 */  sw        $s0, 0x30($sp)
/* 102DC4 802E1544 0080802D */  daddu     $s0, $a0, $zero
/* 102DC8 802E1548 27A20028 */  addiu     $v0, $sp, 0x28
/* 102DCC 802E154C 27A40018 */  addiu     $a0, $sp, 0x18
/* 102DD0 802E1550 3C014120 */  lui       $at, 0x4120
/* 102DD4 802E1554 44810000 */  mtc1      $at, $f0
/* 102DD8 802E1558 27A5001C */  addiu     $a1, $sp, 0x1c
/* 102DDC 802E155C AFBF0038 */  sw        $ra, 0x38($sp)
/* 102DE0 802E1560 AFB10034 */  sw        $s1, 0x34($sp)
/* 102DE4 802E1564 C6020048 */  lwc1      $f2, 0x48($s0)
/* 102DE8 802E1568 C604004C */  lwc1      $f4, 0x4c($s0)
/* 102DEC 802E156C C6060050 */  lwc1      $f6, 0x50($s0)
/* 102DF0 802E1570 27A60020 */  addiu     $a2, $sp, 0x20
/* 102DF4 802E1574 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 102DF8 802E1578 E7A20018 */  swc1      $f2, 0x18($sp)
/* 102DFC 802E157C E7A4001C */  swc1      $f4, 0x1c($sp)
/* 102E00 802E1580 E7A60020 */  swc1      $f6, 0x20($sp)
/* 102E04 802E1584 8E110040 */  lw        $s1, 0x40($s0)
/* 102E08 802E1588 27A70024 */  addiu     $a3, $sp, 0x24
/* 102E0C 802E158C AFA20010 */  sw        $v0, 0x10($sp)
/* 102E10 802E1590 27A2002C */  addiu     $v0, $sp, 0x2c
/* 102E14 802E1594 0C04497A */  jal       func_801125E8
/* 102E18 802E1598 AFA20014 */   sw       $v0, 0x14($sp)
/* 102E1C 802E159C C600004C */  lwc1      $f0, 0x4c($s0)
/* 102E20 802E15A0 C7A4001C */  lwc1      $f4, 0x1c($sp)
/* 102E24 802E15A4 46040032 */  c.eq.s    $f0, $f4
/* 102E28 802E15A8 00000000 */  nop       
/* 102E2C 802E15AC 45010014 */  bc1t      .L802E1600
/* 102E30 802E15B0 00000000 */   nop      
/* 102E34 802E15B4 4600203C */  c.lt.s    $f4, $f0
/* 102E38 802E15B8 00000000 */  nop       
/* 102E3C 802E15BC 45000010 */  bc1f      .L802E1600
/* 102E40 802E15C0 00000000 */   nop      
/* 102E44 802E15C4 C6220000 */  lwc1      $f2, ($s1)
/* 102E48 802E15C8 3C013FE0 */  lui       $at, 0x3fe0
/* 102E4C 802E15CC 44810800 */  mtc1      $at, $f1
/* 102E50 802E15D0 44800000 */  mtc1      $zero, $f0
/* 102E54 802E15D4 460010A1 */  cvt.d.s   $f2, $f2
/* 102E58 802E15D8 46201080 */  add.d     $f2, $f2, $f0
/* 102E5C 802E15DC 462010A0 */  cvt.s.d   $f2, $f2
/* 102E60 802E15E0 E6220000 */  swc1      $f2, ($s1)
/* 102E64 802E15E4 C600004C */  lwc1      $f0, 0x4c($s0)
/* 102E68 802E15E8 46020001 */  sub.s     $f0, $f0, $f2
/* 102E6C 802E15EC 4604003C */  c.lt.s    $f0, $f4
/* 102E70 802E15F0 00000000 */  nop       
/* 102E74 802E15F4 45000002 */  bc1f      .L802E1600
/* 102E78 802E15F8 E600004C */   swc1     $f0, 0x4c($s0)
/* 102E7C 802E15FC E604004C */  swc1      $f4, 0x4c($s0)
.L802E1600:
/* 102E80 802E1600 8FBF0038 */  lw        $ra, 0x38($sp)
/* 102E84 802E1604 8FB10034 */  lw        $s1, 0x34($sp)
/* 102E88 802E1608 8FB00030 */  lw        $s0, 0x30($sp)
/* 102E8C 802E160C 03E00008 */  jr        $ra
/* 102E90 802E1610 27BD0040 */   addiu    $sp, $sp, 0x40
