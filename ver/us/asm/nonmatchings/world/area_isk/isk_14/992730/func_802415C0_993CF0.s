.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415C0_993CF0
/* 993CF0 802415C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 993CF4 802415C4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 993CF8 802415C8 AFB10014 */  sw        $s1, 0x14($sp)
/* 993CFC 802415CC AFB00010 */  sw        $s0, 0x10($sp)
/* 993D00 802415D0 8C84014C */  lw        $a0, 0x14c($a0)
/* 993D04 802415D4 0C00EAD2 */  jal       get_npc_safe
/* 993D08 802415D8 0000882D */   daddu    $s1, $zero, $zero
/* 993D0C 802415DC 8C500020 */  lw        $s0, 0x20($v0)
.L802415E0:
/* 993D10 802415E0 8E040000 */  lw        $a0, ($s0)
/* 993D14 802415E4 26310001 */  addiu     $s1, $s1, 1
/* 993D18 802415E8 0C00E273 */  jal       npc_free
/* 993D1C 802415EC 26100010 */   addiu    $s0, $s0, 0x10
/* 993D20 802415F0 2A220008 */  slti      $v0, $s1, 8
/* 993D24 802415F4 1440FFFA */  bnez      $v0, .L802415E0
/* 993D28 802415F8 24020002 */   addiu    $v0, $zero, 2
/* 993D2C 802415FC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 993D30 80241600 8FB10014 */  lw        $s1, 0x14($sp)
/* 993D34 80241604 8FB00010 */  lw        $s0, 0x10($sp)
/* 993D38 80241608 03E00008 */  jr        $ra
/* 993D3C 8024160C 27BD0020 */   addiu    $sp, $sp, 0x20
