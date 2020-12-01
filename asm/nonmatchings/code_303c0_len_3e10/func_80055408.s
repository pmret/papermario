.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055408
/* 30808 80055408 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3080C 8005540C 0080182D */  daddu     $v1, $a0, $zero
/* 30810 80055410 30E700FF */  andi      $a3, $a3, 0xff
/* 30814 80055414 00051400 */  sll       $v0, $a1, 0x10
/* 30818 80055418 AFA70010 */  sw        $a3, 0x10($sp)
/* 3081C 8005541C 00063C00 */  sll       $a3, $a2, 0x10
/* 30820 80055420 0060282D */  daddu     $a1, $v1, $zero
/* 30824 80055424 00023403 */  sra       $a2, $v0, 0x10
/* 30828 80055428 3C04800A */  lui       $a0, %hi(D_8009A640)
/* 3082C 8005542C 8C84A640 */  lw        $a0, %lo(D_8009A640)($a0)
/* 30830 80055430 AFBF0018 */  sw        $ra, 0x18($sp)
/* 30834 80055434 0C012DB6 */  jal       func_8004B6D8
/* 30838 80055438 00073C03 */   sra      $a3, $a3, 0x10
/* 3083C 8005543C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 30840 80055440 03E00008 */  jr        $ra
/* 30844 80055444 27BD0020 */   addiu    $sp, $sp, 0x20
