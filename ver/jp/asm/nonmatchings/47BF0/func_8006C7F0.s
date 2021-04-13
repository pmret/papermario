.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006C7F0
/* 47BF0 8006C7F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 47BF4 8006C7F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 47BF8 8006C7F8 00808021 */  addu      $s0, $a0, $zero
/* 47BFC 8006C7FC AFB10014 */  sw        $s1, 0x14($sp)
/* 47C00 8006C800 AFBF0018 */  sw        $ra, 0x18($sp)
/* 47C04 8006C804 0C01B5F0 */  jal       func_8006D7C0
/* 47C08 8006C808 00A08821 */   addu     $s1, $a1, $zero
/* 47C0C 8006C80C 54400005 */  bnel      $v0, $zero, .L8006C824
/* 47C10 8006C810 2402FFFF */   addiu    $v0, $zero, -1
/* 47C14 8006C814 3C02A000 */  lui       $v0, 0xa000
/* 47C18 8006C818 02021025 */  or        $v0, $s0, $v0
/* 47C1C 8006C81C AC510000 */  sw        $s1, ($v0)
/* 47C20 8006C820 00001021 */  addu      $v0, $zero, $zero
.L8006C824:
/* 47C24 8006C824 8FBF0018 */  lw        $ra, 0x18($sp)
/* 47C28 8006C828 8FB10014 */  lw        $s1, 0x14($sp)
/* 47C2C 8006C82C 8FB00010 */  lw        $s0, 0x10($sp)
/* 47C30 8006C830 03E00008 */  jr        $ra
/* 47C34 8006C834 27BD0020 */   addiu    $sp, $sp, 0x20
/* 47C38 8006C838 00000000 */  nop
/* 47C3C 8006C83C 00000000 */  nop
