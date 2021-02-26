.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002B9DC
/* 6DDC 8002B9DC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6DE0 8002B9E0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6DE4 8002B9E4 0C01BD01 */  jal       func_8006F404
/* 6DE8 8002B9E8 000421C0 */   sll      $a0, $a0, 7
/* 6DEC 8002B9EC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6DF0 8002B9F0 03E00008 */  jr        $ra
/* 6DF4 8002B9F4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 6DF8 8002B9F8 00000000 */  nop
/* 6DFC 8002B9FC 00000000 */  nop
