.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D417C
/* F8B2C 802D417C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F8B30 802D4180 AFB20018 */  sw        $s2, 0x18($sp)
/* F8B34 802D4184 3C12802E */  lui       $s2, 0x802e
/* F8B38 802D4188 2652B7C0 */  addiu     $s2, $s2, -0x4840
/* F8B3C 802D418C AFB10014 */  sw        $s1, 0x14($sp)
/* F8B40 802D4190 00048880 */  sll       $s1, $a0, 2
/* F8B44 802D4194 AFBF001C */  sw        $ra, 0x1c($sp)
/* F8B48 802D4198 AFB00010 */  sw        $s0, 0x10($sp)
/* F8B4C 802D419C 8E420000 */  lw        $v0, ($s2)
/* F8B50 802D41A0 02221021 */  addu      $v0, $s1, $v0
/* F8B54 802D41A4 8C500000 */  lw        $s0, ($v0)
/* F8B58 802D41A8 0C048338 */  jal       load_virtual_model
/* F8B5C 802D41AC 00A0202D */   daddu    $a0, $a1, $zero
/* F8B60 802D41B0 3C013F80 */  lui       $at, 0x3f80
/* F8B64 802D41B4 44810000 */  mtc1      $at, $f0
/* F8B68 802D41B8 AE020000 */  sw        $v0, ($s0)
/* F8B6C 802D41BC 0040202D */  daddu     $a0, $v0, $zero
/* F8B70 802D41C0 AE000004 */  sw        $zero, 4($s0)
/* F8B74 802D41C4 AE000008 */  sw        $zero, 8($s0)
/* F8B78 802D41C8 AE00000C */  sw        $zero, 0xc($s0)
/* F8B7C 802D41CC AE000010 */  sw        $zero, 0x10($s0)
/* F8B80 802D41D0 AE000014 */  sw        $zero, 0x14($s0)
/* F8B84 802D41D4 AE000018 */  sw        $zero, 0x18($s0)
/* F8B88 802D41D8 E600001C */  swc1      $f0, 0x1c($s0)
/* F8B8C 802D41DC E6000020 */  swc1      $f0, 0x20($s0)
/* F8B90 802D41E0 0C0483C1 */  jal       func_80120F04
/* F8B94 802D41E4 E6000024 */   swc1     $f0, 0x24($s0)
/* F8B98 802D41E8 8E420000 */  lw        $v0, ($s2)
/* F8B9C 802D41EC 8FBF001C */  lw        $ra, 0x1c($sp)
/* F8BA0 802D41F0 8FB20018 */  lw        $s2, 0x18($sp)
/* F8BA4 802D41F4 8FB00010 */  lw        $s0, 0x10($sp)
/* F8BA8 802D41F8 02228821 */  addu      $s1, $s1, $v0
/* F8BAC 802D41FC 8E220000 */  lw        $v0, ($s1)
/* F8BB0 802D4200 8FB10014 */  lw        $s1, 0x14($sp)
/* F8BB4 802D4204 03E00008 */  jr        $ra
/* F8BB8 802D4208 27BD0020 */   addiu    $sp, $sp, 0x20
