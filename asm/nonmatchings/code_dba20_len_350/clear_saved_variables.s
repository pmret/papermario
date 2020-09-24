.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel clear_saved_variables
/* DBA20 80145320 2402003F */  addiu     $v0, $zero, 0x3f
/* DBA24 80145324 3C04800E */  lui       $a0, 0x800e
/* DBA28 80145328 2484ACC0 */  addiu     $a0, $a0, -0x5340
/* DBA2C 8014532C 248300FC */  addiu     $v1, $a0, 0xfc
.L80145330:
/* DBA30 80145330 AC600FB0 */  sw        $zero, 0xfb0($v1)
/* DBA34 80145334 2442FFFF */  addiu     $v0, $v0, -1
/* DBA38 80145338 0441FFFD */  bgez      $v0, .L80145330
/* DBA3C 8014533C 2463FFFC */   addiu    $v1, $v1, -4
/* DBA40 80145340 240201FF */  addiu     $v0, $zero, 0x1ff
/* DBA44 80145344 00821821 */  addu      $v1, $a0, $v0
.L80145348:
/* DBA48 80145348 A06010B0 */  sb        $zero, 0x10b0($v1)
/* DBA4C 8014534C 2442FFFF */  addiu     $v0, $v0, -1
/* DBA50 80145350 0441FFFD */  bgez      $v0, .L80145348
/* DBA54 80145354 2463FFFF */   addiu    $v1, $v1, -1
/* DBA58 80145358 24020007 */  addiu     $v0, $zero, 7
/* DBA5C 8014535C 2483001C */  addiu     $v1, $a0, 0x1c
.L80145360:
/* DBA60 80145360 AC6012B0 */  sw        $zero, 0x12b0($v1)
/* DBA64 80145364 2442FFFF */  addiu     $v0, $v0, -1
/* DBA68 80145368 0441FFFD */  bgez      $v0, .L80145360
/* DBA6C 8014536C 2463FFFC */   addiu    $v1, $v1, -4
/* DBA70 80145370 2402000F */  addiu     $v0, $zero, 0xf
/* DBA74 80145374 00821821 */  addu      $v1, $a0, $v0
.L80145378:
/* DBA78 80145378 A06012D0 */  sb        $zero, 0x12d0($v1)
/* DBA7C 8014537C 2442FFFF */  addiu     $v0, $v0, -1
/* DBA80 80145380 0441FFFD */  bgez      $v0, .L80145378
/* DBA84 80145384 2463FFFF */   addiu    $v1, $v1, -1
/* DBA88 80145388 03E00008 */  jr        $ra
/* DBA8C 8014538C 00000000 */   nop      
