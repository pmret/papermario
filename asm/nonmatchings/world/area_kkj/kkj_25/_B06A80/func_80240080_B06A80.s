.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240080_B06A80
/* B06A80 80240080 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B06A84 80240084 AFBF0010 */  sw        $ra, 0x10($sp)
/* B06A88 80240088 8C82000C */  lw        $v0, 0xc($a0)
/* B06A8C 8024008C 3C068016 */  lui       $a2, 0x8016
/* B06A90 80240090 84C6A552 */  lh        $a2, -0x5aae($a2)
/* B06A94 80240094 0C0B2026 */  jal       set_variable
/* B06A98 80240098 8C450000 */   lw       $a1, ($v0)
/* B06A9C 8024009C 8FBF0010 */  lw        $ra, 0x10($sp)
/* B06AA0 802400A0 24020002 */  addiu     $v0, $zero, 2
/* B06AA4 802400A4 03E00008 */  jr        $ra
/* B06AA8 802400A8 27BD0018 */   addiu    $sp, $sp, 0x18
