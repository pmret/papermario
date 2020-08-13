.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel PartnerPowerBounceEnemy
/* 1AEB50 80280270 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 1AEB54 80280274 AFB20018 */  sw    $s2, 0x18($sp)
/* 1AEB58 80280278 0080902D */  daddu $s2, $a0, $zero
/* 1AEB5C 8028027C AFBF0024 */  sw    $ra, 0x24($sp)
/* 1AEB60 80280280 AFB40020 */  sw    $s4, 0x20($sp)
/* 1AEB64 80280284 AFB3001C */  sw    $s3, 0x1c($sp)
/* 1AEB68 80280288 AFB10014 */  sw    $s1, 0x14($sp)
/* 1AEB6C 8028028C AFB00010 */  sw    $s0, 0x10($sp)
/* 1AEB70 80280290 8E440148 */  lw    $a0, 0x148($s2)
/* 1AEB74 80280294 0C09A75B */  jal   get_actor
/* 1AEB78 80280298 8E50000C */   lw    $s0, 0xc($s2)
/* 1AEB7C 8028029C 8E140000 */  lw    $s4, ($s0)
/* 1AEB80 802802A0 26100004 */  addiu $s0, $s0, 4
/* 1AEB84 802802A4 8E030000 */  lw    $v1, ($s0)
/* 1AEB88 802802A8 26100004 */  addiu $s0, $s0, 4
/* 1AEB8C 802802AC 0240202D */  daddu $a0, $s2, $zero
/* 1AEB90 802802B0 3C11800E */  lui   $s1, 0x800e
/* 1AEB94 802802B4 2631C070 */  addiu $s1, $s1, -0x3f90
/* 1AEB98 802802B8 0040982D */  daddu $s3, $v0, $zero
/* 1AEB9C 802802BC AE230188 */  sw    $v1, 0x188($s1)
/* 1AEBA0 802802C0 8E030000 */  lw    $v1, ($s0)
/* 1AEBA4 802802C4 26100004 */  addiu $s0, $s0, 4
/* 1AEBA8 802802C8 AE23018C */  sw    $v1, 0x18c($s1)
/* 1AEBAC 802802CC 8E030000 */  lw    $v1, ($s0)
/* 1AEBB0 802802D0 26100004 */  addiu $s0, $s0, 4
/* 1AEBB4 802802D4 AE230190 */  sw    $v1, 0x190($s1)
/* 1AEBB8 802802D8 8E050000 */  lw    $a1, ($s0)
/* 1AEBBC 802802DC 0C0B1EAF */  jal   get_variable
/* 1AEBC0 802802E0 26100004 */   addiu $s0, $s0, 4
/* 1AEBC4 802802E4 A622017E */  sh    $v0, 0x17e($s1)
/* 1AEBC8 802802E8 8E050000 */  lw    $a1, ($s0)
/* 1AEBCC 802802EC 26100004 */  addiu $s0, $s0, 4
/* 1AEBD0 802802F0 0C0B1EAF */  jal   get_variable
/* 1AEBD4 802802F4 0240202D */   daddu $a0, $s2, $zero
/* 1AEBD8 802802F8 A2220198 */  sb    $v0, 0x198($s1)
/* 1AEBDC 802802FC 8E100000 */  lw    $s0, ($s0)
/* 1AEBE0 80280300 24020030 */  addiu $v0, $zero, 0x30
/* 1AEBE4 80280304 32030030 */  andi  $v1, $s0, 0x30
/* 1AEBE8 80280308 54620004 */  bnel  $v1, $v0, .L8028031C
/* 1AEBEC 8028030C 32020010 */   andi  $v0, $s0, 0x10
/* 1AEBF0 80280310 8E220000 */  lw    $v0, ($s1)
/* 1AEBF4 80280314 080A00D7 */  j     func_8028035C
/* 1AEBF8 80280318 34420030 */   ori   $v0, $v0, 0x30

.L8028031C:
/* 1AEBFC 8028031C 10400004 */  beqz  $v0, .L80280330
/* 1AEC00 80280320 2403FFDF */   addiu $v1, $zero, -0x21
/* 1AEC04 80280324 8E220000 */  lw    $v0, ($s1)
/* 1AEC08 80280328 080A00D6 */  j     .L80280358
/* 1AEC0C 8028032C 34420010 */   ori   $v0, $v0, 0x10

