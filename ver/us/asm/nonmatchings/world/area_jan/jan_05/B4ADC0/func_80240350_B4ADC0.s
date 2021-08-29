.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240350_B4ADC0
/* B4ADC0 80240350 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* B4ADC4 80240354 AFB10034 */  sw        $s1, 0x34($sp)
/* B4ADC8 80240358 0080882D */  daddu     $s1, $a0, $zero
/* B4ADCC 8024035C AFBF0038 */  sw        $ra, 0x38($sp)
/* B4ADD0 80240360 AFB00030 */  sw        $s0, 0x30($sp)
/* B4ADD4 80240364 10A00016 */  beqz      $a1, .L802403C0
/* B4ADD8 80240368 8E30000C */   lw       $s0, 0xc($s1)
/* B4ADDC 8024036C 8E050000 */  lw        $a1, ($s0)
/* B4ADE0 80240370 0C0B1EAF */  jal       get_variable
/* B4ADE4 80240374 26100004 */   addiu    $s0, $s0, 4
/* B4ADE8 80240378 8E030000 */  lw        $v1, ($s0)
/* B4ADEC 8024037C 0040202D */  daddu     $a0, $v0, $zero
/* B4ADF0 80240380 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B4ADF4 80240384 AE23007C */   sw       $v1, 0x7c($s1)
/* B4ADF8 80240388 0C046B4C */  jal       get_model_from_list_index
/* B4ADFC 8024038C 0040202D */   daddu    $a0, $v0, $zero
/* B4AE00 80240390 0040802D */  daddu     $s0, $v0, $zero
/* B4AE04 80240394 0000202D */  daddu     $a0, $zero, $zero
/* B4AE08 80240398 AE300074 */  sw        $s0, 0x74($s1)
/* B4AE0C 8024039C 8E050098 */  lw        $a1, 0x98($s0)
/* B4AE10 802403A0 8E0700A0 */  lw        $a3, 0xa0($s0)
/* B4AE14 802403A4 0C044898 */  jal       create_shadow_type
/* B4AE18 802403A8 0000302D */   daddu    $a2, $zero, $zero
/* B4AE1C 802403AC 0220202D */  daddu     $a0, $s1, $zero
/* B4AE20 802403B0 8E25007C */  lw        $a1, 0x7c($s1)
/* B4AE24 802403B4 0000302D */  daddu     $a2, $zero, $zero
/* B4AE28 802403B8 0C0B2026 */  jal       evt_set_variable
/* B4AE2C 802403BC AE220078 */   sw       $v0, 0x78($s1)
.L802403C0:
/* B4AE30 802403C0 8E25007C */  lw        $a1, 0x7c($s1)
/* B4AE34 802403C4 0C0B1EAF */  jal       get_variable
/* B4AE38 802403C8 0220202D */   daddu    $a0, $s1, $zero
/* B4AE3C 802403CC 1440002A */  bnez      $v0, .L80240478
/* B4AE40 802403D0 00000000 */   nop
/* B4AE44 802403D4 8E240078 */  lw        $a0, 0x78($s1)
/* B4AE48 802403D8 0C044181 */  jal       get_shadow_by_index
/* B4AE4C 802403DC 8E300074 */   lw       $s0, 0x74($s1)
/* B4AE50 802403E0 27A40018 */  addiu     $a0, $sp, 0x18
/* B4AE54 802403E4 27A5001C */  addiu     $a1, $sp, 0x1c
/* B4AE58 802403E8 27A60020 */  addiu     $a2, $sp, 0x20
/* B4AE5C 802403EC 27A70024 */  addiu     $a3, $sp, 0x24
/* B4AE60 802403F0 27A30028 */  addiu     $v1, $sp, 0x28
/* B4AE64 802403F4 C6000098 */  lwc1      $f0, 0x98($s0)
/* B4AE68 802403F8 C602009C */  lwc1      $f2, 0x9c($s0)
/* B4AE6C 802403FC C60400A0 */  lwc1      $f4, 0xa0($s0)
/* B4AE70 80240400 0040802D */  daddu     $s0, $v0, $zero
/* B4AE74 80240404 E7A00018 */  swc1      $f0, 0x18($sp)
/* B4AE78 80240408 E7A2001C */  swc1      $f2, 0x1c($sp)
/* B4AE7C 8024040C E7A40020 */  swc1      $f4, 0x20($sp)
/* B4AE80 80240410 AFA30010 */  sw        $v1, 0x10($sp)
/* B4AE84 80240414 27A3002C */  addiu     $v1, $sp, 0x2c
/* B4AE88 80240418 0C04497A */  jal       entity_raycast_down
/* B4AE8C 8024041C AFA30014 */   sw       $v1, 0x14($sp)
/* B4AE90 80240420 8FA5002C */  lw        $a1, 0x2c($sp)
/* B4AE94 80240424 0C044A17 */  jal       set_standard_shadow_scale
/* B4AE98 80240428 0200202D */   daddu    $a0, $s0, $zero
/* B4AE9C 8024042C C7A00018 */  lwc1      $f0, 0x18($sp)
/* B4AEA0 80240430 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* B4AEA4 80240434 C7A60020 */  lwc1      $f6, 0x20($sp)
/* B4AEA8 80240438 C7A80024 */  lwc1      $f8, 0x24($sp)
/* B4AEAC 8024043C C604001C */  lwc1      $f4, 0x1c($s0)
/* B4AEB0 80240440 0000102D */  daddu     $v0, $zero, $zero
/* B4AEB4 80240444 AE00002C */  sw        $zero, 0x2c($s0)
/* B4AEB8 80240448 E6000010 */  swc1      $f0, 0x10($s0)
/* B4AEBC 8024044C C6000024 */  lwc1      $f0, 0x24($s0)
/* B4AEC0 80240450 46042100 */  add.s     $f4, $f4, $f4
/* B4AEC4 80240454 E6020014 */  swc1      $f2, 0x14($s0)
/* B4AEC8 80240458 E6060018 */  swc1      $f6, 0x18($s0)
/* B4AECC 8024045C E6080028 */  swc1      $f8, 0x28($s0)
/* B4AED0 80240460 C7A20028 */  lwc1      $f2, 0x28($sp)
/* B4AED4 80240464 46000000 */  add.s     $f0, $f0, $f0
/* B4AED8 80240468 E6020030 */  swc1      $f2, 0x30($s0)
/* B4AEDC 8024046C E604001C */  swc1      $f4, 0x1c($s0)
/* B4AEE0 80240470 08090122 */  j         .L80240488
/* B4AEE4 80240474 E6000024 */   swc1     $f0, 0x24($s0)
.L80240478:
/* B4AEE8 80240478 8E240078 */  lw        $a0, 0x78($s1)
/* B4AEEC 8024047C 0C0448CA */  jal       delete_shadow
/* B4AEF0 80240480 00000000 */   nop
/* B4AEF4 80240484 24020002 */  addiu     $v0, $zero, 2
.L80240488:
/* B4AEF8 80240488 8FBF0038 */  lw        $ra, 0x38($sp)
/* B4AEFC 8024048C 8FB10034 */  lw        $s1, 0x34($sp)
/* B4AF00 80240490 8FB00030 */  lw        $s0, 0x30($sp)
/* B4AF04 80240494 03E00008 */  jr        $ra
/* B4AF08 80240498 27BD0040 */   addiu    $sp, $sp, 0x40
/* B4AF0C 8024049C 00000000 */  nop
