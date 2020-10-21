.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241138_7EBE48
/* 7EBE48 80241138 3C028025 */  lui       $v0, 0x8025
/* 7EBE4C 8024113C 8C425B98 */  lw        $v0, 0x5b98($v0)
/* 7EBE50 80241140 8C43000C */  lw        $v1, 0xc($v0)
/* 7EBE54 80241144 24020001 */  addiu     $v0, $zero, 1
/* 7EBE58 80241148 AC62001C */  sw        $v0, 0x1c($v1)
/* 7EBE5C 8024114C 03E00008 */  jr        $ra
/* 7EBE60 80241150 24020002 */   addiu    $v0, $zero, 2
