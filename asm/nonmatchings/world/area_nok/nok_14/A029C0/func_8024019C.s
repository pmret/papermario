.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024019C
/* A029DC 8024019C 3C03800B */  lui       $v1, %hi(gCameras)
/* A029E0 802401A0 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* A029E4 802401A4 94620000 */  lhu       $v0, ($v1)
/* A029E8 802401A8 3042EFFF */  andi      $v0, $v0, 0xefff
/* A029EC 802401AC A4620000 */  sh        $v0, ($v1)
/* A029F0 802401B0 03E00008 */  jr        $ra
/* A029F4 802401B4 24020002 */   addiu    $v0, $zero, 2
/* A029F8 802401B8 00000000 */  nop       
/* A029FC 802401BC 00000000 */  nop       
