.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B24_D07254
/* D07254 80241B24 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D07258 80241B28 3C058025 */  lui       $a1, %hi(D_8024B9A8)
/* D0725C 80241B2C 8CA5B9A8 */  lw        $a1, %lo(D_8024B9A8)($a1)
/* D07260 80241B30 AFBF0010 */  sw        $ra, 0x10($sp)
/* D07264 80241B34 0C0B1EAF */  jal       get_variable
/* D07268 80241B38 0000202D */   daddu    $a0, $zero, $zero
/* D0726C 80241B3C 0040182D */  daddu     $v1, $v0, $zero
/* D07270 80241B40 24020001 */  addiu     $v0, $zero, 1
/* D07274 80241B44 14620006 */  bne       $v1, $v0, .L80241B60
/* D07278 80241B48 24020002 */   addiu    $v0, $zero, 2
/* D0727C 80241B4C 44800000 */  mtc1      $zero, $f0
/* D07280 80241B50 00000000 */  nop
/* D07284 80241B54 44050000 */  mfc1      $a1, $f0
/* D07288 80241B58 080906DE */  j         .L80241B78
/* D0728C 80241B5C 0000202D */   daddu    $a0, $zero, $zero
.L80241B60:
/* D07290 80241B60 14620008 */  bne       $v1, $v0, .L80241B84
/* D07294 80241B64 24040001 */   addiu    $a0, $zero, 1
/* D07298 80241B68 44800000 */  mtc1      $zero, $f0
/* D0729C 80241B6C 00000000 */  nop
/* D072A0 80241B70 44050000 */  mfc1      $a1, $f0
/* D072A4 80241B74 00000000 */  nop
.L80241B78:
/* D072A8 80241B78 00A0302D */  daddu     $a2, $a1, $zero
/* D072AC 80241B7C 0C01C5A4 */  jal       func_80071690
/* D072B0 80241B80 00A0382D */   daddu    $a3, $a1, $zero
.L80241B84:
/* D072B4 80241B84 8FBF0010 */  lw        $ra, 0x10($sp)
/* D072B8 80241B88 03E00008 */  jr        $ra
/* D072BC 80241B8C 27BD0018 */   addiu    $sp, $sp, 0x18
