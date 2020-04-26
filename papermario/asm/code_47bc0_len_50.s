
.section .text8006C7C0, "ax"

func_8006C7C0:
/* 047BC0 8006C7C0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 047BC4 8006C7C4 AFB00010 */  sw    $s0, 0x10($sp)
/* 047BC8 8006C7C8 00808021 */  move  $s0, $a0
/* 047BCC 8006C7CC AFB10014 */  sw    $s1, 0x14($sp)
/* 047BD0 8006C7D0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 047BD4 8006C7D4 0C01B5F8 */  jal   func_8006D7E0
/* 047BD8 8006C7D8 00A08821 */   move  $s1, $a1
/* 047BDC 8006C7DC 14400006 */  bnez  $v0, .L8006C7F8
/* 047BE0 8006C7E0 2402FFFF */   addiu $v0, $zero, -1
/* 047BE4 8006C7E4 3C02A000 */  lui   $v0, 0xa000
/* 047BE8 8006C7E8 02021025 */  or    $v0, $s0, $v0
/* 047BEC 8006C7EC 8C430000 */  lw    $v1, ($v0)
/* 047BF0 8006C7F0 00001021 */  move  $v0, $zero
/* 047BF4 8006C7F4 AE230000 */  sw    $v1, ($s1)
.L8006C7F8:
/* 047BF8 8006C7F8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 047BFC 8006C7FC 8FB10014 */  lw    $s1, 0x14($sp)
/* 047C00 8006C800 8FB00010 */  lw    $s0, 0x10($sp)
/* 047C04 8006C804 03E00008 */  jr    $ra
/* 047C08 8006C808 27BD0020 */   addiu $sp, $sp, 0x20

/* 047C0C 8006C80C 00000000 */  nop   
