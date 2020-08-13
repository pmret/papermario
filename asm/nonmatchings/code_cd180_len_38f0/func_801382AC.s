.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_801382AC
/* 0CE9AC 801382AC 3C038015 */  lui   $v1, 0x8015
/* 0CE9B0 801382B0 8C63C6F0 */  lw    $v1, -0x3910($v1)
/* 0CE9B4 801382B4 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0CE9B8 801382B8 AFB60028 */  sw    $s6, 0x28($sp)
/* 0CE9BC 801382BC 0080B02D */  daddu $s6, $a0, $zero
/* 0CE9C0 801382C0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0CE9C4 801382C4 0000882D */  daddu $s1, $zero, $zero
/* 0CE9C8 801382C8 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0CE9CC 801382CC 0220982D */  daddu $s3, $s1, $zero
/* 0CE9D0 801382D0 AFB40020 */  sw    $s4, 0x20($sp)
/* 0CE9D4 801382D4 0220A02D */  daddu $s4, $s1, $zero
/* 0CE9D8 801382D8 AFB50024 */  sw    $s5, 0x24($sp)
/* 0CE9DC 801382DC 0220A82D */  daddu $s5, $s1, $zero
/* 0CE9E0 801382E0 AFB20018 */  sw    $s2, 0x18($sp)
/* 0CE9E4 801382E4 24120014 */  addiu $s2, $zero, 0x14
/* 0CE9E8 801382E8 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0CE9EC 801382EC 2C620011 */  sltiu $v0, $v1, 0x11
/* 0CE9F0 801382F0 1040005E */  beqz  $v0, .L8013846C
/* 0CE9F4 801382F4 AFB00010 */   sw    $s0, 0x10($sp)
/* 0CE9F8 801382F8 00031080 */  sll   $v0, $v1, 2
/* 0CE9FC 801382FC 3C018015 */  lui   $at, 0x8015
/* 0CEA00 80138300 00220821 */  addu  $at, $at, $v0
/* 0CEA04 80138304 8C220EF0 */  lw    $v0, 0xef0($at)
/* 0CEA08 80138308 00400008 */  jr    $v0
/* 0CEA0C 8013830C 00000000 */   nop   
/* 0CEA10 80138310 0804E11B */  j     .L8013846C
/* 0CEA14 80138314 0000882D */   daddu $s1, $zero, $zero

/* 0CEA18 80138318 241500D0 */  addiu $s5, $zero, 0xd0
/* 0CEA1C 8013831C 02A0A02D */  daddu $s4, $s5, $zero
/* 0CEA20 80138320 02A0982D */  daddu $s3, $s5, $zero
/* 0CEA24 80138324 24110001 */  addiu $s1, $zero, 1
/* 0CEA28 80138328 3C048007 */  lui   $a0, 0x8007
/* 0CEA2C 8013832C 8C84419C */  lw    $a0, 0x419c($a0)
/* 0CEA30 80138330 80830071 */  lb    $v1, 0x71($a0)
/* 0CEA34 80138334 24020002 */  addiu $v0, $zero, 2
/* 0CEA38 80138338 1462004C */  bne   $v1, $v0, .L8013846C
/* 0CEA3C 8013833C 2412000A */   addiu $s2, $zero, 0xa
/* 0CEA40 80138340 24020012 */  addiu $v0, $zero, 0x12
/* 0CEA44 80138344 0804E11B */  j     .L8013846C
/* 0CEA48 80138348 A0820072 */   sb    $v0, 0x72($a0)

/* 0CEA4C 8013834C 241500D0 */  addiu $s5, $zero, 0xd0
/* 0CEA50 80138350 02A0A02D */  daddu $s4, $s5, $zero
/* 0CEA54 80138354 02A0982D */  daddu $s3, $s5, $zero
/* 0CEA58 80138358 0804E11B */  j     .L8013846C
/* 0CEA5C 8013835C 24110001 */   addiu $s1, $zero, 1

