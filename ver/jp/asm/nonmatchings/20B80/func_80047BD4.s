.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047BD4
/* 22FD4 80047BD4 00041040 */  sll       $v0, $a0, 1
/* 22FD8 80047BD8 00441021 */  addu      $v0, $v0, $a0
/* 22FDC 80047BDC 00021080 */  sll       $v0, $v0, 2
/* 22FE0 80047BE0 00441023 */  subu      $v0, $v0, $a0
/* 22FE4 80047BE4 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 22FE8 80047BE8 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 22FEC 80047BEC 00021100 */  sll       $v0, $v0, 4
/* 22FF0 80047BF0 00621821 */  addu      $v1, $v1, $v0
/* 22FF4 80047BF4 8C620000 */  lw        $v0, ($v1)
/* 22FF8 80047BF8 34420100 */  ori       $v0, $v0, 0x100
/* 22FFC 80047BFC 03E00008 */  jr        $ra
/* 23000 80047C00 AC620000 */   sw       $v0, ($v1)
