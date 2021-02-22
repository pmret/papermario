.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240614_CC1444
/* CC1444 80240614 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CC1448 80240618 AFBF0010 */  sw        $ra, 0x10($sp)
/* CC144C 8024061C 8C82000C */  lw        $v0, 0xc($a0)
/* CC1450 80240620 0C0B1EAF */  jal       get_variable
/* CC1454 80240624 8C450000 */   lw       $a1, ($v0)
/* CC1458 80240628 3C018024 */  lui       $at, %hi(D_80241854_CC2684)
/* CC145C 8024062C AC221854 */  sw        $v0, %lo(D_80241854_CC2684)($at)
/* CC1460 80240630 24020002 */  addiu     $v0, $zero, 2
/* CC1464 80240634 8FBF0010 */  lw        $ra, 0x10($sp)
/* CC1468 80240638 24030001 */  addiu     $v1, $zero, 1
/* CC146C 8024063C 3C018024 */  lui       $at, %hi(D_80241850_CC2680)
/* CC1470 80240640 AC231850 */  sw        $v1, %lo(D_80241850_CC2680)($at)
/* CC1474 80240644 03E00008 */  jr        $ra
/* CC1478 80240648 27BD0018 */   addiu    $sp, $sp, 0x18
