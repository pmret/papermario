.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_80_main
/* 3A2290 E00A0000 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 3A2294 E00A0004 AFB00028 */  sw        $s0, 0x28($sp)
/* 3A2298 E00A0008 0080802D */  daddu     $s0, $a0, $zero
/* 3A229C E00A000C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3A22A0 E00A0010 24020050 */  addiu     $v0, $zero, 0x50
/* 3A22A4 E00A0014 AFBF002C */  sw        $ra, 0x2c($sp)
/* 3A22A8 E00A0018 AFA00010 */  sw        $zero, 0x10($sp)
/* 3A22AC E00A001C AFA00018 */  sw        $zero, 0x18($sp)
/* 3A22B0 E00A0020 AFA0001C */  sw        $zero, 0x1c($sp)
/* 3A22B4 E00A0024 AFA00020 */  sw        $zero, 0x20($sp)
/* 3A22B8 E00A0028 AFA00024 */  sw        $zero, 0x24($sp)
/* 3A22BC E00A002C 0C080124 */  jal       shim_create_effect_instance
/* 3A22C0 E00A0030 AFA20014 */   sw       $v0, 0x14($sp)
/* 3A22C4 E00A0034 3C04DB06 */  lui       $a0, 0xdb06
/* 3A22C8 E00A0038 34840024 */  ori       $a0, $a0, 0x24
/* 3A22CC E00A003C 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 3A22D0 E00A0040 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 3A22D4 E00A0044 0040582D */  daddu     $t3, $v0, $zero
/* 3A22D8 E00A0048 8CC50000 */  lw        $a1, ($a2)
/* 3A22DC E00A004C 3C02E700 */  lui       $v0, 0xe700
/* 3A22E0 E00A0050 AD60000C */  sw        $zero, 0xc($t3)
/* 3A22E4 E00A0054 00A0182D */  daddu     $v1, $a1, $zero
/* 3A22E8 E00A0058 24A50008 */  addiu     $a1, $a1, 8
/* 3A22EC E00A005C ACC50000 */  sw        $a1, ($a2)
/* 3A22F0 E00A0060 AC620000 */  sw        $v0, ($v1)
/* 3A22F4 E00A0064 AC600004 */  sw        $zero, 4($v1)
/* 3A22F8 E00A0068 ACA40000 */  sw        $a0, ($a1)
/* 3A22FC E00A006C 8D630010 */  lw        $v1, 0x10($t3)
/* 3A2300 E00A0070 24A20008 */  addiu     $v0, $a1, 8
/* 3A2304 E00A0074 ACC20000 */  sw        $v0, ($a2)
/* 3A2308 E00A0078 8C62001C */  lw        $v0, 0x1c($v1)
/* 3A230C E00A007C 3C038000 */  lui       $v1, 0x8000
/* 3A2310 E00A0080 00431021 */  addu      $v0, $v0, $v1
/* 3A2314 E00A0084 1600000A */  bnez      $s0, .LE00A00B0
/* 3A2318 E00A0088 ACA20004 */   sw       $v0, 4($a1)
/* 3A231C E00A008C 3C03FF40 */  lui       $v1, 0xff40
/* 3A2320 E00A0090 24A20010 */  addiu     $v0, $a1, 0x10
/* 3A2324 E00A0094 ACC20000 */  sw        $v0, ($a2)
/* 3A2328 E00A0098 3C02DE00 */  lui       $v0, 0xde00
/* 3A232C E00A009C ACA20008 */  sw        $v0, 8($a1)
/* 3A2330 E00A00A0 3C020900 */  lui       $v0, 0x900
/* 3A2334 E00A00A4 24420400 */  addiu     $v0, $v0, 0x400
/* 3A2338 E00A00A8 08028034 */  j         .LE00A00D0
/* 3A233C E00A00AC 346340E6 */   ori      $v1, $v1, 0x40e6
.LE00A00B0:
/* 3A2340 E00A00B0 3C035050 */  lui       $v1, 0x5050
/* 3A2344 E00A00B4 3463FFE6 */  ori       $v1, $v1, 0xffe6
/* 3A2348 E00A00B8 24A20010 */  addiu     $v0, $a1, 0x10
/* 3A234C E00A00BC ACC20000 */  sw        $v0, ($a2)
/* 3A2350 E00A00C0 3C02DE00 */  lui       $v0, 0xde00
/* 3A2354 E00A00C4 ACA20008 */  sw        $v0, 8($a1)
/* 3A2358 E00A00C8 3C020900 */  lui       $v0, 0x900
/* 3A235C E00A00CC 244204A8 */  addiu     $v0, $v0, 0x4a8
.LE00A00D0:
/* 3A2360 E00A00D0 ACA2000C */  sw        $v0, 0xc($a1)
/* 3A2364 E00A00D4 24A20018 */  addiu     $v0, $a1, 0x18
/* 3A2368 E00A00D8 ACC20000 */  sw        $v0, ($a2)
/* 3A236C E00A00DC 3C02FA00 */  lui       $v0, 0xfa00
/* 3A2370 E00A00E0 ACA20010 */  sw        $v0, 0x10($a1)
/* 3A2374 E00A00E4 ACA30014 */  sw        $v1, 0x14($a1)
/* 3A2378 E00A00E8 3C070050 */  lui       $a3, 0x50
/* 3A237C E00A00EC 34E703C0 */  ori       $a3, $a3, 0x3c0
/* 3A2380 E00A00F0 3C09E430 */  lui       $t1, 0xe430
/* 3A2384 E00A00F4 35290230 */  ori       $t1, $t1, 0x230
/* 3A2388 E00A00F8 3C080020 */  lui       $t0, 0x20
/* 3A238C E00A00FC 35080130 */  ori       $t0, $t0, 0x130
/* 3A2390 E00A0100 3C0A0400 */  lui       $t2, 0x400
/* 3A2394 E00A0104 354A0400 */  ori       $t2, $t2, 0x400
/* 3A2398 E00A0108 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 3A239C E00A010C 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* 3A23A0 E00A0110 0160202D */  daddu     $a0, $t3, $zero
/* 3A23A4 E00A0114 8CA20000 */  lw        $v0, ($a1)
/* 3A23A8 E00A0118 3C03ED00 */  lui       $v1, 0xed00
/* 3A23AC E00A011C 0040302D */  daddu     $a2, $v0, $zero
/* 3A23B0 E00A0120 24420008 */  addiu     $v0, $v0, 8
/* 3A23B4 E00A0124 ACA20000 */  sw        $v0, ($a1)
/* 3A23B8 E00A0128 ACC30000 */  sw        $v1, ($a2)
/* 3A23BC E00A012C 24430008 */  addiu     $v1, $v0, 8
/* 3A23C0 E00A0130 ACC70004 */  sw        $a3, 4($a2)
/* 3A23C4 E00A0134 ACA30000 */  sw        $v1, ($a1)
/* 3A23C8 E00A0138 24430010 */  addiu     $v1, $v0, 0x10
/* 3A23CC E00A013C AC490000 */  sw        $t1, ($v0)
/* 3A23D0 E00A0140 AC480004 */  sw        $t0, 4($v0)
/* 3A23D4 E00A0144 ACA30000 */  sw        $v1, ($a1)
/* 3A23D8 E00A0148 3C03E100 */  lui       $v1, 0xe100
/* 3A23DC E00A014C AC430008 */  sw        $v1, 8($v0)
/* 3A23E0 E00A0150 24030400 */  addiu     $v1, $zero, 0x400
/* 3A23E4 E00A0154 AC43000C */  sw        $v1, 0xc($v0)
/* 3A23E8 E00A0158 24430018 */  addiu     $v1, $v0, 0x18
/* 3A23EC E00A015C ACA30000 */  sw        $v1, ($a1)
/* 3A23F0 E00A0160 3C03F100 */  lui       $v1, 0xf100
/* 3A23F4 E00A0164 AC430010 */  sw        $v1, 0x10($v0)
/* 3A23F8 E00A0168 24430020 */  addiu     $v1, $v0, 0x20
/* 3A23FC E00A016C AC4A0014 */  sw        $t2, 0x14($v0)
/* 3A2400 E00A0170 ACA30000 */  sw        $v1, ($a1)
/* 3A2404 E00A0174 3C03E700 */  lui       $v1, 0xe700
/* 3A2408 E00A0178 AC430018 */  sw        $v1, 0x18($v0)
/* 3A240C E00A017C 24430028 */  addiu     $v1, $v0, 0x28
/* 3A2410 E00A0180 AC40001C */  sw        $zero, 0x1c($v0)
/* 3A2414 E00A0184 ACA30000 */  sw        $v1, ($a1)
/* 3A2418 E00A0188 3C03DB06 */  lui       $v1, 0xdb06
/* 3A241C E00A018C AC430020 */  sw        $v1, 0x20($v0)
/* 3A2420 E00A0190 0C080128 */  jal       shim_remove_effect
/* 3A2424 E00A0194 AC400024 */   sw       $zero, 0x24($v0)
/* 3A2428 E00A0198 8FBF002C */  lw        $ra, 0x2c($sp)
/* 3A242C E00A019C 8FB00028 */  lw        $s0, 0x28($sp)
/* 3A2430 E00A01A0 0000102D */  daddu     $v0, $zero, $zero
/* 3A2434 E00A01A4 03E00008 */  jr        $ra
/* 3A2438 E00A01A8 27BD0030 */   addiu    $sp, $sp, 0x30
/* 3A243C E00A01AC 00000000 */  nop
