.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

glabel osFlashReadArray
/* 3D600 80062200 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 3D604 80062204 AFB40028 */  sw        $s4, 0x28($sp)
/* 3D608 80062208 8FB40048 */  lw        $s4, 0x48($sp)
/* 3D60C 8006220C 3C02800D */  lui       $v0, %hi(D_800D58BC)
/* 3D610 80062210 8C4258BC */  lw        $v0, %lo(D_800D58BC)($v0)
/* 3D614 80062214 AFB20020 */  sw        $s2, 0x20($sp)
/* 3D618 80062218 00809021 */  addu      $s2, $a0, $zero
/* 3D61C 8006221C AFB00018 */  sw        $s0, 0x18($sp)
/* 3D620 80062220 00A08021 */  addu      $s0, $a1, $zero
/* 3D624 80062224 AFB30024 */  sw        $s3, 0x24($sp)
/* 3D628 80062228 00C09821 */  addu      $s3, $a2, $zero
/* 3D62C 8006222C AFB1001C */  sw        $s1, 0x1C($sp)
/* 3D630 80062230 00E08821 */  addu      $s1, $a3, $zero
/* 3D634 80062234 AFB5002C */  sw        $s5, 0x2C($sp)
/* 3D638 80062238 3C15800D */  lui       $s5, %hi(D_800D58B0)
/* 3D63C 8006223C 26B558B0 */  addiu     $s5, $s5, %lo(D_800D58B0)
/* 3D640 80062240 02A02021 */  addu      $a0, $s5, $zero
/* 3D644 80062244 AFB60030 */  sw        $s6, 0x30($sp)
/* 3D648 80062248 8FB6004C */  lw        $s6, 0x4C($sp)
/* 3D64C 8006224C 3C06F000 */  lui       $a2, (0xF0000000 >> 16)
/* 3D650 80062250 3C050001 */  lui       $a1, (0x10000 >> 16)
/* 3D654 80062254 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3D658 80062258 0C018534 */  jal       osEPiWriteIo
/* 3D65C 8006225C 00452825 */   or       $a1, $v0, $a1
/* 3D660 80062260 3C05800D */  lui       $a1, %hi(D_800D58BC)
/* 3D664 80062264 8CA558BC */  lw        $a1, %lo(D_800D58BC)($a1)
/* 3D668 80062268 02A02021 */  addu      $a0, $s5, $zero
/* 3D66C 8006226C 0C01854C */  jal       osEPiReadIo
/* 3D670 80062270 27A60010 */   addiu    $a2, $sp, 0x10
/* 3D674 80062274 02741021 */  addu      $v0, $s3, $s4
/* 3D678 80062278 2442FFFF */  addiu     $v0, $v0, -0x1
/* 3D67C 8006227C 30420F00 */  andi      $v0, $v0, 0xF00
/* 3D680 80062280 32630F00 */  andi      $v1, $s3, 0xF00
/* 3D684 80062284 A2500002 */  sb        $s0, 0x2($s2)
/* 3D688 80062288 AE560004 */  sw        $s6, 0x4($s2)
/* 3D68C 8006228C 10430018 */  beq       $v0, $v1, .LPAL_800622F0
/* 3D690 80062290 AE510008 */   sw       $s1, 0x8($s2)
/* 3D694 80062294 326300FF */  andi      $v1, $s3, 0xFF
/* 3D698 80062298 24020100 */  addiu     $v0, $zero, 0x100
/* 3D69C 8006229C 00431023 */  subu      $v0, $v0, $v1
/* 3D6A0 800622A0 0282A023 */  subu      $s4, $s4, $v0
/* 3D6A4 800622A4 02602021 */  addu      $a0, $s3, $zero
/* 3D6A8 800622A8 000211C0 */  sll       $v0, $v0, 7
/* 3D6AC 800622AC 0C01B1B4 */  jal       func_PAL_8006C6D0
/* 3D6B0 800622B0 AE420010 */   sw       $v0, 0x10($s2)
/* 3D6B4 800622B4 02A02021 */  addu      $a0, $s5, $zero
/* 3D6B8 800622B8 02402821 */  addu      $a1, $s2, $zero
/* 3D6BC 800622BC 00003021 */  addu      $a2, $zero, $zero
/* 3D6C0 800622C0 0C018564 */  jal       osEPiStartDma
/* 3D6C4 800622C4 AE42000C */   sw       $v0, 0xC($s2)
/* 3D6C8 800622C8 02C02021 */  addu      $a0, $s6, $zero
/* 3D6CC 800622CC 00002821 */  addu      $a1, $zero, $zero
/* 3D6D0 800622D0 0C019958 */  jal       osRecvMesg
/* 3D6D4 800622D4 24060001 */   addiu    $a2, $zero, 0x1
/* 3D6D8 800622D8 8E430008 */  lw        $v1, 0x8($s2)
/* 3D6DC 800622DC 8E440010 */  lw        $a0, 0x10($s2)
/* 3D6E0 800622E0 26620100 */  addiu     $v0, $s3, 0x100
/* 3D6E4 800622E4 30530F00 */  andi      $s3, $v0, 0xF00
/* 3D6E8 800622E8 00641821 */  addu      $v1, $v1, $a0
/* 3D6EC 800622EC AE430008 */  sw        $v1, 0x8($s2)
.LPAL_800622F0:
/* 3D6F0 800622F0 2E820101 */  sltiu     $v0, $s4, 0x101
/* 3D6F4 800622F4 14400018 */  bnez      $v0, .LPAL_80062358
/* 3D6F8 800622F8 02602021 */   addu     $a0, $s3, $zero
/* 3D6FC 800622FC 34108000 */  ori       $s0, $zero, 0x8000
.LPAL_80062300:
/* 3D700 80062300 2694FF00 */  addiu     $s4, $s4, -0x100
/* 3D704 80062304 02602021 */  addu      $a0, $s3, $zero
/* 3D708 80062308 0C01B1B4 */  jal       func_PAL_8006C6D0
/* 3D70C 8006230C AE500010 */   sw       $s0, 0x10($s2)
/* 3D710 80062310 3C04800D */  lui       $a0, %hi(D_800D58B0)
/* 3D714 80062314 248458B0 */  addiu     $a0, $a0, %lo(D_800D58B0)
/* 3D718 80062318 02402821 */  addu      $a1, $s2, $zero
/* 3D71C 8006231C 00003021 */  addu      $a2, $zero, $zero
/* 3D720 80062320 0C018564 */  jal       osEPiStartDma
/* 3D724 80062324 AE42000C */   sw       $v0, 0xC($s2)
/* 3D728 80062328 02C02021 */  addu      $a0, $s6, $zero
/* 3D72C 8006232C 00002821 */  addu      $a1, $zero, $zero
/* 3D730 80062330 0C019958 */  jal       osRecvMesg
/* 3D734 80062334 24060001 */   addiu    $a2, $zero, 0x1
/* 3D738 80062338 8E420008 */  lw        $v0, 0x8($s2)
/* 3D73C 8006233C 8E430010 */  lw        $v1, 0x10($s2)
/* 3D740 80062340 00431021 */  addu      $v0, $v0, $v1
/* 3D744 80062344 AE420008 */  sw        $v0, 0x8($s2)
/* 3D748 80062348 2E820101 */  sltiu     $v0, $s4, 0x101
/* 3D74C 8006234C 1040FFEC */  beqz      $v0, .LPAL_80062300
/* 3D750 80062350 26730100 */   addiu    $s3, $s3, 0x100
/* 3D754 80062354 02602021 */  addu      $a0, $s3, $zero
.LPAL_80062358:
/* 3D758 80062358 001411C0 */  sll       $v0, $s4, 7
/* 3D75C 8006235C 0C01B1B4 */  jal       func_PAL_8006C6D0
/* 3D760 80062360 AE420010 */   sw       $v0, 0x10($s2)
/* 3D764 80062364 3C04800D */  lui       $a0, %hi(D_800D58B0)
/* 3D768 80062368 248458B0 */  addiu     $a0, $a0, %lo(D_800D58B0)
/* 3D76C 8006236C 02402821 */  addu      $a1, $s2, $zero
/* 3D770 80062370 00003021 */  addu      $a2, $zero, $zero
/* 3D774 80062374 0C018564 */  jal       osEPiStartDma
/* 3D778 80062378 ACA2000C */   sw       $v0, 0xC($a1)
/* 3D77C 8006237C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3D780 80062380 8FB60030 */  lw        $s6, 0x30($sp)
/* 3D784 80062384 8FB5002C */  lw        $s5, 0x2C($sp)
/* 3D788 80062388 8FB40028 */  lw        $s4, 0x28($sp)
/* 3D78C 8006238C 8FB30024 */  lw        $s3, 0x24($sp)
/* 3D790 80062390 8FB20020 */  lw        $s2, 0x20($sp)
/* 3D794 80062394 8FB1001C */  lw        $s1, 0x1C($sp)
/* 3D798 80062398 8FB00018 */  lw        $s0, 0x18($sp)
/* 3D79C 8006239C 03E00008 */  jr        $ra
/* 3D7A0 800623A0 27BD0038 */   addiu    $sp, $sp, 0x38
/* 3D7A4 800623A4 00000000 */  nop
/* 3D7A8 800623A8 00000000 */  nop
/* 3D7AC 800623AC 00000000 */  nop