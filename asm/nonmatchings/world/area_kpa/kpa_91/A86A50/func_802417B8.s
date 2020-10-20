.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417B8
/* A88208 802417B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A8820C 802417BC AFBF0010 */  sw        $ra, 0x10($sp)
/* A88210 802417C0 8C82000C */  lw        $v0, 0xc($a0)
/* A88214 802417C4 3C068011 */  lui       $a2, 0x8011
/* A88218 802417C8 80C6F2A2 */  lb        $a2, -0xd5e($a2)
/* A8821C 802417CC 0C0B2026 */  jal       set_variable
/* A88220 802417D0 8C450000 */   lw       $a1, ($v0)
/* A88224 802417D4 0C03AC5A */  jal       func_800EB168
/* A88228 802417D8 0000202D */   daddu    $a0, $zero, $zero
/* A8822C 802417DC 8FBF0010 */  lw        $ra, 0x10($sp)
/* A88230 802417E0 24020002 */  addiu     $v0, $zero, 2
/* A88234 802417E4 03E00008 */  jr        $ra
/* A88238 802417E8 27BD0018 */   addiu    $sp, $sp, 0x18
