.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006B830
/* 46C30 8006B830 3C02A450 */  lui       $v0, 0xa450
/* 46C34 8006B834 3442000C */  ori       $v0, $v0, 0xc
/* 46C38 8006B838 8C420000 */  lw        $v0, ($v0)
/* 46C3C 8006B83C 03E00008 */  jr        $ra
/* 46C40 8006B840 28420000 */   slti     $v0, $v0, 0
/* 46C44 8006B844 00000000 */  nop
/* 46C48 8006B848 00000000 */  nop
/* 46C4C 8006B84C 00000000 */  nop
