.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241AE0_EA23E0
/* EA23E0 80241AE0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* EA23E4 80241AE4 AFB10034 */  sw        $s1, 0x34($sp)
/* EA23E8 80241AE8 0080882D */  daddu     $s1, $a0, $zero
/* EA23EC 80241AEC AFBF0048 */  sw        $ra, 0x48($sp)
/* EA23F0 80241AF0 AFB50044 */  sw        $s5, 0x44($sp)
/* EA23F4 80241AF4 AFB40040 */  sw        $s4, 0x40($sp)
/* EA23F8 80241AF8 AFB3003C */  sw        $s3, 0x3c($sp)
/* EA23FC 80241AFC AFB20038 */  sw        $s2, 0x38($sp)
/* EA2400 80241B00 AFB00030 */  sw        $s0, 0x30($sp)
/* EA2404 80241B04 8E300148 */  lw        $s0, 0x148($s1)
/* EA2408 80241B08 86040008 */  lh        $a0, 8($s0)
/* EA240C 80241B0C 0C00F92F */  jal       dead_get_npc_unsafe
/* EA2410 80241B10 00A0A82D */   daddu    $s5, $a1, $zero
/* EA2414 80241B14 8E23000C */  lw        $v1, 0xc($s1)
/* EA2418 80241B18 0220202D */  daddu     $a0, $s1, $zero
/* EA241C 80241B1C 8C650000 */  lw        $a1, ($v1)
/* EA2420 80241B20 0C0B53A3 */  jal       dead_evt_get_variable
/* EA2424 80241B24 0040A02D */   daddu    $s4, $v0, $zero
/* EA2428 80241B28 AFA00010 */  sw        $zero, 0x10($sp)
/* EA242C 80241B2C 8E0300D0 */  lw        $v1, 0xd0($s0)
/* EA2430 80241B30 8C630030 */  lw        $v1, 0x30($v1)
/* EA2434 80241B34 AFA30014 */  sw        $v1, 0x14($sp)
/* EA2438 80241B38 8E0300D0 */  lw        $v1, 0xd0($s0)
/* EA243C 80241B3C 8C63001C */  lw        $v1, 0x1c($v1)
/* EA2440 80241B40 AFA30018 */  sw        $v1, 0x18($sp)
/* EA2444 80241B44 8E0300D0 */  lw        $v1, 0xd0($s0)
/* EA2448 80241B48 8C630024 */  lw        $v1, 0x24($v1)
/* EA244C 80241B4C AFA3001C */  sw        $v1, 0x1c($sp)
/* EA2450 80241B50 8E0300D0 */  lw        $v1, 0xd0($s0)
/* EA2454 80241B54 8C630028 */  lw        $v1, 0x28($v1)
/* EA2458 80241B58 0200202D */  daddu     $a0, $s0, $zero
/* EA245C 80241B5C AFA30020 */  sw        $v1, 0x20($sp)
/* EA2460 80241B60 8E0300D0 */  lw        $v1, 0xd0($s0)
/* EA2464 80241B64 3C014348 */  lui       $at, 0x4348
/* EA2468 80241B68 44810000 */  mtc1      $at, $f0
/* EA246C 80241B6C 8C63002C */  lw        $v1, 0x2c($v1)
/* EA2470 80241B70 0040902D */  daddu     $s2, $v0, $zero
/* EA2474 80241B74 E7A00028 */  swc1      $f0, 0x28($sp)
/* EA2478 80241B78 A7A0002C */  sh        $zero, 0x2c($sp)
/* EA247C 80241B7C 0C013638 */  jal       func_8004D8E0
/* EA2480 80241B80 AFA30024 */   sw       $v1, 0x24($sp)
/* EA2484 80241B84 8E020000 */  lw        $v0, ($s0)
/* EA2488 80241B88 3C030010 */  lui       $v1, 0x10
/* EA248C 80241B8C 00431024 */  and       $v0, $v0, $v1
/* EA2490 80241B90 10400008 */  beqz      $v0, .L80241BB4
/* EA2494 80241B94 27B30010 */   addiu    $s3, $sp, 0x10
/* EA2498 80241B98 3C014120 */  lui       $at, 0x4120
/* EA249C 80241B9C 44810000 */  mtc1      $at, $f0
/* EA24A0 80241BA0 3C013F33 */  lui       $at, 0x3f33
/* EA24A4 80241BA4 34213333 */  ori       $at, $at, 0x3333
/* EA24A8 80241BA8 44811000 */  mtc1      $at, $f2
/* EA24AC 80241BAC E6000114 */  swc1      $f0, 0x114($s0)
/* EA24B0 80241BB0 E6020118 */  swc1      $f2, 0x118($s0)
.L80241BB4:
/* EA24B4 80241BB4 56A00006 */  bnel      $s5, $zero, .L80241BD0
/* EA24B8 80241BB8 AE200070 */   sw       $zero, 0x70($s1)
/* EA24BC 80241BBC 8E0200B0 */  lw        $v0, 0xb0($s0)
/* EA24C0 80241BC0 30420004 */  andi      $v0, $v0, 4
/* EA24C4 80241BC4 10400011 */  beqz      $v0, .L80241C0C
/* EA24C8 80241BC8 00000000 */   nop
/* EA24CC 80241BCC AE200070 */  sw        $zero, 0x70($s1)
.L80241BD0:
/* EA24D0 80241BD0 A680008E */  sh        $zero, 0x8e($s4)
/* EA24D4 80241BD4 8E0200CC */  lw        $v0, 0xcc($s0)
/* EA24D8 80241BD8 8C420000 */  lw        $v0, ($v0)
/* EA24DC 80241BDC AE820028 */  sw        $v0, 0x28($s4)
/* EA24E0 80241BE0 8E0200B0 */  lw        $v0, 0xb0($s0)
/* EA24E4 80241BE4 30420004 */  andi      $v0, $v0, 4
/* EA24E8 80241BE8 10400008 */  beqz      $v0, .L80241C0C
/* EA24EC 80241BEC AE00006C */   sw       $zero, 0x6c($s0)
/* EA24F0 80241BF0 24020063 */  addiu     $v0, $zero, 0x63
/* EA24F4 80241BF4 AE220070 */  sw        $v0, 0x70($s1)
/* EA24F8 80241BF8 AE200074 */  sw        $zero, 0x74($s1)
/* EA24FC 80241BFC 8E0200B0 */  lw        $v0, 0xb0($s0)
/* EA2500 80241C00 2403FFFB */  addiu     $v1, $zero, -5
/* EA2504 80241C04 00431024 */  and       $v0, $v0, $v1
/* EA2508 80241C08 AE0200B0 */  sw        $v0, 0xb0($s0)
.L80241C0C:
/* EA250C 80241C0C 8E230070 */  lw        $v1, 0x70($s1)
/* EA2510 80241C10 2410000B */  addiu     $s0, $zero, 0xb
/* EA2514 80241C14 1070002A */  beq       $v1, $s0, .L80241CC0
/* EA2518 80241C18 2862000C */   slti     $v0, $v1, 0xc
/* EA251C 80241C1C 1040000D */  beqz      $v0, .L80241C54
/* EA2520 80241C20 24020001 */   addiu    $v0, $zero, 1
/* EA2524 80241C24 1062001A */  beq       $v1, $v0, .L80241C90
/* EA2528 80241C28 28620002 */   slti     $v0, $v1, 2
/* EA252C 80241C2C 10400005 */  beqz      $v0, .L80241C44
/* EA2530 80241C30 2402000A */   addiu    $v0, $zero, 0xa
/* EA2534 80241C34 10600013 */  beqz      $v1, .L80241C84
/* EA2538 80241C38 0220202D */   daddu    $a0, $s1, $zero
/* EA253C 80241C3C 08090750 */  j         .L80241D40
/* EA2540 80241C40 00000000 */   nop
.L80241C44:
/* EA2544 80241C44 10620018 */  beq       $v1, $v0, .L80241CA8
/* EA2548 80241C48 0220202D */   daddu    $a0, $s1, $zero
/* EA254C 80241C4C 08090750 */  j         .L80241D40
/* EA2550 80241C50 00000000 */   nop
.L80241C54:
/* EA2554 80241C54 2402000D */  addiu     $v0, $zero, 0xd
/* EA2558 80241C58 10620029 */  beq       $v1, $v0, .L80241D00
/* EA255C 80241C5C 0062102A */   slt      $v0, $v1, $v0
/* EA2560 80241C60 14400020 */  bnez      $v0, .L80241CE4
/* EA2564 80241C64 0220202D */   daddu    $a0, $s1, $zero
/* EA2568 80241C68 2402000E */  addiu     $v0, $zero, 0xe
/* EA256C 80241C6C 1062002D */  beq       $v1, $v0, .L80241D24
/* EA2570 80241C70 24020063 */   addiu    $v0, $zero, 0x63
/* EA2574 80241C74 10620030 */  beq       $v1, $v0, .L80241D38
/* EA2578 80241C78 00000000 */   nop
/* EA257C 80241C7C 08090750 */  j         .L80241D40
/* EA2580 80241C80 00000000 */   nop
.L80241C84:
/* EA2584 80241C84 0240282D */  daddu     $a1, $s2, $zero
/* EA2588 80241C88 0C090317 */  jal       func_80240C5C_EA155C
/* EA258C 80241C8C 0260302D */   daddu    $a2, $s3, $zero
.L80241C90:
/* EA2590 80241C90 0220202D */  daddu     $a0, $s1, $zero
/* EA2594 80241C94 0240282D */  daddu     $a1, $s2, $zero
/* EA2598 80241C98 0C090332 */  jal       func_80240CC8_EA15C8
/* EA259C 80241C9C 0260302D */   daddu    $a2, $s3, $zero
/* EA25A0 80241CA0 08090750 */  j         .L80241D40
/* EA25A4 80241CA4 00000000 */   nop
.L80241CA8:
/* EA25A8 80241CA8 0240282D */  daddu     $a1, $s2, $zero
/* EA25AC 80241CAC 0C090371 */  jal       func_80240DC4_EA16C4
/* EA25B0 80241CB0 0260302D */   daddu    $a2, $s3, $zero
/* EA25B4 80241CB4 8E220070 */  lw        $v0, 0x70($s1)
/* EA25B8 80241CB8 14500021 */  bne       $v0, $s0, .L80241D40
/* EA25BC 80241CBC 00000000 */   nop
.L80241CC0:
/* EA25C0 80241CC0 0220202D */  daddu     $a0, $s1, $zero
/* EA25C4 80241CC4 0240282D */  daddu     $a1, $s2, $zero
/* EA25C8 80241CC8 0C090601 */  jal       func_80241804_EA2104
/* EA25CC 80241CCC 0260302D */   daddu    $a2, $s3, $zero
/* EA25D0 80241CD0 8E230070 */  lw        $v1, 0x70($s1)
/* EA25D4 80241CD4 2402000C */  addiu     $v0, $zero, 0xc
/* EA25D8 80241CD8 14620019 */  bne       $v1, $v0, .L80241D40
/* EA25DC 80241CDC 00000000 */   nop
/* EA25E0 80241CE0 0220202D */  daddu     $a0, $s1, $zero
.L80241CE4:
/* EA25E4 80241CE4 0240282D */  daddu     $a1, $s2, $zero
/* EA25E8 80241CE8 0C090625 */  jal       func_80241894_EA2194
/* EA25EC 80241CEC 0260302D */   daddu    $a2, $s3, $zero
/* EA25F0 80241CF0 8E230070 */  lw        $v1, 0x70($s1)
/* EA25F4 80241CF4 2402000D */  addiu     $v0, $zero, 0xd
/* EA25F8 80241CF8 14620011 */  bne       $v1, $v0, .L80241D40
/* EA25FC 80241CFC 00000000 */   nop
.L80241D00:
/* EA2600 80241D00 0220202D */  daddu     $a0, $s1, $zero
/* EA2604 80241D04 0240282D */  daddu     $a1, $s2, $zero
/* EA2608 80241D08 0C090665 */  jal       func_80241994_EA2294
/* EA260C 80241D0C 0260302D */   daddu    $a2, $s3, $zero
/* EA2610 80241D10 8E230070 */  lw        $v1, 0x70($s1)
/* EA2614 80241D14 2402000E */  addiu     $v0, $zero, 0xe
/* EA2618 80241D18 14620009 */  bne       $v1, $v0, .L80241D40
/* EA261C 80241D1C 00000000 */   nop
/* EA2620 80241D20 0220202D */  daddu     $a0, $s1, $zero
.L80241D24:
/* EA2624 80241D24 0240282D */  daddu     $a1, $s2, $zero
/* EA2628 80241D28 0C09067D */  jal       func_802419F4_EA22F4
/* EA262C 80241D2C 0260302D */   daddu    $a2, $s3, $zero
/* EA2630 80241D30 08090750 */  j         .L80241D40
/* EA2634 80241D34 00000000 */   nop
.L80241D38:
/* EA2638 80241D38 0C013AE3 */  jal       func_8004EB8C
/* EA263C 80241D3C 0220202D */   daddu    $a0, $s1, $zero
.L80241D40:
/* EA2640 80241D40 8FBF0048 */  lw        $ra, 0x48($sp)
/* EA2644 80241D44 8FB50044 */  lw        $s5, 0x44($sp)
/* EA2648 80241D48 8FB40040 */  lw        $s4, 0x40($sp)
/* EA264C 80241D4C 8FB3003C */  lw        $s3, 0x3c($sp)
/* EA2650 80241D50 8FB20038 */  lw        $s2, 0x38($sp)
/* EA2654 80241D54 8FB10034 */  lw        $s1, 0x34($sp)
/* EA2658 80241D58 8FB00030 */  lw        $s0, 0x30($sp)
/* EA265C 80241D5C 0000102D */  daddu     $v0, $zero, $zero
/* EA2660 80241D60 03E00008 */  jr        $ra
/* EA2664 80241D64 27BD0050 */   addiu    $sp, $sp, 0x50
