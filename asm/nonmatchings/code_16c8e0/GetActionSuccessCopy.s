.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetActionSuccessCopy
/* 197DD8 802694F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 197DDC 802694FC AFBF0010 */  sw        $ra, 0x10($sp)
/* 197DE0 80269500 8C82000C */  lw        $v0, 0xc($a0)
/* 197DE4 80269504 3C06800E */  lui       $a2, 0x800e
/* 197DE8 80269508 80C6C0F1 */  lb        $a2, -0x3f0f($a2)
/* 197DEC 8026950C 0C0B2026 */  jal       set_variable
/* 197DF0 80269510 8C450000 */   lw       $a1, ($v0)
/* 197DF4 80269514 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197DF8 80269518 24020002 */  addiu     $v0, $zero, 2
/* 197DFC 8026951C 03E00008 */  jr        $ra
/* 197E00 80269520 27BD0018 */   addiu    $sp, $sp, 0x18
