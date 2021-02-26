.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005F554
/* 3A954 8005F554 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3A958 8005F558 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3A95C 8005F55C 8C83000C */  lw        $v1, 0xc($a0)
/* 3A960 8005F560 8C620000 */  lw        $v0, ($v1)
/* 3A964 8005F564 8C660004 */  lw        $a2, 4($v1)
/* 3A968 8005F568 8C440000 */  lw        $a0, ($v0)
/* 3A96C 8005F56C 0C01A300 */  jal       func_80068C00
/* 3A970 8005F570 8C450004 */   lw       $a1, 4($v0)
/* 3A974 8005F574 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3A978 8005F578 03E00008 */  jr        $ra
/* 3A97C 8005F57C 27BD0018 */   addiu    $sp, $sp, 0x18
