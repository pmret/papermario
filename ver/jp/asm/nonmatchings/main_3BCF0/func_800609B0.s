.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800609B0
/* 3BDB0 800609B0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 3BDB4 800609B4 AFB00018 */  sw        $s0, 0x18($sp)
/* 3BDB8 800609B8 00808021 */  addu      $s0, $a0, $zero
/* 3BDBC 800609BC AFB5002C */  sw        $s5, 0x2c($sp)
/* 3BDC0 800609C0 00A0A821 */  addu      $s5, $a1, $zero
/* 3BDC4 800609C4 AFB40028 */  sw        $s4, 0x28($sp)
/* 3BDC8 800609C8 3C148009 */  lui       $s4, %hi(D_80093D30)
/* 3BDCC 800609CC 26943D30 */  addiu     $s4, $s4, %lo(D_80093D30)
/* 3BDD0 800609D0 AFBF0030 */  sw        $ra, 0x30($sp)
/* 3BDD4 800609D4 AFB30024 */  sw        $s3, 0x24($sp)
/* 3BDD8 800609D8 AFB20020 */  sw        $s2, 0x20($sp)
/* 3BDDC 800609DC AFB1001C */  sw        $s1, 0x1c($sp)
/* 3BDE0 800609E0 8E820000 */  lw        $v0, ($s4)
/* 3BDE4 800609E4 00C02821 */  addu      $a1, $a2, $zero
/* 3BDE8 800609E8 1440004C */  bnez      $v0, .L80060B1C
/* 3BDEC 800609EC 00E03021 */   addu     $a2, $a3, $zero
/* 3BDF0 800609F0 0C019554 */  jal       func_80065550
/* 3BDF4 800609F4 02A02021 */   addu     $a0, $s5, $zero
/* 3BDF8 800609F8 3C13800B */  lui       $s3, %hi(D_800AF870)
/* 3BDFC 800609FC 2673F870 */  addiu     $s3, $s3, %lo(D_800AF870)
/* 3BE00 80060A00 02602021 */  addu      $a0, $s3, $zero
/* 3BE04 80060A04 3C05800B */  lui       $a1, %hi(D_800AF888)
/* 3BE08 80060A08 24A5F888 */  addiu     $a1, $a1, %lo(D_800AF888)
/* 3BE0C 80060A0C 0C019554 */  jal       func_80065550
/* 3BE10 80060A10 24060001 */   addiu    $a2, $zero, 1
/* 3BE14 80060A14 3C028009 */  lui       $v0, %hi(D_80093D70)
/* 3BE18 80060A18 8C423D70 */  lw        $v0, %lo(D_80093D70)($v0)
/* 3BE1C 80060A1C 54400004 */  bnel      $v0, $zero, .L80060A30
/* 3BE20 80060A20 24040008 */   addiu    $a0, $zero, 8
/* 3BE24 80060A24 0C018508 */  jal       func_80061420
/* 3BE28 80060A28 00000000 */   nop
/* 3BE2C 80060A2C 24040008 */  addiu     $a0, $zero, 8
.L80060A30:
/* 3BE30 80060A30 02602821 */  addu      $a1, $s3, $zero
/* 3BE34 80060A34 3C062222 */  lui       $a2, 0x2222
/* 3BE38 80060A38 0C019648 */  jal       func_80065920
/* 3BE3C 80060A3C 34C62222 */   ori      $a2, $a2, 0x2222
/* 3BE40 80060A40 2412FFFF */  addiu     $s2, $zero, -1
/* 3BE44 80060A44 0C0197C0 */  jal       func_80065F00
/* 3BE48 80060A48 00002021 */   addu     $a0, $zero, $zero
/* 3BE4C 80060A4C 00401821 */  addu      $v1, $v0, $zero
/* 3BE50 80060A50 0070102A */  slt       $v0, $v1, $s0
/* 3BE54 80060A54 10400005 */  beqz      $v0, .L80060A6C
/* 3BE58 80060A58 00000000 */   nop
/* 3BE5C 80060A5C 00609021 */  addu      $s2, $v1, $zero
/* 3BE60 80060A60 00002021 */  addu      $a0, $zero, $zero
/* 3BE64 80060A64 0C0197C8 */  jal       func_80065F20
/* 3BE68 80060A68 02002821 */   addu     $a1, $s0, $zero
.L80060A6C:
/* 3BE6C 80060A6C 0C01ACD0 */  jal       func_8006B340
/* 3BE70 80060A70 00000000 */   nop
/* 3BE74 80060A74 3C11800B */  lui       $s1, %hi(D_800AE6C0)
/* 3BE78 80060A78 2631E6C0 */  addiu     $s1, $s1, %lo(D_800AE6C0)
/* 3BE7C 80060A7C 02202021 */  addu      $a0, $s1, $zero
/* 3BE80 80060A80 00002821 */  addu      $a1, $zero, $zero
/* 3BE84 80060A84 3C068006 */  lui       $a2, %hi(D_80061060)
/* 3BE88 80060A88 24C61060 */  addiu     $a2, $a2, %lo(D_80061060)
/* 3BE8C 80060A8C 24030001 */  addiu     $v1, $zero, 1
/* 3BE90 80060A90 AE830000 */  sw        $v1, ($s4)
/* 3BE94 80060A94 3C03800B */  lui       $v1, %hi(D_800B4360)
/* 3BE98 80060A98 24634360 */  addiu     $v1, $v1, %lo(D_800B4360)
/* 3BE9C 80060A9C 3C018009 */  lui       $at, %hi(D_80093D40)
/* 3BEA0 80060AA0 AC233D40 */  sw        $v1, %lo(D_80093D40)($at)
/* 3BEA4 80060AA4 3C038007 */  lui       $v1, %hi(D_8006B460)
/* 3BEA8 80060AA8 2463B460 */  addiu     $v1, $v1, %lo(D_8006B460)
/* 3BEAC 80060AAC 3C018009 */  lui       $at, %hi(D_80093D44)
/* 3BEB0 80060AB0 AC233D44 */  sw        $v1, %lo(D_80093D44)($at)
/* 3BEB4 80060AB4 3C038006 */  lui       $v1, %hi(func_80060B40)
/* 3BEB8 80060AB8 24630B40 */  addiu     $v1, $v1, %lo(func_80060B40)
/* 3BEBC 80060ABC 3C018009 */  lui       $at, %hi(D_80093D48)
/* 3BEC0 80060AC0 AC233D48 */  sw        $v1, %lo(D_80093D48)($at)
/* 3BEC4 80060AC4 3C03800B */  lui       $v1, %hi(D_800AF870)
/* 3BEC8 80060AC8 2463F870 */  addiu     $v1, $v1, %lo(D_800AF870)
/* 3BECC 80060ACC AFB00014 */  sw        $s0, 0x14($sp)
/* 3BED0 80060AD0 00408021 */  addu      $s0, $v0, $zero
/* 3BED4 80060AD4 02803821 */  addu      $a3, $s4, $zero
/* 3BED8 80060AD8 3C018009 */  lui       $at, %hi(D_80093D34)
/* 3BEDC 80060ADC AC313D34 */  sw        $s1, %lo(D_80093D34)($at)
/* 3BEE0 80060AE0 3C018009 */  lui       $at, %hi(D_80093D38)
/* 3BEE4 80060AE4 AC353D38 */  sw        $s5, %lo(D_80093D38)($at)
/* 3BEE8 80060AE8 3C018009 */  lui       $at, %hi(D_80093D3C)
/* 3BEEC 80060AEC AC333D3C */  sw        $s3, %lo(D_80093D3C)($at)
/* 3BEF0 80060AF0 0C01978C */  jal       func_80065E30
/* 3BEF4 80060AF4 AFA30010 */   sw       $v1, 0x10($sp)
/* 3BEF8 80060AF8 0C0197FC */  jal       func_80065FF0
/* 3BEFC 80060AFC 02202021 */   addu     $a0, $s1, $zero
/* 3BF00 80060B00 0C01ACEC */  jal       func_8006B3B0
/* 3BF04 80060B04 02002021 */   addu     $a0, $s0, $zero
/* 3BF08 80060B08 2402FFFF */  addiu     $v0, $zero, -1
/* 3BF0C 80060B0C 12420003 */  beq       $s2, $v0, .L80060B1C
/* 3BF10 80060B10 00002021 */   addu     $a0, $zero, $zero
/* 3BF14 80060B14 0C0197C8 */  jal       func_80065F20
/* 3BF18 80060B18 02402821 */   addu     $a1, $s2, $zero
.L80060B1C:
/* 3BF1C 80060B1C 8FBF0030 */  lw        $ra, 0x30($sp)
/* 3BF20 80060B20 8FB5002C */  lw        $s5, 0x2c($sp)
/* 3BF24 80060B24 8FB40028 */  lw        $s4, 0x28($sp)
/* 3BF28 80060B28 8FB30024 */  lw        $s3, 0x24($sp)
/* 3BF2C 80060B2C 8FB20020 */  lw        $s2, 0x20($sp)
/* 3BF30 80060B30 8FB1001C */  lw        $s1, 0x1c($sp)
/* 3BF34 80060B34 8FB00018 */  lw        $s0, 0x18($sp)
/* 3BF38 80060B38 03E00008 */  jr        $ra
/* 3BF3C 80060B3C 27BD0038 */   addiu    $sp, $sp, 0x38
