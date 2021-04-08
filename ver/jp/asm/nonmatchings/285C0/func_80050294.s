.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050294
/* 2B694 80050294 00041903 */  sra       $v1, $a0, 4
/* 2B698 80050298 00041043 */  sra       $v0, $a0, 1
/* 2B69C 8005029C 00621821 */  addu      $v1, $v1, $v0
/* 2B6A0 800502A0 30630001 */  andi      $v1, $v1, 1
/* 2B6A4 800502A4 00041183 */  sra       $v0, $a0, 6
/* 2B6A8 800502A8 3042000F */  andi      $v0, $v0, 0xf
/* 2B6AC 800502AC 00042080 */  sll       $a0, $a0, 2
/* 2B6B0 800502B0 308400F0 */  andi      $a0, $a0, 0xf0
/* 2B6B4 800502B4 10600009 */  beqz      $v1, .L800502DC
/* 2B6B8 800502B8 00442021 */   addu     $a0, $v0, $a0
/* 2B6BC 800502BC 30C300FF */  andi      $v1, $a2, 0xff
/* 2B6C0 800502C0 00041080 */  sll       $v0, $a0, 2
/* 2B6C4 800502C4 00441021 */  addu      $v0, $v0, $a0
/* 2B6C8 800502C8 00620018 */  mult      $v1, $v0
/* 2B6CC 800502CC 00003812 */  mflo      $a3
/* 2B6D0 800502D0 00071203 */  sra       $v0, $a3, 8
/* 2B6D4 800502D4 080140BE */  j         .L800502F8
/* 2B6D8 800502D8 00A21021 */   addu     $v0, $a1, $v0
.L800502DC:
/* 2B6DC 800502DC 30C300FF */  andi      $v1, $a2, 0xff
/* 2B6E0 800502E0 00041080 */  sll       $v0, $a0, 2
/* 2B6E4 800502E4 00441021 */  addu      $v0, $v0, $a0
/* 2B6E8 800502E8 00620018 */  mult      $v1, $v0
/* 2B6EC 800502EC 00003812 */  mflo      $a3
/* 2B6F0 800502F0 00071203 */  sra       $v0, $a3, 8
/* 2B6F4 800502F4 00A21023 */  subu      $v0, $a1, $v0
.L800502F8:
/* 2B6F8 800502F8 00021400 */  sll       $v0, $v0, 0x10
/* 2B6FC 800502FC 03E00008 */  jr        $ra
/* 2B700 80050300 00021403 */   sra      $v0, $v0, 0x10
