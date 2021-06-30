.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_stats_init
/* 139E08 80246AC8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 139E0C 80246ACC AFB3001C */  sw        $s3, 0x1c($sp)
/* 139E10 80246AD0 0080982D */  daddu     $s3, $a0, $zero
/* 139E14 80246AD4 AFB00010 */  sw        $s0, 0x10($sp)
/* 139E18 80246AD8 0000802D */  daddu     $s0, $zero, $zero
/* 139E1C 80246ADC AFB20018 */  sw        $s2, 0x18($sp)
/* 139E20 80246AE0 3C128027 */  lui       $s2, %hi(gStatsMenuIconIDs)
/* 139E24 80246AE4 26520150 */  addiu     $s2, $s2, %lo(gStatsMenuIconIDs)
/* 139E28 80246AE8 AFB10014 */  sw        $s1, 0x14($sp)
/* 139E2C 80246AEC 3C118025 */  lui       $s1, %hi(D_8024F330)
/* 139E30 80246AF0 2631F330 */  addiu     $s1, $s1, %lo(D_8024F330)
/* 139E34 80246AF4 AFBF0020 */  sw        $ra, 0x20($sp)
.L80246AF8:
/* 139E38 80246AF8 8E240000 */  lw        $a0, ($s1)
/* 139E3C 80246AFC 26310004 */  addiu     $s1, $s1, 4
/* 139E40 80246B00 0C050529 */  jal       create_hud_element
/* 139E44 80246B04 26100001 */   addiu    $s0, $s0, 1
/* 139E48 80246B08 0040202D */  daddu     $a0, $v0, $zero
/* 139E4C 80246B0C 24050080 */  addiu     $a1, $zero, 0x80
/* 139E50 80246B10 0C051280 */  jal       set_hud_element_flags
/* 139E54 80246B14 AE440000 */   sw       $a0, ($s2)
/* 139E58 80246B18 2A02000C */  slti      $v0, $s0, 0xc
/* 139E5C 80246B1C 1440FFF6 */  bnez      $v0, .L80246AF8
/* 139E60 80246B20 26520004 */   addiu    $s2, $s2, 4
/* 139E64 80246B24 0000802D */  daddu     $s0, $zero, $zero
/* 139E68 80246B28 3C028025 */  lui       $v0, %hi(D_8024F488)
/* 139E6C 80246B2C 2442F488 */  addiu     $v0, $v0, %lo(D_8024F488)
.L80246B30:
/* 139E70 80246B30 AC530010 */  sw        $s3, 0x10($v0)
/* 139E74 80246B34 26100001 */  addiu     $s0, $s0, 1
/* 139E78 80246B38 1A00FFFD */  blez      $s0, .L80246B30
/* 139E7C 80246B3C 24420024 */   addiu    $v0, $v0, 0x24
/* 139E80 80246B40 3C048025 */  lui       $a0, %hi(D_8024F488)
/* 139E84 80246B44 2484F488 */  addiu     $a0, $a0, %lo(D_8024F488)
/* 139E88 80246B48 0C051FCC */  jal       setup_pause_menu_tab
/* 139E8C 80246B4C 24050001 */   addiu    $a1, $zero, 1
/* 139E90 80246B50 24020001 */  addiu     $v0, $zero, 1
/* 139E94 80246B54 A2620000 */  sb        $v0, ($s3)
/* 139E98 80246B58 8FBF0020 */  lw        $ra, 0x20($sp)
/* 139E9C 80246B5C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 139EA0 80246B60 8FB20018 */  lw        $s2, 0x18($sp)
/* 139EA4 80246B64 8FB10014 */  lw        $s1, 0x14($sp)
/* 139EA8 80246B68 8FB00010 */  lw        $s0, 0x10($sp)
/* 139EAC 80246B6C 03E00008 */  jr        $ra
/* 139EB0 80246B70 27BD0028 */   addiu    $sp, $sp, 0x28
