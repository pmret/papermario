.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800477E4
/* 22BE4 800477E4 00041040 */  sll       $v0, $a0, 1
/* 22BE8 800477E8 00441021 */  addu      $v0, $v0, $a0
/* 22BEC 800477EC 00021080 */  sll       $v0, $v0, 2
/* 22BF0 800477F0 00441023 */  subu      $v0, $v0, $a0
/* 22BF4 800477F4 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 22BF8 800477F8 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 22BFC 800477FC 00021100 */  sll       $v0, $v0, 4
/* 22C00 80047800 00622821 */  addu      $a1, $v1, $v0
/* 22C04 80047804 2403FFDF */  addiu     $v1, $zero, -0x21
/* 22C08 80047808 8CA20000 */  lw        $v0, ($a1)
/* 22C0C 8004780C 80A40068 */  lb        $a0, 0x68($a1)
/* 22C10 80047810 00431024 */  and       $v0, $v0, $v1
/* 22C14 80047814 14800004 */  bnez      $a0, .L80047828
/* 22C18 80047818 ACA20000 */   sw       $v0, ($a1)
/* 22C1C 8004781C 24020001 */  addiu     $v0, $zero, 1
/* 22C20 80047820 A0A20068 */  sb        $v0, 0x68($a1)
/* 22C24 80047824 A0A2006A */  sb        $v0, 0x6a($a1)
.L80047828:
/* 22C28 80047828 03E00008 */  jr        $ra
/* 22C2C 8004782C 00000000 */   nop
