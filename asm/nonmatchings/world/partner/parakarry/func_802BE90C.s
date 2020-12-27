.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BE90C
/* 31AE7C 802BE90C 3C02802C */  lui       $v0, %hi(D_802BEBB0)
/* 31AE80 802BE910 8C42EBB0 */  lw        $v0, %lo(D_802BEBB0)($v0)
/* 31AE84 802BE914 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 31AE88 802BE918 AFB00010 */  sw        $s0, 0x10($sp)
/* 31AE8C 802BE91C 0080802D */  daddu     $s0, $a0, $zero
/* 31AE90 802BE920 AFB10014 */  sw        $s1, 0x14($sp)
/* 31AE94 802BE924 3C118011 */  lui       $s1, %hi(D_8010EBB0)
/* 31AE98 802BE928 2631EBB0 */  addiu     $s1, $s1, %lo(D_8010EBB0)
/* 31AE9C 802BE92C 10400021 */  beqz      $v0, .L802BE9B4
/* 31AEA0 802BE930 AFBF0018 */   sw       $ra, 0x18($sp)
/* 31AEA4 802BE934 3C02802C */  lui       $v0, %hi(D_802BEBB8)
/* 31AEA8 802BE938 8C42EBB8 */  lw        $v0, %lo(D_802BEBB8)($v0)
/* 31AEAC 802BE93C 10400003 */  beqz      $v0, .L802BE94C
/* 31AEB0 802BE940 00000000 */   nop      
/* 31AEB4 802BE944 0C038050 */  jal       enable_player_static_collisions
/* 31AEB8 802BE948 00000000 */   nop      
.L802BE94C:
/* 31AEBC 802BE94C 3C02802C */  lui       $v0, %hi(D_802BEBB4)
/* 31AEC0 802BE950 8C42EBB4 */  lw        $v0, %lo(D_802BEBB4)($v0)
/* 31AEC4 802BE954 10400003 */  beqz      $v0, .L802BE964
/* 31AEC8 802BE958 00000000 */   nop      
/* 31AECC 802BE95C 0C038069 */  jal       enable_player_input
/* 31AED0 802BE960 00000000 */   nop      
.L802BE964:
/* 31AED4 802BE964 0C039769 */  jal       set_action_state
/* 31AED8 802BE968 0000202D */   daddu    $a0, $zero, $zero
/* 31AEDC 802BE96C 26230018 */  addiu     $v1, $s1, 0x18
/* 31AEE0 802BE970 0200102D */  daddu     $v0, $s0, $zero
/* 31AEE4 802BE974 26040340 */  addiu     $a0, $s0, 0x340
.L802BE978:
/* 31AEE8 802BE978 8C450000 */  lw        $a1, ($v0)
/* 31AEEC 802BE97C 8C460004 */  lw        $a2, 4($v0)
/* 31AEF0 802BE980 8C470008 */  lw        $a3, 8($v0)
/* 31AEF4 802BE984 8C48000C */  lw        $t0, 0xc($v0)
/* 31AEF8 802BE988 AC650000 */  sw        $a1, ($v1)
/* 31AEFC 802BE98C AC660004 */  sw        $a2, 4($v1)
/* 31AF00 802BE990 AC670008 */  sw        $a3, 8($v1)
/* 31AF04 802BE994 AC68000C */  sw        $t0, 0xc($v1)
/* 31AF08 802BE998 24420010 */  addiu     $v0, $v0, 0x10
/* 31AF0C 802BE99C 1444FFF6 */  bne       $v0, $a0, .L802BE978
/* 31AF10 802BE9A0 24630010 */   addiu    $v1, $v1, 0x10
/* 31AF14 802BE9A4 24020001 */  addiu     $v0, $zero, 1
/* 31AF18 802BE9A8 A2220001 */  sb        $v0, 1($s1)
/* 31AF1C 802BE9AC 0C03BD17 */  jal       clear_partner_move_history
/* 31AF20 802BE9B0 0200202D */   daddu    $a0, $s0, $zero
.L802BE9B4:
/* 31AF24 802BE9B4 24020004 */  addiu     $v0, $zero, 4
/* 31AF28 802BE9B8 A2220003 */  sb        $v0, 3($s1)
/* 31AF2C 802BE9BC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 31AF30 802BE9C0 8FB10014 */  lw        $s1, 0x14($sp)
/* 31AF34 802BE9C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 31AF38 802BE9C8 03E00008 */  jr        $ra
/* 31AF3C 802BE9CC 27BD0020 */   addiu    $sp, $sp, 0x20
