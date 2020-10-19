.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240438_E12B98
/* E12B98 80240438 3C04FFFB */  lui       $a0, 0xfffb
/* E12B9C 8024043C 3C03800A */  lui       $v1, %hi(D_8009A650)
/* E12BA0 80240440 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* E12BA4 80240444 8C620000 */  lw        $v0, ($v1)
/* E12BA8 80240448 3484FFFF */  ori       $a0, $a0, 0xffff
/* E12BAC 8024044C 00441024 */  and       $v0, $v0, $a0
/* E12BB0 80240450 AC620000 */  sw        $v0, ($v1)
/* E12BB4 80240454 03E00008 */  jr        $ra
/* E12BB8 80240458 24020002 */   addiu    $v0, $zero, 2
