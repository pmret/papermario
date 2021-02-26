.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CE30
/* 28230 8004CE30 8CA20000 */  lw        $v0, ($a1)
/* 28234 8004CE34 90440000 */  lbu       $a0, ($v0)
/* 28238 8004CE38 24420001 */  addiu     $v0, $v0, 1
/* 2823C 8004CE3C 10800005 */  beqz      $a0, .L8004CE54
/* 28240 8004CE40 ACA20000 */   sw       $v0, ($a1)
/* 28244 8004CE44 3C0300FF */  lui       $v1, 0xff
/* 28248 8004CE48 3463FFFF */  ori       $v1, $v1, 0xffff
/* 2824C 8004CE4C 00041600 */  sll       $v0, $a0, 0x18
/* 28250 8004CE50 00432025 */  or        $a0, $v0, $v1
.L8004CE54:
/* 28254 8004CE54 24020001 */  addiu     $v0, $zero, 1
/* 28258 8004CE58 ACA4006C */  sw        $a0, 0x6c($a1)
/* 2825C 8004CE5C 03E00008 */  jr        $ra
/* 28260 8004CE60 A0A20055 */   sb       $v0, 0x55($a1)
