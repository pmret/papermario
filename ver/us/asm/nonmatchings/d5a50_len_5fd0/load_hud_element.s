.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80151140
.word L8013F6DC_D5DDC, L8013F418_D5B18, L8013F3B4_D5AB4, L8013F38C_D5A8C, L8013F38C_D5A8C, L8013F3BC_D5ABC, L8013F3C8_D5AC8, L8013F3C8_D5AC8, L8013F38C_D5A8C, L8013F38C_D5A8C, L8013F410_D5B10, L8013F410_D5B10, L8013F418_D5B18, L8013F430_D5B30, L8013F410_D5B10, L8013F410_D5B10, L8013F418_D5B18, L8013F38C_D5A8C, L8013F38C_D5A8C, L8013F3DC_D5ADC, L8013F418_D5B18, L8013F410_D5B10, L8013F38C_D5A8C, L8013F410_D5B10, L8013F410_D5B10, L8013F410_D5B10, L8013F410_D5B10, L8013F418_D5B18

.section .text

glabel load_hud_element
/* D5A50 8013F350 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D5A54 8013F354 AFB50024 */  sw        $s5, 0x24($sp)
/* D5A58 8013F358 0080A82D */  daddu     $s5, $a0, $zero
/* D5A5C 8013F35C AFB00010 */  sw        $s0, 0x10($sp)
/* D5A60 8013F360 00A0802D */  daddu     $s0, $a1, $zero
/* D5A64 8013F364 AFBF002C */  sw        $ra, 0x2c($sp)
/* D5A68 8013F368 AFB60028 */  sw        $s6, 0x28($sp)
/* D5A6C 8013F36C AFB40020 */  sw        $s4, 0x20($sp)
/* D5A70 8013F370 AFB3001C */  sw        $s3, 0x1c($sp)
/* D5A74 8013F374 AFB20018 */  sw        $s2, 0x18($sp)
/* D5A78 8013F378 120000D8 */  beqz      $s0, L8013F6DC_D5DDC
/* D5A7C 8013F37C AFB10014 */   sw       $s1, 0x14($sp)
/* D5A80 8013F380 0000982D */  daddu     $s3, $zero, $zero
/* D5A84 8013F384 3C168015 */  lui       $s6, %hi(D_8014EFCC)
/* D5A88 8013F388 26D6EFCC */  addiu     $s6, $s6, %lo(D_8014EFCC)
glabel L8013F38C_D5A8C
/* D5A8C 8013F38C 8E030000 */  lw        $v1, ($s0)
/* D5A90 8013F390 2C62001C */  sltiu     $v0, $v1, 0x1c
/* D5A94 8013F394 1040FFFD */  beqz      $v0, L8013F38C_D5A8C
/* D5A98 8013F398 26100004 */   addiu    $s0, $s0, 4
/* D5A9C 8013F39C 00031080 */  sll       $v0, $v1, 2
/* D5AA0 8013F3A0 3C018015 */  lui       $at, %hi(jtbl_80151140)
/* D5AA4 8013F3A4 00220821 */  addu      $at, $at, $v0
/* D5AA8 8013F3A8 8C221140 */  lw        $v0, %lo(jtbl_80151140)($at)
/* D5AAC 8013F3AC 00400008 */  jr        $v0
/* D5AB0 8013F3B0 00000000 */   nop
glabel L8013F3B4_D5AB4
/* D5AB4 8013F3B4 0804FCE3 */  j         L8013F38C_D5A8C
/* D5AB8 8013F3B8 2610000C */   addiu    $s0, $s0, 0xc
glabel L8013F3BC_D5ABC
/* D5ABC 8013F3BC 8E130000 */  lw        $s3, ($s0)
/* D5AC0 8013F3C0 0804FCF4 */  j         .L8013F3D0
/* D5AC4 8013F3C4 26100004 */   addiu    $s0, $s0, 4
glabel L8013F3C8_D5AC8
/* D5AC8 8013F3C8 8E130000 */  lw        $s3, ($s0)
/* D5ACC 8013F3CC 26100008 */  addiu     $s0, $s0, 8
.L8013F3D0:
/* D5AD0 8013F3D0 A2B30046 */  sb        $s3, 0x46($s5)
/* D5AD4 8013F3D4 0804FCE3 */  j         L8013F38C_D5A8C
/* D5AD8 8013F3D8 A2B30045 */   sb       $s3, 0x45($s5)
glabel L8013F3DC_D5ADC
/* D5ADC 8013F3DC 92020003 */  lbu       $v0, 3($s0)
/* D5AE0 8013F3E0 26100004 */  addiu     $s0, $s0, 4
/* D5AE4 8013F3E4 3C030010 */  lui       $v1, 0x10
/* D5AE8 8013F3E8 A2A2004E */  sb        $v0, 0x4e($s5)
/* D5AEC 8013F3EC A2A20050 */  sb        $v0, 0x50($s5)
/* D5AF0 8013F3F0 92040003 */  lbu       $a0, 3($s0)
/* D5AF4 8013F3F4 8EA20000 */  lw        $v0, ($s5)
/* D5AF8 8013F3F8 26100004 */  addiu     $s0, $s0, 4
/* D5AFC 8013F3FC 00431025 */  or        $v0, $v0, $v1
/* D5B00 8013F400 AEA20000 */  sw        $v0, ($s5)
/* D5B04 8013F404 A2A4004F */  sb        $a0, 0x4f($s5)
/* D5B08 8013F408 0804FCE3 */  j         L8013F38C_D5A8C
/* D5B0C 8013F40C A2A40051 */   sb       $a0, 0x51($s5)
glabel L8013F410_D5B10
/* D5B10 8013F410 0804FCE3 */  j         L8013F38C_D5A8C
/* D5B14 8013F414 26100004 */   addiu    $s0, $s0, 4
glabel L8013F418_D5B18
/* D5B18 8013F418 0804FCE3 */  j         L8013F38C_D5A8C
/* D5B1C 8013F41C 26100008 */   addiu    $s0, $s0, 8
.L8013F420:
/* D5B20 8013F420 0804FD62 */  j         .L8013F588
/* D5B24 8013F424 AE110000 */   sw       $s1, ($s0)
.L8013F428:
/* D5B28 8013F428 0804FDB2 */  j         .L8013F6C8
/* D5B2C 8013F42C AE110000 */   sw       $s1, ($s0)
glabel L8013F430_D5B30
/* D5B30 8013F430 26100004 */  addiu     $s0, $s0, 4
/* D5B34 8013F434 8E070000 */  lw        $a3, ($s0)
/* D5B38 8013F438 26100004 */  addiu     $s0, $s0, 4
/* D5B3C 8013F43C 8E140000 */  lw        $s4, ($s0)
/* D5B40 8013F440 26100004 */  addiu     $s0, $s0, 4
/* D5B44 8013F444 0000882D */  daddu     $s1, $zero, $zero
/* D5B48 8013F448 00131040 */  sll       $v0, $s3, 1
/* D5B4C 8013F44C 00531021 */  addu      $v0, $v0, $s3
/* D5B50 8013F450 00021040 */  sll       $v0, $v0, 1
/* D5B54 8013F454 3C048015 */  lui       $a0, %hi(D_801512C8)
/* D5B58 8013F458 8C8412C8 */  lw        $a0, %lo(D_801512C8)($a0)
/* D5B5C 8013F45C 00569021 */  addu      $s2, $v0, $s6
/* D5B60 8013F460 24850004 */  addiu     $a1, $a0, 4
.L8013F464:
/* D5B64 8013F464 8C830000 */  lw        $v1, ($a0)
/* D5B68 8013F468 2402FFFF */  addiu     $v0, $zero, -1
/* D5B6C 8013F46C 14620038 */  bne       $v1, $v0, .L8013F550
/* D5B70 8013F470 00000000 */   nop
/* D5B74 8013F474 3C038015 */  lui       $v1, %hi(D_8015133C)
/* D5B78 8013F478 8C63133C */  lw        $v1, %lo(D_8015133C)($v1)
/* D5B7C 8013F47C 3C028015 */  lui       $v0, %hi(D_80151314)
/* D5B80 8013F480 8C421314 */  lw        $v0, %lo(D_80151314)($v0)
/* D5B84 8013F484 AC870000 */  sw        $a3, ($a0)
/* D5B88 8013F488 8C630000 */  lw        $v1, ($v1)
/* D5B8C 8013F48C 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* D5B90 8013F490 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* D5B94 8013F494 00431021 */  addu      $v0, $v0, $v1
/* D5B98 8013F498 ACA20000 */  sw        $v0, ($a1)
/* D5B9C 8013F49C 80820070 */  lb        $v0, 0x70($a0)
/* D5BA0 8013F4A0 14400004 */  bnez      $v0, .L8013F4B4
/* D5BA4 8013F4A4 00000000 */   nop
/* D5BA8 8013F4A8 3C048015 */  lui       $a0, %hi(D_8014EFC4)
/* D5BAC 8013F4AC 0804FD32 */  j         .L8013F4C8
/* D5BB0 8013F4B0 8C84EFC4 */   lw       $a0, %lo(D_8014EFC4)($a0)
.L8013F4B4:
/* D5BB4 8013F4B4 3C028015 */  lui       $v0, %hi(D_8014EFC4)
/* D5BB8 8013F4B8 8C42EFC4 */  lw        $v0, %lo(D_8014EFC4)($v0)
/* D5BBC 8013F4BC 00021FC2 */  srl       $v1, $v0, 0x1f
/* D5BC0 8013F4C0 00431021 */  addu      $v0, $v0, $v1
/* D5BC4 8013F4C4 00022043 */  sra       $a0, $v0, 1
.L8013F4C8:
/* D5BC8 8013F4C8 3C028015 */  lui       $v0, %hi(D_8015133C)
/* D5BCC 8013F4CC 8C42133C */  lw        $v0, %lo(D_8015133C)($v0)
/* D5BD0 8013F4D0 86430004 */  lh        $v1, 4($s2)
/* D5BD4 8013F4D4 8C420000 */  lw        $v0, ($v0)
/* D5BD8 8013F4D8 00431021 */  addu      $v0, $v0, $v1
/* D5BDC 8013F4DC 0044102A */  slt       $v0, $v0, $a0
/* D5BE0 8013F4E0 14400003 */  bnez      $v0, .L8013F4F0
/* D5BE4 8013F4E4 00000000 */   nop
.L8013F4E8:
/* D5BE8 8013F4E8 0804FD3A */  j         .L8013F4E8
/* D5BEC 8013F4EC 00000000 */   nop
.L8013F4F0:
/* D5BF0 8013F4F0 3C04001D */  lui       $a0, 0x1d
/* D5BF4 8013F4F4 2484C310 */  addiu     $a0, $a0, -0x3cf0
/* D5BF8 8013F4F8 8CA50000 */  lw        $a1, ($a1)
/* D5BFC 8013F4FC 86460004 */  lh        $a2, 4($s2)
/* D5C00 8013F500 0C017D24 */  jal       nuPiReadRom
/* D5C04 8013F504 00E42021 */   addu     $a0, $a3, $a0
/* D5C08 8013F508 3C038015 */  lui       $v1, %hi(D_8015133C)
/* D5C0C 8013F50C 8C63133C */  lw        $v1, %lo(D_8015133C)($v1)
/* D5C10 8013F510 86440004 */  lh        $a0, 4($s2)
/* D5C14 8013F514 8C620000 */  lw        $v0, ($v1)
/* D5C18 8013F518 00441021 */  addu      $v0, $v0, $a0
/* D5C1C 8013F51C AC620000 */  sw        $v0, ($v1)
/* D5C20 8013F520 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* D5C24 8013F524 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* D5C28 8013F528 80420070 */  lb        $v0, 0x70($v0)
/* D5C2C 8013F52C 14400003 */  bnez      $v0, .L8013F53C
/* D5C30 8013F530 00111C00 */   sll      $v1, $s1, 0x10
/* D5C34 8013F534 0804FD52 */  j         .L8013F548
/* D5C38 8013F538 AE110000 */   sw       $s1, ($s0)
.L8013F53C:
/* D5C3C 8013F53C 96020002 */  lhu       $v0, 2($s0)
/* D5C40 8013F540 00431025 */  or        $v0, $v0, $v1
/* D5C44 8013F544 AE020000 */  sw        $v0, ($s0)
.L8013F548:
/* D5C48 8013F548 0804FD62 */  j         .L8013F588
/* D5C4C 8013F54C 26310001 */   addiu    $s1, $s1, 1
.L8013F550:
/* D5C50 8013F550 5467000A */  bnel      $v1, $a3, .L8013F57C
/* D5C54 8013F554 24A50008 */   addiu    $a1, $a1, 8
/* D5C58 8013F558 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* D5C5C 8013F55C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* D5C60 8013F560 80420070 */  lb        $v0, 0x70($v0)
/* D5C64 8013F564 1040FFAE */  beqz      $v0, .L8013F420
/* D5C68 8013F568 00111C00 */   sll      $v1, $s1, 0x10
/* D5C6C 8013F56C 96020002 */  lhu       $v0, 2($s0)
/* D5C70 8013F570 00431025 */  or        $v0, $v0, $v1
/* D5C74 8013F574 0804FD62 */  j         .L8013F588
/* D5C78 8013F578 AE020000 */   sw       $v0, ($s0)
.L8013F57C:
/* D5C7C 8013F57C 24840008 */  addiu     $a0, $a0, 8
/* D5C80 8013F580 0804FD19 */  j         .L8013F464
/* D5C84 8013F584 26310001 */   addiu    $s1, $s1, 1
.L8013F588:
/* D5C88 8013F588 2A2200C0 */  slti      $v0, $s1, 0xc0
/* D5C8C 8013F58C 14400003 */  bnez      $v0, .L8013F59C
/* D5C90 8013F590 26100004 */   addiu    $s0, $s0, 4
.L8013F594:
/* D5C94 8013F594 0804FD65 */  j         .L8013F594
/* D5C98 8013F598 00000000 */   nop
.L8013F59C:
/* D5C9C 8013F59C 3C048015 */  lui       $a0, %hi(D_801512D0)
/* D5CA0 8013F5A0 8C8412D0 */  lw        $a0, %lo(D_801512D0)($a0)
/* D5CA4 8013F5A4 0000882D */  daddu     $s1, $zero, $zero
/* D5CA8 8013F5A8 24850004 */  addiu     $a1, $a0, 4
.L8013F5AC:
/* D5CAC 8013F5AC 8C830000 */  lw        $v1, ($a0)
/* D5CB0 8013F5B0 2402FFFF */  addiu     $v0, $zero, -1
/* D5CB4 8013F5B4 14620036 */  bne       $v1, $v0, .L8013F690
/* D5CB8 8013F5B8 00000000 */   nop
/* D5CBC 8013F5BC 3C038015 */  lui       $v1, %hi(D_8015133C)
/* D5CC0 8013F5C0 8C63133C */  lw        $v1, %lo(D_8015133C)($v1)
/* D5CC4 8013F5C4 3C028015 */  lui       $v0, %hi(D_80151314)
/* D5CC8 8013F5C8 8C421314 */  lw        $v0, %lo(D_80151314)($v0)
/* D5CCC 8013F5CC AC940000 */  sw        $s4, ($a0)
/* D5CD0 8013F5D0 8C630000 */  lw        $v1, ($v1)
/* D5CD4 8013F5D4 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* D5CD8 8013F5D8 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* D5CDC 8013F5DC 00431021 */  addu      $v0, $v0, $v1
/* D5CE0 8013F5E0 ACA20000 */  sw        $v0, ($a1)
/* D5CE4 8013F5E4 80820070 */  lb        $v0, 0x70($a0)
/* D5CE8 8013F5E8 14400004 */  bnez      $v0, .L8013F5FC
/* D5CEC 8013F5EC 00000000 */   nop
/* D5CF0 8013F5F0 3C048015 */  lui       $a0, %hi(D_8014EFC4)
/* D5CF4 8013F5F4 0804FD84 */  j         .L8013F610
/* D5CF8 8013F5F8 8C84EFC4 */   lw       $a0, %lo(D_8014EFC4)($a0)
.L8013F5FC:
/* D5CFC 8013F5FC 3C028015 */  lui       $v0, %hi(D_8014EFC4)
/* D5D00 8013F600 8C42EFC4 */  lw        $v0, %lo(D_8014EFC4)($v0)
/* D5D04 8013F604 00021FC2 */  srl       $v1, $v0, 0x1f
/* D5D08 8013F608 00431021 */  addu      $v0, $v0, $v1
/* D5D0C 8013F60C 00022043 */  sra       $a0, $v0, 1
.L8013F610:
/* D5D10 8013F610 3C028015 */  lui       $v0, %hi(D_8015133C)
/* D5D14 8013F614 8C42133C */  lw        $v0, %lo(D_8015133C)($v0)
/* D5D18 8013F618 8C420000 */  lw        $v0, ($v0)
/* D5D1C 8013F61C 24420020 */  addiu     $v0, $v0, 0x20
/* D5D20 8013F620 0044102A */  slt       $v0, $v0, $a0
/* D5D24 8013F624 14400003 */  bnez      $v0, .L8013F634
/* D5D28 8013F628 00000000 */   nop
.L8013F62C:
/* D5D2C 8013F62C 0804FD8B */  j         .L8013F62C
/* D5D30 8013F630 00000000 */   nop
.L8013F634:
/* D5D34 8013F634 3C04001D */  lui       $a0, 0x1d
/* D5D38 8013F638 2484C310 */  addiu     $a0, $a0, -0x3cf0
/* D5D3C 8013F63C 02842021 */  addu      $a0, $s4, $a0
/* D5D40 8013F640 8CA50000 */  lw        $a1, ($a1)
/* D5D44 8013F644 0C017D24 */  jal       nuPiReadRom
/* D5D48 8013F648 24060020 */   addiu    $a2, $zero, 0x20
/* D5D4C 8013F64C 3C038015 */  lui       $v1, %hi(D_8015133C)
/* D5D50 8013F650 8C63133C */  lw        $v1, %lo(D_8015133C)($v1)
/* D5D54 8013F654 8C620000 */  lw        $v0, ($v1)
/* D5D58 8013F658 24420020 */  addiu     $v0, $v0, 0x20
/* D5D5C 8013F65C AC620000 */  sw        $v0, ($v1)
/* D5D60 8013F660 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* D5D64 8013F664 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* D5D68 8013F668 80420070 */  lb        $v0, 0x70($v0)
/* D5D6C 8013F66C 14400003 */  bnez      $v0, .L8013F67C
/* D5D70 8013F670 00111C00 */   sll      $v1, $s1, 0x10
/* D5D74 8013F674 0804FDA2 */  j         .L8013F688
/* D5D78 8013F678 AE110000 */   sw       $s1, ($s0)
.L8013F67C:
/* D5D7C 8013F67C 96020002 */  lhu       $v0, 2($s0)
/* D5D80 8013F680 00431025 */  or        $v0, $v0, $v1
/* D5D84 8013F684 AE020000 */  sw        $v0, ($s0)
.L8013F688:
/* D5D88 8013F688 0804FDB2 */  j         .L8013F6C8
/* D5D8C 8013F68C 26310001 */   addiu    $s1, $s1, 1
.L8013F690:
/* D5D90 8013F690 5474000A */  bnel      $v1, $s4, .L8013F6BC
/* D5D94 8013F694 24A50008 */   addiu    $a1, $a1, 8
/* D5D98 8013F698 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* D5D9C 8013F69C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* D5DA0 8013F6A0 80420070 */  lb        $v0, 0x70($v0)
/* D5DA4 8013F6A4 1040FF60 */  beqz      $v0, .L8013F428
/* D5DA8 8013F6A8 00111C00 */   sll      $v1, $s1, 0x10
/* D5DAC 8013F6AC 96020002 */  lhu       $v0, 2($s0)
/* D5DB0 8013F6B0 00431025 */  or        $v0, $v0, $v1
/* D5DB4 8013F6B4 0804FDB2 */  j         .L8013F6C8
/* D5DB8 8013F6B8 AE020000 */   sw       $v0, ($s0)
.L8013F6BC:
/* D5DBC 8013F6BC 24840008 */  addiu     $a0, $a0, 8
/* D5DC0 8013F6C0 0804FD6B */  j         .L8013F5AC
/* D5DC4 8013F6C4 26310001 */   addiu    $s1, $s1, 1
.L8013F6C8:
/* D5DC8 8013F6C8 2A2200C0 */  slti      $v0, $s1, 0xc0
/* D5DCC 8013F6CC 1440FF2F */  bnez      $v0, L8013F38C_D5A8C
/* D5DD0 8013F6D0 26100004 */   addiu    $s0, $s0, 4
.L8013F6D4:
/* D5DD4 8013F6D4 0804FDB5 */  j         .L8013F6D4
/* D5DD8 8013F6D8 00000000 */   nop
glabel L8013F6DC_D5DDC
/* D5DDC 8013F6DC 8FBF002C */  lw        $ra, 0x2c($sp)
/* D5DE0 8013F6E0 8FB60028 */  lw        $s6, 0x28($sp)
/* D5DE4 8013F6E4 8FB50024 */  lw        $s5, 0x24($sp)
/* D5DE8 8013F6E8 8FB40020 */  lw        $s4, 0x20($sp)
/* D5DEC 8013F6EC 8FB3001C */  lw        $s3, 0x1c($sp)
/* D5DF0 8013F6F0 8FB20018 */  lw        $s2, 0x18($sp)
/* D5DF4 8013F6F4 8FB10014 */  lw        $s1, 0x14($sp)
/* D5DF8 8013F6F8 8FB00010 */  lw        $s0, 0x10($sp)
/* D5DFC 8013F6FC 03E00008 */  jr        $ra
/* D5E00 8013F700 27BD0030 */   addiu    $sp, $sp, 0x30
