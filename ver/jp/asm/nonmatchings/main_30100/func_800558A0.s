.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800558A0
/* 30CA0 800558A0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30CA4 800558A4 24020001 */  addiu     $v0, $zero, 1
/* 30CA8 800558A8 AFA40010 */  sw        $a0, 0x10($sp)
/* 30CAC 800558AC 27A40010 */  addiu     $a0, $sp, 0x10
/* 30CB0 800558B0 0000282D */  daddu     $a1, $zero, $zero
/* 30CB4 800558B4 AFBF0030 */  sw        $ra, 0x30($sp)
/* 30CB8 800558B8 AFA00014 */  sw        $zero, 0x14($sp)
/* 30CBC 800558BC AFA00018 */  sw        $zero, 0x18($sp)
/* 30CC0 800558C0 AFA0001C */  sw        $zero, 0x1c($sp)
/* 30CC4 800558C4 AFA00020 */  sw        $zero, 0x20($sp)
/* 30CC8 800558C8 0C01365A */  jal       func_8004D968
/* 30CCC 800558CC AFA20024 */   sw       $v0, 0x24($sp)
/* 30CD0 800558D0 8FBF0030 */  lw        $ra, 0x30($sp)
/* 30CD4 800558D4 03E00008 */  jr        $ra
/* 30CD8 800558D8 27BD0038 */   addiu    $sp, $sp, 0x38
