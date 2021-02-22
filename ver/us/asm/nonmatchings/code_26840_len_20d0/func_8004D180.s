.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D180
/* 28580 8004D180 8CA20000 */  lw        $v0, ($a1)
/* 28584 8004D184 90440000 */  lbu       $a0, ($v0)
/* 28588 8004D188 24420001 */  addiu     $v0, $v0, 1
/* 2858C 8004D18C 10800005 */  beqz      $a0, .L8004D1A4
/* 28590 8004D190 ACA20000 */   sw       $v0, ($a1)
/* 28594 8004D194 3C0300FF */  lui       $v1, 0xff
/* 28598 8004D198 3463FFFF */  ori       $v1, $v1, 0xffff
/* 2859C 8004D19C 00041600 */  sll       $v0, $a0, 0x18
/* 285A0 8004D1A0 00432025 */  or        $a0, $v0, $v1
.L8004D1A4:
/* 285A4 8004D1A4 24020001 */  addiu     $v0, $zero, 1
/* 285A8 8004D1A8 ACA4006C */  sw        $a0, 0x6c($a1)
/* 285AC 8004D1AC 03E00008 */  jr        $ra
/* 285B0 8004D1B0 A0A20055 */   sb       $v0, 0x55($a1)
