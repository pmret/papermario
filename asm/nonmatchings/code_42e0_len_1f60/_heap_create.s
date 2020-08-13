.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel _heap_create
/* 004430 80029030 2CA20020 */  sltiu $v0, $a1, 0x20
/* 004434 80029034 1440000B */  bnez  $v0, .L80029064
/* 004438 80029038 2482000F */   addiu $v0, $a0, 0xf
/* 00443C 8002903C 2403FFF0 */  addiu $v1, $zero, -0x10
/* 004440 80029040 00431024 */  and   $v0, $v0, $v1
/* 004444 80029044 00441823 */  subu  $v1, $v0, $a0
/* 004448 80029048 00A32823 */  subu  $a1, $a1, $v1
/* 00444C 8002904C 24A3FFF0 */  addiu $v1, $a1, -0x10
/* 004450 80029050 AC400000 */  sw    $zero, ($v0)
/* 004454 80029054 AC430004 */  sw    $v1, 4($v0)
/* 004458 80029058 A4400008 */  sh    $zero, 8($v0)
/* 00445C 8002905C 03E00008 */  jr    $ra
/* 004460 80029060 AC45000C */   sw    $a1, 0xc($v0)

.L80029064:
/* 004464 80029064 03E00008 */  jr    $ra
/* 004468 80029068 2402FFFF */   addiu $v0, $zero, -1

