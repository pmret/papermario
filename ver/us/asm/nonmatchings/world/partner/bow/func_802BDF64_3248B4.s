.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BDF64_3248B4
/* 3248B4 802BDF64 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3248B8 802BDF68 AFB00010 */  sw        $s0, 0x10($sp)
/* 3248BC 802BDF6C AFB20018 */  sw        $s2, 0x18($sp)
/* 3248C0 802BDF70 3C12802C */  lui       $s2, %hi(D_802BE0C0)
/* 3248C4 802BDF74 2652E0C0 */  addiu     $s2, $s2, %lo(D_802BE0C0)
/* 3248C8 802BDF78 AFBF001C */  sw        $ra, 0x1c($sp)
/* 3248CC 802BDF7C AFB10014 */  sw        $s1, 0x14($sp)
/* 3248D0 802BDF80 8E420000 */  lw        $v0, ($s2)
/* 3248D4 802BDF84 3C118011 */  lui       $s1, %hi(D_8010EBB0)
/* 3248D8 802BDF88 2631EBB0 */  addiu     $s1, $s1, %lo(D_8010EBB0)
/* 3248DC 802BDF8C 1040000E */  beqz      $v0, .L802BDFC8
/* 3248E0 802BDF90 0080802D */   daddu    $s0, $a0, $zero
/* 3248E4 802BDF94 0C038069 */  jal       enable_player_input
/* 3248E8 802BDF98 00000000 */   nop
/* 3248EC 802BDF9C 0C039769 */  jal       set_action_state
/* 3248F0 802BDFA0 0000202D */   daddu    $a0, $zero, $zero
/* 3248F4 802BDFA4 0C03BD17 */  jal       clear_partner_move_history
/* 3248F8 802BDFA8 0200202D */   daddu    $a0, $s0, $zero
/* 3248FC 802BDFAC A2200000 */  sb        $zero, ($s1)
/* 324900 802BDFB0 A2200003 */  sb        $zero, 3($s1)
/* 324904 802BDFB4 AE400000 */  sw        $zero, ($s2)
/* 324908 802BDFB8 8E020000 */  lw        $v0, ($s0)
/* 32490C 802BDFBC 2403FFFD */  addiu     $v1, $zero, -3
/* 324910 802BDFC0 00431024 */  and       $v0, $v0, $v1
/* 324914 802BDFC4 AE020000 */  sw        $v0, ($s0)
.L802BDFC8:
/* 324918 802BDFC8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 32491C 802BDFCC 8FB20018 */  lw        $s2, 0x18($sp)
/* 324920 802BDFD0 8FB10014 */  lw        $s1, 0x14($sp)
/* 324924 802BDFD4 8FB00010 */  lw        $s0, 0x10($sp)
/* 324928 802BDFD8 03E00008 */  jr        $ra
/* 32492C 802BDFDC 27BD0020 */   addiu    $sp, $sp, 0x20
