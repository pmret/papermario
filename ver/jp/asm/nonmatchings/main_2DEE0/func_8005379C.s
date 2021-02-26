.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005379C
/* 2EB9C 8005379C 00051400 */  sll       $v0, $a1, 0x10
/* 2EBA0 800537A0 AC820010 */  sw        $v0, 0x10($a0)
/* 2EBA4 800537A4 A4850018 */  sh        $a1, 0x18($a0)
/* 2EBA8 800537A8 A480001A */  sh        $zero, 0x1a($a0)
/* 2EBAC 800537AC 03E00008 */  jr        $ra
/* 2EBB0 800537B0 AC800014 */   sw       $zero, 0x14($a0)
