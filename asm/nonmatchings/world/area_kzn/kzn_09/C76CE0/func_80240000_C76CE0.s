.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_C76CE0
/* C76CE0 80240000 3C03800A */  lui       $v1, %hi(D_8009A650)
/* C76CE4 80240004 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* C76CE8 80240008 8C620000 */  lw        $v0, ($v1)
/* C76CEC 8024000C 34420040 */  ori       $v0, $v0, 0x40
/* C76CF0 80240010 AC620000 */  sw        $v0, ($v1)
/* C76CF4 80240014 03E00008 */  jr        $ra
/* C76CF8 80240018 24020002 */   addiu    $v0, $zero, 2
