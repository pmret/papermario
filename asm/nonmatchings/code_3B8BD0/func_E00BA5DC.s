.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00BA5DC
/* 3B91AC E00BA5DC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3B91B0 E00BA5E0 3C02E00C */  lui       $v0, %hi(D_E00BA620)
/* 3B91B4 E00BA5E4 2442A620 */  addiu     $v0, $v0, %lo(D_E00BA620)
/* 3B91B8 E00BA5E8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3B91BC E00BA5EC 24020064 */  addiu     $v0, $zero, 0x64
/* 3B91C0 E00BA5F0 AFA20014 */  sw        $v0, 0x14($sp)
/* 3B91C4 E00BA5F4 2402002D */  addiu     $v0, $zero, 0x2d
/* 3B91C8 E00BA5F8 AFA40018 */  sw        $a0, 0x18($sp)
/* 3B91CC E00BA5FC 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B91D0 E00BA600 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3B91D4 E00BA604 0C080120 */  jal       func_E0200480
/* 3B91D8 E00BA608 AFA20010 */   sw       $v0, 0x10($sp)
/* 3B91DC E00BA60C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3B91E0 E00BA610 03E00008 */  jr        $ra
/* 3B91E4 E00BA614 27BD0028 */   addiu    $sp, $sp, 0x28
