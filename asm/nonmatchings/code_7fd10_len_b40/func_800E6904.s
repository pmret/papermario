.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E6904
/* 7FDB4 800E6904 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7FDB8 800E6908 AFB10014 */  sw        $s1, 0x14($sp)
/* 7FDBC 800E690C 3C118011 */  lui       $s1, %hi(D_8010EBB0)
/* 7FDC0 800E6910 2631EBB0 */  addiu     $s1, $s1, %lo(D_8010EBB0)
/* 7FDC4 800E6914 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 7FDC8 800E6918 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 7FDCC 800E691C 0040202D */  daddu     $a0, $v0, $zero
/* 7FDD0 800E6920 3C030010 */  lui       $v1, 0x10
/* 7FDD4 800E6924 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7FDD8 800E6928 AFB00010 */  sw        $s0, 0x10($sp)
/* 7FDDC 800E692C 8C820004 */  lw        $v0, 4($a0)
/* 7FDE0 800E6930 809000B4 */  lb        $s0, 0xb4($a0)
/* 7FDE4 800E6934 00431024 */  and       $v0, $v0, $v1
/* 7FDE8 800E6938 14400023 */  bnez      $v0, .L800E69C8
/* 7FDEC 800E693C 0000102D */   daddu    $v0, $zero, $zero
/* 7FDF0 800E6940 82220000 */  lb        $v0, ($s1)
/* 7FDF4 800E6944 1440000A */  bnez      $v0, .L800E6970
/* 7FDF8 800E6948 00000000 */   nop      
/* 7FDFC 800E694C 8C820000 */  lw        $v0, ($a0)
/* 7FE00 800E6950 30421000 */  andi      $v0, $v0, 0x1000
/* 7FE04 800E6954 1440001C */  bnez      $v0, .L800E69C8
/* 7FE08 800E6958 0000102D */   daddu    $v0, $zero, $zero
/* 7FE0C 800E695C 2E020003 */  sltiu     $v0, $s0, 3
/* 7FE10 800E6960 10400019 */  beqz      $v0, .L800E69C8
/* 7FE14 800E6964 0000102D */   daddu    $v0, $zero, $zero
.L800E6968:
/* 7FE18 800E6968 08039A72 */  j         .L800E69C8
/* 7FE1C 800E696C 24020001 */   addiu    $v0, $zero, 1
.L800E6970:
/* 7FE20 800E6970 0C03ACF8 */  jal       partner_player_can_pause
/* 7FE24 800E6974 00000000 */   nop      
/* 7FE28 800E6978 10400012 */  beqz      $v0, .L800E69C4
/* 7FE2C 800E697C 24020006 */   addiu    $v0, $zero, 6
/* 7FE30 800E6980 82230003 */  lb        $v1, 3($s1)
/* 7FE34 800E6984 1062FFF8 */  beq       $v1, $v0, .L800E6968
/* 7FE38 800E6988 24020009 */   addiu    $v0, $zero, 9
/* 7FE3C 800E698C 14620006 */  bne       $v1, $v0, .L800E69A8
/* 7FE40 800E6990 24020008 */   addiu    $v0, $zero, 8
/* 7FE44 800E6994 24020021 */  addiu     $v0, $zero, 0x21
/* 7FE48 800E6998 1602000B */  bne       $s0, $v0, .L800E69C8
/* 7FE4C 800E699C 0000102D */   daddu    $v0, $zero, $zero
/* 7FE50 800E69A0 08039A72 */  j         .L800E69C8
/* 7FE54 800E69A4 24020001 */   addiu    $v0, $zero, 1
.L800E69A8:
/* 7FE58 800E69A8 14620007 */  bne       $v1, $v0, .L800E69C8
/* 7FE5C 800E69AC 0000102D */   daddu    $v0, $zero, $zero
/* 7FE60 800E69B0 24020021 */  addiu     $v0, $zero, 0x21
/* 7FE64 800E69B4 12020004 */  beq       $s0, $v0, .L800E69C8
/* 7FE68 800E69B8 24020001 */   addiu    $v0, $zero, 1
/* 7FE6C 800E69BC 0C05272D */  jal       play_sound
/* 7FE70 800E69C0 2404021D */   addiu    $a0, $zero, 0x21d
.L800E69C4:
/* 7FE74 800E69C4 0000102D */  daddu     $v0, $zero, $zero
.L800E69C8:
/* 7FE78 800E69C8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7FE7C 800E69CC 8FB10014 */  lw        $s1, 0x14($sp)
/* 7FE80 800E69D0 8FB00010 */  lw        $s0, 0x10($sp)
/* 7FE84 800E69D4 03E00008 */  jr        $ra
/* 7FE88 800E69D8 27BD0020 */   addiu    $sp, $sp, 0x20
