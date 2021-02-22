.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800476AC
/* 22AAC 800476AC 00041040 */  sll       $v0, $a0, 1
/* 22AB0 800476B0 00441021 */  addu      $v0, $v0, $a0
/* 22AB4 800476B4 00021080 */  sll       $v0, $v0, 2
/* 22AB8 800476B8 00441023 */  subu      $v0, $v0, $a0
/* 22ABC 800476BC 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 22AC0 800476C0 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 22AC4 800476C4 00021100 */  sll       $v0, $v0, 4
/* 22AC8 800476C8 00621821 */  addu      $v1, $v1, $v0
/* 22ACC 800476CC 8C620000 */  lw        $v0, ($v1)
/* 22AD0 800476D0 34420008 */  ori       $v0, $v0, 8
/* 22AD4 800476D4 03E00008 */  jr        $ra
/* 22AD8 800476D8 AC620000 */   sw       $v0, ($v1)
