.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403B0_C5AAF0
/* C5AAF0 802403B0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C5AAF4 802403B4 AFBF0010 */  sw        $ra, 0x10($sp)
/* C5AAF8 802403B8 8C82000C */  lw        $v0, 0xc($a0)
/* C5AAFC 802403BC 3C068011 */  lui       $a2, %hi(D_8010EBB0+0x3)
/* C5AB00 802403C0 80C6EBB3 */  lb        $a2, %lo(D_8010EBB0+0x3)($a2)
/* C5AB04 802403C4 0C0B2026 */  jal       set_variable
/* C5AB08 802403C8 8C450000 */   lw       $a1, ($v0)
/* C5AB0C 802403CC 8FBF0010 */  lw        $ra, 0x10($sp)
/* C5AB10 802403D0 24020002 */  addiu     $v0, $zero, 2
/* C5AB14 802403D4 03E00008 */  jr        $ra
/* C5AB18 802403D8 27BD0018 */   addiu    $sp, $sp, 0x18
