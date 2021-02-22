.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005BA88
/* 36E88 8005BA88 000410C0 */  sll       $v0, $a0, 3
/* 36E8C 8005BA8C 00441023 */  subu      $v0, $v0, $a0
/* 36E90 8005BA90 3C03800B */  lui       $v1, %hi(D_800B42C4)
/* 36E94 8005BA94 8C6342C4 */  lw        $v1, %lo(D_800B42C4)($v1)
/* 36E98 8005BA98 00021080 */  sll       $v0, $v0, 2
/* 36E9C 8005BA9C 00431021 */  addu      $v0, $v0, $v1
/* 36EA0 8005BAA0 8C42000C */  lw        $v0, 0xc($v0)
/* 36EA4 8005BAA4 C4400030 */  lwc1      $f0, 0x30($v0)
/* 36EA8 8005BAA8 E4A00000 */  swc1      $f0, ($a1)
/* 36EAC 8005BAAC C4400034 */  lwc1      $f0, 0x34($v0)
/* 36EB0 8005BAB0 E4C00000 */  swc1      $f0, ($a2)
/* 36EB4 8005BAB4 C4400038 */  lwc1      $f0, 0x38($v0)
/* 36EB8 8005BAB8 03E00008 */  jr        $ra
/* 36EBC 8005BABC E4E00000 */   swc1     $f0, ($a3)
