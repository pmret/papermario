.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel ForceCloseMessageBox
/* 17FCD0 802513F0 3C028028 */  lui       $v0, %hi(D_802838F8)
/* 17FCD4 802513F4 8C4238F8 */  lw        $v0, %lo(D_802838F8)($v0)
/* 17FCD8 802513F8 54400001 */  bnel      $v0, $zero, .L80251400
/* 17FCDC 802513FC A4400014 */   sh       $zero, 0x14($v0)
.L80251400:
/* 17FCE0 80251400 03E00008 */  jr        $ra
/* 17FCE4 80251404 24020002 */   addiu    $v0, $zero, 2
