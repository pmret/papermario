.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel UpdateColliderTransform
/* 0EEB38 802CA188 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EEB3C 802CA18C AFBF0010 */  sw    $ra, 0x10($sp)
/* 0EEB40 802CA190 8C82000C */  lw    $v0, 0xc($a0)
/* 0EEB44 802CA194 0C0B1EAF */  jal   get_variable
/* 0EEB48 802CA198 8C450000 */   lw    $a1, ($v0)
/* 0EEB4C 802CA19C 00021400 */  sll   $v0, $v0, 0x10
/* 0EEB50 802CA1A0 0C016E89 */  jal   update_collider_transform
/* 0EEB54 802CA1A4 00022403 */   sra   $a0, $v0, 0x10
/* 0EEB58 802CA1A8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0EEB5C 802CA1AC 24020002 */  addiu $v0, $zero, 2
/* 0EEB60 802CA1B0 03E00008 */  jr    $ra
/* 0EEB64 802CA1B4 27BD0018 */   addiu $sp, $sp, 0x18

