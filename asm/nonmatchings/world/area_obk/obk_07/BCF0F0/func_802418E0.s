.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418E0
/* BD04D0 802418E0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BD04D4 802418E4 AFB20018 */  sw        $s2, 0x18($sp)
/* BD04D8 802418E8 0080902D */  daddu     $s2, $a0, $zero
/* BD04DC 802418EC AFBF001C */  sw        $ra, 0x1c($sp)
/* BD04E0 802418F0 AFB10014 */  sw        $s1, 0x14($sp)
/* BD04E4 802418F4 AFB00010 */  sw        $s0, 0x10($sp)
/* BD04E8 802418F8 F7BE0048 */  sdc1      $f30, 0x48($sp)
/* BD04EC 802418FC F7BC0040 */  sdc1      $f28, 0x40($sp)
/* BD04F0 80241900 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* BD04F4 80241904 F7B80030 */  sdc1      $f24, 0x30($sp)
/* BD04F8 80241908 F7B60028 */  sdc1      $f22, 0x28($sp)
/* BD04FC 8024190C F7B40020 */  sdc1      $f20, 0x20($sp)
/* BD0500 80241910 0C00EABB */  jal       get_npc_unsafe
/* BD0504 80241914 24040002 */   addiu    $a0, $zero, 2
/* BD0508 80241918 0C090150 */  jal       func_80240540
/* BD050C 8024191C 0040802D */   daddu    $s0, $v0, $zero
/* BD0510 80241920 0040882D */  daddu     $s1, $v0, $zero
/* BD0514 80241924 2403FFFF */  addiu     $v1, $zero, -1
/* BD0518 80241928 3C01C308 */  lui       $at, 0xc308
/* BD051C 8024192C 4481D000 */  mtc1      $at, $f26
/* BD0520 80241930 C6160038 */  lwc1      $f22, 0x38($s0)
/* BD0524 80241934 C6180040 */  lwc1      $f24, 0x40($s0)
/* BD0528 80241938 3C01C2B8 */  lui       $at, 0xc2b8
/* BD052C 8024193C 4481F000 */  mtc1      $at, $f30
/* BD0530 80241940 8E220030 */  lw        $v0, 0x30($s1)
/* BD0534 80241944 3C014328 */  lui       $at, 0x4328
/* BD0538 80241948 4481E000 */  mtc1      $at, $f28
/* BD053C 8024194C 14430025 */  bne       $v0, $v1, .L802419E4
/* BD0540 80241950 3C020095 */   lui      $v0, 0x95
/* BD0544 80241954 34420003 */  ori       $v0, $v0, 3
/* BD0548 80241958 4600B306 */  mov.s     $f12, $f22
/* BD054C 8024195C 3C014000 */  lui       $at, 0x4000
/* BD0550 80241960 4481A000 */  mtc1      $at, $f20
/* BD0554 80241964 4406E000 */  mfc1      $a2, $f28
/* BD0558 80241968 4407D000 */  mfc1      $a3, $f26
/* BD055C 8024196C 4600C386 */  mov.s     $f14, $f24
/* BD0560 80241970 0C00A7B5 */  jal       dist2D
/* BD0564 80241974 AE020028 */   sw       $v0, 0x28($s0)
/* BD0568 80241978 4614003C */  c.lt.s    $f0, $f20
/* BD056C 8024197C 00000000 */  nop       
/* BD0570 80241980 4500000D */  bc1f      .L802419B8
/* BD0574 80241984 4600B306 */   mov.s    $f12, $f22
/* BD0578 80241988 4406F000 */  mfc1      $a2, $f30
/* BD057C 8024198C 4407D000 */  mfc1      $a3, $f26
/* BD0580 80241990 4600C386 */  mov.s     $f14, $f24
/* BD0584 80241994 E61C0038 */  swc1      $f28, 0x38($s0)
/* BD0588 80241998 0C00A720 */  jal       atan2
/* BD058C 8024199C AE070040 */   sw       $a3, 0x40($s0)
/* BD0590 802419A0 24020002 */  addiu     $v0, $zero, 2
/* BD0594 802419A4 24030001 */  addiu     $v1, $zero, 1
/* BD0598 802419A8 E600000C */  swc1      $f0, 0xc($s0)
/* BD059C 802419AC AE4000AC */  sw        $zero, 0xac($s2)
/* BD05A0 802419B0 080906C8 */  j         .L80241B20
/* BD05A4 802419B4 AE4300B0 */   sw       $v1, 0xb0($s2)
.L802419B8:
/* BD05A8 802419B8 4406E000 */  mfc1      $a2, $f28
/* BD05AC 802419BC 4407D000 */  mfc1      $a3, $f26
/* BD05B0 802419C0 0C00A720 */  jal       atan2
/* BD05B4 802419C4 4600C386 */   mov.s    $f14, $f24
/* BD05B8 802419C8 4405A000 */  mfc1      $a1, $f20
/* BD05BC 802419CC 44060000 */  mfc1      $a2, $f0
/* BD05C0 802419D0 0200202D */  daddu     $a0, $s0, $zero
/* BD05C4 802419D4 0C00EA95 */  jal       npc_move_heading
/* BD05C8 802419D8 AC86000C */   sw       $a2, 0xc($a0)
/* BD05CC 802419DC 080906C8 */  j         .L80241B20
/* BD05D0 802419E0 24020002 */   addiu    $v0, $zero, 2
.L802419E4:
/* BD05D4 802419E4 8E2201D4 */  lw        $v0, 0x1d4($s1)
/* BD05D8 802419E8 28421B59 */  slti      $v0, $v0, 0x1b59
/* BD05DC 802419EC 14400019 */  bnez      $v0, .L80241A54
/* BD05E0 802419F0 4600B306 */   mov.s    $f12, $f22
/* BD05E4 802419F4 4600C386 */  mov.s     $f14, $f24
/* BD05E8 802419F8 3C014000 */  lui       $at, 0x4000
/* BD05EC 802419FC 4481A000 */  mtc1      $at, $f20
/* BD05F0 80241A00 4406F000 */  mfc1      $a2, $f30
/* BD05F4 80241A04 4407D000 */  mfc1      $a3, $f26
/* BD05F8 80241A08 24020001 */  addiu     $v0, $zero, 1
/* BD05FC 80241A0C 0C00A7B5 */  jal       dist2D
/* BD0600 80241A10 AE4200AC */   sw       $v0, 0xac($s2)
/* BD0604 80241A14 4614003C */  c.lt.s    $f0, $f20
/* BD0608 80241A18 00000000 */  nop       
/* BD060C 80241A1C 45000004 */  bc1f      .L80241A30
/* BD0610 80241A20 4600B306 */   mov.s    $f12, $f22
/* BD0614 80241A24 E61E0038 */  swc1      $f30, 0x38($s0)
/* BD0618 80241A28 08090695 */  j         .L80241A54
/* BD061C 80241A2C E61A0040 */   swc1     $f26, 0x40($s0)
.L80241A30:
/* BD0620 80241A30 4406F000 */  mfc1      $a2, $f30
/* BD0624 80241A34 4407D000 */  mfc1      $a3, $f26
/* BD0628 80241A38 0C00A720 */  jal       atan2
/* BD062C 80241A3C 4600C386 */   mov.s    $f14, $f24
/* BD0630 80241A40 4405A000 */  mfc1      $a1, $f20
/* BD0634 80241A44 44060000 */  mfc1      $a2, $f0
/* BD0638 80241A48 0200202D */  daddu     $a0, $s0, $zero
/* BD063C 80241A4C 0C00EA95 */  jal       npc_move_heading
/* BD0640 80241A50 AE06000C */   sw       $a2, 0xc($s0)
.L80241A54:
/* BD0644 80241A54 8E2201D4 */  lw        $v0, 0x1d4($s1)
/* BD0648 80241A58 28420BB8 */  slti      $v0, $v0, 0xbb8
/* BD064C 80241A5C 1040001D */  beqz      $v0, .L80241AD4
/* BD0650 80241A60 4600B306 */   mov.s    $f12, $f22
/* BD0654 80241A64 3C014000 */  lui       $at, 0x4000
/* BD0658 80241A68 4481A000 */  mtc1      $at, $f20
/* BD065C 80241A6C 4406E000 */  mfc1      $a2, $f28
/* BD0660 80241A70 4407D000 */  mfc1      $a3, $f26
/* BD0664 80241A74 4600C386 */  mov.s     $f14, $f24
/* BD0668 80241A78 0C00A7B5 */  jal       dist2D
/* BD066C 80241A7C AE4000AC */   sw       $zero, 0xac($s2)
/* BD0670 80241A80 4614003C */  c.lt.s    $f0, $f20
/* BD0674 80241A84 00000000 */  nop       
/* BD0678 80241A88 45000009 */  bc1f      .L80241AB0
/* BD067C 80241A8C 4600B306 */   mov.s    $f12, $f22
/* BD0680 80241A90 4406F000 */  mfc1      $a2, $f30
/* BD0684 80241A94 3C07C308 */  lui       $a3, 0xc308
/* BD0688 80241A98 4600C386 */  mov.s     $f14, $f24
/* BD068C 80241A9C E61C0038 */  swc1      $f28, 0x38($s0)
/* BD0690 80241AA0 0C00A720 */  jal       atan2
/* BD0694 80241AA4 E61A0040 */   swc1     $f26, 0x40($s0)
/* BD0698 80241AA8 080906B5 */  j         .L80241AD4
/* BD069C 80241AAC E600000C */   swc1     $f0, 0xc($s0)
.L80241AB0:
/* BD06A0 80241AB0 4406E000 */  mfc1      $a2, $f28
/* BD06A4 80241AB4 4407D000 */  mfc1      $a3, $f26
/* BD06A8 80241AB8 0C00A720 */  jal       atan2
/* BD06AC 80241ABC 4600C386 */   mov.s    $f14, $f24
/* BD06B0 80241AC0 4405A000 */  mfc1      $a1, $f20
/* BD06B4 80241AC4 44060000 */  mfc1      $a2, $f0
/* BD06B8 80241AC8 0200202D */  daddu     $a0, $s0, $zero
/* BD06BC 80241ACC 0C00EA95 */  jal       npc_move_heading
/* BD06C0 80241AD0 AE06000C */   sw       $a2, 0xc($s0)
.L80241AD4:
/* BD06C4 80241AD4 8E2301D4 */  lw        $v1, 0x1d4($s1)
/* BD06C8 80241AD8 28621B59 */  slti      $v0, $v1, 0x1b59
/* BD06CC 80241ADC 54400004 */  bnel      $v0, $zero, .L80241AF0
/* BD06D0 80241AE0 28621389 */   slti     $v0, $v1, 0x1389
/* BD06D4 80241AE4 3C020095 */  lui       $v0, 0x95
/* BD06D8 80241AE8 080906C6 */  j         .L80241B18
/* BD06DC 80241AEC 34420005 */   ori      $v0, $v0, 5
.L80241AF0:
/* BD06E0 80241AF0 54400004 */  bnel      $v0, $zero, .L80241B04
/* BD06E4 80241AF4 28620BB9 */   slti     $v0, $v1, 0xbb9
/* BD06E8 80241AF8 3C020095 */  lui       $v0, 0x95
/* BD06EC 80241AFC 080906C6 */  j         .L80241B18
/* BD06F0 80241B00 34420003 */   ori      $v0, $v0, 3
.L80241B04:
/* BD06F4 80241B04 14400003 */  bnez      $v0, .L80241B14
/* BD06F8 80241B08 3C020095 */   lui      $v0, 0x95
/* BD06FC 80241B0C 080906C6 */  j         .L80241B18
/* BD0700 80241B10 34420002 */   ori      $v0, $v0, 2
.L80241B14:
/* BD0704 80241B14 34420001 */  ori       $v0, $v0, 1
.L80241B18:
/* BD0708 80241B18 AE020028 */  sw        $v0, 0x28($s0)
/* BD070C 80241B1C 24020002 */  addiu     $v0, $zero, 2
.L80241B20:
/* BD0710 80241B20 8FBF001C */  lw        $ra, 0x1c($sp)
/* BD0714 80241B24 8FB20018 */  lw        $s2, 0x18($sp)
/* BD0718 80241B28 8FB10014 */  lw        $s1, 0x14($sp)
/* BD071C 80241B2C 8FB00010 */  lw        $s0, 0x10($sp)
/* BD0720 80241B30 D7BE0048 */  ldc1      $f30, 0x48($sp)
/* BD0724 80241B34 D7BC0040 */  ldc1      $f28, 0x40($sp)
/* BD0728 80241B38 D7BA0038 */  ldc1      $f26, 0x38($sp)
/* BD072C 80241B3C D7B80030 */  ldc1      $f24, 0x30($sp)
/* BD0730 80241B40 D7B60028 */  ldc1      $f22, 0x28($sp)
/* BD0734 80241B44 D7B40020 */  ldc1      $f20, 0x20($sp)
/* BD0738 80241B48 03E00008 */  jr        $ra
/* BD073C 80241B4C 27BD0050 */   addiu    $sp, $sp, 0x50
