.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B7450_E20560
/* E20560 802B7450 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E20564 802B7454 3C028016 */  lui       $v0, %hi(gCollisionStatus)
/* E20568 802B7458 2442A550 */  addiu     $v0, $v0, %lo(gCollisionStatus)
/* E2056C 802B745C AFB10014 */  sw        $s1, 0x14($sp)
/* E20570 802B7460 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* E20574 802B7464 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* E20578 802B7468 AFB20018 */  sw        $s2, 0x18($sp)
/* E2057C 802B746C 2412FFFF */  addiu     $s2, $zero, -1
/* E20580 802B7470 AFBF001C */  sw        $ra, 0x1c($sp)
/* E20584 802B7474 AFB00010 */  sw        $s0, 0x10($sp)
/* E20588 802B7478 84500012 */  lh        $s0, 0x12($v0)
/* E2058C 802B747C 8E2500C8 */  lw        $a1, 0xc8($s1)
/* E20590 802B7480 56120030 */  bnel      $s0, $s2, .L802B7544
/* E20594 802B7484 32024000 */   andi     $v0, $s0, 0x4000
/* E20598 802B7488 84440002 */  lh        $a0, 2($v0)
/* E2059C 802B748C 04800010 */  bltz      $a0, .L802B74D0
/* E205A0 802B7490 30824000 */   andi     $v0, $a0, 0x4000
/* E205A4 802B7494 1040000F */  beqz      $v0, .L802B74D4
/* E205A8 802B7498 3C020200 */   lui      $v0, 0x200
/* E205AC 802B749C 0C0441A9 */  jal       get_entity_type
/* E205B0 802B74A0 0080802D */   daddu    $s0, $a0, $zero
/* E205B4 802B74A4 2443FFFD */  addiu     $v1, $v0, -3
/* E205B8 802B74A8 2C620031 */  sltiu     $v0, $v1, 0x31
/* E205BC 802B74AC 10400038 */  beqz      $v0, .L802B7590
/* E205C0 802B74B0 00031080 */   sll      $v0, $v1, 2
/* E205C4 802B74B4 3C01802B */  lui       $at, %hi(jtbl_802B7CC0_E20DD0)
/* E205C8 802B74B8 00220821 */  addu      $at, $at, $v0
/* E205CC 802B74BC 8C227CC0 */  lw        $v0, %lo(jtbl_802B7CC0_E20DD0)($at)
/* E205D0 802B74C0 00400008 */  jr        $v0
/* E205D4 802B74C4 00000000 */   nop
glabel L802B74C8_E205D8
/* E205D8 802B74C8 080ADD64 */  j         .L802B7590
/* E205DC 802B74CC 2410FFFF */   addiu    $s0, $zero, -1
.L802B74D0:
/* E205E0 802B74D0 3C020200 */  lui       $v0, 0x200
.L802B74D4:
/* E205E4 802B74D4 8E230000 */  lw        $v1, ($s1)
/* E205E8 802B74D8 34422000 */  ori       $v0, $v0, 0x2000
/* E205EC 802B74DC 00621824 */  and       $v1, $v1, $v0
/* E205F0 802B74E0 3C020200 */  lui       $v0, 0x200
/* E205F4 802B74E4 1462000F */  bne       $v1, $v0, .L802B7524
/* E205F8 802B74E8 3C03F7FF */   lui      $v1, 0xf7ff
/* E205FC 802B74EC 10A0000C */  beqz      $a1, .L802B7520
/* E20600 802B74F0 3C031000 */   lui      $v1, 0x1000
/* E20604 802B74F4 8CA20000 */  lw        $v0, ($a1)
/* E20608 802B74F8 00431024 */  and       $v0, $v0, $v1
/* E2060C 802B74FC 10400009 */  beqz      $v0, .L802B7524
/* E20610 802B7500 3C03F7FF */   lui      $v1, 0xf7ff
/* E20614 802B7504 80A200A4 */  lb        $v0, 0xa4($a1)
/* E20618 802B7508 862300C6 */  lh        $v1, 0xc6($s1)
/* E2061C 802B750C 34502000 */  ori       $s0, $v0, 0x2000
/* E20620 802B7510 14700029 */  bne       $v1, $s0, .L802B75B8
/* E20624 802B7514 3C03F7FF */   lui      $v1, 0xf7ff
/* E20628 802B7518 080ADD74 */  j         .L802B75D0
/* E2062C 802B751C 24020001 */   addiu    $v0, $zero, 1
.L802B7520:
/* E20630 802B7520 3C03F7FF */  lui       $v1, 0xf7ff
.L802B7524:
/* E20634 802B7524 3463FFFF */  ori       $v1, $v1, 0xffff
/* E20638 802B7528 0000102D */  daddu     $v0, $zero, $zero
/* E2063C 802B752C 8E240000 */  lw        $a0, ($s1)
/* E20640 802B7530 2405FFFF */  addiu     $a1, $zero, -1
/* E20644 802B7534 A62500C6 */  sh        $a1, 0xc6($s1)
/* E20648 802B7538 00832024 */  and       $a0, $a0, $v1
/* E2064C 802B753C 080ADD74 */  j         .L802B75D0
/* E20650 802B7540 AE240000 */   sw       $a0, ($s1)
.L802B7544:
/* E20654 802B7544 14400007 */  bnez      $v0, .L802B7564
/* E20658 802B7548 32022000 */   andi     $v0, $s0, 0x2000
/* E2065C 802B754C 14400010 */  bnez      $v0, .L802B7590
/* E20660 802B7550 00000000 */   nop
/* E20664 802B7554 0C05173A */  jal       func_80145CE8
/* E20668 802B7558 0200202D */   daddu    $a0, $s0, $zero
/* E2066C 802B755C 080ADD5B */  j         .L802B756C
/* E20670 802B7560 00000000 */   nop
.L802B7564:
/* E20674 802B7564 0C0394BE */  jal       func_800E52F8
/* E20678 802B7568 00000000 */   nop
.L802B756C:
/* E2067C 802B756C 14400008 */  bnez      $v0, .L802B7590
/* E20680 802B7570 3C04F7FF */   lui      $a0, 0xf7ff
/* E20684 802B7574 3484FFFF */  ori       $a0, $a0, 0xffff
/* E20688 802B7578 8E230000 */  lw        $v1, ($s1)
/* E2068C 802B757C 0000102D */  daddu     $v0, $zero, $zero
/* E20690 802B7580 A63200C6 */  sh        $s2, 0xc6($s1)
/* E20694 802B7584 00641824 */  and       $v1, $v1, $a0
/* E20698 802B7588 080ADD74 */  j         .L802B75D0
/* E2069C 802B758C AE230000 */   sw       $v1, ($s1)
.L802B7590:
glabel L802B7590_E206A0
/* E206A0 802B7590 862200C6 */  lh        $v0, 0xc6($s1)
/* E206A4 802B7594 14500008 */  bne       $v0, $s0, .L802B75B8
/* E206A8 802B7598 3C03F7FF */   lui      $v1, 0xf7ff
/* E206AC 802B759C 8E220000 */  lw        $v0, ($s1)
/* E206B0 802B75A0 3C030800 */  lui       $v1, 0x800
/* E206B4 802B75A4 00431024 */  and       $v0, $v0, $v1
/* E206B8 802B75A8 10400007 */  beqz      $v0, .L802B75C8
/* E206BC 802B75AC 0000102D */   daddu    $v0, $zero, $zero
/* E206C0 802B75B0 080ADD74 */  j         .L802B75D0
/* E206C4 802B75B4 00000000 */   nop
.L802B75B8:
/* E206C8 802B75B8 8E220000 */  lw        $v0, ($s1)
/* E206CC 802B75BC 3463FFFF */  ori       $v1, $v1, 0xffff
/* E206D0 802B75C0 00431024 */  and       $v0, $v0, $v1
/* E206D4 802B75C4 AE220000 */  sw        $v0, ($s1)
.L802B75C8:
/* E206D8 802B75C8 A63000C6 */  sh        $s0, 0xc6($s1)
/* E206DC 802B75CC 24020001 */  addiu     $v0, $zero, 1
.L802B75D0:
/* E206E0 802B75D0 8FBF001C */  lw        $ra, 0x1c($sp)
/* E206E4 802B75D4 8FB20018 */  lw        $s2, 0x18($sp)
/* E206E8 802B75D8 8FB10014 */  lw        $s1, 0x14($sp)
/* E206EC 802B75DC 8FB00010 */  lw        $s0, 0x10($sp)
/* E206F0 802B75E0 03E00008 */  jr        $ra
/* E206F4 802B75E4 27BD0020 */   addiu    $sp, $sp, 0x20
