.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409B0
/* A27880 802409B0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A27884 802409B4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* A27888 802409B8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* A2788C 802409BC 3C04800B */  lui       $a0, %hi(gCameras)
/* A27890 802409C0 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* A27894 802409C4 AFBF0024 */  sw        $ra, 0x24($sp)
/* A27898 802409C8 AFB20020 */  sw        $s2, 0x20($sp)
/* A2789C 802409CC AFB1001C */  sw        $s1, 0x1c($sp)
/* A278A0 802409D0 AFB00018 */  sw        $s0, 0x18($sp)
/* A278A4 802409D4 00031080 */  sll       $v0, $v1, 2
/* A278A8 802409D8 00431021 */  addu      $v0, $v0, $v1
/* A278AC 802409DC 00021080 */  sll       $v0, $v0, 2
/* A278B0 802409E0 00431023 */  subu      $v0, $v0, $v1
/* A278B4 802409E4 000218C0 */  sll       $v1, $v0, 3
/* A278B8 802409E8 00431021 */  addu      $v0, $v0, $v1
/* A278BC 802409EC 000210C0 */  sll       $v0, $v0, 3
/* A278C0 802409F0 10A00005 */  beqz      $a1, .L80240A08
/* A278C4 802409F4 00449021 */   addu     $s2, $v0, $a0
/* A278C8 802409F8 3C018024 */  lui       $at, 0x8024
/* A278CC 802409FC C4201B54 */  lwc1      $f0, 0x1b54($at)
/* A278D0 80240A00 3C018024 */  lui       $at, 0x8024
/* A278D4 80240A04 E4203370 */  swc1      $f0, 0x3370($at)
.L80240A08:
/* A278D8 80240A08 3C118024 */  lui       $s1, 0x8024
/* A278DC 80240A0C 26313370 */  addiu     $s1, $s1, 0x3370
/* A278E0 80240A10 3C01428C */  lui       $at, 0x428c
/* A278E4 80240A14 44810000 */  mtc1      $at, $f0
/* A278E8 80240A18 3C058024 */  lui       $a1, 0x8024
/* A278EC 80240A1C 8CA51B54 */  lw        $a1, 0x1b54($a1)
/* A278F0 80240A20 3C06442F */  lui       $a2, 0x442f
/* A278F4 80240A24 3C108024 */  lui       $s0, 0x8024
/* A278F8 80240A28 26101B84 */  addiu     $s0, $s0, 0x1b84
/* A278FC 80240A2C AFB10014 */  sw        $s1, 0x14($sp)
/* A27900 80240A30 E7A00010 */  swc1      $f0, 0x10($sp)
/* A27904 80240A34 C6000000 */  lwc1      $f0, ($s0)
/* A27908 80240A38 46800020 */  cvt.s.w   $f0, $f0
/* A2790C 80240A3C 44070000 */  mfc1      $a3, $f0
/* A27910 80240A40 0C0901CD */  jal       func_80240734
/* A27914 80240A44 24040001 */   addiu    $a0, $zero, 1
/* A27918 80240A48 C6200000 */  lwc1      $f0, ($s1)
/* A2791C 80240A4C 8E020000 */  lw        $v0, ($s0)
/* A27920 80240A50 24030001 */  addiu     $v1, $zero, 1
/* A27924 80240A54 A6430506 */  sh        $v1, 0x506($s2)
/* A27928 80240A58 24420001 */  addiu     $v0, $v0, 1
/* A2792C 80240A5C E64004DC */  swc1      $f0, 0x4dc($s2)
/* A27930 80240A60 AE020000 */  sw        $v0, ($s0)
/* A27934 80240A64 28420046 */  slti      $v0, $v0, 0x46
/* A27938 80240A68 8FBF0024 */  lw        $ra, 0x24($sp)
/* A2793C 80240A6C 8FB20020 */  lw        $s2, 0x20($sp)
/* A27940 80240A70 8FB1001C */  lw        $s1, 0x1c($sp)
/* A27944 80240A74 8FB00018 */  lw        $s0, 0x18($sp)
/* A27948 80240A78 38420001 */  xori      $v0, $v0, 1
/* A2794C 80240A7C 03E00008 */  jr        $ra
/* A27950 80240A80 27BD0028 */   addiu    $sp, $sp, 0x28
