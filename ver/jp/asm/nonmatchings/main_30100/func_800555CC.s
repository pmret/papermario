.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800555CC
/* 309CC 800555CC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 309D0 800555D0 AFB00030 */  sw        $s0, 0x30($sp)
/* 309D4 800555D4 3C108008 */  lui       $s0, %hi(D_80078D80)
/* 309D8 800555D8 26108D80 */  addiu     $s0, $s0, %lo(D_80078D80)
/* 309DC 800555DC 24020001 */  addiu     $v0, $zero, 1
/* 309E0 800555E0 AFBF0034 */  sw        $ra, 0x34($sp)
/* 309E4 800555E4 AE020000 */  sw        $v0, ($s0)
/* 309E8 800555E8 2402007F */  addiu     $v0, $zero, 0x7f
/* 309EC 800555EC AFA40010 */  sw        $a0, 0x10($sp)
/* 309F0 800555F0 27A40010 */  addiu     $a0, $sp, 0x10
/* 309F4 800555F4 AFA00014 */  sw        $zero, 0x14($sp)
/* 309F8 800555F8 AFA20018 */  sw        $v0, 0x18($sp)
/* 309FC 800555FC AFA2001C */  sw        $v0, 0x1c($sp)
/* 30A00 80055600 AFA00020 */  sw        $zero, 0x20($sp)
/* 30A04 80055604 0C013524 */  jal       func_8004D490
/* 30A08 80055608 AFA00024 */   sw       $zero, 0x24($sp)
/* 30A0C 8005560C AE000000 */  sw        $zero, ($s0)
/* 30A10 80055610 8FBF0034 */  lw        $ra, 0x34($sp)
/* 30A14 80055614 8FB00030 */  lw        $s0, 0x30($sp)
/* 30A18 80055618 03E00008 */  jr        $ra
/* 30A1C 8005561C 27BD0038 */   addiu    $sp, $sp, 0x38
