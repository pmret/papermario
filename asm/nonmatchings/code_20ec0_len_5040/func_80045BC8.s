.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045BC8
/* 20FC8 80045BC8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 20FCC 80045BCC AFB10014 */  sw        $s1, 0x14($sp)
/* 20FD0 80045BD0 0000882D */  daddu     $s1, $zero, $zero
/* 20FD4 80045BD4 AFB00010 */  sw        $s0, 0x10($sp)
/* 20FD8 80045BD8 3C10800A */  lui       $s0, 0x800a
/* 20FDC 80045BDC 26100BC0 */  addiu     $s0, $s0, 0xbc0
/* 20FE0 80045BE0 AFBF0018 */  sw        $ra, 0x18($sp)
.L80045BE4:
/* 20FE4 80045BE4 86020010 */  lh        $v0, 0x10($s0)
/* 20FE8 80045BE8 50400007 */  beql      $v0, $zero, .L80045C08
/* 20FEC 80045BEC 26310001 */   addiu    $s1, $s1, 1
/* 20FF0 80045BF0 8E020008 */  lw        $v0, 8($s0)
/* 20FF4 80045BF4 50400004 */  beql      $v0, $zero, .L80045C08
/* 20FF8 80045BF8 26310001 */   addiu    $s1, $s1, 1
/* 20FFC 80045BFC 0040F809 */  jalr      $v0
/* 21000 80045C00 0200202D */   daddu    $a0, $s0, $zero
/* 21004 80045C04 26310001 */  addiu     $s1, $s1, 1
.L80045C08:
/* 21008 80045C08 2A220020 */  slti      $v0, $s1, 0x20
/* 2100C 80045C0C 1440FFF5 */  bnez      $v0, .L80045BE4
/* 21010 80045C10 2610001C */   addiu    $s0, $s0, 0x1c
/* 21014 80045C14 8FBF0018 */  lw        $ra, 0x18($sp)
/* 21018 80045C18 8FB10014 */  lw        $s1, 0x14($sp)
/* 2101C 80045C1C 8FB00010 */  lw        $s0, 0x10($sp)
/* 21020 80045C20 03E00008 */  jr        $ra
/* 21024 80045C24 27BD0020 */   addiu    $sp, $sp, 0x20