.L80280330:
/* 1AEC10 80280330 32020020 */  andi  $v0, $s0, 0x20
/* 1AEC14 80280334 10400005 */  beqz  $v0, .L8028034C
/* 1AEC18 80280338 2403FFEF */   addiu $v1, $zero, -0x11
/* 1AEC1C 8028033C 8E220000 */  lw    $v0, ($s1)
/* 1AEC20 80280340 00431024 */  and   $v0, $v0, $v1
/* 1AEC24 80280344 080A00D7 */  j     func_8028035C
/* 1AEC28 80280348 34420020 */   ori   $v0, $v0, 0x20

.L8028034C:
/* 1AEC2C 8028034C 8E220000 */  lw    $v0, ($s1)
/* 1AEC30 80280350 00431024 */  and   $v0, $v0, $v1
/* 1AEC34 80280354 2403FFDF */  addiu $v1, $zero, -0x21
.L80280358:
/* 1AEC38 80280358 00431024 */  and   $v0, $v0, $v1
/* 1AEC3C 8028035C AE220000 */  sw    $v0, ($s1)
/* 1AEC40 80280360 32020040 */  andi  $v0, $s0, 0x40
/* 1AEC44 80280364 10400007 */  beqz  $v0, .L80280384
/* 1AEC48 80280368 2404FFBF */   addiu $a0, $zero, -0x41
/* 1AEC4C 8028036C 3C03800E */  lui   $v1, 0x800e
/* 1AEC50 80280370 2463C070 */  addiu $v1, $v1, -0x3f90
/* 1AEC54 80280374 8C620000 */  lw    $v0, ($v1)
/* 1AEC58 80280378 34420040 */  ori   $v0, $v0, 0x40
/* 1AEC5C 8028037C 080A00E6 */  j     .L80280398
/* 1AEC60 80280380 AC620000 */   sw    $v0, ($v1)

.L80280384:
/* 1AEC64 80280384 3C02800E */  lui   $v0, 0x800e
/* 1AEC68 80280388 2442C070 */  addiu $v0, $v0, -0x3f90
/* 1AEC6C 8028038C 8C430000 */  lw    $v1, ($v0)
/* 1AEC70 80280390 00641824 */  and   $v1, $v1, $a0
/* 1AEC74 80280394 AC430000 */  sw    $v1, ($v0)
.L80280398:
/* 1AEC78 80280398 32020200 */  andi  $v0, $s0, 0x200
/* 1AEC7C 8028039C 10400007 */  beqz  $v0, .L802803BC
/* 1AEC80 802803A0 2404FDFF */   addiu $a0, $zero, -0x201
/* 1AEC84 802803A4 3C03800E */  lui   $v1, 0x800e
/* 1AEC88 802803A8 2463C070 */  addiu $v1, $v1, -0x3f90
/* 1AEC8C 802803AC 8C620000 */  lw    $v0, ($v1)
/* 1AEC90 802803B0 34420200 */  ori   $v0, $v0, 0x200
/* 1AEC94 802803B4 080A00F4 */  j     .L802803D0
/* 1AEC98 802803B8 AC620000 */   sw    $v0, ($v1)

.L802803BC:
/* 1AEC9C 802803BC 3C02800E */  lui   $v0, 0x800e
/* 1AECA0 802803C0 2442C070 */  addiu $v0, $v0, -0x3f90
/* 1AECA4 802803C4 8C430000 */  lw    $v1, ($v0)
/* 1AECA8 802803C8 00641824 */  and   $v1, $v1, $a0
/* 1AECAC 802803CC AC430000 */  sw    $v1, ($v0)
.L802803D0:
/* 1AECB0 802803D0 32020080 */  andi  $v0, $s0, 0x80
/* 1AECB4 802803D4 10400007 */  beqz  $v0, .L802803F4
/* 1AECB8 802803D8 2404FF7F */   addiu $a0, $zero, -0x81
/* 1AECBC 802803DC 3C03800E */  lui   $v1, 0x800e
/* 1AECC0 802803E0 2463C070 */  addiu $v1, $v1, -0x3f90
/* 1AECC4 802803E4 8C620000 */  lw    $v0, ($v1)
/* 1AECC8 802803E8 34420080 */  ori   $v0, $v0, 0x80
/* 1AECCC 802803EC 080A0102 */  j     .L80280408
/* 1AECD0 802803F0 AC620000 */   sw    $v0, ($v1)

