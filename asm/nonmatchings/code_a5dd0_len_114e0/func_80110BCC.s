.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80110BCC
/* 0A72CC 80110BCC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A72D0 80110BD0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0A72D4 80110BD4 8C820000 */  lw    $v0, ($a0)
/* 0A72D8 80110BD8 30420008 */  andi  $v0, $v0, 8
/* 0A72DC 80110BDC 14400003 */  bnez  $v0, .L80110BEC
/* 0A72E0 80110BE0 00000000 */   nop   
/* 0A72E4 80110BE4 0C048B5F */  jal   func_80122D7C
/* 0A72E8 80110BE8 84840014 */   lh    $a0, 0x14($a0)
.L80110BEC:
/* 0A72EC 80110BEC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0A72F0 80110BF0 03E00008 */  jr    $ra
/* 0A72F4 80110BF4 27BD0018 */   addiu $sp, $sp, 0x18

/* 0A72F8 80110BF8 3C03FFFE */  lui   $v1, 0xfffe
/* 0A72FC 80110BFC 8C820000 */  lw    $v0, ($a0)
/* 0A7300 80110C00 3463FFFF */  ori   $v1, $v1, 0xffff
/* 0A7304 80110C04 A0800007 */  sb    $zero, 7($a0)
/* 0A7308 80110C08 00431024 */  and   $v0, $v0, $v1
/* 0A730C 80110C0C 03E00008 */  jr    $ra
/* 0A7310 80110C10 AC820000 */   sw    $v0, ($a0)

