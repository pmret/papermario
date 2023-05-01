.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

glabel osFlashWriteBuffer
/* 3D410 80062010 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3D414 80062014 AFB10014 */  sw        $s1, 0x14($sp)
/* 3D418 80062018 00808821 */  addu      $s1, $a0, $zero
/* 3D41C 8006201C AFB3001C */  sw        $s3, 0x1C($sp)
/* 3D420 80062020 00A09821 */  addu      $s3, $a1, $zero
/* 3D424 80062024 AFB40020 */  sw        $s4, 0x20($sp)
/* 3D428 80062028 00C0A021 */  addu      $s4, $a2, $zero
/* 3D42C 8006202C AFB20018 */  sw        $s2, 0x18($sp)
/* 3D430 80062030 00E09021 */  addu      $s2, $a3, $zero
/* 3D434 80062034 AFB00010 */  sw        $s0, 0x10($sp)
/* 3D438 80062038 3C10800D */  lui       $s0, %hi(D_800D58B0)
/* 3D43C 8006203C 261058B0 */  addiu     $s0, $s0, %lo(D_800D58B0)
/* 3D440 80062040 02002021 */  addu      $a0, $s0, $zero
/* 3D444 80062044 3C02800D */  lui       $v0, %hi(D_800D58BC)
/* 3D448 80062048 8C4258BC */  lw        $v0, %lo(D_800D58BC)($v0)
/* 3D44C 8006204C 3C06B400 */  lui       $a2, (0xB4000000 >> 16)
/* 3D450 80062050 3C050001 */  lui       $a1, (0x10000 >> 16)
/* 3D454 80062054 AFBF0024 */  sw        $ra, 0x24($sp)
/* 3D458 80062058 0C018534 */  jal       osEPiWriteIo
/* 3D45C 8006205C 00452825 */   or       $a1, $v0, $a1
/* 3D460 80062060 02002021 */  addu      $a0, $s0, $zero
/* 3D464 80062064 02202821 */  addu      $a1, $s1, $zero
/* 3D468 80062068 24060001 */  addiu     $a2, $zero, 0x1
/* 3D46C 8006206C 24020080 */  addiu     $v0, $zero, 0x80
/* 3D470 80062070 A0B30002 */  sb        $s3, 0x2($a1)
/* 3D474 80062074 ACB20004 */  sw        $s2, 0x4($a1)
/* 3D478 80062078 ACB40008 */  sw        $s4, 0x8($a1)
/* 3D47C 8006207C ACA0000C */  sw        $zero, 0xC($a1)
/* 3D480 80062080 0C018564 */  jal       osEPiStartDma
/* 3D484 80062084 ACA20010 */   sw       $v0, 0x10($a1)
/* 3D488 80062088 8FBF0024 */  lw        $ra, 0x24($sp)
/* 3D48C 8006208C 8FB40020 */  lw        $s4, 0x20($sp)
/* 3D490 80062090 8FB3001C */  lw        $s3, 0x1C($sp)
/* 3D494 80062094 8FB20018 */  lw        $s2, 0x18($sp)
/* 3D498 80062098 8FB10014 */  lw        $s1, 0x14($sp)
/* 3D49C 8006209C 8FB00010 */  lw        $s0, 0x10($sp)
/* 3D4A0 800620A0 03E00008 */  jr        $ra
/* 3D4A4 800620A4 27BD0028 */   addiu    $sp, $sp, 0x28
/* 3D4A8 800620A8 00000000 */  nop
/* 3D4AC 800620AC 00000000 */  nop
