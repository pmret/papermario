.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800269C0
/* 1DC0 800269C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1DC4 800269C4 AFB20018 */  sw        $s2, 0x18($sp)
/* 1DC8 800269C8 3C120001 */  lui       $s2, 1
/* 1DCC 800269CC 36520230 */  ori       $s2, $s2, 0x230
/* 1DD0 800269D0 AFB10014 */  sw        $s1, 0x14($sp)
/* 1DD4 800269D4 3C11800A */  lui       $s1, %hi(D_8009A654)
/* 1DD8 800269D8 2631A654 */  addiu     $s1, $s1, %lo(D_8009A654)
/* 1DDC 800269DC 3C038007 */  lui       $v1, %hi(D_800741D4)
/* 1DE0 800269E0 8C6341D4 */  lw        $v1, %lo(D_800741D4)($v1)
/* 1DE4 800269E4 3C048016 */  lui       $a0, %hi(D_80164000)
/* 1DE8 800269E8 24844000 */  addiu     $a0, $a0, %lo(D_80164000)
/* 1DEC 800269EC AFB00010 */  sw        $s0, 0x10($sp)
/* 1DF0 800269F0 3C10800A */  lui       $s0, %hi(D_8009A64C)
/* 1DF4 800269F4 2610A64C */  addiu     $s0, $s0, %lo(D_8009A64C)
/* 1DF8 800269F8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 1DFC 800269FC 00031040 */  sll       $v0, $v1, 1
/* 1E00 80026A00 00431021 */  addu      $v0, $v0, $v1
/* 1E04 80026A04 00021940 */  sll       $v1, $v0, 5
/* 1E08 80026A08 00431021 */  addu      $v0, $v0, $v1
/* 1E0C 80026A0C 00021980 */  sll       $v1, $v0, 6
/* 1E10 80026A10 00431021 */  addu      $v0, $v0, $v1
/* 1E14 80026A14 00021100 */  sll       $v0, $v0, 4
/* 1E18 80026A18 00441021 */  addu      $v0, $v0, $a0
/* 1E1C 80026A1C AE220000 */  sw        $v0, ($s1)
/* 1E20 80026A20 00521021 */  addu      $v0, $v0, $s2
/* 1E24 80026A24 0C009C5C */  jal       func_80027170
/* 1E28 80026A28 AE020000 */   sw       $v0, ($s0)
/* 1E2C 80026A2C 0C009F78 */  jal       func_80027DE0
/* 1E30 80026A30 00000000 */   nop
/* 1E34 80026A34 8E030000 */  lw        $v1, ($s0)
/* 1E38 80026A38 3C02E900 */  lui       $v0, 0xe900
/* 1E3C 80026A3C 0060202D */  daddu     $a0, $v1, $zero
/* 1E40 80026A40 24630008 */  addiu     $v1, $v1, 8
/* 1E44 80026A44 AE030000 */  sw        $v1, ($s0)
/* 1E48 80026A48 AC820000 */  sw        $v0, ($a0)
/* 1E4C 80026A4C 24620008 */  addiu     $v0, $v1, 8
/* 1E50 80026A50 AC800004 */  sw        $zero, 4($a0)
/* 1E54 80026A54 3C04DF00 */  lui       $a0, 0xdf00
/* 1E58 80026A58 AE020000 */  sw        $v0, ($s0)
/* 1E5C 80026A5C AC640000 */  sw        $a0, ($v1)
/* 1E60 80026A60 AC600004 */  sw        $zero, 4($v1)
/* 1E64 80026A64 8E230000 */  lw        $v1, ($s1)
/* 1E68 80026A68 00521023 */  subu      $v0, $v0, $s2
/* 1E6C 80026A6C 00431023 */  subu      $v0, $v0, $v1
/* 1E70 80026A70 000210C2 */  srl       $v0, $v0, 3
/* 1E74 80026A74 28420200 */  slti      $v0, $v0, 0x200
/* 1E78 80026A78 14400003 */  bnez      $v0, .L80026A88
/* 1E7C 80026A7C 3C040001 */   lui      $a0, 1
.L80026A80:
/* 1E80 80026A80 08009AA0 */  j         .L80026A80
/* 1E84 80026A84 00000000 */   nop
.L80026A88:
/* 1E88 80026A88 34840230 */  ori       $a0, $a0, 0x230
/* 1E8C 80026A8C 0000302D */  daddu     $a2, $zero, $zero
/* 1E90 80026A90 00C0382D */  daddu     $a3, $a2, $zero
/* 1E94 80026A94 3C05800A */  lui       $a1, %hi(D_8009A64C)
/* 1E98 80026A98 8CA5A64C */  lw        $a1, %lo(D_8009A64C)($a1)
/* 1E9C 80026A9C 3C02800A */  lui       $v0, %hi(D_8009A654)
/* 1EA0 80026AA0 8C42A654 */  lw        $v0, %lo(D_8009A654)($v0)
/* 1EA4 80026AA4 00A42823 */  subu      $a1, $a1, $a0
/* 1EA8 80026AA8 00A22823 */  subu      $a1, $a1, $v0
/* 1EAC 80026AAC 000528C3 */  sra       $a1, $a1, 3
/* 1EB0 80026AB0 00442021 */  addu      $a0, $v0, $a0
/* 1EB4 80026AB4 0C00B3C9 */  jal       func_8002CF24
/* 1EB8 80026AB8 000528C0 */   sll      $a1, $a1, 3
/* 1EBC 80026ABC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 1EC0 80026AC0 8FB20018 */  lw        $s2, 0x18($sp)
/* 1EC4 80026AC4 8FB10014 */  lw        $s1, 0x14($sp)
/* 1EC8 80026AC8 8FB00010 */  lw        $s0, 0x10($sp)
/* 1ECC 80026ACC 03E00008 */  jr        $ra
/* 1ED0 80026AD0 27BD0020 */   addiu    $sp, $sp, 0x20
