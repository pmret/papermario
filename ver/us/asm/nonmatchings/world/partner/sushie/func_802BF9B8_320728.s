.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BF9B8_320728
/* 320728 802BF9B8 3C02802C */  lui       $v0, %hi(D_802BFEEC)
/* 32072C 802BF9BC 8C42FEEC */  lw        $v0, %lo(D_802BFEEC)($v0)
/* 320730 802BF9C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 320734 802BF9C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 320738 802BF9C8 0080802D */  daddu     $s0, $a0, $zero
/* 32073C 802BF9CC AFB10014 */  sw        $s1, 0x14($sp)
/* 320740 802BF9D0 3C118011 */  lui       $s1, %hi(D_8010EBB0)
/* 320744 802BF9D4 2631EBB0 */  addiu     $s1, $s1, %lo(D_8010EBB0)
/* 320748 802BF9D8 10400018 */  beqz      $v0, .L802BFA3C
/* 32074C 802BF9DC AFBF0018 */   sw       $ra, 0x18($sp)
/* 320750 802BF9E0 26230018 */  addiu     $v1, $s1, 0x18
/* 320754 802BF9E4 0200102D */  daddu     $v0, $s0, $zero
/* 320758 802BF9E8 26040340 */  addiu     $a0, $s0, 0x340
.L802BF9EC:
/* 32075C 802BF9EC 8C450000 */  lw        $a1, ($v0)
/* 320760 802BF9F0 8C460004 */  lw        $a2, 4($v0)
/* 320764 802BF9F4 8C470008 */  lw        $a3, 8($v0)
/* 320768 802BF9F8 8C48000C */  lw        $t0, 0xc($v0)
/* 32076C 802BF9FC AC650000 */  sw        $a1, ($v1)
/* 320770 802BFA00 AC660004 */  sw        $a2, 4($v1)
/* 320774 802BFA04 AC670008 */  sw        $a3, 8($v1)
/* 320778 802BFA08 AC68000C */  sw        $t0, 0xc($v1)
/* 32077C 802BFA0C 24420010 */  addiu     $v0, $v0, 0x10
/* 320780 802BFA10 1444FFF6 */  bne       $v0, $a0, .L802BF9EC
/* 320784 802BFA14 24630010 */   addiu    $v1, $v1, 0x10
/* 320788 802BFA18 24020001 */  addiu     $v0, $zero, 1
/* 32078C 802BFA1C 0C038050 */  jal       enable_player_static_collisions
/* 320790 802BFA20 A2220001 */   sb       $v0, 1($s1)
/* 320794 802BFA24 0C038069 */  jal       enable_player_input
/* 320798 802BFA28 00000000 */   nop
/* 32079C 802BFA2C 0C039769 */  jal       set_action_state
/* 3207A0 802BFA30 0000202D */   daddu    $a0, $zero, $zero
/* 3207A4 802BFA34 0C03BD17 */  jal       partner_clear_player_tracking
/* 3207A8 802BFA38 0200202D */   daddu    $a0, $s0, $zero
.L802BFA3C:
/* 3207AC 802BFA3C 24020007 */  addiu     $v0, $zero, 7
/* 3207B0 802BFA40 A2220003 */  sb        $v0, 3($s1)
/* 3207B4 802BFA44 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3207B8 802BFA48 8FB10014 */  lw        $s1, 0x14($sp)
/* 3207BC 802BFA4C 8FB00010 */  lw        $s0, 0x10($sp)
/* 3207C0 802BFA50 03E00008 */  jr        $ra
/* 3207C4 802BFA54 27BD0020 */   addiu    $sp, $sp, 0x20
