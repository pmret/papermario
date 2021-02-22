.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005EAE0
/* 39EE0 8005EAE0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 39EE4 8005EAE4 AFB00010 */  sw        $s0, 0x10($sp)
/* 39EE8 8005EAE8 0080802D */  daddu     $s0, $a0, $zero
/* 39EEC 8005EAEC AFB20018 */  sw        $s2, 0x18($sp)
/* 39EF0 8005EAF0 00A0902D */  daddu     $s2, $a1, $zero
/* 39EF4 8005EAF4 AFB10014 */  sw        $s1, 0x14($sp)
/* 39EF8 8005EAF8 00C0882D */  daddu     $s1, $a2, $zero
/* 39EFC 8005EAFC AFBF001C */  sw        $ra, 0x1c($sp)
/* 39F00 8005EB00 0C018244 */  jal       func_80060910
/* 39F04 8005EB04 24040001 */   addiu    $a0, $zero, 1
/* 39F08 8005EB08 3C05800E */  lui       $a1, %hi(D_800DAA88)
/* 39F0C 8005EB0C 24A5AA88 */  addiu     $a1, $a1, %lo(D_800DAA88)
/* 39F10 8005EB10 AE120004 */  sw        $s2, 4($s0)
/* 39F14 8005EB14 8CA30000 */  lw        $v1, ($a1)
/* 39F18 8005EB18 A6110008 */  sh        $s1, 8($s0)
/* 39F1C 8005EB1C 32310002 */  andi      $s1, $s1, 2
/* 39F20 8005EB20 AE030000 */  sw        $v1, ($s0)
/* 39F24 8005EB24 ACB00000 */  sw        $s0, ($a1)
/* 39F28 8005EB28 12200008 */  beqz      $s1, .L8005EB4C
/* 39F2C 8005EB2C 0040802D */   daddu    $s0, $v0, $zero
/* 39F30 8005EB30 3C02800A */  lui       $v0, %hi(D_8009A590)
/* 39F34 8005EB34 9042A590 */  lbu       $v0, %lo(D_8009A590)($v0)
/* 39F38 8005EB38 10400004 */  beqz      $v0, .L8005EB4C
/* 39F3C 8005EB3C 0240202D */   daddu    $a0, $s2, $zero
/* 39F40 8005EB40 24A5F99A */  addiu     $a1, $a1, -0x666
/* 39F44 8005EB44 0C0195FC */  jal       func_800657F0
/* 39F48 8005EB48 0000302D */   daddu    $a2, $zero, $zero
.L8005EB4C:
/* 39F4C 8005EB4C 0C018244 */  jal       func_80060910
/* 39F50 8005EB50 0200202D */   daddu    $a0, $s0, $zero
/* 39F54 8005EB54 8FBF001C */  lw        $ra, 0x1c($sp)
/* 39F58 8005EB58 8FB20018 */  lw        $s2, 0x18($sp)
/* 39F5C 8005EB5C 8FB10014 */  lw        $s1, 0x14($sp)
/* 39F60 8005EB60 8FB00010 */  lw        $s0, 0x10($sp)
/* 39F64 8005EB64 03E00008 */  jr        $ra
/* 39F68 8005EB68 27BD0020 */   addiu    $sp, $sp, 0x20
