.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kzn_04_UnkFunc17
/* C6845C 8024032C 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* C68460 80240330 2442A650 */  addiu     $v0, $v0, %lo(gOverrideFlags)
/* C68464 80240334 8C430000 */  lw        $v1, ($v0)
/* C68468 80240338 2404FFBF */  addiu     $a0, $zero, -0x41
/* C6846C 8024033C 00641824 */  and       $v1, $v1, $a0
/* C68470 80240340 AC430000 */  sw        $v1, ($v0)
/* C68474 80240344 03E00008 */  jr        $ra
/* C68478 80240348 24020002 */   addiu    $v0, $zero, 2
