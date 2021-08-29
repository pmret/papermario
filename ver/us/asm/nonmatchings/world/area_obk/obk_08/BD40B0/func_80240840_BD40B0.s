.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240840_BD40B0
/* BD40B0 80240840 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BD40B4 80240844 AFBF0010 */  sw        $ra, 0x10($sp)
/* BD40B8 80240848 8C82000C */  lw        $v0, 0xc($a0)
/* BD40BC 8024084C 0C0B1EAF */  jal       evt_get_variable
/* BD40C0 80240850 8C450000 */   lw       $a1, ($v0)
/* BD40C4 80240854 24040064 */  addiu     $a0, $zero, 0x64
/* BD40C8 80240858 0C00A3C2 */  jal       start_rumble
/* BD40CC 8024085C 3045FFFF */   andi     $a1, $v0, 0xffff
/* BD40D0 80240860 8FBF0010 */  lw        $ra, 0x10($sp)
/* BD40D4 80240864 24020002 */  addiu     $v0, $zero, 2
/* BD40D8 80240868 03E00008 */  jr        $ra
/* BD40DC 8024086C 27BD0018 */   addiu    $sp, $sp, 0x18
