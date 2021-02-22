.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80065E00
/* 41200 80065E00 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 41204 80065E04 AFBF0010 */  sw        $ra, 0x10($sp)
/* 41208 80065E08 3C04800E */  lui       $a0, %hi(D_800DAC88)
/* 4120C 80065E0C 2484AC88 */  addiu     $a0, $a0, %lo(D_800DAC88)
/* 41210 80065E10 00002821 */  addu      $a1, $zero, $zero
/* 41214 80065E14 0C0195FC */  jal       func_800657F0
/* 41218 80065E18 00003021 */   addu     $a2, $zero, $zero
/* 4121C 80065E1C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 41220 80065E20 03E00008 */  jr        $ra
/* 41224 80065E24 27BD0018 */   addiu    $sp, $sp, 0x18
/* 41228 80065E28 00000000 */  nop
/* 4122C 80065E2C 00000000 */  nop