.L802803F4:
/* 1AECD4 802803F4 3C02800E */  lui   $v0, 0x800e
/* 1AECD8 802803F8 2442C070 */  addiu $v0, $v0, -0x3f90
/* 1AECDC 802803FC 8C430000 */  lw    $v1, ($v0)
/* 1AECE0 80280400 00641824 */  and   $v1, $v1, $a0
/* 1AECE4 80280404 AC430000 */  sw    $v1, ($v0)
.L80280408:
/* 1AECE8 80280408 32020800 */  andi  $v0, $s0, 0x800
/* 1AECEC 8028040C 10400007 */  beqz  $v0, .L8028042C
/* 1AECF0 80280410 2404F7FF */   addiu $a0, $zero, -0x801
/* 1AECF4 80280414 3C03800E */  lui   $v1, 0x800e
/* 1AECF8 80280418 2463C070 */  addiu $v1, $v1, -0x3f90
/* 1AECFC 8028041C 8C620000 */  lw    $v0, ($v1)
/* 1AED00 80280420 34420800 */  ori   $v0, $v0, 0x800
/* 1AED04 80280424 080A0110 */  j     .L80280440
/* 1AED08 80280428 AC620000 */   sw    $v0, ($v1)

.L8028042C:
/* 1AED0C 8028042C 3C02800E */  lui   $v0, 0x800e
/* 1AED10 80280430 2442C070 */  addiu $v0, $v0, -0x3f90
/* 1AED14 80280434 8C430000 */  lw    $v1, ($v0)
/* 1AED18 80280438 00641824 */  and   $v1, $v1, $a0
/* 1AED1C 8028043C AC430000 */  sw    $v1, ($v0)
.L80280440:
/* 1AED20 80280440 96620428 */  lhu   $v0, 0x428($s3)
/* 1AED24 80280444 92230193 */  lbu   $v1, 0x193($s1)
/* 1AED28 80280448 A62201A0 */  sh    $v0, 0x1a0($s1)
/* 1AED2C 8028044C 92620426 */  lbu   $v0, 0x426($s3)
/* 1AED30 80280450 A2230194 */  sb    $v1, 0x194($s1)
/* 1AED34 80280454 306300FF */  andi  $v1, $v1, 0xff
/* 1AED38 80280458 A22201A2 */  sb    $v0, 0x1a2($s1)
/* 1AED3C 8028045C 240200FF */  addiu $v0, $zero, 0xff
/* 1AED40 80280460 50620001 */  beql  $v1, $v0, .L80280468
/* 1AED44 80280464 A2200194 */   sb    $zero, 0x194($s1)
.L80280468:
/* 1AED48 80280468 8E220190 */  lw    $v0, 0x190($s1)
/* 1AED4C 8028046C 30420F00 */  andi  $v0, $v0, 0xf00
/* 1AED50 80280470 00021203 */  sra   $v0, $v0, 8
/* 1AED54 80280474 0C09F8CA */  jal   calc_partner_damage_enemy
/* 1AED58 80280478 A2220195 */   sb    $v0, 0x195($s1)
/* 1AED5C 8028047C 0440000B */  bltz  $v0, .L802804AC
/* 1AED60 80280480 0240202D */   daddu $a0, $s2, $zero
/* 1AED64 80280484 0280282D */  daddu $a1, $s4, $zero
/* 1AED68 80280488 0C0B2026 */  jal   set_variable
/* 1AED6C 8028048C 0040302D */   daddu $a2, $v0, $zero
/* 1AED70 80280490 0C0B1069 */  jal   does_script_exist_by_ref
/* 1AED74 80280494 0240202D */   daddu $a0, $s2, $zero
/* 1AED78 80280498 0040182D */  daddu $v1, $v0, $zero
/* 1AED7C 8028049C 10600004 */  beqz  $v1, .L802804B0
/* 1AED80 802804A0 240200FF */   addiu $v0, $zero, 0xff
/* 1AED84 802804A4 080A012C */  j     .L802804B0
/* 1AED88 802804A8 24020002 */   addiu $v0, $zero, 2

.L802804AC:
/* 1AED8C 802804AC 240200FF */  addiu $v0, $zero, 0xff
.L802804B0:
.L802804B0:
/* 1AED90 802804B0 8FBF0024 */  lw    $ra, 0x24($sp)
/* 1AED94 802804B4 8FB40020 */  lw    $s4, 0x20($sp)
/* 1AED98 802804B8 8FB3001C */  lw    $s3, 0x1c($sp)
/* 1AED9C 802804BC 8FB20018 */  lw    $s2, 0x18($sp)
/* 1AEDA0 802804C0 8FB10014 */  lw    $s1, 0x14($sp)
/* 1AEDA4 802804C4 8FB00010 */  lw    $s0, 0x10($sp)
/* 1AEDA8 802804C8 03E00008 */  jr    $ra
/* 1AEDAC 802804CC 27BD0028 */   addiu $sp, $sp, 0x28

