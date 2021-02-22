.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411A0_D51190
/* D51190 802411A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D51194 802411A4 AFBF0010 */  sw        $ra, 0x10($sp)
/* D51198 802411A8 8C82000C */  lw        $v0, 0xc($a0)
/* D5119C 802411AC 0C0B1EAF */  jal       get_variable
/* D511A0 802411B0 8C450000 */   lw       $a1, ($v0)
/* D511A4 802411B4 3C018024 */  lui       $at, %hi(D_80242AD0_D52AC0)
/* D511A8 802411B8 AC222AD0 */  sw        $v0, %lo(D_80242AD0_D52AC0)($at)
/* D511AC 802411BC 24020002 */  addiu     $v0, $zero, 2
/* D511B0 802411C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* D511B4 802411C4 24030001 */  addiu     $v1, $zero, 1
/* D511B8 802411C8 3C018024 */  lui       $at, %hi(D_80242ACC_D52ABC)
/* D511BC 802411CC AC232ACC */  sw        $v1, %lo(D_80242ACC_D52ABC)($at)
/* D511C0 802411D0 03E00008 */  jr        $ra
/* D511C4 802411D4 27BD0018 */   addiu    $sp, $sp, 0x18
