.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CFC_9C60DC
/* 9C60DC 80240CFC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C60E0 80240D00 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C60E4 80240D04 8C82000C */  lw        $v0, 0xc($a0)
/* 9C60E8 80240D08 3C068011 */  lui       $a2, 0x8011
/* 9C60EC 80240D0C 80C6F2A2 */  lb        $a2, -0xd5e($a2)
/* 9C60F0 80240D10 0C0B2026 */  jal       set_variable
/* 9C60F4 80240D14 8C450000 */   lw       $a1, ($v0)
/* 9C60F8 80240D18 0C03AC5A */  jal       func_800EB168
/* 9C60FC 80240D1C 0000202D */   daddu    $a0, $zero, $zero
/* 9C6100 80240D20 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C6104 80240D24 24020002 */  addiu     $v0, $zero, 2
/* 9C6108 80240D28 03E00008 */  jr        $ra
/* 9C610C 80240D2C 27BD0018 */   addiu    $sp, $sp, 0x18
