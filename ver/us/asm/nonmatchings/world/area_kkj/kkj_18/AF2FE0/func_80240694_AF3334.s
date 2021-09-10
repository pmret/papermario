.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240694_AF3334
/* AF3334 80240694 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AF3338 80240698 AFBF0010 */  sw        $ra, 0x10($sp)
/* AF333C 8024069C 8C82000C */  lw        $v0, 0xc($a0)
/* AF3340 802406A0 0C0B1EAF */  jal       evt_get_variable
/* AF3344 802406A4 8C450000 */   lw       $a1, ($v0)
/* AF3348 802406A8 0040182D */  daddu     $v1, $v0, $zero
/* AF334C 802406AC 10600012 */  beqz      $v1, .L802406F8
/* AF3350 802406B0 0000202D */   daddu    $a0, $zero, $zero
/* AF3354 802406B4 8C620000 */  lw        $v0, ($v1)
/* AF3358 802406B8 5040000A */  beql      $v0, $zero, .L802406E4
/* AF335C 802406BC 00041080 */   sll      $v0, $a0, 2
/* AF3360 802406C0 3C058024 */  lui       $a1, %hi(D_80244E78_A1B098)
/* AF3364 802406C4 24A54E78 */  addiu     $a1, $a1, %lo(D_80244E78_A1B098)
.L802406C8:
/* AF3368 802406C8 24630004 */  addiu     $v1, $v1, 4
/* AF336C 802406CC 24840001 */  addiu     $a0, $a0, 1
/* AF3370 802406D0 ACA20000 */  sw        $v0, ($a1)
/* AF3374 802406D4 8C620000 */  lw        $v0, ($v1)
/* AF3378 802406D8 1440FFFB */  bnez      $v0, .L802406C8
/* AF337C 802406DC 24A50004 */   addiu    $a1, $a1, 4
/* AF3380 802406E0 00041080 */  sll       $v0, $a0, 2
.L802406E4:
/* AF3384 802406E4 3C018024 */  lui       $at, %hi(D_80244E78_A1B098)
/* AF3388 802406E8 00220821 */  addu      $at, $at, $v0
/* AF338C 802406EC AC204E78 */  sw        $zero, %lo(D_80244E78_A1B098)($at)
/* AF3390 802406F0 080901C8 */  j         .L80240720
/* AF3394 802406F4 00000000 */   nop
.L802406F8:
/* AF3398 802406F8 3C038024 */  lui       $v1, %hi(D_80244E78_A1B098)
/* AF339C 802406FC 24634E78 */  addiu     $v1, $v1, %lo(D_80244E78_A1B098)
/* AF33A0 80240700 0060282D */  daddu     $a1, $v1, $zero
.L80240704:
/* AF33A4 80240704 24820080 */  addiu     $v0, $a0, 0x80
/* AF33A8 80240708 AC620000 */  sw        $v0, ($v1)
/* AF33AC 8024070C 24630004 */  addiu     $v1, $v1, 4
/* AF33B0 80240710 24840001 */  addiu     $a0, $a0, 1
/* AF33B4 80240714 2882005B */  slti      $v0, $a0, 0x5b
/* AF33B8 80240718 1440FFFA */  bnez      $v0, .L80240704
/* AF33BC 8024071C ACA0016C */   sw       $zero, 0x16c($a1)
.L80240720:
/* AF33C0 80240720 8FBF0010 */  lw        $ra, 0x10($sp)
/* AF33C4 80240724 24020002 */  addiu     $v0, $zero, 2
/* AF33C8 80240728 03E00008 */  jr        $ra
/* AF33CC 8024072C 27BD0018 */   addiu    $sp, $sp, 0x18
