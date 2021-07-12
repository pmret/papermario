.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BDD0C_31D87C
/* 31D87C 802BDD0C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 31D880 802BDD10 AFB20018 */  sw        $s2, 0x18($sp)
/* 31D884 802BDD14 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* 31D888 802BDD18 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* 31D88C 802BDD1C AFB10014 */  sw        $s1, 0x14($sp)
/* 31D890 802BDD20 3C118011 */  lui       $s1, %hi(D_8010EBB0)
/* 31D894 802BDD24 2631EBB0 */  addiu     $s1, $s1, %lo(D_8010EBB0)
/* 31D898 802BDD28 AFBF001C */  sw        $ra, 0x1c($sp)
/* 31D89C 802BDD2C AFB00010 */  sw        $s0, 0x10($sp)
/* 31D8A0 802BDD30 10A00011 */  beqz      $a1, .L802BDD78
/* 31D8A4 802BDD34 8C90014C */   lw       $s0, 0x14c($a0)
/* 31D8A8 802BDD38 0C0AF460 */  jal       func_802BD180_31CCF0
/* 31D8AC 802BDD3C 00000000 */   nop
/* 31D8B0 802BDD40 0C03BA65 */  jal       partner_init_put_away
/* 31D8B4 802BDD44 0200202D */   daddu    $a0, $s0, $zero
/* 31D8B8 802BDD48 3C040001 */  lui       $a0, 1
/* 31D8BC 802BDD4C 0C037FD4 */  jal       force_player_anim
/* 31D8C0 802BDD50 34840002 */   ori      $a0, $a0, 2
/* 31D8C4 802BDD54 2402FFFC */  addiu     $v0, $zero, -4
/* 31D8C8 802BDD58 A2200003 */  sb        $zero, 3($s1)
/* 31D8CC 802BDD5C A2200000 */  sb        $zero, ($s1)
/* 31D8D0 802BDD60 8E430004 */  lw        $v1, 4($s2)
/* 31D8D4 802BDD64 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* 31D8D8 802BDD68 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* 31D8DC 802BDD6C 00621824 */  and       $v1, $v1, $v0
/* 31D8E0 802BDD70 AE430004 */  sw        $v1, 4($s2)
/* 31D8E4 802BDD74 A080007D */  sb        $zero, 0x7d($a0)
.L802BDD78:
/* 31D8E8 802BDD78 0C03BA6E */  jal       partner_put_away
/* 31D8EC 802BDD7C 0200202D */   daddu    $a0, $s0, $zero
/* 31D8F0 802BDD80 8FBF001C */  lw        $ra, 0x1c($sp)
/* 31D8F4 802BDD84 8FB20018 */  lw        $s2, 0x18($sp)
/* 31D8F8 802BDD88 8FB10014 */  lw        $s1, 0x14($sp)
/* 31D8FC 802BDD8C 8FB00010 */  lw        $s0, 0x10($sp)
/* 31D900 802BDD90 0002102B */  sltu      $v0, $zero, $v0
/* 31D904 802BDD94 03E00008 */  jr        $ra
/* 31D908 802BDD98 27BD0020 */   addiu    $sp, $sp, 0x20
