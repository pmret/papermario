.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel start_battle
/* 1FAB4 800446B4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 1FAB8 800446B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 1FABC 800446BC 00A0802D */  daddu     $s0, $a1, $zero
/* 1FAC0 800446C0 AFBF0028 */  sw        $ra, 0x28($sp)
/* 1FAC4 800446C4 AFB50024 */  sw        $s5, 0x24($sp)
/* 1FAC8 800446C8 AFB40020 */  sw        $s4, 0x20($sp)
/* 1FACC 800446CC AFB3001C */  sw        $s3, 0x1c($sp)
/* 1FAD0 800446D0 AFB20018 */  sw        $s2, 0x18($sp)
/* 1FAD4 800446D4 AFB10014 */  sw        $s1, 0x14($sp)
/* 1FAD8 800446D8 8C910148 */  lw        $s1, 0x148($a0)
/* 1FADC 800446DC 0C0B1192 */  jal       resume_all_group
/* 1FAE0 800446E0 24040001 */   addiu    $a0, $zero, 1
/* 1FAE4 800446E4 3C13800B */  lui       $s3, %hi(gCurrentEncounter)
/* 1FAE8 800446E8 26730F10 */  addiu     $s3, $s3, %lo(gCurrentEncounter)
/* 1FAEC 800446EC 24020001 */  addiu     $v0, $zero, 1
/* 1FAF0 800446F0 A2620005 */  sb        $v0, 5($s3)
/* 1FAF4 800446F4 A2220005 */  sb        $v0, 5($s1)
/* 1FAF8 800446F8 AE71008C */  sw        $s1, 0x8c($s3)
/* 1FAFC 800446FC 82220004 */  lb        $v0, 4($s1)
/* 1FB00 80044700 00021080 */  sll       $v0, $v0, 2
/* 1FB04 80044704 00531021 */  addu      $v0, $v0, $s3
/* 1FB08 80044708 8C430028 */  lw        $v1, 0x28($v0)
/* 1FB0C 8004470C 2402FFFF */  addiu     $v0, $zero, -1
/* 1FB10 80044710 A2600004 */  sb        $zero, 4($s3)
/* 1FB14 80044714 A2600011 */  sb        $zero, 0x11($s3)
/* 1FB18 80044718 AE700014 */  sw        $s0, 0x14($s3)
/* 1FB1C 8004471C AE620018 */  sw        $v0, 0x18($s3)
/* 1FB20 80044720 AE630088 */  sw        $v1, 0x88($s3)
/* 1FB24 80044724 8E22003C */  lw        $v0, 0x3c($s1)
/* 1FB28 80044728 10400003 */  beqz      $v0, .L80044738
/* 1FB2C 8004472C 00000000 */   nop
/* 1FB30 80044730 0C0B1108 */  jal       suspend_all_script
/* 1FB34 80044734 8E240054 */   lw       $a0, 0x54($s1)
.L80044738:
/* 1FB38 80044738 8E220044 */  lw        $v0, 0x44($s1)
/* 1FB3C 8004473C 10400003 */  beqz      $v0, .L8004474C
/* 1FB40 80044740 00000000 */   nop
/* 1FB44 80044744 0C0B1108 */  jal       suspend_all_script
/* 1FB48 80044748 8E24005C */   lw       $a0, 0x5c($s1)
.L8004474C:
/* 1FB4C 8004474C 0C03805E */  jal       disable_player_input
/* 1FB50 80044750 0000802D */   daddu    $s0, $zero, $zero
/* 1FB54 80044754 0C03BD8A */  jal       func_800EF628
/* 1FB58 80044758 00000000 */   nop
/* 1FB5C 8004475C 8E740088 */  lw        $s4, 0x88($s3)
/* 1FB60 80044760 8E820000 */  lw        $v0, ($s4)
/* 1FB64 80044764 18400021 */  blez      $v0, .L800447EC
/* 1FB68 80044768 24150001 */   addiu    $s5, $zero, 1
/* 1FB6C 8004476C 0280902D */  daddu     $s2, $s4, $zero
.L80044770:
/* 1FB70 80044770 8E510004 */  lw        $s1, 4($s2)
/* 1FB74 80044774 12200018 */  beqz      $s1, .L800447D8
/* 1FB78 80044778 00000000 */   nop
/* 1FB7C 8004477C 8E220000 */  lw        $v0, ($s1)
/* 1FB80 80044780 30420008 */  andi      $v0, $v0, 8
/* 1FB84 80044784 10400004 */  beqz      $v0, .L80044798
/* 1FB88 80044788 00000000 */   nop
/* 1FB8C 8004478C 8E62008C */  lw        $v0, 0x8c($s3)
/* 1FB90 80044790 16220011 */  bne       $s1, $v0, .L800447D8
/* 1FB94 80044794 00000000 */   nop
.L80044798:
/* 1FB98 80044798 8E220028 */  lw        $v0, 0x28($s1)
/* 1FB9C 8004479C 1040000E */  beqz      $v0, .L800447D8
/* 1FBA0 800447A0 0040202D */   daddu    $a0, $v0, $zero
/* 1FBA4 800447A4 2405000A */  addiu     $a1, $zero, 0xa
/* 1FBA8 800447A8 0000302D */  daddu     $a2, $zero, $zero
/* 1FBAC 800447AC 0C0B0CF8 */  jal       start_script
/* 1FBB0 800447B0 A2350005 */   sb       $s5, 5($s1)
/* 1FBB4 800447B4 0040182D */  daddu     $v1, $v0, $zero
/* 1FBB8 800447B8 AE230040 */  sw        $v1, 0x40($s1)
/* 1FBBC 800447BC 8C620144 */  lw        $v0, 0x144($v1)
/* 1FBC0 800447C0 AE220058 */  sw        $v0, 0x58($s1)
/* 1FBC4 800447C4 AC710148 */  sw        $s1, 0x148($v1)
/* 1FBC8 800447C8 86220008 */  lh        $v0, 8($s1)
/* 1FBCC 800447CC AC62014C */  sw        $v0, 0x14c($v1)
/* 1FBD0 800447D0 92220006 */  lbu       $v0, 6($s1)
/* 1FBD4 800447D4 A0620004 */  sb        $v0, 4($v1)
.L800447D8:
/* 1FBD8 800447D8 8E820000 */  lw        $v0, ($s4)
/* 1FBDC 800447DC 26100001 */  addiu     $s0, $s0, 1
/* 1FBE0 800447E0 0202102A */  slt       $v0, $s0, $v0
/* 1FBE4 800447E4 1440FFE2 */  bnez      $v0, .L80044770
/* 1FBE8 800447E8 26520004 */   addiu    $s2, $s2, 4
.L800447EC:
/* 1FBEC 800447EC 24020001 */  addiu     $v0, $zero, 1
/* 1FBF0 800447F0 AE600090 */  sw        $zero, 0x90($s3)
/* 1FBF4 800447F4 AE600094 */  sw        $zero, 0x94($s3)
/* 1FBF8 800447F8 A2620012 */  sb        $v0, 0x12($s3)
/* 1FBFC 800447FC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 1FC00 80044800 8FB50024 */  lw        $s5, 0x24($sp)
/* 1FC04 80044804 8FB40020 */  lw        $s4, 0x20($sp)
/* 1FC08 80044808 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1FC0C 8004480C 8FB20018 */  lw        $s2, 0x18($sp)
/* 1FC10 80044810 8FB10014 */  lw        $s1, 0x14($sp)
/* 1FC14 80044814 8FB00010 */  lw        $s0, 0x10($sp)
/* 1FC18 80044818 24020003 */  addiu     $v0, $zero, 3
/* 1FC1C 8004481C 3C01800A */  lui       $at, %hi(gGameState)
/* 1FC20 80044820 AC22A600 */  sw        $v0, %lo(gGameState)($at)
/* 1FC24 80044824 24020001 */  addiu     $v0, $zero, 1
/* 1FC28 80044828 3C01800A */  lui       $at, %hi(D_8009A678)
/* 1FC2C 8004482C AC22A678 */  sw        $v0, %lo(D_8009A678)($at)
/* 1FC30 80044830 3C01800A */  lui       $at, %hi(D_8009A5D0)
/* 1FC34 80044834 AC20A5D0 */  sw        $zero, %lo(D_8009A5D0)($at)
/* 1FC38 80044838 03E00008 */  jr        $ra
/* 1FC3C 8004483C 27BD0030 */   addiu    $sp, $sp, 0x30
