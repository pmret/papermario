.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_cam_zoom
/* 17CE74 8024E594 3C028028 */  lui       $v0, %hi(D_80280CE0)
/* 17CE78 8024E598 80420CE0 */  lb        $v0, %lo(D_80280CE0)($v0)
/* 17CE7C 8024E59C 14400003 */  bnez      $v0, .L8024E5AC
/* 17CE80 8024E5A0 00000000 */   nop      
/* 17CE84 8024E5A4 3C01802A */  lui       $at, %hi(D_8029F280)
/* 17CE88 8024E5A8 A424F280 */  sh        $a0, %lo(D_8029F280)($at)
.L8024E5AC:
/* 17CE8C 8024E5AC 03E00008 */  jr        $ra
/* 17CE90 8024E5B0 00000000 */   nop      
