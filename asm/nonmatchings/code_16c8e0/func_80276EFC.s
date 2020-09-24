.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80276EFC
/* 1A57DC 80276EFC 3C02800E */  lui       $v0, 0x800e
/* 1A57E0 80276F00 2442C070 */  addiu     $v0, $v0, -0x3f90
/* 1A57E4 80276F04 8C430000 */  lw        $v1, ($v0)
/* 1A57E8 80276F08 3C040020 */  lui       $a0, 0x20
/* 1A57EC 80276F0C 00641825 */  or        $v1, $v1, $a0
/* 1A57F0 80276F10 AC430000 */  sw        $v1, ($v0)
/* 1A57F4 80276F14 03E00008 */  jr        $ra
/* 1A57F8 80276F18 24020002 */   addiu    $v0, $zero, 2
