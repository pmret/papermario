.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800558DC
/* 30CDC 800558DC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 30CE0 800558E0 24020001 */  addiu     $v0, $zero, 1
/* 30CE4 800558E4 AFA40010 */  sw        $a0, 0x10($sp)
/* 30CE8 800558E8 27A40010 */  addiu     $a0, $sp, 0x10
/* 30CEC 800558EC AFBF0030 */  sw        $ra, 0x30($sp)
/* 30CF0 800558F0 AFA00014 */  sw        $zero, 0x14($sp)
/* 30CF4 800558F4 AFA00018 */  sw        $zero, 0x18($sp)
/* 30CF8 800558F8 AFA0001C */  sw        $zero, 0x1c($sp)
/* 30CFC 800558FC AFA00020 */  sw        $zero, 0x20($sp)
/* 30D00 80055900 0C0136B7 */  jal       func_8004DADC
/* 30D04 80055904 AFA20024 */   sw       $v0, 0x24($sp)
/* 30D08 80055908 8FBF0030 */  lw        $ra, 0x30($sp)
/* 30D0C 8005590C 03E00008 */  jr        $ra
/* 30D10 80055910 27BD0038 */   addiu    $sp, $sp, 0x38
