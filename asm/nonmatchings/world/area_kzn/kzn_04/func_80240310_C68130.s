.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_C68440
/* C68440 80240310 3C03800A */  lui       $v1, %hi(D_8009A650)
/* C68444 80240314 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* C68448 80240318 8C620000 */  lw        $v0, ($v1)
/* C6844C 8024031C 34420040 */  ori       $v0, $v0, 0x40
/* C68450 80240320 AC620000 */  sw        $v0, ($v1)
/* C68454 80240324 03E00008 */  jr        $ra
/* C68458 80240328 24020002 */   addiu    $v0, $zero, 2
