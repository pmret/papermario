.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_801499EC
/* E00EC 801499EC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* E00F0 801499F0 F7B40020 */  sdc1      $f20, 0x20($sp)
/* E00F4 801499F4 4486A000 */  mtc1      $a2, $f20
/* E00F8 801499F8 AFB00010 */  sw        $s0, 0x10($sp)
/* E00FC 801499FC 0080802D */  daddu     $s0, $a0, $zero
/* E0100 80149A00 AFB10014 */  sw        $s1, 0x14($sp)
/* E0104 80149A04 F7B60028 */  sdc1      $f22, 0x28($sp)
/* E0108 80149A08 4487B000 */  mtc1      $a3, $f22
/* E010C 80149A0C AFBF0018 */  sw        $ra, 0x18($sp)
/* E0110 80149A10 0C052631 */  jal       func_801498C4
/* E0114 80149A14 00A0882D */   daddu    $s1, $a1, $zero
/* E0118 80149A18 0040202D */  daddu     $a0, $v0, $zero
/* E011C 80149A1C 1080000B */  beqz      $a0, .L80149A4C
/* E0120 80149A20 24020001 */   addiu    $v0, $zero, 1
/* E0124 80149A24 8C830000 */  lw        $v1, ($a0)
/* E0128 80149A28 AC910008 */  sw        $s1, 8($a0)
/* E012C 80149A2C E4940010 */  swc1      $f20, 0x10($a0)
/* E0130 80149A30 E4960014 */  swc1      $f22, 0x14($a0)
/* E0134 80149A34 C7A00040 */  lwc1      $f0, 0x40($sp)
/* E0138 80149A38 AC900004 */  sw        $s0, 4($a0)
/* E013C 80149A3C 34630003 */  ori       $v1, $v1, 3
/* E0140 80149A40 E4800018 */  swc1      $f0, 0x18($a0)
/* E0144 80149A44 08052694 */  j         .L80149A50
/* E0148 80149A48 AC830000 */   sw       $v1, ($a0)
.L80149A4C:
/* E014C 80149A4C 0000102D */  daddu     $v0, $zero, $zero
.L80149A50:
/* E0150 80149A50 8FBF0018 */  lw        $ra, 0x18($sp)
/* E0154 80149A54 8FB10014 */  lw        $s1, 0x14($sp)
/* E0158 80149A58 8FB00010 */  lw        $s0, 0x10($sp)
/* E015C 80149A5C D7B60028 */  ldc1      $f22, 0x28($sp)
/* E0160 80149A60 D7B40020 */  ldc1      $f20, 0x20($sp)
/* E0164 80149A64 03E00008 */  jr        $ra
/* E0168 80149A68 27BD0030 */   addiu    $sp, $sp, 0x30
