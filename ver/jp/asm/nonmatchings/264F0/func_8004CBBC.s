.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CBBC
/* 27FBC 8004CBBC 8CA20000 */  lw        $v0, ($a1)
/* 27FC0 8004CBC0 90A3009A */  lbu       $v1, 0x9a($a1)
/* 27FC4 8004CBC4 90460000 */  lbu       $a2, ($v0)
/* 27FC8 8004CBC8 24420001 */  addiu     $v0, $v0, 1
/* 27FCC 8004CBCC 30630020 */  andi      $v1, $v1, 0x20
/* 27FD0 8004CBD0 10600002 */  beqz      $v1, .L8004CBDC
/* 27FD4 8004CBD4 ACA20000 */   sw       $v0, ($a1)
/* 27FD8 8004CBD8 9086008D */  lbu       $a2, 0x8d($a0)
.L8004CBDC:
/* 27FDC 8004CBDC 24020001 */  addiu     $v0, $zero, 1
/* 27FE0 8004CBE0 A0A6009C */  sb        $a2, 0x9c($a1)
/* 27FE4 8004CBE4 03E00008 */  jr        $ra
/* 27FE8 8004CBE8 A0A20057 */   sb       $v0, 0x57($a1)
