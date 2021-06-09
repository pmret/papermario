.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80144E74
/* DB574 80144E74 2402F7FF */  addiu     $v0, $zero, -0x801
/* DB578 80144E78 00822024 */  and       $a0, $a0, $v0
/* DB57C 80144E7C 00042080 */  sll       $a0, $a0, 2
/* DB580 80144E80 3C028015 */  lui       $v0, %hi(gHudElementList)
/* DB584 80144E84 8C427960 */  lw        $v0, %lo(gHudElementList)($v0)
/* DB588 80144E88 3C03F0FF */  lui       $v1, 0xf0ff
/* DB58C 80144E8C 00822021 */  addu      $a0, $a0, $v0
/* DB590 80144E90 8C840000 */  lw        $a0, ($a0)
/* DB594 80144E94 3463FFFF */  ori       $v1, $v1, 0xffff
/* DB598 80144E98 8C820000 */  lw        $v0, ($a0)
/* DB59C 80144E9C 00052E00 */  sll       $a1, $a1, 0x18
/* DB5A0 80144EA0 00431024 */  and       $v0, $v0, $v1
/* DB5A4 80144EA4 00451025 */  or        $v0, $v0, $a1
/* DB5A8 80144EA8 03E00008 */  jr        $ra
/* DB5AC 80144EAC AC820000 */   sw       $v0, ($a0)
