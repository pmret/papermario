.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800555E4
/* 309E4 800555E4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 309E8 800555E8 AFB00010 */  sw        $s0, 0x10($sp)
/* 309EC 800555EC AFBF0014 */  sw        $ra, 0x14($sp)
/* 309F0 800555F0 0C01430C */  jal       func_80050C30
/* 309F4 800555F4 0080802D */   daddu    $s0, $a0, $zero
/* 309F8 800555F8 14400003 */  bnez      $v0, .L80055608
/* 309FC 800555FC 00000000 */   nop      
/* 30A00 80055600 0C014414 */  jal       func_80051050
/* 30A04 80055604 0200202D */   daddu    $a0, $s0, $zero
.L80055608:
/* 30A08 80055608 8FBF0014 */  lw        $ra, 0x14($sp)
/* 30A0C 8005560C 8FB00010 */  lw        $s0, 0x10($sp)
/* 30A10 80055610 03E00008 */  jr        $ra
/* 30A14 80055614 27BD0018 */   addiu    $sp, $sp, 0x18
