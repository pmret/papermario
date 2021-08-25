.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80245D38_A99478
.double 180.0

glabel D_80245D40_A99480
.double 75.0

glabel D_80245D48_A99488
.double 90.0

glabel D_80245D50_A99490
.double 70.0

.section .text

glabel func_80241D30_A95470
/* A95470 80241D30 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A95474 80241D34 AFB00018 */  sw        $s0, 0x18($sp)
/* A95478 80241D38 AFBF0024 */  sw        $ra, 0x24($sp)
/* A9547C 80241D3C AFB20020 */  sw        $s2, 0x20($sp)
/* A95480 80241D40 AFB1001C */  sw        $s1, 0x1c($sp)
/* A95484 80241D44 F7B60030 */  sdc1      $f22, 0x30($sp)
/* A95488 80241D48 F7B40028 */  sdc1      $f20, 0x28($sp)
/* A9548C 80241D4C 8C920148 */  lw        $s2, 0x148($a0)
/* A95490 80241D50 4485A000 */  mtc1      $a1, $f20
/* A95494 80241D54 86440008 */  lh        $a0, 8($s2)
/* A95498 80241D58 4486B000 */  mtc1      $a2, $f22
/* A9549C 80241D5C 0C00EABB */  jal       get_npc_unsafe
/* A954A0 80241D60 00E0802D */   daddu    $s0, $a3, $zero
/* A954A4 80241D64 0200202D */  daddu     $a0, $s0, $zero
/* A954A8 80241D68 0040882D */  daddu     $s1, $v0, $zero
/* A954AC 80241D6C 4406A000 */  mfc1      $a2, $f20
/* A954B0 80241D70 4407B000 */  mfc1      $a3, $f22
/* A954B4 80241D74 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* A954B8 80241D78 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* A954BC 80241D7C 3C05800B */  lui       $a1, %hi(gCameras)
/* A954C0 80241D80 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* A954C4 80241D84 AFA00010 */  sw        $zero, 0x10($sp)
/* A954C8 80241D88 00031080 */  sll       $v0, $v1, 2
/* A954CC 80241D8C 00431021 */  addu      $v0, $v0, $v1
/* A954D0 80241D90 00021080 */  sll       $v0, $v0, 2
/* A954D4 80241D94 00431023 */  subu      $v0, $v0, $v1
/* A954D8 80241D98 000218C0 */  sll       $v1, $v0, 3
/* A954DC 80241D9C 00431021 */  addu      $v0, $v0, $v1
/* A954E0 80241DA0 000210C0 */  sll       $v0, $v0, 3
/* A954E4 80241DA4 00458021 */  addu      $s0, $v0, $a1
/* A954E8 80241DA8 0C01242D */  jal       func_800490B4
/* A954EC 80241DAC 0240282D */   daddu    $a1, $s2, $zero
/* A954F0 80241DB0 1040004B */  beqz      $v0, .L80241EE0
/* A954F4 80241DB4 2402FFFF */   addiu    $v0, $zero, -1
/* A954F8 80241DB8 C60C006C */  lwc1      $f12, 0x6c($s0)
/* A954FC 80241DBC C62E000C */  lwc1      $f14, 0xc($s1)
/* A95500 80241DC0 3C014387 */  lui       $at, 0x4387
/* A95504 80241DC4 4481A000 */  mtc1      $at, $f20
/* A95508 80241DC8 0C00A70A */  jal       get_clamped_angle_diff
/* A9550C 80241DCC 00000000 */   nop
/* A95510 80241DD0 0C00A6C9 */  jal       clamp_angle
/* A95514 80241DD4 46000306 */   mov.s    $f12, $f0
/* A95518 80241DD8 3C018024 */  lui       $at, %hi(D_80245D38_A99478)
/* A9551C 80241DDC D4225D38 */  ldc1      $f2, %lo(D_80245D38_A99478)($at)
/* A95520 80241DE0 46000021 */  cvt.d.s   $f0, $f0
/* A95524 80241DE4 4622003C */  c.lt.d    $f0, $f2
/* A95528 80241DE8 00000000 */  nop
/* A9552C 80241DEC 45000003 */  bc1f      .L80241DFC
/* A95530 80241DF0 00000000 */   nop
/* A95534 80241DF4 3C0142B4 */  lui       $at, 0x42b4
/* A95538 80241DF8 4481A000 */  mtc1      $at, $f20
.L80241DFC:
/* A9553C 80241DFC 3C10800F */  lui       $s0, %hi(gPlayerStatusPtr)
/* A95540 80241E00 26107B30 */  addiu     $s0, $s0, %lo(gPlayerStatusPtr)
/* A95544 80241E04 C62C0038 */  lwc1      $f12, 0x38($s1)
/* A95548 80241E08 8E020000 */  lw        $v0, ($s0)
/* A9554C 80241E0C C62E0040 */  lwc1      $f14, 0x40($s1)
/* A95550 80241E10 8C460028 */  lw        $a2, 0x28($v0)
/* A95554 80241E14 0C00A720 */  jal       atan2
/* A95558 80241E18 8C470030 */   lw       $a3, 0x30($v0)
/* A9555C 80241E1C 4600A306 */  mov.s     $f12, $f20
/* A95560 80241E20 0C00A70A */  jal       get_clamped_angle_diff
/* A95564 80241E24 46000386 */   mov.s    $f14, $f0
/* A95568 80241E28 46000005 */  abs.s     $f0, $f0
/* A9556C 80241E2C 3C018024 */  lui       $at, %hi(D_80245D40_A99480)
/* A95570 80241E30 D4225D40 */  ldc1      $f2, %lo(D_80245D40_A99480)($at)
/* A95574 80241E34 46000021 */  cvt.d.s   $f0, $f0
/* A95578 80241E38 4620103C */  c.lt.d    $f2, $f0
/* A9557C 80241E3C 00000000 */  nop
/* A95580 80241E40 45010027 */  bc1t      .L80241EE0
/* A95584 80241E44 2402FFFF */   addiu    $v0, $zero, -1
/* A95588 80241E48 8E020000 */  lw        $v0, ($s0)
/* A9558C 80241E4C C6200038 */  lwc1      $f0, 0x38($s1)
/* A95590 80241E50 C4420028 */  lwc1      $f2, 0x28($v0)
/* A95594 80241E54 44806000 */  mtc1      $zero, $f12
/* A95598 80241E58 46020001 */  sub.s     $f0, $f0, $f2
/* A9559C 80241E5C C62E003C */  lwc1      $f14, 0x3c($s1)
/* A955A0 80241E60 8C47002C */  lw        $a3, 0x2c($v0)
/* A955A4 80241E64 46000005 */  abs.s     $f0, $f0
/* A955A8 80241E68 44060000 */  mfc1      $a2, $f0
/* A955AC 80241E6C 0C00A720 */  jal       atan2
/* A955B0 80241E70 00000000 */   nop
/* A955B4 80241E74 3C018024 */  lui       $at, %hi(D_80245D48_A99488)
/* A955B8 80241E78 D4225D48 */  ldc1      $f2, %lo(D_80245D48_A99488)($at)
/* A955BC 80241E7C 46000021 */  cvt.d.s   $f0, $f0
/* A955C0 80241E80 46220001 */  sub.d     $f0, $f0, $f2
/* A955C4 80241E84 3C018024 */  lui       $at, %hi(D_80245D50_A99490)
/* A955C8 80241E88 D4225D50 */  ldc1      $f2, %lo(D_80245D50_A99490)($at)
/* A955CC 80241E8C 46200020 */  cvt.s.d   $f0, $f0
/* A955D0 80241E90 46000005 */  abs.s     $f0, $f0
/* A955D4 80241E94 46000021 */  cvt.d.s   $f0, $f0
/* A955D8 80241E98 4620103C */  c.lt.d    $f2, $f0
/* A955DC 80241E9C 00000000 */  nop
/* A955E0 80241EA0 4501000F */  bc1t      .L80241EE0
/* A955E4 80241EA4 2402FFFF */   addiu    $v0, $zero, -1
/* A955E8 80241EA8 3C038011 */  lui       $v1, %hi(gPartnerActionStatus+0x3)
/* A955EC 80241EAC 8063EBB3 */  lb        $v1, %lo(gPartnerActionStatus+0x3)($v1)
/* A955F0 80241EB0 24020009 */  addiu     $v0, $zero, 9
/* A955F4 80241EB4 10620009 */  beq       $v1, $v0, .L80241EDC
/* A955F8 80241EB8 24020007 */   addiu    $v0, $zero, 7
/* A955FC 80241EBC 50620008 */  beql      $v1, $v0, .L80241EE0
/* A95600 80241EC0 2402FFFF */   addiu    $v0, $zero, -1
/* A95604 80241EC4 86440008 */  lh        $a0, 8($s2)
/* A95608 80241EC8 0C00FB3A */  jal       get_enemy
/* A9560C 80241ECC 24840001 */   addiu    $a0, $a0, 1
/* A95610 80241ED0 8C43006C */  lw        $v1, 0x6c($v0)
/* A95614 80241ED4 10600002 */  beqz      $v1, .L80241EE0
/* A95618 80241ED8 24020001 */   addiu    $v0, $zero, 1
.L80241EDC:
/* A9561C 80241EDC 2402FFFF */  addiu     $v0, $zero, -1
.L80241EE0:
/* A95620 80241EE0 8FBF0024 */  lw        $ra, 0x24($sp)
/* A95624 80241EE4 8FB20020 */  lw        $s2, 0x20($sp)
/* A95628 80241EE8 8FB1001C */  lw        $s1, 0x1c($sp)
/* A9562C 80241EEC 8FB00018 */  lw        $s0, 0x18($sp)
/* A95630 80241EF0 D7B60030 */  ldc1      $f22, 0x30($sp)
/* A95634 80241EF4 D7B40028 */  ldc1      $f20, 0x28($sp)
/* A95638 80241EF8 03E00008 */  jr        $ra
/* A9563C 80241EFC 27BD0038 */   addiu    $sp, $sp, 0x38
