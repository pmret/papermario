.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418AC_84447C
/* 84447C 802418AC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 844480 802418B0 AFB00010 */  sw        $s0, 0x10($sp)
/* 844484 802418B4 0080802D */  daddu     $s0, $a0, $zero
/* 844488 802418B8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 84448C 802418BC AFB20018 */  sw        $s2, 0x18($sp)
/* 844490 802418C0 AFB10014 */  sw        $s1, 0x14($sp)
/* 844494 802418C4 8E02000C */  lw        $v0, 0xc($s0)
/* 844498 802418C8 0C090612 */  jal       func_80241848_844418
/* 84449C 802418CC 8C520000 */   lw       $s2, ($v0)
/* 8444A0 802418D0 3C118011 */  lui       $s1, %hi(gPlayerData)
/* 8444A4 802418D4 2631F290 */  addiu     $s1, $s1, %lo(gPlayerData)
/* 8444A8 802418D8 82230008 */  lb        $v1, 8($s1)
/* 8444AC 802418DC 0062182A */  slt       $v1, $v1, $v0
/* 8444B0 802418E0 14600005 */  bnez      $v1, .L802418F8
/* 8444B4 802418E4 2403003F */   addiu    $v1, $zero, 0x3f
/* 8444B8 802418E8 0200202D */  daddu     $a0, $s0, $zero
/* 8444BC 802418EC 0240282D */  daddu     $a1, $s2, $zero
/* 8444C0 802418F0 08090648 */  j         .L80241920
/* 8444C4 802418F4 0000302D */   daddu    $a2, $zero, $zero
.L802418F8:
/* 8444C8 802418F8 26220286 */  addiu     $v0, $s1, 0x286
.L802418FC:
/* 8444CC 802418FC A4400000 */  sh        $zero, ($v0)
/* 8444D0 80241900 2463FFFF */  addiu     $v1, $v1, -1
/* 8444D4 80241904 0461FFFD */  bgez      $v1, .L802418FC
/* 8444D8 80241908 2442FFFE */   addiu    $v0, $v0, -2
/* 8444DC 8024190C 0C039E1B */  jal       enforce_hpfp_limits
/* 8444E0 80241910 00000000 */   nop
/* 8444E4 80241914 0200202D */  daddu     $a0, $s0, $zero
/* 8444E8 80241918 0240282D */  daddu     $a1, $s2, $zero
/* 8444EC 8024191C 24060001 */  addiu     $a2, $zero, 1
.L80241920:
/* 8444F0 80241920 0C0B2026 */  jal       set_variable
/* 8444F4 80241924 00000000 */   nop
/* 8444F8 80241928 24020002 */  addiu     $v0, $zero, 2
/* 8444FC 8024192C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 844500 80241930 8FB20018 */  lw        $s2, 0x18($sp)
/* 844504 80241934 8FB10014 */  lw        $s1, 0x14($sp)
/* 844508 80241938 8FB00010 */  lw        $s0, 0x10($sp)
/* 84450C 8024193C 03E00008 */  jr        $ra
/* 844510 80241940 27BD0020 */   addiu    $sp, $sp, 0x20
