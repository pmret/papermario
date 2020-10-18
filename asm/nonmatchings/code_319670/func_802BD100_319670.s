.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD100_319670
/* 319670 802BD100 24020025 */  addiu     $v0, $zero, 0x25
/* 319674 802BD104 A48200A8 */  sh        $v0, 0xa8($a0)
/* 319678 802BD108 24020028 */  addiu     $v0, $zero, 0x28
/* 31967C 802BD10C A48200A6 */  sh        $v0, 0xa6($a0)
/* 319680 802BD110 3C01802C */  lui       $at, 0x802c
/* 319684 802BD114 AC20EBB0 */  sw        $zero, -0x1450($at)
/* 319688 802BD118 3C01802C */  lui       $at, 0x802c
/* 31968C 802BD11C AC20EBC0 */  sw        $zero, -0x1440($at)
/* 319690 802BD120 3C01802C */  lui       $at, 0x802c
/* 319694 802BD124 AC20EBB4 */  sw        $zero, -0x144c($at)
/* 319698 802BD128 3C01802C */  lui       $at, 0x802c
/* 31969C 802BD12C AC20EBB8 */  sw        $zero, -0x1448($at)
/* 3196A0 802BD130 3C01802C */  lui       $at, 0x802c
/* 3196A4 802BD134 AC20EBBC */  sw        $zero, -0x1444($at)
/* 3196A8 802BD138 3C01802C */  lui       $at, 0x802c
/* 3196AC 802BD13C AC20EBC4 */  sw        $zero, -0x143c($at)
/* 3196B0 802BD140 03E00008 */  jr        $ra
/* 3196B4 802BD144 00000000 */   nop      
