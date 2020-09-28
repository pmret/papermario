.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_defeated
/* 1A1F0 8003EDF0 0080302D */  daddu     $a2, $a0, $zero
/* 1A1F4 8003EDF4 04A10002 */  bgez      $a1, .L8003EE00
/* 1A1F8 8003EDF8 00A0182D */   daddu    $v1, $a1, $zero
/* 1A1FC 8003EDFC 24A3001F */  addiu     $v1, $a1, 0x1f
.L8003EE00:
/* 1A200 8003EE00 00031943 */  sra       $v1, $v1, 5
/* 1A204 8003EE04 00032140 */  sll       $a0, $v1, 5
/* 1A208 8003EE08 00A42023 */  subu      $a0, $a1, $a0
/* 1A20C 8003EE0C 00031880 */  sll       $v1, $v1, 2
/* 1A210 8003EE10 00061040 */  sll       $v0, $a2, 1
/* 1A214 8003EE14 00461021 */  addu      $v0, $v0, $a2
/* 1A218 8003EE18 00021100 */  sll       $v0, $v0, 4
/* 1A21C 8003EE1C 00621821 */  addu      $v1, $v1, $v0
/* 1A220 8003EE20 3C02800B */  lui       $v0, %hi(gCurrentEncounter)
/* 1A224 8003EE24 24420F10 */  addiu     $v0, $v0, %lo(gCurrentEncounter)
/* 1A228 8003EE28 00621821 */  addu      $v1, $v1, $v0
/* 1A22C 8003EE2C 24020001 */  addiu     $v0, $zero, 1
/* 1A230 8003EE30 8C6300B0 */  lw        $v1, 0xb0($v1)
/* 1A234 8003EE34 00821004 */  sllv      $v0, $v0, $a0
/* 1A238 8003EE38 03E00008 */  jr        $ra
/* 1A23C 8003EE3C 00621024 */   and      $v0, $v1, $v0
