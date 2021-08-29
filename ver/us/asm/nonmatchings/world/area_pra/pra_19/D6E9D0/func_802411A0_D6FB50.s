.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411A0_D6FB50
/* D6FB50 802411A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D6FB54 802411A4 AFBF0010 */  sw        $ra, 0x10($sp)
/* D6FB58 802411A8 8C82000C */  lw        $v0, 0xc($a0)
/* D6FB5C 802411AC 0C0B1EAF */  jal       evt_get_variable
/* D6FB60 802411B0 8C450000 */   lw       $a1, ($v0)
/* D6FB64 802411B4 3C018024 */  lui       $at, %hi(D_802421A0_D70B50)
/* D6FB68 802411B8 AC2221A0 */  sw        $v0, %lo(D_802421A0_D70B50)($at)
/* D6FB6C 802411BC 24020002 */  addiu     $v0, $zero, 2
/* D6FB70 802411C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* D6FB74 802411C4 24030001 */  addiu     $v1, $zero, 1
/* D6FB78 802411C8 3C018024 */  lui       $at, %hi(D_8024219C_D70B4C)
/* D6FB7C 802411CC AC23219C */  sw        $v1, %lo(D_8024219C_D70B4C)($at)
/* D6FB80 802411D0 03E00008 */  jr        $ra
/* D6FB84 802411D4 27BD0018 */   addiu    $sp, $sp, 0x18
