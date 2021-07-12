.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel btl_cam_unfreeze
/* 17CEE0 8024E600 3C018028 */  lui       $at, %hi(D_80280CE0)
/* 17CEE4 8024E604 03E00008 */  jr        $ra
/* 17CEE8 8024E608 A0200CE0 */   sb       $zero, %lo(D_80280CE0)($at)
