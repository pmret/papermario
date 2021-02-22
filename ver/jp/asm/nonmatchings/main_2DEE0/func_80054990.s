.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054990
/* 2FD90 80054990 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 2FD94 80054994 AFB10014 */  sw        $s1, 0x14($sp)
/* 2FD98 80054998 0080882D */  daddu     $s1, $a0, $zero
/* 2FD9C 8005499C 2CA20009 */  sltiu     $v0, $a1, 9
/* 2FDA0 800549A0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 2FDA4 800549A4 1040001A */  beqz      $v0, .L80054A10
/* 2FDA8 800549A8 AFB00010 */   sw       $s0, 0x10($sp)
/* 2FDAC 800549AC 00051040 */  sll       $v0, $a1, 1
/* 2FDB0 800549B0 3C108008 */  lui       $s0, %hi(D_80078500)
/* 2FDB4 800549B4 02028021 */  addu      $s0, $s0, $v0
/* 2FDB8 800549B8 96108500 */  lhu       $s0, %lo(D_80078500)($s0)
/* 2FDBC 800549BC 32220001 */  andi      $v0, $s1, 1
/* 2FDC0 800549C0 1040000C */  beqz      $v0, .L800549F4
/* 2FDC4 800549C4 32220010 */   andi     $v0, $s1, 0x10
/* 2FDC8 800549C8 3C02800A */  lui       $v0, %hi(D_8009A644)
/* 2FDCC 800549CC 8C42A644 */  lw        $v0, %lo(D_8009A644)($v0)
/* 2FDD0 800549D0 2444002C */  addiu     $a0, $v0, 0x2c
/* 2FDD4 800549D4 0C014DDE */  jal       func_80053778
/* 2FDD8 800549D8 AC500048 */   sw       $s0, 0x48($v0)
/* 2FDDC 800549DC 3C02800A */  lui       $v0, %hi(D_8009A5DC)
/* 2FDE0 800549E0 8C42A5DC */  lw        $v0, %lo(D_8009A5DC)($v0)
/* 2FDE4 800549E4 2444002C */  addiu     $a0, $v0, 0x2c
/* 2FDE8 800549E8 0C014DDE */  jal       func_80053778
/* 2FDEC 800549EC AC500048 */   sw       $s0, 0x48($v0)
/* 2FDF0 800549F0 32220010 */  andi      $v0, $s1, 0x10
.L800549F4:
/* 2FDF4 800549F4 10400006 */  beqz      $v0, .L80054A10
/* 2FDF8 800549F8 00000000 */   nop
/* 2FDFC 800549FC 3C02800A */  lui       $v0, %hi(D_8009A620)
/* 2FE00 80054A00 8C42A620 */  lw        $v0, %lo(D_8009A620)($v0)
/* 2FE04 80054A04 24440040 */  addiu     $a0, $v0, 0x40
/* 2FE08 80054A08 0C014DDE */  jal       func_80053778
/* 2FE0C 80054A0C AC50005C */   sw       $s0, 0x5c($v0)
.L80054A10:
/* 2FE10 80054A10 8FBF0018 */  lw        $ra, 0x18($sp)
/* 2FE14 80054A14 8FB10014 */  lw        $s1, 0x14($sp)
/* 2FE18 80054A18 8FB00010 */  lw        $s0, 0x10($sp)
/* 2FE1C 80054A1C 03E00008 */  jr        $ra
/* 2FE20 80054A20 27BD0020 */   addiu    $sp, $sp, 0x20
