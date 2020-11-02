.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240758_B02FD8
/* B02FD8 80240758 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B02FDC 8024075C AFBF0010 */  sw        $ra, 0x10($sp)
/* B02FE0 80240760 8C82000C */  lw        $v0, 0xc($a0)
/* B02FE4 80240764 3C068011 */  lui       $a2, %hi(gPlayerStatus+0xC)
/* B02FE8 80240768 80C6EFD4 */  lb        $a2, %lo(gPlayerStatus+0xC)($a2)
/* B02FEC 8024076C 0C0B2026 */  jal       set_variable
/* B02FF0 80240770 8C450000 */   lw       $a1, ($v0)
/* B02FF4 80240774 8FBF0010 */  lw        $ra, 0x10($sp)
/* B02FF8 80240778 24020002 */  addiu     $v0, $zero, 2
/* B02FFC 8024077C 03E00008 */  jr        $ra
/* B03000 80240780 27BD0018 */   addiu    $sp, $sp, 0x18
