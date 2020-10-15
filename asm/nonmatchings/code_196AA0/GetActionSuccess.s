.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetActionSuccess
/* 197B74 80269294 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 197B78 80269298 AFBF0010 */  sw        $ra, 0x10($sp)
/* 197B7C 8026929C 8C82000C */  lw        $v0, 0xc($a0)
/* 197B80 802692A0 3C06800E */  lui       $a2, 0x800e
/* 197B84 802692A4 80C6C0F1 */  lb        $a2, -0x3f0f($a2)
/* 197B88 802692A8 0C0B2026 */  jal       set_variable
/* 197B8C 802692AC 8C450000 */   lw       $a1, ($v0)
/* 197B90 802692B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197B94 802692B4 24020002 */  addiu     $v0, $zero, 2
/* 197B98 802692B8 03E00008 */  jr        $ra
/* 197B9C 802692BC 27BD0018 */   addiu    $sp, $sp, 0x18