/* 0CEA60 80138360 3C048007 */  lui   $a0, 0x8007
/* 0CEA64 80138364 8C84419C */  lw    $a0, 0x419c($a0)
/* 0CEA68 80138368 80830071 */  lb    $v1, 0x71($a0)
/* 0CEA6C 8013836C 24020002 */  addiu $v0, $zero, 2
/* 0CEA70 80138370 14620004 */  bne   $v1, $v0, .L80138384
/* 0CEA74 80138374 241500D0 */   addiu $s5, $zero, 0xd0
/* 0CEA78 80138378 24020012 */  addiu $v0, $zero, 0x12
/* 0CEA7C 8013837C A0820072 */  sb    $v0, 0x72($a0)
/* 0CEA80 80138380 241500D0 */  addiu $s5, $zero, 0xd0
.L80138384:
/* 0CEA84 80138384 02A0A02D */  daddu $s4, $s5, $zero
/* 0CEA88 80138388 02A0982D */  daddu $s3, $s5, $zero
/* 0CEA8C 8013838C 24110001 */  addiu $s1, $zero, 1
/* 0CEA90 80138390 0804E11B */  j     .L8013846C
/* 0CEA94 80138394 24120007 */   addiu $s2, $zero, 7

/* 0CEA98 80138398 241500D0 */  addiu $s5, $zero, 0xd0
/* 0CEA9C 8013839C 02A0A02D */  daddu $s4, $s5, $zero
/* 0CEAA0 801383A0 02A0982D */  daddu $s3, $s5, $zero
/* 0CEAA4 801383A4 24110001 */  addiu $s1, $zero, 1
/* 0CEAA8 801383A8 0804E11B */  j     .L8013846C
/* 0CEAAC 801383AC 24120032 */   addiu $s2, $zero, 0x32

/* 0CEAB0 801383B0 0000202D */  daddu $a0, $zero, $zero
/* 0CEAB4 801383B4 0C04E035 */  jal   func_801380D4
/* 0CEAB8 801383B8 0000282D */   daddu $a1, $zero, $zero
/* 0CEABC 801383BC 0804E11B */  j     .L8013846C
/* 0CEAC0 801383C0 24110004 */   addiu $s1, $zero, 4

/* 0CEAC4 801383C4 241500D0 */  addiu $s5, $zero, 0xd0
/* 0CEAC8 801383C8 02A0A02D */  daddu $s4, $s5, $zero
/* 0CEACC 801383CC 02A0982D */  daddu $s3, $s5, $zero
/* 0CEAD0 801383D0 0000202D */  daddu $a0, $zero, $zero
/* 0CEAD4 801383D4 0C04E035 */  jal   func_801380D4
/* 0CEAD8 801383D8 0000282D */   daddu $a1, $zero, $zero
/* 0CEADC 801383DC 24110004 */  addiu $s1, $zero, 4
/* 0CEAE0 801383E0 0804E11B */  j     .L8013846C
/* 0CEAE4 801383E4 24120007 */   addiu $s2, $zero, 7

/* 0CEAE8 801383E8 0000202D */  daddu $a0, $zero, $zero
/* 0CEAEC 801383EC 3C054320 */  lui   $a1, 0x4320
/* 0CEAF0 801383F0 241500D0 */  addiu $s5, $zero, 0xd0
/* 0CEAF4 801383F4 02A0A02D */  daddu $s4, $s5, $zero
/* 0CEAF8 801383F8 02A0982D */  daddu $s3, $s5, $zero
/* 0CEAFC 801383FC 24110005 */  addiu $s1, $zero, 5
/* 0CEB00 80138400 0C04E035 */  jal   func_801380D4
/* 0CEB04 80138404 24120007 */   addiu $s2, $zero, 7
/* 0CEB08 80138408 0804E11B */  j     .L8013846C
/* 0CEB0C 8013840C 00000000 */   nop   

/* 0CEB10 80138410 0000202D */  daddu $a0, $zero, $zero
/* 0CEB14 80138414 0C04E035 */  jal   func_801380D4
/* 0CEB18 80138418 0000282D */   daddu $a1, $zero, $zero
/* 0CEB1C 8013841C 24110005 */  addiu $s1, $zero, 5
/* 0CEB20 80138420 0804E11B */  j     .L8013846C
/* 0CEB24 80138424 24120007 */   addiu $s2, $zero, 7

