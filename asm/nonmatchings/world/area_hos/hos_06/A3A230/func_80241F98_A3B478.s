.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F98_A3B478
/* A3B478 80241F98 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A3B47C 80241F9C AFBF0010 */  sw        $ra, 0x10($sp)
/* A3B480 80241FA0 8C82000C */  lw        $v0, 0xc($a0)
/* A3B484 80241FA4 0C0B1EAF */  jal       get_variable
/* A3B488 80241FA8 8C450000 */   lw       $a1, ($v0)
/* A3B48C 80241FAC 8C44000C */  lw        $a0, 0xc($v0)
/* A3B490 80241FB0 8C83001C */  lw        $v1, 0x1c($a0)
/* A3B494 80241FB4 24630001 */  addiu     $v1, $v1, 1
/* A3B498 80241FB8 AC83001C */  sw        $v1, 0x1c($a0)
/* A3B49C 80241FBC 8FBF0010 */  lw        $ra, 0x10($sp)
/* A3B4A0 80241FC0 24020002 */  addiu     $v0, $zero, 2
/* A3B4A4 80241FC4 03E00008 */  jr        $ra
/* A3B4A8 80241FC8 27BD0018 */   addiu    $sp, $sp, 0x18
/* A3B4AC 80241FCC 00000000 */  nop       
