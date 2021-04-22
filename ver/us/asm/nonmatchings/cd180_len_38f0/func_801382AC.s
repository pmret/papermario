.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80150EF0
.word L80138358_CEA58, L80138310_CEA10, L801383A4_CEAA4, L80138318_CEA18, L8013838C_CEA8C, L8013838C_CEA8C, L8013834C_CEA4C, L80138360_CEA60, L801383B0_CEAB0, L801383C4_CEAC4, L801383D0_CEAD0, L80138380_CEA80, L801383E8_CEAE8, L80138410_CEB10, L80138398_CEA98, L80138380_CEA80, L80138428_CEB28, 0

.section .text

glabel func_801382AC
/* CE9AC 801382AC 3C038015 */  lui       $v1, %hi(D_8014C6F0)
/* CE9B0 801382B0 8C63C6F0 */  lw        $v1, %lo(D_8014C6F0)($v1)
/* CE9B4 801382B4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* CE9B8 801382B8 AFB60028 */  sw        $s6, 0x28($sp)
/* CE9BC 801382BC 0080B02D */  daddu     $s6, $a0, $zero
/* CE9C0 801382C0 AFB10014 */  sw        $s1, 0x14($sp)
/* CE9C4 801382C4 0000882D */  daddu     $s1, $zero, $zero
/* CE9C8 801382C8 AFB3001C */  sw        $s3, 0x1c($sp)
/* CE9CC 801382CC 0220982D */  daddu     $s3, $s1, $zero
/* CE9D0 801382D0 AFB40020 */  sw        $s4, 0x20($sp)
/* CE9D4 801382D4 0220A02D */  daddu     $s4, $s1, $zero
/* CE9D8 801382D8 AFB50024 */  sw        $s5, 0x24($sp)
/* CE9DC 801382DC 0220A82D */  daddu     $s5, $s1, $zero
/* CE9E0 801382E0 AFB20018 */  sw        $s2, 0x18($sp)
/* CE9E4 801382E4 24120014 */  addiu     $s2, $zero, 0x14
/* CE9E8 801382E8 AFBF002C */  sw        $ra, 0x2c($sp)
/* CE9EC 801382EC 2C620011 */  sltiu     $v0, $v1, 0x11
/* CE9F0 801382F0 1040005E */  beqz      $v0, .L8013846C
/* CE9F4 801382F4 AFB00010 */   sw       $s0, 0x10($sp)
/* CE9F8 801382F8 00031080 */  sll       $v0, $v1, 2
/* CE9FC 801382FC 3C018015 */  lui       $at, %hi(jtbl_80150EF0)
/* CEA00 80138300 00220821 */  addu      $at, $at, $v0
/* CEA04 80138304 8C220EF0 */  lw        $v0, %lo(jtbl_80150EF0)($at)
/* CEA08 80138308 00400008 */  jr        $v0
/* CEA0C 8013830C 00000000 */   nop
glabel L80138310_CEA10
/* CEA10 80138310 0804E11B */  j         .L8013846C
/* CEA14 80138314 0000882D */   daddu    $s1, $zero, $zero
glabel L80138318_CEA18
/* CEA18 80138318 241500D0 */  addiu     $s5, $zero, 0xd0
/* CEA1C 8013831C 02A0A02D */  daddu     $s4, $s5, $zero
/* CEA20 80138320 02A0982D */  daddu     $s3, $s5, $zero
/* CEA24 80138324 24110001 */  addiu     $s1, $zero, 1
/* CEA28 80138328 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* CEA2C 8013832C 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* CEA30 80138330 80830071 */  lb        $v1, 0x71($a0)
/* CEA34 80138334 24020002 */  addiu     $v0, $zero, 2
/* CEA38 80138338 1462004C */  bne       $v1, $v0, .L8013846C
/* CEA3C 8013833C 2412000A */   addiu    $s2, $zero, 0xa
/* CEA40 80138340 24020012 */  addiu     $v0, $zero, 0x12
/* CEA44 80138344 0804E11B */  j         .L8013846C
/* CEA48 80138348 A0820072 */   sb       $v0, 0x72($a0)
glabel L8013834C_CEA4C
/* CEA4C 8013834C 241500D0 */  addiu     $s5, $zero, 0xd0
/* CEA50 80138350 02A0A02D */  daddu     $s4, $s5, $zero
/* CEA54 80138354 02A0982D */  daddu     $s3, $s5, $zero
glabel L80138358_CEA58
/* CEA58 80138358 0804E11B */  j         .L8013846C
/* CEA5C 8013835C 24110001 */   addiu    $s1, $zero, 1
glabel L80138360_CEA60
/* CEA60 80138360 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* CEA64 80138364 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* CEA68 80138368 80830071 */  lb        $v1, 0x71($a0)
/* CEA6C 8013836C 24020002 */  addiu     $v0, $zero, 2
/* CEA70 80138370 14620004 */  bne       $v1, $v0, .L80138384
/* CEA74 80138374 241500D0 */   addiu    $s5, $zero, 0xd0
/* CEA78 80138378 24020012 */  addiu     $v0, $zero, 0x12
/* CEA7C 8013837C A0820072 */  sb        $v0, 0x72($a0)
glabel L80138380_CEA80
/* CEA80 80138380 241500D0 */  addiu     $s5, $zero, 0xd0
.L80138384:
/* CEA84 80138384 02A0A02D */  daddu     $s4, $s5, $zero
/* CEA88 80138388 02A0982D */  daddu     $s3, $s5, $zero
glabel L8013838C_CEA8C
/* CEA8C 8013838C 24110001 */  addiu     $s1, $zero, 1
/* CEA90 80138390 0804E11B */  j         .L8013846C
/* CEA94 80138394 24120007 */   addiu    $s2, $zero, 7
glabel L80138398_CEA98
/* CEA98 80138398 241500D0 */  addiu     $s5, $zero, 0xd0
/* CEA9C 8013839C 02A0A02D */  daddu     $s4, $s5, $zero
/* CEAA0 801383A0 02A0982D */  daddu     $s3, $s5, $zero
glabel L801383A4_CEAA4
/* CEAA4 801383A4 24110001 */  addiu     $s1, $zero, 1
/* CEAA8 801383A8 0804E11B */  j         .L8013846C
/* CEAAC 801383AC 24120032 */   addiu    $s2, $zero, 0x32
glabel L801383B0_CEAB0
/* CEAB0 801383B0 0000202D */  daddu     $a0, $zero, $zero
/* CEAB4 801383B4 0C04E035 */  jal       set_transition_stencil_alpha
/* CEAB8 801383B8 0000282D */   daddu    $a1, $zero, $zero
/* CEABC 801383BC 0804E11B */  j         .L8013846C
/* CEAC0 801383C0 24110004 */   addiu    $s1, $zero, 4
glabel L801383C4_CEAC4
/* CEAC4 801383C4 241500D0 */  addiu     $s5, $zero, 0xd0
/* CEAC8 801383C8 02A0A02D */  daddu     $s4, $s5, $zero
/* CEACC 801383CC 02A0982D */  daddu     $s3, $s5, $zero
glabel L801383D0_CEAD0
/* CEAD0 801383D0 0000202D */  daddu     $a0, $zero, $zero
/* CEAD4 801383D4 0C04E035 */  jal       set_transition_stencil_alpha
/* CEAD8 801383D8 0000282D */   daddu    $a1, $zero, $zero
/* CEADC 801383DC 24110004 */  addiu     $s1, $zero, 4
/* CEAE0 801383E0 0804E11B */  j         .L8013846C
/* CEAE4 801383E4 24120007 */   addiu    $s2, $zero, 7
glabel L801383E8_CEAE8
/* CEAE8 801383E8 0000202D */  daddu     $a0, $zero, $zero
/* CEAEC 801383EC 3C054320 */  lui       $a1, 0x4320
/* CEAF0 801383F0 241500D0 */  addiu     $s5, $zero, 0xd0
/* CEAF4 801383F4 02A0A02D */  daddu     $s4, $s5, $zero
/* CEAF8 801383F8 02A0982D */  daddu     $s3, $s5, $zero
/* CEAFC 801383FC 24110005 */  addiu     $s1, $zero, 5
/* CEB00 80138400 0C04E035 */  jal       set_transition_stencil_alpha
/* CEB04 80138404 24120007 */   addiu    $s2, $zero, 7
/* CEB08 80138408 0804E11B */  j         .L8013846C
/* CEB0C 8013840C 00000000 */   nop
glabel L80138410_CEB10
/* CEB10 80138410 0000202D */  daddu     $a0, $zero, $zero
/* CEB14 80138414 0C04E035 */  jal       set_transition_stencil_alpha
/* CEB18 80138418 0000282D */   daddu    $a1, $zero, $zero
/* CEB1C 8013841C 24110005 */  addiu     $s1, $zero, 5
/* CEB20 80138420 0804E11B */  j         .L8013846C
/* CEB24 80138424 24120007 */   addiu    $s2, $zero, 7
glabel L80138428_CEB28
/* CEB28 80138428 0000202D */  daddu     $a0, $zero, $zero
/* CEB2C 8013842C 0080282D */  daddu     $a1, $a0, $zero
/* CEB30 80138430 2406000F */  addiu     $a2, $zero, 0xf
/* CEB34 80138434 0C04DF93 */  jal       set_transition_stencil_center
/* CEB38 80138438 2407001C */   addiu    $a3, $zero, 0x1c
/* CEB3C 8013843C 0000202D */  daddu     $a0, $zero, $zero
/* CEB40 80138440 24050001 */  addiu     $a1, $zero, 1
/* CEB44 80138444 24060131 */  addiu     $a2, $zero, 0x131
/* CEB48 80138448 0C04DF93 */  jal       set_transition_stencil_center
/* CEB4C 8013844C 2407009C */   addiu    $a3, $zero, 0x9c
/* CEB50 80138450 3C05437F */  lui       $a1, 0x437f
/* CEB54 80138454 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* CEB58 80138458 2404000C */   addiu    $a0, $zero, 0xc
/* CEB5C 8013845C 24020001 */  addiu     $v0, $zero, 1
/* CEB60 80138460 240300FF */  addiu     $v1, $zero, 0xff
/* CEB64 80138464 0804E16B */  j         .L801385AC
/* CEB68 80138468 A6C30000 */   sh       $v1, ($s6)
.L8013846C:
/* CEB6C 8013846C 3C038015 */  lui       $v1, %hi(D_8014C6F0)
/* CEB70 80138470 8C63C6F0 */  lw        $v1, %lo(D_8014C6F0)($v1)
/* CEB74 80138474 24020005 */  addiu     $v0, $zero, 5
/* CEB78 80138478 14620025 */  bne       $v1, $v0, .L80138510
/* CEB7C 8013847C 0000802D */   daddu    $s0, $zero, $zero
/* CEB80 80138480 3C048080 */  lui       $a0, 0x8080
/* CEB84 80138484 34848081 */  ori       $a0, $a0, 0x8081
/* CEB88 80138488 86C30000 */  lh        $v1, ($s6)
/* CEB8C 8013848C 241000FF */  addiu     $s0, $zero, 0xff
/* CEB90 80138490 02031823 */  subu      $v1, $s0, $v1
/* CEB94 80138494 00031040 */  sll       $v0, $v1, 1
/* CEB98 80138498 00431021 */  addu      $v0, $v0, $v1
/* CEB9C 8013849C 00021080 */  sll       $v0, $v0, 2
/* CEBA0 801384A0 00431021 */  addu      $v0, $v0, $v1
/* CEBA4 801384A4 00021100 */  sll       $v0, $v0, 4
/* CEBA8 801384A8 00440018 */  mult      $v0, $a0
/* CEBAC 801384AC 0000202D */  daddu     $a0, $zero, $zero
/* CEBB0 801384B0 00004010 */  mfhi      $t0
/* CEBB4 801384B4 01022821 */  addu      $a1, $t0, $v0
/* CEBB8 801384B8 000529C3 */  sra       $a1, $a1, 7
/* CEBBC 801384BC 000217C3 */  sra       $v0, $v0, 0x1f
/* CEBC0 801384C0 00A22823 */  subu      $a1, $a1, $v0
/* CEBC4 801384C4 30A500FF */  andi      $a1, $a1, 0xff
/* CEBC8 801384C8 00A0302D */  daddu     $a2, $a1, $zero
/* CEBCC 801384CC 0C04DF84 */  jal       set_transition_stencil_color
/* CEBD0 801384D0 00A0382D */   daddu    $a3, $a1, $zero
/* CEBD4 801384D4 3C05437F */  lui       $a1, 0x437f
/* CEBD8 801384D8 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* CEBDC 801384DC 0220202D */   daddu    $a0, $s1, $zero
/* CEBE0 801384E0 86C20000 */  lh        $v0, ($s6)
/* CEBE4 801384E4 96C30000 */  lhu       $v1, ($s6)
/* CEBE8 801384E8 10500027 */  beq       $v0, $s0, .L80138588
/* CEBEC 801384EC 00721021 */   addu     $v0, $v1, $s2
/* CEBF0 801384F0 A6C20000 */  sh        $v0, ($s6)
/* CEBF4 801384F4 00021400 */  sll       $v0, $v0, 0x10
/* CEBF8 801384F8 00021403 */  sra       $v0, $v0, 0x10
/* CEBFC 801384FC 28420100 */  slti      $v0, $v0, 0x100
/* CEC00 80138500 50400029 */  beql      $v0, $zero, .L801385A8
/* CEC04 80138504 A6D00000 */   sh       $s0, ($s6)
/* CEC08 80138508 0804E16B */  j         .L801385AC
/* CEC0C 8013850C 0000102D */   daddu    $v0, $zero, $zero
.L80138510:
/* CEC10 80138510 00108400 */  sll       $s0, $s0, 0x10
/* CEC14 80138514 00108403 */  sra       $s0, $s0, 0x10
/* CEC18 80138518 0200202D */  daddu     $a0, $s0, $zero
/* CEC1C 8013851C 0260282D */  daddu     $a1, $s3, $zero
/* CEC20 80138520 0280302D */  daddu     $a2, $s4, $zero
/* CEC24 80138524 0C04DF84 */  jal       set_transition_stencil_color
/* CEC28 80138528 02A0382D */   daddu    $a3, $s5, $zero
/* CEC2C 8013852C 1600000A */  bnez      $s0, .L80138558
/* CEC30 80138530 00000000 */   nop
/* CEC34 80138534 86C20000 */  lh        $v0, ($s6)
/* CEC38 80138538 44820000 */  mtc1      $v0, $f0
/* CEC3C 8013853C 00000000 */  nop
/* CEC40 80138540 46800020 */  cvt.s.w   $f0, $f0
/* CEC44 80138544 44050000 */  mfc1      $a1, $f0
/* CEC48 80138548 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* CEC4C 8013854C 0220202D */   daddu    $a0, $s1, $zero
/* CEC50 80138550 0804E15E */  j         .L80138578
/* CEC54 80138554 240400FF */   addiu    $a0, $zero, 0xff
.L80138558:
/* CEC58 80138558 86C20000 */  lh        $v0, ($s6)
/* CEC5C 8013855C 44820000 */  mtc1      $v0, $f0
/* CEC60 80138560 00000000 */  nop
/* CEC64 80138564 46800020 */  cvt.s.w   $f0, $f0
/* CEC68 80138568 44050000 */  mfc1      $a1, $f0
/* CEC6C 8013856C 0C04DF69 */  jal       set_transition_stencil_zoom_1
/* CEC70 80138570 0220202D */   daddu    $a0, $s1, $zero
/* CEC74 80138574 240400FF */  addiu     $a0, $zero, 0xff
.L80138578:
/* CEC78 80138578 86C20000 */  lh        $v0, ($s6)
/* CEC7C 8013857C 96C30000 */  lhu       $v1, ($s6)
/* CEC80 80138580 14440003 */  bne       $v0, $a0, .L80138590
/* CEC84 80138584 00721021 */   addu     $v0, $v1, $s2
.L80138588:
/* CEC88 80138588 0804E16B */  j         .L801385AC
/* CEC8C 8013858C 24020001 */   addiu    $v0, $zero, 1
.L80138590:
/* CEC90 80138590 A6C20000 */  sh        $v0, ($s6)
/* CEC94 80138594 00021400 */  sll       $v0, $v0, 0x10
/* CEC98 80138598 00021403 */  sra       $v0, $v0, 0x10
/* CEC9C 8013859C 28420100 */  slti      $v0, $v0, 0x100
/* CECA0 801385A0 50400001 */  beql      $v0, $zero, .L801385A8
/* CECA4 801385A4 A6C40000 */   sh       $a0, ($s6)
.L801385A8:
/* CECA8 801385A8 0000102D */  daddu     $v0, $zero, $zero
.L801385AC:
/* CECAC 801385AC 8FBF002C */  lw        $ra, 0x2c($sp)
/* CECB0 801385B0 8FB60028 */  lw        $s6, 0x28($sp)
/* CECB4 801385B4 8FB50024 */  lw        $s5, 0x24($sp)
/* CECB8 801385B8 8FB40020 */  lw        $s4, 0x20($sp)
/* CECBC 801385BC 8FB3001C */  lw        $s3, 0x1c($sp)
/* CECC0 801385C0 8FB20018 */  lw        $s2, 0x18($sp)
/* CECC4 801385C4 8FB10014 */  lw        $s1, 0x14($sp)
/* CECC8 801385C8 8FB00010 */  lw        $s0, 0x10($sp)
/* CECCC 801385CC 03E00008 */  jr        $ra
/* CECD0 801385D0 27BD0030 */   addiu    $sp, $sp, 0x30
