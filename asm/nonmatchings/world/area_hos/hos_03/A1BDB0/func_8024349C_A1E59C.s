.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024349C_A1E59C
/* A1E59C 8024349C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1E5A0 802434A0 3C058025 */  lui       $a1, %hi(D_8024BDE8)
/* A1E5A4 802434A4 8CA5BDE8 */  lw        $a1, %lo(D_8024BDE8)($a1)
/* A1E5A8 802434A8 AFBF0010 */  sw        $ra, 0x10($sp)
/* A1E5AC 802434AC 0C0B1EAF */  jal       get_variable
/* A1E5B0 802434B0 0000202D */   daddu    $a0, $zero, $zero
/* A1E5B4 802434B4 0040182D */  daddu     $v1, $v0, $zero
/* A1E5B8 802434B8 24020001 */  addiu     $v0, $zero, 1
/* A1E5BC 802434BC 14620006 */  bne       $v1, $v0, .L802434D8
/* A1E5C0 802434C0 24020002 */   addiu    $v0, $zero, 2
/* A1E5C4 802434C4 44800000 */  mtc1      $zero, $f0
/* A1E5C8 802434C8 00000000 */  nop
/* A1E5CC 802434CC 44050000 */  mfc1      $a1, $f0
/* A1E5D0 802434D0 08090D3C */  j         .L802434F0
/* A1E5D4 802434D4 0000202D */   daddu    $a0, $zero, $zero
.L802434D8:
/* A1E5D8 802434D8 14620008 */  bne       $v1, $v0, .L802434FC
/* A1E5DC 802434DC 24040001 */   addiu    $a0, $zero, 1
/* A1E5E0 802434E0 44800000 */  mtc1      $zero, $f0
/* A1E5E4 802434E4 00000000 */  nop
/* A1E5E8 802434E8 44050000 */  mfc1      $a1, $f0
/* A1E5EC 802434EC 00000000 */  nop
.L802434F0:
/* A1E5F0 802434F0 00A0302D */  daddu     $a2, $a1, $zero
/* A1E5F4 802434F4 0C01C5A4 */  jal       func_80071690
/* A1E5F8 802434F8 00A0382D */   daddu    $a3, $a1, $zero
.L802434FC:
/* A1E5FC 802434FC 8FBF0010 */  lw        $ra, 0x10($sp)
/* A1E600 80243500 03E00008 */  jr        $ra
/* A1E604 80243504 27BD0018 */   addiu    $sp, $sp, 0x18
