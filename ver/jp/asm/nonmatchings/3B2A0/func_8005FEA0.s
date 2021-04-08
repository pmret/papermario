.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005FEA0
/* 3B2A0 8005FEA0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3B2A4 8005FEA4 AFB00018 */  sw        $s0, 0x18($sp)
/* 3B2A8 8005FEA8 3C10800B */  lui       $s0, %hi(D_800B1B70)
/* 3B2AC 8005FEAC 26101B70 */  addiu     $s0, $s0, %lo(D_800B1B70)
/* 3B2B0 8005FEB0 0200202D */  daddu     $a0, $s0, $zero
/* 3B2B4 8005FEB4 3C02800B */  lui       $v0, %hi(D_800AC4E0)
/* 3B2B8 8005FEB8 2442C4E0 */  addiu     $v0, $v0, %lo(D_800AC4E0)
/* 3B2BC 8005FEBC AFA20010 */  sw        $v0, 0x10($sp)
/* 3B2C0 8005FEC0 24020032 */  addiu     $v0, $zero, 0x32
/* 3B2C4 8005FEC4 24050004 */  addiu     $a1, $zero, 4
/* 3B2C8 8005FEC8 3C068006 */  lui       $a2, %hi(func_8005FEF8)
/* 3B2CC 8005FECC 24C6FEF8 */  addiu     $a2, $a2, %lo(func_8005FEF8)
/* 3B2D0 8005FED0 0000382D */  daddu     $a3, $zero, $zero
/* 3B2D4 8005FED4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 3B2D8 8005FED8 0C01978C */  jal       func_80065E30
/* 3B2DC 8005FEDC AFA20014 */   sw       $v0, 0x14($sp)
/* 3B2E0 8005FEE0 0C0197FC */  jal       func_80065FF0
/* 3B2E4 8005FEE4 0200202D */   daddu    $a0, $s0, $zero
/* 3B2E8 8005FEE8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 3B2EC 8005FEEC 8FB00018 */  lw        $s0, 0x18($sp)
/* 3B2F0 8005FEF0 03E00008 */  jr        $ra
/* 3B2F4 8005FEF4 27BD0020 */   addiu    $sp, $sp, 0x20
