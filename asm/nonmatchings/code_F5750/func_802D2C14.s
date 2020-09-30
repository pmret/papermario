.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D2C14
/* F75C4 802D2C14 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F75C8 802D2C18 AFBF0010 */  sw        $ra, 0x10($sp)
/* F75CC 802D2C1C 8C82000C */  lw        $v0, 0xc($a0)
/* F75D0 802D2C20 0C0B1EAF */  jal       get_variable
/* F75D4 802D2C24 8C450000 */   lw       $a1, ($v0)
/* F75D8 802D2C28 0C03BCF5 */  jal       func_800EF3D4
/* F75DC 802D2C2C 0040202D */   daddu    $a0, $v0, $zero
/* F75E0 802D2C30 8FBF0010 */  lw        $ra, 0x10($sp)
/* F75E4 802D2C34 24020002 */  addiu     $v0, $zero, 2
/* F75E8 802D2C38 03E00008 */  jr        $ra
/* F75EC 802D2C3C 27BD0018 */   addiu    $sp, $sp, 0x18
