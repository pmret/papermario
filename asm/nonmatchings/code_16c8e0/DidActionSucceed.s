.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel DidActionSucceed
/* 1A5794 80276EB4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1A5798 80276EB8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 1A579C 80276EBC 8C82000C */  lw    $v0, 0xc($a0)
/* 1A57A0 80276EC0 3C03800E */  lui   $v1, 0x800e
/* 1A57A4 80276EC4 8063C0F1 */  lb    $v1, -0x3f0f($v1)
/* 1A57A8 80276EC8 8C450000 */  lw    $a1, ($v0)
/* 1A57AC 80276ECC 04610002 */  bgez  $v1, .L80276ED8
/* 1A57B0 80276ED0 0000302D */   daddu $a2, $zero, $zero
/* 1A57B4 80276ED4 00C0182D */  daddu $v1, $a2, $zero
.L80276ED8:
/* 1A57B8 80276ED8 00C3102A */  slt   $v0, $a2, $v1
/* 1A57BC 80276EDC 54400001 */  bnezl $v0, .L80276EE4
/* 1A57C0 80276EE0 0060302D */   daddu $a2, $v1, $zero
.L80276EE4:
/* 1A57C4 80276EE4 0C0B2026 */  jal   set_variable
/* 1A57C8 80276EE8 00000000 */   nop   
/* 1A57CC 80276EEC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 1A57D0 80276EF0 24020002 */  addiu $v0, $zero, 2
/* 1A57D4 80276EF4 03E00008 */  jr    $ra
/* 1A57D8 80276EF8 27BD0018 */   addiu $sp, $sp, 0x18

/* 1A57DC 80276EFC 3C02800E */  lui   $v0, 0x800e
/* 1A57E0 80276F00 2442C070 */  addiu $v0, $v0, -0x3f90
/* 1A57E4 80276F04 8C430000 */  lw    $v1, ($v0)
/* 1A57E8 80276F08 3C040020 */  lui   $a0, 0x20
/* 1A57EC 80276F0C 00641825 */  or    $v1, $v1, $a0
/* 1A57F0 80276F10 AC430000 */  sw    $v1, ($v0)
/* 1A57F4 80276F14 03E00008 */  jr    $ra
/* 1A57F8 80276F18 24020002 */   addiu $v0, $zero, 2

/* 1A57FC 80276F1C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1A5800 80276F20 AFBF0010 */  sw    $ra, 0x10($sp)
/* 1A5804 80276F24 8C82000C */  lw    $v0, 0xc($a0)
/* 1A5808 80276F28 0C0B1EAF */  jal   get_variable
/* 1A580C 80276F2C 8C450000 */   lw    $a1, ($v0)
/* 1A5810 80276F30 0C09C596 */  jal   dispatch_event_player
/* 1A5814 80276F34 0040202D */   daddu $a0, $v0, $zero
/* 1A5818 80276F38 8FBF0010 */  lw    $ra, 0x10($sp)
/* 1A581C 80276F3C 24020002 */  addiu $v0, $zero, 2
/* 1A5820 80276F40 03E00008 */  jr    $ra
/* 1A5824 80276F44 27BD0018 */   addiu $sp, $sp, 0x18

/* 1A5828 80276F48 00000000 */  nop   
/* 1A582C 80276F4C 00000000 */  nop   
