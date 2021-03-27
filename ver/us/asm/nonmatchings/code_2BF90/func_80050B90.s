.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050B90
/* 2BF90 80050B90 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 2BF94 80050B94 AFB00010 */  sw        $s0, 0x10($sp)
/* 2BF98 80050B98 0080802D */  daddu     $s0, $a0, $zero
/* 2BF9C 80050B9C AFB3001C */  sw        $s3, 0x1c($sp)
/* 2BFA0 80050BA0 00E0982D */  daddu     $s3, $a3, $zero
/* 2BFA4 80050BA4 AFB10014 */  sw        $s1, 0x14($sp)
/* 2BFA8 80050BA8 00A0882D */  daddu     $s1, $a1, $zero
/* 2BFAC 80050BAC AFB20018 */  sw        $s2, 0x18($sp)
/* 2BFB0 80050BB0 00C0902D */  daddu     $s2, $a2, $zero
/* 2BFB4 80050BB4 24050834 */  addiu     $a1, $zero, 0x834
/* 2BFB8 80050BB8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 2BFBC 80050BBC 0C0153A4 */  jal       snd_memset
/* 2BFC0 80050BC0 0000302D */   daddu    $a2, $zero, $zero
/* 2BFC4 80050BC4 0000182D */  daddu     $v1, $zero, $zero
/* 2BFC8 80050BC8 24060001 */  addiu     $a2, $zero, 1
/* 2BFCC 80050BCC 3C057F00 */  lui       $a1, 0x7f00
/* 2BFD0 80050BD0 24040024 */  addiu     $a0, $zero, 0x24
.L80050BD4:
/* 2BFD4 80050BD4 02041021 */  addu      $v0, $s0, $a0
/* 2BFD8 80050BD8 A0430014 */  sb        $v1, 0x14($v0)
/* 2BFDC 80050BDC 24630001 */  addiu     $v1, $v1, 1
/* 2BFE0 80050BE0 AC460018 */  sw        $a2, 0x18($v0)
/* 2BFE4 80050BE4 AC450038 */  sw        $a1, 0x38($v0)
/* 2BFE8 80050BE8 28620004 */  slti      $v0, $v1, 4
/* 2BFEC 80050BEC 1440FFF9 */  bnez      $v0, .L80050BD4
/* 2BFF0 80050BF0 248401E4 */   addiu    $a0, $a0, 0x1e4
/* 2BFF4 80050BF4 24020001 */  addiu     $v0, $zero, 1
/* 2BFF8 80050BF8 AE020004 */  sw        $v0, 4($s0)
/* 2BFFC 80050BFC 24020002 */  addiu     $v0, $zero, 2
/* 2C000 80050C00 AE130000 */  sw        $s3, ($s0)
/* 2C004 80050C04 AE02000C */  sw        $v0, 0xc($s0)
/* 2C008 80050C08 AE020008 */  sw        $v0, 8($s0)
/* 2C00C 80050C0C A2110022 */  sb        $s1, 0x22($s0)
/* 2C010 80050C10 A2120023 */  sb        $s2, 0x23($s0)
/* 2C014 80050C14 8FBF0020 */  lw        $ra, 0x20($sp)
/* 2C018 80050C18 8FB3001C */  lw        $s3, 0x1c($sp)
/* 2C01C 80050C1C 8FB20018 */  lw        $s2, 0x18($sp)
/* 2C020 80050C20 8FB10014 */  lw        $s1, 0x14($sp)
/* 2C024 80050C24 8FB00010 */  lw        $s0, 0x10($sp)
/* 2C028 80050C28 03E00008 */  jr        $ra
/* 2C02C 80050C2C 27BD0028 */   addiu    $sp, $sp, 0x28
