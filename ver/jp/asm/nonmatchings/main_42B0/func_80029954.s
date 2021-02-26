.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80029954
/* 4D54 80029954 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4D58 80029958 AFB00010 */  sw        $s0, 0x10($sp)
/* 4D5C 8002995C 2410FFFF */  addiu     $s0, $zero, -1
/* 4D60 80029960 AFB10014 */  sw        $s1, 0x14($sp)
/* 4D64 80029964 24910001 */  addiu     $s1, $a0, 1
/* 4D68 80029968 16200002 */  bnez      $s1, .L80029974
/* 4D6C 8002996C 0211001B */   divu     $zero, $s0, $s1
/* 4D70 80029970 0007000D */  break     7
.L80029974:
/* 4D74 80029974 00008012 */   mflo     $s0
/* 4D78 80029978 16000002 */  bnez      $s0, .L80029984
/* 4D7C 8002997C AFBF0018 */   sw       $ra, 0x18($sp)
/* 4D80 80029980 24100001 */  addiu     $s0, $zero, 1
.L80029984:
/* 4D84 80029984 0C00A630 */  jal       func_800298C0
/* 4D88 80029988 00000000 */   nop
/* 4D8C 8002998C 16000002 */  bnez      $s0, .L80029998
/* 4D90 80029990 0050001B */   divu     $zero, $v0, $s0
/* 4D94 80029994 0007000D */  break     7
.L80029998:
/* 4D98 80029998 00001812 */   mflo     $v1
/* 4D9C 8002999C 0071102B */  sltu      $v0, $v1, $s1
/* 4DA0 800299A0 1040FFF8 */  beqz      $v0, .L80029984
/* 4DA4 800299A4 0060102D */   daddu    $v0, $v1, $zero
/* 4DA8 800299A8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4DAC 800299AC 8FB10014 */  lw        $s1, 0x14($sp)
/* 4DB0 800299B0 8FB00010 */  lw        $s0, 0x10($sp)
/* 4DB4 800299B4 03E00008 */  jr        $ra
/* 4DB8 800299B8 27BD0020 */   addiu    $sp, $sp, 0x20
