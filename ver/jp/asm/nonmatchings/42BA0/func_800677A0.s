.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800677A0
/* 42BA0 800677A0 AC850000 */  sw        $a1, ($a0)
/* 42BA4 800677A4 AC800004 */  sw        $zero, 4($a0)
/* 42BA8 800677A8 AC800008 */  sw        $zero, 8($a0)
/* 42BAC 800677AC AC80000C */  sw        $zero, 0xc($a0)
/* 42BB0 800677B0 AC800010 */  sw        $zero, 0x10($a0)
/* 42BB4 800677B4 AC860014 */  sw        $a2, 0x14($a0)
/* 42BB8 800677B8 AC800018 */  sw        $zero, 0x18($a0)
/* 42BBC 800677BC AC80001C */  sw        $zero, 0x1c($a0)
/* 42BC0 800677C0 AC800020 */  sw        $zero, 0x20($a0)
/* 42BC4 800677C4 AC800024 */  sw        $zero, 0x24($a0)
/* 42BC8 800677C8 AC870028 */  sw        $a3, 0x28($a0)
/* 42BCC 800677CC AC80002C */  sw        $zero, 0x2c($a0)
/* 42BD0 800677D0 3C083F80 */  lui       $t0, 0x3f80
/* 42BD4 800677D4 AC800030 */  sw        $zero, 0x30($a0)
/* 42BD8 800677D8 AC800034 */  sw        $zero, 0x34($a0)
/* 42BDC 800677DC AC800038 */  sw        $zero, 0x38($a0)
/* 42BE0 800677E0 03E00008 */  jr        $ra
/* 42BE4 800677E4 AC88003C */   sw       $t0, 0x3c($a0)
/* 42BE8 800677E8 00000000 */  nop
/* 42BEC 800677EC 00000000 */  nop
/* 42BF0 800677F0 00000000 */  nop
/* 42BF4 800677F4 00000000 */  nop
/* 42BF8 800677F8 00000000 */  nop
/* 42BFC 800677FC 00000000 */  nop
