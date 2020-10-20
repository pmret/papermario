.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240580_E16300
/* E16300 80240580 3C04FFFB */  lui       $a0, 0xfffb
/* E16304 80240584 3C03800A */  lui       $v1, %hi(D_8009A650)
/* E16308 80240588 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* E1630C 8024058C 8C620000 */  lw        $v0, ($v1)
/* E16310 80240590 3484FFFF */  ori       $a0, $a0, 0xffff
/* E16314 80240594 00441024 */  and       $v0, $v0, $a0
/* E16318 80240598 AC620000 */  sw        $v0, ($v1)
/* E1631C 8024059C 03E00008 */  jr        $ra
/* E16320 802405A0 24020002 */   addiu    $v0, $zero, 2
