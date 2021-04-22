.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80028FF0
/* 43F0 80028FF0 2CA20020 */  sltiu     $v0, $a1, 0x20
/* 43F4 80028FF4 1440000B */  bnez      $v0, .L80029024
/* 43F8 80028FF8 2482000F */   addiu    $v0, $a0, 0xf
/* 43FC 80028FFC 2403FFF0 */  addiu     $v1, $zero, -0x10
/* 4400 80029000 00431024 */  and       $v0, $v0, $v1
/* 4404 80029004 00441823 */  subu      $v1, $v0, $a0
/* 4408 80029008 00A32823 */  subu      $a1, $a1, $v1
/* 440C 8002900C 24A3FFF0 */  addiu     $v1, $a1, -0x10
/* 4410 80029010 AC400000 */  sw        $zero, ($v0)
/* 4414 80029014 AC430004 */  sw        $v1, 4($v0)
/* 4418 80029018 A4400008 */  sh        $zero, 8($v0)
/* 441C 8002901C 03E00008 */  jr        $ra
/* 4420 80029020 AC45000C */   sw       $a1, 0xc($v0)
.L80029024:
/* 4424 80029024 03E00008 */  jr        $ra
/* 4428 80029028 2402FFFF */   addiu    $v0, $zero, -1
