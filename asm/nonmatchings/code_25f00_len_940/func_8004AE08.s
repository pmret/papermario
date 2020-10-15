.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004AE08
/* 26208 8004AE08 27BDFF50 */  addiu     $sp, $sp, -0xb0
/* 2620C 8004AE0C AFB00088 */  sw        $s0, 0x88($sp)
/* 26210 8004AE10 27B00020 */  addiu     $s0, $sp, 0x20
/* 26214 8004AE14 0200202D */  daddu     $a0, $s0, $zero
/* 26218 8004AE18 27A50038 */  addiu     $a1, $sp, 0x38
/* 2621C 8004AE1C 24060008 */  addiu     $a2, $zero, 8
/* 26220 8004AE20 AFBF00AC */  sw        $ra, 0xac($sp)
/* 26224 8004AE24 AFBE00A8 */  sw        $fp, 0xa8($sp)
/* 26228 8004AE28 AFB700A4 */  sw        $s7, 0xa4($sp)
/* 2622C 8004AE2C AFB600A0 */  sw        $s6, 0xa0($sp)
/* 26230 8004AE30 AFB5009C */  sw        $s5, 0x9c($sp)
/* 26234 8004AE34 AFB40098 */  sw        $s4, 0x98($sp)
/* 26238 8004AE38 AFB30094 */  sw        $s3, 0x94($sp)
/* 2623C 8004AE3C AFB20090 */  sw        $s2, 0x90($sp)
/* 26240 8004AE40 0C019560 */  jal       osCreateMesgQueue
/* 26244 8004AE44 AFB1008C */   sw       $s1, 0x8c($sp)
/* 26248 8004AE48 27B10058 */  addiu     $s1, $sp, 0x58
/* 2624C 8004AE4C 0220202D */  daddu     $a0, $s1, $zero
/* 26250 8004AE50 27A50070 */  addiu     $a1, $sp, 0x70
/* 26254 8004AE54 0C019560 */  jal       osCreateMesgQueue
/* 26258 8004AE58 24060001 */   addiu    $a2, $zero, 1
/* 2625C 8004AE5C 27A40010 */  addiu     $a0, $sp, 0x10
/* 26260 8004AE60 0200282D */  daddu     $a1, $s0, $zero
/* 26264 8004AE64 0C017B8C */  jal       nuScAddClient
/* 26268 8004AE68 24060003 */   addiu    $a2, $zero, 3
/* 2626C 8004AE6C 0000902D */  daddu     $s2, $zero, $zero
/* 26270 8004AE70 0240982D */  daddu     $s3, $s2, $zero
/* 26274 8004AE74 0240A82D */  daddu     $s5, $s2, $zero
/* 26278 8004AE78 3C14800A */  lui       $s4, 0x800a
/* 2627C 8004AE7C 8E943510 */  lw        $s4, 0x3510($s4)
/* 26280 8004AE80 3C1E800A */  lui       $fp, 0x800a
/* 26284 8004AE84 8FDE3628 */  lw        $fp, 0x3628($fp)
/* 26288 8004AE88 3C178008 */  lui       $s7, 0x8008
/* 2628C 8004AE8C 26F78170 */  addiu     $s7, $s7, -0x7e90
/* 26290 8004AE90 AFB10080 */  sw        $s1, 0x80($sp)
/* 26294 8004AE94 3C11800A */  lui       $s1, 0x800a
/* 26298 8004AE98 26313520 */  addiu     $s1, $s1, 0x3520
/* 2629C 8004AE9C AFA00078 */  sw        $zero, 0x78($sp)
.L8004AEA0:
/* 262A0 8004AEA0 27A40020 */  addiu     $a0, $sp, 0x20
.L8004AEA4:
/* 262A4 8004AEA4 27A50074 */  addiu     $a1, $sp, 0x74
.L8004AEA8:
/* 262A8 8004AEA8 0C0195BC */  jal       osRecvMesg
/* 262AC 8004AEAC 24060001 */   addiu    $a2, $zero, 1
/* 262B0 8004AEB0 8FA20074 */  lw        $v0, 0x74($sp)
/* 262B4 8004AEB4 84430000 */  lh        $v1, ($v0)
/* 262B8 8004AEB8 24080001 */  addiu     $t0, $zero, 1
/* 262BC 8004AEBC 10680005 */  beq       $v1, $t0, .L8004AED4
/* 262C0 8004AEC0 24020002 */   addiu    $v0, $zero, 2
/* 262C4 8004AEC4 1062005F */  beq       $v1, $v0, .L8004B044
/* 262C8 8004AEC8 27A40020 */   addiu    $a0, $sp, 0x20
/* 262CC 8004AECC 08012BAA */  j         .L8004AEA8
/* 262D0 8004AED0 27A50074 */   addiu    $a1, $sp, 0x74
.L8004AED4:
/* 262D4 8004AED4 8FA20078 */  lw        $v0, 0x78($sp)
/* 262D8 8004AED8 10400021 */  beqz      $v0, .L8004AF60
/* 262DC 8004AEDC 24080001 */   addiu    $t0, $zero, 1
/* 262E0 8004AEE0 3C028008 */  lui       $v0, 0x8008
/* 262E4 8004AEE4 90428180 */  lbu       $v0, -0x7e80($v0)
/* 262E8 8004AEE8 1448001D */  bne       $v0, $t0, .L8004AF60
/* 262EC 8004AEEC 0100302D */   daddu    $a2, $t0, $zero
/* 262F0 8004AEF0 8FA80080 */  lw        $t0, 0x80($sp)
/* 262F4 8004AEF4 3C04800E */  lui       $a0, 0x800e
/* 262F8 8004AEF8 2484A444 */  addiu     $a0, $a0, -0x5bbc
/* 262FC 8004AEFC AE340040 */  sw        $s4, 0x40($s1)
/* 26300 8004AF00 AE280050 */  sw        $t0, 0x50($s1)
/* 26304 8004AF04 8FA8007C */  lw        $t0, 0x7c($sp)
/* 26308 8004AF08 0220282D */  daddu     $a1, $s1, $zero
/* 2630C 8004AF0C 01141023 */  subu      $v0, $t0, $s4
/* 26310 8004AF10 000210C3 */  sra       $v0, $v0, 3
/* 26314 8004AF14 000210C0 */  sll       $v0, $v0, 3
/* 26318 8004AF18 0C019608 */  jal       osSendMesg
/* 2631C 8004AF1C AE220044 */   sw       $v0, 0x44($s1)
/* 26320 8004AF20 0C012C9A */  jal       nuAuCleanDMABuffers
/* 26324 8004AF24 26730001 */   addiu    $s3, $s3, 1
/* 26328 8004AF28 0000282D */  daddu     $a1, $zero, $zero
/* 2632C 8004AF2C 8FA40080 */  lw        $a0, 0x80($sp)
/* 26330 8004AF30 0C0195BC */  jal       osRecvMesg
/* 26334 8004AF34 24060001 */   addiu    $a2, $zero, 1
/* 26338 8004AF38 24080003 */  addiu     $t0, $zero, 3
/* 2633C 8004AF3C 52680001 */  beql      $s3, $t0, .L8004AF44
/* 26340 8004AF40 0000982D */   daddu    $s3, $zero, $zero
.L8004AF44:
/* 26344 8004AF44 26520001 */  addiu     $s2, $s2, 1
/* 26348 8004AF48 24080003 */  addiu     $t0, $zero, 3
/* 2634C 8004AF4C 16480004 */  bne       $s2, $t0, .L8004AF60
/* 26350 8004AF50 26310058 */   addiu    $s1, $s1, 0x58
/* 26354 8004AF54 3C11800A */  lui       $s1, 0x800a
/* 26358 8004AF58 26313520 */  addiu     $s1, $s1, 0x3520
/* 2635C 8004AF5C 0000902D */  daddu     $s2, $zero, $zero
.L8004AF60:
/* 26360 8004AF60 0C018554 */  jal       osAiGetStatus
/* 26364 8004AF64 00000000 */   nop      
/* 26368 8004AF68 04410003 */  bgez      $v0, .L8004AF78
/* 2636C 8004AF6C 00000000 */   nop      
/* 26370 8004AF70 08012BA8 */  j         .L8004AEA0
/* 26374 8004AF74 0000B02D */   daddu    $s6, $zero, $zero
.L8004AF78:
/* 26378 8004AF78 0C018550 */  jal       osAiGetLength
/* 2637C 8004AF7C 00000000 */   nop      
/* 26380 8004AF80 8FA30078 */  lw        $v1, 0x78($sp)
/* 26384 8004AF84 10600011 */  beqz      $v1, .L8004AFCC
/* 26388 8004AF88 00028082 */   srl      $s0, $v0, 2
/* 2638C 8004AF8C 3C028008 */  lui       $v0, 0x8008
/* 26390 8004AF90 90428180 */  lbu       $v0, -0x7e80($v0)
/* 26394 8004AF94 24080001 */  addiu     $t0, $zero, 1
/* 26398 8004AF98 1448000D */  bne       $v0, $t0, .L8004AFD0
/* 2639C 8004AF9C 2A0200B8 */   slti     $v0, $s0, 0xb8
/* 263A0 8004AFA0 03C0202D */  daddu     $a0, $fp, $zero
/* 263A4 8004AFA4 0C0185A0 */  jal       osAiSetNextBuffer
/* 263A8 8004AFA8 00152880 */   sll      $a1, $s5, 2
/* 263AC 8004AFAC 00121080 */  sll       $v0, $s2, 2
/* 263B0 8004AFB0 3C14800A */  lui       $s4, 0x800a
/* 263B4 8004AFB4 0282A021 */  addu      $s4, $s4, $v0
/* 263B8 8004AFB8 8E943510 */  lw        $s4, 0x3510($s4)
/* 263BC 8004AFBC 00131080 */  sll       $v0, $s3, 2
/* 263C0 8004AFC0 3C1E800A */  lui       $fp, 0x800a
/* 263C4 8004AFC4 03C2F021 */  addu      $fp, $fp, $v0
/* 263C8 8004AFC8 8FDE3628 */  lw        $fp, 0x3628($fp)
.L8004AFCC:
/* 263CC 8004AFCC 2A0200B8 */  slti      $v0, $s0, 0xb8
.L8004AFD0:
/* 263D0 8004AFD0 14400003 */  bnez      $v0, .L8004AFE0
/* 263D4 8004AFD4 00000000 */   nop      
/* 263D8 8004AFD8 12C00005 */  beqz      $s6, .L8004AFF0
/* 263DC 8004AFDC 24160001 */   addiu    $s6, $zero, 1
.L8004AFE0:
/* 263E0 8004AFE0 3C15800A */  lui       $s5, 0x800a
/* 263E4 8004AFE4 8EB53634 */  lw        $s5, 0x3634($s5)
/* 263E8 8004AFE8 08012BFE */  j         .L8004AFF8
/* 263EC 8004AFEC 0000B02D */   daddu    $s6, $zero, $zero
.L8004AFF0:
/* 263F0 8004AFF0 3C15800A */  lui       $s5, 0x800a
/* 263F4 8004AFF4 8EB53638 */  lw        $s5, 0x3638($s5)
.L8004AFF8:
/* 263F8 8004AFF8 0C0187A4 */  jal       osVirtualToPhysical
/* 263FC 8004AFFC 03C0202D */   daddu    $a0, $fp, $zero
/* 26400 8004B000 0280202D */  daddu     $a0, $s4, $zero
/* 26404 8004B004 27A50078 */  addiu     $a1, $sp, 0x78
/* 26408 8004B008 0040302D */  daddu     $a2, $v0, $zero
/* 2640C 8004B00C 0C015970 */  jal       alAudioFrame
/* 26410 8004B010 02A0382D */   daddu    $a3, $s5, $zero
/* 26414 8004B014 3C038008 */  lui       $v1, 0x8008
/* 26418 8004B018 8C638174 */  lw        $v1, -0x7e8c($v1)
/* 2641C 8004B01C 1060FFA0 */  beqz      $v1, .L8004AEA0
/* 26420 8004B020 AFA2007C */   sw       $v0, 0x7c($sp)
/* 26424 8004B024 92E20000 */  lbu       $v0, ($s7)
/* 26428 8004B028 1040FF9E */  beqz      $v0, .L8004AEA4
/* 2642C 8004B02C 27A40020 */   addiu    $a0, $sp, 0x20
/* 26430 8004B030 0040282D */  daddu     $a1, $v0, $zero
/* 26434 8004B034 0060F809 */  jalr      $v1
/* 26438 8004B038 24040001 */   addiu    $a0, $zero, 1
/* 2643C 8004B03C 08012C19 */  j         .L8004B064
/* 26440 8004B040 00000000 */   nop      
.L8004B044:
/* 26444 8004B044 3C028008 */  lui       $v0, 0x8008
/* 26448 8004B048 8C428174 */  lw        $v0, -0x7e8c($v0)
/* 2644C 8004B04C 10400005 */  beqz      $v0, .L8004B064
/* 26450 8004B050 00000000 */   nop      
/* 26454 8004B054 3C058008 */  lui       $a1, 0x8008
/* 26458 8004B058 90A58170 */  lbu       $a1, -0x7e90($a1)
/* 2645C 8004B05C 0040F809 */  jalr      $v0
/* 26460 8004B060 24040002 */   addiu    $a0, $zero, 2
.L8004B064:
/* 26464 8004B064 92E20000 */  lbu       $v0, ($s7)
/* 26468 8004B068 24420001 */  addiu     $v0, $v0, 1
/* 2646C 8004B06C 08012BA8 */  j         .L8004AEA0
/* 26470 8004B070 A2E20000 */   sb       $v0, ($s7)
/* 26474 8004B074 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 26478 8004B078 AFB3001C */  sw        $s3, 0x1c($sp)
/* 2647C 8004B07C 0080982D */  daddu     $s3, $a0, $zero
/* 26480 8004B080 30E700FF */  andi      $a3, $a3, 0xff
/* 26484 8004B084 AFBF0020 */  sw        $ra, 0x20($sp)
/* 26488 8004B088 AFB20018 */  sw        $s2, 0x18($sp)
/* 2648C 8004B08C AFB10014 */  sw        $s1, 0x14($sp)
/* 26490 8004B090 14E00005 */  bnez      $a3, .L8004B0A8
/* 26494 8004B094 AFB00010 */   sw       $s0, 0x10($sp)
/* 26498 8004B098 0C0187A4 */  jal       osVirtualToPhysical
/* 2649C 8004B09C 00000000 */   nop      
/* 264A0 8004B0A0 08012C82 */  j         .L8004B208
/* 264A4 8004B0A4 00000000 */   nop      
.L8004B0A8:
/* 264A8 8004B0A8 0000802D */  daddu     $s0, $zero, $zero
/* 264AC 8004B0AC 3C11800A */  lui       $s1, 0x800a
/* 264B0 8004B0B0 8E313BD4 */  lw        $s1, 0x3bd4($s1)
/* 264B4 8004B0B4 1220000B */  beqz      $s1, .L8004B0E4
/* 264B8 8004B0B8 02652821 */   addu     $a1, $s3, $a1
.L8004B0BC:
/* 264BC 8004B0BC 8E220008 */  lw        $v0, 8($s1)
/* 264C0 8004B0C0 24430500 */  addiu     $v1, $v0, 0x500
/* 264C4 8004B0C4 0262102B */  sltu      $v0, $s3, $v0
/* 264C8 8004B0C8 14400006 */  bnez      $v0, .L8004B0E4
/* 264CC 8004B0CC 0065102A */   slt      $v0, $v1, $a1
/* 264D0 8004B0D0 1040001F */  beqz      $v0, .L8004B150
/* 264D4 8004B0D4 0220802D */   daddu    $s0, $s1, $zero
/* 264D8 8004B0D8 8E310000 */  lw        $s1, ($s1)
/* 264DC 8004B0DC 1620FFF7 */  bnez      $s1, .L8004B0BC
/* 264E0 8004B0E0 00000000 */   nop      
.L8004B0E4:
/* 264E4 8004B0E4 3C12800A */  lui       $s2, 0x800a
/* 264E8 8004B0E8 26523BD0 */  addiu     $s2, $s2, 0x3bd0
/* 264EC 8004B0EC 8E510008 */  lw        $s1, 8($s2)
/* 264F0 8004B0F0 16200006 */  bnez      $s1, .L8004B10C
/* 264F4 8004B0F4 0220202D */   daddu    $a0, $s1, $zero
/* 264F8 8004B0F8 8E440004 */  lw        $a0, 4($s2)
/* 264FC 8004B0FC 0C0187A4 */  jal       osVirtualToPhysical
/* 26500 8004B100 00000000 */   nop      
/* 26504 8004B104 08012C82 */  j         .L8004B208
/* 26508 8004B108 00000000 */   nop      
.L8004B10C:
/* 2650C 8004B10C 8E220000 */  lw        $v0, ($s1)
/* 26510 8004B110 0C012D03 */  jal       alUnlink
/* 26514 8004B114 AE420008 */   sw       $v0, 8($s2)
/* 26518 8004B118 12000005 */  beqz      $s0, .L8004B130
/* 2651C 8004B11C 0220202D */   daddu    $a0, $s1, $zero
/* 26520 8004B120 0C012CFB */  jal       alLink
/* 26524 8004B124 0200282D */   daddu    $a1, $s0, $zero
/* 26528 8004B128 08012C61 */  j         .L8004B184
/* 2652C 8004B12C 00000000 */   nop      
.L8004B130:
/* 26530 8004B130 8E450004 */  lw        $a1, 4($s2)
/* 26534 8004B134 10A00010 */  beqz      $a1, .L8004B178
/* 26538 8004B138 00A0802D */   daddu    $s0, $a1, $zero
/* 2653C 8004B13C AE510004 */  sw        $s1, 4($s2)
/* 26540 8004B140 AE300000 */  sw        $s0, ($s1)
/* 26544 8004B144 AE200004 */  sw        $zero, 4($s1)
/* 26548 8004B148 08012C61 */  j         .L8004B184
/* 2654C 8004B14C AE110004 */   sw       $s1, 4($s0)
.L8004B150:
/* 26550 8004B150 8E240010 */  lw        $a0, 0x10($s1)
/* 26554 8004B154 8E220008 */  lw        $v0, 8($s1)
/* 26558 8004B158 3C038008 */  lui       $v1, 0x8008
/* 2655C 8004B15C 8C63817C */  lw        $v1, -0x7e84($v1)
/* 26560 8004B160 00932021 */  addu      $a0, $a0, $s3
/* 26564 8004B164 00822023 */  subu      $a0, $a0, $v0
/* 26568 8004B168 0C0187A4 */  jal       osVirtualToPhysical
/* 2656C 8004B16C AE23000C */   sw       $v1, 0xc($s1)
/* 26570 8004B170 08012C82 */  j         .L8004B208
/* 26574 8004B174 00000000 */   nop      
.L8004B178:
/* 26578 8004B178 AE510004 */  sw        $s1, 4($s2)
/* 2657C 8004B17C AE200000 */  sw        $zero, ($s1)
/* 26580 8004B180 AE200004 */  sw        $zero, 4($s1)
.L8004B184:
/* 26584 8004B184 3C048008 */  lui       $a0, 0x8008
/* 26588 8004B188 24848178 */  addiu     $a0, $a0, -0x7e88
/* 2658C 8004B18C 32700001 */  andi      $s0, $s3, 1
/* 26590 8004B190 02709823 */  subu      $s3, $s3, $s0
/* 26594 8004B194 3C02800A */  lui       $v0, 0x800a
/* 26598 8004B198 24423720 */  addiu     $v0, $v0, 0x3720
/* 2659C 8004B19C 8C830000 */  lw        $v1, ($a0)
/* 265A0 8004B1A0 8E320010 */  lw        $s2, 0x10($s1)
/* 265A4 8004B1A4 0000302D */  daddu     $a2, $zero, $zero
/* 265A8 8004B1A8 AE330008 */  sw        $s3, 8($s1)
/* 265AC 8004B1AC 00032840 */  sll       $a1, $v1, 1
/* 265B0 8004B1B0 00A32821 */  addu      $a1, $a1, $v1
/* 265B4 8004B1B4 000528C0 */  sll       $a1, $a1, 3
/* 265B8 8004B1B8 00A22821 */  addu      $a1, $a1, $v0
/* 265BC 8004B1BC 3C028008 */  lui       $v0, 0x8008
/* 265C0 8004B1C0 8C42817C */  lw        $v0, -0x7e84($v0)
/* 265C4 8004B1C4 24630001 */  addiu     $v1, $v1, 1
/* 265C8 8004B1C8 AE22000C */  sw        $v0, 0xc($s1)
/* 265CC 8004B1CC AC830000 */  sw        $v1, ($a0)
/* 265D0 8004B1D0 A0A00002 */  sb        $zero, 2($a1)
/* 265D4 8004B1D4 3C04800A */  lui       $a0, %hi(carthandle)
/* 265D8 8004B1D8 8C84A638 */  lw        $a0, %lo(carthandle)($a0)
/* 265DC 8004B1DC 3C02800A */  lui       $v0, 0x800a
/* 265E0 8004B1E0 24423640 */  addiu     $v0, $v0, 0x3640
/* 265E4 8004B1E4 ACA20004 */  sw        $v0, 4($a1)
/* 265E8 8004B1E8 24020500 */  addiu     $v0, $zero, 0x500
/* 265EC 8004B1EC ACB20008 */  sw        $s2, 8($a1)
/* 265F0 8004B1F0 ACB3000C */  sw        $s3, 0xc($a1)
/* 265F4 8004B1F4 0C018388 */  jal       osEPiStartDma
/* 265F8 8004B1F8 ACA20010 */   sw       $v0, 0x10($a1)
/* 265FC 8004B1FC 0C0187A4 */  jal       osVirtualToPhysical
/* 26600 8004B200 0240202D */   daddu    $a0, $s2, $zero
/* 26604 8004B204 00501021 */  addu      $v0, $v0, $s0
.L8004B208:
/* 26608 8004B208 8FBF0020 */  lw        $ra, 0x20($sp)
/* 2660C 8004B20C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 26610 8004B210 8FB20018 */  lw        $s2, 0x18($sp)
/* 26614 8004B214 8FB10014 */  lw        $s1, 0x14($sp)
/* 26618 8004B218 8FB00010 */  lw        $s0, 0x10($sp)
/* 2661C 8004B21C 03E00008 */  jr        $ra
/* 26620 8004B220 27BD0028 */   addiu    $sp, $sp, 0x28
