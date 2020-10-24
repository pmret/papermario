.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E20_DAF220
/* DAF220 80241E20 3C03800B */  lui       $v1, %hi(gCameras)
/* DAF224 80241E24 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* DAF228 80241E28 94620000 */  lhu       $v0, ($v1)
/* DAF22C 80241E2C 3042EFFF */  andi      $v0, $v0, 0xefff
/* DAF230 80241E30 A4620000 */  sh        $v0, ($v1)
/* DAF234 80241E34 03E00008 */  jr        $ra
/* DAF238 80241E38 24020002 */   addiu    $v0, $zero, 2
/* DAF23C 80241E3C 00000000 */  nop       
