.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80060D90
/* 3C190 80060D90 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3C194 80060D94 AFB00010 */  sw        $s0, 0x10($sp)
/* 3C198 80060D98 00808021 */  addu      $s0, $a0, $zero
/* 3C19C 80060D9C AFB10014 */  sw        $s1, 0x14($sp)
/* 3C1A0 80060DA0 00A08821 */  addu      $s1, $a1, $zero
/* 3C1A4 80060DA4 AFB20018 */  sw        $s2, 0x18($sp)
/* 3C1A8 80060DA8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 3C1AC 80060DAC 0C01851D */  jal       func_80061474
/* 3C1B0 80060DB0 00C09021 */   addu     $s2, $a2, $zero
/* 3C1B4 80060DB4 02002021 */  addu      $a0, $s0, $zero
/* 3C1B8 80060DB8 02202821 */  addu      $a1, $s1, $zero
/* 3C1BC 80060DBC 0C01AD54 */  jal       func_8006B550
/* 3C1C0 80060DC0 02403021 */   addu     $a2, $s2, $zero
/* 3C1C4 80060DC4 0C018538 */  jal       func_800614E0
/* 3C1C8 80060DC8 00408021 */   addu     $s0, $v0, $zero
/* 3C1CC 80060DCC 02001021 */  addu      $v0, $s0, $zero
/* 3C1D0 80060DD0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 3C1D4 80060DD4 8FB20018 */  lw        $s2, 0x18($sp)
/* 3C1D8 80060DD8 8FB10014 */  lw        $s1, 0x14($sp)
/* 3C1DC 80060DDC 8FB00010 */  lw        $s0, 0x10($sp)
/* 3C1E0 80060DE0 03E00008 */  jr        $ra
/* 3C1E4 80060DE4 27BD0020 */   addiu    $sp, $sp, 0x20
/* 3C1E8 80060DE8 00000000 */  nop
/* 3C1EC 80060DEC 00000000 */  nop
