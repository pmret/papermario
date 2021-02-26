.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005E560
/* 39960 8005E560 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 39964 8005E564 AFBF001C */  sw        $ra, 0x1c($sp)
/* 39968 8005E568 0C01A9BA */  jal       func_8006A6E8
/* 3996C 8005E56C AFB00018 */   sw       $s0, 0x18($sp)
/* 39970 8005E570 3C10800A */  lui       $s0, %hi(D_800A2080)
/* 39974 8005E574 26102080 */  addiu     $s0, $s0, %lo(D_800A2080)
/* 39978 8005E578 0200202D */  daddu     $a0, $s0, $zero
/* 3997C 8005E57C 3C02800A */  lui       $v0, %hi(D_800A43E0)
/* 39980 8005E580 244243E0 */  addiu     $v0, $v0, %lo(D_800A43E0)
/* 39984 8005E584 AFA20010 */  sw        $v0, 0x10($sp)
/* 39988 8005E588 2402000A */  addiu     $v0, $zero, 0xa
/* 3998C 8005E58C 24050001 */  addiu     $a1, $zero, 1
/* 39990 8005E590 3C068006 */  lui       $a2, %hi(func_8005E5BC)
/* 39994 8005E594 24C6E5BC */  addiu     $a2, $a2, %lo(func_8005E5BC)
/* 39998 8005E598 0000382D */  daddu     $a3, $zero, $zero
/* 3999C 8005E59C 0C01978C */  jal       func_80065E30
/* 399A0 8005E5A0 AFA20014 */   sw       $v0, 0x14($sp)
/* 399A4 8005E5A4 0C0197FC */  jal       func_80065FF0
/* 399A8 8005E5A8 0200202D */   daddu    $a0, $s0, $zero
/* 399AC 8005E5AC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 399B0 8005E5B0 8FB00018 */  lw        $s0, 0x18($sp)
/* 399B4 8005E5B4 03E00008 */  jr        $ra
/* 399B8 8005E5B8 27BD0020 */   addiu    $sp, $sp, 0x20
