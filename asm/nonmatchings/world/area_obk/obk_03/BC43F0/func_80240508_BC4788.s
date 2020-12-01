.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240508_BC4788
/* BC4788 80240508 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BC478C 8024050C AFBF0010 */  sw        $ra, 0x10($sp)
/* BC4790 80240510 8C82000C */  lw        $v0, 0xc($a0)
/* BC4794 80240514 0C0B1EAF */  jal       get_variable
/* BC4798 80240518 8C450000 */   lw       $a1, ($v0)
/* BC479C 8024051C 3C018024 */  lui       $at, %hi(D_80242F34)
/* BC47A0 80240520 AC222F34 */  sw        $v0, %lo(D_80242F34)($at)
/* BC47A4 80240524 24020002 */  addiu     $v0, $zero, 2
/* BC47A8 80240528 8FBF0010 */  lw        $ra, 0x10($sp)
/* BC47AC 8024052C 24030001 */  addiu     $v1, $zero, 1
/* BC47B0 80240530 3C018024 */  lui       $at, %hi(D_80242F30)
/* BC47B4 80240534 AC232F30 */  sw        $v1, %lo(D_80242F30)($at)
/* BC47B8 80240538 03E00008 */  jr        $ra
/* BC47BC 8024053C 27BD0018 */   addiu    $sp, $sp, 0x18
