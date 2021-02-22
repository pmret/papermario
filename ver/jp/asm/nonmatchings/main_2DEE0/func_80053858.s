.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053858
/* 2EC58 80053858 9482001A */  lhu       $v0, 0x1a($a0)
/* 2EC5C 8005385C 2442FFFF */  addiu     $v0, $v0, -1
/* 2EC60 80053860 A482001A */  sh        $v0, 0x1a($a0)
/* 2EC64 80053864 00021400 */  sll       $v0, $v0, 0x10
/* 2EC68 80053868 10400006 */  beqz      $v0, .L80053884
/* 2EC6C 8005386C 00000000 */   nop
/* 2EC70 80053870 8C820010 */  lw        $v0, 0x10($a0)
/* 2EC74 80053874 8C830014 */  lw        $v1, 0x14($a0)
/* 2EC78 80053878 00431021 */  addu      $v0, $v0, $v1
/* 2EC7C 8005387C 03E00008 */  jr        $ra
/* 2EC80 80053880 AC820010 */   sw       $v0, 0x10($a0)
.L80053884:
/* 2EC84 80053884 84820018 */  lh        $v0, 0x18($a0)
/* 2EC88 80053888 AC800014 */  sw        $zero, 0x14($a0)
/* 2EC8C 8005388C 00021400 */  sll       $v0, $v0, 0x10
/* 2EC90 80053890 03E00008 */  jr        $ra
/* 2EC94 80053894 AC820010 */   sw       $v0, 0x10($a0)
