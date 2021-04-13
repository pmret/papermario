.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80060230
/* 3B630 80060230 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 3B634 80060234 AFB00030 */  sw        $s0, 0x30($sp)
/* 3B638 80060238 3C10800E */  lui       $s0, %hi(D_800DAC58)
/* 3B63C 8006023C 2610AC58 */  addiu     $s0, $s0, %lo(D_800DAC58)
/* 3B640 80060240 0200202D */  daddu     $a0, $s0, $zero
/* 3B644 80060244 3C05800B */  lui       $a1, %hi(D_800AC4E0)
/* 3B648 80060248 24A5C4E0 */  addiu     $a1, $a1, %lo(D_800AC4E0)
/* 3B64C 8006024C AFBF0034 */  sw        $ra, 0x34($sp)
/* 3B650 80060250 0C019554 */  jal       func_80065550
/* 3B654 80060254 24060008 */   addiu    $a2, $zero, 8
/* 3B658 80060258 24040005 */  addiu     $a0, $zero, 5
/* 3B65C 8006025C 0200282D */  daddu     $a1, $s0, $zero
/* 3B660 80060260 0C019648 */  jal       func_80065920
/* 3B664 80060264 0000302D */   daddu    $a2, $zero, $zero
/* 3B668 80060268 0200202D */  daddu     $a0, $s0, $zero
/* 3B66C 8006026C 27A50028 */  addiu     $a1, $sp, 0x28
/* 3B670 80060270 0C0186D4 */  jal       func_80061B50
/* 3B674 80060274 27A60018 */   addiu    $a2, $sp, 0x18
/* 3B678 80060278 3C10800B */  lui       $s0, %hi(D_800AC500)
/* 3B67C 8006027C 2610C500 */  addiu     $s0, $s0, %lo(D_800AC500)
/* 3B680 80060280 0200202D */  daddu     $a0, $s0, $zero
/* 3B684 80060284 24050006 */  addiu     $a1, $zero, 6
/* 3B688 80060288 3C068006 */  lui       $a2, %hi(func_800600A0)
/* 3B68C 8006028C 24C600A0 */  addiu     $a2, $a2, %lo(func_800600A0)
/* 3B690 80060290 3C02800B */  lui       $v0, %hi(D_800AE6B0)
/* 3B694 80060294 2442E6B0 */  addiu     $v0, $v0, %lo(D_800AE6B0)
/* 3B698 80060298 AFA20010 */  sw        $v0, 0x10($sp)
/* 3B69C 8006029C 24020073 */  addiu     $v0, $zero, 0x73
/* 3B6A0 800602A0 0000382D */  daddu     $a3, $zero, $zero
/* 3B6A4 800602A4 0C01978C */  jal       func_80065E30
/* 3B6A8 800602A8 AFA20014 */   sw       $v0, 0x14($sp)
/* 3B6AC 800602AC 0C0197FC */  jal       func_80065FF0
/* 3B6B0 800602B0 0200202D */   daddu    $a0, $s0, $zero
/* 3B6B4 800602B4 93A20028 */  lbu       $v0, 0x28($sp)
/* 3B6B8 800602B8 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3B6BC 800602BC 8FB00030 */  lw        $s0, 0x30($sp)
/* 3B6C0 800602C0 03E00008 */  jr        $ra
/* 3B6C4 800602C4 27BD0038 */   addiu    $sp, $sp, 0x38
