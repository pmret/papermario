.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BE9D0_31AF40
/* 31AF40 802BE9D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 31AF44 802BE9D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 31AF48 802BE9D8 3C108011 */  lui       $s0, %hi(D_8010EBB0)
/* 31AF4C 802BE9DC 2610EBB0 */  addiu     $s0, $s0, %lo(D_8010EBB0)
/* 31AF50 802BE9E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 31AF54 802BE9E4 AFB10014 */  sw        $s1, 0x14($sp)
/* 31AF58 802BE9E8 82020001 */  lb        $v0, 1($s0)
/* 31AF5C 802BE9EC 10400023 */  beqz      $v0, .L802BEA7C
/* 31AF60 802BE9F0 0080882D */   daddu    $s1, $a0, $zero
/* 31AF64 802BE9F4 3C02802C */  lui       $v0, %hi(D_802BEBB8)
/* 31AF68 802BE9F8 8C42EBB8 */  lw        $v0, %lo(D_802BEBB8)($v0)
/* 31AF6C 802BE9FC 10400003 */  beqz      $v0, .L802BEA0C
/* 31AF70 802BEA00 00000000 */   nop
/* 31AF74 802BEA04 0C038045 */  jal       disable_player_static_collisions
/* 31AF78 802BEA08 00000000 */   nop
.L802BEA0C:
/* 31AF7C 802BEA0C 3C02802C */  lui       $v0, %hi(D_802BEBB4)
/* 31AF80 802BEA10 8C42EBB4 */  lw        $v0, %lo(D_802BEBB4)($v0)
/* 31AF84 802BEA14 10400003 */  beqz      $v0, .L802BEA24
/* 31AF88 802BEA18 00000000 */   nop
/* 31AF8C 802BEA1C 0C03805E */  jal       disable_player_input
/* 31AF90 802BEA20 00000000 */   nop
.L802BEA24:
/* 31AF94 802BEA24 0C039769 */  jal       set_action_state
/* 31AF98 802BEA28 24040021 */   addiu    $a0, $zero, 0x21
/* 31AF9C 802BEA2C 0220182D */  daddu     $v1, $s1, $zero
/* 31AFA0 802BEA30 26020018 */  addiu     $v0, $s0, 0x18
/* 31AFA4 802BEA34 26040358 */  addiu     $a0, $s0, 0x358
.L802BEA38:
/* 31AFA8 802BEA38 8C450000 */  lw        $a1, ($v0)
/* 31AFAC 802BEA3C 8C460004 */  lw        $a2, 4($v0)
/* 31AFB0 802BEA40 8C470008 */  lw        $a3, 8($v0)
/* 31AFB4 802BEA44 8C48000C */  lw        $t0, 0xc($v0)
/* 31AFB8 802BEA48 AC650000 */  sw        $a1, ($v1)
/* 31AFBC 802BEA4C AC660004 */  sw        $a2, 4($v1)
/* 31AFC0 802BEA50 AC670008 */  sw        $a3, 8($v1)
/* 31AFC4 802BEA54 AC68000C */  sw        $t0, 0xc($v1)
/* 31AFC8 802BEA58 24420010 */  addiu     $v0, $v0, 0x10
/* 31AFCC 802BEA5C 1444FFF6 */  bne       $v0, $a0, .L802BEA38
/* 31AFD0 802BEA60 24630010 */   addiu    $v1, $v1, 0x10
/* 31AFD4 802BEA64 0220202D */  daddu     $a0, $s1, $zero
/* 31AFD8 802BEA68 A2000003 */  sb        $zero, 3($s0)
/* 31AFDC 802BEA6C 0C03BD17 */  jal       clear_partner_move_history
/* 31AFE0 802BEA70 A2000000 */   sb       $zero, ($s0)
/* 31AFE4 802BEA74 0C03ACC5 */  jal       partner_use_ability
/* 31AFE8 802BEA78 00000000 */   nop
.L802BEA7C:
/* 31AFEC 802BEA7C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 31AFF0 802BEA80 8FB10014 */  lw        $s1, 0x14($sp)
/* 31AFF4 802BEA84 8FB00010 */  lw        $s0, 0x10($sp)
/* 31AFF8 802BEA88 03E00008 */  jr        $ra
/* 31AFFC 802BEA8C 27BD0020 */   addiu    $sp, $sp, 0x20
