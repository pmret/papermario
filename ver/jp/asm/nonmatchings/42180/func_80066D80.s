.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80066D80
/* 42180 80066D80 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 42184 80066D84 AFB00010 */  sw        $s0, 0x10($sp)
/* 42188 80066D88 00808021 */  addu      $s0, $a0, $zero
/* 4218C 80066D8C AFB10014 */  sw        $s1, 0x14($sp)
/* 42190 80066D90 00A08821 */  addu      $s1, $a1, $zero
/* 42194 80066D94 AFB20018 */  sw        $s2, 0x18($sp)
/* 42198 80066D98 AFBF001C */  sw        $ra, 0x1c($sp)
/* 4219C 80066D9C 0C01ACD0 */  jal       func_8006B340
/* 421A0 80066DA0 00C09021 */   addu     $s2, $a2, $zero
/* 421A4 80066DA4 3C038009 */  lui       $v1, %hi(D_80095964)
/* 421A8 80066DA8 8C635964 */  lw        $v1, %lo(D_80095964)($v1)
/* 421AC 80066DAC 00402021 */  addu      $a0, $v0, $zero
/* 421B0 80066DB0 AC700010 */  sw        $s0, 0x10($v1)
/* 421B4 80066DB4 AC710014 */  sw        $s1, 0x14($v1)
/* 421B8 80066DB8 0C01ACEC */  jal       func_8006B3B0
/* 421BC 80066DBC A4720002 */   sh       $s2, 2($v1)
/* 421C0 80066DC0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 421C4 80066DC4 8FB20018 */  lw        $s2, 0x18($sp)
/* 421C8 80066DC8 8FB10014 */  lw        $s1, 0x14($sp)
/* 421CC 80066DCC 8FB00010 */  lw        $s0, 0x10($sp)
/* 421D0 80066DD0 03E00008 */  jr        $ra
/* 421D4 80066DD4 27BD0020 */   addiu    $sp, $sp, 0x20
/* 421D8 80066DD8 00000000 */  nop
/* 421DC 80066DDC 00000000 */  nop
