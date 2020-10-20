.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E04_DAF204
/* DAF204 80241E04 3C03800B */  lui       $v1, %hi(gCameras)
/* DAF208 80241E08 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* DAF20C 80241E0C 94620000 */  lhu       $v0, ($v1)
/* DAF210 80241E10 34421000 */  ori       $v0, $v0, 0x1000
/* DAF214 80241E14 A4620000 */  sh        $v0, ($v1)
/* DAF218 80241E18 03E00008 */  jr        $ra
/* DAF21C 80241E1C 24020002 */   addiu    $v0, $zero, 2
