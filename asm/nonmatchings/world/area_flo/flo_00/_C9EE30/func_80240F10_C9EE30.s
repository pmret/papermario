.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F10_C9EE30
/* C9EE30 80240F10 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C9EE34 80240F14 AFB00010 */  sw        $s0, 0x10($sp)
/* C9EE38 80240F18 0080802D */  daddu     $s0, $a0, $zero
/* C9EE3C 80240F1C AFB20018 */  sw        $s2, 0x18($sp)
/* C9EE40 80240F20 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* C9EE44 80240F24 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* C9EE48 80240F28 AFBF001C */  sw        $ra, 0x1c($sp)
/* C9EE4C 80240F2C AFB10014 */  sw        $s1, 0x14($sp)
/* C9EE50 80240F30 C64000A8 */  lwc1      $f0, 0xa8($s2)
/* C9EE54 80240F34 8E02000C */  lw        $v0, 0xc($s0)
/* C9EE58 80240F38 4600008D */  trunc.w.s $f2, $f0
/* C9EE5C 80240F3C 44061000 */  mfc1      $a2, $f2
/* C9EE60 80240F40 8C450000 */  lw        $a1, ($v0)
/* C9EE64 80240F44 0C0B2026 */  jal       set_variable
/* C9EE68 80240F48 8C510004 */   lw       $s1, 4($v0)
/* C9EE6C 80240F4C 0200202D */  daddu     $a0, $s0, $zero
/* C9EE70 80240F50 C6400080 */  lwc1      $f0, 0x80($s2)
/* C9EE74 80240F54 4600008D */  trunc.w.s $f2, $f0
/* C9EE78 80240F58 44061000 */  mfc1      $a2, $f2
/* C9EE7C 80240F5C 0C0B2026 */  jal       set_variable
/* C9EE80 80240F60 0220282D */   daddu    $a1, $s1, $zero
/* C9EE84 80240F64 8FBF001C */  lw        $ra, 0x1c($sp)
/* C9EE88 80240F68 8FB20018 */  lw        $s2, 0x18($sp)
/* C9EE8C 80240F6C 8FB10014 */  lw        $s1, 0x14($sp)
/* C9EE90 80240F70 8FB00010 */  lw        $s0, 0x10($sp)
/* C9EE94 80240F74 24020002 */  addiu     $v0, $zero, 2
/* C9EE98 80240F78 03E00008 */  jr        $ra
/* C9EE9C 80240F7C 27BD0020 */   addiu    $sp, $sp, 0x20
