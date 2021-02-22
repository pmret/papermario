.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415C0_97F090
/* 97F090 802415C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 97F094 802415C4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 97F098 802415C8 AFB10014 */  sw        $s1, 0x14($sp)
/* 97F09C 802415CC AFB00010 */  sw        $s0, 0x10($sp)
/* 97F0A0 802415D0 8C84014C */  lw        $a0, 0x14c($a0)
/* 97F0A4 802415D4 0C00EAD2 */  jal       get_npc_safe
/* 97F0A8 802415D8 0000882D */   daddu    $s1, $zero, $zero
/* 97F0AC 802415DC 8C500020 */  lw        $s0, 0x20($v0)
.L802415E0:
/* 97F0B0 802415E0 8E040000 */  lw        $a0, ($s0)
/* 97F0B4 802415E4 26310001 */  addiu     $s1, $s1, 1
/* 97F0B8 802415E8 0C00E273 */  jal       free_npc
/* 97F0BC 802415EC 26100010 */   addiu    $s0, $s0, 0x10
/* 97F0C0 802415F0 2A220008 */  slti      $v0, $s1, 8
/* 97F0C4 802415F4 1440FFFA */  bnez      $v0, .L802415E0
/* 97F0C8 802415F8 24020002 */   addiu    $v0, $zero, 2
/* 97F0CC 802415FC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 97F0D0 80241600 8FB10014 */  lw        $s1, 0x14($sp)
/* 97F0D4 80241604 8FB00010 */  lw        $s0, 0x10($sp)
/* 97F0D8 80241608 03E00008 */  jr        $ra
/* 97F0DC 8024160C 27BD0020 */   addiu    $sp, $sp, 0x20
