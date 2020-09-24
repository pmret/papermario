.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel icon_set_tint
/* DB5FC 80144EFC 2402F7FF */  addiu     $v0, $zero, -0x801
/* DB600 80144F00 00822024 */  and       $a0, $a0, $v0
/* DB604 80144F04 3C028015 */  lui       $v0, 0x8015
/* DB608 80144F08 8C427960 */  lw        $v0, 0x7960($v0)
/* DB60C 80144F0C 00042080 */  sll       $a0, $a0, 2
/* DB610 80144F10 00822021 */  addu      $a0, $a0, $v0
/* DB614 80144F14 8C820000 */  lw        $v0, ($a0)
/* DB618 80144F18 A045004B */  sb        $a1, 0x4b($v0)
/* DB61C 80144F1C A046004C */  sb        $a2, 0x4c($v0)
/* DB620 80144F20 03E00008 */  jr        $ra
/* DB624 80144F24 A047004D */   sb       $a3, 0x4d($v0)
