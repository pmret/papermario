.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402DC_DDF5EC
/* DDF5EC 802402DC 3C03800B */  lui       $v1, %hi(gCameras)
/* DDF5F0 802402E0 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* DDF5F4 802402E4 94620000 */  lhu       $v0, ($v1)
/* DDF5F8 802402E8 34421000 */  ori       $v0, $v0, 0x1000
/* DDF5FC 802402EC A4620000 */  sh        $v0, ($v1)
/* DDF600 802402F0 03E00008 */  jr        $ra
/* DDF604 802402F4 24020002 */   addiu    $v0, $zero, 2
