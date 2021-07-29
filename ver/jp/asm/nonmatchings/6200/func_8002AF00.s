.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002AF00
/* 6300 8002AF00 0000282D */  daddu     $a1, $zero, $zero
/* 6304 8002AF04 3C04800E */  lui       $a0, %hi(D_800D95C8)
/* 6308 8002AF08 248495C8 */  addiu     $a0, $a0, %lo(D_800D95C8)
/* 630C 8002AF0C 00A0182D */  daddu     $v1, $a1, $zero
.L8002AF10:
/* 6310 8002AF10 24630001 */  addiu     $v1, $v1, 1
/* 6314 8002AF14 8C820000 */  lw        $v0, ($a0)
/* 6318 8002AF18 00A22821 */  addu      $a1, $a1, $v0
/* 631C 8002AF1C 2C620020 */  sltiu     $v0, $v1, 0x20
/* 6320 8002AF20 1440FFFB */  bnez      $v0, .L8002AF10
/* 6324 8002AF24 24840004 */   addiu    $a0, $a0, 4
/* 6328 8002AF28 03E00008 */  jr        $ra
/* 632C 8002AF2C 00A0102D */   daddu    $v0, $a1, $zero
