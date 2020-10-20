.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422C8
/* 825588 802422C8 3C028025 */  lui       $v0, 0x8025
/* 82558C 802422CC 8C42E568 */  lw        $v0, -0x1a98($v0)
/* 825590 802422D0 8C43000C */  lw        $v1, 0xc($v0)
/* 825594 802422D4 24020001 */  addiu     $v0, $zero, 1
/* 825598 802422D8 AC62001C */  sw        $v0, 0x1c($v1)
/* 82559C 802422DC 03E00008 */  jr        $ra
/* 8255A0 802422E0 24020002 */   addiu    $v0, $zero, 2
