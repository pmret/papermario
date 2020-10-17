.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025DEB0
/* 18C790 8025DEB0 3C02800E */  lui       $v0, 0x800e
/* 18C794 8025DEB4 8042C0E8 */  lb        $v0, -0x3f18($v0)
/* 18C798 8025DEB8 AC820084 */  sw        $v0, 0x84($a0)
/* 18C79C 8025DEBC 03E00008 */  jr        $ra
/* 18C7A0 8025DEC0 24020002 */   addiu    $v0, $zero, 2
