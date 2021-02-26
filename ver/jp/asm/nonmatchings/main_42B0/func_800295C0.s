.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800295C0
/* 49C0 800295C0 18A00005 */  blez      $a1, .L800295D8
/* 49C4 800295C4 00000000 */   nop
.L800295C8:
/* 49C8 800295C8 A0800000 */  sb        $zero, ($a0)
/* 49CC 800295CC 24A5FFFF */  addiu     $a1, $a1, -1
/* 49D0 800295D0 1CA0FFFD */  bgtz      $a1, .L800295C8
/* 49D4 800295D4 24840001 */   addiu    $a0, $a0, 1
.L800295D8:
/* 49D8 800295D8 03E00008 */  jr        $ra
/* 49DC 800295DC 00000000 */   nop
