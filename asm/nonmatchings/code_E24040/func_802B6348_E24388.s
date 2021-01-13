.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6348_E24388
/* E24388 802B6348 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* E2438C 802B634C 3C058011 */  lui       $a1, %hi(gPlayerStatus)
/* E24390 802B6350 24A5EFC8 */  addiu     $a1, $a1, %lo(gPlayerStatus)
/* E24394 802B6354 AFBF004C */  sw        $ra, 0x4c($sp)
/* E24398 802B6358 AFB00048 */  sw        $s0, 0x48($sp)
/* E2439C 802B635C 8CA20004 */  lw        $v0, 4($a1)
/* E243A0 802B6360 30421000 */  andi      $v0, $v0, 0x1000
/* E243A4 802B6364 10400005 */  beqz      $v0, .L802B637C
/* E243A8 802B6368 00A0802D */   daddu    $s0, $a1, $zero
/* E243AC 802B636C 0C0AD942 */  jal       func_802B6508_E24548
/* E243B0 802B6370 00000000 */   nop
/* E243B4 802B6374 080AD91B */  j         .L802B646C
/* E243B8 802B6378 00000000 */   nop
.L802B637C:
/* E243BC 802B637C 8CA30000 */  lw        $v1, ($a1)
/* E243C0 802B6380 0461000A */  bgez      $v1, .L802B63AC
/* E243C4 802B6384 3C027FFF */   lui      $v0, 0x7fff
/* E243C8 802B6388 3442FFF5 */  ori       $v0, $v0, 0xfff5
/* E243CC 802B638C 00621024 */  and       $v0, $v1, $v0
/* E243D0 802B6390 3C04800B */  lui       $a0, %hi(gCameras)
/* E243D4 802B6394 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* E243D8 802B6398 94830002 */  lhu       $v1, 2($a0)
/* E243DC 802B639C 34420004 */  ori       $v0, $v0, 4
/* E243E0 802B63A0 ACA20000 */  sw        $v0, ($a1)
/* E243E4 802B63A4 34630001 */  ori       $v1, $v1, 1
/* E243E8 802B63A8 A4830002 */  sh        $v1, 2($a0)
.L802B63AC:
/* E243EC 802B63AC 960200C0 */  lhu       $v0, 0xc0($s0)
/* E243F0 802B63B0 24420001 */  addiu     $v0, $v0, 1
/* E243F4 802B63B4 0C039454 */  jal       func_800E5150
/* E243F8 802B63B8 A60200C0 */   sh       $v0, 0xc0($s0)
/* E243FC 802B63BC 0200202D */  daddu     $a0, $s0, $zero
/* E24400 802B63C0 27A50028 */  addiu     $a1, $sp, 0x28
/* E24404 802B63C4 27A6002C */  addiu     $a2, $sp, 0x2c
/* E24408 802B63C8 C6000028 */  lwc1      $f0, 0x28($s0)
/* E2440C 802B63CC C602002C */  lwc1      $f2, 0x2c($s0)
/* E24410 802B63D0 C6040030 */  lwc1      $f4, 0x30($s0)
/* E24414 802B63D4 860200B0 */  lh        $v0, 0xb0($s0)
/* E24418 802B63D8 27A70030 */  addiu     $a3, $sp, 0x30
/* E2441C 802B63DC E7A00028 */  swc1      $f0, 0x28($sp)
/* E24420 802B63E0 44820000 */  mtc1      $v0, $f0
/* E24424 802B63E4 00000000 */  nop
/* E24428 802B63E8 46800020 */  cvt.s.w   $f0, $f0
/* E2442C 802B63EC 27A20034 */  addiu     $v0, $sp, 0x34
/* E24430 802B63F0 E7A2002C */  swc1      $f2, 0x2c($sp)
/* E24434 802B63F4 E7A40030 */  swc1      $f4, 0x30($sp)
/* E24438 802B63F8 E7A00034 */  swc1      $f0, 0x34($sp)
/* E2443C 802B63FC AFA20010 */  sw        $v0, 0x10($sp)
/* E24440 802B6400 27A20038 */  addiu     $v0, $sp, 0x38
/* E24444 802B6404 AFA20014 */  sw        $v0, 0x14($sp)
/* E24448 802B6408 27A2003C */  addiu     $v0, $sp, 0x3c
/* E2444C 802B640C AFA20018 */  sw        $v0, 0x18($sp)
/* E24450 802B6410 27A20040 */  addiu     $v0, $sp, 0x40
/* E24454 802B6414 AFA2001C */  sw        $v0, 0x1c($sp)
/* E24458 802B6418 27A20044 */  addiu     $v0, $sp, 0x44
/* E2445C 802B641C 0C03791B */  jal       func_800DE46C
/* E24460 802B6420 AFA20020 */   sw       $v0, 0x20($sp)
/* E24464 802B6424 0C016F6A */  jal       get_collider_type_by_id
/* E24468 802B6428 0040202D */   daddu    $a0, $v0, $zero
/* E2446C 802B642C 304200FF */  andi      $v0, $v0, 0xff
/* E24470 802B6430 2442FFFE */  addiu     $v0, $v0, -2
/* E24474 802B6434 2C420002 */  sltiu     $v0, $v0, 2
/* E24478 802B6438 1440000C */  bnez      $v0, .L802B646C
/* E2447C 802B643C 00000000 */   nop
/* E24480 802B6440 0C039858 */  jal       check_input_jump
/* E24484 802B6444 00000000 */   nop
/* E24488 802B6448 10400008 */  beqz      $v0, .L802B646C
/* E2448C 802B644C 00000000 */   nop
/* E24490 802B6450 0C039769 */  jal       set_action_state
/* E24494 802B6454 24040003 */   addiu    $a0, $zero, 3
/* E24498 802B6458 8E020000 */  lw        $v0, ($s0)
/* E2449C 802B645C 2403FFF1 */  addiu     $v1, $zero, -0xf
/* E244A0 802B6460 00431024 */  and       $v0, $v0, $v1
/* E244A4 802B6464 0C0AD82D */  jal       func_802B60B4_E240F4
/* E244A8 802B6468 AE020000 */   sw       $v0, ($s0)
.L802B646C:
/* E244AC 802B646C 8FBF004C */  lw        $ra, 0x4c($sp)
/* E244B0 802B6470 8FB00048 */  lw        $s0, 0x48($sp)
/* E244B4 802B6474 03E00008 */  jr        $ra
/* E244B8 802B6478 27BD0050 */   addiu    $sp, $sp, 0x50
