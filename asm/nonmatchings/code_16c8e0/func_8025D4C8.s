.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8025D4C8
/* 18BDA8 8025D4C8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 18BDAC 8025D4CC AFB1001C */  sw    $s1, 0x1c($sp)
/* 18BDB0 8025D4D0 0080882D */  daddu $s1, $a0, $zero
/* 18BDB4 8025D4D4 AFBF0028 */  sw    $ra, 0x28($sp)
/* 18BDB8 8025D4D8 AFB30024 */  sw    $s3, 0x24($sp)
/* 18BDBC 8025D4DC AFB20020 */  sw    $s2, 0x20($sp)
/* 18BDC0 8025D4E0 AFB00018 */  sw    $s0, 0x18($sp)
/* 18BDC4 8025D4E4 8E3000C0 */  lw    $s0, 0xc0($s1)
/* 18BDC8 8025D4E8 00A0982D */  daddu $s3, $a1, $zero
/* 18BDCC 8025D4EC 02139021 */  addu  $s2, $s0, $s3
/* 18BDD0 8025D4F0 824308BC */  lb    $v1, 0x8bc($s2)
/* 18BDD4 8025D4F4 10600005 */  beqz  $v1, .L8025D50C
/* 18BDD8 8025D4F8 24020001 */   addiu $v0, $zero, 1
/* 18BDDC 8025D4FC 1062001E */  beq   $v1, $v0, .L8025D578
/* 18BDE0 8025D500 00131080 */   sll   $v0, $s3, 2
/* 18BDE4 8025D504 08097581 */  j     .L8025D604
/* 18BDE8 8025D508 00000000 */   nop   

