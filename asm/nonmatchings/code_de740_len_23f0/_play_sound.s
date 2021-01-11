.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel _play_sound
/* E01B8 80149AB8 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* E01BC 80149ABC 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* E01C0 80149AC0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E01C4 80149AC4 AFBF0010 */  sw        $ra, 0x10($sp)
/* E01C8 80149AC8 80420071 */  lb        $v0, 0x71($v0)
/* E01CC 80149ACC 14400042 */  bnez      $v0, .L80149BD8
/* E01D0 80149AD0 00E0482D */   daddu    $t1, $a3, $zero
/* E01D4 80149AD4 0483003C */  bgezl     $a0, .L80149BC8
/* E01D8 80149AD8 30A500FF */   andi     $a1, $a1, 0xff
/* E01DC 80149ADC 00041702 */  srl       $v0, $a0, 0x1c
/* E01E0 80149AE0 30430007 */  andi      $v1, $v0, 7
/* E01E4 80149AE4 24020001 */  addiu     $v0, $zero, 1
/* E01E8 80149AE8 10620018 */  beq       $v1, $v0, .L80149B4C
/* E01EC 80149AEC 308800FF */   andi     $t0, $a0, 0xff
/* E01F0 80149AF0 28620002 */  slti      $v0, $v1, 2
/* E01F4 80149AF4 10400005 */  beqz      $v0, .L80149B0C
/* E01F8 80149AF8 24020002 */   addiu    $v0, $zero, 2
/* E01FC 80149AFC 10600009 */  beqz      $v1, .L80149B24
/* E0200 80149B00 00081080 */   sll      $v0, $t0, 2
/* E0204 80149B04 080526F2 */  j         .L80149BC8
/* E0208 80149B08 30A500FF */   andi     $a1, $a1, 0xff
.L80149B0C:
/* E020C 80149B0C 10620013 */  beq       $v1, $v0, .L80149B5C
/* E0210 80149B10 24020003 */   addiu    $v0, $zero, 3
/* E0214 80149B14 1062001B */  beq       $v1, $v0, .L80149B84
/* E0218 80149B18 000810C0 */   sll      $v0, $t0, 3
/* E021C 80149B1C 080526F2 */  j         .L80149BC8
/* E0220 80149B20 30A500FF */   andi     $a1, $a1, 0xff
.L80149B24:
/* E0224 80149B24 3C048015 */  lui       $a0, %hi(D_8014F2D0)
/* E0228 80149B28 00822021 */  addu      $a0, $a0, $v0
/* E022C 80149B2C 8C84F2D0 */  lw        $a0, %lo(D_8014F2D0)($a0)
/* E0230 80149B30 30A500FF */  andi      $a1, $a1, 0xff
/* E0234 80149B34 30C600FF */  andi      $a2, $a2, 0xff
/* E0238 80149B38 00073C00 */  sll       $a3, $a3, 0x10
/* E023C 80149B3C 0C052642 */  jal       func_80149908
/* E0240 80149B40 00073C03 */   sra      $a3, $a3, 0x10
/* E0244 80149B44 080526F6 */  j         .L80149BD8
/* E0248 80149B48 00000000 */   nop
.L80149B4C:
/* E024C 80149B4C 3C028015 */  lui       $v0, %hi(gCurrentDoorSoundsSet)
/* E0250 80149B50 94421340 */  lhu       $v0, %lo(gCurrentDoorSoundsSet)($v0)
/* E0254 80149B54 080526DA */  j         .L80149B68
/* E0258 80149B58 00081880 */   sll      $v1, $t0, 2
.L80149B5C:
/* E025C 80149B5C 3C028015 */  lui       $v0, %hi(D_80151308)
/* E0260 80149B60 94421308 */  lhu       $v0, %lo(D_80151308)($v0)
/* E0264 80149B64 00081880 */  sll       $v1, $t0, 2
.L80149B68:
/* E0268 80149B68 000210C0 */  sll       $v0, $v0, 3
/* E026C 80149B6C 00621821 */  addu      $v1, $v1, $v0
/* E0270 80149B70 3C048015 */  lui       $a0, %hi(D_8014F6B4)
/* E0274 80149B74 00832021 */  addu      $a0, $a0, $v1
/* E0278 80149B78 8C84F6B4 */  lw        $a0, %lo(D_8014F6B4)($a0)
/* E027C 80149B7C 080526F2 */  j         .L80149BC8
/* E0280 80149B80 30A500FF */   andi     $a1, $a1, 0xff
.L80149B84:
/* E0284 80149B84 3C038015 */  lui       $v1, %hi(D_8014F5A4)
/* E0288 80149B88 2463F5A4 */  addiu     $v1, $v1, %lo(D_8014F5A4)
/* E028C 80149B8C 00432021 */  addu      $a0, $v0, $v1
/* E0290 80149B90 84820006 */  lh        $v0, 6($a0)
/* E0294 80149B94 84830004 */  lh        $v1, 4($a0)
/* E0298 80149B98 0043102A */  slt       $v0, $v0, $v1
/* E029C 80149B9C 50400001 */  beql      $v0, $zero, .L80149BA4
/* E02A0 80149BA0 A4800006 */   sh       $zero, 6($a0)
.L80149BA4:
/* E02A4 80149BA4 94820006 */  lhu       $v0, 6($a0)
/* E02A8 80149BA8 24430001 */  addiu     $v1, $v0, 1
/* E02AC 80149BAC 00021400 */  sll       $v0, $v0, 0x10
/* E02B0 80149BB0 A4830006 */  sh        $v1, 6($a0)
/* E02B4 80149BB4 8C830000 */  lw        $v1, ($a0)
/* E02B8 80149BB8 00021383 */  sra       $v0, $v0, 0xe
/* E02BC 80149BBC 00431021 */  addu      $v0, $v0, $v1
/* E02C0 80149BC0 8C440000 */  lw        $a0, ($v0)
/* E02C4 80149BC4 30A500FF */  andi      $a1, $a1, 0xff
.L80149BC8:
/* E02C8 80149BC8 30C600FF */  andi      $a2, $a2, 0xff
/* E02CC 80149BCC 00093C00 */  sll       $a3, $t1, 0x10
/* E02D0 80149BD0 0C015490 */  jal       func_80055240
/* E02D4 80149BD4 00073C03 */   sra      $a3, $a3, 0x10
.L80149BD8:
/* E02D8 80149BD8 8FBF0010 */  lw        $ra, 0x10($sp)
/* E02DC 80149BDC 03E00008 */  jr        $ra
/* E02E0 80149BE0 27BD0018 */   addiu    $sp, $sp, 0x18
