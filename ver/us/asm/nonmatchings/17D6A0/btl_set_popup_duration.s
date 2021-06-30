.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel btl_set_popup_duration
/* 17E3A4 8024FAC4 3C02802A */  lui       $v0, %hi(D_8029F64A)
/* 17E3A8 8024FAC8 8442F64A */  lh        $v0, %lo(D_8029F64A)($v0)
/* 17E3AC 8024FACC 3C038028 */  lui       $v1, %hi(D_802838F8)
/* 17E3B0 8024FAD0 10400003 */  beqz      $v0, .L8024FAE0
/* 17E3B4 8024FAD4 8C6338F8 */   lw       $v1, %lo(D_802838F8)($v1)
/* 17E3B8 8024FAD8 54600001 */  bnel      $v1, $zero, .L8024FAE0
/* 17E3BC 8024FADC A4640014 */   sh       $a0, 0x14($v1)
.L8024FAE0:
/* 17E3C0 8024FAE0 03E00008 */  jr        $ra
/* 17E3C4 8024FAE4 00000000 */   nop
