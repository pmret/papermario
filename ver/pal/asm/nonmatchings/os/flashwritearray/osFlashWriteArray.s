.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

glabel osFlashWriteArray
/* 3D4B0 800620B0 3C038009 */  lui       $v1, %hi(D_80096990)
/* 3D4B4 800620B4 8C636990 */  lw        $v1, %lo(D_80096990)($v1)
/* 3D4B8 800620B8 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 3D4BC 800620BC AFB00060 */  sw        $s0, 0x60($sp)
/* 3D4C0 800620C0 00808021 */  addu      $s0, $a0, $zero
/* 3D4C4 800620C4 24020001 */  addiu     $v0, $zero, 0x1
/* 3D4C8 800620C8 AFBF006C */  sw        $ra, 0x6C($sp)
/* 3D4CC 800620CC AFB20068 */  sw        $s2, 0x68($sp)
/* 3D4D0 800620D0 14620009 */  bne       $v1, $v0, .LPAL_800620F8
/* 3D4D4 800620D4 AFB10064 */   sw       $s1, 0x64($sp)
/* 3D4D8 800620D8 3C04800D */  lui       $a0, %hi(D_800D58B0)
/* 3D4DC 800620DC 248458B0 */  addiu     $a0, $a0, %lo(D_800D58B0)
/* 3D4E0 800620E0 3C02800D */  lui       $v0, %hi(D_800D58BC)
/* 3D4E4 800620E4 8C4258BC */  lw        $v0, %lo(D_800D58BC)($v0)
/* 3D4E8 800620E8 3C06B400 */  lui       $a2, (0xB4000000 >> 16)
/* 3D4EC 800620EC 3C050001 */  lui       $a1, (0x10000 >> 16)
/* 3D4F0 800620F0 0C018534 */  jal       osEPiWriteIo
/* 3D4F4 800620F4 00452825 */   or       $a1, $v0, $a1
.LPAL_800620F8:
/* 3D4F8 800620F8 3C04800D */  lui       $a0, %hi(D_800D58B0)
/* 3D4FC 800620FC 248458B0 */  addiu     $a0, $a0, %lo(D_800D58B0)
/* 3D500 80062100 3C06A500 */  lui       $a2, (0xA5000000 >> 16)
/* 3D504 80062104 02063025 */  or        $a2, $s0, $a2
/* 3D508 80062108 27A20040 */  addiu     $v0, $sp, 0x40
/* 3D50C 8006210C 00408821 */  addu      $s1, $v0, $zero
/* 3D510 80062110 27A20058 */  addiu     $v0, $sp, 0x58
/* 3D514 80062114 00408021 */  addu      $s0, $v0, $zero
/* 3D518 80062118 3C02800D */  lui       $v0, %hi(D_800D58BC)
/* 3D51C 8006211C 8C4258BC */  lw        $v0, %lo(D_800D58BC)($v0)
/* 3D520 80062120 00809021 */  addu      $s2, $a0, $zero
/* 3D524 80062124 3C050001 */  lui       $a1, (0x10000 >> 16)
/* 3D528 80062128 0C018534 */  jal       osEPiWriteIo
/* 3D52C 8006212C 00452825 */   or       $a1, $v0, $a1
/* 3D530 80062130 02202021 */  addu      $a0, $s1, $zero
/* 3D534 80062134 02002821 */  addu      $a1, $s0, $zero
/* 3D538 80062138 0C0198FC */  jal       osCreateMesgQueue
/* 3D53C 8006213C 24060001 */   addiu    $a2, $zero, 0x1
.LPAL_80062140:
/* 3D540 80062140 00004021 */  addu      $t0, $zero, $zero
/* 3D544 80062144 00004821 */  addu      $t1, $zero, $zero
/* 3D548 80062148 27A40020 */  addiu     $a0, $sp, 0x20
/* 3D54C 8006214C 24060000 */  addiu     $a2, $zero, 0x0
/* 3D550 80062150 2407249F */  addiu     $a3, $zero, 0x249F
/* 3D554 80062154 AFA80010 */  sw        $t0, 0x10($sp)
/* 3D558 80062158 AFA90014 */  sw        $t1, 0x14($sp)
/* 3D55C 8006215C AFB10018 */  sw        $s1, 0x18($sp)
/* 3D560 80062160 0C019C70 */  jal       osSetTimer
/* 3D564 80062164 AFB0001C */   sw       $s0, 0x1C($sp)
/* 3D568 80062168 02202021 */  addu      $a0, $s1, $zero
/* 3D56C 8006216C 02002821 */  addu      $a1, $s0, $zero
/* 3D570 80062170 0C019958 */  jal       osRecvMesg
/* 3D574 80062174 24060001 */   addiu    $a2, $zero, 0x1
/* 3D578 80062178 3C05800D */  lui       $a1, %hi(D_800D58BC)
/* 3D57C 8006217C 8CA558BC */  lw        $a1, %lo(D_800D58BC)($a1)
/* 3D580 80062180 02402021 */  addu      $a0, $s2, $zero
/* 3D584 80062184 0C01854C */  jal       osEPiReadIo
/* 3D588 80062188 27A6005C */   addiu    $a2, $sp, 0x5C
/* 3D58C 8006218C 8FA2005C */  lw        $v0, 0x5C($sp)
/* 3D590 80062190 30420001 */  andi      $v0, $v0, 0x1
/* 3D594 80062194 1440FFEA */  bnez      $v0, .LPAL_80062140
/* 3D598 80062198 02402021 */   addu     $a0, $s2, $zero
/* 3D59C 8006219C 3C05800D */  lui       $a1, %hi(D_800D58BC)
/* 3D5A0 800621A0 8CA558BC */  lw        $a1, %lo(D_800D58BC)($a1)
/* 3D5A4 800621A4 0C01854C */  jal       osEPiReadIo
/* 3D5A8 800621A8 27A6005C */   addiu    $a2, $sp, 0x5C
/* 3D5AC 800621AC 0C01B1E4 */  jal       func_PAL_8006C790
/* 3D5B0 800621B0 00000000 */   nop
/* 3D5B4 800621B4 8FA4005C */  lw        $a0, 0x5C($sp)
/* 3D5B8 800621B8 308200FF */  andi      $v0, $a0, 0xFF
/* 3D5BC 800621BC 38430004 */  xori      $v1, $v0, 0x4
/* 3D5C0 800621C0 2C630001 */  sltiu     $v1, $v1, 0x1
/* 3D5C4 800621C4 38420044 */  xori      $v0, $v0, 0x44
/* 3D5C8 800621C8 2C420001 */  sltiu     $v0, $v0, 0x1
/* 3D5CC 800621CC 00621825 */  or        $v1, $v1, $v0
/* 3D5D0 800621D0 14600005 */  bnez      $v1, .LPAL_800621E8
/* 3D5D4 800621D4 00001021 */   addu     $v0, $zero, $zero
/* 3D5D8 800621D8 30820004 */  andi      $v0, $a0, 0x4
/* 3D5DC 800621DC 14400002 */  bnez      $v0, .LPAL_800621E8
/* 3D5E0 800621E0 00001021 */   addu     $v0, $zero, $zero
/* 3D5E4 800621E4 2402FFFF */  addiu     $v0, $zero, -0x1
.LPAL_800621E8:
/* 3D5E8 800621E8 8FBF006C */  lw        $ra, 0x6C($sp)
/* 3D5EC 800621EC 8FB20068 */  lw        $s2, 0x68($sp)
/* 3D5F0 800621F0 8FB10064 */  lw        $s1, 0x64($sp)
/* 3D5F4 800621F4 8FB00060 */  lw        $s0, 0x60($sp)
/* 3D5F8 800621F8 03E00008 */  jr        $ra
/* 3D5FC 800621FC 27BD0070 */   addiu    $sp, $sp, 0x70
