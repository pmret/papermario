.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80042D0C
/* 1E10C 80042D0C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1E110 80042D10 3C03800B */  lui       $v1, %hi(D_800B0EF0)
/* 1E114 80042D14 24630EF0 */  addiu     $v1, $v1, %lo(D_800B0EF0)
/* 1E118 80042D18 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1E11C 80042D1C 8C620098 */  lw        $v0, 0x98($v1)
/* 1E120 80042D20 1040000B */  beqz      $v0, .L80042D50
/* 1E124 80042D24 00000000 */   nop
/* 1E128 80042D28 C4600090 */  lwc1      $f0, 0x90($v1)
/* 1E12C 80042D2C 46800020 */  cvt.s.w   $f0, $f0
/* 1E130 80042D30 44050000 */  mfc1      $a1, $f0
/* 1E134 80042D34 0C04F38E */  jal       func_8013CE38
/* 1E138 80042D38 0000202D */   daddu    $a0, $zero, $zero
/* 1E13C 80042D3C 0000202D */  daddu     $a0, $zero, $zero
/* 1E140 80042D40 0080282D */  daddu     $a1, $a0, $zero
/* 1E144 80042D44 0080302D */  daddu     $a2, $a0, $zero
/* 1E148 80042D48 0C04F3B0 */  jal       func_8013CEC0
/* 1E14C 80042D4C 0080382D */   daddu    $a3, $a0, $zero
.L80042D50:
/* 1E150 80042D50 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1E154 80042D54 03E00008 */  jr        $ra
/* 1E158 80042D58 27BD0018 */   addiu    $sp, $sp, 0x18
