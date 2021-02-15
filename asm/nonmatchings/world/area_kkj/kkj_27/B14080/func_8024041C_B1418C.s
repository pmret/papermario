.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024041C_B1418C
/* B1418C 8024041C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B14190 80240420 AFBF0010 */  sw        $ra, 0x10($sp)
/* B14194 80240424 8C82000C */  lw        $v0, 0xc($a0)
/* B14198 80240428 0C0B1EAF */  jal       get_variable
/* B1419C 8024042C 8C450000 */   lw       $a1, ($v0)
/* B141A0 80240430 8FBF0010 */  lw        $ra, 0x10($sp)
/* B141A4 80240434 3C018024 */  lui       $at, %hi(D_80240B00_B14870)
/* B141A8 80240438 AC220B00 */  sw        $v0, %lo(D_80240B00_B14870)($at)
/* B141AC 8024043C 24020002 */  addiu     $v0, $zero, 2
/* B141B0 80240440 03E00008 */  jr        $ra
/* B141B4 80240444 27BD0018 */   addiu    $sp, $sp, 0x18
