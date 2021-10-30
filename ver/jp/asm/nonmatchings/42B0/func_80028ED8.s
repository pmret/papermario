.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80028ED8
/* 42D8 80028ED8 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 42DC 80028EDC 8C42417C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 42E0 80028EE0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 42E4 80028EE4 AFB00010 */  sw        $s0, 0x10($sp)
/* 42E8 80028EE8 0080802D */  daddu     $s0, $a0, $zero
/* 42EC 80028EEC AFBF0018 */  sw        $ra, 0x18($sp)
/* 42F0 80028EF0 AFB10014 */  sw        $s1, 0x14($sp)
/* 42F4 80028EF4 80420071 */  lb        $v0, 0x71($v0)
/* 42F8 80028EF8 1440000F */  bnez      $v0, .L80028F38
/* 42FC 80028EFC 00A0882D */   daddu    $s1, $a1, $zero
/* 4300 80028F00 3C028007 */  lui       $v0, %hi(D_80074240)
/* 4304 80028F04 94424240 */  lhu       $v0, %lo(D_80074240)($v0)
/* 4308 80028F08 1040000B */  beqz      $v0, .L80028F38
/* 430C 80028F0C 00000000 */   nop
/* 4310 80028F10 0C017EE8 */  jal       func_8005FBA0
/* 4314 80028F14 0000202D */   daddu    $a0, $zero, $zero
/* 4318 80028F18 14400007 */  bnez      $v0, .L80028F38
/* 431C 80028F1C 0000202D */   daddu    $a0, $zero, $zero
/* 4320 80028F20 0C017F10 */  jal       func_8005FC40
/* 4324 80028F24 24050002 */   addiu    $a1, $zero, 2
/* 4328 80028F28 0000202D */  daddu     $a0, $zero, $zero
/* 432C 80028F2C 3205FFFF */  andi      $a1, $s0, 0xffff
/* 4330 80028F30 0C017ED0 */  jal       func_8005FB40
/* 4334 80028F34 3226FFFF */   andi     $a2, $s1, 0xffff
.L80028F38:
/* 4338 80028F38 8FBF0018 */  lw        $ra, 0x18($sp)
/* 433C 80028F3C 8FB10014 */  lw        $s1, 0x14($sp)
/* 4340 80028F40 8FB00010 */  lw        $s0, 0x10($sp)
/* 4344 80028F44 03E00008 */  jr        $ra
/* 4348 80028F48 27BD0020 */   addiu    $sp, $sp, 0x20
