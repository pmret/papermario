.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003EAB0
/* 19EB0 8003EAB0 0080302D */  daddu     $a2, $a0, $zero
/* 19EB4 8003EAB4 04A10002 */  bgez      $a1, .L8003EAC0
/* 19EB8 8003EAB8 00A0182D */   daddu    $v1, $a1, $zero
/* 19EBC 8003EABC 24A3001F */  addiu     $v1, $a1, 0x1f
.L8003EAC0:
/* 19EC0 8003EAC0 00031943 */  sra       $v1, $v1, 5
/* 19EC4 8003EAC4 00032140 */  sll       $a0, $v1, 5
/* 19EC8 8003EAC8 00A42023 */  subu      $a0, $a1, $a0
/* 19ECC 8003EACC 00031880 */  sll       $v1, $v1, 2
/* 19ED0 8003EAD0 00061040 */  sll       $v0, $a2, 1
/* 19ED4 8003EAD4 00461021 */  addu      $v0, $v0, $a2
/* 19ED8 8003EAD8 00021100 */  sll       $v0, $v0, 4
/* 19EDC 8003EADC 00621821 */  addu      $v1, $v1, $v0
/* 19EE0 8003EAE0 3C02800B */  lui       $v0, %hi(D_800B0EF0)
/* 19EE4 8003EAE4 24420EF0 */  addiu     $v0, $v0, %lo(D_800B0EF0)
/* 19EE8 8003EAE8 00621821 */  addu      $v1, $v1, $v0
/* 19EEC 8003EAEC 24020001 */  addiu     $v0, $zero, 1
/* 19EF0 8003EAF0 8C6300B0 */  lw        $v1, 0xb0($v1)
/* 19EF4 8003EAF4 00821004 */  sllv      $v0, $v0, $a0
/* 19EF8 8003EAF8 03E00008 */  jr        $ra
/* 19EFC 8003EAFC 00621024 */   and      $v0, $v1, $v0
