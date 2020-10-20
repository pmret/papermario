.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240660_B5E910
/* B5E910 80240660 3C03800A */  lui       $v1, %hi(D_8009A650)
/* B5E914 80240664 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* B5E918 80240668 8C620000 */  lw        $v0, ($v1)
/* B5E91C 8024066C 34420040 */  ori       $v0, $v0, 0x40
/* B5E920 80240670 AC620000 */  sw        $v0, ($v1)
/* B5E924 80240674 03E00008 */  jr        $ra
/* B5E928 80240678 24020002 */   addiu    $v0, $zero, 2
