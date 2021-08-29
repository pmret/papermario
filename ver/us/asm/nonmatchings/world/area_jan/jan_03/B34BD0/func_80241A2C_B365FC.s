.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A2C_B365FC
/* B365FC 80241A2C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B36600 80241A30 AFBF0010 */  sw        $ra, 0x10($sp)
/* B36604 80241A34 8C82000C */  lw        $v0, 0xc($a0)
/* B36608 80241A38 0C0B1EAF */  jal       evt_get_variable
/* B3660C 80241A3C 8C450000 */   lw       $a1, ($v0)
/* B36610 80241A40 3C018024 */  lui       $at, %hi(D_80247448_B3C018)
/* B36614 80241A44 AC227448 */  sw        $v0, %lo(D_80247448_B3C018)($at)
/* B36618 80241A48 24020002 */  addiu     $v0, $zero, 2
/* B3661C 80241A4C 8FBF0010 */  lw        $ra, 0x10($sp)
/* B36620 80241A50 24030001 */  addiu     $v1, $zero, 1
/* B36624 80241A54 3C018024 */  lui       $at, %hi(D_80247444_B3C014)
/* B36628 80241A58 AC237444 */  sw        $v1, %lo(D_80247444_B3C014)($at)
/* B3662C 80241A5C 03E00008 */  jr        $ra
/* B36630 80241A60 27BD0018 */   addiu    $sp, $sp, 0x18
