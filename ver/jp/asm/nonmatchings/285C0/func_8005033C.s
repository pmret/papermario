.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005033C
/* 2B73C 8005033C 000411C3 */  sra       $v0, $a0, 7
/* 2B740 80050340 30420007 */  andi      $v0, $v0, 7
/* 2B744 80050344 000420C0 */  sll       $a0, $a0, 3
/* 2B748 80050348 308400F8 */  andi      $a0, $a0, 0xf8
/* 2B74C 8005034C 00441021 */  addu      $v0, $v0, $a0
/* 2B750 80050350 30C600FF */  andi      $a2, $a2, 0xff
/* 2B754 80050354 00C20018 */  mult      $a2, $v0
/* 2B758 80050358 30A500FF */  andi      $a1, $a1, 0xff
/* 2B75C 8005035C 00001812 */  mflo      $v1
/* 2B760 80050360 34028000 */  ori       $v0, $zero, 0x8000
/* 2B764 80050364 00431023 */  subu      $v0, $v0, $v1
/* 2B768 80050368 00A20018 */  mult      $a1, $v0
/* 2B76C 8005036C 00001812 */  mflo      $v1
/* 2B770 80050370 03E00008 */  jr        $ra
/* 2B774 80050374 306200FF */   andi     $v0, $v1, 0xff
