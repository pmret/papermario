.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E5FB0
/* 107830 802E5FB0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 107834 802E5FB4 AFB00018 */  sw        $s0, 0x18($sp)
/* 107838 802E5FB8 0080802D */  daddu     $s0, $a0, $zero
/* 10783C 802E5FBC 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* 107840 802E5FC0 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* 107844 802E5FC4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 107848 802E5FC8 808300B4 */  lb        $v1, 0xb4($a0)
/* 10784C 802E5FCC 24020021 */  addiu     $v0, $zero, 0x21
/* 107850 802E5FD0 10620020 */  beq       $v1, $v0, .L802E6054
/* 107854 802E5FD4 00000000 */   nop
/* 107858 802E5FD8 92020006 */  lbu       $v0, 6($s0)
/* 10785C 802E5FDC 30420001 */  andi      $v0, $v0, 1
/* 107860 802E5FE0 1040001C */  beqz      $v0, .L802E6054
/* 107864 802E5FE4 24020005 */   addiu    $v0, $zero, 5
/* 107868 802E5FE8 A08200C5 */  sb        $v0, 0xc5($a0)
/* 10786C 802E5FEC 8C820000 */  lw        $v0, ($a0)
/* 107870 802E5FF0 2403FFFB */  addiu     $v1, $zero, -5
/* 107874 802E5FF4 00431024 */  and       $v0, $v0, $v1
/* 107878 802E5FF8 3C030080 */  lui       $v1, 0x80
/* 10787C 802E5FFC 00431025 */  or        $v0, $v0, $v1
/* 107880 802E6000 AC820000 */  sw        $v0, ($a0)
/* 107884 802E6004 86040014 */  lh        $a0, 0x14($s0)
/* 107888 802E6008 3C050000 */  lui       $a1, 0
/* 10788C 802E600C 24A501E4 */  addiu     $a1, $a1, 0x1e4
/* 107890 802E6010 0C048052 */  jal       play_model_animation
/* 107894 802E6014 00000000 */   nop
/* 107898 802E6018 0C04419E */  jal       func_80110678
/* 10789C 802E601C 0200202D */   daddu    $a0, $s0, $zero
/* 1078A0 802E6020 10400003 */  beqz      $v0, .L802E6030
/* 1078A4 802E6024 00000000 */   nop
/* 1078A8 802E6028 0C039769 */  jal       set_action_state
/* 1078AC 802E602C 24040026 */   addiu    $a0, $zero, 0x26
.L802E6030:
/* 1078B0 802E6030 0C043F5A */  jal       exec_entity_updatecmd
/* 1078B4 802E6034 0200202D */   daddu    $a0, $s0, $zero
/* 1078B8 802E6038 C6000050 */  lwc1      $f0, 0x50($s0)
/* 1078BC 802E603C 24042086 */  addiu     $a0, $zero, 0x2086
/* 1078C0 802E6040 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1078C4 802E6044 8E060048 */  lw        $a2, 0x48($s0)
/* 1078C8 802E6048 8E07004C */  lw        $a3, 0x4c($s0)
/* 1078CC 802E604C 0C052757 */  jal       sfx_play_sound_at_position
/* 1078D0 802E6050 0000282D */   daddu    $a1, $zero, $zero
.L802E6054:
/* 1078D4 802E6054 8FBF001C */  lw        $ra, 0x1c($sp)
/* 1078D8 802E6058 8FB00018 */  lw        $s0, 0x18($sp)
/* 1078DC 802E605C 03E00008 */  jr        $ra
/* 1078E0 802E6060 27BD0020 */   addiu    $sp, $sp, 0x20
