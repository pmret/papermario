.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411A0_D65780
/* D65780 802411A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D65784 802411A4 AFBF0010 */  sw        $ra, 0x10($sp)
/* D65788 802411A8 8C82000C */  lw        $v0, 0xc($a0)
/* D6578C 802411AC 0C0B1EAF */  jal       get_variable
/* D65790 802411B0 8C450000 */   lw       $a1, ($v0)
/* D65794 802411B4 3C018024 */  lui       $at, %hi(D_802422D0)
/* D65798 802411B8 AC2222D0 */  sw        $v0, %lo(D_802422D0)($at)
/* D6579C 802411BC 24020002 */  addiu     $v0, $zero, 2
/* D657A0 802411C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* D657A4 802411C4 24030001 */  addiu     $v1, $zero, 1
/* D657A8 802411C8 3C018024 */  lui       $at, %hi(D_802422CC)
/* D657AC 802411CC AC2322CC */  sw        $v1, %lo(D_802422CC)($at)
/* D657B0 802411D0 03E00008 */  jr        $ra
/* D657B4 802411D4 27BD0018 */   addiu    $sp, $sp, 0x18
