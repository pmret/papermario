.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80143C48
/* DA348 80143C48 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* DA34C 80143C4C AFBE0040 */  sw        $fp, 0x40($sp)
/* DA350 80143C50 0080F02D */  daddu     $fp, $a0, $zero
/* DA354 80143C54 AFB10024 */  sw        $s1, 0x24($sp)
/* DA358 80143C58 00C0882D */  daddu     $s1, $a2, $zero
/* DA35C 80143C5C 3C02800B */  lui       $v0, %hi(gCameras)
/* DA360 80143C60 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* DA364 80143C64 00111880 */  sll       $v1, $s1, 2
/* DA368 80143C68 00711821 */  addu      $v1, $v1, $s1
/* DA36C 80143C6C 00031880 */  sll       $v1, $v1, 2
/* DA370 80143C70 00711823 */  subu      $v1, $v1, $s1
/* DA374 80143C74 000320C0 */  sll       $a0, $v1, 3
/* DA378 80143C78 00641821 */  addu      $v1, $v1, $a0
/* DA37C 80143C7C 000318C0 */  sll       $v1, $v1, 3
/* DA380 80143C80 AFB60038 */  sw        $s6, 0x38($sp)
/* DA384 80143C84 0062B021 */  addu      $s6, $v1, $v0
/* DA388 80143C88 AFBF0044 */  sw        $ra, 0x44($sp)
/* DA38C 80143C8C AFB7003C */  sw        $s7, 0x3c($sp)
/* DA390 80143C90 AFB50034 */  sw        $s5, 0x34($sp)
/* DA394 80143C94 AFB40030 */  sw        $s4, 0x30($sp)
/* DA398 80143C98 AFB3002C */  sw        $s3, 0x2c($sp)
/* DA39C 80143C9C AFB20028 */  sw        $s2, 0x28($sp)
/* DA3A0 80143CA0 18A00133 */  blez      $a1, .L80144170
/* DA3A4 80143CA4 AFB00020 */   sw       $s0, 0x20($sp)
/* DA3A8 80143CA8 96C20000 */  lhu       $v0, ($s6)
/* DA3AC 80143CAC 1040014E */  beqz      $v0, .L801441E8
/* DA3B0 80143CB0 30420002 */   andi     $v0, $v0, 2
/* DA3B4 80143CB4 1440014C */  bnez      $v0, .L801441E8
/* DA3B8 80143CB8 3C02DC08 */   lui      $v0, 0xdc08
/* DA3BC 80143CBC 34420008 */  ori       $v0, $v0, 8
/* DA3C0 80143CC0 3C04D9C0 */  lui       $a0, 0xd9c0
/* DA3C4 80143CC4 3484F9FB */  ori       $a0, $a0, 0xf9fb
/* DA3C8 80143CC8 3C05E300 */  lui       $a1, 0xe300
/* DA3CC 80143CCC 34A50800 */  ori       $a1, $a1, 0x800
/* DA3D0 80143CD0 3C06E300 */  lui       $a2, 0xe300
/* DA3D4 80143CD4 34C61001 */  ori       $a2, $a2, 0x1001
/* DA3D8 80143CD8 3C07E300 */  lui       $a3, 0xe300
/* DA3DC 80143CDC 34E71201 */  ori       $a3, $a3, 0x1201
/* DA3E0 80143CE0 3C0AFCFF */  lui       $t2, 0xfcff
/* DA3E4 80143CE4 354AFFFF */  ori       $t2, $t2, 0xffff
/* DA3E8 80143CE8 3C08FFFE */  lui       $t0, 0xfffe
/* DA3EC 80143CEC 3508793C */  ori       $t0, $t0, 0x793c
/* DA3F0 80143CF0 3C0BE200 */  lui       $t3, 0xe200
/* DA3F4 80143CF4 356B001C */  ori       $t3, $t3, 0x1c
/* DA3F8 80143CF8 3C090F0A */  lui       $t1, 0xf0a
/* DA3FC 80143CFC 35294000 */  ori       $t1, $t1, 0x4000
/* DA400 80143D00 3C0CDB04 */  lui       $t4, 0xdb04
/* DA404 80143D04 358C0004 */  ori       $t4, $t4, 4
/* DA408 80143D08 3C0DDB04 */  lui       $t5, 0xdb04
/* DA40C 80143D0C 35AD000C */  ori       $t5, $t5, 0xc
/* DA410 80143D10 3C0EDB04 */  lui       $t6, 0xdb04
/* DA414 80143D14 35CE0014 */  ori       $t6, $t6, 0x14
/* DA418 80143D18 3C0FDB04 */  lui       $t7, 0xdb04
/* DA41C 80143D1C 35EF001C */  ori       $t7, $t7, 0x1c
/* DA420 80143D20 3C14E300 */  lui       $s4, 0xe300
/* DA424 80143D24 36940A01 */  ori       $s4, $s4, 0xa01
/* DA428 80143D28 3C15FF10 */  lui       $s5, 0xff10
/* DA42C 80143D2C 36B5013F */  ori       $s5, $s5, 0x13f
/* DA430 80143D30 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* DA434 80143D34 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* DA438 80143D38 8E500000 */  lw        $s0, ($s2)
/* DA43C 80143D3C 3C13E700 */  lui       $s3, 0xe700
/* DA440 80143D40 3C01800A */  lui       $at, %hi(D_8009A634)
/* DA444 80143D44 A431A634 */  sh        $s1, %lo(D_8009A634)($at)
/* DA448 80143D48 0200182D */  daddu     $v1, $s0, $zero
/* DA44C 80143D4C 26100008 */  addiu     $s0, $s0, 8
/* DA450 80143D50 AE500000 */  sw        $s0, ($s2)
/* DA454 80143D54 AC620000 */  sw        $v0, ($v1)
/* DA458 80143D58 26C200A0 */  addiu     $v0, $s6, 0xa0
/* DA45C 80143D5C AC620004 */  sw        $v0, 4($v1)
/* DA460 80143D60 26020008 */  addiu     $v0, $s0, 8
/* DA464 80143D64 AE420000 */  sw        $v0, ($s2)
/* DA468 80143D68 26020010 */  addiu     $v0, $s0, 0x10
/* DA46C 80143D6C AE040000 */  sw        $a0, ($s0)
/* DA470 80143D70 AE000004 */  sw        $zero, 4($s0)
/* DA474 80143D74 AE420000 */  sw        $v0, ($s2)
/* DA478 80143D78 3C02D700 */  lui       $v0, 0xd700
/* DA47C 80143D7C AE020008 */  sw        $v0, 8($s0)
/* DA480 80143D80 26020018 */  addiu     $v0, $s0, 0x18
/* DA484 80143D84 AE00000C */  sw        $zero, 0xc($s0)
/* DA488 80143D88 AE420000 */  sw        $v0, ($s2)
/* DA48C 80143D8C 26020020 */  addiu     $v0, $s0, 0x20
/* DA490 80143D90 AE050010 */  sw        $a1, 0x10($s0)
/* DA494 80143D94 AE000014 */  sw        $zero, 0x14($s0)
/* DA498 80143D98 AE420000 */  sw        $v0, ($s2)
/* DA49C 80143D9C 26020028 */  addiu     $v0, $s0, 0x28
/* DA4A0 80143DA0 AE060018 */  sw        $a2, 0x18($s0)
/* DA4A4 80143DA4 AE00001C */  sw        $zero, 0x1c($s0)
/* DA4A8 80143DA8 AE420000 */  sw        $v0, ($s2)
/* DA4AC 80143DAC 24022000 */  addiu     $v0, $zero, 0x2000
/* DA4B0 80143DB0 AE020024 */  sw        $v0, 0x24($s0)
/* DA4B4 80143DB4 26020030 */  addiu     $v0, $s0, 0x30
/* DA4B8 80143DB8 AE070020 */  sw        $a3, 0x20($s0)
/* DA4BC 80143DBC AE420000 */  sw        $v0, ($s2)
/* DA4C0 80143DC0 26020038 */  addiu     $v0, $s0, 0x38
/* DA4C4 80143DC4 AE0A0028 */  sw        $t2, 0x28($s0)
/* DA4C8 80143DC8 AE08002C */  sw        $t0, 0x2c($s0)
/* DA4CC 80143DCC AE420000 */  sw        $v0, ($s2)
/* DA4D0 80143DD0 26020040 */  addiu     $v0, $s0, 0x40
/* DA4D4 80143DD4 24030002 */  addiu     $v1, $zero, 2
/* DA4D8 80143DD8 AE0B0030 */  sw        $t3, 0x30($s0)
/* DA4DC 80143DDC AE090034 */  sw        $t1, 0x34($s0)
/* DA4E0 80143DE0 AE420000 */  sw        $v0, ($s2)
/* DA4E4 80143DE4 26020048 */  addiu     $v0, $s0, 0x48
/* DA4E8 80143DE8 AE0C0038 */  sw        $t4, 0x38($s0)
/* DA4EC 80143DEC AE03003C */  sw        $v1, 0x3c($s0)
/* DA4F0 80143DF0 AE420000 */  sw        $v0, ($s2)
/* DA4F4 80143DF4 26020050 */  addiu     $v0, $s0, 0x50
/* DA4F8 80143DF8 AE030044 */  sw        $v1, 0x44($s0)
/* DA4FC 80143DFC 3403FFFE */  ori       $v1, $zero, 0xfffe
/* DA500 80143E00 AE0D0040 */  sw        $t5, 0x40($s0)
/* DA504 80143E04 AE420000 */  sw        $v0, ($s2)
/* DA508 80143E08 AE0E0048 */  sw        $t6, 0x48($s0)
/* DA50C 80143E0C 3C04800A */  lui       $a0, %hi(nuGfxZBuffer)
/* DA510 80143E10 8C84A5DC */  lw        $a0, %lo(nuGfxZBuffer)($a0)
/* DA514 80143E14 26020058 */  addiu     $v0, $s0, 0x58
/* DA518 80143E18 AE03004C */  sw        $v1, 0x4c($s0)
/* DA51C 80143E1C AE420000 */  sw        $v0, ($s2)
/* DA520 80143E20 26020060 */  addiu     $v0, $s0, 0x60
/* DA524 80143E24 AE0F0050 */  sw        $t7, 0x50($s0)
/* DA528 80143E28 AE030054 */  sw        $v1, 0x54($s0)
/* DA52C 80143E2C AE420000 */  sw        $v0, ($s2)
/* DA530 80143E30 26020068 */  addiu     $v0, $s0, 0x68
/* DA534 80143E34 AE130058 */  sw        $s3, 0x58($s0)
/* DA538 80143E38 AE00005C */  sw        $zero, 0x5c($s0)
/* DA53C 80143E3C AE420000 */  sw        $v0, ($s2)
/* DA540 80143E40 3C020030 */  lui       $v0, 0x30
/* DA544 80143E44 AE020064 */  sw        $v0, 0x64($s0)
/* DA548 80143E48 26020070 */  addiu     $v0, $s0, 0x70
/* DA54C 80143E4C AE140060 */  sw        $s4, 0x60($s0)
/* DA550 80143E50 AE420000 */  sw        $v0, ($s2)
/* DA554 80143E54 0C0187A4 */  jal       osVirtualToPhysical
/* DA558 80143E58 AE150068 */   sw       $s5, 0x68($s0)
/* DA55C 80143E5C 3C05FFFC */  lui       $a1, 0xfffc
/* DA560 80143E60 8E510000 */  lw        $s1, ($s2)
/* DA564 80143E64 34A5FFFC */  ori       $a1, $a1, 0xfffc
/* DA568 80143E68 AE02006C */  sw        $v0, 0x6c($s0)
/* DA56C 80143E6C 3C02F700 */  lui       $v0, 0xf700
/* DA570 80143E70 3C04800A */  lui       $a0, %hi(D_8009A64C)
/* DA574 80143E74 8C84A64C */  lw        $a0, %lo(D_8009A64C)($a0)
/* DA578 80143E78 0220182D */  daddu     $v1, $s1, $zero
/* DA57C 80143E7C 26310008 */  addiu     $s1, $s1, 8
/* DA580 80143E80 AE510000 */  sw        $s1, ($s2)
/* DA584 80143E84 AC620000 */  sw        $v0, ($v1)
/* DA588 80143E88 26220008 */  addiu     $v0, $s1, 8
/* DA58C 80143E8C AC650004 */  sw        $a1, 4($v1)
/* DA590 80143E90 AE420000 */  sw        $v0, ($s2)
/* DA594 80143E94 86C3000E */  lh        $v1, 0xe($s6)
/* DA598 80143E98 86C5000A */  lh        $a1, 0xa($s6)
/* DA59C 80143E9C 26220010 */  addiu     $v0, $s1, 0x10
/* DA5A0 80143EA0 AE420000 */  sw        $v0, ($s2)
/* DA5A4 80143EA4 86C20010 */  lh        $v0, 0x10($s6)
/* DA5A8 80143EA8 00651821 */  addu      $v1, $v1, $a1
/* DA5AC 80143EAC 2463FFFF */  addiu     $v1, $v1, -1
/* DA5B0 80143EB0 306303FF */  andi      $v1, $v1, 0x3ff
/* DA5B4 80143EB4 86C5000C */  lh        $a1, 0xc($s6)
/* DA5B8 80143EB8 00031B80 */  sll       $v1, $v1, 0xe
/* DA5BC 80143EBC 00451021 */  addu      $v0, $v0, $a1
/* DA5C0 80143EC0 2442FFFF */  addiu     $v0, $v0, -1
/* DA5C4 80143EC4 304203FF */  andi      $v0, $v0, 0x3ff
/* DA5C8 80143EC8 00021080 */  sll       $v0, $v0, 2
/* DA5CC 80143ECC 3C05F600 */  lui       $a1, 0xf600
/* DA5D0 80143ED0 00451025 */  or        $v0, $v0, $a1
/* DA5D4 80143ED4 00621825 */  or        $v1, $v1, $v0
/* DA5D8 80143ED8 AE230000 */  sw        $v1, ($s1)
/* DA5DC 80143EDC 96C2000E */  lhu       $v0, 0xe($s6)
/* DA5E0 80143EE0 96C50010 */  lhu       $a1, 0x10($s6)
/* DA5E4 80143EE4 26230018 */  addiu     $v1, $s1, 0x18
/* DA5E8 80143EE8 AE430000 */  sw        $v1, ($s2)
/* DA5EC 80143EEC AE330008 */  sw        $s3, 8($s1)
/* DA5F0 80143EF0 AE20000C */  sw        $zero, 0xc($s1)
/* DA5F4 80143EF4 AE350010 */  sw        $s5, 0x10($s1)
/* DA5F8 80143EF8 304203FF */  andi      $v0, $v0, 0x3ff
/* DA5FC 80143EFC 00021380 */  sll       $v0, $v0, 0xe
/* DA600 80143F00 30A503FF */  andi      $a1, $a1, 0x3ff
/* DA604 80143F04 00052880 */  sll       $a1, $a1, 2
/* DA608 80143F08 00451025 */  or        $v0, $v0, $a1
/* DA60C 80143F0C 0C0187A4 */  jal       osVirtualToPhysical
/* DA610 80143F10 AE220004 */   sw       $v0, 4($s1)
/* DA614 80143F14 26D000D4 */  addiu     $s0, $s6, 0xd4
/* DA618 80143F18 8E430000 */  lw        $v1, ($s2)
/* DA61C 80143F1C 44800000 */  mtc1      $zero, $f0
/* DA620 80143F20 3C01447A */  lui       $at, 0x447a
/* DA624 80143F24 44811000 */  mtc1      $at, $f2
/* DA628 80143F28 3C013F80 */  lui       $at, 0x3f80
/* DA62C 80143F2C 44812000 */  mtc1      $at, $f4
/* DA630 80143F30 3C0643A0 */  lui       $a2, 0x43a0
/* DA634 80143F34 3C07C370 */  lui       $a3, 0xc370
/* DA638 80143F38 0200202D */  daddu     $a0, $s0, $zero
/* DA63C 80143F3C AE220014 */  sw        $v0, 0x14($s1)
/* DA640 80143F40 0060102D */  daddu     $v0, $v1, $zero
/* DA644 80143F44 44050000 */  mfc1      $a1, $f0
/* DA648 80143F48 3C01C47A */  lui       $at, 0xc47a
/* DA64C 80143F4C 44810000 */  mtc1      $at, $f0
/* DA650 80143F50 24630008 */  addiu     $v1, $v1, 8
/* DA654 80143F54 AE430000 */  sw        $v1, ($s2)
/* DA658 80143F58 AC530000 */  sw        $s3, ($v0)
/* DA65C 80143F5C AC400004 */  sw        $zero, 4($v0)
/* DA660 80143F60 E7A20018 */  swc1      $f2, 0x18($sp)
/* DA664 80143F64 E7A4001C */  swc1      $f4, 0x1c($sp)
/* DA668 80143F68 AFA50010 */  sw        $a1, 0x10($sp)
/* DA66C 80143F6C 0C018E44 */  jal       guOrthoF
/* DA670 80143F70 E7A00014 */   swc1     $f0, 0x14($sp)
/* DA674 80143F74 0200202D */  daddu     $a0, $s0, $zero
/* DA678 80143F78 3C10800A */  lui       $s0, %hi(gDisplayContext)
/* DA67C 80143F7C 2610A674 */  addiu     $s0, $s0, %lo(gDisplayContext)
/* DA680 80143F80 3C05800A */  lui       $a1, %hi(D_8009A634)
/* DA684 80143F84 84A5A634 */  lh        $a1, %lo(D_8009A634)($a1)
/* DA688 80143F88 8E020000 */  lw        $v0, ($s0)
/* DA68C 80143F8C 00052980 */  sll       $a1, $a1, 6
/* DA690 80143F90 24A50030 */  addiu     $a1, $a1, 0x30
/* DA694 80143F94 0C019D40 */  jal       guMtxF2L
/* DA698 80143F98 00452821 */   addu     $a1, $v0, $a1
/* DA69C 80143F9C 3C03DA38 */  lui       $v1, 0xda38
/* DA6A0 80143FA0 34630007 */  ori       $v1, $v1, 7
/* DA6A4 80143FA4 3C07ED03 */  lui       $a3, 0xed03
/* DA6A8 80143FA8 34E70050 */  ori       $a3, $a3, 0x50
/* DA6AC 80143FAC 3C06004D */  lui       $a2, 0x4d
/* DA6B0 80143FB0 34C60370 */  ori       $a2, $a2, 0x370
/* DA6B4 80143FB4 3C08D9C0 */  lui       $t0, 0xd9c0
/* DA6B8 80143FB8 3508F9FA */  ori       $t0, $t0, 0xf9fa
/* DA6BC 80143FBC 3C0AD9FF */  lui       $t2, 0xd9ff
/* DA6C0 80143FC0 354AFFFF */  ori       $t2, $t2, 0xffff
/* DA6C4 80143FC4 3C090022 */  lui       $t1, 0x22
/* DA6C8 80143FC8 35290005 */  ori       $t1, $t1, 5
/* DA6CC 80143FCC 3C0BDC08 */  lui       $t3, 0xdc08
/* DA6D0 80143FD0 356B060A */  ori       $t3, $t3, 0x60a
/* DA6D4 80143FD4 3C0CDC08 */  lui       $t4, 0xdc08
/* DA6D8 80143FD8 358C090A */  ori       $t4, $t4, 0x90a
/* DA6DC 80143FDC 3C0DD700 */  lui       $t5, 0xd700
/* DA6E0 80143FE0 35AD0002 */  ori       $t5, $t5, 2
/* DA6E4 80143FE4 3C0EE300 */  lui       $t6, 0xe300
/* DA6E8 80143FE8 35CE0F00 */  ori       $t6, $t6, 0xf00
/* DA6EC 80143FEC 3C0FE300 */  lui       $t7, 0xe300
/* DA6F0 80143FF0 35EF0C00 */  ori       $t7, $t7, 0xc00
/* DA6F4 80143FF4 3C11E300 */  lui       $s1, 0xe300
/* DA6F8 80143FF8 36311801 */  ori       $s1, $s1, 0x1801
/* DA6FC 80143FFC 3C15E300 */  lui       $s5, 0xe300
/* DA700 80144000 36B50D01 */  ori       $s5, $s5, 0xd01
/* DA704 80144004 3C16E300 */  lui       $s6, 0xe300
/* DA708 80144008 36D61402 */  ori       $s6, $s6, 0x1402
/* DA70C 8014400C 3C17E300 */  lui       $s7, 0xe300
/* DA710 80144010 36F71700 */  ori       $s7, $s7, 0x1700
/* DA714 80144014 3C18E200 */  lui       $t8, 0xe200
/* DA718 80144018 37181E01 */  ori       $t8, $t8, 0x1e01
/* DA71C 8014401C 8E420000 */  lw        $v0, ($s2)
/* DA720 80144020 3C04800A */  lui       $a0, %hi(D_8009A634)
/* DA724 80144024 8484A634 */  lh        $a0, %lo(D_8009A634)($a0)
/* DA728 80144028 0040282D */  daddu     $a1, $v0, $zero
/* DA72C 8014402C 24420008 */  addiu     $v0, $v0, 8
/* DA730 80144030 00042180 */  sll       $a0, $a0, 6
/* DA734 80144034 AE420000 */  sw        $v0, ($s2)
/* DA738 80144038 ACA30000 */  sw        $v1, ($a1)
/* DA73C 8014403C 8E030000 */  lw        $v1, ($s0)
/* DA740 80144040 24840030 */  addiu     $a0, $a0, 0x30
/* DA744 80144044 00641821 */  addu      $v1, $v1, $a0
/* DA748 80144048 ACA30004 */  sw        $v1, 4($a1)
/* DA74C 8014404C 24430008 */  addiu     $v1, $v0, 8
/* DA750 80144050 AE430000 */  sw        $v1, ($s2)
/* DA754 80144054 24430010 */  addiu     $v1, $v0, 0x10
/* DA758 80144058 AC470000 */  sw        $a3, ($v0)
/* DA75C 8014405C AC460004 */  sw        $a2, 4($v0)
/* DA760 80144060 AE430000 */  sw        $v1, ($s2)
/* DA764 80144064 24430018 */  addiu     $v1, $v0, 0x18
/* DA768 80144068 AC530008 */  sw        $s3, 8($v0)
/* DA76C 8014406C AC40000C */  sw        $zero, 0xc($v0)
/* DA770 80144070 AE430000 */  sw        $v1, ($s2)
/* DA774 80144074 24430020 */  addiu     $v1, $v0, 0x20
/* DA778 80144078 AC540010 */  sw        $s4, 0x10($v0)
/* DA77C 8014407C AC400014 */  sw        $zero, 0x14($v0)
/* DA780 80144080 AE430000 */  sw        $v1, ($s2)
/* DA784 80144084 24430028 */  addiu     $v1, $v0, 0x28
/* DA788 80144088 AC480018 */  sw        $t0, 0x18($v0)
/* DA78C 8014408C AC40001C */  sw        $zero, 0x1c($v0)
/* DA790 80144090 AE430000 */  sw        $v1, ($s2)
/* DA794 80144094 24430030 */  addiu     $v1, $v0, 0x30
/* DA798 80144098 AC4A0020 */  sw        $t2, 0x20($v0)
/* DA79C 8014409C AC490024 */  sw        $t1, 0x24($v0)
/* DA7A0 801440A0 AE430000 */  sw        $v1, ($s2)
/* DA7A4 801440A4 3C03DB02 */  lui       $v1, 0xdb02
/* DA7A8 801440A8 AC430028 */  sw        $v1, 0x28($v0)
/* DA7AC 801440AC 24030018 */  addiu     $v1, $zero, 0x18
/* DA7B0 801440B0 AC43002C */  sw        $v1, 0x2c($v0)
/* DA7B4 801440B4 24430038 */  addiu     $v1, $v0, 0x38
/* DA7B8 801440B8 3C048015 */  lui       $a0, %hi(D_8014F110)
/* DA7BC 801440BC 2484F110 */  addiu     $a0, $a0, %lo(D_8014F110)
/* DA7C0 801440C0 AE430000 */  sw        $v1, ($s2)
/* DA7C4 801440C4 24430040 */  addiu     $v1, $v0, 0x40
/* DA7C8 801440C8 AC440034 */  sw        $a0, 0x34($v0)
/* DA7CC 801440CC 2484FFF8 */  addiu     $a0, $a0, -8
/* DA7D0 801440D0 AC4B0030 */  sw        $t3, 0x30($v0)
/* DA7D4 801440D4 AE430000 */  sw        $v1, ($s2)
/* DA7D8 801440D8 24430048 */  addiu     $v1, $v0, 0x48
/* DA7DC 801440DC AC4C0038 */  sw        $t4, 0x38($v0)
/* DA7E0 801440E0 AC44003C */  sw        $a0, 0x3c($v0)
/* DA7E4 801440E4 AE430000 */  sw        $v1, ($s2)
/* DA7E8 801440E8 2403FFFF */  addiu     $v1, $zero, -1
/* DA7EC 801440EC AC430044 */  sw        $v1, 0x44($v0)
/* DA7F0 801440F0 24430050 */  addiu     $v1, $v0, 0x50
/* DA7F4 801440F4 AC4D0040 */  sw        $t5, 0x40($v0)
/* DA7F8 801440F8 AE430000 */  sw        $v1, ($s2)
/* DA7FC 801440FC 24430058 */  addiu     $v1, $v0, 0x58
/* DA800 80144100 AC4E0048 */  sw        $t6, 0x48($v0)
/* DA804 80144104 AC40004C */  sw        $zero, 0x4c($v0)
/* DA808 80144108 AE430000 */  sw        $v1, ($s2)
/* DA80C 8014410C 3C030008 */  lui       $v1, 8
/* DA810 80144110 AC430054 */  sw        $v1, 0x54($v0)
/* DA814 80144114 24430060 */  addiu     $v1, $v0, 0x60
/* DA818 80144118 AC4F0050 */  sw        $t7, 0x50($v0)
/* DA81C 8014411C AE430000 */  sw        $v1, ($s2)
/* DA820 80144120 240300C0 */  addiu     $v1, $zero, 0xc0
/* DA824 80144124 AC43005C */  sw        $v1, 0x5c($v0)
/* DA828 80144128 24430068 */  addiu     $v1, $v0, 0x68
/* DA82C 8014412C AC510058 */  sw        $s1, 0x58($v0)
/* DA830 80144130 AE430000 */  sw        $v1, ($s2)
/* DA834 80144134 24430070 */  addiu     $v1, $v0, 0x70
/* DA838 80144138 AC550060 */  sw        $s5, 0x60($v0)
/* DA83C 8014413C AC400064 */  sw        $zero, 0x64($v0)
/* DA840 80144140 AE430000 */  sw        $v1, ($s2)
/* DA844 80144144 24030C00 */  addiu     $v1, $zero, 0xc00
/* DA848 80144148 AC43006C */  sw        $v1, 0x6c($v0)
/* DA84C 8014414C 24430078 */  addiu     $v1, $v0, 0x78
/* DA850 80144150 AC560068 */  sw        $s6, 0x68($v0)
/* DA854 80144154 AE430000 */  sw        $v1, ($s2)
/* DA858 80144158 24430080 */  addiu     $v1, $v0, 0x80
/* DA85C 8014415C AC570070 */  sw        $s7, 0x70($v0)
/* DA860 80144160 AC400074 */  sw        $zero, 0x74($v0)
/* DA864 80144164 AE430000 */  sw        $v1, ($s2)
/* DA868 80144168 AC580078 */  sw        $t8, 0x78($v0)
/* DA86C 8014416C AC40007C */  sw        $zero, 0x7c($v0)
.L80144170:
/* DA870 80144170 07C0001D */  bltz      $fp, .L801441E8
/* DA874 80144174 2402F7FF */   addiu    $v0, $zero, -0x801
/* DA878 80144178 03C2F024 */  and       $fp, $fp, $v0
/* DA87C 8014417C 3C038015 */  lui       $v1, %hi(D_80157960)
/* DA880 80144180 8C637960 */  lw        $v1, %lo(D_80157960)($v1)
/* DA884 80144184 001E1080 */  sll       $v0, $fp, 2
/* DA888 80144188 00431021 */  addu      $v0, $v0, $v1
/* DA88C 8014418C 8C440000 */  lw        $a0, ($v0)
/* DA890 80144190 10800015 */  beqz      $a0, .L801441E8
/* DA894 80144194 00000000 */   nop
/* DA898 80144198 8C830000 */  lw        $v1, ($a0)
/* DA89C 8014419C 10600012 */  beqz      $v1, .L801441E8
/* DA8A0 801441A0 30620002 */   andi     $v0, $v1, 2
/* DA8A4 801441A4 14400010 */  bnez      $v0, .L801441E8
/* DA8A8 801441A8 3C021020 */   lui      $v0, 0x1020
/* DA8AC 801441AC 00621024 */  and       $v0, $v1, $v0
/* DA8B0 801441B0 1440000D */  bnez      $v0, .L801441E8
/* DA8B4 801441B4 3C020001 */   lui      $v0, 1
/* DA8B8 801441B8 00621024 */  and       $v0, $v1, $v0
/* DA8BC 801441BC 1040000A */  beqz      $v0, .L801441E8
/* DA8C0 801441C0 30620040 */   andi     $v0, $v1, 0x40
/* DA8C4 801441C4 14400008 */  bnez      $v0, .L801441E8
/* DA8C8 801441C8 00000000 */   nop
/* DA8CC 801441CC 80820045 */  lb        $v0, 0x45($a0)
/* DA8D0 801441D0 04400005 */  bltz      $v0, .L801441E8
/* DA8D4 801441D4 30620080 */   andi     $v0, $v1, 0x80
/* DA8D8 801441D8 10400003 */  beqz      $v0, .L801441E8
/* DA8DC 801441DC 00000000 */   nop
/* DA8E0 801441E0 0C050AFF */  jal       render_menu_icon
/* DA8E4 801441E4 00000000 */   nop
.L801441E8:
/* DA8E8 801441E8 8FBF0044 */  lw        $ra, 0x44($sp)
/* DA8EC 801441EC 8FBE0040 */  lw        $fp, 0x40($sp)
/* DA8F0 801441F0 8FB7003C */  lw        $s7, 0x3c($sp)
/* DA8F4 801441F4 8FB60038 */  lw        $s6, 0x38($sp)
/* DA8F8 801441F8 8FB50034 */  lw        $s5, 0x34($sp)
/* DA8FC 801441FC 8FB40030 */  lw        $s4, 0x30($sp)
/* DA900 80144200 8FB3002C */  lw        $s3, 0x2c($sp)
/* DA904 80144204 8FB20028 */  lw        $s2, 0x28($sp)
/* DA908 80144208 8FB10024 */  lw        $s1, 0x24($sp)
/* DA90C 8014420C 8FB00020 */  lw        $s0, 0x20($sp)
/* DA910 80144210 03E00008 */  jr        $ra
/* DA914 80144214 27BD0048 */   addiu    $sp, $sp, 0x48
