.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005BA58
/* 36E58 8005BA58 30824000 */  andi      $v0, $a0, 0x4000
/* 36E5C 8005BA5C 14400008 */  bnez      $v0, .L8005BA80
/* 36E60 8005BA60 000410C0 */   sll      $v0, $a0, 3
/* 36E64 8005BA64 00441023 */  subu      $v0, $v0, $a0
/* 36E68 8005BA68 3C03800B */  lui       $v1, %hi(D_800B42C4)
/* 36E6C 8005BA6C 8C6342C4 */  lw        $v1, %lo(D_800B42C4)($v1)
/* 36E70 8005BA70 00021080 */  sll       $v0, $v0, 2
/* 36E74 8005BA74 00431021 */  addu      $v0, $v0, $v1
/* 36E78 8005BA78 03E00008 */  jr        $ra
/* 36E7C 8005BA7C 8C420000 */   lw       $v0, ($v0)
.L8005BA80:
/* 36E80 8005BA80 03E00008 */  jr        $ra
/* 36E84 8005BA84 0000102D */   daddu    $v0, $zero, $zero
