.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800269EC
/* 1DEC 800269EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1DF0 800269F0 AFB20018 */  sw        $s2, 0x18($sp)
/* 1DF4 800269F4 3C120001 */  lui       $s2, 1
/* 1DF8 800269F8 36520630 */  ori       $s2, $s2, 0x630
/* 1DFC 800269FC AFB10014 */  sw        $s1, 0x14($sp)
/* 1E00 80026A00 3C11800A */  lui       $s1, %hi(D_8009A674)
/* 1E04 80026A04 2631A674 */  addiu     $s1, $s1, %lo(D_8009A674)
/* 1E08 80026A08 3C048007 */  lui       $a0, %hi(D_800741F4)
/* 1E0C 80026A0C 8C8441F4 */  lw        $a0, %lo(D_800741F4)($a0)
/* 1E10 80026A10 3C058016 */  lui       $a1, %hi(D_80164000)
/* 1E14 80026A14 24A54000 */  addiu     $a1, $a1, %lo(D_80164000)
/* 1E18 80026A18 AFB00010 */  sw        $s0, 0x10($sp)
/* 1E1C 80026A1C 3C10800A */  lui       $s0, %hi(D_8009A66C)
/* 1E20 80026A20 2610A66C */  addiu     $s0, $s0, %lo(D_8009A66C)
/* 1E24 80026A24 AFBF001C */  sw        $ra, 0x1c($sp)
/* 1E28 80026A28 00041040 */  sll       $v0, $a0, 1
/* 1E2C 80026A2C 00441021 */  addu      $v0, $v0, $a0
/* 1E30 80026A30 000210C0 */  sll       $v0, $v0, 3
/* 1E34 80026A34 00441021 */  addu      $v0, $v0, $a0
/* 1E38 80026A38 00021980 */  sll       $v1, $v0, 6
/* 1E3C 80026A3C 00431021 */  addu      $v0, $v0, $v1
/* 1E40 80026A40 00021080 */  sll       $v0, $v0, 2
/* 1E44 80026A44 00441023 */  subu      $v0, $v0, $a0
/* 1E48 80026A48 00021100 */  sll       $v0, $v0, 4
/* 1E4C 80026A4C 00451021 */  addu      $v0, $v0, $a1
/* 1E50 80026A50 AE220000 */  sw        $v0, ($s1)
/* 1E54 80026A54 00521021 */  addu      $v0, $v0, $s2
/* 1E58 80026A58 0C009C68 */  jal       func_800271A0
/* 1E5C 80026A5C AE020000 */   sw       $v0, ($s0)
/* 1E60 80026A60 0C009F84 */  jal       func_80027E10
/* 1E64 80026A64 00000000 */   nop      
/* 1E68 80026A68 8E030000 */  lw        $v1, ($s0)
/* 1E6C 80026A6C 3C02E900 */  lui       $v0, 0xe900
/* 1E70 80026A70 0060202D */  daddu     $a0, $v1, $zero
/* 1E74 80026A74 24630008 */  addiu     $v1, $v1, 8
/* 1E78 80026A78 AE030000 */  sw        $v1, ($s0)
/* 1E7C 80026A7C AC820000 */  sw        $v0, ($a0)
/* 1E80 80026A80 24620008 */  addiu     $v0, $v1, 8
/* 1E84 80026A84 AC800004 */  sw        $zero, 4($a0)
/* 1E88 80026A88 3C04DF00 */  lui       $a0, 0xdf00
/* 1E8C 80026A8C AE020000 */  sw        $v0, ($s0)
/* 1E90 80026A90 AC640000 */  sw        $a0, ($v1)
/* 1E94 80026A94 AC600004 */  sw        $zero, 4($v1)
/* 1E98 80026A98 8E230000 */  lw        $v1, ($s1)
/* 1E9C 80026A9C 00521023 */  subu      $v0, $v0, $s2
/* 1EA0 80026AA0 00431023 */  subu      $v0, $v0, $v1
/* 1EA4 80026AA4 000210C2 */  srl       $v0, $v0, 3
/* 1EA8 80026AA8 28420200 */  slti      $v0, $v0, 0x200
/* 1EAC 80026AAC 14400003 */  bnez      $v0, .L80026ABC
/* 1EB0 80026AB0 3C040001 */   lui      $a0, 1
.L80026AB4:
/* 1EB4 80026AB4 08009AAD */  j         .L80026AB4
/* 1EB8 80026AB8 00000000 */   nop      
.L80026ABC:
/* 1EBC 80026ABC 34840630 */  ori       $a0, $a0, 0x630
/* 1EC0 80026AC0 0000302D */  daddu     $a2, $zero, $zero
/* 1EC4 80026AC4 00C0382D */  daddu     $a3, $a2, $zero
/* 1EC8 80026AC8 3C05800A */  lui       $a1, %hi(D_8009A66C)
/* 1ECC 80026ACC 8CA5A66C */  lw        $a1, %lo(D_8009A66C)($a1)
/* 1ED0 80026AD0 3C02800A */  lui       $v0, %hi(D_8009A674)
/* 1ED4 80026AD4 8C42A674 */  lw        $v0, %lo(D_8009A674)($v0)
/* 1ED8 80026AD8 00A42823 */  subu      $a1, $a1, $a0
/* 1EDC 80026ADC 00A22823 */  subu      $a1, $a1, $v0
/* 1EE0 80026AE0 000528C3 */  sra       $a1, $a1, 3
/* 1EE4 80026AE4 00442021 */  addu      $a0, $v0, $a0
/* 1EE8 80026AE8 0C00B331 */  jal       nuGfxTaskStart
/* 1EEC 80026AEC 000528C0 */   sll      $a1, $a1, 3
/* 1EF0 80026AF0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 1EF4 80026AF4 8FB20018 */  lw        $s2, 0x18($sp)
/* 1EF8 80026AF8 8FB10014 */  lw        $s1, 0x14($sp)
/* 1EFC 80026AFC 8FB00010 */  lw        $s0, 0x10($sp)
/* 1F00 80026B00 03E00008 */  jr        $ra
/* 1F04 80026B04 27BD0020 */   addiu    $sp, $sp, 0x20
