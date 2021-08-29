.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218D90_59F470
/* 59F470 80218D90 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 59F474 80218D94 AFB10014 */  sw        $s1, 0x14($sp)
/* 59F478 80218D98 0080882D */  daddu     $s1, $a0, $zero
/* 59F47C 80218D9C AFBF0018 */  sw        $ra, 0x18($sp)
/* 59F480 80218DA0 AFB00010 */  sw        $s0, 0x10($sp)
/* 59F484 80218DA4 8E30000C */  lw        $s0, 0xc($s1)
/* 59F488 80218DA8 8E050000 */  lw        $a1, ($s0)
/* 59F48C 80218DAC 0C0B1EAF */  jal       evt_get_variable
/* 59F490 80218DB0 26100004 */   addiu    $s0, $s0, 4
/* 59F494 80218DB4 8E050000 */  lw        $a1, ($s0)
/* 59F498 80218DB8 8C50000C */  lw        $s0, 0xc($v0)
/* 59F49C 80218DBC 0C0B1EAF */  jal       evt_get_variable
/* 59F4A0 80218DC0 0220202D */   daddu    $a0, $s1, $zero
/* 59F4A4 80218DC4 44820000 */  mtc1      $v0, $f0
/* 59F4A8 80218DC8 00000000 */  nop
/* 59F4AC 80218DCC 46800020 */  cvt.s.w   $f0, $f0
/* 59F4B0 80218DD0 E6000004 */  swc1      $f0, 4($s0)
/* 59F4B4 80218DD4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 59F4B8 80218DD8 8FB10014 */  lw        $s1, 0x14($sp)
/* 59F4BC 80218DDC 8FB00010 */  lw        $s0, 0x10($sp)
/* 59F4C0 80218DE0 24020002 */  addiu     $v0, $zero, 2
/* 59F4C4 80218DE4 03E00008 */  jr        $ra
/* 59F4C8 80218DE8 27BD0020 */   addiu    $sp, $sp, 0x20
/* 59F4CC 80218DEC 00000000 */  nop
