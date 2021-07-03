.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80244758_AA7478
.double 190.0

.section .text

glabel func_802404AC_AA31CC
/* AA31CC 802404AC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* AA31D0 802404B0 AFB40020 */  sw        $s4, 0x20($sp)
/* AA31D4 802404B4 0080A02D */  daddu     $s4, $a0, $zero
/* AA31D8 802404B8 AFBF0024 */  sw        $ra, 0x24($sp)
/* AA31DC 802404BC AFB3001C */  sw        $s3, 0x1c($sp)
/* AA31E0 802404C0 AFB20018 */  sw        $s2, 0x18($sp)
/* AA31E4 802404C4 AFB10014 */  sw        $s1, 0x14($sp)
/* AA31E8 802404C8 AFB00010 */  sw        $s0, 0x10($sp)
/* AA31EC 802404CC 8E920148 */  lw        $s2, 0x148($s4)
/* AA31F0 802404D0 86440008 */  lh        $a0, 8($s2)
/* AA31F4 802404D4 8E90000C */  lw        $s0, 0xc($s4)
/* AA31F8 802404D8 0C00EABB */  jal       get_npc_unsafe
/* AA31FC 802404DC 00A0882D */   daddu    $s1, $a1, $zero
/* AA3200 802404E0 0280202D */  daddu     $a0, $s4, $zero
/* AA3204 802404E4 8E050000 */  lw        $a1, ($s0)
/* AA3208 802404E8 0C0B1EAF */  jal       get_variable
/* AA320C 802404EC 0040982D */   daddu    $s3, $v0, $zero
/* AA3210 802404F0 1220000C */  beqz      $s1, .L80240524
/* AA3214 802404F4 2402001E */   addiu    $v0, $zero, 0x1e
/* AA3218 802404F8 AE800070 */  sw        $zero, 0x70($s4)
/* AA321C 802404FC A662008E */  sh        $v0, 0x8e($s3)
/* AA3220 80240500 8E4200CC */  lw        $v0, 0xcc($s2)
/* AA3224 80240504 8C420000 */  lw        $v0, ($v0)
/* AA3228 80240508 0260202D */  daddu     $a0, $s3, $zero
/* AA322C 8024050C AE620028 */  sw        $v0, 0x28($s3)
/* AA3230 80240510 8E420000 */  lw        $v0, ($s2)
/* AA3234 80240514 3C030020 */  lui       $v1, 0x20
/* AA3238 80240518 00431025 */  or        $v0, $v0, $v1
/* AA323C 8024051C 0C00EAFF */  jal       disable_npc_shadow
/* AA3240 80240520 AE420000 */   sw       $v0, ($s2)
.L80240524:
/* AA3244 80240524 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* AA3248 80240528 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* AA324C 8024052C C660003C */  lwc1      $f0, 0x3c($s3)
/* AA3250 80240530 C442002C */  lwc1      $f2, 0x2c($v0)
/* AA3254 80240534 46020001 */  sub.s     $f0, $f0, $f2
/* AA3258 80240538 3C018024 */  lui       $at, %hi(D_80244758_AA7478)
/* AA325C 8024053C D4224758 */  ldc1      $f2, %lo(D_80244758_AA7478)($at)
/* AA3260 80240540 46000121 */  cvt.d.s   $f4, $f0
/* AA3264 80240544 4624103C */  c.lt.d    $f2, $f4
/* AA3268 80240548 00000000 */  nop
/* AA326C 8024054C 45010071 */  bc1t      .L80240714
/* AA3270 80240550 0000102D */   daddu    $v0, $zero, $zero
/* AA3274 80240554 3C01C054 */  lui       $at, 0xc054
/* AA3278 80240558 44810800 */  mtc1      $at, $f1
/* AA327C 8024055C 44800000 */  mtc1      $zero, $f0
/* AA3280 80240560 00000000 */  nop
/* AA3284 80240564 4620203C */  c.lt.d    $f4, $f0
/* AA3288 80240568 00000000 */  nop
/* AA328C 8024056C 45010069 */  bc1t      .L80240714
/* AA3290 80240570 00000000 */   nop
/* AA3294 80240574 8E4200B0 */  lw        $v0, 0xb0($s2)
/* AA3298 80240578 30420004 */  andi      $v0, $v0, 4
/* AA329C 8024057C 1040000B */  beqz      $v0, .L802405AC
/* AA32A0 80240580 00000000 */   nop
/* AA32A4 80240584 8E4200CC */  lw        $v0, 0xcc($s2)
/* AA32A8 80240588 8C420000 */  lw        $v0, ($v0)
/* AA32AC 8024058C AE620028 */  sw        $v0, 0x28($s3)
/* AA32B0 80240590 824200B4 */  lb        $v0, 0xb4($s2)
/* AA32B4 80240594 1440005F */  bnez      $v0, .L80240714
/* AA32B8 80240598 0000102D */   daddu    $v0, $zero, $zero
/* AA32BC 8024059C 8E4200B0 */  lw        $v0, 0xb0($s2)
/* AA32C0 802405A0 2403FFFB */  addiu     $v1, $zero, -5
/* AA32C4 802405A4 00431024 */  and       $v0, $v0, $v1
/* AA32C8 802405A8 AE4200B0 */  sw        $v0, 0xb0($s2)
.L802405AC:
/* AA32CC 802405AC 8E900070 */  lw        $s0, 0x70($s4)
/* AA32D0 802405B0 1200000E */  beqz      $s0, .L802405EC
/* AA32D4 802405B4 00000000 */   nop
/* AA32D8 802405B8 06000055 */  bltz      $s0, .L80240710
/* AA32DC 802405BC 2402000A */   addiu    $v0, $zero, 0xa
/* AA32E0 802405C0 12020013 */  beq       $s0, $v0, .L80240610
/* AA32E4 802405C4 0202102A */   slt      $v0, $s0, $v0
/* AA32E8 802405C8 14400052 */  bnez      $v0, .L80240714
/* AA32EC 802405CC 0000102D */   daddu    $v0, $zero, $zero
/* AA32F0 802405D0 2402000B */  addiu     $v0, $zero, 0xb
/* AA32F4 802405D4 12020022 */  beq       $s0, $v0, .L80240660
/* AA32F8 802405D8 2402000C */   addiu    $v0, $zero, 0xc
/* AA32FC 802405DC 12020035 */  beq       $s0, $v0, .L802406B4
/* AA3300 802405E0 0000102D */   daddu    $v0, $zero, $zero
/* AA3304 802405E4 080901C5 */  j         .L80240714
/* AA3308 802405E8 00000000 */   nop
.L802405EC:
/* AA330C 802405EC 9662008E */  lhu       $v0, 0x8e($s3)
/* AA3310 802405F0 2442FFFF */  addiu     $v0, $v0, -1
/* AA3314 802405F4 A662008E */  sh        $v0, 0x8e($s3)
/* AA3318 802405F8 00021400 */  sll       $v0, $v0, 0x10
/* AA331C 802405FC 1C400045 */  bgtz      $v0, .L80240714
/* AA3320 80240600 0000102D */   daddu    $v0, $zero, $zero
/* AA3324 80240604 2402000A */  addiu     $v0, $zero, 0xa
/* AA3328 80240608 080901C4 */  j         .L80240710
/* AA332C 8024060C AE820070 */   sw       $v0, 0x70($s4)
.L80240610:
/* AA3330 80240610 0C090000 */  jal       func_80240000_AA2D20
/* AA3334 80240614 00000000 */   nop
/* AA3338 80240618 1840002C */  blez      $v0, .L802406CC
/* AA333C 8024061C AE42006C */   sw       $v0, 0x6c($s2)
/* AA3340 80240620 0C00FB3A */  jal       get_enemy
/* AA3344 80240624 0040202D */   daddu    $a0, $v0, $zero
/* AA3348 80240628 0040182D */  daddu     $v1, $v0, $zero
/* AA334C 8024062C 24020001 */  addiu     $v0, $zero, 1
/* AA3350 80240630 AC62006C */  sw        $v0, 0x6c($v1)
/* AA3354 80240634 86420008 */  lh        $v0, 8($s2)
/* AA3358 80240638 AC620070 */  sw        $v0, 0x70($v1)
/* AA335C 8024063C 8E420070 */  lw        $v0, 0x70($s2)
/* AA3360 80240640 AC620074 */  sw        $v0, 0x74($v1)
/* AA3364 80240644 8E4200CC */  lw        $v0, 0xcc($s2)
/* AA3368 80240648 8C420020 */  lw        $v0, 0x20($v0)
/* AA336C 8024064C A670008E */  sh        $s0, 0x8e($s3)
/* AA3370 80240650 AE620028 */  sw        $v0, 0x28($s3)
/* AA3374 80240654 2402000B */  addiu     $v0, $zero, 0xb
/* AA3378 80240658 080901C4 */  j         .L80240710
/* AA337C 8024065C AE820070 */   sw       $v0, 0x70($s4)
.L80240660:
/* AA3380 80240660 9662008E */  lhu       $v0, 0x8e($s3)
/* AA3384 80240664 2442FFFF */  addiu     $v0, $v0, -1
/* AA3388 80240668 A662008E */  sh        $v0, 0x8e($s3)
/* AA338C 8024066C 00021400 */  sll       $v0, $v0, 0x10
/* AA3390 80240670 1C400028 */  bgtz      $v0, .L80240714
/* AA3394 80240674 0000102D */   daddu    $v0, $zero, $zero
/* AA3398 80240678 8E4200CC */  lw        $v0, 0xcc($s2)
/* AA339C 8024067C 8C420000 */  lw        $v0, ($v0)
/* AA33A0 80240680 AE620028 */  sw        $v0, 0x28($s3)
/* AA33A4 80240684 0C00FB3A */  jal       get_enemy
/* AA33A8 80240688 8E44006C */   lw       $a0, 0x6c($s2)
/* AA33AC 8024068C 0260202D */  daddu     $a0, $s3, $zero
/* AA33B0 80240690 24050328 */  addiu     $a1, $zero, 0x328
/* AA33B4 80240694 24030002 */  addiu     $v1, $zero, 2
/* AA33B8 80240698 3C060020 */  lui       $a2, 0x20
/* AA33BC 8024069C 0C012530 */  jal       ai_enemy_play_sound
/* AA33C0 802406A0 AC43006C */   sw       $v1, 0x6c($v0)
/* AA33C4 802406A4 24020005 */  addiu     $v0, $zero, 5
/* AA33C8 802406A8 A662008E */  sh        $v0, 0x8e($s3)
/* AA33CC 802406AC 2402000C */  addiu     $v0, $zero, 0xc
/* AA33D0 802406B0 AE820070 */  sw        $v0, 0x70($s4)
.L802406B4:
/* AA33D4 802406B4 9662008E */  lhu       $v0, 0x8e($s3)
/* AA33D8 802406B8 2442FFFF */  addiu     $v0, $v0, -1
/* AA33DC 802406BC A662008E */  sh        $v0, 0x8e($s3)
/* AA33E0 802406C0 00021400 */  sll       $v0, $v0, 0x10
/* AA33E4 802406C4 1C400013 */  bgtz      $v0, .L80240714
/* AA33E8 802406C8 0000102D */   daddu    $v0, $zero, $zero
.L802406CC:
/* AA33EC 802406CC 0C00A67F */  jal       rand_int
/* AA33F0 802406D0 240403E8 */   addiu    $a0, $zero, 0x3e8
/* AA33F4 802406D4 3C038888 */  lui       $v1, 0x8888
/* AA33F8 802406D8 34638889 */  ori       $v1, $v1, 0x8889
/* AA33FC 802406DC 00430018 */  mult      $v0, $v1
/* AA3400 802406E0 00021FC3 */  sra       $v1, $v0, 0x1f
/* AA3404 802406E4 00003810 */  mfhi      $a3
/* AA3408 802406E8 00E22021 */  addu      $a0, $a3, $v0
/* AA340C 802406EC 00042143 */  sra       $a0, $a0, 5
/* AA3410 802406F0 00832023 */  subu      $a0, $a0, $v1
/* AA3414 802406F4 00041900 */  sll       $v1, $a0, 4
/* AA3418 802406F8 00641823 */  subu      $v1, $v1, $a0
/* AA341C 802406FC 00031880 */  sll       $v1, $v1, 2
/* AA3420 80240700 00431023 */  subu      $v0, $v0, $v1
/* AA3424 80240704 24420028 */  addiu     $v0, $v0, 0x28
/* AA3428 80240708 A662008E */  sh        $v0, 0x8e($s3)
/* AA342C 8024070C AE800070 */  sw        $zero, 0x70($s4)
.L80240710:
/* AA3430 80240710 0000102D */  daddu     $v0, $zero, $zero
.L80240714:
/* AA3434 80240714 8FBF0024 */  lw        $ra, 0x24($sp)
/* AA3438 80240718 8FB40020 */  lw        $s4, 0x20($sp)
/* AA343C 8024071C 8FB3001C */  lw        $s3, 0x1c($sp)
/* AA3440 80240720 8FB20018 */  lw        $s2, 0x18($sp)
/* AA3444 80240724 8FB10014 */  lw        $s1, 0x14($sp)
/* AA3448 80240728 8FB00010 */  lw        $s0, 0x10($sp)
/* AA344C 8024072C 03E00008 */  jr        $ra
/* AA3450 80240730 27BD0028 */   addiu    $sp, $sp, 0x28
/* AA3454 80240734 00000000 */  nop
/* AA3458 80240738 00000000 */  nop
/* AA345C 8024073C 00000000 */  nop
