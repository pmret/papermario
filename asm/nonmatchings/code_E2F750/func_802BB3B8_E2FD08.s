.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB3B8_E2FD08
/* E2FD08 802BB3B8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* E2FD0C 802BB3BC AFB40020 */  sw        $s4, 0x20($sp)
/* E2FD10 802BB3C0 0080A02D */  daddu     $s4, $a0, $zero
/* E2FD14 802BB3C4 AFBF0030 */  sw        $ra, 0x30($sp)
/* E2FD18 802BB3C8 AFB7002C */  sw        $s7, 0x2c($sp)
/* E2FD1C 802BB3CC AFB60028 */  sw        $s6, 0x28($sp)
/* E2FD20 802BB3D0 AFB50024 */  sw        $s5, 0x24($sp)
/* E2FD24 802BB3D4 AFB3001C */  sw        $s3, 0x1c($sp)
/* E2FD28 802BB3D8 AFB20018 */  sw        $s2, 0x18($sp)
/* E2FD2C 802BB3DC AFB10014 */  sw        $s1, 0x14($sp)
/* E2FD30 802BB3E0 0C04417A */  jal       get_entity_by_index
/* E2FD34 802BB3E4 AFB00010 */   sw       $s0, 0x10($sp)
/* E2FD38 802BB3E8 3C05E300 */  lui       $a1, 0xe300
/* E2FD3C 802BB3EC 34A51001 */  ori       $a1, $a1, 0x1001
/* E2FD40 802BB3F0 3C06D700 */  lui       $a2, 0xd700
/* E2FD44 802BB3F4 34C60002 */  ori       $a2, $a2, 2
/* E2FD48 802BB3F8 3C08FC20 */  lui       $t0, 0xfc20
/* E2FD4C 802BB3FC 3508A204 */  ori       $t0, $t0, 0xa204
/* E2FD50 802BB400 3C07FF13 */  lui       $a3, 0xff13
/* E2FD54 802BB404 34E7FFFF */  ori       $a3, $a3, 0xffff
/* E2FD58 802BB408 3C09E300 */  lui       $t1, 0xe300
/* E2FD5C 802BB40C 35290D01 */  ori       $t1, $t1, 0xd01
/* E2FD60 802BB410 3C0BE300 */  lui       $t3, 0xe300
/* E2FD64 802BB414 356B0F00 */  ori       $t3, $t3, 0xf00
/* E2FD68 802BB418 3C0CFD88 */  lui       $t4, 0xfd88
/* E2FD6C 802BB41C 358C001F */  ori       $t4, $t4, 0x1f
/* E2FD70 802BB420 3C0AF588 */  lui       $t2, 0xf588
/* E2FD74 802BB424 354A0800 */  ori       $t2, $t2, 0x800
/* E2FD78 802BB428 3C0D0701 */  lui       $t5, 0x701
/* E2FD7C 802BB42C 35AD4050 */  ori       $t5, $t5, 0x4050
/* E2FD80 802BB430 3C0E0707 */  lui       $t6, 0x707
/* E2FD84 802BB434 35CEC07C */  ori       $t6, $t6, 0xc07c
/* E2FD88 802BB438 3C120001 */  lui       $s2, 1
/* E2FD8C 802BB43C 36524050 */  ori       $s2, $s2, 0x4050
/* E2FD90 802BB440 3C150007 */  lui       $s5, 7
/* E2FD94 802BB444 36B5C07C */  ori       $s5, $s5, 0xc07c
/* E2FD98 802BB448 3C0FF588 */  lui       $t7, 0xf588
/* E2FD9C 802BB44C 35EF0880 */  ori       $t7, $t7, 0x880
/* E2FDA0 802BB450 3C160101 */  lui       $s6, 0x101
/* E2FDA4 802BB454 36D64050 */  ori       $s6, $s6, 0x4050
/* E2FDA8 802BB458 3C170107 */  lui       $s7, 0x107
/* E2FDAC 802BB45C 36F7C07C */  ori       $s7, $s7, 0xc07c
/* E2FDB0 802BB460 3C18E300 */  lui       $t8, 0xe300
/* E2FDB4 802BB464 37180C00 */  ori       $t8, $t8, 0xc00
/* E2FDB8 802BB468 3C19E300 */  lui       $t9, 0xe300
/* E2FDBC 802BB46C 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* E2FDC0 802BB470 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* E2FDC4 802BB474 37391201 */  ori       $t9, $t9, 0x1201
/* E2FDC8 802BB478 8E030000 */  lw        $v1, ($s0)
/* E2FDCC 802BB47C 3C13E700 */  lui       $s3, 0xe700
/* E2FDD0 802BB480 0060202D */  daddu     $a0, $v1, $zero
/* E2FDD4 802BB484 24630008 */  addiu     $v1, $v1, 8
/* E2FDD8 802BB488 AE030000 */  sw        $v1, ($s0)
/* E2FDDC 802BB48C 8C510040 */  lw        $s1, 0x40($v0)
/* E2FDE0 802BB490 24620008 */  addiu     $v0, $v1, 8
/* E2FDE4 802BB494 AC930000 */  sw        $s3, ($a0)
/* E2FDE8 802BB498 AC800004 */  sw        $zero, 4($a0)
/* E2FDEC 802BB49C AE020000 */  sw        $v0, ($s0)
/* E2FDF0 802BB4A0 24620010 */  addiu     $v0, $v1, 0x10
/* E2FDF4 802BB4A4 AC650000 */  sw        $a1, ($v1)
/* E2FDF8 802BB4A8 AC600004 */  sw        $zero, 4($v1)
/* E2FDFC 802BB4AC AE020000 */  sw        $v0, ($s0)
/* E2FE00 802BB4B0 2402FFFF */  addiu     $v0, $zero, -1
/* E2FE04 802BB4B4 AC62000C */  sw        $v0, 0xc($v1)
/* E2FE08 802BB4B8 24620018 */  addiu     $v0, $v1, 0x18
/* E2FE0C 802BB4BC AC660008 */  sw        $a2, 8($v1)
/* E2FE10 802BB4C0 AE020000 */  sw        $v0, ($s0)
/* E2FE14 802BB4C4 24620020 */  addiu     $v0, $v1, 0x20
/* E2FE18 802BB4C8 AC680010 */  sw        $t0, 0x10($v1)
/* E2FE1C 802BB4CC AC670014 */  sw        $a3, 0x14($v1)
/* E2FE20 802BB4D0 AE020000 */  sw        $v0, ($s0)
/* E2FE24 802BB4D4 24620028 */  addiu     $v0, $v1, 0x28
/* E2FE28 802BB4D8 AC690018 */  sw        $t1, 0x18($v1)
/* E2FE2C 802BB4DC AC60001C */  sw        $zero, 0x1c($v1)
/* E2FE30 802BB4E0 AE020000 */  sw        $v0, ($s0)
/* E2FE34 802BB4E4 24620030 */  addiu     $v0, $v1, 0x30
/* E2FE38 802BB4E8 AC6B0020 */  sw        $t3, 0x20($v1)
/* E2FE3C 802BB4EC AC600024 */  sw        $zero, 0x24($v1)
/* E2FE40 802BB4F0 AE020000 */  sw        $v0, ($s0)
/* E2FE44 802BB4F4 3C020A00 */  lui       $v0, 0xa00
/* E2FE48 802BB4F8 24420BF0 */  addiu     $v0, $v0, 0xbf0
/* E2FE4C 802BB4FC AC62002C */  sw        $v0, 0x2c($v1)
/* E2FE50 802BB500 24620038 */  addiu     $v0, $v1, 0x38
/* E2FE54 802BB504 AC6C0028 */  sw        $t4, 0x28($v1)
/* E2FE58 802BB508 AE020000 */  sw        $v0, ($s0)
/* E2FE5C 802BB50C 24620040 */  addiu     $v0, $v1, 0x40
/* E2FE60 802BB510 3C05E600 */  lui       $a1, 0xe600
/* E2FE64 802BB514 AC6A0030 */  sw        $t2, 0x30($v1)
/* E2FE68 802BB518 AC6D0034 */  sw        $t5, 0x34($v1)
/* E2FE6C 802BB51C AE020000 */  sw        $v0, ($s0)
/* E2FE70 802BB520 24620048 */  addiu     $v0, $v1, 0x48
/* E2FE74 802BB524 3C04F400 */  lui       $a0, 0xf400
/* E2FE78 802BB528 AC650038 */  sw        $a1, 0x38($v1)
/* E2FE7C 802BB52C AC60003C */  sw        $zero, 0x3c($v1)
/* E2FE80 802BB530 AE020000 */  sw        $v0, ($s0)
/* E2FE84 802BB534 24620050 */  addiu     $v0, $v1, 0x50
/* E2FE88 802BB538 AC640040 */  sw        $a0, 0x40($v1)
/* E2FE8C 802BB53C AC6E0044 */  sw        $t6, 0x44($v1)
/* E2FE90 802BB540 AE020000 */  sw        $v0, ($s0)
/* E2FE94 802BB544 24620058 */  addiu     $v0, $v1, 0x58
/* E2FE98 802BB548 AC730048 */  sw        $s3, 0x48($v1)
/* E2FE9C 802BB54C AC60004C */  sw        $zero, 0x4c($v1)
/* E2FEA0 802BB550 AE020000 */  sw        $v0, ($s0)
/* E2FEA4 802BB554 24620060 */  addiu     $v0, $v1, 0x60
/* E2FEA8 802BB558 AC720054 */  sw        $s2, 0x54($v1)
/* E2FEAC 802BB55C 3C12F200 */  lui       $s2, 0xf200
/* E2FEB0 802BB560 AC6A0050 */  sw        $t2, 0x50($v1)
/* E2FEB4 802BB564 AE020000 */  sw        $v0, ($s0)
/* E2FEB8 802BB568 24620068 */  addiu     $v0, $v1, 0x68
/* E2FEBC 802BB56C AC720058 */  sw        $s2, 0x58($v1)
/* E2FEC0 802BB570 AC75005C */  sw        $s5, 0x5c($v1)
/* E2FEC4 802BB574 AE020000 */  sw        $v0, ($s0)
/* E2FEC8 802BB578 3C020A00 */  lui       $v0, 0xa00
/* E2FECC 802BB57C 24420FF0 */  addiu     $v0, $v0, 0xff0
/* E2FED0 802BB580 AC620064 */  sw        $v0, 0x64($v1)
/* E2FED4 802BB584 24620070 */  addiu     $v0, $v1, 0x70
/* E2FED8 802BB588 AC6C0060 */  sw        $t4, 0x60($v1)
/* E2FEDC 802BB58C AE020000 */  sw        $v0, ($s0)
/* E2FEE0 802BB590 24620078 */  addiu     $v0, $v1, 0x78
/* E2FEE4 802BB594 AC6F0068 */  sw        $t7, 0x68($v1)
/* E2FEE8 802BB598 AC6D006C */  sw        $t5, 0x6c($v1)
/* E2FEEC 802BB59C AE020000 */  sw        $v0, ($s0)
/* E2FEF0 802BB5A0 24620080 */  addiu     $v0, $v1, 0x80
/* E2FEF4 802BB5A4 AC650070 */  sw        $a1, 0x70($v1)
/* E2FEF8 802BB5A8 AC600074 */  sw        $zero, 0x74($v1)
/* E2FEFC 802BB5AC AE020000 */  sw        $v0, ($s0)
/* E2FF00 802BB5B0 24620088 */  addiu     $v0, $v1, 0x88
/* E2FF04 802BB5B4 AC640078 */  sw        $a0, 0x78($v1)
/* E2FF08 802BB5B8 AC6E007C */  sw        $t6, 0x7c($v1)
/* E2FF0C 802BB5BC AE020000 */  sw        $v0, ($s0)
/* E2FF10 802BB5C0 24620090 */  addiu     $v0, $v1, 0x90
/* E2FF14 802BB5C4 AC730080 */  sw        $s3, 0x80($v1)
/* E2FF18 802BB5C8 AC600084 */  sw        $zero, 0x84($v1)
/* E2FF1C 802BB5CC AE020000 */  sw        $v0, ($s0)
/* E2FF20 802BB5D0 24620098 */  addiu     $v0, $v1, 0x98
/* E2FF24 802BB5D4 AC6F0088 */  sw        $t7, 0x88($v1)
/* E2FF28 802BB5D8 AC76008C */  sw        $s6, 0x8c($v1)
/* E2FF2C 802BB5DC AE020000 */  sw        $v0, ($s0)
/* E2FF30 802BB5E0 246200A0 */  addiu     $v0, $v1, 0xa0
/* E2FF34 802BB5E4 AC720090 */  sw        $s2, 0x90($v1)
/* E2FF38 802BB5E8 AC770094 */  sw        $s7, 0x94($v1)
/* E2FF3C 802BB5EC AE020000 */  sw        $v0, ($s0)
/* E2FF40 802BB5F0 3C020008 */  lui       $v0, 8
/* E2FF44 802BB5F4 AC62009C */  sw        $v0, 0x9c($v1)
/* E2FF48 802BB5F8 246200A8 */  addiu     $v0, $v1, 0xa8
/* E2FF4C 802BB5FC AC780098 */  sw        $t8, 0x98($v1)
/* E2FF50 802BB600 AE020000 */  sw        $v0, ($s0)
/* E2FF54 802BB604 24022000 */  addiu     $v0, $zero, 0x2000
/* E2FF58 802BB608 0280202D */  daddu     $a0, $s4, $zero
/* E2FF5C 802BB60C AC7900A0 */  sw        $t9, 0xa0($v1)
/* E2FF60 802BB610 AC6200A4 */  sw        $v0, 0xa4($v1)
/* E2FF64 802BB614 96220090 */  lhu       $v0, 0x90($s1)
/* E2FF68 802BB618 96250092 */  lhu       $a1, 0x92($s1)
/* E2FF6C 802BB61C 30420FFF */  andi      $v0, $v0, 0xfff
/* E2FF70 802BB620 00021300 */  sll       $v0, $v0, 0xc
/* E2FF74 802BB624 30A50FFF */  andi      $a1, $a1, 0xfff
/* E2FF78 802BB628 00B22825 */  or        $a1, $a1, $s2
/* E2FF7C 802BB62C 00451025 */  or        $v0, $v0, $a1
/* E2FF80 802BB630 AC6200A8 */  sw        $v0, 0xa8($v1)
/* E2FF84 802BB634 86220090 */  lh        $v0, 0x90($s1)
/* E2FF88 802BB638 246500B0 */  addiu     $a1, $v1, 0xb0
/* E2FF8C 802BB63C AE050000 */  sw        $a1, ($s0)
/* E2FF90 802BB640 86250092 */  lh        $a1, 0x92($s1)
/* E2FF94 802BB644 2442007C */  addiu     $v0, $v0, 0x7c
/* E2FF98 802BB648 30420FFF */  andi      $v0, $v0, 0xfff
/* E2FF9C 802BB64C 00021300 */  sll       $v0, $v0, 0xc
/* E2FFA0 802BB650 24A5007C */  addiu     $a1, $a1, 0x7c
/* E2FFA4 802BB654 30A50FFF */  andi      $a1, $a1, 0xfff
/* E2FFA8 802BB658 00451025 */  or        $v0, $v0, $a1
/* E2FFAC 802BB65C 0C0AEB80 */  jal       func_802BAE00_E2F750
/* E2FFB0 802BB660 AC6200AC */   sw       $v0, 0xac($v1)
/* E2FFB4 802BB664 8E050000 */  lw        $a1, ($s0)
/* E2FFB8 802BB668 0280202D */  daddu     $a0, $s4, $zero
/* E2FFBC 802BB66C 00A0102D */  daddu     $v0, $a1, $zero
/* E2FFC0 802BB670 AC530000 */  sw        $s3, ($v0)
/* E2FFC4 802BB674 AC400004 */  sw        $zero, 4($v0)
/* E2FFC8 802BB678 96230094 */  lhu       $v1, 0x94($s1)
/* E2FFCC 802BB67C 24A50008 */  addiu     $a1, $a1, 8
/* E2FFD0 802BB680 AE050000 */  sw        $a1, ($s0)
/* E2FFD4 802BB684 96220096 */  lhu       $v0, 0x96($s1)
/* E2FFD8 802BB688 30630FFF */  andi      $v1, $v1, 0xfff
/* E2FFDC 802BB68C 00031B00 */  sll       $v1, $v1, 0xc
/* E2FFE0 802BB690 30420FFF */  andi      $v0, $v0, 0xfff
/* E2FFE4 802BB694 00521025 */  or        $v0, $v0, $s2
/* E2FFE8 802BB698 00621825 */  or        $v1, $v1, $v0
/* E2FFEC 802BB69C ACA30000 */  sw        $v1, ($a1)
/* E2FFF0 802BB6A0 86220094 */  lh        $v0, 0x94($s1)
/* E2FFF4 802BB6A4 24A30008 */  addiu     $v1, $a1, 8
/* E2FFF8 802BB6A8 AE030000 */  sw        $v1, ($s0)
/* E2FFFC 802BB6AC 86230096 */  lh        $v1, 0x96($s1)
/* E30000 802BB6B0 2442007C */  addiu     $v0, $v0, 0x7c
/* E30004 802BB6B4 30420FFF */  andi      $v0, $v0, 0xfff
/* E30008 802BB6B8 00021300 */  sll       $v0, $v0, 0xc
/* E3000C 802BB6BC 2463007C */  addiu     $v1, $v1, 0x7c
/* E30010 802BB6C0 30630FFF */  andi      $v1, $v1, 0xfff
/* E30014 802BB6C4 00431025 */  or        $v0, $v0, $v1
/* E30018 802BB6C8 0C0AEBE1 */  jal       func_802BAF84_E2F8D4
/* E3001C 802BB6CC ACA20004 */   sw       $v0, 4($a1)
/* E30020 802BB6D0 0C0AEC42 */  jal       func_802BB108_E2FA58
/* E30024 802BB6D4 0280202D */   daddu    $a0, $s4, $zero
/* E30028 802BB6D8 8FBF0030 */  lw        $ra, 0x30($sp)
/* E3002C 802BB6DC 8FB7002C */  lw        $s7, 0x2c($sp)
/* E30030 802BB6E0 8FB60028 */  lw        $s6, 0x28($sp)
/* E30034 802BB6E4 8FB50024 */  lw        $s5, 0x24($sp)
/* E30038 802BB6E8 8FB40020 */  lw        $s4, 0x20($sp)
/* E3003C 802BB6EC 8FB3001C */  lw        $s3, 0x1c($sp)
/* E30040 802BB6F0 8FB20018 */  lw        $s2, 0x18($sp)
/* E30044 802BB6F4 8FB10014 */  lw        $s1, 0x14($sp)
/* E30048 802BB6F8 8FB00010 */  lw        $s0, 0x10($sp)
/* E3004C 802BB6FC 03E00008 */  jr        $ra
/* E30050 802BB700 27BD0038 */   addiu    $sp, $sp, 0x38
