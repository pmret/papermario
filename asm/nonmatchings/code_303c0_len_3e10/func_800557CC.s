.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800557CC
/* 30BCC 800557CC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 30BD0 800557D0 AFB10014 */  sw        $s1, 0x14($sp)
/* 30BD4 800557D4 0080882D */  daddu     $s1, $a0, $zero
/* 30BD8 800557D8 AFB20018 */  sw        $s2, 0x18($sp)
/* 30BDC 800557DC 24120004 */  addiu     $s2, $zero, 4
/* 30BE0 800557E0 AFB00010 */  sw        $s0, 0x10($sp)
/* 30BE4 800557E4 0000802D */  daddu     $s0, $zero, $zero
/* 30BE8 800557E8 AFBF001C */  sw        $ra, 0x1c($sp)
.L800557EC:
/* 30BEC 800557EC 3C028008 */  lui       $v0, %hi(D_80078DB6)
/* 30BF0 800557F0 94428DB6 */  lhu       $v0, %lo(D_80078DB6)($v0)
/* 30BF4 800557F4 16020005 */  bne       $s0, $v0, .L8005580C
/* 30BF8 800557F8 0200202D */   daddu    $a0, $s0, $zero
/* 30BFC 800557FC 0C01553A */  jal       func_800554E8
/* 30C00 80055800 0220282D */   daddu    $a1, $s1, $zero
/* 30C04 80055804 08015606 */  j         .L80055818
/* 30C08 80055808 0040182D */   daddu    $v1, $v0, $zero
.L8005580C:
/* 30C0C 8005580C 0C015529 */  jal       func_800554A4
/* 30C10 80055810 0200202D */   daddu    $a0, $s0, $zero
/* 30C14 80055814 0040182D */  daddu     $v1, $v0, $zero
.L80055818:
/* 30C18 80055818 14600004 */  bnez      $v1, .L8005582C
/* 30C1C 8005581C 26100001 */   addiu    $s0, $s0, 1
/* 30C20 80055820 0212102B */  sltu      $v0, $s0, $s2
/* 30C24 80055824 1440FFF1 */  bnez      $v0, .L800557EC
/* 30C28 80055828 00000000 */   nop      
.L8005582C:
/* 30C2C 8005582C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 30C30 80055830 8FB20018 */  lw        $s2, 0x18($sp)
/* 30C34 80055834 8FB10014 */  lw        $s1, 0x14($sp)
/* 30C38 80055838 8FB00010 */  lw        $s0, 0x10($sp)
/* 30C3C 8005583C 0060102D */  daddu     $v0, $v1, $zero
/* 30C40 80055840 03E00008 */  jr        $ra
/* 30C44 80055844 27BD0020 */   addiu    $sp, $sp, 0x20
