.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241154_B29184
/* B29184 80241154 3C03800B */  lui       $v1, %hi(gCameras)
/* B29188 80241158 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* B2918C 8024115C 94620000 */  lhu       $v0, ($v1)
/* B29190 80241160 34421000 */  ori       $v0, $v0, 0x1000
/* B29194 80241164 A4620000 */  sh        $v0, ($v1)
/* B29198 80241168 03E00008 */  jr        $ra
/* B2919C 8024116C 24020002 */   addiu    $v0, $zero, 2
