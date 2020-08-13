.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel CheckButtonHeld
/* 19C9B0 8026E0D0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19C9B4 8026E0D4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 19C9B8 8026E0D8 8C82000C */  lw    $v0, 0xc($a0)
/* 19C9BC 8026E0DC 3C06800E */  lui   $a2, 0x800e
/* 19C9C0 8026E0E0 8CC6C288 */  lw    $a2, -0x3d78($a2)
/* 19C9C4 8026E0E4 8C430000 */  lw    $v1, ($v0)
/* 19C9C8 8026E0E8 8C450004 */  lw    $a1, 4($v0)
/* 19C9CC 8026E0EC 00C33024 */  and   $a2, $a2, $v1
/* 19C9D0 8026E0F0 0C0B2026 */  jal   set_variable
/* 19C9D4 8026E0F4 0006302B */   sltu  $a2, $zero, $a2
/* 19C9D8 8026E0F8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 19C9DC 8026E0FC 24020002 */  addiu $v0, $zero, 2
/* 19C9E0 8026E100 03E00008 */  jr    $ra
/* 19C9E4 8026E104 27BD0018 */   addiu $sp, $sp, 0x18

