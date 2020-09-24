.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802825FC
/* 7E347C 802825FC 24020001 */  addiu     $v0, $zero, 1
/* 7E3480 80282600 3C018015 */  lui       $at, 0x8015
/* 7E3484 80282604 AC221310 */  sw        $v0, 0x1310($at)
/* 7E3488 80282608 03E00008 */  jr        $ra
/* 7E348C 8028260C 24020002 */   addiu    $v0, $zero, 2
