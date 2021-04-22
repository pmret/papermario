.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80060020
/* 3B420 80060020 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3B424 80060024 AFB10044 */  sw        $s1, 0x44($sp)
/* 3B428 80060028 0080882D */  daddu     $s1, $a0, $zero
/* 3B42C 8006002C AFB00040 */  sw        $s0, 0x40($sp)
/* 3B430 80060030 27B00020 */  addiu     $s0, $sp, 0x20
/* 3B434 80060034 0200202D */  daddu     $a0, $s0, $zero
/* 3B438 80060038 27A50038 */  addiu     $a1, $sp, 0x38
/* 3B43C 8006003C AFBF0048 */  sw        $ra, 0x48($sp)
/* 3B440 80060040 0C019554 */  jal       func_80065550
/* 3B444 80060044 24060001 */   addiu    $a2, $zero, 1
/* 3B448 80060048 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B44C 8006004C 0200282D */  daddu     $a1, $s0, $zero
/* 3B450 80060050 0C017AB8 */  jal       func_8005EAE0
/* 3B454 80060054 24060001 */   addiu    $a2, $zero, 1
/* 3B458 80060058 12200007 */  beqz      $s1, .L80060078
/* 3B45C 8006005C 27A40020 */   addiu    $a0, $sp, 0x20
.L80060060:
/* 3B460 80060060 0000282D */  daddu     $a1, $zero, $zero
/* 3B464 80060064 0C0195B0 */  jal       func_800656C0
/* 3B468 80060068 24060001 */   addiu    $a2, $zero, 1
/* 3B46C 8006006C 2631FFFF */  addiu     $s1, $s1, -1
/* 3B470 80060070 1620FFFB */  bnez      $s1, .L80060060
/* 3B474 80060074 27A40020 */   addiu    $a0, $sp, 0x20
.L80060078:
/* 3B478 80060078 0C017ADB */  jal       func_8005EB6C
/* 3B47C 8006007C 27A40010 */   addiu    $a0, $sp, 0x10
/* 3B480 80060080 8FBF0048 */  lw        $ra, 0x48($sp)
/* 3B484 80060084 8FB10044 */  lw        $s1, 0x44($sp)
/* 3B488 80060088 8FB00040 */  lw        $s0, 0x40($sp)
/* 3B48C 8006008C 03E00008 */  jr        $ra
/* 3B490 80060090 27BD0050 */   addiu    $sp, $sp, 0x50
/* 3B494 80060094 00000000 */  nop
/* 3B498 80060098 00000000 */  nop
/* 3B49C 8006009C 00000000 */  nop
