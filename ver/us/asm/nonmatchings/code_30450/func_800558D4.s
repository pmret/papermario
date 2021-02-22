.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800558D4
/* 30CD4 800558D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 30CD8 800558D8 AFB00018 */  sw        $s0, 0x18($sp)
/* 30CDC 800558DC 0080802D */  daddu     $s0, $a0, $zero
/* 30CE0 800558E0 00A0202D */  daddu     $a0, $a1, $zero
/* 30CE4 800558E4 27A50010 */  addiu     $a1, $sp, 0x10
/* 30CE8 800558E8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 30CEC 800558EC 0C014F16 */  jal       func_80053C58
/* 30CF0 800558F0 27A60014 */   addiu    $a2, $sp, 0x14
/* 30CF4 800558F4 8FA50010 */  lw        $a1, 0x10($sp)
/* 30CF8 800558F8 10A00004 */  beqz      $a1, .L8005590C
/* 30CFC 800558FC 24020003 */   addiu    $v0, $zero, 3
/* 30D00 80055900 8FA60014 */  lw        $a2, 0x14($sp)
/* 30D04 80055904 0C014F3E */  jal       func_80053CF8
/* 30D08 80055908 0200202D */   daddu    $a0, $s0, $zero
.L8005590C:
/* 30D0C 8005590C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 30D10 80055910 8FB00018 */  lw        $s0, 0x18($sp)
/* 30D14 80055914 03E00008 */  jr        $ra
/* 30D18 80055918 27BD0020 */   addiu    $sp, $sp, 0x20
