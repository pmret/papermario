.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FD04
/* 2B104 8004FD04 90830235 */  lbu       $v1, 0x235($a0)
/* 2B108 8004FD08 8C820000 */  lw        $v0, ($a0)
/* 2B10C 8004FD0C 908500D4 */  lbu       $a1, 0xd4($a0)
/* 2B110 8004FD10 00031880 */  sll       $v1, $v1, 2
/* 2B114 8004FD14 00431021 */  addu      $v0, $v0, $v1
/* 2B118 8004FD18 A0450040 */  sb        $a1, 0x40($v0)
/* 2B11C 8004FD1C 90820235 */  lbu       $v0, 0x235($a0)
/* 2B120 8004FD20 8C830000 */  lw        $v1, ($a0)
/* 2B124 8004FD24 00021080 */  sll       $v0, $v0, 2
/* 2B128 8004FD28 00621821 */  addu      $v1, $v1, $v0
/* 2B12C 8004FD2C 24020001 */  addiu     $v0, $zero, 1
/* 2B130 8004FD30 03E00008 */  jr        $ra
/* 2B134 8004FD34 A0620041 */   sb       $v0, 0x41($v1)
