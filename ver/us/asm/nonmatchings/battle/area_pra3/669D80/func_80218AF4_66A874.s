.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218AF4_66A874
/* 66A874 80218AF4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 66A878 80218AF8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 66A87C 80218AFC 8C82000C */  lw        $v0, 0xc($a0)
/* 66A880 80218B00 0C0B1EAF */  jal       evt_get_variable
/* 66A884 80218B04 8C450000 */   lw       $a1, ($v0)
/* 66A888 80218B08 8C43000C */  lw        $v1, 0xc($v0)
/* 66A88C 80218B0C 3C01C47A */  lui       $at, 0xc47a
/* 66A890 80218B10 44810000 */  mtc1      $at, $f0
/* 66A894 80218B14 00000000 */  nop
/* 66A898 80218B18 E4600008 */  swc1      $f0, 8($v1)
/* 66A89C 80218B1C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 66A8A0 80218B20 24020002 */  addiu     $v0, $zero, 2
/* 66A8A4 80218B24 03E00008 */  jr        $ra
/* 66A8A8 80218B28 27BD0018 */   addiu    $sp, $sp, 0x18
