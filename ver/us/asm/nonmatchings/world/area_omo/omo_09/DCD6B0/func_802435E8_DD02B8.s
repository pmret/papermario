.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802435E8_DD02B8
/* DD02B8 802435E8 3C03800B */  lui       $v1, %hi(gCameras)
/* DD02BC 802435EC 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* DD02C0 802435F0 94620000 */  lhu       $v0, ($v1)
/* DD02C4 802435F4 3042EFFF */  andi      $v0, $v0, 0xefff
/* DD02C8 802435F8 A4620000 */  sh        $v0, ($v1)
/* DD02CC 802435FC 03E00008 */  jr        $ra
/* DD02D0 80243600 24020002 */   addiu    $v0, $zero, 2
/* DD02D4 80243604 00000000 */  nop
/* DD02D8 80243608 00000000 */  nop
/* DD02DC 8024360C 00000000 */  nop
