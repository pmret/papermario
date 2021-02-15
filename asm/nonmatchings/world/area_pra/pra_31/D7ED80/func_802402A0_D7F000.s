.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402A0_D7F000
/* D7F000 802402A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D7F004 802402A4 AFBF0010 */  sw        $ra, 0x10($sp)
/* D7F008 802402A8 8C82000C */  lw        $v0, 0xc($a0)
/* D7F00C 802402AC 0C0B1EAF */  jal       get_variable
/* D7F010 802402B0 8C450000 */   lw       $a1, ($v0)
/* D7F014 802402B4 3C018024 */  lui       $at, %hi(D_802411A0_D7FF00)
/* D7F018 802402B8 AC2211A0 */  sw        $v0, %lo(D_802411A0_D7FF00)($at)
/* D7F01C 802402BC 24020002 */  addiu     $v0, $zero, 2
/* D7F020 802402C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* D7F024 802402C4 24030001 */  addiu     $v1, $zero, 1
/* D7F028 802402C8 3C018024 */  lui       $at, %hi(D_8024119C_D7FEFC)
/* D7F02C 802402CC AC23119C */  sw        $v1, %lo(D_8024119C_D7FEFC)($at)
/* D7F030 802402D0 03E00008 */  jr        $ra
/* D7F034 802402D4 27BD0018 */   addiu    $sp, $sp, 0x18
