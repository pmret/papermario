.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024001C_BCD07C
/* BCD07C 8024001C 3C03800B */  lui       $v1, %hi(gCameras)
/* BCD080 80240020 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* BCD084 80240024 94620002 */  lhu       $v0, 2($v1)
/* BCD088 80240028 34420001 */  ori       $v0, $v0, 1
/* BCD08C 8024002C A4620002 */  sh        $v0, 2($v1)
/* BCD090 80240030 03E00008 */  jr        $ra
/* BCD094 80240034 24020002 */   addiu    $v0, $zero, 2
