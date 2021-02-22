.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel is_popup_displayed
/* 17E394 8024FAB4 3C028028 */  lui       $v0, %hi(D_802838F8)
/* 17E398 8024FAB8 8C4238F8 */  lw        $v0, %lo(D_802838F8)($v0)
/* 17E39C 8024FABC 03E00008 */  jr        $ra
/* 17E3A0 8024FAC0 0002102B */   sltu     $v0, $zero, $v0