.L8025D50C:
/* 18BDEC 8025D50C 00131080 */  sll   $v0, $s3, 2
/* 18BDF0 8025D510 244208B0 */  addiu $v0, $v0, 0x8b0
/* 18BDF4 8025D514 3C013ECC */  lui   $at, 0x3ecc
/* 18BDF8 8025D518 3421CCCD */  ori   $at, $at, 0xcccd
/* 18BDFC 8025D51C 44810000 */  mtc1  $at, $f0
/* 18BE00 8025D520 02021021 */  addu  $v0, $s0, $v0
/* 18BE04 8025D524 AFA20014 */  sw    $v0, 0x14($sp)
/* 18BE08 8025D528 E7A00010 */  swc1  $f0, 0x10($sp)
/* 18BE0C 8025D52C 8E250058 */  lw    $a1, 0x58($s1)
/* 18BE10 8025D530 8E26005C */  lw    $a2, 0x5c($s1)
/* 18BE14 8025D534 8E270060 */  lw    $a3, 0x60($s1)
/* 18BE18 8025D538 0C01C3AC */  jal   func_80070EB0
/* 18BE1C 8025D53C 24040001 */   addiu $a0, $zero, 1
/* 18BE20 8025D540 24020001 */  addiu $v0, $zero, 1
/* 18BE24 8025D544 A24208BC */  sb    $v0, 0x8bc($s2)
/* 18BE28 8025D548 00131100 */  sll   $v0, $s3, 4
/* 18BE2C 8025D54C 02021021 */  addu  $v0, $s0, $v0
/* 18BE30 8025D550 24030028 */  addiu $v1, $zero, 0x28
/* 18BE34 8025D554 A44308C6 */  sh    $v1, 0x8c6($v0)
/* 18BE38 8025D558 A44308C8 */  sh    $v1, 0x8c8($v0)
/* 18BE3C 8025D55C 240300FF */  addiu $v1, $zero, 0xff
/* 18BE40 8025D560 A44308CA */  sh    $v1, 0x8ca($v0)
/* 18BE44 8025D564 A44008CC */  sh    $zero, 0x8cc($v0)
/* 18BE48 8025D568 A44308CE */  sh    $v1, 0x8ce($v0)
/* 18BE4C 8025D56C A44008D0 */  sh    $zero, 0x8d0($v0)
/* 18BE50 8025D570 A44008D2 */  sh    $zero, 0x8d2($v0)
/* 18BE54 8025D574 00131080 */  sll   $v0, $s3, 2
.L8025D578:
/* 18BE58 8025D578 02021021 */  addu  $v0, $s0, $v0
/* 18BE5C 8025D57C 8C4508B0 */  lw    $a1, 0x8b0($v0)
/* 18BE60 8025D580 C6200058 */  lwc1  $f0, 0x58($s1)
/* 18BE64 8025D584 8CA3000C */  lw    $v1, 0xc($a1)
/* 18BE68 8025D588 00132100 */  sll   $a0, $s3, 4
/* 18BE6C 8025D58C E4600004 */  swc1  $f0, 4($v1)
/* 18BE70 8025D590 C620005C */  lwc1  $f0, 0x5c($s1)
/* 18BE74 8025D594 02042021 */  addu  $a0, $s0, $a0
/* 18BE78 8025D598 E4600008 */  swc1  $f0, 8($v1)
/* 18BE7C 8025D59C 848208CC */  lh    $v0, 0x8cc($a0)
/* 18BE80 8025D5A0 C6200060 */  lwc1  $f0, 0x60($s1)
/* 18BE84 8025D5A4 44821000 */  mtc1  $v0, $f2
/* 18BE88 8025D5A8 00000000 */  nop   
/* 18BE8C 8025D5AC 468010A0 */  cvt.s.w $f2, $f2
/* 18BE90 8025D5B0 46020000 */  add.s $f0, $f0, $f2
/* 18BE94 8025D5B4 E460000C */  swc1  $f0, 0xc($v1)
/* 18BE98 8025D5B8 848208C6 */  lh    $v0, 0x8c6($a0)
/* 18BE9C 8025D5BC 3C0142C8 */  lui   $at, 0x42c8
/* 18BEA0 8025D5C0 44810000 */  mtc1  $at, $f0
/* 18BEA4 8025D5C4 44821000 */  mtc1  $v0, $f2
/* 18BEA8 8025D5C8 00000000 */  nop   
/* 18BEAC 8025D5CC 468010A0 */  cvt.s.w $f2, $f2
/* 18BEB0 8025D5D0 8CA2000C */  lw    $v0, 0xc($a1)
/* 18BEB4 8025D5D4 46001083 */  div.s $f2, $f2, $f0
/* 18BEB8 8025D5D8 E442001C */  swc1  $f2, 0x1c($v0)
/* 18BEBC 8025D5DC 848208C8 */  lh    $v0, 0x8c8($a0)
/* 18BEC0 8025D5E0 44821000 */  mtc1  $v0, $f2
/* 18BEC4 8025D5E4 00000000 */  nop   
/* 18BEC8 8025D5E8 468010A0 */  cvt.s.w $f2, $f2
/* 18BECC 8025D5EC 8CA2000C */  lw    $v0, 0xc($a1)
/* 18BED0 8025D5F0 46001083 */  div.s $f2, $f2, $f0
/* 18BED4 8025D5F4 E4420020 */  swc1  $f2, 0x20($v0)
/* 18BED8 8025D5F8 8CA3000C */  lw    $v1, 0xc($a1)
/* 18BEDC 8025D5FC 848208CA */  lh    $v0, 0x8ca($a0)
/* 18BEE0 8025D600 AC620028 */  sw    $v0, 0x28($v1)
.L8025D604:
/* 18BEE4 8025D604 8FBF0028 */  lw    $ra, 0x28($sp)
/* 18BEE8 8025D608 8FB30024 */  lw    $s3, 0x24($sp)
/* 18BEEC 8025D60C 8FB20020 */  lw    $s2, 0x20($sp)
/* 18BEF0 8025D610 8FB1001C */  lw    $s1, 0x1c($sp)
/* 18BEF4 8025D614 8FB00018 */  lw    $s0, 0x18($sp)
/* 18BEF8 8025D618 03E00008 */  jr    $ra
/* 18BEFC 8025D61C 27BD0030 */   addiu $sp, $sp, 0x30

