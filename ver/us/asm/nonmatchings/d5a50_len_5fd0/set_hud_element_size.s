.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_hud_element_size
/* DB4F4 80144DF4 2402F7FF */  addiu     $v0, $zero, -0x801
/* DB4F8 80144DF8 00822024 */  and       $a0, $a0, $v0
/* DB4FC 80144DFC 00042080 */  sll       $a0, $a0, 2
/* DB500 80144E00 3C028015 */  lui       $v0, %hi(gHudElementList)
/* DB504 80144E04 8C427960 */  lw        $v0, %lo(gHudElementList)($v0)
/* DB508 80144E08 3C013F80 */  lui       $at, 0x3f80
/* DB50C 80144E0C 44810000 */  mtc1      $at, $f0
/* DB510 80144E10 00822021 */  addu      $a0, $a0, $v0
/* DB514 80144E14 8C840000 */  lw        $a0, ($a0)
/* DB518 80144E18 24020400 */  addiu     $v0, $zero, 0x400
/* DB51C 80144E1C AC820034 */  sw        $v0, 0x34($a0)
/* DB520 80144E20 AC820038 */  sw        $v0, 0x38($a0)
/* DB524 80144E24 8C820000 */  lw        $v0, ($a0)
/* DB528 80144E28 2403FEFF */  addiu     $v1, $zero, -0x101
/* DB52C 80144E2C A0850046 */  sb        $a1, 0x46($a0)
/* DB530 80144E30 A0850045 */  sb        $a1, 0x45($a0)
/* DB534 80144E34 E4800030 */  swc1      $f0, 0x30($a0)
/* DB538 80144E38 00431024 */  and       $v0, $v0, $v1
/* DB53C 80144E3C 2403F7EF */  addiu     $v1, $zero, -0x811
/* DB540 80144E40 00431024 */  and       $v0, $v0, $v1
/* DB544 80144E44 03E00008 */  jr        $ra
/* DB548 80144E48 AC820000 */   sw       $v0, ($a0)
