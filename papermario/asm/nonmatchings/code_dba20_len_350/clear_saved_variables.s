.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel clear_saved_variables
/* 0DBA20 80145320 2402003F */  addiu $v0, $zero, 0x3f
/* 0DBA24 80145324 3C04800E */  lui   $a0, 0x800e
/* 0DBA28 80145328 2484ACC0 */  addiu $a0, $a0, -0x5340
/* 0DBA2C 8014532C 248300FC */  addiu $v1, $a0, 0xfc
.L80145330:
/* 0DBA30 80145330 AC600FB0 */  sw    $zero, 0xfb0($v1)
/* 0DBA34 80145334 2442FFFF */  addiu $v0, $v0, -1
/* 0DBA38 80145338 0441FFFD */  bgez  $v0, .L80145330
/* 0DBA3C 8014533C 2463FFFC */   addiu $v1, $v1, -4
/* 0DBA40 80145340 240201FF */  addiu $v0, $zero, 0x1ff
/* 0DBA44 80145344 00821821 */  addu  $v1, $a0, $v0
.L80145348:
/* 0DBA48 80145348 A06010B0 */  sb    $zero, 0x10b0($v1)
/* 0DBA4C 8014534C 2442FFFF */  addiu $v0, $v0, -1
/* 0DBA50 80145350 0441FFFD */  bgez  $v0, .L80145348
/* 0DBA54 80145354 2463FFFF */   addiu $v1, $v1, -1
/* 0DBA58 80145358 24020007 */  addiu $v0, $zero, 7
/* 0DBA5C 8014535C 2483001C */  addiu $v1, $a0, 0x1c
.L80145360:
/* 0DBA60 80145360 AC6012B0 */  sw    $zero, 0x12b0($v1)
/* 0DBA64 80145364 2442FFFF */  addiu $v0, $v0, -1
/* 0DBA68 80145368 0441FFFD */  bgez  $v0, .L80145360
/* 0DBA6C 8014536C 2463FFFC */   addiu $v1, $v1, -4
/* 0DBA70 80145370 2402000F */  addiu $v0, $zero, 0xf
/* 0DBA74 80145374 00821821 */  addu  $v1, $a0, $v0
.L80145378:
/* 0DBA78 80145378 A06012D0 */  sb    $zero, 0x12d0($v1)
/* 0DBA7C 8014537C 2442FFFF */  addiu $v0, $v0, -1
/* 0DBA80 80145380 0441FFFD */  bgez  $v0, .L80145378
/* 0DBA84 80145384 2463FFFF */   addiu $v1, $v1, -1
/* 0DBA88 80145388 03E00008 */  jr    $ra
/* 0DBA8C 8014538C 00000000 */   nop   

