.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_items_get_row
/* 13CC20 802498E0 3C038027 */  lui       $v1, 0x8027
/* 13CC24 802498E4 246304D0 */  addiu     $v1, $v1, 0x4d0
/* 13CC28 802498E8 00041040 */  sll       $v0, $a0, 1
/* 13CC2C 802498EC 00441021 */  addu      $v0, $v0, $a0
/* 13CC30 802498F0 00021080 */  sll       $v0, $v0, 2
/* 13CC34 802498F4 00431021 */  addu      $v0, $v0, $v1
/* 13CC38 802498F8 90430002 */  lbu       $v1, 2($v0)
/* 13CC3C 802498FC 14600002 */  bnez      $v1, .L80249908
/* 13CC40 80249900 00A3001A */   div      $zero, $a1, $v1
/* 13CC44 80249904 0007000D */  break     7
.L80249908:
/* 13CC48 80249908 2401FFFF */   addiu    $at, $zero, -1
/* 13CC4C 8024990C 14610004 */  bne       $v1, $at, .L80249920
/* 13CC50 80249910 3C018000 */   lui      $at, 0x8000
/* 13CC54 80249914 14A10002 */  bne       $a1, $at, .L80249920
/* 13CC58 80249918 00000000 */   nop      
/* 13CC5C 8024991C 0006000D */  break     6
.L80249920:
/* 13CC60 80249920 00002812 */   mflo     $a1
/* 13CC64 80249924 90420001 */  lbu       $v0, 1($v0)
/* 13CC68 80249928 03E00008 */  jr        $ra
/* 13CC6C 8024992C 00451021 */   addu     $v0, $v0, $a1
