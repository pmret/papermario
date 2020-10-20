.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024001C_D9D4EC
/* D9D4EC 8024001C 3C03800B */  lui       $v1, %hi(gCameras)
/* D9D4F0 80240020 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* D9D4F4 80240024 94620002 */  lhu       $v0, 2($v1)
/* D9D4F8 80240028 34420001 */  ori       $v0, $v0, 1
/* D9D4FC 8024002C A4620002 */  sh        $v0, 2($v1)
/* D9D500 80240030 03E00008 */  jr        $ra
/* D9D504 80240034 24020002 */   addiu    $v0, $zero, 2
/* D9D508 80240038 00000000 */  nop       
/* D9D50C 8024003C 00000000 */  nop       
