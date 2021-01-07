.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406A8_C965D8
/* C965D8 802406A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C965DC 802406AC AFBF0010 */  sw        $ra, 0x10($sp)
/* C965E0 802406B0 8C82000C */  lw        $v0, 0xc($a0)
/* C965E4 802406B4 0C0B1EAF */  jal       get_variable
/* C965E8 802406B8 8C450000 */   lw       $a1, ($v0)
/* C965EC 802406BC 3C018024 */  lui       $at, %hi(D_802417E8)
/* C965F0 802406C0 AC2217E8 */  sw        $v0, %lo(D_802417E8)($at)
/* C965F4 802406C4 24020002 */  addiu     $v0, $zero, 2
/* C965F8 802406C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* C965FC 802406CC 24030001 */  addiu     $v1, $zero, 1
/* C96600 802406D0 3C018024 */  lui       $at, %hi(D_802417E4)
/* C96604 802406D4 AC2317E4 */  sw        $v1, %lo(D_802417E4)($at)
/* C96608 802406D8 03E00008 */  jr        $ra
/* C9660C 802406DC 27BD0018 */   addiu    $sp, $sp, 0x18
