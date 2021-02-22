.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80110BF8
/* A72F8 80110BF8 3C03FFFE */  lui       $v1, 0xfffe
/* A72FC 80110BFC 8C820000 */  lw        $v0, ($a0)
/* A7300 80110C00 3463FFFF */  ori       $v1, $v1, 0xffff
/* A7304 80110C04 A0800007 */  sb        $zero, 7($a0)
/* A7308 80110C08 00431024 */  and       $v0, $v0, $v1
/* A730C 80110C0C 03E00008 */  jr        $ra
/* A7310 80110C10 AC820000 */   sw       $v0, ($a0)
