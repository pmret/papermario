.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003EB00
/* 19F00 8003EB00 0080182D */  daddu     $v1, $a0, $zero
/* 19F04 8003EB04 00A0102D */  daddu     $v0, $a1, $zero
/* 19F08 8003EB08 04410002 */  bgez      $v0, .L8003EB14
/* 19F0C 8003EB0C 0040202D */   daddu    $a0, $v0, $zero
/* 19F10 8003EB10 2444001F */  addiu     $a0, $v0, 0x1f
.L8003EB14:
/* 19F14 8003EB14 00042143 */  sra       $a0, $a0, 5
/* 19F18 8003EB18 00042940 */  sll       $a1, $a0, 5
/* 19F1C 8003EB1C 00452823 */  subu      $a1, $v0, $a1
/* 19F20 8003EB20 00042080 */  sll       $a0, $a0, 2
/* 19F24 8003EB24 00031040 */  sll       $v0, $v1, 1
/* 19F28 8003EB28 00431021 */  addu      $v0, $v0, $v1
/* 19F2C 8003EB2C 00021100 */  sll       $v0, $v0, 4
/* 19F30 8003EB30 00822021 */  addu      $a0, $a0, $v0
/* 19F34 8003EB34 3C02800B */  lui       $v0, %hi(D_800B0EF0)
/* 19F38 8003EB38 24420EF0 */  addiu     $v0, $v0, %lo(D_800B0EF0)
/* 19F3C 8003EB3C 00822021 */  addu      $a0, $a0, $v0
/* 19F40 8003EB40 24030001 */  addiu     $v1, $zero, 1
/* 19F44 8003EB44 8C8200B0 */  lw        $v0, 0xb0($a0)
/* 19F48 8003EB48 00A31804 */  sllv      $v1, $v1, $a1
/* 19F4C 8003EB4C 00431025 */  or        $v0, $v0, $v1
/* 19F50 8003EB50 03E00008 */  jr        $ra
/* 19F54 8003EB54 AC8200B0 */   sw       $v0, 0xb0($a0)
