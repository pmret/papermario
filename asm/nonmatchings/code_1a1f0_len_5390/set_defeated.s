.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_defeated
/* 1A240 8003EE40 0080182D */  daddu     $v1, $a0, $zero
/* 1A244 8003EE44 00A0102D */  daddu     $v0, $a1, $zero
/* 1A248 8003EE48 04410002 */  bgez      $v0, .L8003EE54
/* 1A24C 8003EE4C 0040202D */   daddu    $a0, $v0, $zero
/* 1A250 8003EE50 2444001F */  addiu     $a0, $v0, 0x1f
.L8003EE54:
/* 1A254 8003EE54 00042143 */  sra       $a0, $a0, 5
/* 1A258 8003EE58 00042940 */  sll       $a1, $a0, 5
/* 1A25C 8003EE5C 00452823 */  subu      $a1, $v0, $a1
/* 1A260 8003EE60 00042080 */  sll       $a0, $a0, 2
/* 1A264 8003EE64 00031040 */  sll       $v0, $v1, 1
/* 1A268 8003EE68 00431021 */  addu      $v0, $v0, $v1
/* 1A26C 8003EE6C 00021100 */  sll       $v0, $v0, 4
/* 1A270 8003EE70 00822021 */  addu      $a0, $a0, $v0
/* 1A274 8003EE74 3C02800B */  lui       $v0, 0x800b
/* 1A278 8003EE78 24420F10 */  addiu     $v0, $v0, 0xf10
/* 1A27C 8003EE7C 00822021 */  addu      $a0, $a0, $v0
/* 1A280 8003EE80 24030001 */  addiu     $v1, $zero, 1
/* 1A284 8003EE84 8C8200B0 */  lw        $v0, 0xb0($a0)
/* 1A288 8003EE88 00A31804 */  sllv      $v1, $v1, $a1
/* 1A28C 8003EE8C 00431025 */  or        $v0, $v0, $v1
/* 1A290 8003EE90 03E00008 */  jr        $ra
/* 1A294 8003EE94 AC8200B0 */   sw       $v0, 0xb0($a0)
