.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802431DC_DC048C
/* DC048C 802431DC 3C03800B */  lui       $v1, %hi(gCameras)
/* DC0490 802431E0 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* DC0494 802431E4 94620002 */  lhu       $v0, 2($v1)
/* DC0498 802431E8 3042FFFE */  andi      $v0, $v0, 0xfffe
/* DC049C 802431EC A4620002 */  sh        $v0, 2($v1)
/* DC04A0 802431F0 03E00008 */  jr        $ra
/* DC04A4 802431F4 24020002 */   addiu    $v0, $zero, 2
