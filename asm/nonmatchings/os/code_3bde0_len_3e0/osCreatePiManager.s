.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osCreatePiManager
/* 3BDE0 800609E0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 3BDE4 800609E4 AFB00018 */  sw        $s0, 0x18($sp)
/* 3BDE8 800609E8 00808021 */  addu      $s0, $a0, $zero
/* 3BDEC 800609EC AFB5002C */  sw        $s5, 0x2c($sp)
/* 3BDF0 800609F0 00A0A821 */  addu      $s5, $a1, $zero
/* 3BDF4 800609F4 AFB40028 */  sw        $s4, 0x28($sp)
/* 3BDF8 800609F8 3C148009 */  lui       $s4, 0x8009
/* 3BDFC 800609FC 26943D50 */  addiu     $s4, $s4, 0x3d50
/* 3BE00 80060A00 AFBF0030 */  sw        $ra, 0x30($sp)
/* 3BE04 80060A04 AFB30024 */  sw        $s3, 0x24($sp)
/* 3BE08 80060A08 AFB20020 */  sw        $s2, 0x20($sp)
/* 3BE0C 80060A0C AFB1001C */  sw        $s1, 0x1c($sp)
/* 3BE10 80060A10 8E820000 */  lw        $v0, ($s4)
/* 3BE14 80060A14 00C02821 */  addu      $a1, $a2, $zero
/* 3BE18 80060A18 1440004C */  bnez      $v0, .L80060B4C
/* 3BE1C 80060A1C 00E03021 */   addu     $a2, $a3, $zero
/* 3BE20 80060A20 0C019560 */  jal       osCreateMesgQueue
/* 3BE24 80060A24 02A02021 */   addu     $a0, $s5, $zero
/* 3BE28 80060A28 3C13800B */  lui       $s3, 0x800b
/* 3BE2C 80060A2C 2673F890 */  addiu     $s3, $s3, -0x770
/* 3BE30 80060A30 02602021 */  addu      $a0, $s3, $zero
/* 3BE34 80060A34 3C05800B */  lui       $a1, 0x800b
/* 3BE38 80060A38 24A5F8A8 */  addiu     $a1, $a1, -0x758
/* 3BE3C 80060A3C 0C019560 */  jal       osCreateMesgQueue
/* 3BE40 80060A40 24060001 */   addiu    $a2, $zero, 1
/* 3BE44 80060A44 3C028009 */  lui       $v0, 0x8009
/* 3BE48 80060A48 8C423D90 */  lw        $v0, 0x3d90($v0)
/* 3BE4C 80060A4C 54400004 */  bnel      $v0, $zero, .L80060A60
/* 3BE50 80060A50 24040008 */   addiu    $a0, $zero, 8
/* 3BE54 80060A54 0C018514 */  jal       osPiCreateAccessQueue
/* 3BE58 80060A58 00000000 */   nop      
/* 3BE5C 80060A5C 24040008 */  addiu     $a0, $zero, 8
.L80060A60:
/* 3BE60 80060A60 02602821 */  addu      $a1, $s3, $zero
/* 3BE64 80060A64 3C062222 */  lui       $a2, 0x2222
/* 3BE68 80060A68 0C019654 */  jal       osSetEventMesg
/* 3BE6C 80060A6C 34C62222 */   ori      $a2, $a2, 0x2222
/* 3BE70 80060A70 2412FFFF */  addiu     $s2, $zero, -1
/* 3BE74 80060A74 0C0197CC */  jal       osGetThreadPri
/* 3BE78 80060A78 00002021 */   addu     $a0, $zero, $zero
/* 3BE7C 80060A7C 00401821 */  addu      $v1, $v0, $zero
/* 3BE80 80060A80 0070102A */  slt       $v0, $v1, $s0
/* 3BE84 80060A84 10400005 */  beqz      $v0, .L80060A9C
/* 3BE88 80060A88 00000000 */   nop      
/* 3BE8C 80060A8C 00609021 */  addu      $s2, $v1, $zero
/* 3BE90 80060A90 00002021 */  addu      $a0, $zero, $zero
/* 3BE94 80060A94 0C0197D4 */  jal       osSetThreadPri
/* 3BE98 80060A98 02002821 */   addu     $a1, $s0, $zero
.L80060A9C:
/* 3BE9C 80060A9C 0C01ACD8 */  jal       __osDisableInt
/* 3BEA0 80060AA0 00000000 */   nop      
/* 3BEA4 80060AA4 3C11800B */  lui       $s1, 0x800b
/* 3BEA8 80060AA8 2631E6E0 */  addiu     $s1, $s1, -0x1920
/* 3BEAC 80060AAC 02202021 */  addu      $a0, $s1, $zero
/* 3BEB0 80060AB0 00002821 */  addu      $a1, $zero, $zero
/* 3BEB4 80060AB4 3C068006 */  lui       $a2, 0x8006
/* 3BEB8 80060AB8 24C61090 */  addiu     $a2, $a2, 0x1090
/* 3BEBC 80060ABC 24030001 */  addiu     $v1, $zero, 1
/* 3BEC0 80060AC0 AE830000 */  sw        $v1, ($s4)
/* 3BEC4 80060AC4 3C03800B */  lui       $v1, 0x800b
/* 3BEC8 80060AC8 24634380 */  addiu     $v1, $v1, 0x4380
/* 3BECC 80060ACC 3C018009 */  lui       $at, 0x8009
/* 3BED0 80060AD0 AC233D60 */  sw        $v1, 0x3d60($at)
/* 3BED4 80060AD4 3C038007 */  lui       $v1, 0x8007
/* 3BED8 80060AD8 2463B480 */  addiu     $v1, $v1, -0x4b80
/* 3BEDC 80060ADC 3C018009 */  lui       $at, 0x8009
/* 3BEE0 80060AE0 AC233D64 */  sw        $v1, 0x3d64($at)
/* 3BEE4 80060AE4 3C038006 */  lui       $v1, 0x8006
/* 3BEE8 80060AE8 24630B70 */  addiu     $v1, $v1, 0xb70
/* 3BEEC 80060AEC 3C018009 */  lui       $at, 0x8009
/* 3BEF0 80060AF0 AC233D68 */  sw        $v1, 0x3d68($at)
/* 3BEF4 80060AF4 3C03800B */  lui       $v1, 0x800b
/* 3BEF8 80060AF8 2463F890 */  addiu     $v1, $v1, -0x770
/* 3BEFC 80060AFC AFB00014 */  sw        $s0, 0x14($sp)
/* 3BF00 80060B00 00408021 */  addu      $s0, $v0, $zero
/* 3BF04 80060B04 02803821 */  addu      $a3, $s4, $zero
/* 3BF08 80060B08 3C018009 */  lui       $at, 0x8009
/* 3BF0C 80060B0C AC313D54 */  sw        $s1, 0x3d54($at)
/* 3BF10 80060B10 3C018009 */  lui       $at, 0x8009
/* 3BF14 80060B14 AC353D58 */  sw        $s5, 0x3d58($at)
/* 3BF18 80060B18 3C018009 */  lui       $at, 0x8009
/* 3BF1C 80060B1C AC333D5C */  sw        $s3, 0x3d5c($at)
/* 3BF20 80060B20 0C019798 */  jal       osCreateThread
/* 3BF24 80060B24 AFA30010 */   sw       $v1, 0x10($sp)
/* 3BF28 80060B28 0C019808 */  jal       osStartThread
/* 3BF2C 80060B2C 02202021 */   addu     $a0, $s1, $zero
/* 3BF30 80060B30 0C01ACF4 */  jal       __osRestoreInt
/* 3BF34 80060B34 02002021 */   addu     $a0, $s0, $zero
/* 3BF38 80060B38 2402FFFF */  addiu     $v0, $zero, -1
/* 3BF3C 80060B3C 12420003 */  beq       $s2, $v0, .L80060B4C
/* 3BF40 80060B40 00002021 */   addu     $a0, $zero, $zero
/* 3BF44 80060B44 0C0197D4 */  jal       osSetThreadPri
/* 3BF48 80060B48 02402821 */   addu     $a1, $s2, $zero
.L80060B4C:
/* 3BF4C 80060B4C 8FBF0030 */  lw        $ra, 0x30($sp)
/* 3BF50 80060B50 8FB5002C */  lw        $s5, 0x2c($sp)
/* 3BF54 80060B54 8FB40028 */  lw        $s4, 0x28($sp)
/* 3BF58 80060B58 8FB30024 */  lw        $s3, 0x24($sp)
/* 3BF5C 80060B5C 8FB20020 */  lw        $s2, 0x20($sp)
/* 3BF60 80060B60 8FB1001C */  lw        $s1, 0x1c($sp)
/* 3BF64 80060B64 8FB00018 */  lw        $s0, 0x18($sp)
/* 3BF68 80060B68 03E00008 */  jr        $ra
/* 3BF6C 80060B6C 27BD0038 */   addiu    $sp, $sp, 0x38
