.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406A8_EB1508
/* EB1508 802406A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EB150C 802406AC AFBF0010 */  sw        $ra, 0x10($sp)
/* EB1510 802406B0 8C82000C */  lw        $v0, 0xc($a0)
/* EB1514 802406B4 0C0B53A3 */  jal       func_802D4E8C
/* EB1518 802406B8 8C450000 */   lw       $a1, ($v0)
/* EB151C 802406BC 3C018024 */  lui       $at, %hi(D_802417E8_EB2648)
/* EB1520 802406C0 AC2217E8 */  sw        $v0, %lo(D_802417E8_EB2648)($at)
/* EB1524 802406C4 24020002 */  addiu     $v0, $zero, 2
/* EB1528 802406C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* EB152C 802406CC 24030001 */  addiu     $v1, $zero, 1
/* EB1530 802406D0 3C018024 */  lui       $at, %hi(D_802417E4_EB2644)
/* EB1534 802406D4 AC2317E4 */  sw        $v1, %lo(D_802417E4_EB2644)($at)
/* EB1538 802406D8 03E00008 */  jr        $ra
/* EB153C 802406DC 27BD0018 */   addiu    $sp, $sp, 0x18
