.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241EAC_95D0AC
/* 95D0AC 80241EAC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 95D0B0 80241EB0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 95D0B4 80241EB4 8C82000C */  lw        $v0, 0xc($a0)
/* 95D0B8 80241EB8 0C0B1EAF */  jal       get_variable
/* 95D0BC 80241EBC 8C450000 */   lw       $a1, ($v0)
/* 95D0C0 80241EC0 3C038025 */  lui       $v1, %hi(D_8024DFE0)
/* 95D0C4 80241EC4 8C63DFE0 */  lw        $v1, %lo(D_8024DFE0)($v1)
/* 95D0C8 80241EC8 8C63000C */  lw        $v1, 0xc($v1)
/* 95D0CC 80241ECC AC620034 */  sw        $v0, 0x34($v1)
/* 95D0D0 80241ED0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 95D0D4 80241ED4 24020002 */  addiu     $v0, $zero, 2
/* 95D0D8 80241ED8 03E00008 */  jr        $ra
/* 95D0DC 80241EDC 27BD0018 */   addiu    $sp, $sp, 0x18
