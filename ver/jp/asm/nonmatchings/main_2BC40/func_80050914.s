.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050914
/* 2BD14 80050914 3C03800A */  lui       $v1, %hi(D_8009A608)
/* 2BD18 80050918 8C63A608 */  lw        $v1, %lo(D_8009A608)($v1)
/* 2BD1C 8005091C 00041100 */  sll       $v0, $a0, 4
/* 2BD20 80050920 00441023 */  subu      $v0, $v0, $a0
/* 2BD24 80050924 000210C0 */  sll       $v0, $v0, 3
/* 2BD28 80050928 00441021 */  addu      $v0, $v0, $a0
/* 2BD2C 8005092C 00021080 */  sll       $v0, $v0, 2
/* 2BD30 80050930 24420024 */  addiu     $v0, $v0, 0x24
/* 2BD34 80050934 14A00003 */  bnez      $a1, .L80050944
/* 2BD38 80050938 00621821 */   addu     $v1, $v1, $v0
/* 2BD3C 8005093C 03E00008 */  jr        $ra
/* 2BD40 80050940 A0600025 */   sb       $zero, 0x25($v1)
.L80050944:
/* 2BD44 80050944 24020002 */  addiu     $v0, $zero, 2
/* 2BD48 80050948 03E00008 */  jr        $ra
/* 2BD4C 8005094C A0620025 */   sb       $v0, 0x25($v1)
