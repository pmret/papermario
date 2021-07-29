.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005FA94
/* 3AE94 8005FA94 8C82000C */  lw        $v0, 0xc($a0)
/* 3AE98 8005FA98 90430000 */  lbu       $v1, ($v0)
/* 3AE9C 8005FA9C 00031080 */  sll       $v0, $v1, 2
/* 3AEA0 8005FAA0 00431021 */  addu      $v0, $v0, $v1
/* 3AEA4 8005FAA4 00021040 */  sll       $v0, $v0, 1
/* 3AEA8 8005FAA8 3C01800B */  lui       $at, %hi(D_800B1D22)
/* 3AEAC 8005FAAC 00220821 */  addu      $at, $at, $v0
/* 3AEB0 8005FAB0 A4201D22 */  sh        $zero, %lo(D_800B1D22)($at)
/* 3AEB4 8005FAB4 03E00008 */  jr        $ra
/* 3AEB8 8005FAB8 0000102D */   daddu    $v0, $zero, $zero
