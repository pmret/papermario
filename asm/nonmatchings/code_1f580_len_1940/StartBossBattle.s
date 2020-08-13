.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel StartBossBattle
/* 01FC9C 8004489C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 01FCA0 800448A0 AFBF0028 */  sw    $ra, 0x28($sp)
/* 01FCA4 800448A4 AFB50024 */  sw    $s5, 0x24($sp)
/* 01FCA8 800448A8 AFB40020 */  sw    $s4, 0x20($sp)
/* 01FCAC 800448AC AFB3001C */  sw    $s3, 0x1c($sp)
/* 01FCB0 800448B0 AFB20018 */  sw    $s2, 0x18($sp)
/* 01FCB4 800448B4 AFB10014 */  sw    $s1, 0x14($sp)
/* 01FCB8 800448B8 AFB00010 */  sw    $s0, 0x10($sp)
/* 01FCBC 800448BC 8C82000C */  lw    $v0, 0xc($a0)
/* 01FCC0 800448C0 8C450000 */  lw    $a1, ($v0)
/* 01FCC4 800448C4 0C0B1EAF */  jal   get_variable
/* 01FCC8 800448C8 8C910148 */   lw    $s1, 0x148($a0)
/* 01FCCC 800448CC 24040001 */  addiu $a0, $zero, 1
/* 01FCD0 800448D0 0C0B1192 */  jal   resume_all_group
/* 01FCD4 800448D4 0040802D */   daddu $s0, $v0, $zero
/* 01FCD8 800448D8 3C13800B */  lui   $s3, 0x800b
/* 01FCDC 800448DC 26730F10 */  addiu $s3, $s3, 0xf10
/* 01FCE0 800448E0 24030001 */  addiu $v1, $zero, 1
/* 01FCE4 800448E4 A2630005 */  sb    $v1, 5($s3)
/* 01FCE8 800448E8 A2230005 */  sb    $v1, 5($s1)
/* 01FCEC 800448EC AE71008C */  sw    $s1, 0x8c($s3)
/* 01FCF0 800448F0 82220004 */  lb    $v0, 4($s1)
/* 01FCF4 800448F4 00021080 */  sll   $v0, $v0, 2
/* 01FCF8 800448F8 00531021 */  addu  $v0, $v0, $s3
/* 01FCFC 800448FC 8C440028 */  lw    $a0, 0x28($v0)
/* 01FD00 80044900 2402FFFF */  addiu $v0, $zero, -1
/* 01FD04 80044904 A2600004 */  sb    $zero, 4($s3)
/* 01FD08 80044908 A2630011 */  sb    $v1, 0x11($s3)
/* 01FD0C 8004490C AE700014 */  sw    $s0, 0x14($s3)
/* 01FD10 80044910 AE620018 */  sw    $v0, 0x18($s3)
/* 01FD14 80044914 AE640088 */  sw    $a0, 0x88($s3)
/* 01FD18 80044918 8E22003C */  lw    $v0, 0x3c($s1)
/* 01FD1C 8004491C 10400003 */  beqz  $v0, .L8004492C
/* 01FD20 80044920 00000000 */   nop   
/* 01FD24 80044924 0C0B1108 */  jal   suspend_all_script
/* 01FD28 80044928 8E240054 */   lw    $a0, 0x54($s1)
.L8004492C:
/* 01FD2C 8004492C 8E220044 */  lw    $v0, 0x44($s1)
/* 01FD30 80044930 10400003 */  beqz  $v0, .L80044940
/* 01FD34 80044934 00000000 */   nop   
/* 01FD38 80044938 0C0B1108 */  jal   suspend_all_script
/* 01FD3C 8004493C 8E24005C */   lw    $a0, 0x5c($s1)
.L80044940:
/* 01FD40 80044940 0C03805E */  jal   func_800E0178
/* 01FD44 80044944 0000802D */   daddu $s0, $zero, $zero
/* 01FD48 80044948 0C03BD8A */  jal   func_800EF628
/* 01FD4C 8004494C 00000000 */   nop   
/* 01FD50 80044950 8E740088 */  lw    $s4, 0x88($s3)
/* 01FD54 80044954 8E820000 */  lw    $v0, ($s4)
/* 01FD58 80044958 18400021 */  blez  $v0, .L800449E0
/* 01FD5C 8004495C 24150001 */   addiu $s5, $zero, 1
/* 01FD60 80044960 0280902D */  daddu $s2, $s4, $zero
.L80044964:
/* 01FD64 80044964 8E510004 */  lw    $s1, 4($s2)
/* 01FD68 80044968 12200018 */  beqz  $s1, .L800449CC
/* 01FD6C 8004496C 00000000 */   nop   
/* 01FD70 80044970 8E220000 */  lw    $v0, ($s1)
/* 01FD74 80044974 30420008 */  andi  $v0, $v0, 8
/* 01FD78 80044978 10400004 */  beqz  $v0, .L8004498C
/* 01FD7C 8004497C 00000000 */   nop   
/* 01FD80 80044980 8E62008C */  lw    $v0, 0x8c($s3)
/* 01FD84 80044984 16220011 */  bne   $s1, $v0, .L800449CC
/* 01FD88 80044988 00000000 */   nop   
.L8004498C:
/* 01FD8C 8004498C 8E220028 */  lw    $v0, 0x28($s1)
/* 01FD90 80044990 1040000E */  beqz  $v0, .L800449CC
/* 01FD94 80044994 0040202D */   daddu $a0, $v0, $zero
/* 01FD98 80044998 2405000A */  addiu $a1, $zero, 0xa
/* 01FD9C 8004499C 0000302D */  daddu $a2, $zero, $zero
/* 01FDA0 800449A0 0C0B0CF8 */  jal   start_script
/* 01FDA4 800449A4 A2350005 */   sb    $s5, 5($s1)
/* 01FDA8 800449A8 0040202D */  daddu $a0, $v0, $zero
/* 01FDAC 800449AC AE240040 */  sw    $a0, 0x40($s1)
/* 01FDB0 800449B0 8C820144 */  lw    $v0, 0x144($a0)
/* 01FDB4 800449B4 AE220058 */  sw    $v0, 0x58($s1)
/* 01FDB8 800449B8 AC910148 */  sw    $s1, 0x148($a0)
/* 01FDBC 800449BC 86220008 */  lh    $v0, 8($s1)
/* 01FDC0 800449C0 AC82014C */  sw    $v0, 0x14c($a0)
/* 01FDC4 800449C4 92220006 */  lbu   $v0, 6($s1)
/* 01FDC8 800449C8 A0820004 */  sb    $v0, 4($a0)
.L800449CC:
/* 01FDCC 800449CC 8E820000 */  lw    $v0, ($s4)
/* 01FDD0 800449D0 26100001 */  addiu $s0, $s0, 1
/* 01FDD4 800449D4 0202102A */  slt   $v0, $s0, $v0
/* 01FDD8 800449D8 1440FFE2 */  bnez  $v0, .L80044964
/* 01FDDC 800449DC 26520004 */   addiu $s2, $s2, 4
.L800449E0:
/* 01FDE0 800449E0 24020001 */  addiu $v0, $zero, 1
/* 01FDE4 800449E4 0040182D */  daddu $v1, $v0, $zero
/* 01FDE8 800449E8 AE600090 */  sw    $zero, 0x90($s3)
/* 01FDEC 800449EC AE600094 */  sw    $zero, 0x94($s3)
/* 01FDF0 800449F0 A2630012 */  sb    $v1, 0x12($s3)
/* 01FDF4 800449F4 8FBF0028 */  lw    $ra, 0x28($sp)
/* 01FDF8 800449F8 8FB50024 */  lw    $s5, 0x24($sp)
/* 01FDFC 800449FC 8FB40020 */  lw    $s4, 0x20($sp)
/* 01FE00 80044A00 8FB3001C */  lw    $s3, 0x1c($sp)
/* 01FE04 80044A04 8FB20018 */  lw    $s2, 0x18($sp)
/* 01FE08 80044A08 8FB10014 */  lw    $s1, 0x14($sp)
/* 01FE0C 80044A0C 8FB00010 */  lw    $s0, 0x10($sp)
/* 01FE10 80044A10 24030003 */  addiu $v1, $zero, 3
/* 01FE14 80044A14 3C01800A */  lui   $at, 0x800a
/* 01FE18 80044A18 AC23A600 */  sw    $v1, -0x5a00($at)
/* 01FE1C 80044A1C 0040182D */  daddu $v1, $v0, $zero
/* 01FE20 80044A20 3C01800A */  lui   $at, 0x800a
/* 01FE24 80044A24 AC23A678 */  sw    $v1, -0x5988($at)
/* 01FE28 80044A28 3C01800A */  lui   $at, 0x800a
/* 01FE2C 80044A2C AC20A5D0 */  sw    $zero, -0x5a30($at)
/* 01FE30 80044A30 03E00008 */  jr    $ra
/* 01FE34 80044A34 27BD0030 */   addiu $sp, $sp, 0x30

