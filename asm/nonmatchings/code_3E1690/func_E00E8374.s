.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00E8374
/* 3E1A04 E00E8374 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3E1A08 E00E8378 3C02E00F */  lui       $v0, %hi(D_E00E83BC)
/* 3E1A0C E00E837C 244283BC */  addiu     $v0, $v0, %lo(D_E00E83BC)
/* 3E1A10 E00E8380 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3E1A14 E00E8384 2402000A */  addiu     $v0, $zero, 0xa
/* 3E1A18 E00E8388 AFA20014 */  sw        $v0, 0x14($sp)
/* 3E1A1C E00E838C 2402002D */  addiu     $v0, $zero, 0x2d
/* 3E1A20 E00E8390 AFA40018 */  sw        $a0, 0x18($sp)
/* 3E1A24 E00E8394 27A40010 */  addiu     $a0, $sp, 0x10
/* 3E1A28 E00E8398 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3E1A2C E00E839C 0C080120 */  jal       func_E0200480
/* 3E1A30 E00E83A0 AFA20010 */   sw       $v0, 0x10($sp)
/* 3E1A34 E00E83A4 8C430000 */  lw        $v1, ($v0)
/* 3E1A38 E00E83A8 34630002 */  ori       $v1, $v1, 2
/* 3E1A3C E00E83AC AC430000 */  sw        $v1, ($v0)
/* 3E1A40 E00E83B0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3E1A44 E00E83B4 03E00008 */  jr        $ra
/* 3E1A48 E00E83B8 27BD0028 */   addiu    $sp, $sp, 0x28
