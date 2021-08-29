.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F18_ACBA38
/* ACBA38 80240F18 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ACBA3C 80240F1C AFBF0010 */  sw        $ra, 0x10($sp)
/* ACBA40 80240F20 8C82000C */  lw        $v0, 0xc($a0)
/* ACBA44 80240F24 3C068011 */  lui       $a2, %hi(gPlayerStatus+0xC)
/* ACBA48 80240F28 80C6EFD4 */  lb        $a2, %lo(gPlayerStatus+0xC)($a2)
/* ACBA4C 80240F2C 0C0B2026 */  jal       evt_set_variable
/* ACBA50 80240F30 8C450000 */   lw       $a1, ($v0)
/* ACBA54 80240F34 8FBF0010 */  lw        $ra, 0x10($sp)
/* ACBA58 80240F38 24020002 */  addiu     $v0, $zero, 2
/* ACBA5C 80240F3C 03E00008 */  jr        $ra
/* ACBA60 80240F40 27BD0018 */   addiu    $sp, $sp, 0x18
