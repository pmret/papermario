.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055EB4
/* 312B4 80055EB4 2C820008 */  sltiu     $v0, $a0, 8
/* 312B8 80055EB8 10400025 */  beqz      $v0, .L80055F50
/* 312BC 80055EBC 0000182D */   daddu    $v1, $zero, $zero
/* 312C0 80055EC0 00041080 */  sll       $v0, $a0, 2
/* 312C4 80055EC4 3C01800A */  lui       $at, %hi(jtbl_80098908_73D08)
/* 312C8 80055EC8 00220821 */  addu      $at, $at, $v0
/* 312CC 80055ECC 8C228908 */  lw        $v0, %lo(jtbl_80098908_73D08)($at)
/* 312D0 80055ED0 00400008 */  jr        $v0
/* 312D4 80055ED4 00000000 */   nop
/* 312D8 80055ED8 3C038008 */  lui       $v1, %hi(D_80078DB8)
/* 312DC 80055EDC 24638DB8 */  addiu     $v1, $v1, %lo(D_80078DB8)
/* 312E0 80055EE0 03E00008 */  jr        $ra
/* 312E4 80055EE4 0060102D */   daddu    $v0, $v1, $zero
/* 312E8 80055EE8 3C038008 */  lui       $v1, %hi(D_80078DC4)
/* 312EC 80055EEC 24638DC4 */  addiu     $v1, $v1, %lo(D_80078DC4)
/* 312F0 80055EF0 03E00008 */  jr        $ra
/* 312F4 80055EF4 0060102D */   daddu    $v0, $v1, $zero
/* 312F8 80055EF8 3C038008 */  lui       $v1, %hi(D_80078DCC)
/* 312FC 80055EFC 24638DCC */  addiu     $v1, $v1, %lo(D_80078DCC)
/* 31300 80055F00 03E00008 */  jr        $ra
/* 31304 80055F04 0060102D */   daddu    $v0, $v1, $zero
/* 31308 80055F08 3C038008 */  lui       $v1, %hi(D_80078DD0)
/* 3130C 80055F0C 24638DD0 */  addiu     $v1, $v1, %lo(D_80078DD0)
/* 31310 80055F10 03E00008 */  jr        $ra
/* 31314 80055F14 0060102D */   daddu    $v0, $v1, $zero
/* 31318 80055F18 3C038008 */  lui       $v1, %hi(D_80078DDC)
/* 3131C 80055F1C 24638DDC */  addiu     $v1, $v1, %lo(D_80078DDC)
/* 31320 80055F20 03E00008 */  jr        $ra
/* 31324 80055F24 0060102D */   daddu    $v0, $v1, $zero
/* 31328 80055F28 3C038008 */  lui       $v1, %hi(D_80078DF8)
/* 3132C 80055F2C 24638DF8 */  addiu     $v1, $v1, %lo(D_80078DF8)
/* 31330 80055F30 03E00008 */  jr        $ra
/* 31334 80055F34 0060102D */   daddu    $v0, $v1, $zero
/* 31338 80055F38 3C038008 */  lui       $v1, %hi(D_80078E14)
/* 3133C 80055F3C 24638E14 */  addiu     $v1, $v1, %lo(D_80078E14)
/* 31340 80055F40 03E00008 */  jr        $ra
/* 31344 80055F44 0060102D */   daddu    $v0, $v1, $zero
/* 31348 80055F48 3C038008 */  lui       $v1, %hi(D_80078E30)
/* 3134C 80055F4C 24638E30 */  addiu     $v1, $v1, %lo(D_80078E30)
.L80055F50:
/* 31350 80055F50 03E00008 */  jr        $ra
/* 31354 80055F54 0060102D */   daddu    $v0, $v1, $zero
