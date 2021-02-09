.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osCreateMesgQueue
/* 40980 80065580 3C028009 */  lui       $v0, %hi(D_80094650)
/* 40984 80065584 24424650 */  addiu     $v0, $v0, %lo(D_80094650)
/* 40988 80065588 AC820000 */  sw        $v0, ($a0)
/* 4098C 8006558C AC820004 */  sw        $v0, 4($a0)
/* 40990 80065590 AC800008 */  sw        $zero, 8($a0)
/* 40994 80065594 AC80000C */  sw        $zero, 0xc($a0)
/* 40998 80065598 AC860010 */  sw        $a2, 0x10($a0)
/* 4099C 8006559C 03E00008 */  jr        $ra
/* 409A0 800655A0 AC850014 */   sw       $a1, 0x14($a0)
/* 409A4 800655A4 00000000 */  nop
/* 409A8 800655A8 00000000 */  nop
/* 409AC 800655AC 00000000 */  nop
