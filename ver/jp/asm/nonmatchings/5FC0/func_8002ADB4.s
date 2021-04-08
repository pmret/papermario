.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002ADB4
/* 61B4 8002ADB4 3C028007 */  lui       $v0, %hi(D_8007417C)
/* 61B8 8002ADB8 8C42417C */  lw        $v0, %lo(D_8007417C)($v0)
/* 61BC 8002ADBC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 61C0 8002ADC0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 61C4 8002ADC4 80420070 */  lb        $v0, 0x70($v0)
/* 61C8 8002ADC8 0080282D */  daddu     $a1, $a0, $zero
/* 61CC 8002ADCC 3C04803E */  lui       $a0, %hi(D_803DA800)
/* 61D0 8002ADD0 2484A800 */  addiu     $a0, $a0, %lo(D_803DA800)
/* 61D4 8002ADD4 14400003 */  bnez      $v0, .L8002ADE4
/* 61D8 8002ADD8 00000000 */   nop
/* 61DC 8002ADDC 3C048027 */  lui       $a0, %hi(D_80268000)
/* 61E0 8002ADE0 24848000 */  addiu     $a0, $a0, %lo(D_80268000)
.L8002ADE4:
/* 61E4 8002ADE4 0C00A477 */  jal       func_800291DC
/* 61E8 8002ADE8 00000000 */   nop
/* 61EC 8002ADEC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 61F0 8002ADF0 03E00008 */  jr        $ra
/* 61F4 8002ADF4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 61F8 8002ADF8 00000000 */  nop
/* 61FC 8002ADFC 00000000 */  nop
