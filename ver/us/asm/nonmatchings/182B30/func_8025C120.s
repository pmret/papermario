.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025C120
/* 18AA00 8025C120 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 18AA04 8025C124 AFB40028 */  sw        $s4, 0x28($sp)
/* 18AA08 8025C128 0080A02D */  daddu     $s4, $a0, $zero
/* 18AA0C 8025C12C AFB30024 */  sw        $s3, 0x24($sp)
/* 18AA10 8025C130 00A0982D */  daddu     $s3, $a1, $zero
/* 18AA14 8025C134 AFB5002C */  sw        $s5, 0x2c($sp)
/* 18AA18 8025C138 00C0A82D */  daddu     $s5, $a2, $zero
/* 18AA1C 8025C13C AFBF0038 */  sw        $ra, 0x38($sp)
/* 18AA20 8025C140 AFB70034 */  sw        $s7, 0x34($sp)
/* 18AA24 8025C144 AFB60030 */  sw        $s6, 0x30($sp)
/* 18AA28 8025C148 AFB20020 */  sw        $s2, 0x20($sp)
/* 18AA2C 8025C14C AFB1001C */  sw        $s1, 0x1c($sp)
/* 18AA30 8025C150 AFB00018 */  sw        $s0, 0x18($sp)
/* 18AA34 8025C154 8E7000C0 */  lw        $s0, 0xc0($s3)
/* 18AA38 8025C158 820206C1 */  lb        $v0, 0x6c1($s0)
/* 18AA3C 8025C15C 8FB20050 */  lw        $s2, 0x50($sp)
/* 18AA40 8025C160 10400055 */  beqz      $v0, .L8025C2B8
/* 18AA44 8025C164 00E0B02D */   daddu    $s6, $a3, $zero
/* 18AA48 8025C168 16800016 */  bnez      $s4, .L8025C1C4
/* 18AA4C 8025C16C 00000000 */   nop
/* 18AA50 8025C170 0C0B7830 */  jal       spr_get_player_palettes
/* 18AA54 8025C174 96640088 */   lhu      $a0, 0x88($s3)
/* 18AA58 8025C178 AE0206D0 */  sw        $v0, 0x6d0($s0)
/* 18AA5C 8025C17C 0040202D */  daddu     $a0, $v0, $zero
/* 18AA60 8025C180 A20006CD */  sb        $zero, 0x6cd($s0)
/* 18AA64 8025C184 8C830000 */  lw        $v1, ($a0)
/* 18AA68 8025C188 2402FFFF */  addiu     $v0, $zero, -1
/* 18AA6C 8025C18C 10620023 */  beq       $v1, $v0, .L8025C21C
/* 18AA70 8025C190 0080182D */   daddu    $v1, $a0, $zero
/* 18AA74 8025C194 0040202D */  daddu     $a0, $v0, $zero
.L8025C198:
/* 18AA78 8025C198 920206CD */  lbu       $v0, 0x6cd($s0)
/* 18AA7C 8025C19C 24420001 */  addiu     $v0, $v0, 1
/* 18AA80 8025C1A0 A20206CD */  sb        $v0, 0x6cd($s0)
/* 18AA84 8025C1A4 00021600 */  sll       $v0, $v0, 0x18
/* 18AA88 8025C1A8 00021583 */  sra       $v0, $v0, 0x16
/* 18AA8C 8025C1AC 00431021 */  addu      $v0, $v0, $v1
/* 18AA90 8025C1B0 8C420000 */  lw        $v0, ($v0)
/* 18AA94 8025C1B4 10440019 */  beq       $v0, $a0, .L8025C21C
/* 18AA98 8025C1B8 00000000 */   nop
/* 18AA9C 8025C1BC 08097066 */  j         .L8025C198
/* 18AAA0 8025C1C0 00000000 */   nop
.L8025C1C4:
/* 18AAA4 8025C1C4 0C0B7A90 */  jal       spr_get_npc_palettes
/* 18AAA8 8025C1C8 96640088 */   lhu      $a0, 0x88($s3)
/* 18AAAC 8025C1CC AE0206D0 */  sw        $v0, 0x6d0($s0)
/* 18AAB0 8025C1D0 0040202D */  daddu     $a0, $v0, $zero
/* 18AAB4 8025C1D4 A20006CD */  sb        $zero, 0x6cd($s0)
/* 18AAB8 8025C1D8 8C830000 */  lw        $v1, ($a0)
/* 18AABC 8025C1DC 2402FFFF */  addiu     $v0, $zero, -1
/* 18AAC0 8025C1E0 1062000B */  beq       $v1, $v0, .L8025C210
/* 18AAC4 8025C1E4 0080182D */   daddu    $v1, $a0, $zero
/* 18AAC8 8025C1E8 0040202D */  daddu     $a0, $v0, $zero
.L8025C1EC:
/* 18AACC 8025C1EC 920206CD */  lbu       $v0, 0x6cd($s0)
/* 18AAD0 8025C1F0 24420001 */  addiu     $v0, $v0, 1
/* 18AAD4 8025C1F4 A20206CD */  sb        $v0, 0x6cd($s0)
/* 18AAD8 8025C1F8 00021600 */  sll       $v0, $v0, 0x18
/* 18AADC 8025C1FC 00021583 */  sra       $v0, $v0, 0x16
/* 18AAE0 8025C200 00431021 */  addu      $v0, $v0, $v1
/* 18AAE4 8025C204 8C420000 */  lw        $v0, ($v0)
/* 18AAE8 8025C208 1444FFF8 */  bne       $v0, $a0, .L8025C1EC
/* 18AAEC 8025C20C 00000000 */   nop
.L8025C210:
/* 18AAF0 8025C210 0C0B7A9B */  jal       spr_get_npc_color_variations
/* 18AAF4 8025C214 96640088 */   lhu      $a0, 0x88($s3)
/* 18AAF8 8025C218 A20206CC */  sb        $v0, 0x6cc($s0)
.L8025C21C:
/* 18AAFC 8025C21C 820306C1 */  lb        $v1, 0x6c1($s0)
/* 18AB00 8025C220 24020001 */  addiu     $v0, $zero, 1
/* 18AB04 8025C224 14620004 */  bne       $v1, $v0, .L8025C238
/* 18AB08 8025C228 240200FF */   addiu    $v0, $zero, 0xff
/* 18AB0C 8025C22C A20006C2 */  sb        $zero, 0x6c2($s0)
/* 18AB10 8025C230 08097090 */  j         .L8025C240
/* 18AB14 8025C234 A60006CA */   sh       $zero, 0x6ca($s0)
.L8025C238:
/* 18AB18 8025C238 A20006C2 */  sb        $zero, 0x6c2($s0)
/* 18AB1C 8025C23C A60206CA */  sh        $v0, 0x6ca($s0)
.L8025C240:
/* 18AB20 8025C240 820206CD */  lb        $v0, 0x6cd($s0)
/* 18AB24 8025C244 18400017 */  blez      $v0, .L8025C2A4
/* 18AB28 8025C248 0000602D */   daddu    $t4, $zero, $zero
/* 18AB2C 8025C24C 0200202D */  daddu     $a0, $s0, $zero
.L8025C250:
/* 18AB30 8025C250 8E0206D0 */  lw        $v0, 0x6d0($s0)
/* 18AB34 8025C254 000C1880 */  sll       $v1, $t4, 2
/* 18AB38 8025C258 00621821 */  addu      $v1, $v1, $v0
/* 18AB3C 8025C25C 000C1140 */  sll       $v0, $t4, 5
/* 18AB40 8025C260 8C6B0000 */  lw        $t3, ($v1)
/* 18AB44 8025C264 02024821 */  addu      $t1, $s0, $v0
/* 18AB48 8025C268 11600009 */  beqz      $t3, .L8025C290
/* 18AB4C 8025C26C AC8906D4 */   sw       $t1, 0x6d4($a0)
/* 18AB50 8025C270 0000502D */  daddu     $t2, $zero, $zero
.L8025C274:
/* 18AB54 8025C274 95620000 */  lhu       $v0, ($t3)
/* 18AB58 8025C278 256B0002 */  addiu     $t3, $t3, 2
/* 18AB5C 8025C27C 254A0001 */  addiu     $t2, $t2, 1
/* 18AB60 8025C280 A5220000 */  sh        $v0, ($t1)
/* 18AB64 8025C284 29420010 */  slti      $v0, $t2, 0x10
/* 18AB68 8025C288 1440FFFA */  bnez      $v0, .L8025C274
/* 18AB6C 8025C28C 25290002 */   addiu    $t1, $t1, 2
.L8025C290:
/* 18AB70 8025C290 820206CD */  lb        $v0, 0x6cd($s0)
/* 18AB74 8025C294 258C0001 */  addiu     $t4, $t4, 1
/* 18AB78 8025C298 0182102A */  slt       $v0, $t4, $v0
/* 18AB7C 8025C29C 1440FFEC */  bnez      $v0, .L8025C250
/* 18AB80 8025C2A0 24840004 */   addiu    $a0, $a0, 4
.L8025C2A4:
/* 18AB84 8025C2A4 96020744 */  lhu       $v0, 0x744($s0)
/* 18AB88 8025C2A8 A60006CA */  sh        $zero, 0x6ca($s0)
/* 18AB8C 8025C2AC A20006C2 */  sb        $zero, 0x6c2($s0)
/* 18AB90 8025C2B0 A20006C1 */  sb        $zero, 0x6c1($s0)
/* 18AB94 8025C2B4 A60206C8 */  sh        $v0, 0x6c8($s0)
.L8025C2B8:
/* 18AB98 8025C2B8 820306C2 */  lb        $v1, 0x6c2($s0)
/* 18AB9C 8025C2BC 10600005 */  beqz      $v1, .L8025C2D4
/* 18ABA0 8025C2C0 24020001 */   addiu    $v0, $zero, 1
/* 18ABA4 8025C2C4 1062000E */  beq       $v1, $v0, .L8025C300
/* 18ABA8 8025C2C8 24020002 */   addiu    $v0, $zero, 2
/* 18ABAC 8025C2CC 08097156 */  j         .L8025C558
/* 18ABB0 8025C2D0 00000000 */   nop
.L8025C2D4:
/* 18ABB4 8025C2D4 1640009E */  bnez      $s2, .L8025C550
/* 18ABB8 8025C2D8 00000000 */   nop
/* 18ABBC 8025C2DC 860206C8 */  lh        $v0, 0x6c8($s0)
/* 18ABC0 8025C2E0 960306C8 */  lhu       $v1, 0x6c8($s0)
/* 18ABC4 8025C2E4 10400003 */  beqz      $v0, .L8025C2F4
/* 18ABC8 8025C2E8 2462FFFF */   addiu    $v0, $v1, -1
/* 18ABCC 8025C2EC 08097154 */  j         .L8025C550
/* 18ABD0 8025C2F0 A60206C8 */   sh       $v0, 0x6c8($s0)
.L8025C2F4:
/* 18ABD4 8025C2F4 24020001 */  addiu     $v0, $zero, 1
/* 18ABD8 8025C2F8 A60006CA */  sh        $zero, 0x6ca($s0)
/* 18ABDC 8025C2FC A20206C2 */  sb        $v0, 0x6c2($s0)
.L8025C300:
/* 18ABE0 8025C300 16400018 */  bnez      $s2, .L8025C364
/* 18ABE4 8025C304 3C0451EB */   lui      $a0, 0x51eb
/* 18ABE8 8025C308 86020746 */  lh        $v0, 0x746($s0)
/* 18ABEC 8025C30C 24036400 */  addiu     $v1, $zero, 0x6400
/* 18ABF0 8025C310 14400002 */  bnez      $v0, .L8025C31C
/* 18ABF4 8025C314 0062001A */   div      $zero, $v1, $v0
/* 18ABF8 8025C318 0007000D */  break     7
.L8025C31C:
/* 18ABFC 8025C31C 2401FFFF */   addiu    $at, $zero, -1
/* 18AC00 8025C320 14410004 */  bne       $v0, $at, .L8025C334
/* 18AC04 8025C324 3C018000 */   lui      $at, 0x8000
/* 18AC08 8025C328 14610002 */  bne       $v1, $at, .L8025C334
/* 18AC0C 8025C32C 00000000 */   nop
/* 18AC10 8025C330 0006000D */  break     6
.L8025C334:
/* 18AC14 8025C334 00001812 */   mflo     $v1
/* 18AC18 8025C338 960206CA */  lhu       $v0, 0x6ca($s0)
/* 18AC1C 8025C33C 00431021 */  addu      $v0, $v0, $v1
/* 18AC20 8025C340 A60206CA */  sh        $v0, 0x6ca($s0)
/* 18AC24 8025C344 00021400 */  sll       $v0, $v0, 0x10
/* 18AC28 8025C348 00021403 */  sra       $v0, $v0, 0x10
/* 18AC2C 8025C34C 2842639D */  slti      $v0, $v0, 0x639d
/* 18AC30 8025C350 14400005 */  bnez      $v0, .L8025C368
/* 18AC34 8025C354 3484851F */   ori      $a0, $a0, 0x851f
/* 18AC38 8025C358 2402639C */  addiu     $v0, $zero, 0x639c
/* 18AC3C 8025C35C A60206CA */  sh        $v0, 0x6ca($s0)
/* 18AC40 8025C360 3C0451EB */  lui       $a0, 0x51eb
.L8025C364:
/* 18AC44 8025C364 3484851F */  ori       $a0, $a0, 0x851f
.L8025C368:
/* 18AC48 8025C368 960306CA */  lhu       $v1, 0x6ca($s0)
/* 18AC4C 8025C36C 00031C00 */  sll       $v1, $v1, 0x10
/* 18AC50 8025C370 00031403 */  sra       $v0, $v1, 0x10
/* 18AC54 8025C374 00440018 */  mult      $v0, $a0
/* 18AC58 8025C378 0000602D */  daddu     $t4, $zero, $zero
/* 18AC5C 8025C37C 920506CC */  lbu       $a1, 0x6cc($s0)
/* 18AC60 8025C380 00031FC3 */  sra       $v1, $v1, 0x1f
/* 18AC64 8025C384 820206CC */  lb        $v0, 0x6cc($s0)
/* 18AC68 8025C388 0000B810 */  mfhi      $s7
/* 18AC6C 8025C38C 00172143 */  sra       $a0, $s7, 5
/* 18AC70 8025C390 18400068 */  blez      $v0, .L8025C534
/* 18AC74 8025C394 00838823 */   subu     $s1, $a0, $v1
/* 18AC78 8025C398 322E00FF */  andi      $t6, $s1, 0xff
/* 18AC7C 8025C39C 240200FF */  addiu     $v0, $zero, 0xff
/* 18AC80 8025C3A0 004EC023 */  subu      $t8, $v0, $t6
/* 18AC84 8025C3A4 3C0F8080 */  lui       $t7, 0x8080
/* 18AC88 8025C3A8 35EF8081 */  ori       $t7, $t7, 0x8081
/* 18AC8C 8025C3AC 0200C82D */  daddu     $t9, $s0, $zero
.L8025C3B0:
/* 18AC90 8025C3B0 00052600 */  sll       $a0, $a1, 0x18
/* 18AC94 8025C3B4 86020740 */  lh        $v0, 0x740($s0)
/* 18AC98 8025C3B8 00042603 */  sra       $a0, $a0, 0x18
/* 18AC9C 8025C3BC 00440018 */  mult      $v0, $a0
/* 18ACA0 8025C3C0 86030742 */  lh        $v1, 0x742($s0)
/* 18ACA4 8025C3C4 000C1140 */  sll       $v0, $t4, 5
/* 18ACA8 8025C3C8 0000B812 */  mflo      $s7
/* 18ACAC 8025C3CC 02026821 */  addu      $t5, $s0, $v0
/* 18ACB0 8025C3D0 02EC1021 */  addu      $v0, $s7, $t4
/* 18ACB4 8025C3D4 00640018 */  mult      $v1, $a0
/* 18ACB8 8025C3D8 8E0306D0 */  lw        $v1, 0x6d0($s0)
/* 18ACBC 8025C3DC 00021080 */  sll       $v0, $v0, 2
/* 18ACC0 8025C3E0 00431021 */  addu      $v0, $v0, $v1
/* 18ACC4 8025C3E4 8C4B0000 */  lw        $t3, ($v0)
/* 18ACC8 8025C3E8 0000B812 */  mflo      $s7
/* 18ACCC 8025C3EC 02EC1021 */  addu      $v0, $s7, $t4
/* 18ACD0 8025C3F0 00021080 */  sll       $v0, $v0, 2
/* 18ACD4 8025C3F4 00431021 */  addu      $v0, $v0, $v1
/* 18ACD8 8025C3F8 8C490000 */  lw        $t1, ($v0)
/* 18ACDC 8025C3FC 0000502D */  daddu     $t2, $zero, $zero
/* 18ACE0 8025C400 AF2D06D4 */  sw        $t5, 0x6d4($t9)
.L8025C404:
/* 18ACE4 8025C404 95630000 */  lhu       $v1, ($t3)
/* 18ACE8 8025C408 000312C2 */  srl       $v0, $v1, 0xb
/* 18ACEC 8025C40C 00580018 */  mult      $v0, $t8
/* 18ACF0 8025C410 95240000 */  lhu       $a0, ($t1)
/* 18ACF4 8025C414 00002812 */  mflo      $a1
/* 18ACF8 8025C418 000412C2 */  srl       $v0, $a0, 0xb
/* 18ACFC 8025C41C 00000000 */  nop
/* 18AD00 8025C420 004E0018 */  mult      $v0, $t6
/* 18AD04 8025C424 00004012 */  mflo      $t0
/* 18AD08 8025C428 00A82821 */  addu      $a1, $a1, $t0
/* 18AD0C 8025C42C 00000000 */  nop
/* 18AD10 8025C430 00AF0018 */  mult      $a1, $t7
/* 18AD14 8025C434 0000B810 */  mfhi      $s7
/* 18AD18 8025C438 00031182 */  srl       $v0, $v1, 6
/* 18AD1C 8025C43C 3042001F */  andi      $v0, $v0, 0x1f
/* 18AD20 8025C440 00580018 */  mult      $v0, $t8
/* 18AD24 8025C444 00004012 */  mflo      $t0
/* 18AD28 8025C448 00041182 */  srl       $v0, $a0, 6
/* 18AD2C 8025C44C 3042001F */  andi      $v0, $v0, 0x1f
/* 18AD30 8025C450 004E0018 */  mult      $v0, $t6
/* 18AD34 8025C454 00003812 */  mflo      $a3
/* 18AD38 8025C458 00031842 */  srl       $v1, $v1, 1
/* 18AD3C 8025C45C 3063001F */  andi      $v1, $v1, 0x1f
/* 18AD40 8025C460 00780018 */  mult      $v1, $t8
/* 18AD44 8025C464 256B0002 */  addiu     $t3, $t3, 2
/* 18AD48 8025C468 254A0001 */  addiu     $t2, $t2, 1
/* 18AD4C 8025C46C 00042042 */  srl       $a0, $a0, 1
/* 18AD50 8025C470 00001812 */  mflo      $v1
/* 18AD54 8025C474 3084001F */  andi      $a0, $a0, 0x1f
/* 18AD58 8025C478 AFB70010 */  sw        $s7, 0x10($sp)
/* 18AD5C 8025C47C 008E0018 */  mult      $a0, $t6
/* 18AD60 8025C480 91260001 */  lbu       $a2, 1($t1)
/* 18AD64 8025C484 25290002 */  addiu     $t1, $t1, 2
/* 18AD68 8025C488 30C60001 */  andi      $a2, $a2, 1
/* 18AD6C 8025C48C 01072021 */  addu      $a0, $t0, $a3
/* 18AD70 8025C490 0000B812 */  mflo      $s7
/* 18AD74 8025C494 AFB70014 */  sw        $s7, 0x14($sp)
/* 18AD78 8025C498 8FB70010 */  lw        $s7, 0x10($sp)
/* 18AD7C 8025C49C 008F0018 */  mult      $a0, $t7
/* 18AD80 8025C4A0 02E51021 */  addu      $v0, $s7, $a1
/* 18AD84 8025C4A4 000211C3 */  sra       $v0, $v0, 7
/* 18AD88 8025C4A8 00052FC3 */  sra       $a1, $a1, 0x1f
/* 18AD8C 8025C4AC 8FB70014 */  lw        $s7, 0x14($sp)
/* 18AD90 8025C4B0 00004010 */  mfhi      $t0
/* 18AD94 8025C4B4 00453823 */  subu      $a3, $v0, $a1
/* 18AD98 8025C4B8 00771821 */  addu      $v1, $v1, $s7
/* 18AD9C 8025C4BC 006F0018 */  mult      $v1, $t7
/* 18ADA0 8025C4C0 01041021 */  addu      $v0, $t0, $a0
/* 18ADA4 8025C4C4 000211C3 */  sra       $v0, $v0, 7
/* 18ADA8 8025C4C8 000427C3 */  sra       $a0, $a0, 0x1f
/* 18ADAC 8025C4CC 00442823 */  subu      $a1, $v0, $a0
/* 18ADB0 8025C4D0 0000B810 */  mfhi      $s7
/* 18ADB4 8025C4D4 AFB70010 */  sw        $s7, 0x10($sp)
/* 18ADB8 8025C4D8 02E31021 */  addu      $v0, $s7, $v1
/* 18ADBC 8025C4DC 000211C3 */  sra       $v0, $v0, 7
/* 18ADC0 8025C4E0 00031FC3 */  sra       $v1, $v1, 0x1f
/* 18ADC4 8025C4E4 00432023 */  subu      $a0, $v0, $v1
/* 18ADC8 8025C4E8 30E300FF */  andi      $v1, $a3, 0xff
/* 18ADCC 8025C4EC 00031AC0 */  sll       $v1, $v1, 0xb
/* 18ADD0 8025C4F0 30A200FF */  andi      $v0, $a1, 0xff
/* 18ADD4 8025C4F4 00021180 */  sll       $v0, $v0, 6
/* 18ADD8 8025C4F8 00621825 */  or        $v1, $v1, $v0
/* 18ADDC 8025C4FC 308200FF */  andi      $v0, $a0, 0xff
/* 18ADE0 8025C500 00021040 */  sll       $v0, $v0, 1
/* 18ADE4 8025C504 00621825 */  or        $v1, $v1, $v0
/* 18ADE8 8025C508 00C33025 */  or        $a2, $a2, $v1
/* 18ADEC 8025C50C A5A60000 */  sh        $a2, ($t5)
/* 18ADF0 8025C510 29420010 */  slti      $v0, $t2, 0x10
/* 18ADF4 8025C514 1440FFBB */  bnez      $v0, .L8025C404
/* 18ADF8 8025C518 25AD0002 */   addiu    $t5, $t5, 2
/* 18ADFC 8025C51C 258C0001 */  addiu     $t4, $t4, 1
/* 18AE00 8025C520 820206CC */  lb        $v0, 0x6cc($s0)
/* 18AE04 8025C524 920506CC */  lbu       $a1, 0x6cc($s0)
/* 18AE08 8025C528 0182102A */  slt       $v0, $t4, $v0
/* 18AE0C 8025C52C 1440FFA0 */  bnez      $v0, .L8025C3B0
/* 18AE10 8025C530 27390004 */   addiu    $t9, $t9, 4
.L8025C534:
/* 18AE14 8025C534 322300FF */  andi      $v1, $s1, 0xff
/* 18AE18 8025C538 240200FF */  addiu     $v0, $zero, 0xff
/* 18AE1C 8025C53C 14620004 */  bne       $v1, $v0, .L8025C550
/* 18AE20 8025C540 24020002 */   addiu    $v0, $zero, 2
/* 18AE24 8025C544 96030748 */  lhu       $v1, 0x748($s0)
/* 18AE28 8025C548 A20206C2 */  sb        $v0, 0x6c2($s0)
/* 18AE2C 8025C54C A60306C8 */  sh        $v1, 0x6c8($s0)
.L8025C550:
/* 18AE30 8025C550 820306C2 */  lb        $v1, 0x6c2($s0)
/* 18AE34 8025C554 24020002 */  addiu     $v0, $zero, 2
.L8025C558:
/* 18AE38 8025C558 10620005 */  beq       $v1, $v0, .L8025C570
/* 18AE3C 8025C55C 24020003 */   addiu    $v0, $zero, 3
/* 18AE40 8025C560 1062000C */  beq       $v1, $v0, .L8025C594
/* 18AE44 8025C564 00000000 */   nop
/* 18AE48 8025C568 080971F5 */  j         .L8025C7D4
/* 18AE4C 8025C56C 00000000 */   nop
.L8025C570:
/* 18AE50 8025C570 16400098 */  bnez      $s2, .L8025C7D4
/* 18AE54 8025C574 00000000 */   nop
/* 18AE58 8025C578 860206C8 */  lh        $v0, 0x6c8($s0)
/* 18AE5C 8025C57C 960306C8 */  lhu       $v1, 0x6c8($s0)
/* 18AE60 8025C580 14400093 */  bnez      $v0, .L8025C7D0
/* 18AE64 8025C584 2462FFFF */   addiu    $v0, $v1, -1
/* 18AE68 8025C588 24020003 */  addiu     $v0, $zero, 3
/* 18AE6C 8025C58C A60006CA */  sh        $zero, 0x6ca($s0)
/* 18AE70 8025C590 A20206C2 */  sb        $v0, 0x6c2($s0)
.L8025C594:
/* 18AE74 8025C594 16400018 */  bnez      $s2, .L8025C5F8
/* 18AE78 8025C598 3C0451EB */   lui      $a0, 0x51eb
/* 18AE7C 8025C59C 8602074A */  lh        $v0, 0x74a($s0)
/* 18AE80 8025C5A0 24036400 */  addiu     $v1, $zero, 0x6400
/* 18AE84 8025C5A4 14400002 */  bnez      $v0, .L8025C5B0
/* 18AE88 8025C5A8 0062001A */   div      $zero, $v1, $v0
/* 18AE8C 8025C5AC 0007000D */  break     7
.L8025C5B0:
/* 18AE90 8025C5B0 2401FFFF */   addiu    $at, $zero, -1
/* 18AE94 8025C5B4 14410004 */  bne       $v0, $at, .L8025C5C8
/* 18AE98 8025C5B8 3C018000 */   lui      $at, 0x8000
/* 18AE9C 8025C5BC 14610002 */  bne       $v1, $at, .L8025C5C8
/* 18AEA0 8025C5C0 00000000 */   nop
/* 18AEA4 8025C5C4 0006000D */  break     6
.L8025C5C8:
/* 18AEA8 8025C5C8 00001812 */   mflo     $v1
/* 18AEAC 8025C5CC 960206CA */  lhu       $v0, 0x6ca($s0)
/* 18AEB0 8025C5D0 00431021 */  addu      $v0, $v0, $v1
/* 18AEB4 8025C5D4 A60206CA */  sh        $v0, 0x6ca($s0)
/* 18AEB8 8025C5D8 00021400 */  sll       $v0, $v0, 0x10
/* 18AEBC 8025C5DC 00021403 */  sra       $v0, $v0, 0x10
/* 18AEC0 8025C5E0 2842639D */  slti      $v0, $v0, 0x639d
/* 18AEC4 8025C5E4 14400005 */  bnez      $v0, .L8025C5FC
/* 18AEC8 8025C5E8 3484851F */   ori      $a0, $a0, 0x851f
/* 18AECC 8025C5EC 2402639C */  addiu     $v0, $zero, 0x639c
/* 18AED0 8025C5F0 A60206CA */  sh        $v0, 0x6ca($s0)
/* 18AED4 8025C5F4 3C0451EB */  lui       $a0, 0x51eb
.L8025C5F8:
/* 18AED8 8025C5F8 3484851F */  ori       $a0, $a0, 0x851f
.L8025C5FC:
/* 18AEDC 8025C5FC 960306CA */  lhu       $v1, 0x6ca($s0)
/* 18AEE0 8025C600 00031C00 */  sll       $v1, $v1, 0x10
/* 18AEE4 8025C604 00031403 */  sra       $v0, $v1, 0x10
/* 18AEE8 8025C608 00440018 */  mult      $v0, $a0
/* 18AEEC 8025C60C 0000602D */  daddu     $t4, $zero, $zero
/* 18AEF0 8025C610 920506CC */  lbu       $a1, 0x6cc($s0)
/* 18AEF4 8025C614 00031FC3 */  sra       $v1, $v1, 0x1f
/* 18AEF8 8025C618 820206CC */  lb        $v0, 0x6cc($s0)
/* 18AEFC 8025C61C 0000B810 */  mfhi      $s7
/* 18AF00 8025C620 00172143 */  sra       $a0, $s7, 5
/* 18AF04 8025C624 18400064 */  blez      $v0, .L8025C7B8
/* 18AF08 8025C628 00838823 */   subu     $s1, $a0, $v1
/* 18AF0C 8025C62C 322E00FF */  andi      $t6, $s1, 0xff
/* 18AF10 8025C630 240200FF */  addiu     $v0, $zero, 0xff
/* 18AF14 8025C634 004EC023 */  subu      $t8, $v0, $t6
/* 18AF18 8025C638 3C0F8080 */  lui       $t7, 0x8080
/* 18AF1C 8025C63C 35EF8081 */  ori       $t7, $t7, 0x8081
/* 18AF20 8025C640 0200C82D */  daddu     $t9, $s0, $zero
.L8025C644:
/* 18AF24 8025C644 00052600 */  sll       $a0, $a1, 0x18
/* 18AF28 8025C648 86020740 */  lh        $v0, 0x740($s0)
/* 18AF2C 8025C64C 00042603 */  sra       $a0, $a0, 0x18
/* 18AF30 8025C650 00440018 */  mult      $v0, $a0
/* 18AF34 8025C654 86030742 */  lh        $v1, 0x742($s0)
/* 18AF38 8025C658 000C1140 */  sll       $v0, $t4, 5
/* 18AF3C 8025C65C 0000B812 */  mflo      $s7
/* 18AF40 8025C660 02026821 */  addu      $t5, $s0, $v0
/* 18AF44 8025C664 02EC1021 */  addu      $v0, $s7, $t4
/* 18AF48 8025C668 00640018 */  mult      $v1, $a0
/* 18AF4C 8025C66C 8E0306D0 */  lw        $v1, 0x6d0($s0)
/* 18AF50 8025C670 00021080 */  sll       $v0, $v0, 2
/* 18AF54 8025C674 00431021 */  addu      $v0, $v0, $v1
/* 18AF58 8025C678 8C4B0000 */  lw        $t3, ($v0)
/* 18AF5C 8025C67C 0000B812 */  mflo      $s7
/* 18AF60 8025C680 02EC1021 */  addu      $v0, $s7, $t4
/* 18AF64 8025C684 00021080 */  sll       $v0, $v0, 2
/* 18AF68 8025C688 00431021 */  addu      $v0, $v0, $v1
/* 18AF6C 8025C68C 8C490000 */  lw        $t1, ($v0)
/* 18AF70 8025C690 0000502D */  daddu     $t2, $zero, $zero
/* 18AF74 8025C694 AF2D06D4 */  sw        $t5, 0x6d4($t9)
.L8025C698:
/* 18AF78 8025C698 95630000 */  lhu       $v1, ($t3)
/* 18AF7C 8025C69C 000312C2 */  srl       $v0, $v1, 0xb
/* 18AF80 8025C6A0 00580018 */  mult      $v0, $t8
/* 18AF84 8025C6A4 95240000 */  lhu       $a0, ($t1)
/* 18AF88 8025C6A8 00002812 */  mflo      $a1
/* 18AF8C 8025C6AC 000412C2 */  srl       $v0, $a0, 0xb
/* 18AF90 8025C6B0 00000000 */  nop
/* 18AF94 8025C6B4 004E0018 */  mult      $v0, $t6
/* 18AF98 8025C6B8 00004012 */  mflo      $t0
/* 18AF9C 8025C6BC 00A82821 */  addu      $a1, $a1, $t0
/* 18AFA0 8025C6C0 00000000 */  nop
/* 18AFA4 8025C6C4 00AF0018 */  mult      $a1, $t7
/* 18AFA8 8025C6C8 00009010 */  mfhi      $s2
/* 18AFAC 8025C6CC 00031182 */  srl       $v0, $v1, 6
/* 18AFB0 8025C6D0 3042001F */  andi      $v0, $v0, 0x1f
/* 18AFB4 8025C6D4 00580018 */  mult      $v0, $t8
/* 18AFB8 8025C6D8 00004012 */  mflo      $t0
/* 18AFBC 8025C6DC 00041182 */  srl       $v0, $a0, 6
/* 18AFC0 8025C6E0 3042001F */  andi      $v0, $v0, 0x1f
/* 18AFC4 8025C6E4 004E0018 */  mult      $v0, $t6
/* 18AFC8 8025C6E8 00003812 */  mflo      $a3
/* 18AFCC 8025C6EC 00031842 */  srl       $v1, $v1, 1
/* 18AFD0 8025C6F0 3063001F */  andi      $v1, $v1, 0x1f
/* 18AFD4 8025C6F4 00780018 */  mult      $v1, $t8
/* 18AFD8 8025C6F8 00001812 */  mflo      $v1
/* 18AFDC 8025C6FC 00042042 */  srl       $a0, $a0, 1
/* 18AFE0 8025C700 3084001F */  andi      $a0, $a0, 0x1f
/* 18AFE4 8025C704 008E0018 */  mult      $a0, $t6
/* 18AFE8 8025C708 256B0002 */  addiu     $t3, $t3, 2
/* 18AFEC 8025C70C 91260001 */  lbu       $a2, 1($t1)
/* 18AFF0 8025C710 25290002 */  addiu     $t1, $t1, 2
/* 18AFF4 8025C714 254A0001 */  addiu     $t2, $t2, 1
/* 18AFF8 8025C718 0000B812 */  mflo      $s7
/* 18AFFC 8025C71C 30C60001 */  andi      $a2, $a2, 1
/* 18B000 8025C720 01072021 */  addu      $a0, $t0, $a3
/* 18B004 8025C724 008F0018 */  mult      $a0, $t7
/* 18B008 8025C728 02451021 */  addu      $v0, $s2, $a1
/* 18B00C 8025C72C 000211C3 */  sra       $v0, $v0, 7
/* 18B010 8025C730 00052FC3 */  sra       $a1, $a1, 0x1f
/* 18B014 8025C734 00453823 */  subu      $a3, $v0, $a1
/* 18B018 8025C738 00004010 */  mfhi      $t0
/* 18B01C 8025C73C AFB70014 */  sw        $s7, 0x14($sp)
/* 18B020 8025C740 00771821 */  addu      $v1, $v1, $s7
/* 18B024 8025C744 006F0018 */  mult      $v1, $t7
/* 18B028 8025C748 01041021 */  addu      $v0, $t0, $a0
/* 18B02C 8025C74C 000211C3 */  sra       $v0, $v0, 7
/* 18B030 8025C750 000427C3 */  sra       $a0, $a0, 0x1f
/* 18B034 8025C754 00442823 */  subu      $a1, $v0, $a0
/* 18B038 8025C758 00009010 */  mfhi      $s2
/* 18B03C 8025C75C 02431021 */  addu      $v0, $s2, $v1
/* 18B040 8025C760 000211C3 */  sra       $v0, $v0, 7
/* 18B044 8025C764 00031FC3 */  sra       $v1, $v1, 0x1f
/* 18B048 8025C768 00432023 */  subu      $a0, $v0, $v1
/* 18B04C 8025C76C 30E300FF */  andi      $v1, $a3, 0xff
/* 18B050 8025C770 00031AC0 */  sll       $v1, $v1, 0xb
/* 18B054 8025C774 30A200FF */  andi      $v0, $a1, 0xff
/* 18B058 8025C778 00021180 */  sll       $v0, $v0, 6
/* 18B05C 8025C77C 00621825 */  or        $v1, $v1, $v0
/* 18B060 8025C780 308200FF */  andi      $v0, $a0, 0xff
/* 18B064 8025C784 00021040 */  sll       $v0, $v0, 1
/* 18B068 8025C788 00621825 */  or        $v1, $v1, $v0
/* 18B06C 8025C78C 00C33025 */  or        $a2, $a2, $v1
/* 18B070 8025C790 A5A60000 */  sh        $a2, ($t5)
/* 18B074 8025C794 29420010 */  slti      $v0, $t2, 0x10
/* 18B078 8025C798 1440FFBF */  bnez      $v0, .L8025C698
/* 18B07C 8025C79C 25AD0002 */   addiu    $t5, $t5, 2
/* 18B080 8025C7A0 258C0001 */  addiu     $t4, $t4, 1
/* 18B084 8025C7A4 820206CC */  lb        $v0, 0x6cc($s0)
/* 18B088 8025C7A8 920506CC */  lbu       $a1, 0x6cc($s0)
/* 18B08C 8025C7AC 0182102A */  slt       $v0, $t4, $v0
/* 18B090 8025C7B0 1440FFA4 */  bnez      $v0, .L8025C644
/* 18B094 8025C7B4 27390004 */   addiu    $t9, $t9, 4
.L8025C7B8:
/* 18B098 8025C7B8 322300FF */  andi      $v1, $s1, 0xff
/* 18B09C 8025C7BC 240200FF */  addiu     $v0, $zero, 0xff
/* 18B0A0 8025C7C0 14620004 */  bne       $v1, $v0, .L8025C7D4
/* 18B0A4 8025C7C4 00000000 */   nop
/* 18B0A8 8025C7C8 96020744 */  lhu       $v0, 0x744($s0)
/* 18B0AC 8025C7CC A20006C2 */  sb        $zero, 0x6c2($s0)
.L8025C7D0:
/* 18B0B0 8025C7D0 A60206C8 */  sh        $v0, 0x6c8($s0)
.L8025C7D4:
/* 18B0B4 8025C7D4 820306C2 */  lb        $v1, 0x6c2($s0)
/* 18B0B8 8025C7D8 28620004 */  slti      $v0, $v1, 4
/* 18B0BC 8025C7DC 1040000D */  beqz      $v0, .L8025C814
/* 18B0C0 8025C7E0 00000000 */   nop
/* 18B0C4 8025C7E4 0460000B */  bltz      $v1, .L8025C814
/* 18B0C8 8025C7E8 00000000 */   nop
/* 18B0CC 8025C7EC 16800006 */  bnez      $s4, .L8025C808
/* 18B0D0 8025C7F0 0260202D */   daddu    $a0, $s3, $zero
/* 18B0D4 8025C7F4 02A0282D */  daddu     $a1, $s5, $zero
/* 18B0D8 8025C7F8 0C096657 */  jal       func_8025995C
/* 18B0DC 8025C7FC 02C0302D */   daddu    $a2, $s6, $zero
/* 18B0E0 8025C800 08097205 */  j         .L8025C814
/* 18B0E4 8025C804 00000000 */   nop
.L8025C808:
/* 18B0E8 8025C808 02A0282D */  daddu     $a1, $s5, $zero
/* 18B0EC 8025C80C 0C0965B0 */  jal       func_802596C0
/* 18B0F0 8025C810 02C0302D */   daddu    $a2, $s6, $zero
.L8025C814:
/* 18B0F4 8025C814 8FBF0038 */  lw        $ra, 0x38($sp)
/* 18B0F8 8025C818 8FB70034 */  lw        $s7, 0x34($sp)
/* 18B0FC 8025C81C 8FB60030 */  lw        $s6, 0x30($sp)
/* 18B100 8025C820 8FB5002C */  lw        $s5, 0x2c($sp)
/* 18B104 8025C824 8FB40028 */  lw        $s4, 0x28($sp)
/* 18B108 8025C828 8FB30024 */  lw        $s3, 0x24($sp)
/* 18B10C 8025C82C 8FB20020 */  lw        $s2, 0x20($sp)
/* 18B110 8025C830 8FB1001C */  lw        $s1, 0x1c($sp)
/* 18B114 8025C834 8FB00018 */  lw        $s0, 0x18($sp)
/* 18B118 8025C838 03E00008 */  jr        $ra
/* 18B11C 8025C83C 27BD0040 */   addiu    $sp, $sp, 0x40
