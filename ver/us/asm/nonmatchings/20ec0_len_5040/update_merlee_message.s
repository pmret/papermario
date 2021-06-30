.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_800986B0
.word L80045DB4_211B4, L80045DC0_211C0, L80045DCC_211CC, L80045E08_21208, L80045E14_21214, 0

.section .text

glabel update_merlee_message
/* 2117C 80045D7C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 21180 80045D80 AFB00010 */  sw        $s0, 0x10($sp)
/* 21184 80045D84 0080802D */  daddu     $s0, $a0, $zero
/* 21188 80045D88 AFBF0014 */  sw        $ra, 0x14($sp)
/* 2118C 80045D8C 82030016 */  lb        $v1, 0x16($s0)
/* 21190 80045D90 2C620005 */  sltiu     $v0, $v1, 5
/* 21194 80045D94 10400020 */  beqz      $v0, .L80045E18
/* 21198 80045D98 0000202D */   daddu    $a0, $zero, $zero
/* 2119C 80045D9C 00031080 */  sll       $v0, $v1, 2
/* 211A0 80045DA0 3C01800A */  lui       $at, %hi(jtbl_800986B0)
/* 211A4 80045DA4 00220821 */  addu      $at, $at, $v0
/* 211A8 80045DA8 8C2286B0 */  lw        $v0, %lo(jtbl_800986B0)($at)
/* 211AC 80045DAC 00400008 */  jr        $v0
/* 211B0 80045DB0 00000000 */   nop
glabel L80045DB4_211B4
/* 211B4 80045DB4 24020001 */  addiu     $v0, $zero, 1
/* 211B8 80045DB8 08011786 */  j         .L80045E18
/* 211BC 80045DBC A2020016 */   sb       $v0, 0x16($s0)
glabel L80045DC0_211C0
/* 211C0 80045DC0 24020002 */  addiu     $v0, $zero, 2
/* 211C4 80045DC4 08011786 */  j         .L80045E18
/* 211C8 80045DC8 A2020016 */   sb       $v0, 0x16($s0)
glabel L80045DCC_211CC
/* 211CC 80045DCC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 211D0 80045DD0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 211D4 80045DD4 8C420010 */  lw        $v0, 0x10($v0)
/* 211D8 80045DD8 3042C000 */  andi      $v0, $v0, 0xc000
/* 211DC 80045DDC 54400001 */  bnel      $v0, $zero, .L80045DE4
/* 211E0 80045DE0 A6000014 */   sh       $zero, 0x14($s0)
.L80045DE4:
/* 211E4 80045DE4 86020014 */  lh        $v0, 0x14($s0)
/* 211E8 80045DE8 96030014 */  lhu       $v1, 0x14($s0)
/* 211EC 80045DEC 10400003 */  beqz      $v0, .L80045DFC
/* 211F0 80045DF0 2462FFFF */   addiu    $v0, $v1, -1
/* 211F4 80045DF4 08011786 */  j         .L80045E18
/* 211F8 80045DF8 A6020014 */   sh       $v0, 0x14($s0)
.L80045DFC:
/* 211FC 80045DFC 24020003 */  addiu     $v0, $zero, 3
/* 21200 80045E00 08011786 */  j         .L80045E18
/* 21204 80045E04 A2020016 */   sb       $v0, 0x16($s0)
glabel L80045E08_21208
/* 21208 80045E08 24020004 */  addiu     $v0, $zero, 4
/* 2120C 80045E0C 08011786 */  j         .L80045E18
/* 21210 80045E10 A2020016 */   sb       $v0, 0x16($s0)
glabel L80045E14_21214
/* 21214 80045E14 24040001 */  addiu     $a0, $zero, 1
.L80045E18:
/* 21218 80045E18 10800008 */  beqz      $a0, .L80045E3C
/* 2121C 80045E1C 00000000 */   nop
/* 21220 80045E20 24040009 */  addiu     $a0, $zero, 9
/* 21224 80045E24 0C051F9F */  jal       set_window_update
/* 21228 80045E28 24050002 */   addiu    $a1, $zero, 2
/* 2122C 80045E2C 3C01800A */  lui       $at, %hi(D_800A0F40)
/* 21230 80045E30 AC200F40 */  sw        $zero, %lo(D_800A0F40)($at)
/* 21234 80045E34 0C011731 */  jal       dispose_merlee_message
/* 21238 80045E38 0200202D */   daddu    $a0, $s0, $zero
.L80045E3C:
/* 2123C 80045E3C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 21240 80045E40 8FB00010 */  lw        $s0, 0x10($sp)
/* 21244 80045E44 03E00008 */  jr        $ra
/* 21248 80045E48 27BD0018 */   addiu    $sp, $sp, 0x18
