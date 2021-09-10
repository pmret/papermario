.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024078C_B20CCC
/* B20CCC 8024078C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B20CD0 80240790 AFBF0010 */  sw        $ra, 0x10($sp)
/* B20CD4 80240794 8C82000C */  lw        $v0, 0xc($a0)
/* B20CD8 80240798 0C0B1EAF */  jal       evt_get_variable
/* B20CDC 8024079C 8C450000 */   lw       $a1, ($v0)
/* B20CE0 802407A0 3C018024 */  lui       $at, %hi(D_80242430_B22970)
/* B20CE4 802407A4 AC222430 */  sw        $v0, %lo(D_80242430_B22970)($at)
/* B20CE8 802407A8 24020002 */  addiu     $v0, $zero, 2
/* B20CEC 802407AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* B20CF0 802407B0 24030001 */  addiu     $v1, $zero, 1
/* B20CF4 802407B4 3C018024 */  lui       $at, %hi(D_8024242C_B2296C)
/* B20CF8 802407B8 AC23242C */  sw        $v1, %lo(D_8024242C_B2296C)($at)
/* B20CFC 802407BC 03E00008 */  jr        $ra
/* B20D00 802407C0 27BD0018 */   addiu    $sp, $sp, 0x18
