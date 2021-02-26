.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053C14
/* 2F014 80053C14 14800004 */  bnez      $a0, .L80053C28
/* 2F018 80053C18 0000102D */   daddu    $v0, $zero, $zero
/* 2F01C 80053C1C 3C02800A */  lui       $v0, %hi(D_8009A5A0)
/* 2F020 80053C20 8C42A5A0 */  lw        $v0, %lo(D_8009A5A0)($v0)
/* 2F024 80053C24 8C42006C */  lw        $v0, 0x6c($v0)
.L80053C28:
/* 2F028 80053C28 03E00008 */  jr        $ra
/* 2F02C 80053C2C 00000000 */   nop
