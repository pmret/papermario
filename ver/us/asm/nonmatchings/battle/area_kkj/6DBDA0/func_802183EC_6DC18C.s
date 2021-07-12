.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802183EC_6DC18C
/* 6DC18C 802183EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6DC190 802183F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 6DC194 802183F4 0080802D */  daddu     $s0, $a0, $zero
/* 6DC198 802183F8 10A00010 */  beqz      $a1, .L8021843C
/* 6DC19C 802183FC AFBF0014 */   sw       $ra, 0x14($sp)
/* 6DC1A0 80218400 24040001 */  addiu     $a0, $zero, 1
/* 6DC1A4 80218404 0000282D */  daddu     $a1, $zero, $zero
/* 6DC1A8 80218408 00A0302D */  daddu     $a2, $a1, $zero
/* 6DC1AC 8021840C 00A0382D */  daddu     $a3, $a1, $zero
/* 6DC1B0 80218410 2402001E */  addiu     $v0, $zero, 0x1e
/* 6DC1B4 80218414 0C04DF93 */  jal       set_screen_overlay_center
/* 6DC1B8 80218418 AE020070 */   sw       $v0, 0x70($s0)
/* 6DC1BC 8021841C 24040001 */  addiu     $a0, $zero, 1
/* 6DC1C0 80218420 0080282D */  daddu     $a1, $a0, $zero
/* 6DC1C4 80218424 24060140 */  addiu     $a2, $zero, 0x140
/* 6DC1C8 80218428 0C04DF93 */  jal       set_screen_overlay_center
/* 6DC1CC 8021842C 240700F0 */   addiu    $a3, $zero, 0xf0
/* 6DC1D0 80218430 3C054316 */  lui       $a1, 0x4316
/* 6DC1D4 80218434 0C04DF69 */  jal       set_screen_overlay_params_back
/* 6DC1D8 80218438 2404000C */   addiu    $a0, $zero, 0xc
.L8021843C:
/* 6DC1DC 8021843C 8E020070 */  lw        $v0, 0x70($s0)
/* 6DC1E0 80218440 14400010 */  bnez      $v0, .L80218484
/* 6DC1E4 80218444 2442FFFF */   addiu    $v0, $v0, -1
/* 6DC1E8 80218448 24040001 */  addiu     $a0, $zero, 1
/* 6DC1EC 8021844C 0000282D */  daddu     $a1, $zero, $zero
/* 6DC1F0 80218450 00A0302D */  daddu     $a2, $a1, $zero
/* 6DC1F4 80218454 0C04DF93 */  jal       set_screen_overlay_center
/* 6DC1F8 80218458 00A0382D */   daddu    $a3, $a1, $zero
/* 6DC1FC 8021845C 24040001 */  addiu     $a0, $zero, 1
/* 6DC200 80218460 0080282D */  daddu     $a1, $a0, $zero
/* 6DC204 80218464 24060140 */  addiu     $a2, $zero, 0x140
/* 6DC208 80218468 0C04DF93 */  jal       set_screen_overlay_center
/* 6DC20C 8021846C 240700F0 */   addiu    $a3, $zero, 0xf0
/* 6DC210 80218470 3C05BF80 */  lui       $a1, 0xbf80
/* 6DC214 80218474 0C04DF69 */  jal       set_screen_overlay_params_back
/* 6DC218 80218478 240400FF */   addiu    $a0, $zero, 0xff
/* 6DC21C 8021847C 08086123 */  j         .L8021848C
/* 6DC220 80218480 24020002 */   addiu    $v0, $zero, 2
.L80218484:
/* 6DC224 80218484 AE020070 */  sw        $v0, 0x70($s0)
/* 6DC228 80218488 0000102D */  daddu     $v0, $zero, $zero
.L8021848C:
/* 6DC22C 8021848C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6DC230 80218490 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DC234 80218494 03E00008 */  jr        $ra
/* 6DC238 80218498 27BD0018 */   addiu    $sp, $sp, 0x18
