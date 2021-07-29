.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80060840
/* 3BC40 80060840 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3BC44 80060844 AFB00010 */  sw        $s0, 0x10($sp)
/* 3BC48 80060848 3C10800E */  lui       $s0, %hi(D_800DAC58)
/* 3BC4C 8006084C 2610AC58 */  addiu     $s0, $s0, %lo(D_800DAC58)
/* 3BC50 80060850 AFBF0014 */  sw        $ra, 0x14($sp)
/* 3BC54 80060854 0C018634 */  jal       func_800618D0
/* 3BC58 80060858 0200202D */   daddu    $a0, $s0, $zero
/* 3BC5C 8006085C 14400008 */  bnez      $v0, .L80060880
/* 3BC60 80060860 0200202D */   daddu    $a0, $s0, $zero
/* 3BC64 80060864 0000282D */  daddu     $a1, $zero, $zero
/* 3BC68 80060868 0C0195B0 */  jal       func_800656C0
/* 3BC6C 8006086C 24060001 */   addiu    $a2, $zero, 1
/* 3BC70 80060870 3C04800B */  lui       $a0, %hi(D_800B1B5C)
/* 3BC74 80060874 0C018654 */  jal       func_80061950
/* 3BC78 80060878 24841B5C */   addiu    $a0, $a0, %lo(D_800B1B5C)
/* 3BC7C 8006087C 0000102D */  daddu     $v0, $zero, $zero
.L80060880:
/* 3BC80 80060880 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3BC84 80060884 8FB00010 */  lw        $s0, 0x10($sp)
/* 3BC88 80060888 03E00008 */  jr        $ra
/* 3BC8C 8006088C 27BD0018 */   addiu    $sp, $sp, 0x18
