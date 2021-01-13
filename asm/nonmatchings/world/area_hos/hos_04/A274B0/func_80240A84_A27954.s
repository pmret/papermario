.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A84_A27954
/* A27954 80240A84 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A27958 80240A88 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* A2795C 80240A8C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* A27960 80240A90 3C04800B */  lui       $a0, %hi(gCameras)
/* A27964 80240A94 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* A27968 80240A98 AFBF0024 */  sw        $ra, 0x24($sp)
/* A2796C 80240A9C AFB20020 */  sw        $s2, 0x20($sp)
/* A27970 80240AA0 AFB1001C */  sw        $s1, 0x1c($sp)
/* A27974 80240AA4 AFB00018 */  sw        $s0, 0x18($sp)
/* A27978 80240AA8 00031080 */  sll       $v0, $v1, 2
/* A2797C 80240AAC 00431021 */  addu      $v0, $v0, $v1
/* A27980 80240AB0 00021080 */  sll       $v0, $v0, 2
/* A27984 80240AB4 00431023 */  subu      $v0, $v0, $v1
/* A27988 80240AB8 000218C0 */  sll       $v1, $v0, 3
/* A2798C 80240ABC 00431021 */  addu      $v0, $v0, $v1
/* A27990 80240AC0 000210C0 */  sll       $v0, $v0, 3
/* A27994 80240AC4 10A00005 */  beqz      $a1, .L80240ADC
/* A27998 80240AC8 00449021 */   addu     $s2, $v0, $a0
/* A2799C 80240ACC 3C018024 */  lui       $at, %hi(func_80241B74_911224)
/* A279A0 80240AD0 C4201B74 */  lwc1      $f0, %lo(func_80241B74_911224)($at)
/* A279A4 80240AD4 3C018024 */  lui       $at, %hi(D_80243374)
/* A279A8 80240AD8 E4203374 */  swc1      $f0, %lo(D_80243374)($at)
.L80240ADC:
/* A279AC 80240ADC 3C118024 */  lui       $s1, %hi(D_80243374)
/* A279B0 80240AE0 26313374 */  addiu     $s1, $s1, %lo(D_80243374)
/* A279B4 80240AE4 3C014348 */  lui       $at, 0x4348
/* A279B8 80240AE8 44810000 */  mtc1      $at, $f0
/* A279BC 80240AEC 3C058024 */  lui       $a1, %hi(func_80241B74_911224)
/* A279C0 80240AF0 8CA51B74 */  lw        $a1, %lo(func_80241B74_911224)($a1)
/* A279C4 80240AF4 3C06C2A0 */  lui       $a2, 0xc2a0
/* A279C8 80240AF8 3C108024 */  lui       $s0, %hi(D_80241B88)
/* A279CC 80240AFC 26101B88 */  addiu     $s0, $s0, %lo(D_80241B88)
/* A279D0 80240B00 AFB10014 */  sw        $s1, 0x14($sp)
/* A279D4 80240B04 E7A00010 */  swc1      $f0, 0x10($sp)
/* A279D8 80240B08 C6000000 */  lwc1      $f0, ($s0)
/* A279DC 80240B0C 46800020 */  cvt.s.w   $f0, $f0
/* A279E0 80240B10 44070000 */  mfc1      $a3, $f0
/* A279E4 80240B14 0C0901CD */  jal       func_80240734_A27604
/* A279E8 80240B18 24040005 */   addiu    $a0, $zero, 5
/* A279EC 80240B1C C6200000 */  lwc1      $f0, ($s1)
/* A279F0 80240B20 8E020000 */  lw        $v0, ($s0)
/* A279F4 80240B24 24030001 */  addiu     $v1, $zero, 1
/* A279F8 80240B28 A6430506 */  sh        $v1, 0x506($s2)
/* A279FC 80240B2C 24420001 */  addiu     $v0, $v0, 1
/* A27A00 80240B30 E64004FC */  swc1      $f0, 0x4fc($s2)
/* A27A04 80240B34 AE020000 */  sw        $v0, ($s0)
/* A27A08 80240B38 384200C8 */  xori      $v0, $v0, 0xc8
/* A27A0C 80240B3C 2C420001 */  sltiu     $v0, $v0, 1
/* A27A10 80240B40 8FBF0024 */  lw        $ra, 0x24($sp)
/* A27A14 80240B44 8FB20020 */  lw        $s2, 0x20($sp)
/* A27A18 80240B48 8FB1001C */  lw        $s1, 0x1c($sp)
/* A27A1C 80240B4C 8FB00018 */  lw        $s0, 0x18($sp)
/* A27A20 80240B50 00021040 */  sll       $v0, $v0, 1
/* A27A24 80240B54 03E00008 */  jr        $ra
/* A27A28 80240B58 27BD0028 */   addiu    $sp, $sp, 0x28
/* A27A2C 80240B5C 00000000 */  nop
