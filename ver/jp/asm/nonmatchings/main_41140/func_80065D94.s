.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80065D94
/* 41194 80065D94 3C028009 */  lui       $v0, %hi(D_80094620)
/* 41198 80065D98 8C424620 */  lw        $v0, %lo(D_80094620)($v0)
/* 4119C 80065D9C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 411A0 80065DA0 1440000F */  bnez      $v0, .L80065DE0
/* 411A4 80065DA4 AFBF0018 */   sw       $ra, 0x18($sp)
/* 411A8 80065DA8 24020001 */  addiu     $v0, $zero, 1
/* 411AC 80065DAC 3C018009 */  lui       $at, %hi(D_80094620)
/* 411B0 80065DB0 AC224620 */  sw        $v0, %lo(D_80094620)($at)
/* 411B4 80065DB4 3C04800E */  lui       $a0, %hi(D_800DAC88)
/* 411B8 80065DB8 2484AC88 */  addiu     $a0, $a0, %lo(D_800DAC88)
/* 411BC 80065DBC 3C05800B */  lui       $a1, %hi(D_800AF8E0)
/* 411C0 80065DC0 24A5F8E0 */  addiu     $a1, $a1, %lo(D_800AF8E0)
/* 411C4 80065DC4 0C019554 */  jal       func_80065550
/* 411C8 80065DC8 24060001 */   addiu    $a2, $zero, 1
/* 411CC 80065DCC 3C04800E */  lui       $a0, %hi(D_800DAC88)
/* 411D0 80065DD0 2484AC88 */  addiu     $a0, $a0, %lo(D_800DAC88)
/* 411D4 80065DD4 00002821 */  addu      $a1, $zero, $zero
/* 411D8 80065DD8 0C0195FC */  jal       func_800657F0
/* 411DC 80065DDC 00003021 */   addu     $a2, $zero, $zero
.L80065DE0:
/* 411E0 80065DE0 3C04800E */  lui       $a0, %hi(D_800DAC88)
/* 411E4 80065DE4 2484AC88 */  addiu     $a0, $a0, %lo(D_800DAC88)
/* 411E8 80065DE8 27A50010 */  addiu     $a1, $sp, 0x10
/* 411EC 80065DEC 0C0195B0 */  jal       func_800656C0
/* 411F0 80065DF0 24060001 */   addiu    $a2, $zero, 1
/* 411F4 80065DF4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 411F8 80065DF8 03E00008 */  jr        $ra
/* 411FC 80065DFC 27BD0020 */   addiu    $sp, $sp, 0x20
