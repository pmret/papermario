.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005BAC0
/* 36EC0 8005BAC0 000410C0 */  sll       $v0, $a0, 3
/* 36EC4 8005BAC4 00441023 */  subu      $v0, $v0, $a0
/* 36EC8 8005BAC8 3C03800B */  lui       $v1, %hi(D_800B42C4)
/* 36ECC 8005BACC 8C6342C4 */  lw        $v1, %lo(D_800B42C4)($v1)
/* 36ED0 8005BAD0 00021080 */  sll       $v0, $v0, 2
/* 36ED4 8005BAD4 00431021 */  addu      $v0, $v0, $v1
/* 36ED8 8005BAD8 8C420010 */  lw        $v0, 0x10($v0)
/* 36EDC 8005BADC C4400000 */  lwc1      $f0, ($v0)
/* 36EE0 8005BAE0 C442000C */  lwc1      $f2, 0xc($v0)
/* 36EE4 8005BAE4 46020000 */  add.s     $f0, $f0, $f2
/* 36EE8 8005BAE8 3C013F00 */  lui       $at, 0x3f00
/* 36EEC 8005BAEC 44812000 */  mtc1      $at, $f4
/* 36EF0 8005BAF0 00000000 */  nop
/* 36EF4 8005BAF4 46040002 */  mul.s     $f0, $f0, $f4
/* 36EF8 8005BAF8 00000000 */  nop
/* 36EFC 8005BAFC E4A00000 */  swc1      $f0, ($a1)
/* 36F00 8005BB00 C4400004 */  lwc1      $f0, 4($v0)
/* 36F04 8005BB04 C4420010 */  lwc1      $f2, 0x10($v0)
/* 36F08 8005BB08 46020000 */  add.s     $f0, $f0, $f2
/* 36F0C 8005BB0C 46040002 */  mul.s     $f0, $f0, $f4
/* 36F10 8005BB10 00000000 */  nop
/* 36F14 8005BB14 E4C00000 */  swc1      $f0, ($a2)
/* 36F18 8005BB18 C4400008 */  lwc1      $f0, 8($v0)
/* 36F1C 8005BB1C C4420014 */  lwc1      $f2, 0x14($v0)
/* 36F20 8005BB20 46020000 */  add.s     $f0, $f0, $f2
/* 36F24 8005BB24 46040002 */  mul.s     $f0, $f0, $f4
/* 36F28 8005BB28 00000000 */  nop
/* 36F2C 8005BB2C 03E00008 */  jr        $ra
/* 36F30 8005BB30 E4E00000 */   swc1     $f0, ($a3)
