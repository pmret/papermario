.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80050888
/* 02BC88 80050888 10C00002 */  beqz  $a2, .L80050894
/* 02BC8C 8005088C 00061200 */   sll   $v0, $a2, 8
/* 02BC90 80050890 344600FF */  ori   $a2, $v0, 0xff
.L80050894:
/* 02BC94 80050894 1CE00003 */  bgtz  $a3, .L800508A4
/* 02BC98 80050898 28E203E9 */   slti  $v0, $a3, 0x3e9
/* 02BC9C 8005089C 0801422B */  j     .L800508AC
/* 02BCA0 800508A0 24070001 */   addiu $a3, $zero, 1

.L800508A4:
/* 02BCA4 800508A4 50400001 */  beql  $v0, $zero, .L800508AC
/* 02BCA8 800508A8 240703E8 */   addiu $a3, $zero, 0x3e8
.L800508AC:
/* 02BCAC 800508AC 8CA2002C */  lw    $v0, 0x2c($a1)
/* 02BCB0 800508B0 14C20003 */  bne   $a2, $v0, .L800508C0
/* 02BCB4 800508B4 00061400 */   sll   $v0, $a2, 0x10
/* 02BCB8 800508B8 03E00008 */  jr    $ra
/* 02BCBC 800508BC A4A00036 */   sh    $zero, 0x36($a1)

.L800508C0:
/* 02BCC0 800508C0 8CA3002C */  lw    $v1, 0x2c($a1)
/* 02BCC4 800508C4 00431023 */  subu  $v0, $v0, $v1
/* 02BCC8 800508C8 14E00002 */  bnez  $a3, .L800508D4
/* 02BCCC 800508CC 0047001A */   div   $zero, $v0, $a3
/* 02BCD0 800508D0 0007000D */  break 7
.L800508D4:
/* 02BCD4 800508D4 2401FFFF */  addiu $at, $zero, -1
/* 02BCD8 800508D8 14E10004 */  bne   $a3, $at, .L800508EC
/* 02BCDC 800508DC 3C018000 */   lui   $at, 0x8000
/* 02BCE0 800508E0 14410002 */  bne   $v0, $at, .L800508EC
/* 02BCE4 800508E4 00000000 */   nop   
/* 02BCE8 800508E8 0006000D */  break 6
.L800508EC:
/* 02BCEC 800508EC 00001012 */  mflo  $v0
/* 02BCF0 800508F0 A4A70036 */  sh    $a3, 0x36($a1)
/* 02BCF4 800508F4 A4A60034 */  sh    $a2, 0x34($a1)
/* 02BCF8 800508F8 03E00008 */  jr    $ra
/* 02BCFC 800508FC ACA20030 */   sw    $v0, 0x30($a1)