/* 0CEB28 80138428 0000202D */  daddu $a0, $zero, $zero
/* 0CEB2C 8013842C 0080282D */  daddu $a1, $a0, $zero
/* 0CEB30 80138430 2406000F */  addiu $a2, $zero, 0xf
/* 0CEB34 80138434 0C04DF93 */  jal   func_80137E4C
/* 0CEB38 80138438 2407001C */   addiu $a3, $zero, 0x1c
/* 0CEB3C 8013843C 0000202D */  daddu $a0, $zero, $zero
/* 0CEB40 80138440 24050001 */  addiu $a1, $zero, 1
/* 0CEB44 80138444 24060131 */  addiu $a2, $zero, 0x131
/* 0CEB48 80138448 0C04DF93 */  jal   func_80137E4C
/* 0CEB4C 8013844C 2407009C */   addiu $a3, $zero, 0x9c
/* 0CEB50 80138450 3C05437F */  lui   $a1, 0x437f
/* 0CEB54 80138454 0C04DF62 */  jal   func_80137D88
/* 0CEB58 80138458 2404000C */   addiu $a0, $zero, 0xc
/* 0CEB5C 8013845C 24020001 */  addiu $v0, $zero, 1
/* 0CEB60 80138460 240300FF */  addiu $v1, $zero, 0xff
/* 0CEB64 80138464 0804E16B */  j     .L801385AC
/* 0CEB68 80138468 A6C30000 */   sh    $v1, ($s6)

.L8013846C:
/* 0CEB6C 8013846C 3C038015 */  lui   $v1, 0x8015
/* 0CEB70 80138470 8C63C6F0 */  lw    $v1, -0x3910($v1)
/* 0CEB74 80138474 24020005 */  addiu $v0, $zero, 5
/* 0CEB78 80138478 14620025 */  bne   $v1, $v0, .L80138510
/* 0CEB7C 8013847C 0000802D */   daddu $s0, $zero, $zero
/* 0CEB80 80138480 3C048080 */  lui   $a0, 0x8080
/* 0CEB84 80138484 34848081 */  ori   $a0, $a0, 0x8081
/* 0CEB88 80138488 86C30000 */  lh    $v1, ($s6)
/* 0CEB8C 8013848C 241000FF */  addiu $s0, $zero, 0xff
/* 0CEB90 80138490 02031823 */  subu  $v1, $s0, $v1
/* 0CEB94 80138494 00031040 */  sll   $v0, $v1, 1
/* 0CEB98 80138498 00431021 */  addu  $v0, $v0, $v1
/* 0CEB9C 8013849C 00021080 */  sll   $v0, $v0, 2
/* 0CEBA0 801384A0 00431021 */  addu  $v0, $v0, $v1
/* 0CEBA4 801384A4 00021100 */  sll   $v0, $v0, 4
/* 0CEBA8 801384A8 00440018 */  mult  $v0, $a0
/* 0CEBAC 801384AC 0000202D */  daddu $a0, $zero, $zero
/* 0CEBB0 801384B0 00004010 */  mfhi  $t0
/* 0CEBB4 801384B4 01022821 */  addu  $a1, $t0, $v0
/* 0CEBB8 801384B8 000529C3 */  sra   $a1, $a1, 7
/* 0CEBBC 801384BC 000217C3 */  sra   $v0, $v0, 0x1f
/* 0CEBC0 801384C0 00A22823 */  subu  $a1, $a1, $v0
/* 0CEBC4 801384C4 30A500FF */  andi  $a1, $a1, 0xff
/* 0CEBC8 801384C8 00A0302D */  daddu $a2, $a1, $zero
/* 0CEBCC 801384CC 0C04DF84 */  jal   func_80137E10
/* 0CEBD0 801384D0 00A0382D */   daddu $a3, $a1, $zero
/* 0CEBD4 801384D4 3C05437F */  lui   $a1, 0x437f
/* 0CEBD8 801384D8 0C04DF62 */  jal   func_80137D88
/* 0CEBDC 801384DC 0220202D */   daddu $a0, $s1, $zero
/* 0CEBE0 801384E0 86C20000 */  lh    $v0, ($s6)
/* 0CEBE4 801384E4 96C30000 */  lhu   $v1, ($s6)
/* 0CEBE8 801384E8 10500027 */  beq   $v0, $s0, .L80138588
/* 0CEBEC 801384EC 00721021 */   addu  $v0, $v1, $s2
/* 0CEBF0 801384F0 A6C20000 */  sh    $v0, ($s6)
/* 0CEBF4 801384F4 00021400 */  sll   $v0, $v0, 0x10
/* 0CEBF8 801384F8 00021403 */  sra   $v0, $v0, 0x10
/* 0CEBFC 801384FC 28420100 */  slti  $v0, $v0, 0x100
/* 0CEC00 80138500 50400029 */  beql  $v0, $zero, .L801385A8
/* 0CEC04 80138504 A6D00000 */   sh    $s0, ($s6)
/* 0CEC08 80138508 0804E16B */  j     .L801385AC
/* 0CEC0C 8013850C 0000102D */   daddu $v0, $zero, $zero

