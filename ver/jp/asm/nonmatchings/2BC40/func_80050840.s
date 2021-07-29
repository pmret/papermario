.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050840
/* 2BC40 80050840 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 2BC44 80050844 AFB00010 */  sw        $s0, 0x10($sp)
/* 2BC48 80050848 0080802D */  daddu     $s0, $a0, $zero
/* 2BC4C 8005084C AFB3001C */  sw        $s3, 0x1c($sp)
/* 2BC50 80050850 00E0982D */  daddu     $s3, $a3, $zero
/* 2BC54 80050854 AFB10014 */  sw        $s1, 0x14($sp)
/* 2BC58 80050858 00A0882D */  daddu     $s1, $a1, $zero
/* 2BC5C 8005085C AFB20018 */  sw        $s2, 0x18($sp)
/* 2BC60 80050860 00C0902D */  daddu     $s2, $a2, $zero
/* 2BC64 80050864 24050834 */  addiu     $a1, $zero, 0x834
/* 2BC68 80050868 AFBF0020 */  sw        $ra, 0x20($sp)
/* 2BC6C 8005086C 0C0152D0 */  jal       func_80054B40
/* 2BC70 80050870 0000302D */   daddu    $a2, $zero, $zero
/* 2BC74 80050874 0000182D */  daddu     $v1, $zero, $zero
/* 2BC78 80050878 24060001 */  addiu     $a2, $zero, 1
/* 2BC7C 8005087C 3C057F00 */  lui       $a1, 0x7f00
/* 2BC80 80050880 24040024 */  addiu     $a0, $zero, 0x24
.L80050884:
/* 2BC84 80050884 02041021 */  addu      $v0, $s0, $a0
/* 2BC88 80050888 A0430014 */  sb        $v1, 0x14($v0)
/* 2BC8C 8005088C 24630001 */  addiu     $v1, $v1, 1
/* 2BC90 80050890 AC460018 */  sw        $a2, 0x18($v0)
/* 2BC94 80050894 AC450038 */  sw        $a1, 0x38($v0)
/* 2BC98 80050898 28620004 */  slti      $v0, $v1, 4
/* 2BC9C 8005089C 1440FFF9 */  bnez      $v0, .L80050884
/* 2BCA0 800508A0 248401E4 */   addiu    $a0, $a0, 0x1e4
/* 2BCA4 800508A4 24020001 */  addiu     $v0, $zero, 1
/* 2BCA8 800508A8 AE020004 */  sw        $v0, 4($s0)
/* 2BCAC 800508AC 24020002 */  addiu     $v0, $zero, 2
/* 2BCB0 800508B0 AE130000 */  sw        $s3, ($s0)
/* 2BCB4 800508B4 AE02000C */  sw        $v0, 0xc($s0)
/* 2BCB8 800508B8 AE020008 */  sw        $v0, 8($s0)
/* 2BCBC 800508BC A2110022 */  sb        $s1, 0x22($s0)
/* 2BCC0 800508C0 A2120023 */  sb        $s2, 0x23($s0)
/* 2BCC4 800508C4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 2BCC8 800508C8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 2BCCC 800508CC 8FB20018 */  lw        $s2, 0x18($sp)
/* 2BCD0 800508D0 8FB10014 */  lw        $s1, 0x14($sp)
/* 2BCD4 800508D4 8FB00010 */  lw        $s0, 0x10($sp)
/* 2BCD8 800508D8 03E00008 */  jr        $ra
/* 2BCDC 800508DC 27BD0028 */   addiu    $sp, $sp, 0x28
