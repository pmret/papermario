.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011BCEC
/* B23EC 8011BCEC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B23F0 8011BCF0 AFB10014 */  sw        $s1, 0x14($sp)
/* B23F4 8011BCF4 0000882D */  daddu     $s1, $zero, $zero
/* B23F8 8011BCF8 AFB50024 */  sw        $s5, 0x24($sp)
/* B23FC 8011BCFC 3C158015 */  lui       $s5, 0x8015
/* B2400 8011BD00 26B512B8 */  addiu     $s5, $s5, 0x12b8
/* B2404 8011BD04 3C02800A */  lui       $v0, 0x800a
/* B2408 8011BD08 2442A66C */  addiu     $v0, $v0, -0x5994
/* B240C 8011BD0C AFB20018 */  sw        $s2, 0x18($sp)
/* B2410 8011BD10 0040902D */  daddu     $s2, $v0, $zero
/* B2414 8011BD14 AFBF0028 */  sw        $ra, 0x28($sp)
/* B2418 8011BD18 AFB40020 */  sw        $s4, 0x20($sp)
/* B241C 8011BD1C AFB3001C */  sw        $s3, 0x1c($sp)
/* B2420 8011BD20 AFB00010 */  sw        $s0, 0x10($sp)
/* B2424 8011BD24 8E530000 */  lw        $s3, ($s2)
/* B2428 8011BD28 3C14DF00 */  lui       $s4, 0xdf00
/* B242C 8011BD2C 26620008 */  addiu     $v0, $s3, 8
/* B2430 8011BD30 AE420000 */  sw        $v0, ($s2)
/* B2434 8011BD34 3C02DE01 */  lui       $v0, 0xde01
/* B2438 8011BD38 AE620000 */  sw        $v0, ($s3)
/* B243C 8011BD3C AE600004 */  sw        $zero, 4($s3)
.L8011BD40:
/* B2440 8011BD40 8EA20000 */  lw        $v0, ($s5)
/* B2444 8011BD44 001180C0 */  sll       $s0, $s1, 3
/* B2448 8011BD48 02021021 */  addu      $v0, $s0, $v0
/* B244C 8011BD4C 8C450000 */  lw        $a1, ($v0)
/* B2450 8011BD50 10A0000D */  beqz      $a1, .L8011BD88
/* B2454 8011BD54 0220202D */   daddu    $a0, $s1, $zero
/* B2458 8011BD58 3C028015 */  lui       $v0, %hi(gCurrentModelSpecialDlsPtr)
/* B245C 8011BD5C 8C4212E8 */  lw        $v0, %lo(gCurrentModelSpecialDlsPtr)($v0)
/* B2460 8011BD60 8E430000 */  lw        $v1, ($s2)
/* B2464 8011BD64 02021021 */  addu      $v0, $s0, $v0
/* B2468 8011BD68 00A0F809 */  jalr      $a1
/* B246C 8011BD6C AC430000 */   sw       $v1, ($v0)
/* B2470 8011BD70 8E420000 */  lw        $v0, ($s2)
/* B2474 8011BD74 0040182D */  daddu     $v1, $v0, $zero
/* B2478 8011BD78 24420008 */  addiu     $v0, $v0, 8
/* B247C 8011BD7C AE420000 */  sw        $v0, ($s2)
/* B2480 8011BD80 AC740000 */  sw        $s4, ($v1)
/* B2484 8011BD84 AC600004 */  sw        $zero, 4($v1)
.L8011BD88:
/* B2488 8011BD88 8EA20000 */  lw        $v0, ($s5)
/* B248C 8011BD8C 02021021 */  addu      $v0, $s0, $v0
/* B2490 8011BD90 8C450004 */  lw        $a1, 4($v0)
/* B2494 8011BD94 50A0000F */  beql      $a1, $zero, .L8011BDD4
/* B2498 8011BD98 26310001 */   addiu    $s1, $s1, 1
/* B249C 8011BD9C 0220202D */  daddu     $a0, $s1, $zero
/* B24A0 8011BDA0 3C028015 */  lui       $v0, %hi(gCurrentModelSpecialDlsPtr)
/* B24A4 8011BDA4 8C4212E8 */  lw        $v0, %lo(gCurrentModelSpecialDlsPtr)($v0)
/* B24A8 8011BDA8 8E430000 */  lw        $v1, ($s2)
/* B24AC 8011BDAC 02021021 */  addu      $v0, $s0, $v0
/* B24B0 8011BDB0 00A0F809 */  jalr      $a1
/* B24B4 8011BDB4 AC430004 */   sw       $v1, 4($v0)
/* B24B8 8011BDB8 8E420000 */  lw        $v0, ($s2)
/* B24BC 8011BDBC 0040182D */  daddu     $v1, $v0, $zero
/* B24C0 8011BDC0 24420008 */  addiu     $v0, $v0, 8
/* B24C4 8011BDC4 AE420000 */  sw        $v0, ($s2)
/* B24C8 8011BDC8 AC740000 */  sw        $s4, ($v1)
/* B24CC 8011BDCC AC600004 */  sw        $zero, 4($v1)
/* B24D0 8011BDD0 26310001 */  addiu     $s1, $s1, 1
.L8011BDD4:
/* B24D4 8011BDD4 2A220010 */  slti      $v0, $s1, 0x10
/* B24D8 8011BDD8 1440FFD9 */  bnez      $v0, .L8011BD40
/* B24DC 8011BDDC 3C02DE01 */   lui      $v0, 0xde01
/* B24E0 8011BDE0 3C03800A */  lui       $v1, 0x800a
/* B24E4 8011BDE4 8C63A66C */  lw        $v1, -0x5994($v1)
/* B24E8 8011BDE8 AE620000 */  sw        $v0, ($s3)
/* B24EC 8011BDEC AE630004 */  sw        $v1, 4($s3)
/* B24F0 8011BDF0 8FBF0028 */  lw        $ra, 0x28($sp)
/* B24F4 8011BDF4 8FB50024 */  lw        $s5, 0x24($sp)
/* B24F8 8011BDF8 8FB40020 */  lw        $s4, 0x20($sp)
/* B24FC 8011BDFC 8FB3001C */  lw        $s3, 0x1c($sp)
/* B2500 8011BE00 8FB20018 */  lw        $s2, 0x18($sp)
/* B2504 8011BE04 8FB10014 */  lw        $s1, 0x14($sp)
/* B2508 8011BE08 8FB00010 */  lw        $s0, 0x10($sp)
/* B250C 8011BE0C 03E00008 */  jr        $ra
/* B2510 8011BE10 27BD0030 */   addiu    $sp, $sp, 0x30
