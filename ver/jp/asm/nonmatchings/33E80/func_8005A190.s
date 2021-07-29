.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005A190
/* 35590 8005A190 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 35594 8005A194 AFB20018 */  sw        $s2, 0x18($sp)
/* 35598 8005A198 0000902D */  daddu     $s2, $zero, $zero
/* 3559C 8005A19C AFB10014 */  sw        $s1, 0x14($sp)
/* 355A0 8005A1A0 3C11800B */  lui       $s1, %hi(D_800B4378)
/* 355A4 8005A1A4 26314378 */  addiu     $s1, $s1, %lo(D_800B4378)
/* 355A8 8005A1A8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 355AC 8005A1AC AFB00010 */  sw        $s0, 0x10($sp)
.L8005A1B0:
/* 355B0 8005A1B0 8E300000 */  lw        $s0, ($s1)
/* 355B4 8005A1B4 5200000E */  beql      $s0, $zero, .L8005A1F0
/* 355B8 8005A1B8 26520001 */   addiu    $s2, $s2, 1
/* 355BC 8005A1BC 8E020000 */  lw        $v0, ($s0)
/* 355C0 8005A1C0 30420004 */  andi      $v0, $v0, 4
/* 355C4 8005A1C4 5040000A */  beql      $v0, $zero, .L8005A1F0
/* 355C8 8005A1C8 26520001 */   addiu    $s2, $s2, 1
/* 355CC 8005A1CC 8E04000C */  lw        $a0, 0xc($s0)
/* 355D0 8005A1D0 10800003 */  beqz      $a0, .L8005A1E0
/* 355D4 8005A1D4 00000000 */   nop
/* 355D8 8005A1D8 0C00AB0E */  jal       func_8002AC38
/* 355DC 8005A1DC 00000000 */   nop
.L8005A1E0:
/* 355E0 8005A1E0 0C00AB0E */  jal       func_8002AC38
/* 355E4 8005A1E4 0200202D */   daddu    $a0, $s0, $zero
/* 355E8 8005A1E8 AE200000 */  sw        $zero, ($s1)
/* 355EC 8005A1EC 26520001 */  addiu     $s2, $s2, 1
.L8005A1F0:
/* 355F0 8005A1F0 2A420060 */  slti      $v0, $s2, 0x60
/* 355F4 8005A1F4 1440FFEE */  bnez      $v0, .L8005A1B0
/* 355F8 8005A1F8 26310004 */   addiu    $s1, $s1, 4
/* 355FC 8005A1FC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 35600 8005A200 8FB20018 */  lw        $s2, 0x18($sp)
/* 35604 8005A204 8FB10014 */  lw        $s1, 0x14($sp)
/* 35608 8005A208 8FB00010 */  lw        $s0, 0x10($sp)
/* 3560C 8005A20C 03E00008 */  jr        $ra
/* 35610 8005A210 27BD0020 */   addiu    $sp, $sp, 0x20
