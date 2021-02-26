.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053EF8
/* 2F2F8 80053EF8 308400FF */  andi      $a0, $a0, 0xff
/* 2F2FC 80053EFC 24020002 */  addiu     $v0, $zero, 2
/* 2F300 80053F00 10820010 */  beq       $a0, $v0, .L80053F44
/* 2F304 80053F04 28820003 */   slti     $v0, $a0, 3
/* 2F308 80053F08 10400005 */  beqz      $v0, .L80053F20
/* 2F30C 80053F0C 24020001 */   addiu    $v0, $zero, 1
/* 2F310 80053F10 10820008 */  beq       $a0, $v0, .L80053F34
/* 2F314 80053F14 0000102D */   daddu    $v0, $zero, $zero
/* 2F318 80053F18 08014FD9 */  j         .L80053F64
/* 2F31C 80053F1C 00000000 */   nop
.L80053F20:
/* 2F320 80053F20 24020004 */  addiu     $v0, $zero, 4
/* 2F324 80053F24 1082000B */  beq       $a0, $v0, .L80053F54
/* 2F328 80053F28 0000102D */   daddu    $v0, $zero, $zero
/* 2F32C 80053F2C 08014FD9 */  j         .L80053F64
/* 2F330 80053F30 00000000 */   nop
.L80053F34:
/* 2F334 80053F34 3C02800A */  lui       $v0, %hi(D_8009A644)
/* 2F338 80053F38 8C42A644 */  lw        $v0, %lo(D_8009A644)($v0)
/* 2F33C 80053F3C 03E00008 */  jr        $ra
/* 2F340 80053F40 00000000 */   nop
.L80053F44:
/* 2F344 80053F44 3C02800A */  lui       $v0, %hi(D_8009A5DC)
/* 2F348 80053F48 8C42A5DC */  lw        $v0, %lo(D_8009A5DC)($v0)
/* 2F34C 80053F4C 03E00008 */  jr        $ra
/* 2F350 80053F50 00000000 */   nop
.L80053F54:
/* 2F354 80053F54 3C02800A */  lui       $v0, %hi(D_8009A620)
/* 2F358 80053F58 8C42A620 */  lw        $v0, %lo(D_8009A620)($v0)
/* 2F35C 80053F5C 03E00008 */  jr        $ra
/* 2F360 80053F60 00000000 */   nop
.L80053F64:
/* 2F364 80053F64 03E00008 */  jr        $ra
/* 2F368 80053F68 00000000 */   nop
