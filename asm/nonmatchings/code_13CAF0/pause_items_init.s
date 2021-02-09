.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_items_init
/* 13DA54 8024A714 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 13DA58 8024A718 AFB3001C */  sw        $s3, 0x1c($sp)
/* 13DA5C 8024A71C 0080982D */  daddu     $s3, $a0, $zero
/* 13DA60 8024A720 AFBF0020 */  sw        $ra, 0x20($sp)
/* 13DA64 8024A724 AFB20018 */  sw        $s2, 0x18($sp)
/* 13DA68 8024A728 AFB10014 */  sw        $s1, 0x14($sp)
/* 13DA6C 8024A72C AFB00010 */  sw        $s0, 0x10($sp)
/* 13DA70 8024A730 3C018027 */  lui       $at, %hi(gItemMenuLevel)
/* 13DA74 8024A734 AC2005E0 */  sw        $zero, %lo(gItemMenuLevel)($at)
/* 13DA78 8024A738 3C018027 */  lui       $at, %hi(gItemMenuCurrentTab)
/* 13DA7C 8024A73C AC2005E4 */  sw        $zero, %lo(gItemMenuCurrentTab)($at)
/* 13DA80 8024A740 0C092937 */  jal       pause_items_load_items
/* 13DA84 8024A744 0000202D */   daddu    $a0, $zero, $zero
/* 13DA88 8024A748 0000802D */  daddu     $s0, $zero, $zero
/* 13DA8C 8024A74C 3C128027 */  lui       $s2, %hi(D_802705E8)
/* 13DA90 8024A750 265205E8 */  addiu     $s2, $s2, %lo(D_802705E8)
/* 13DA94 8024A754 3C118025 */  lui       $s1, %hi(D_8024F570)
/* 13DA98 8024A758 2631F570 */  addiu     $s1, $s1, %lo(D_8024F570)
.L8024A75C:
/* 13DA9C 8024A75C 8E240000 */  lw        $a0, ($s1)
/* 13DAA0 8024A760 26310004 */  addiu     $s1, $s1, 4
/* 13DAA4 8024A764 0C050529 */  jal       create_icon
/* 13DAA8 8024A768 26100001 */   addiu    $s0, $s0, 1
/* 13DAAC 8024A76C 0040202D */  daddu     $a0, $v0, $zero
/* 13DAB0 8024A770 24050080 */  addiu     $a1, $zero, 0x80
/* 13DAB4 8024A774 0C051280 */  jal       set_icon_flags
/* 13DAB8 8024A778 AE440000 */   sw       $a0, ($s2)
/* 13DABC 8024A77C 2A020014 */  slti      $v0, $s0, 0x14
/* 13DAC0 8024A780 1440FFF6 */  bnez      $v0, .L8024A75C
/* 13DAC4 8024A784 26520004 */   addiu    $s2, $s2, 4
/* 13DAC8 8024A788 0000802D */  daddu     $s0, $zero, $zero
/* 13DACC 8024A78C 3C028025 */  lui       $v0, %hi(D_8024F5C0)
/* 13DAD0 8024A790 2442F5C0 */  addiu     $v0, $v0, %lo(D_8024F5C0)
.L8024A794:
/* 13DAD4 8024A794 AC530010 */  sw        $s3, 0x10($v0)
/* 13DAD8 8024A798 26100001 */  addiu     $s0, $s0, 1
/* 13DADC 8024A79C 1A00FFFD */  blez      $s0, .L8024A794
/* 13DAE0 8024A7A0 24420024 */   addiu    $v0, $v0, 0x24
/* 13DAE4 8024A7A4 3C048025 */  lui       $a0, %hi(D_8024F5C0)
/* 13DAE8 8024A7A8 2484F5C0 */  addiu     $a0, $a0, %lo(D_8024F5C0)
/* 13DAEC 8024A7AC 0C051FCC */  jal       setup_pause_menu_tab
/* 13DAF0 8024A7B0 24050001 */   addiu    $a1, $zero, 1
/* 13DAF4 8024A7B4 24020001 */  addiu     $v0, $zero, 1
/* 13DAF8 8024A7B8 A2620000 */  sb        $v0, ($s3)
/* 13DAFC 8024A7BC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 13DB00 8024A7C0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 13DB04 8024A7C4 8FB20018 */  lw        $s2, 0x18($sp)
/* 13DB08 8024A7C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 13DB0C 8024A7CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 13DB10 8024A7D0 03E00008 */  jr        $ra
/* 13DB14 8024A7D4 27BD0028 */   addiu    $sp, $sp, 0x28
