.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003C44C
/* 1784C 8003C44C 00052880 */  sll       $a1, $a1, 2
/* 17850 8003C450 00852021 */  addu      $a0, $a0, $a1
/* 17854 8003C454 8C820324 */  lw        $v0, 0x324($a0)
/* 17858 8003C458 8C43000C */  lw        $v1, 0xc($v0)
/* 1785C 8003C45C 24020005 */  addiu     $v0, $zero, 5
/* 17860 8003C460 03E00008 */  jr        $ra
/* 17864 8003C464 AC62002C */   sw       $v0, 0x2c($v1)
