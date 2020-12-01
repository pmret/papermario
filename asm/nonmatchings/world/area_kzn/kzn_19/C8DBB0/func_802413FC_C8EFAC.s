.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413FC_C8EFAC
/* C8EFAC 802413FC 3C018025 */  lui       $at, %hi(D_80248380)
/* C8EFB0 80241400 AC208380 */  sw        $zero, %lo(D_80248380)($at)
/* C8EFB4 80241404 03E00008 */  jr        $ra
/* C8EFB8 80241408 24020002 */   addiu    $v0, $zero, 2
