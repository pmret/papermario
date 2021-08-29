.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetCommandAutoSuccess
/* 197C50 80269370 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 197C54 80269374 AFBF0010 */  sw        $ra, 0x10($sp)
/* 197C58 80269378 8C82000C */  lw        $v0, 0xc($a0)
/* 197C5C 8026937C 3C06802A */  lui       $a2, %hi(D_8029FC3E)
/* 197C60 80269380 80C6FC3E */  lb        $a2, %lo(D_8029FC3E)($a2)
/* 197C64 80269384 0C0B2026 */  jal       evt_set_variable
/* 197C68 80269388 8C450000 */   lw       $a1, ($v0)
/* 197C6C 8026938C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197C70 80269390 24020002 */  addiu     $v0, $zero, 2
/* 197C74 80269394 03E00008 */  jr        $ra
/* 197C78 80269398 27BD0018 */   addiu    $sp, $sp, 0x18
