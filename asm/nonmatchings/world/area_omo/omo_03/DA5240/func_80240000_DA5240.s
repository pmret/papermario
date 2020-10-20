.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_DA5240
/* DA5240 80240000 3C03800B */  lui       $v1, %hi(gCameras)
/* DA5244 80240004 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* DA5248 80240008 94620002 */  lhu       $v0, 2($v1)
/* DA524C 8024000C 3042FFFE */  andi      $v0, $v0, 0xfffe
/* DA5250 80240010 A4620002 */  sh        $v0, 2($v1)
/* DA5254 80240014 03E00008 */  jr        $ra
/* DA5258 80240018 24020002 */   addiu    $v0, $zero, 2
/* DA525C 8024001C 00000000 */  nop       
