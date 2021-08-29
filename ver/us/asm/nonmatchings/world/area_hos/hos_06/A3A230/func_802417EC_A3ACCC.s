.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417EC_A3ACCC
/* A3ACCC 802417EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A3ACD0 802417F0 AFB10014 */  sw        $s1, 0x14($sp)
/* A3ACD4 802417F4 0080882D */  daddu     $s1, $a0, $zero
/* A3ACD8 802417F8 AFBF0018 */  sw        $ra, 0x18($sp)
/* A3ACDC 802417FC AFB00010 */  sw        $s0, 0x10($sp)
/* A3ACE0 80241800 8E30000C */  lw        $s0, 0xc($s1)
/* A3ACE4 80241804 8E050000 */  lw        $a1, ($s0)
/* A3ACE8 80241808 0C0B1EAF */  jal       get_variable
/* A3ACEC 8024180C 26100004 */   addiu    $s0, $s0, 4
/* A3ACF0 80241810 3C038011 */  lui       $v1, %hi(gPlayerData+0xC)
/* A3ACF4 80241814 8463F29C */  lh        $v1, %lo(gPlayerData+0xC)($v1)
/* A3ACF8 80241818 3C018024 */  lui       $at, %hi(D_802447D0_A3DCB0)
/* A3ACFC 8024181C 00220821 */  addu      $at, $at, $v0
/* A3AD00 80241820 902247D0 */  lbu       $v0, %lo(D_802447D0_A3DCB0)($at)
/* A3AD04 80241824 8E050000 */  lw        $a1, ($s0)
/* A3AD08 80241828 0062182A */  slt       $v1, $v1, $v0
/* A3AD0C 8024182C 10600003 */  beqz      $v1, .L8024183C
/* A3AD10 80241830 0220202D */   daddu    $a0, $s1, $zero
/* A3AD14 80241834 08090610 */  j         .L80241840
/* A3AD18 80241838 24060001 */   addiu    $a2, $zero, 1
.L8024183C:
/* A3AD1C 8024183C 0000302D */  daddu     $a2, $zero, $zero
.L80241840:
/* A3AD20 80241840 0C0B2026 */  jal       evt_set_variable
/* A3AD24 80241844 00000000 */   nop
/* A3AD28 80241848 8FBF0018 */  lw        $ra, 0x18($sp)
/* A3AD2C 8024184C 8FB10014 */  lw        $s1, 0x14($sp)
/* A3AD30 80241850 8FB00010 */  lw        $s0, 0x10($sp)
/* A3AD34 80241854 24020002 */  addiu     $v0, $zero, 2
/* A3AD38 80241858 03E00008 */  jr        $ra
/* A3AD3C 8024185C 27BD0020 */   addiu    $sp, $sp, 0x20
