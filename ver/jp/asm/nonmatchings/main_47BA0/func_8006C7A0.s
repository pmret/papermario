.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006C7A0
/* 47BA0 8006C7A0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 47BA4 8006C7A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 47BA8 8006C7A8 00808021 */  addu      $s0, $a0, $zero
/* 47BAC 8006C7AC AFB10014 */  sw        $s1, 0x14($sp)
/* 47BB0 8006C7B0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 47BB4 8006C7B4 0C01B5F0 */  jal       func_8006D7C0
/* 47BB8 8006C7B8 00A08821 */   addu     $s1, $a1, $zero
/* 47BBC 8006C7BC 14400006 */  bnez      $v0, .L8006C7D8
/* 47BC0 8006C7C0 2402FFFF */   addiu    $v0, $zero, -1
/* 47BC4 8006C7C4 3C02A000 */  lui       $v0, 0xa000
/* 47BC8 8006C7C8 02021025 */  or        $v0, $s0, $v0
/* 47BCC 8006C7CC 8C430000 */  lw        $v1, ($v0)
/* 47BD0 8006C7D0 00001021 */  addu      $v0, $zero, $zero
/* 47BD4 8006C7D4 AE230000 */  sw        $v1, ($s1)
.L8006C7D8:
/* 47BD8 8006C7D8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 47BDC 8006C7DC 8FB10014 */  lw        $s1, 0x14($sp)
/* 47BE0 8006C7E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 47BE4 8006C7E4 03E00008 */  jr        $ra
/* 47BE8 8006C7E8 27BD0020 */   addiu    $sp, $sp, 0x20
/* 47BEC 8006C7EC 00000000 */  nop
