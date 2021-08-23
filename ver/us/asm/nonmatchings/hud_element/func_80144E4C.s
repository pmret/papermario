.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80144E4C
/* DB54C 80144E4C 2402F7FF */  addiu     $v0, $zero, -0x801
/* DB550 80144E50 00822024 */  and       $a0, $a0, $v0
/* DB554 80144E54 3C028015 */  lui       $v0, %hi(hudElements)
/* DB558 80144E58 8C427960 */  lw        $v0, %lo(hudElements)($v0)
/* DB55C 80144E5C 00042080 */  sll       $a0, $a0, 2
/* DB560 80144E60 00822021 */  addu      $a0, $a0, $v0
/* DB564 80144E64 8C820000 */  lw        $v0, ($a0)
/* DB568 80144E68 90420000 */  lbu       $v0, ($v0)
/* DB56C 80144E6C 03E00008 */  jr        $ra
/* DB570 80144E70 3042000F */   andi     $v0, $v0, 0xf
