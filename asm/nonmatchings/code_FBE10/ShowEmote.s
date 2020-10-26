.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel ShowEmote
/* FC250 802D78A0 27BDFF90 */  addiu     $sp, $sp, -0x70
/* FC254 802D78A4 AFB10034 */  sw        $s1, 0x34($sp)
/* FC258 802D78A8 0080882D */  daddu     $s1, $a0, $zero
/* FC25C 802D78AC AFBF0048 */  sw        $ra, 0x48($sp)
/* FC260 802D78B0 AFB50044 */  sw        $s5, 0x44($sp)
/* FC264 802D78B4 AFB40040 */  sw        $s4, 0x40($sp)
/* FC268 802D78B8 AFB3003C */  sw        $s3, 0x3c($sp)
/* FC26C 802D78BC AFB20038 */  sw        $s2, 0x38($sp)
/* FC270 802D78C0 AFB00030 */  sw        $s0, 0x30($sp)
/* FC274 802D78C4 F7BA0068 */  sdc1      $f26, 0x68($sp)
/* FC278 802D78C8 F7B80060 */  sdc1      $f24, 0x60($sp)
/* FC27C 802D78CC F7B60058 */  sdc1      $f22, 0x58($sp)
/* FC280 802D78D0 F7B40050 */  sdc1      $f20, 0x50($sp)
/* FC284 802D78D4 8E30000C */  lw        $s0, 0xc($s1)
/* FC288 802D78D8 8E050000 */  lw        $a1, ($s0)
/* FC28C 802D78DC 0C0B1EAF */  jal       get_variable
/* FC290 802D78E0 26100004 */   addiu    $s0, $s0, 4
/* FC294 802D78E4 8E050000 */  lw        $a1, ($s0)
/* FC298 802D78E8 26100004 */  addiu     $s0, $s0, 4
/* FC29C 802D78EC 0220202D */  daddu     $a0, $s1, $zero
/* FC2A0 802D78F0 0C0B1EAF */  jal       get_variable
/* FC2A4 802D78F4 0040982D */   daddu    $s3, $v0, $zero
/* FC2A8 802D78F8 8E050000 */  lw        $a1, ($s0)
/* FC2AC 802D78FC 26100004 */  addiu     $s0, $s0, 4
/* FC2B0 802D7900 0220202D */  daddu     $a0, $s1, $zero
/* FC2B4 802D7904 0C0B210B */  jal       get_float_variable
/* FC2B8 802D7908 0040A82D */   daddu    $s5, $v0, $zero
/* FC2BC 802D790C 8E050000 */  lw        $a1, ($s0)
/* FC2C0 802D7910 26100004 */  addiu     $s0, $s0, 4
/* FC2C4 802D7914 0220202D */  daddu     $a0, $s1, $zero
/* FC2C8 802D7918 0C0B1EAF */  jal       get_variable
/* FC2CC 802D791C 46000686 */   mov.s    $f26, $f0
/* FC2D0 802D7920 8E050000 */  lw        $a1, ($s0)
/* FC2D4 802D7924 26100004 */  addiu     $s0, $s0, 4
/* FC2D8 802D7928 0220202D */  daddu     $a0, $s1, $zero
/* FC2DC 802D792C 0C0B1EAF */  jal       get_variable
/* FC2E0 802D7930 0040A02D */   daddu    $s4, $v0, $zero
/* FC2E4 802D7934 8E050000 */  lw        $a1, ($s0)
/* FC2E8 802D7938 26100004 */  addiu     $s0, $s0, 4
/* FC2EC 802D793C 0220202D */  daddu     $a0, $s1, $zero
/* FC2F0 802D7940 0C0B210B */  jal       get_float_variable
/* FC2F4 802D7944 0040902D */   daddu    $s2, $v0, $zero
/* FC2F8 802D7948 8E050000 */  lw        $a1, ($s0)
/* FC2FC 802D794C 26100004 */  addiu     $s0, $s0, 4
/* FC300 802D7950 0220202D */  daddu     $a0, $s1, $zero
/* FC304 802D7954 0C0B210B */  jal       get_float_variable
/* FC308 802D7958 46000606 */   mov.s    $f24, $f0
/* FC30C 802D795C 8E050000 */  lw        $a1, ($s0)
/* FC310 802D7960 26100004 */  addiu     $s0, $s0, 4
/* FC314 802D7964 0220202D */  daddu     $a0, $s1, $zero
/* FC318 802D7968 0C0B210B */  jal       get_float_variable
/* FC31C 802D796C 46000586 */   mov.s    $f22, $f0
/* FC320 802D7970 0220202D */  daddu     $a0, $s1, $zero
/* FC324 802D7974 8E050000 */  lw        $a1, ($s0)
/* FC328 802D7978 0C0B210B */  jal       get_float_variable
/* FC32C 802D797C 46000506 */   mov.s    $f20, $f0
/* FC330 802D7980 12400006 */  beqz      $s2, .L802D799C
/* FC334 802D7984 3C055555 */   lui      $a1, 0x5555
/* FC338 802D7988 24020001 */  addiu     $v0, $zero, 1
/* FC33C 802D798C 12420018 */  beq       $s2, $v0, .L802D79F0
/* FC340 802D7990 4600C086 */   mov.s    $f2, $f24
/* FC344 802D7994 080B5E9E */  j         .L802D7A78
/* FC348 802D7998 4600B106 */   mov.s    $f4, $f22
.L802D799C:
/* FC34C 802D799C 3C028011 */  lui       $v0, 0x8011
/* FC350 802D79A0 9442F078 */  lhu       $v0, -0xf88($v0)
/* FC354 802D79A4 34A55556 */  ori       $a1, $a1, 0x5556
/* FC358 802D79A8 00021400 */  sll       $v0, $v0, 0x10
/* FC35C 802D79AC 00022403 */  sra       $a0, $v0, 0x10
/* FC360 802D79B0 00041840 */  sll       $v1, $a0, 1
/* FC364 802D79B4 00650018 */  mult      $v1, $a1
/* FC368 802D79B8 44801000 */  mtc1      $zero, $f2
/* FC36C 802D79BC 00003010 */  mfhi      $a2
/* FC370 802D79C0 2407FFFF */  addiu     $a3, $zero, -1
/* FC374 802D79C4 46001186 */  mov.s     $f6, $f2
/* FC378 802D79C8 00850018 */  mult      $a0, $a1
/* FC37C 802D79CC 00031FC3 */  sra       $v1, $v1, 0x1f
/* FC380 802D79D0 000217C3 */  sra       $v0, $v0, 0x1f
/* FC384 802D79D4 00C31823 */  subu      $v1, $a2, $v1
/* FC388 802D79D8 44832000 */  mtc1      $v1, $f4
/* FC38C 802D79DC 00000000 */  nop       
/* FC390 802D79E0 46802120 */  cvt.s.w   $f4, $f4
/* FC394 802D79E4 00004810 */  mfhi      $t1
/* FC398 802D79E8 080B5E97 */  j         .L802D7A5C
/* FC39C 802D79EC 01221023 */   subu     $v0, $t1, $v0
.L802D79F0:
/* FC3A0 802D79F0 0220202D */  daddu     $a0, $s1, $zero
/* FC3A4 802D79F4 0C0B36B0 */  jal       resolve_npc
/* FC3A8 802D79F8 0260282D */   daddu    $a1, $s3, $zero
/* FC3AC 802D79FC 0040382D */  daddu     $a3, $v0, $zero
/* FC3B0 802D7A00 10E0002A */  beqz      $a3, .L802D7AAC
/* FC3B4 802D7A04 3C036666 */   lui      $v1, 0x6666
/* FC3B8 802D7A08 94E200A8 */  lhu       $v0, 0xa8($a3)
/* FC3BC 802D7A0C 34636667 */  ori       $v1, $v1, 0x6667
/* FC3C0 802D7A10 00021400 */  sll       $v0, $v0, 0x10
/* FC3C4 802D7A14 00023403 */  sra       $a2, $v0, 0x10
/* FC3C8 802D7A18 00062080 */  sll       $a0, $a2, 2
/* FC3CC 802D7A1C 00830018 */  mult      $a0, $v1
/* FC3D0 802D7A20 3C055555 */  lui       $a1, 0x5555
/* FC3D4 802D7A24 34A55556 */  ori       $a1, $a1, 0x5556
/* FC3D8 802D7A28 44801000 */  mtc1      $zero, $f2
/* FC3DC 802D7A2C 00004010 */  mfhi      $t0
/* FC3E0 802D7A30 46001186 */  mov.s     $f6, $f2
/* FC3E4 802D7A34 00081843 */  sra       $v1, $t0, 1
/* FC3E8 802D7A38 00C50018 */  mult      $a2, $a1
/* FC3EC 802D7A3C 000427C3 */  sra       $a0, $a0, 0x1f
/* FC3F0 802D7A40 000217C3 */  sra       $v0, $v0, 0x1f
/* FC3F4 802D7A44 00641823 */  subu      $v1, $v1, $a0
/* FC3F8 802D7A48 44832000 */  mtc1      $v1, $f4
/* FC3FC 802D7A4C 00000000 */  nop       
/* FC400 802D7A50 46802120 */  cvt.s.w   $f4, $f4
/* FC404 802D7A54 00004010 */  mfhi      $t0
/* FC408 802D7A58 01021023 */  subu      $v0, $t0, $v0
.L802D7A5C:
/* FC40C 802D7A5C 00021400 */  sll       $v0, $v0, 0x10
/* FC410 802D7A60 00021403 */  sra       $v0, $v0, 0x10
/* FC414 802D7A64 44820000 */  mtc1      $v0, $f0
/* FC418 802D7A68 00000000 */  nop       
/* FC41C 802D7A6C 46800020 */  cvt.s.w   $f0, $f0
/* FC420 802D7A70 080B5EA1 */  j         .L802D7A84
/* FC424 802D7A74 02A0202D */   daddu    $a0, $s5, $zero
.L802D7A78:
/* FC428 802D7A78 4600A186 */  mov.s     $f6, $f20
/* FC42C 802D7A7C 0000382D */  daddu     $a3, $zero, $zero
/* FC430 802D7A80 02A0202D */  daddu     $a0, $s5, $zero
.L802D7A84:
/* FC434 802D7A84 00E0282D */  daddu     $a1, $a3, $zero
/* FC438 802D7A88 44061000 */  mfc1      $a2, $f2
/* FC43C 802D7A8C 44072000 */  mfc1      $a3, $f4
/* FC440 802D7A90 27A20028 */  addiu     $v0, $sp, 0x28
/* FC444 802D7A94 E7A60010 */  swc1      $f6, 0x10($sp)
/* FC448 802D7A98 E7A00014 */  swc1      $f0, 0x14($sp)
/* FC44C 802D7A9C E7BA0018 */  swc1      $f26, 0x18($sp)
/* FC450 802D7AA0 AFB4001C */  sw        $s4, 0x1c($sp)
/* FC454 802D7AA4 0C01BFA4 */  jal       fx_emote
/* FC458 802D7AA8 AFA20020 */   sw       $v0, 0x20($sp)
.L802D7AAC:
/* FC45C 802D7AAC 24020002 */  addiu     $v0, $zero, 2
/* FC460 802D7AB0 8FBF0048 */  lw        $ra, 0x48($sp)
/* FC464 802D7AB4 8FB50044 */  lw        $s5, 0x44($sp)
/* FC468 802D7AB8 8FB40040 */  lw        $s4, 0x40($sp)
/* FC46C 802D7ABC 8FB3003C */  lw        $s3, 0x3c($sp)
/* FC470 802D7AC0 8FB20038 */  lw        $s2, 0x38($sp)
/* FC474 802D7AC4 8FB10034 */  lw        $s1, 0x34($sp)
/* FC478 802D7AC8 8FB00030 */  lw        $s0, 0x30($sp)
/* FC47C 802D7ACC D7BA0068 */  ldc1      $f26, 0x68($sp)
/* FC480 802D7AD0 D7B80060 */  ldc1      $f24, 0x60($sp)
/* FC484 802D7AD4 D7B60058 */  ldc1      $f22, 0x58($sp)
/* FC488 802D7AD8 D7B40050 */  ldc1      $f20, 0x50($sp)
/* FC48C 802D7ADC 03E00008 */  jr        $ra
/* FC490 802D7AE0 27BD0070 */   addiu    $sp, $sp, 0x70
