.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053270
/* 2E670 80053270 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 2E674 80053274 AFB10014 */  sw        $s1, 0x14($sp)
/* 2E678 80053278 3C11800A */  lui       $s1, %hi(D_8009A5A0)
/* 2E67C 8005327C 8E31A5A0 */  lw        $s1, %lo(D_8009A5A0)($s1)
/* 2E680 80053280 AFB00010 */  sw        $s0, 0x10($sp)
/* 2E684 80053284 3C10800A */  lui       $s0, %hi(D_8009A644)
/* 2E688 80053288 8E10A644 */  lw        $s0, %lo(D_8009A644)($s0)
/* 2E68C 8005328C AFBF001C */  sw        $ra, 0x1c($sp)
/* 2E690 80053290 AFB20018 */  sw        $s2, 0x18($sp)
/* 2E694 80053294 8E22009C */  lw        $v0, 0x9c($s1)
/* 2E698 80053298 3C12800A */  lui       $s2, %hi(D_8009A620)
/* 2E69C 8005329C 8E52A620 */  lw        $s2, %lo(D_8009A620)($s2)
/* 2E6A0 800532A0 10400003 */  beqz      $v0, .L800532B0
/* 2E6A4 800532A4 00000000 */   nop
/* 2E6A8 800532A8 0C01576F */  jal       func_80055DBC
/* 2E6AC 800532AC 00000000 */   nop
.L800532B0:
/* 2E6B0 800532B0 8E2200A4 */  lw        $v0, 0xa4($s1)
/* 2E6B4 800532B4 3C01800A */  lui       $at, %hi(D_8009A5C8)
/* 2E6B8 800532B8 AC22A5C8 */  sw        $v0, %lo(D_8009A5C8)($at)
/* 2E6BC 800532BC 10400003 */  beqz      $v0, .L800532CC
/* 2E6C0 800532C0 00000000 */   nop
/* 2E6C4 800532C4 0040F809 */  jalr      $v0
/* 2E6C8 800532C8 00000000 */   nop
.L800532CC:
/* 2E6CC 800532CC 0C013470 */  jal       func_8004D1C0
/* 2E6D0 800532D0 0200202D */   daddu    $a0, $s0, $zero
/* 2E6D4 800532D4 3C04800A */  lui       $a0, %hi(D_8009A5DC)
/* 2E6D8 800532D8 8C84A5DC */  lw        $a0, %lo(D_8009A5DC)($a0)
/* 2E6DC 800532DC 0C013470 */  jal       func_8004D1C0
/* 2E6E0 800532E0 00000000 */   nop
/* 2E6E4 800532E4 0C012CFE */  jal       func_8004B3F8
/* 2E6E8 800532E8 0240202D */   daddu    $a0, $s2, $zero
/* 2E6EC 800532EC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 2E6F0 800532F0 8FB20018 */  lw        $s2, 0x18($sp)
/* 2E6F4 800532F4 8FB10014 */  lw        $s1, 0x14($sp)
/* 2E6F8 800532F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 2E6FC 800532FC 03E00008 */  jr        $ra
/* 2E700 80053300 27BD0020 */   addiu    $sp, $sp, 0x20
