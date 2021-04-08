.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004AF18
/* 26318 8004AF18 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 2631C 8004AF1C 3C02800A */  lui       $v0, %hi(D_800A19E0)
/* 26320 8004AF20 244219E0 */  addiu     $v0, $v0, %lo(D_800A19E0)
/* 26324 8004AF24 AFBF001C */  sw        $ra, 0x1c($sp)
/* 26328 8004AF28 AFB20018 */  sw        $s2, 0x18($sp)
/* 2632C 8004AF2C AFB10014 */  sw        $s1, 0x14($sp)
/* 26330 8004AF30 AFB00010 */  sw        $s0, 0x10($sp)
/* 26334 8004AF34 8C500004 */  lw        $s0, 4($v0)
/* 26338 8004AF38 1200001A */  beqz      $s0, .L8004AFA4
/* 2633C 8004AF3C 0040902D */   daddu    $s2, $v0, $zero
.L8004AF40:
/* 26340 8004AF40 8E02000C */  lw        $v0, 0xc($s0)
/* 26344 8004AF44 3C038008 */  lui       $v1, %hi(D_8007814C)
/* 26348 8004AF48 8C63814C */  lw        $v1, %lo(D_8007814C)($v1)
/* 2634C 8004AF4C 8E110000 */  lw        $s1, ($s0)
/* 26350 8004AF50 24420001 */  addiu     $v0, $v0, 1
/* 26354 8004AF54 0043102B */  sltu      $v0, $v0, $v1
/* 26358 8004AF58 50400010 */  beql      $v0, $zero, .L8004AF9C
/* 2635C 8004AF5C 0220802D */   daddu    $s0, $s1, $zero
/* 26360 8004AF60 8E420004 */  lw        $v0, 4($s2)
/* 26364 8004AF64 50500001 */  beql      $v0, $s0, .L8004AF6C
/* 26368 8004AF68 AE510004 */   sw       $s1, 4($s2)
.L8004AF6C:
/* 2636C 8004AF6C 0C012C2F */  jal       func_8004B0BC
/* 26370 8004AF70 0200202D */   daddu    $a0, $s0, $zero
/* 26374 8004AF74 8E450008 */  lw        $a1, 8($s2)
/* 26378 8004AF78 50A00005 */  beql      $a1, $zero, .L8004AF90
/* 2637C 8004AF7C AE500008 */   sw       $s0, 8($s2)
/* 26380 8004AF80 0C012C27 */  jal       func_8004B09C
/* 26384 8004AF84 0200202D */   daddu    $a0, $s0, $zero
/* 26388 8004AF88 08012BE7 */  j         .L8004AF9C
/* 2638C 8004AF8C 0220802D */   daddu    $s0, $s1, $zero
.L8004AF90:
/* 26390 8004AF90 AE000000 */  sw        $zero, ($s0)
/* 26394 8004AF94 AE000004 */  sw        $zero, 4($s0)
/* 26398 8004AF98 0220802D */  daddu     $s0, $s1, $zero
.L8004AF9C:
/* 2639C 8004AF9C 1600FFE8 */  bnez      $s0, .L8004AF40
/* 263A0 8004AFA0 00000000 */   nop
.L8004AFA4:
/* 263A4 8004AFA4 3C038008 */  lui       $v1, %hi(D_8007814C)
/* 263A8 8004AFA8 2463814C */  addiu     $v1, $v1, %lo(D_8007814C)
/* 263AC 8004AFAC 8C620000 */  lw        $v0, ($v1)
/* 263B0 8004AFB0 3C018008 */  lui       $at, %hi(D_80078148)
/* 263B4 8004AFB4 AC208148 */  sw        $zero, %lo(D_80078148)($at)
/* 263B8 8004AFB8 24420001 */  addiu     $v0, $v0, 1
/* 263BC 8004AFBC AC620000 */  sw        $v0, ($v1)
/* 263C0 8004AFC0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 263C4 8004AFC4 8FB20018 */  lw        $s2, 0x18($sp)
/* 263C8 8004AFC8 8FB10014 */  lw        $s1, 0x14($sp)
/* 263CC 8004AFCC 8FB00010 */  lw        $s0, 0x10($sp)
/* 263D0 8004AFD0 03E00008 */  jr        $ra
/* 263D4 8004AFD4 27BD0020 */   addiu    $sp, $sp, 0x20
