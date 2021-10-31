.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005E5BC
/* 399BC 8005E5BC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 399C0 8005E5C0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 399C4 8005E5C4 AFB00018 */  sw        $s0, 0x18($sp)
/* 399C8 8005E5C8 3C01800A */  lui       $at, %hi(D_8009A610)
/* 399CC 8005E5CC 0C017C40 */  jal       func_8005F100
/* 399D0 8005E5D0 AC20A610 */   sw       $zero, %lo(D_8009A610)($at)
/* 399D4 8005E5D4 24040002 */  addiu     $a0, $zero, 2
/* 399D8 8005E5D8 0C017998 */  jal       func_8005E660
/* 399DC 8005E5DC 24050001 */   addiu    $a1, $zero, 1
/* 399E0 8005E5E0 0C019B8C */  jal       osViSetSpecialFeatures
/* 399E4 8005E5E4 2404005A */   addiu    $a0, $zero, 0x5a
/* 399E8 8005E5E8 3C10800A */  lui       $s0, %hi(D_800A2230)
/* 399EC 8005E5EC 26102230 */  addiu     $s0, $s0, %lo(D_800A2230)
/* 399F0 8005E5F0 0200202D */  daddu     $a0, $s0, $zero
/* 399F4 8005E5F4 24050003 */  addiu     $a1, $zero, 3
/* 399F8 8005E5F8 3C02800C */  lui       $v0, %hi(D_800B8570)
/* 399FC 8005E5FC 24428570 */  addiu     $v0, $v0, %lo(D_800B8570)
/* 39A00 8005E600 AFA20010 */  sw        $v0, 0x10($sp)
/* 39A04 8005E604 2402000A */  addiu     $v0, $zero, 0xa
/* 39A08 8005E608 3C068002 */  lui       $a2, %hi(boot_main)
/* 39A0C 8005E60C 24C65F70 */  addiu     $a2, $a2, %lo(boot_main)
/* 39A10 8005E610 0000382D */  daddu     $a3, $zero, $zero
/* 39A14 8005E614 0C01978C */  jal       func_80065E30
/* 39A18 8005E618 AFA20014 */   sw       $v0, 0x14($sp)
/* 39A1C 8005E61C 0C0197FC */  jal       func_80065FF0
/* 39A20 8005E620 0200202D */   daddu    $a0, $s0, $zero
/* 39A24 8005E624 3C04800A */  lui       $a0, %hi(D_800A2080)
/* 39A28 8005E628 24842080 */  addiu     $a0, $a0, %lo(D_800A2080)
/* 39A2C 8005E62C 0C0197C8 */  jal       func_80065F20
/* 39A30 8005E630 0000282D */   daddu    $a1, $zero, $zero
.L8005E634:
/* 39A34 8005E634 3C02800A */  lui       $v0, %hi(D_8009A610)
/* 39A38 8005E638 8C42A610 */  lw        $v0, %lo(D_8009A610)($v0)
.L8005E63C:
/* 39A3C 8005E63C 1040FFFF */  beqz      $v0, .L8005E63C
/* 39A40 8005E640 00000000 */   nop
/* 39A44 8005E644 0040F809 */  jalr      $v0
/* 39A48 8005E648 00000000 */   nop
/* 39A4C 8005E64C 0801798D */  j         .L8005E634
/* 39A50 8005E650 00000000 */   nop
/* 39A54 8005E654 00000000 */  nop
/* 39A58 8005E658 00000000 */  nop
/* 39A5C 8005E65C 00000000 */  nop