.L80138510:
/* 0CEC10 80138510 00108400 */  sll   $s0, $s0, 0x10
/* 0CEC14 80138514 00108403 */  sra   $s0, $s0, 0x10
/* 0CEC18 80138518 0200202D */  daddu $a0, $s0, $zero
/* 0CEC1C 8013851C 0260282D */  daddu $a1, $s3, $zero
/* 0CEC20 80138520 0280302D */  daddu $a2, $s4, $zero
/* 0CEC24 80138524 0C04DF84 */  jal   func_80137E10
/* 0CEC28 80138528 02A0382D */   daddu $a3, $s5, $zero
/* 0CEC2C 8013852C 1600000A */  bnez  $s0, .L80138558
/* 0CEC30 80138530 00000000 */   nop   
/* 0CEC34 80138534 86C20000 */  lh    $v0, ($s6)
/* 0CEC38 80138538 44820000 */  mtc1  $v0, $f0
/* 0CEC3C 8013853C 00000000 */  nop   
/* 0CEC40 80138540 46800020 */  cvt.s.w $f0, $f0
/* 0CEC44 80138544 44050000 */  mfc1  $a1, $f0
/* 0CEC48 80138548 0C04DF62 */  jal   func_80137D88
/* 0CEC4C 8013854C 0220202D */   daddu $a0, $s1, $zero
/* 0CEC50 80138550 0804E15E */  j     .L80138578
/* 0CEC54 80138554 240400FF */   addiu $a0, $zero, 0xff

.L80138558:
/* 0CEC58 80138558 86C20000 */  lh    $v0, ($s6)
/* 0CEC5C 8013855C 44820000 */  mtc1  $v0, $f0
/* 0CEC60 80138560 00000000 */  nop   
/* 0CEC64 80138564 46800020 */  cvt.s.w $f0, $f0
/* 0CEC68 80138568 44050000 */  mfc1  $a1, $f0
/* 0CEC6C 8013856C 0C04DF69 */  jal   func_80137DA4
/* 0CEC70 80138570 0220202D */   daddu $a0, $s1, $zero
/* 0CEC74 80138574 240400FF */  addiu $a0, $zero, 0xff
.L80138578:
/* 0CEC78 80138578 86C20000 */  lh    $v0, ($s6)
/* 0CEC7C 8013857C 96C30000 */  lhu   $v1, ($s6)
/* 0CEC80 80138580 14440003 */  bne   $v0, $a0, .L80138590
/* 0CEC84 80138584 00721021 */   addu  $v0, $v1, $s2
.L80138588:
/* 0CEC88 80138588 0804E16B */  j     .L801385AC
/* 0CEC8C 8013858C 24020001 */   addiu $v0, $zero, 1

.L80138590:
/* 0CEC90 80138590 A6C20000 */  sh    $v0, ($s6)
/* 0CEC94 80138594 00021400 */  sll   $v0, $v0, 0x10
/* 0CEC98 80138598 00021403 */  sra   $v0, $v0, 0x10
/* 0CEC9C 8013859C 28420100 */  slti  $v0, $v0, 0x100
/* 0CECA0 801385A0 50400001 */  beql  $v0, $zero, .L801385A8
/* 0CECA4 801385A4 A6C40000 */   sh    $a0, ($s6)
.L801385A8:
/* 0CECA8 801385A8 0000102D */  daddu $v0, $zero, $zero
.L801385AC:
/* 0CECAC 801385AC 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0CECB0 801385B0 8FB60028 */  lw    $s6, 0x28($sp)
/* 0CECB4 801385B4 8FB50024 */  lw    $s5, 0x24($sp)
/* 0CECB8 801385B8 8FB40020 */  lw    $s4, 0x20($sp)
/* 0CECBC 801385BC 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0CECC0 801385C0 8FB20018 */  lw    $s2, 0x18($sp)
/* 0CECC4 801385C4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0CECC8 801385C8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0CECCC 801385CC 03E00008 */  jr    $ra
/* 0CECD0 801385D0 27BD0030 */   addiu $sp, $sp, 0x30

