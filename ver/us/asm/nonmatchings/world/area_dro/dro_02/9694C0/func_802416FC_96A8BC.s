.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416FC_96A8BC
/* 96A8BC 802416FC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 96A8C0 80241700 AFB20028 */  sw        $s2, 0x28($sp)
/* 96A8C4 80241704 0080902D */  daddu     $s2, $a0, $zero
/* 96A8C8 80241708 AFBF0030 */  sw        $ra, 0x30($sp)
/* 96A8CC 8024170C AFB3002C */  sw        $s3, 0x2c($sp)
/* 96A8D0 80241710 AFB10024 */  sw        $s1, 0x24($sp)
/* 96A8D4 80241714 AFB00020 */  sw        $s0, 0x20($sp)
/* 96A8D8 80241718 3C018025 */  lui       $at, %hi(D_8024EFCC)
/* 96A8DC 8024171C AC32EFCC */  sw        $s2, %lo(D_8024EFCC)($at)
/* 96A8E0 80241720 0C04E9C1 */  jal       func_8013A704
/* 96A8E4 80241724 24040001 */   addiu    $a0, $zero, 1
/* 96A8E8 80241728 0040982D */  daddu     $s3, $v0, $zero
/* 96A8EC 8024172C 0260202D */  daddu     $a0, $s3, $zero
/* 96A8F0 80241730 24050005 */  addiu     $a1, $zero, 5
/* 96A8F4 80241734 2406000F */  addiu     $a2, $zero, 0xf
/* 96A8F8 80241738 24070001 */  addiu     $a3, $zero, 1
/* 96A8FC 8024173C 00E0882D */  daddu     $s1, $a3, $zero
/* 96A900 80241740 24100800 */  addiu     $s0, $zero, 0x800
/* 96A904 80241744 AFB10010 */  sw        $s1, 0x10($sp)
/* 96A908 80241748 AFA00014 */  sw        $zero, 0x14($sp)
/* 96A90C 8024174C 0C04EAA7 */  jal       func_8013AA9C
/* 96A910 80241750 AFB00018 */   sw       $s0, 0x18($sp)
/* 96A914 80241754 0240202D */  daddu     $a0, $s2, $zero
/* 96A918 80241758 3C05F4AC */  lui       $a1, 0xf4ac
/* 96A91C 8024175C 34A5D480 */  ori       $a1, $a1, 0xd480
/* 96A920 80241760 0C0B2026 */  jal       set_variable
/* 96A924 80241764 0260302D */   daddu    $a2, $s3, $zero
/* 96A928 80241768 0C04E9C1 */  jal       func_8013A704
/* 96A92C 8024176C 24040001 */   addiu    $a0, $zero, 1
/* 96A930 80241770 0040982D */  daddu     $s3, $v0, $zero
/* 96A934 80241774 0260202D */  daddu     $a0, $s3, $zero
/* 96A938 80241778 24050005 */  addiu     $a1, $zero, 5
/* 96A93C 8024177C 24060010 */  addiu     $a2, $zero, 0x10
/* 96A940 80241780 24070001 */  addiu     $a3, $zero, 1
/* 96A944 80241784 AFB10010 */  sw        $s1, 0x10($sp)
/* 96A948 80241788 AFA00014 */  sw        $zero, 0x14($sp)
/* 96A94C 8024178C 0C04EAA7 */  jal       func_8013AA9C
/* 96A950 80241790 AFB00018 */   sw       $s0, 0x18($sp)
/* 96A954 80241794 0240202D */  daddu     $a0, $s2, $zero
/* 96A958 80241798 3C05F4AC */  lui       $a1, 0xf4ac
/* 96A95C 8024179C 34A5D481 */  ori       $a1, $a1, 0xd481
/* 96A960 802417A0 0C0B2026 */  jal       set_variable
/* 96A964 802417A4 0260302D */   daddu    $a2, $s3, $zero
/* 96A968 802417A8 0C04E9C1 */  jal       func_8013A704
/* 96A96C 802417AC 24040001 */   addiu    $a0, $zero, 1
/* 96A970 802417B0 0040982D */  daddu     $s3, $v0, $zero
/* 96A974 802417B4 0260202D */  daddu     $a0, $s3, $zero
/* 96A978 802417B8 24050005 */  addiu     $a1, $zero, 5
/* 96A97C 802417BC 24060011 */  addiu     $a2, $zero, 0x11
/* 96A980 802417C0 24070001 */  addiu     $a3, $zero, 1
/* 96A984 802417C4 AFB10010 */  sw        $s1, 0x10($sp)
/* 96A988 802417C8 AFA00014 */  sw        $zero, 0x14($sp)
/* 96A98C 802417CC 0C04EAA7 */  jal       func_8013AA9C
/* 96A990 802417D0 AFB00018 */   sw       $s0, 0x18($sp)
/* 96A994 802417D4 0240202D */  daddu     $a0, $s2, $zero
/* 96A998 802417D8 3C05F4AC */  lui       $a1, 0xf4ac
/* 96A99C 802417DC 34A5D482 */  ori       $a1, $a1, 0xd482
/* 96A9A0 802417E0 0C0B2026 */  jal       set_variable
/* 96A9A4 802417E4 0260302D */   daddu    $a2, $s3, $zero
/* 96A9A8 802417E8 0C04E9C1 */  jal       func_8013A704
/* 96A9AC 802417EC 24040001 */   addiu    $a0, $zero, 1
/* 96A9B0 802417F0 0040982D */  daddu     $s3, $v0, $zero
/* 96A9B4 802417F4 0260202D */  daddu     $a0, $s3, $zero
/* 96A9B8 802417F8 24050005 */  addiu     $a1, $zero, 5
/* 96A9BC 802417FC 24060012 */  addiu     $a2, $zero, 0x12
/* 96A9C0 80241800 24070001 */  addiu     $a3, $zero, 1
/* 96A9C4 80241804 AFB10010 */  sw        $s1, 0x10($sp)
/* 96A9C8 80241808 AFA00014 */  sw        $zero, 0x14($sp)
/* 96A9CC 8024180C 0C04EAA7 */  jal       func_8013AA9C
/* 96A9D0 80241810 AFB00018 */   sw       $s0, 0x18($sp)
/* 96A9D4 80241814 0240202D */  daddu     $a0, $s2, $zero
/* 96A9D8 80241818 3C05F4AC */  lui       $a1, 0xf4ac
/* 96A9DC 8024181C 34A5D483 */  ori       $a1, $a1, 0xd483
/* 96A9E0 80241820 0C0B2026 */  jal       set_variable
/* 96A9E4 80241824 0260302D */   daddu    $a2, $s3, $zero
/* 96A9E8 80241828 3C048024 */  lui       $a0, %hi(func_8024240C_96B5CC)
/* 96A9EC 8024182C 2484240C */  addiu     $a0, $a0, %lo(func_8024240C_96B5CC)
/* 96A9F0 80241830 3C058024 */  lui       $a1, %hi(func_80242EAC_96C06C)
/* 96A9F4 80241834 24A52EAC */  addiu     $a1, $a1, %lo(func_80242EAC_96C06C)
/* 96A9F8 80241838 0C048C56 */  jal       bind_dynamic_entity_3
/* 96A9FC 8024183C 00000000 */   nop
/* 96AA00 80241840 0240202D */  daddu     $a0, $s2, $zero
/* 96AA04 80241844 3C05F4AC */  lui       $a1, 0xf4ac
/* 96AA08 80241848 34A5D487 */  ori       $a1, $a1, 0xd487
/* 96AA0C 8024184C 0C0B2026 */  jal       set_variable
/* 96AA10 80241850 0040302D */   daddu    $a2, $v0, $zero
/* 96AA14 80241854 8FBF0030 */  lw        $ra, 0x30($sp)
/* 96AA18 80241858 8FB3002C */  lw        $s3, 0x2c($sp)
/* 96AA1C 8024185C 8FB20028 */  lw        $s2, 0x28($sp)
/* 96AA20 80241860 8FB10024 */  lw        $s1, 0x24($sp)
/* 96AA24 80241864 8FB00020 */  lw        $s0, 0x20($sp)
/* 96AA28 80241868 24020002 */  addiu     $v0, $zero, 2
/* 96AA2C 8024186C 03E00008 */  jr        $ra
/* 96AA30 80241870 27BD0038 */   addiu    $sp, $sp, 0x38
