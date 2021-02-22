.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802188EC_59EFCC
/* 59EFCC 802188EC 3C018023 */  lui       $at, %hi(D_8022B550)
/* 59EFD0 802188F0 AC20B550 */  sw        $zero, %lo(D_8022B550)($at)
/* 59EFD4 802188F4 03E00008 */  jr        $ra
/* 59EFD8 802188F8 24020002 */   addiu    $v0, $zero, 2
