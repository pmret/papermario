.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80044294
/* 1F694 80044294 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1F698 80044298 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1F69C 8004429C 8C82000C */  lw        $v0, 0xc($a0)
/* 1F6A0 800442A0 8C830148 */  lw        $v1, 0x148($a0)
/* 1F6A4 800442A4 8C450000 */  lw        $a1, ($v0)
/* 1F6A8 800442A8 0C0B2026 */  jal       func_802C8098
/* 1F6AC 800442AC 8C6600C8 */   lw       $a2, 0xc8($v1)
/* 1F6B0 800442B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1F6B4 800442B4 24020002 */  addiu     $v0, $zero, 2
/* 1F6B8 800442B8 03E00008 */  jr        $ra
/* 1F6BC 800442BC 27BD0018 */   addiu    $sp, $sp, 0x18
