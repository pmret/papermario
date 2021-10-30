.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002B290
/* 6690 8002B290 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6694 8002B294 AFB20018 */  sw        $s2, 0x18($sp)
/* 6698 8002B298 3C128007 */  lui       $s2, %hi(gGameStatusPtr)
/* 669C 8002B29C 2652417C */  addiu     $s2, $s2, %lo(gGameStatusPtr)
/* 66A0 8002B2A0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 66A4 8002B2A4 AFB10014 */  sw        $s1, 0x14($sp)
/* 66A8 8002B2A8 AFB00010 */  sw        $s0, 0x10($sp)
/* 66AC 8002B2AC 8E420000 */  lw        $v0, ($s2)
/* 66B0 8002B2B0 0080802D */  daddu     $s0, $a0, $zero
/* 66B4 8002B2B4 0C00AC45 */  jal       func_8002B114
/* 66B8 8002B2B8 A0500166 */   sb       $s0, 0x166($v0)
/* 66BC 8002B2BC 3C11800E */  lui       $s1, %hi(D_800DACA0)
/* 66C0 8002B2C0 2631ACA0 */  addiu     $s1, $s1, %lo(D_800DACA0)
/* 66C4 8002B2C4 0220282D */  daddu     $a1, $s1, $zero
/* 66C8 8002B2C8 001080C0 */  sll       $s0, $s0, 3
/* 66CC 8002B2CC 3C04800A */  lui       $a0, %hi(D_8009BA10)
/* 66D0 8002B2D0 00902021 */  addu      $a0, $a0, $s0
/* 66D4 8002B2D4 8C84BA10 */  lw        $a0, %lo(D_8009BA10)($a0)
/* 66D8 8002B2D8 0C00AE0A */  jal       func_8002B828
/* 66DC 8002B2DC 24061380 */   addiu    $a2, $zero, 0x1380
/* 66E0 8002B2E0 3C058007 */  lui       $a1, %hi(D_800745B0)
/* 66E4 8002B2E4 24A545B0 */  addiu     $a1, $a1, %lo(D_800745B0)
/* 66E8 8002B2E8 0C01BB54 */  jal       func_8006ED50
/* 66EC 8002B2EC 0220202D */   daddu    $a0, $s1, $zero
/* 66F0 8002B2F0 1440000A */  bnez      $v0, .L8002B31C
/* 66F4 8002B2F4 0000102D */   daddu    $v0, $zero, $zero
/* 66F8 8002B2F8 8E430000 */  lw        $v1, ($s2)
/* 66FC 8002B2FC 8E24003C */  lw        $a0, 0x3c($s1)
/* 6700 8002B300 8C620168 */  lw        $v0, 0x168($v1)
/* 6704 8002B304 0044102B */  sltu      $v0, $v0, $a0
/* 6708 8002B308 54400001 */  bnel      $v0, $zero, .L8002B310
/* 670C 8002B30C AC640168 */   sw       $a0, 0x168($v1)
.L8002B310:
/* 6710 8002B310 0C00AD14 */  jal       func_8002B450
/* 6714 8002B314 00000000 */   nop
/* 6718 8002B318 24020001 */  addiu     $v0, $zero, 1
.L8002B31C:
/* 671C 8002B31C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6720 8002B320 8FB20018 */  lw        $s2, 0x18($sp)
/* 6724 8002B324 8FB10014 */  lw        $s1, 0x14($sp)
/* 6728 8002B328 8FB00010 */  lw        $s0, 0x10($sp)
/* 672C 8002B32C 03E00008 */  jr        $ra
/* 6730 8002B330 27BD0020 */   addiu    $sp, $sp, 0x20
