.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BFA00_323550
/* 323550 802BFA00 3C02802C */  lui       $v0, %hi(D_802BFF0C)
/* 323554 802BFA04 8C42FF0C */  lw        $v0, %lo(D_802BFF0C)($v0)
/* 323558 802BFA08 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 32355C 802BFA0C AFB00010 */  sw        $s0, 0x10($sp)
/* 323560 802BFA10 0080802D */  daddu     $s0, $a0, $zero
/* 323564 802BFA14 AFB10014 */  sw        $s1, 0x14($sp)
/* 323568 802BFA18 3C118011 */  lui       $s1, %hi(D_8010EBB0)
/* 32356C 802BFA1C 2631EBB0 */  addiu     $s1, $s1, %lo(D_8010EBB0)
/* 323570 802BFA20 10400018 */  beqz      $v0, .L802BFA84
/* 323574 802BFA24 AFBF0018 */   sw       $ra, 0x18($sp)
/* 323578 802BFA28 26230018 */  addiu     $v1, $s1, 0x18
/* 32357C 802BFA2C 0200102D */  daddu     $v0, $s0, $zero
/* 323580 802BFA30 26040340 */  addiu     $a0, $s0, 0x340
.L802BFA34:
/* 323584 802BFA34 8C450000 */  lw        $a1, ($v0)
/* 323588 802BFA38 8C460004 */  lw        $a2, 4($v0)
/* 32358C 802BFA3C 8C470008 */  lw        $a3, 8($v0)
/* 323590 802BFA40 8C48000C */  lw        $t0, 0xc($v0)
/* 323594 802BFA44 AC650000 */  sw        $a1, ($v1)
/* 323598 802BFA48 AC660004 */  sw        $a2, 4($v1)
/* 32359C 802BFA4C AC670008 */  sw        $a3, 8($v1)
/* 3235A0 802BFA50 AC68000C */  sw        $t0, 0xc($v1)
/* 3235A4 802BFA54 24420010 */  addiu     $v0, $v0, 0x10
/* 3235A8 802BFA58 1444FFF6 */  bne       $v0, $a0, .L802BFA34
/* 3235AC 802BFA5C 24630010 */   addiu    $v1, $v1, 0x10
/* 3235B0 802BFA60 24020001 */  addiu     $v0, $zero, 1
/* 3235B4 802BFA64 0C038050 */  jal       enable_player_static_collisions
/* 3235B8 802BFA68 A2220001 */   sb       $v0, 1($s1)
/* 3235BC 802BFA6C 0C038069 */  jal       enable_player_input
/* 3235C0 802BFA70 00000000 */   nop
/* 3235C4 802BFA74 0C039769 */  jal       set_action_state
/* 3235C8 802BFA78 0000202D */   daddu    $a0, $zero, $zero
/* 3235CC 802BFA7C 0C03BD17 */  jal       clear_partner_move_history
/* 3235D0 802BFA80 0200202D */   daddu    $a0, $s0, $zero
.L802BFA84:
/* 3235D4 802BFA84 24020008 */  addiu     $v0, $zero, 8
/* 3235D8 802BFA88 A2220003 */  sb        $v0, 3($s1)
/* 3235DC 802BFA8C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3235E0 802BFA90 8FB10014 */  lw        $s1, 0x14($sp)
/* 3235E4 802BFA94 8FB00010 */  lw        $s0, 0x10($sp)
/* 3235E8 802BFA98 3C01802C */  lui       $at, %hi(D_802BFF18)
/* 3235EC 802BFA9C AC20FF18 */  sw        $zero, %lo(D_802BFF18)($at)
/* 3235F0 802BFAA0 03E00008 */  jr        $ra
/* 3235F4 802BFAA4 27BD0020 */   addiu    $sp, $sp, 0x20
