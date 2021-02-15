.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel guMtxIdentF
/* 428A0 800674A0 3C083F80 */  lui       $t0, 0x3f80
/* 428A4 800674A4 AC880000 */  sw        $t0, ($a0)
/* 428A8 800674A8 AC800004 */  sw        $zero, 4($a0)
/* 428AC 800674AC AC800008 */  sw        $zero, 8($a0)
/* 428B0 800674B0 AC80000C */  sw        $zero, 0xc($a0)
/* 428B4 800674B4 AC800010 */  sw        $zero, 0x10($a0)
/* 428B8 800674B8 AC880014 */  sw        $t0, 0x14($a0)
/* 428BC 800674BC AC800018 */  sw        $zero, 0x18($a0)
/* 428C0 800674C0 AC80001C */  sw        $zero, 0x1c($a0)
/* 428C4 800674C4 AC800020 */  sw        $zero, 0x20($a0)
/* 428C8 800674C8 AC800024 */  sw        $zero, 0x24($a0)
/* 428CC 800674CC AC880028 */  sw        $t0, 0x28($a0)
/* 428D0 800674D0 AC80002C */  sw        $zero, 0x2c($a0)
/* 428D4 800674D4 AC800030 */  sw        $zero, 0x30($a0)
/* 428D8 800674D8 AC800034 */  sw        $zero, 0x34($a0)
/* 428DC 800674DC AC800038 */  sw        $zero, 0x38($a0)
/* 428E0 800674E0 03E00008 */  jr        $ra
/* 428E4 800674E4 AC88003C */   sw       $t0, 0x3c($a0)
/* 428E8 800674E8 00000000 */  nop
/* 428EC 800674EC 00000000 */  nop
/* 428F0 800674F0 00000000 */  nop
/* 428F4 800674F4 00000000 */  nop
/* 428F8 800674F8 00000000 */  nop
/* 428FC 800674FC 00000000 */  nop
