.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045A3C
/* 20E3C 80045A3C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 20E40 80045A40 AFB00010 */  sw        $s0, 0x10($sp)
/* 20E44 80045A44 0080802D */  daddu     $s0, $a0, $zero
/* 20E48 80045A48 AFBF0014 */  sw        $ra, 0x14($sp)
/* 20E4C 80045A4C 82030016 */  lb        $v1, 0x16($s0)
/* 20E50 80045A50 2C620005 */  sltiu     $v0, $v1, 5
/* 20E54 80045A54 10400020 */  beqz      $v0, .L80045AD8
/* 20E58 80045A58 0000202D */   daddu    $a0, $zero, $zero
/* 20E5C 80045A5C 00031080 */  sll       $v0, $v1, 2
/* 20E60 80045A60 3C01800A */  lui       $at, %hi(D_80098690)
/* 20E64 80045A64 00220821 */  addu      $at, $at, $v0
/* 20E68 80045A68 8C228690 */  lw        $v0, %lo(D_80098690)($at)
/* 20E6C 80045A6C 00400008 */  jr        $v0
/* 20E70 80045A70 00000000 */   nop
/* 20E74 80045A74 24020001 */  addiu     $v0, $zero, 1
/* 20E78 80045A78 080116B6 */  j         .L80045AD8
/* 20E7C 80045A7C A2020016 */   sb       $v0, 0x16($s0)
/* 20E80 80045A80 24020002 */  addiu     $v0, $zero, 2
/* 20E84 80045A84 080116B6 */  j         .L80045AD8
/* 20E88 80045A88 A2020016 */   sb       $v0, 0x16($s0)
/* 20E8C 80045A8C 3C028007 */  lui       $v0, %hi(D_8007417C)
/* 20E90 80045A90 8C42417C */  lw        $v0, %lo(D_8007417C)($v0)
/* 20E94 80045A94 8C420010 */  lw        $v0, 0x10($v0)
/* 20E98 80045A98 3042C000 */  andi      $v0, $v0, 0xc000
/* 20E9C 80045A9C 54400001 */  bnel      $v0, $zero, .L80045AA4
/* 20EA0 80045AA0 A6000014 */   sh       $zero, 0x14($s0)
.L80045AA4:
/* 20EA4 80045AA4 86020014 */  lh        $v0, 0x14($s0)
/* 20EA8 80045AA8 96030014 */  lhu       $v1, 0x14($s0)
/* 20EAC 80045AAC 10400003 */  beqz      $v0, .L80045ABC
/* 20EB0 80045AB0 2462FFFF */   addiu    $v0, $v1, -1
/* 20EB4 80045AB4 080116B6 */  j         .L80045AD8
/* 20EB8 80045AB8 A6020014 */   sh       $v0, 0x14($s0)
.L80045ABC:
/* 20EBC 80045ABC 24020003 */  addiu     $v0, $zero, 3
/* 20EC0 80045AC0 080116B6 */  j         .L80045AD8
/* 20EC4 80045AC4 A2020016 */   sb       $v0, 0x16($s0)
/* 20EC8 80045AC8 24020004 */  addiu     $v0, $zero, 4
/* 20ECC 80045ACC 080116B6 */  j         .L80045AD8
/* 20ED0 80045AD0 A2020016 */   sb       $v0, 0x16($s0)
/* 20ED4 80045AD4 24040001 */  addiu     $a0, $zero, 1
.L80045AD8:
/* 20ED8 80045AD8 10800008 */  beqz      $a0, .L80045AFC
/* 20EDC 80045ADC 00000000 */   nop
/* 20EE0 80045AE0 24040009 */  addiu     $a0, $zero, 9
/* 20EE4 80045AE4 0C0533CB */  jal       func_8014CF2C
/* 20EE8 80045AE8 24050002 */   addiu    $a1, $zero, 2
/* 20EEC 80045AEC 3C01800A */  lui       $at, %hi(D_8009ED50)
/* 20EF0 80045AF0 AC20ED50 */  sw        $zero, %lo(D_8009ED50)($at)
/* 20EF4 80045AF4 0C011661 */  jal       func_80045984
/* 20EF8 80045AF8 0200202D */   daddu    $a0, $s0, $zero
.L80045AFC:
/* 20EFC 80045AFC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 20F00 80045B00 8FB00010 */  lw        $s0, 0x10($sp)
/* 20F04 80045B04 03E00008 */  jr        $ra
/* 20F08 80045B08 27BD0018 */   addiu    $sp, $sp, 0x18
