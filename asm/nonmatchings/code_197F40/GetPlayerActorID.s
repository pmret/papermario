.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetPlayerActorID
/* 19D254 8026E974 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19D258 8026E978 AFBF0010 */  sw        $ra, 0x10($sp)
/* 19D25C 8026E97C 8C82000C */  lw        $v0, 0xc($a0)
/* 19D260 8026E980 3C06800E */  lui       $a2, 0x800e
/* 19D264 8026E984 84C6C218 */  lh        $a2, -0x3de8($a2)
/* 19D268 8026E988 0C0B2026 */  jal       set_variable
/* 19D26C 8026E98C 8C450000 */   lw       $a1, ($v0)
/* 19D270 8026E990 8FBF0010 */  lw        $ra, 0x10($sp)
/* 19D274 8026E994 24020002 */  addiu     $v0, $zero, 2
/* 19D278 8026E998 03E00008 */  jr        $ra
/* 19D27C 8026E99C 27BD0018 */   addiu    $sp, $sp, 0x18
