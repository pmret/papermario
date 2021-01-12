.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419F0_ECB6F0
/* ECB6F0 802419F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ECB6F4 802419F4 AFBF0010 */  sw        $ra, 0x10($sp)
/* ECB6F8 802419F8 8C82000C */  lw        $v0, 0xc($a0)
/* ECB6FC 802419FC 0C0B53A3 */  jal       func_802D4E8C
/* ECB700 80241A00 8C450000 */   lw       $a1, ($v0)
/* ECB704 80241A04 3C018024 */  lui       $at, %hi(D_802430BC)
/* ECB708 80241A08 AC2230BC */  sw        $v0, %lo(D_802430BC)($at)
/* ECB70C 80241A0C 24020002 */  addiu     $v0, $zero, 2
/* ECB710 80241A10 8FBF0010 */  lw        $ra, 0x10($sp)
/* ECB714 80241A14 24030001 */  addiu     $v1, $zero, 1
/* ECB718 80241A18 3C018024 */  lui       $at, %hi(func_802430B8_8B3128)
/* ECB71C 80241A1C AC2330B8 */  sw        $v1, %lo(func_802430B8_8B3128)($at)
/* ECB720 80241A20 03E00008 */  jr        $ra
/* ECB724 80241A24 27BD0018 */   addiu    $sp, $sp, 0x18
