.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050654
/* 2BA54 80050654 00041203 */  sra       $v0, $a0, 8
/* 2BA58 80050658 3042001F */  andi      $v0, $v0, 0x1f
/* 2BA5C 8005065C 308400E0 */  andi      $a0, $a0, 0xe0
/* 2BA60 80050660 00441021 */  addu      $v0, $v0, $a0
/* 2BA64 80050664 30C600FF */  andi      $a2, $a2, 0xff
/* 2BA68 80050668 00C20018 */  mult      $a2, $v0
/* 2BA6C 8005066C 30A500FF */  andi      $a1, $a1, 0xff
/* 2BA70 80050670 00001812 */  mflo      $v1
/* 2BA74 80050674 34028000 */  ori       $v0, $zero, 0x8000
/* 2BA78 80050678 00431023 */  subu      $v0, $v0, $v1
/* 2BA7C 8005067C 00A20018 */  mult      $a1, $v0
/* 2BA80 80050680 00001812 */  mflo      $v1
/* 2BA84 80050684 03E00008 */  jr        $ra
/* 2BA88 80050688 306200FF */   andi     $v0, $v1, 0xff
