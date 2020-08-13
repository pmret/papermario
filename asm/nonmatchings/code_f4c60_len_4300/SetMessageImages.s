.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetMessageImages
/* 0F5620 802D0C70 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F5624 802D0C74 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F5628 802D0C78 8C82000C */  lw    $v0, 0xc($a0)
/* 0F562C 802D0C7C 0C0496CB */  jal   set_message_images
/* 0F5630 802D0C80 8C440000 */   lw    $a0, ($v0)
/* 0F5634 802D0C84 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F5638 802D0C88 24020002 */  addiu $v0, $zero, 2
/* 0F563C 802D0C8C 03E00008 */  jr    $ra
/* 0F5640 802D0C90 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F5644 802D0C94 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F5648 802D0C98 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F564C 802D0C9C 8C82000C */  lw    $v0, 0xc($a0)
/* 0F5650 802D0CA0 0C0B1EAF */  jal   get_variable
/* 0F5654 802D0CA4 8C450000 */   lw    $a1, ($v0)
/* 0F5658 802D0CA8 14400007 */  bnez  $v0, .L802D0CC8
/* 0F565C 802D0CAC 2404FFEF */   addiu $a0, $zero, -0x11
/* 0F5660 802D0CB0 3C03800A */  lui   $v1, 0x800a
/* 0F5664 802D0CB4 2463A650 */  addiu $v1, $v1, -0x59b0
/* 0F5668 802D0CB8 8C620000 */  lw    $v0, ($v1)
/* 0F566C 802D0CBC 34420010 */  ori   $v0, $v0, 0x10
/* 0F5670 802D0CC0 080B4337 */  j     .L802D0CDC
/* 0F5674 802D0CC4 AC620000 */   sw    $v0, ($v1)

.L802D0CC8:
/* 0F5678 802D0CC8 3C02800A */  lui   $v0, 0x800a
/* 0F567C 802D0CCC 2442A650 */  addiu $v0, $v0, -0x59b0
/* 0F5680 802D0CD0 8C430000 */  lw    $v1, ($v0)
/* 0F5684 802D0CD4 00641824 */  and   $v1, $v1, $a0
/* 0F5688 802D0CD8 AC430000 */  sw    $v1, ($v0)
.L802D0CDC:
/* 0F568C 802D0CDC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F5690 802D0CE0 24020002 */  addiu $v0, $zero, 2
/* 0F5694 802D0CE4 03E00008 */  jr    $ra
/* 0F5698 802D0CE8 27BD0018 */   addiu $sp, $sp, 0x18

