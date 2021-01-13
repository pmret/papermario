.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026220C
/* 190AEC 8026220C 3C0142C8 */  lui       $at, 0x42c8
/* 190AF0 80262210 44810000 */  mtc1      $at, $f0
/* 190AF4 80262214 00000000 */  nop
/* 190AF8 80262218 460E003C */  c.lt.s    $f0, $f14
/* 190AFC 8026221C 00000000 */  nop
/* 190B00 80262220 45000002 */  bc1f      .L8026222C
/* 190B04 80262224 0000102D */   daddu    $v0, $zero, $zero
/* 190B08 80262228 2402001C */  addiu     $v0, $zero, 0x1c
.L8026222C:
/* 190B0C 8026222C 03E00008 */  jr        $ra
/* 190B10 80262230 00000000 */   nop
/* 190B14 80262234 00000000 */  nop
/* 190B18 80262238 00000000 */  nop
/* 190B1C 8026223C 00000000 */  nop
