.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel snd_SEFCmd_16
/* 2876C 8004D36C 8CA60000 */  lw        $a2, ($a1)
/* 28770 8004D370 90C20000 */  lbu       $v0, ($a2)
/* 28774 8004D374 90C30001 */  lbu       $v1, 1($a2)
/* 28778 8004D378 00021200 */  sll       $v0, $v0, 8
/* 2877C 8004D37C 00431821 */  addu      $v1, $v0, $v1
/* 28780 8004D380 50600004 */  beql      $v1, $zero, .L8004D394
/* 28784 8004D384 ACA00018 */   sw       $zero, 0x18($a1)
/* 28788 8004D388 8C820008 */  lw        $v0, 8($a0)
/* 2878C 8004D38C 00621021 */  addu      $v0, $v1, $v0
/* 28790 8004D390 ACA20018 */  sw        $v0, 0x18($a1)
.L8004D394:
/* 28794 8004D394 24C20002 */  addiu     $v0, $a2, 2
/* 28798 8004D398 03E00008 */  jr        $ra
/* 2879C 8004D39C ACA20000 */   sw       $v0, ($a1)
