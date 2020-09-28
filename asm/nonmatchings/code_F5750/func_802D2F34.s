.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D2F34
/* F78E4 802D2F34 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* F78E8 802D2F38 F7B60020 */  sdc1      $f22, 0x20($sp)
/* F78EC 802D2F3C 4485B000 */  mtc1      $a1, $f22
/* F78F0 802D2F40 3C0140C9 */  lui       $at, 0x40c9
/* F78F4 802D2F44 34210FD0 */  ori       $at, $at, 0xfd0
/* F78F8 802D2F48 44810000 */  mtc1      $at, $f0
/* F78FC 802D2F4C 44862000 */  mtc1      $a2, $f4
/* F7900 802D2F50 F7B40018 */  sdc1      $f20, 0x18($sp)
/* F7904 802D2F54 46002502 */  mul.s     $f20, $f4, $f0
/* F7908 802D2F58 00000000 */  nop       
/* F790C 802D2F5C AFB00010 */  sw        $s0, 0x10($sp)
/* F7910 802D2F60 3C0143B4 */  lui       $at, 0x43b4
/* F7914 802D2F64 44810000 */  mtc1      $at, $f0
/* F7918 802D2F68 0080802D */  daddu     $s0, $a0, $zero
/* F791C 802D2F6C AFBF0014 */  sw        $ra, 0x14($sp)
/* F7920 802D2F70 4600A503 */  div.s     $f20, $f20, $f0
/* F7924 802D2F74 0C00A85B */  jal       sin_rad
/* F7928 802D2F78 4600A306 */   mov.s    $f12, $f20
/* F792C 802D2F7C 4600A306 */  mov.s     $f12, $f20
/* F7930 802D2F80 0C00A874 */  jal       cos_rad
/* F7934 802D2F84 46000506 */   mov.s    $f20, $f0
/* F7938 802D2F88 4614B502 */  mul.s     $f20, $f22, $f20
/* F793C 802D2F8C 00000000 */  nop       
/* F7940 802D2F90 4600B587 */  neg.s     $f22, $f22
/* F7944 802D2F94 4600B582 */  mul.s     $f22, $f22, $f0
/* F7948 802D2F98 00000000 */  nop       
/* F794C 802D2F9C C6020004 */  lwc1      $f2, 4($s0)
/* F7950 802D2FA0 46141080 */  add.s     $f2, $f2, $f20
/* F7954 802D2FA4 C600000C */  lwc1      $f0, 0xc($s0)
/* F7958 802D2FA8 46160000 */  add.s     $f0, $f0, $f22
/* F795C 802D2FAC E6020004 */  swc1      $f2, 4($s0)
/* F7960 802D2FB0 E600000C */  swc1      $f0, 0xc($s0)
/* F7964 802D2FB4 8FBF0014 */  lw        $ra, 0x14($sp)
/* F7968 802D2FB8 8FB00010 */  lw        $s0, 0x10($sp)
/* F796C 802D2FBC D7B60020 */  ldc1      $f22, 0x20($sp)
/* F7970 802D2FC0 D7B40018 */  ldc1      $f20, 0x18($sp)
/* F7974 802D2FC4 03E00008 */  jr        $ra
/* F7978 802D2FC8 27BD0028 */   addiu    $sp, $sp, 0x28
