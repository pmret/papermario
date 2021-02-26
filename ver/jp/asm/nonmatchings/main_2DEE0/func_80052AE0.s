.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80052AE0
/* 2DEE0 80052AE0 308400FF */  andi      $a0, $a0, 0xff
/* 2DEE4 80052AE4 000410C0 */  sll       $v0, $a0, 3
/* 2DEE8 80052AE8 00441021 */  addu      $v0, $v0, $a0
/* 2DEEC 80052AEC 000210C0 */  sll       $v0, $v0, 3
/* 2DEF0 80052AF0 3C03800A */  lui       $v1, %hi(D_8009A5A0)
/* 2DEF4 80052AF4 8C63A5A0 */  lw        $v1, %lo(D_8009A5A0)($v1)
/* 2DEF8 80052AF8 24421320 */  addiu     $v0, $v0, 0x1320
/* 2DEFC 80052AFC 00621821 */  addu      $v1, $v1, $v0
/* 2DF00 80052B00 AC60001C */  sw        $zero, 0x1c($v1)
/* 2DF04 80052B04 03E00008 */  jr        $ra
/* 2DF08 80052B08 A0600045 */   sb       $zero, 0x45($v1)
