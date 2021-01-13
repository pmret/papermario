.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6820_E256F0
/* E256F0 802B6820 27BDFF88 */  addiu     $sp, $sp, -0x78
/* E256F4 802B6824 AFB20040 */  sw        $s2, 0x40($sp)
/* E256F8 802B6828 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* E256FC 802B682C 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* E25700 802B6830 AFBF004C */  sw        $ra, 0x4c($sp)
/* E25704 802B6834 AFB40048 */  sw        $s4, 0x48($sp)
/* E25708 802B6838 AFB30044 */  sw        $s3, 0x44($sp)
/* E2570C 802B683C AFB1003C */  sw        $s1, 0x3c($sp)
/* E25710 802B6840 AFB00038 */  sw        $s0, 0x38($sp)
/* E25714 802B6844 F7BC0070 */  sdc1      $f28, 0x70($sp)
/* E25718 802B6848 F7BA0068 */  sdc1      $f26, 0x68($sp)
/* E2571C 802B684C F7B80060 */  sdc1      $f24, 0x60($sp)
/* E25720 802B6850 F7B60058 */  sdc1      $f22, 0x58($sp)
/* E25724 802B6854 F7B40050 */  sdc1      $f20, 0x50($sp)
/* E25728 802B6858 3C148016 */  lui       $s4, %hi(gCollisionStatus)
/* E2572C 802B685C 2694A550 */  addiu     $s4, $s4, %lo(gCollisionStatus)
/* E25730 802B6860 0C0394D2 */  jal       func_800E5348
/* E25734 802B6864 00000000 */   nop
/* E25738 802B6868 8E4400A4 */  lw        $a0, 0xa4($s2)
/* E2573C 802B686C 0C0AD800 */  jal       func_802B6000_E24ED0
/* E25740 802B6870 46000586 */   mov.s    $f22, $f0
/* E25744 802B6874 10400024 */  beqz      $v0, .L802B6908
/* E25748 802B6878 27A50020 */   addiu    $a1, $sp, 0x20
/* E2574C 802B687C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* E25750 802B6880 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* E25754 802B6884 3C0142B4 */  lui       $at, 0x42b4
/* E25758 802B6888 4481A000 */  mtc1      $at, $f20
/* E2575C 802B688C 00031080 */  sll       $v0, $v1, 2
/* E25760 802B6890 00431021 */  addu      $v0, $v0, $v1
/* E25764 802B6894 00021080 */  sll       $v0, $v0, 2
/* E25768 802B6898 00431023 */  subu      $v0, $v0, $v1
/* E2576C 802B689C 000218C0 */  sll       $v1, $v0, 3
/* E25770 802B68A0 00431021 */  addu      $v0, $v0, $v1
/* E25774 802B68A4 000210C0 */  sll       $v0, $v0, 3
/* E25778 802B68A8 4614B000 */  add.s     $f0, $f22, $f20
/* E2577C 802B68AC 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* E25780 802B68B0 00220821 */  addu      $at, $at, $v0
/* E25784 802B68B4 C42C1DEC */  lwc1      $f12, %lo(D_800B1DEC)($at)
/* E25788 802B68B8 0C00A6C9 */  jal       clamp_angle
/* E2578C 802B68BC 460C0301 */   sub.s    $f12, $f0, $f12
/* E25790 802B68C0 46000086 */  mov.s     $f2, $f0
/* E25794 802B68C4 4602A03E */  c.le.s    $f20, $f2
/* E25798 802B68C8 00000000 */  nop
/* E2579C 802B68CC 45000009 */  bc1f      .L802B68F4
/* E257A0 802B68D0 00000000 */   nop
/* E257A4 802B68D4 3C014387 */  lui       $at, 0x4387
/* E257A8 802B68D8 44810000 */  mtc1      $at, $f0
/* E257AC 802B68DC 00000000 */  nop
/* E257B0 802B68E0 4600103C */  c.lt.s    $f2, $f0
/* E257B4 802B68E4 3C01C1F0 */  lui       $at, 0xc1f0
/* E257B8 802B68E8 44810000 */  mtc1      $at, $f0
/* E257BC 802B68EC 45030005 */  bc1tl     .L802B6904
/* E257C0 802B68F0 4600B580 */   add.s    $f22, $f22, $f0
.L802B68F4:
/* E257C4 802B68F4 3C0141F0 */  lui       $at, 0x41f0
/* E257C8 802B68F8 44810000 */  mtc1      $at, $f0
/* E257CC 802B68FC 00000000 */  nop
/* E257D0 802B6900 4600B580 */  add.s     $f22, $f22, $f0
.L802B6904:
/* E257D4 802B6904 27A50020 */  addiu     $a1, $sp, 0x20
.L802B6908:
/* E257D8 802B6908 3C0140C9 */  lui       $at, 0x40c9
/* E257DC 802B690C 34210FD0 */  ori       $at, $at, 0xfd0
/* E257E0 802B6910 44816000 */  mtc1      $at, $f12
/* E257E4 802B6914 27A60024 */  addiu     $a2, $sp, 0x24
/* E257E8 802B6918 460CB302 */  mul.s     $f12, $f22, $f12
/* E257EC 802B691C 00000000 */  nop
/* E257F0 802B6920 24110001 */  addiu     $s1, $zero, 1
/* E257F4 802B6924 27B30030 */  addiu     $s3, $sp, 0x30
/* E257F8 802B6928 3C0143B4 */  lui       $at, 0x43b4
/* E257FC 802B692C 44810000 */  mtc1      $at, $f0
/* E25800 802B6930 3C014080 */  lui       $at, 0x4080
/* E25804 802B6934 4481A000 */  mtc1      $at, $f20
/* E25808 802B6938 0C00A82D */  jal       sin_cos_rad
/* E2580C 802B693C 46006303 */   div.s    $f12, $f12, $f0
/* E25810 802B6940 C65C0028 */  lwc1      $f28, 0x28($s2)
/* E25814 802B6944 C65A002C */  lwc1      $f26, 0x2c($s2)
/* E25818 802B6948 C6580030 */  lwc1      $f24, 0x30($s2)
.L802B694C:
/* E2581C 802B694C C7A40020 */  lwc1      $f4, 0x20($sp)
/* E25820 802B6950 44910000 */  mtc1      $s1, $f0
/* E25824 802B6954 00000000 */  nop
/* E25828 802B6958 46800020 */  cvt.s.w   $f0, $f0
/* E2582C 802B695C 46002102 */  mul.s     $f4, $f4, $f0
/* E25830 802B6960 00000000 */  nop
/* E25834 802B6964 C7A20024 */  lwc1      $f2, 0x24($sp)
/* E25838 802B6968 46001082 */  mul.s     $f2, $f2, $f0
/* E2583C 802B696C 00000000 */  nop
/* E25840 802B6970 24040003 */  addiu     $a0, $zero, 3
/* E25844 802B6974 0240282D */  daddu     $a1, $s2, $zero
/* E25848 802B6978 4604E100 */  add.s     $f4, $f28, $f4
/* E2584C 802B697C 27A60028 */  addiu     $a2, $sp, 0x28
/* E25850 802B6980 27A7002C */  addiu     $a3, $sp, 0x2c
/* E25854 802B6984 4602C081 */  sub.s     $f2, $f24, $f2
/* E25858 802B6988 E7BA002C */  swc1      $f26, 0x2c($sp)
/* E2585C 802B698C E7A40028 */  swc1      $f4, 0x28($sp)
/* E25860 802B6990 E7A20030 */  swc1      $f2, 0x30($sp)
/* E25864 802B6994 AFB30010 */  sw        $s3, 0x10($sp)
/* E25868 802B6998 E7B40014 */  swc1      $f20, 0x14($sp)
/* E2586C 802B699C 0C037B01 */  jal       do_lateral_collision
/* E25870 802B69A0 E7B60018 */   swc1     $f22, 0x18($sp)
/* E25874 802B69A4 3C03802B */  lui       $v1, %hi(D_802B6DB0)
/* E25878 802B69A8 8C636DB0 */  lw        $v1, %lo(D_802B6DB0)($v1)
/* E2587C 802B69AC 8C630014 */  lw        $v1, 0x14($v1)
/* E25880 802B69B0 14600009 */  bnez      $v1, .L802B69D8
/* E25884 802B69B4 0040802D */   daddu    $s0, $v0, $zero
/* E25888 802B69B8 06000009 */  bltz      $s0, .L802B69E0
/* E2588C 802B69BC A6900014 */   sh       $s0, 0x14($s4)
/* E25890 802B69C0 32024000 */  andi      $v0, $s0, 0x4000
/* E25894 802B69C4 10400004 */  beqz      $v0, .L802B69D8
/* E25898 802B69C8 00000000 */   nop
/* E2589C 802B69CC 0C04417A */  jal       get_entity_by_index
/* E258A0 802B69D0 0200202D */   daddu    $a0, $s0, $zero
/* E258A4 802B69D4 A0400007 */  sb        $zero, 7($v0)
.L802B69D8:
/* E258A8 802B69D8 06010005 */  bgez      $s0, .L802B69F0
/* E258AC 802B69DC 2A220010 */   slti     $v0, $s1, 0x10
.L802B69E0:
/* E258B0 802B69E0 26310001 */  addiu     $s1, $s1, 1
/* E258B4 802B69E4 2A220010 */  slti      $v0, $s1, 0x10
/* E258B8 802B69E8 1440FFD8 */  bnez      $v0, .L802B694C
/* E258BC 802B69EC 00000000 */   nop
.L802B69F0:
/* E258C0 802B69F0 14400062 */  bnez      $v0, .L802B6B7C
/* E258C4 802B69F4 00000000 */   nop
/* E258C8 802B69F8 0C0394D2 */  jal       func_800E5348
/* E258CC 802B69FC 00000000 */   nop
/* E258D0 802B6A00 8E4400A4 */  lw        $a0, 0xa4($s2)
/* E258D4 802B6A04 0C0AD800 */  jal       func_802B6000_E24ED0
/* E258D8 802B6A08 46000586 */   mov.s    $f22, $f0
/* E258DC 802B6A0C 14400024 */  bnez      $v0, .L802B6AA0
/* E258E0 802B6A10 27A50020 */   addiu    $a1, $sp, 0x20
/* E258E4 802B6A14 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* E258E8 802B6A18 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* E258EC 802B6A1C 3C0142B4 */  lui       $at, 0x42b4
/* E258F0 802B6A20 4481A000 */  mtc1      $at, $f20
/* E258F4 802B6A24 00031080 */  sll       $v0, $v1, 2
/* E258F8 802B6A28 00431021 */  addu      $v0, $v0, $v1
/* E258FC 802B6A2C 00021080 */  sll       $v0, $v0, 2
/* E25900 802B6A30 00431023 */  subu      $v0, $v0, $v1
/* E25904 802B6A34 000218C0 */  sll       $v1, $v0, 3
/* E25908 802B6A38 00431021 */  addu      $v0, $v0, $v1
/* E2590C 802B6A3C 000210C0 */  sll       $v0, $v0, 3
/* E25910 802B6A40 4614B000 */  add.s     $f0, $f22, $f20
/* E25914 802B6A44 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* E25918 802B6A48 00220821 */  addu      $at, $at, $v0
/* E2591C 802B6A4C C42C1DEC */  lwc1      $f12, %lo(D_800B1DEC)($at)
/* E25920 802B6A50 0C00A6C9 */  jal       clamp_angle
/* E25924 802B6A54 460C0301 */   sub.s    $f12, $f0, $f12
/* E25928 802B6A58 46000086 */  mov.s     $f2, $f0
/* E2592C 802B6A5C 4602A03E */  c.le.s    $f20, $f2
/* E25930 802B6A60 00000000 */  nop
/* E25934 802B6A64 45000009 */  bc1f      .L802B6A8C
/* E25938 802B6A68 00000000 */   nop
/* E2593C 802B6A6C 3C014387 */  lui       $at, 0x4387
/* E25940 802B6A70 44810000 */  mtc1      $at, $f0
/* E25944 802B6A74 00000000 */  nop
/* E25948 802B6A78 4600103C */  c.lt.s    $f2, $f0
/* E2594C 802B6A7C 3C014170 */  lui       $at, 0x4170
/* E25950 802B6A80 44810000 */  mtc1      $at, $f0
/* E25954 802B6A84 45030005 */  bc1tl     .L802B6A9C
/* E25958 802B6A88 4600B580 */   add.s    $f22, $f22, $f0
.L802B6A8C:
/* E2595C 802B6A8C 3C01C170 */  lui       $at, 0xc170
/* E25960 802B6A90 44810000 */  mtc1      $at, $f0
/* E25964 802B6A94 00000000 */  nop
/* E25968 802B6A98 4600B580 */  add.s     $f22, $f22, $f0
.L802B6A9C:
/* E2596C 802B6A9C 27A50020 */  addiu     $a1, $sp, 0x20
.L802B6AA0:
/* E25970 802B6AA0 3C0140C9 */  lui       $at, 0x40c9
/* E25974 802B6AA4 34210FD0 */  ori       $at, $at, 0xfd0
/* E25978 802B6AA8 44816000 */  mtc1      $at, $f12
/* E2597C 802B6AAC 27A60024 */  addiu     $a2, $sp, 0x24
/* E25980 802B6AB0 460CB302 */  mul.s     $f12, $f22, $f12
/* E25984 802B6AB4 00000000 */  nop
/* E25988 802B6AB8 24110001 */  addiu     $s1, $zero, 1
/* E2598C 802B6ABC 27B30030 */  addiu     $s3, $sp, 0x30
/* E25990 802B6AC0 3C0143B4 */  lui       $at, 0x43b4
/* E25994 802B6AC4 44810000 */  mtc1      $at, $f0
/* E25998 802B6AC8 3C014080 */  lui       $at, 0x4080
/* E2599C 802B6ACC 4481A000 */  mtc1      $at, $f20
/* E259A0 802B6AD0 0C00A82D */  jal       sin_cos_rad
/* E259A4 802B6AD4 46006303 */   div.s    $f12, $f12, $f0
.L802B6AD8:
/* E259A8 802B6AD8 C7A40020 */  lwc1      $f4, 0x20($sp)
/* E259AC 802B6ADC 44910000 */  mtc1      $s1, $f0
/* E259B0 802B6AE0 00000000 */  nop
/* E259B4 802B6AE4 46800020 */  cvt.s.w   $f0, $f0
/* E259B8 802B6AE8 46002102 */  mul.s     $f4, $f4, $f0
/* E259BC 802B6AEC 00000000 */  nop
/* E259C0 802B6AF0 C7A20024 */  lwc1      $f2, 0x24($sp)
/* E259C4 802B6AF4 46001082 */  mul.s     $f2, $f2, $f0
/* E259C8 802B6AF8 00000000 */  nop
/* E259CC 802B6AFC 24040003 */  addiu     $a0, $zero, 3
/* E259D0 802B6B00 0240282D */  daddu     $a1, $s2, $zero
/* E259D4 802B6B04 4604E100 */  add.s     $f4, $f28, $f4
/* E259D8 802B6B08 27A60028 */  addiu     $a2, $sp, 0x28
/* E259DC 802B6B0C 27A7002C */  addiu     $a3, $sp, 0x2c
/* E259E0 802B6B10 4602C081 */  sub.s     $f2, $f24, $f2
/* E259E4 802B6B14 E7BA002C */  swc1      $f26, 0x2c($sp)
/* E259E8 802B6B18 E7A40028 */  swc1      $f4, 0x28($sp)
/* E259EC 802B6B1C E7A20030 */  swc1      $f2, 0x30($sp)
/* E259F0 802B6B20 AFB30010 */  sw        $s3, 0x10($sp)
/* E259F4 802B6B24 E7B40014 */  swc1      $f20, 0x14($sp)
/* E259F8 802B6B28 0C037B01 */  jal       do_lateral_collision
/* E259FC 802B6B2C E7B60018 */   swc1     $f22, 0x18($sp)
/* E25A00 802B6B30 3C03802B */  lui       $v1, %hi(D_802B6DB0)
/* E25A04 802B6B34 8C636DB0 */  lw        $v1, %lo(D_802B6DB0)($v1)
/* E25A08 802B6B38 8C630014 */  lw        $v1, 0x14($v1)
/* E25A0C 802B6B3C 14600009 */  bnez      $v1, .L802B6B64
/* E25A10 802B6B40 0040802D */   daddu    $s0, $v0, $zero
/* E25A14 802B6B44 06000009 */  bltz      $s0, .L802B6B6C
/* E25A18 802B6B48 A6900014 */   sh       $s0, 0x14($s4)
/* E25A1C 802B6B4C 32024000 */  andi      $v0, $s0, 0x4000
/* E25A20 802B6B50 10400004 */  beqz      $v0, .L802B6B64
/* E25A24 802B6B54 00000000 */   nop
/* E25A28 802B6B58 0C04417A */  jal       get_entity_by_index
/* E25A2C 802B6B5C 0200202D */   daddu    $a0, $s0, $zero
/* E25A30 802B6B60 A0400007 */  sb        $zero, 7($v0)
.L802B6B64:
/* E25A34 802B6B64 06010005 */  bgez      $s0, .L802B6B7C
/* E25A38 802B6B68 00000000 */   nop
.L802B6B6C:
/* E25A3C 802B6B6C 26310001 */  addiu     $s1, $s1, 1
/* E25A40 802B6B70 2A220010 */  slti      $v0, $s1, 0x10
/* E25A44 802B6B74 1440FFD8 */  bnez      $v0, .L802B6AD8
/* E25A48 802B6B78 00000000 */   nop
.L802B6B7C:
/* E25A4C 802B6B7C 3C02802B */  lui       $v0, %hi(D_802B6DB0)
/* E25A50 802B6B80 8C426DB0 */  lw        $v0, %lo(D_802B6DB0)($v0)
/* E25A54 802B6B84 8C440018 */  lw        $a0, 0x18($v0)
/* E25A58 802B6B88 24020002 */  addiu     $v0, $zero, 2
/* E25A5C 802B6B8C 14820032 */  bne       $a0, $v0, .L802B6C58
/* E25A60 802B6B90 00000000 */   nop
/* E25A64 802B6B94 3C038011 */  lui       $v1, %hi(gPlayerData+0x1)
/* E25A68 802B6B98 8063F291 */  lb        $v1, %lo(gPlayerData+0x1)($v1)
/* E25A6C 802B6B9C 14640003 */  bne       $v1, $a0, .L802B6BAC
/* E25A70 802B6BA0 24020001 */   addiu    $v0, $zero, 1
/* E25A74 802B6BA4 080ADAEE */  j         .L802B6BB8
/* E25A78 802B6BA8 24042117 */   addiu    $a0, $zero, 0x2117
.L802B6BAC:
/* E25A7C 802B6BAC 14620002 */  bne       $v1, $v0, .L802B6BB8
/* E25A80 802B6BB0 24042115 */   addiu    $a0, $zero, 0x2115
/* E25A84 802B6BB4 24042116 */  addiu     $a0, $zero, 0x2116
.L802B6BB8:
/* E25A88 802B6BB8 0C052736 */  jal       play_sound_at_player
/* E25A8C 802B6BBC 0000282D */   daddu    $a1, $zero, $zero
/* E25A90 802B6BC0 3C02802B */  lui       $v0, %hi(D_802B6DB0)
/* E25A94 802B6BC4 8C426DB0 */  lw        $v0, %lo(D_802B6DB0)($v0)
/* E25A98 802B6BC8 0C0AD812 */  jal       func_802B6048_E24F18
/* E25A9C 802B6BCC 8C440010 */   lw       $a0, 0x10($v0)
/* E25AA0 802B6BD0 86840014 */  lh        $a0, 0x14($s4)
/* E25AA4 802B6BD4 96820014 */  lhu       $v0, 0x14($s4)
/* E25AA8 802B6BD8 04800007 */  bltz      $a0, .L802B6BF8
/* E25AAC 802B6BDC 30424000 */   andi     $v0, $v0, 0x4000
/* E25AB0 802B6BE0 10400005 */  beqz      $v0, .L802B6BF8
/* E25AB4 802B6BE4 00000000 */   nop
/* E25AB8 802B6BE8 0C04417A */  jal       get_entity_by_index
/* E25ABC 802B6BEC 00000000 */   nop
/* E25AC0 802B6BF0 080ADB03 */  j         .L802B6C0C
/* E25AC4 802B6BF4 A0400007 */   sb       $zero, 7($v0)
.L802B6BF8:
/* E25AC8 802B6BF8 3C02802B */  lui       $v0, %hi(D_802B6DB0)
/* E25ACC 802B6BFC 8C426DB0 */  lw        $v0, %lo(D_802B6DB0)($v0)
/* E25AD0 802B6C00 8C420010 */  lw        $v0, 0x10($v0)
/* E25AD4 802B6C04 04410014 */  bgez      $v0, .L802B6C58
/* E25AD8 802B6C08 00000000 */   nop
.L802B6C0C:
/* E25ADC 802B6C0C 8E420000 */  lw        $v0, ($s2)
/* E25AE0 802B6C10 3C030100 */  lui       $v1, 0x100
/* E25AE4 802B6C14 00431025 */  or        $v0, $v0, $v1
/* E25AE8 802B6C18 AE420000 */  sw        $v0, ($s2)
/* E25AEC 802B6C1C 3C02802B */  lui       $v0, %hi(D_802B6DB0)
/* E25AF0 802B6C20 8C426DB0 */  lw        $v0, %lo(D_802B6DB0)($v0)
/* E25AF4 802B6C24 8C420010 */  lw        $v0, 0x10($v0)
/* E25AF8 802B6C28 0441000B */  bgez      $v0, .L802B6C58
/* E25AFC 802B6C2C 00000000 */   nop
/* E25B00 802B6C30 3C028011 */  lui       $v0, %hi(gPlayerData+0x1)
/* E25B04 802B6C34 8042F291 */  lb        $v0, %lo(gPlayerData+0x1)($v0)
/* E25B08 802B6C38 28420002 */  slti      $v0, $v0, 2
/* E25B0C 802B6C3C 14400006 */  bnez      $v0, .L802B6C58
/* E25B10 802B6C40 24030001 */   addiu    $v1, $zero, 1
/* E25B14 802B6C44 3C028016 */  lui       $v0, %hi(D_8015A578)
/* E25B18 802B6C48 2442A578 */  addiu     $v0, $v0, %lo(D_8015A578)
/* E25B1C 802B6C4C C640002C */  lwc1      $f0, 0x2c($s2)
/* E25B20 802B6C50 A0430000 */  sb        $v1, ($v0)
/* E25B24 802B6C54 E4400008 */  swc1      $f0, 8($v0)
.L802B6C58:
/* E25B28 802B6C58 824200B6 */  lb        $v0, 0xb6($s2)
/* E25B2C 802B6C5C 14400009 */  bnez      $v0, .L802B6C84
/* E25B30 802B6C60 924300B6 */   lbu      $v1, 0xb6($s2)
/* E25B34 802B6C64 06000007 */  bltz      $s0, .L802B6C84
/* E25B38 802B6C68 00000000 */   nop
/* E25B3C 802B6C6C 3C02802B */  lui       $v0, %hi(D_802B6DB0)
/* E25B40 802B6C70 8C426DB0 */  lw        $v0, %lo(D_802B6DB0)($v0)
/* E25B44 802B6C74 8C420014 */  lw        $v0, 0x14($v0)
/* E25B48 802B6C78 14400002 */  bnez      $v0, .L802B6C84
/* E25B4C 802B6C7C 24620001 */   addiu    $v0, $v1, 1
/* E25B50 802B6C80 A24200B6 */  sb        $v0, 0xb6($s2)
.L802B6C84:
/* E25B54 802B6C84 824300B6 */  lb        $v1, 0xb6($s2)
/* E25B58 802B6C88 24020001 */  addiu     $v0, $zero, 1
/* E25B5C 802B6C8C 14620004 */  bne       $v1, $v0, .L802B6CA0
/* E25B60 802B6C90 00000000 */   nop
/* E25B64 802B6C94 06010002 */  bgez      $s0, .L802B6CA0
/* E25B68 802B6C98 24020002 */   addiu    $v0, $zero, 2
/* E25B6C 802B6C9C A24200B6 */  sb        $v0, 0xb6($s2)
.L802B6CA0:
/* E25B70 802B6CA0 3C05802B */  lui       $a1, %hi(D_802B6DB0)
/* E25B74 802B6CA4 24A56DB0 */  addiu     $a1, $a1, %lo(D_802B6DB0)
/* E25B78 802B6CA8 8CA30000 */  lw        $v1, ($a1)
/* E25B7C 802B6CAC 8C620018 */  lw        $v0, 0x18($v1)
/* E25B80 802B6CB0 24420001 */  addiu     $v0, $v0, 1
/* E25B84 802B6CB4 06000003 */  bltz      $s0, .L802B6CC4
/* E25B88 802B6CB8 AC620018 */   sw       $v0, 0x18($v1)
/* E25B8C 802B6CBC 24020001 */  addiu     $v0, $zero, 1
/* E25B90 802B6CC0 AC620014 */  sw        $v0, 0x14($v1)
.L802B6CC4:
/* E25B94 802B6CC4 8CA20000 */  lw        $v0, ($a1)
/* E25B98 802B6CC8 8C430018 */  lw        $v1, 0x18($v0)
/* E25B9C 802B6CCC 24020006 */  addiu     $v0, $zero, 6
/* E25BA0 802B6CD0 14620005 */  bne       $v1, $v0, .L802B6CE8
/* E25BA4 802B6CD4 3C03FFDF */   lui      $v1, 0xffdf
/* E25BA8 802B6CD8 8E420000 */  lw        $v0, ($s2)
/* E25BAC 802B6CDC 3463FFFF */  ori       $v1, $v1, 0xffff
/* E25BB0 802B6CE0 00431024 */  and       $v0, $v0, $v1
/* E25BB4 802B6CE4 AE420000 */  sw        $v0, ($s2)
.L802B6CE8:
/* E25BB8 802B6CE8 964400BC */  lhu       $a0, 0xbc($s2)
/* E25BBC 802B6CEC 24020001 */  addiu     $v0, $zero, 1
/* E25BC0 802B6CF0 14820020 */  bne       $a0, $v0, .L802B6D74
/* E25BC4 802B6CF4 00000000 */   nop
/* E25BC8 802B6CF8 8CA30000 */  lw        $v1, ($a1)
/* E25BCC 802B6CFC 8C620018 */  lw        $v0, 0x18($v1)
/* E25BD0 802B6D00 28420007 */  slti      $v0, $v0, 7
/* E25BD4 802B6D04 14400005 */  bnez      $v0, .L802B6D1C
/* E25BD8 802B6D08 00000000 */   nop
/* E25BDC 802B6D0C 8E4200E0 */  lw        $v0, 0xe0($s2)
/* E25BE0 802B6D10 30424000 */  andi      $v0, $v0, 0x4000
/* E25BE4 802B6D14 54400001 */  bnel      $v0, $zero, .L802B6D1C
/* E25BE8 802B6D18 AC64001C */   sw       $a0, 0x1c($v1)
.L802B6D1C:
/* E25BEC 802B6D1C 3C03802B */  lui       $v1, %hi(D_802B6DB0)
/* E25BF0 802B6D20 8C636DB0 */  lw        $v1, %lo(D_802B6DB0)($v1)
/* E25BF4 802B6D24 8C62001C */  lw        $v0, 0x1c($v1)
/* E25BF8 802B6D28 14400006 */  bnez      $v0, .L802B6D44
/* E25BFC 802B6D2C AC600014 */   sw       $zero, 0x14($v1)
/* E25C00 802B6D30 8C630018 */  lw        $v1, 0x18($v1)
/* E25C04 802B6D34 2402000A */  addiu     $v0, $zero, 0xa
/* E25C08 802B6D38 0043102A */  slt       $v0, $v0, $v1
/* E25C0C 802B6D3C 10400009 */  beqz      $v0, .L802B6D64
/* E25C10 802B6D40 3C03FFDF */   lui      $v1, 0xffdf
.L802B6D44:
/* E25C14 802B6D44 3C03FEFF */  lui       $v1, 0xfeff
/* E25C18 802B6D48 3463FFFF */  ori       $v1, $v1, 0xffff
/* E25C1C 802B6D4C 8E420000 */  lw        $v0, ($s2)
/* E25C20 802B6D50 0000202D */  daddu     $a0, $zero, $zero
/* E25C24 802B6D54 00431024 */  and       $v0, $v0, $v1
/* E25C28 802B6D58 0C039769 */  jal       set_action_state
/* E25C2C 802B6D5C AE420000 */   sw       $v0, ($s2)
/* E25C30 802B6D60 3C03FFDF */  lui       $v1, 0xffdf
.L802B6D64:
/* E25C34 802B6D64 8E420000 */  lw        $v0, ($s2)
/* E25C38 802B6D68 3463FFFF */  ori       $v1, $v1, 0xffff
/* E25C3C 802B6D6C 00431024 */  and       $v0, $v0, $v1
/* E25C40 802B6D70 AE420000 */  sw        $v0, ($s2)
.L802B6D74:
/* E25C44 802B6D74 8FBF004C */  lw        $ra, 0x4c($sp)
/* E25C48 802B6D78 8FB40048 */  lw        $s4, 0x48($sp)
/* E25C4C 802B6D7C 8FB30044 */  lw        $s3, 0x44($sp)
/* E25C50 802B6D80 8FB20040 */  lw        $s2, 0x40($sp)
/* E25C54 802B6D84 8FB1003C */  lw        $s1, 0x3c($sp)
/* E25C58 802B6D88 8FB00038 */  lw        $s0, 0x38($sp)
/* E25C5C 802B6D8C D7BC0070 */  ldc1      $f28, 0x70($sp)
/* E25C60 802B6D90 D7BA0068 */  ldc1      $f26, 0x68($sp)
/* E25C64 802B6D94 D7B80060 */  ldc1      $f24, 0x60($sp)
/* E25C68 802B6D98 D7B60058 */  ldc1      $f22, 0x58($sp)
/* E25C6C 802B6D9C D7B40050 */  ldc1      $f20, 0x50($sp)
/* E25C70 802B6DA0 03E00008 */  jr        $ra
/* E25C74 802B6DA4 27BD0078 */   addiu    $sp, $sp, 0x78
/* E25C78 802B6DA8 00000000 */  nop
/* E25C7C 802B6DAC 00000000 */  nop
