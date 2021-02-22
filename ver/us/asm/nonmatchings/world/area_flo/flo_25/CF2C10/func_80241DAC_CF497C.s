.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DAC_CF497C
/* CF497C 80241DAC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF4980 80241DB0 AFBF0010 */  sw        $ra, 0x10($sp)
/* CF4984 80241DB4 8C82000C */  lw        $v0, 0xc($a0)
/* CF4988 80241DB8 0C0B1EAF */  jal       get_variable
/* CF498C 80241DBC 8C450000 */   lw       $a1, ($v0)
/* CF4990 80241DC0 3C018024 */  lui       $at, %hi(D_80242AD0_CF56A0)
/* CF4994 80241DC4 AC222AD0 */  sw        $v0, %lo(D_80242AD0_CF56A0)($at)
/* CF4998 80241DC8 24020002 */  addiu     $v0, $zero, 2
/* CF499C 80241DCC 8FBF0010 */  lw        $ra, 0x10($sp)
/* CF49A0 80241DD0 24030001 */  addiu     $v1, $zero, 1
/* CF49A4 80241DD4 3C018024 */  lui       $at, %hi(D_80242ACC_CF569C)
/* CF49A8 80241DD8 AC232ACC */  sw        $v1, %lo(D_80242ACC_CF569C)($at)
/* CF49AC 80241DDC 03E00008 */  jr        $ra
/* CF49B0 80241DE0 27BD0018 */   addiu    $sp, $sp, 0x18
