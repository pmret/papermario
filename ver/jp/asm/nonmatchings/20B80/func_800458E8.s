.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800458E8
/* 20CE8 800458E8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 20CEC 800458EC AFB10014 */  sw        $s1, 0x14($sp)
/* 20CF0 800458F0 0000882D */  daddu     $s1, $zero, $zero
/* 20CF4 800458F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 20CF8 800458F8 3C10800A */  lui       $s0, %hi(D_8009E9D0)
/* 20CFC 800458FC 2610E9D0 */  addiu     $s0, $s0, %lo(D_8009E9D0)
/* 20D00 80045900 AFBF0018 */  sw        $ra, 0x18($sp)
.L80045904:
/* 20D04 80045904 86020010 */  lh        $v0, 0x10($s0)
/* 20D08 80045908 50400007 */  beql      $v0, $zero, .L80045928
/* 20D0C 8004590C 26310001 */   addiu    $s1, $s1, 1
/* 20D10 80045910 8E02000C */  lw        $v0, 0xc($s0)
/* 20D14 80045914 50400004 */  beql      $v0, $zero, .L80045928
/* 20D18 80045918 26310001 */   addiu    $s1, $s1, 1
/* 20D1C 8004591C 0040F809 */  jalr      $v0
/* 20D20 80045920 0200202D */   daddu    $a0, $s0, $zero
/* 20D24 80045924 26310001 */  addiu     $s1, $s1, 1
.L80045928:
/* 20D28 80045928 2A220020 */  slti      $v0, $s1, 0x20
/* 20D2C 8004592C 1440FFF5 */  bnez      $v0, .L80045904
/* 20D30 80045930 2610001C */   addiu    $s0, $s0, 0x1c
/* 20D34 80045934 8FBF0018 */  lw        $ra, 0x18($sp)
/* 20D38 80045938 8FB10014 */  lw        $s1, 0x14($sp)
/* 20D3C 8004593C 8FB00010 */  lw        $s0, 0x10($sp)
/* 20D40 80045940 03E00008 */  jr        $ra
/* 20D44 80045944 27BD0020 */   addiu    $sp, $sp, 0x20
