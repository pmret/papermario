.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuAuDmaCallBack
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
/* 264AC 8004B0AC 3C11800A */  lui       $s1, %hi(D_800A3BD4)
/* 264B0 8004B0B0 8E313BD4 */  lw        $s1, %lo(D_800A3BD4)($s1)
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
/* 264E4 8004B0E4 3C12800A */  lui       $s2, %hi(nuAuDmaState)
/* 264E8 8004B0E8 26523BD0 */  addiu     $s2, $s2, %lo(nuAuDmaState)
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
/* 26558 8004B158 3C038008 */  lui       $v1, %hi(nuAuFrameCounter)
/* 2655C 8004B15C 8C63817C */  lw        $v1, %lo(nuAuFrameCounter)($v1)
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
/* 26584 8004B184 3C048008 */  lui       $a0, %hi(nuAuDmaNext)
/* 26588 8004B188 24848178 */  addiu     $a0, $a0, %lo(nuAuDmaNext)
/* 2658C 8004B18C 32700001 */  andi      $s0, $s3, 1
/* 26590 8004B190 02709823 */  subu      $s3, $s3, $s0
/* 26594 8004B194 3C02800A */  lui       $v0, %hi(D_800A3720)
/* 26598 8004B198 24423720 */  addiu     $v0, $v0, %lo(D_800A3720)
/* 2659C 8004B19C 8C830000 */  lw        $v1, ($a0)
/* 265A0 8004B1A0 8E320010 */  lw        $s2, 0x10($s1)
/* 265A4 8004B1A4 0000302D */  daddu     $a2, $zero, $zero
/* 265A8 8004B1A8 AE330008 */  sw        $s3, 8($s1)
/* 265AC 8004B1AC 00032840 */  sll       $a1, $v1, 1
/* 265B0 8004B1B0 00A32821 */  addu      $a1, $a1, $v1
/* 265B4 8004B1B4 000528C0 */  sll       $a1, $a1, 3
/* 265B8 8004B1B8 00A22821 */  addu      $a1, $a1, $v0
/* 265BC 8004B1BC 3C028008 */  lui       $v0, %hi(nuAuFrameCounter)
/* 265C0 8004B1C0 8C42817C */  lw        $v0, %lo(nuAuFrameCounter)($v0)
/* 265C4 8004B1C4 24630001 */  addiu     $v1, $v1, 1
/* 265C8 8004B1C8 AE22000C */  sw        $v0, 0xc($s1)
/* 265CC 8004B1CC AC830000 */  sw        $v1, ($a0)
/* 265D0 8004B1D0 A0A00002 */  sb        $zero, 2($a1)
/* 265D4 8004B1D4 3C04800A */  lui       $a0, %hi(carthandle)
/* 265D8 8004B1D8 8C84A638 */  lw        $a0, %lo(carthandle)($a0)
/* 265DC 8004B1DC 3C02800A */  lui       $v0, %hi(D_800A3640)
/* 265E0 8004B1E0 24423640 */  addiu     $v0, $v0, %lo(D_800A3640)
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
