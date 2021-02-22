.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osAiDeviceBusy
/* 46C50 8006B850 3C02A450 */  lui       $v0, 0xa450
/* 46C54 8006B854 3442000C */  ori       $v0, $v0, 0xc
/* 46C58 8006B858 8C420000 */  lw        $v0, ($v0)
/* 46C5C 8006B85C 03E00008 */  jr        $ra
/* 46C60 8006B860 28420000 */   slti     $v0, $v0, 0
/* 46C64 8006B864 00000000 */  nop
/* 46C68 8006B868 00000000 */  nop
/* 46C6C 8006B86C 00000000 */  nop
