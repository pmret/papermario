.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802431F8
/* DC04A8 802431F8 3C03800B */  lui       $v1, %hi(gCameras)
/* DC04AC 802431FC 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* DC04B0 80243200 94620002 */  lhu       $v0, 2($v1)
/* DC04B4 80243204 34420001 */  ori       $v0, $v0, 1
/* DC04B8 80243208 A4620002 */  sh        $v0, 2($v1)
/* DC04BC 8024320C 03E00008 */  jr        $ra
/* DC04C0 80243210 24020002 */   addiu    $v0, $zero, 2
/* DC04C4 80243214 00000000 */  nop       
/* DC04C8 80243218 00000000 */  nop       
/* DC04CC 8024321C 00000000 */  nop       
