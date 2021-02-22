.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F18_ACF058
/* ACF058 80240F18 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ACF05C 80240F1C AFBF0010 */  sw        $ra, 0x10($sp)
/* ACF060 80240F20 8C82000C */  lw        $v0, 0xc($a0)
/* ACF064 80240F24 3C068011 */  lui       $a2, %hi(gPlayerStatus+0xC)
/* ACF068 80240F28 80C6EFD4 */  lb        $a2, %lo(gPlayerStatus+0xC)($a2)
/* ACF06C 80240F2C 0C0B2026 */  jal       set_variable
/* ACF070 80240F30 8C450000 */   lw       $a1, ($v0)
/* ACF074 80240F34 8FBF0010 */  lw        $ra, 0x10($sp)
/* ACF078 80240F38 24020002 */  addiu     $v0, $zero, 2
/* ACF07C 80240F3C 03E00008 */  jr        $ra
/* ACF080 80240F40 27BD0018 */   addiu    $sp, $sp, 0x18
