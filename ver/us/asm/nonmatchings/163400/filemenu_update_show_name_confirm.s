.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_update_show_name_confirm
/* 16452C 80243CCC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 164530 80243CD0 AFB5003C */  sw        $s5, 0x3c($sp)
/* 164534 80243CD4 00E0A82D */  daddu     $s5, $a3, $zero
/* 164538 80243CD8 3C06E300 */  lui       $a2, 0xe300
/* 16453C 80243CDC 34C60A01 */  ori       $a2, $a2, 0xa01
/* 164540 80243CE0 3C09FCFF */  lui       $t1, 0xfcff
/* 164544 80243CE4 3529FFFF */  ori       $t1, $t1, 0xffff
/* 164548 80243CE8 3C07FFFD */  lui       $a3, 0xfffd
/* 16454C 80243CEC 34E7F6FB */  ori       $a3, $a3, 0xf6fb
/* 164550 80243CF0 3C0AE200 */  lui       $t2, 0xe200
/* 164554 80243CF4 354A001C */  ori       $t2, $t2, 0x1c
/* 164558 80243CF8 3C080050 */  lui       $t0, 0x50
/* 16455C 80243CFC 35084340 */  ori       $t0, $t0, 0x4340
/* 164560 80243D00 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 164564 80243D04 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* 164568 80243D08 3C038016 */  lui       $v1, %hi(gWindows)
/* 16456C 80243D0C 24639D50 */  addiu     $v1, $v1, %lo(gWindows)
/* 164570 80243D10 00042140 */  sll       $a0, $a0, 5
/* 164574 80243D14 AFB40038 */  sw        $s4, 0x38($sp)
/* 164578 80243D18 0083A021 */  addu      $s4, $a0, $v1
/* 16457C 80243D1C 3C03E700 */  lui       $v1, 0xe700
/* 164580 80243D20 AFBF0040 */  sw        $ra, 0x40($sp)
/* 164584 80243D24 AFB30034 */  sw        $s3, 0x34($sp)
/* 164588 80243D28 AFB20030 */  sw        $s2, 0x30($sp)
/* 16458C 80243D2C AFB1002C */  sw        $s1, 0x2c($sp)
/* 164590 80243D30 AFB00028 */  sw        $s0, 0x28($sp)
/* 164594 80243D34 8CA20000 */  lw        $v0, ($a1)
/* 164598 80243D38 9293001C */  lbu       $s3, 0x1c($s4)
/* 16459C 80243D3C 0040202D */  daddu     $a0, $v0, $zero
/* 1645A0 80243D40 24420008 */  addiu     $v0, $v0, 8
/* 1645A4 80243D44 ACA20000 */  sw        $v0, ($a1)
/* 1645A8 80243D48 AC830000 */  sw        $v1, ($a0)
/* 1645AC 80243D4C 24430008 */  addiu     $v1, $v0, 8
/* 1645B0 80243D50 AC800004 */  sw        $zero, 4($a0)
/* 1645B4 80243D54 ACA30000 */  sw        $v1, ($a1)
/* 1645B8 80243D58 24430010 */  addiu     $v1, $v0, 0x10
/* 1645BC 80243D5C AC460000 */  sw        $a2, ($v0)
/* 1645C0 80243D60 AC400004 */  sw        $zero, 4($v0)
/* 1645C4 80243D64 ACA30000 */  sw        $v1, ($a1)
/* 1645C8 80243D68 24430018 */  addiu     $v1, $v0, 0x18
/* 1645CC 80243D6C AC490008 */  sw        $t1, 8($v0)
/* 1645D0 80243D70 AC47000C */  sw        $a3, 0xc($v0)
/* 1645D4 80243D74 ACA30000 */  sw        $v1, ($a1)
/* 1645D8 80243D78 24430020 */  addiu     $v1, $v0, 0x20
/* 1645DC 80243D7C AC4A0010 */  sw        $t2, 0x10($v0)
/* 1645E0 80243D80 AC480014 */  sw        $t0, 0x14($v0)
/* 1645E4 80243D84 ACA30000 */  sw        $v1, ($a1)
/* 1645E8 80243D88 3C03FA00 */  lui       $v1, 0xfa00
/* 1645EC 80243D8C AC430018 */  sw        $v1, 0x18($v0)
/* 1645F0 80243D90 2403008C */  addiu     $v1, $zero, 0x8c
/* 1645F4 80243D94 AC43001C */  sw        $v1, 0x1c($v0)
/* 1645F8 80243D98 2A62000A */  slti      $v0, $s3, 0xa
/* 1645FC 80243D9C 1040002D */  beqz      $v0, .L80243E54
/* 164600 80243DA0 0000202D */   daddu    $a0, $zero, $zero
/* 164604 80243DA4 0080282D */  daddu     $a1, $a0, $zero
/* 164608 80243DA8 24060500 */  addiu     $a2, $zero, 0x500
/* 16460C 80243DAC 00138040 */  sll       $s0, $s3, 1
/* 164610 80243DB0 02138021 */  addu      $s0, $s0, $s3
/* 164614 80243DB4 00109100 */  sll       $s2, $s0, 4
/* 164618 80243DB8 0240382D */  daddu     $a3, $s2, $zero
/* 16461C 80243DBC 00108080 */  sll       $s0, $s0, 2
/* 164620 80243DC0 AFA00010 */  sw        $zero, 0x10($sp)
/* 164624 80243DC4 AFA00014 */  sw        $zero, 0x14($sp)
/* 164628 80243DC8 AFA00018 */  sw        $zero, 0x18($sp)
/* 16462C 80243DCC AFA0001C */  sw        $zero, 0x1c($sp)
/* 164630 80243DD0 0C090AE8 */  jal       mainmenu_draw_rect
/* 164634 80243DD4 AFA00020 */   sw       $zero, 0x20($sp)
/* 164638 80243DD8 0000202D */  daddu     $a0, $zero, $zero
/* 16463C 80243DDC 241100F0 */  addiu     $s1, $zero, 0xf0
/* 164640 80243DE0 02308823 */  subu      $s1, $s1, $s0
/* 164644 80243DE4 00118880 */  sll       $s1, $s1, 2
/* 164648 80243DE8 0220282D */  daddu     $a1, $s1, $zero
/* 16464C 80243DEC 24060500 */  addiu     $a2, $zero, 0x500
/* 164650 80243DF0 240703C0 */  addiu     $a3, $zero, 0x3c0
/* 164654 80243DF4 AFA00010 */  sw        $zero, 0x10($sp)
/* 164658 80243DF8 AFA00014 */  sw        $zero, 0x14($sp)
/* 16465C 80243DFC AFA00018 */  sw        $zero, 0x18($sp)
/* 164660 80243E00 AFA0001C */  sw        $zero, 0x1c($sp)
/* 164664 80243E04 0C090AE8 */  jal       mainmenu_draw_rect
/* 164668 80243E08 AFA00020 */   sw       $zero, 0x20($sp)
/* 16466C 80243E0C 0000202D */  daddu     $a0, $zero, $zero
/* 164670 80243E10 0240282D */  daddu     $a1, $s2, $zero
/* 164674 80243E14 00133180 */  sll       $a2, $s3, 6
/* 164678 80243E18 0220382D */  daddu     $a3, $s1, $zero
/* 16467C 80243E1C AFA00010 */  sw        $zero, 0x10($sp)
/* 164680 80243E20 AFA00014 */  sw        $zero, 0x14($sp)
/* 164684 80243E24 AFA00018 */  sw        $zero, 0x18($sp)
/* 164688 80243E28 AFA0001C */  sw        $zero, 0x1c($sp)
/* 16468C 80243E2C 0C090AE8 */  jal       mainmenu_draw_rect
/* 164690 80243E30 AFA00020 */   sw       $zero, 0x20($sp)
/* 164694 80243E34 00131100 */  sll       $v0, $s3, 4
/* 164698 80243E38 24040140 */  addiu     $a0, $zero, 0x140
/* 16469C 80243E3C 00822023 */  subu      $a0, $a0, $v0
/* 1646A0 80243E40 00042080 */  sll       $a0, $a0, 2
/* 1646A4 80243E44 0240282D */  daddu     $a1, $s2, $zero
/* 1646A8 80243E48 24060500 */  addiu     $a2, $zero, 0x500
/* 1646AC 80243E4C 08090F98 */  j         .L80243E60
/* 1646B0 80243E50 0220382D */   daddu    $a3, $s1, $zero
.L80243E54:
/* 1646B4 80243E54 0080282D */  daddu     $a1, $a0, $zero
/* 1646B8 80243E58 24060500 */  addiu     $a2, $zero, 0x500
/* 1646BC 80243E5C 240703C0 */  addiu     $a3, $zero, 0x3c0
.L80243E60:
/* 1646C0 80243E60 AFA00010 */  sw        $zero, 0x10($sp)
/* 1646C4 80243E64 AFA00014 */  sw        $zero, 0x14($sp)
/* 1646C8 80243E68 AFA00018 */  sw        $zero, 0x18($sp)
/* 1646CC 80243E6C AFA0001C */  sw        $zero, 0x1c($sp)
/* 1646D0 80243E70 0C090AE8 */  jal       mainmenu_draw_rect
/* 1646D4 80243E74 AFA00020 */   sw       $zero, 0x20($sp)
/* 1646D8 80243E78 2663FFF6 */  addiu     $v1, $s3, -0xa
/* 1646DC 80243E7C 2C62000A */  sltiu     $v0, $v1, 0xa
/* 1646E0 80243E80 1040000C */  beqz      $v0, .L80243EB4
/* 1646E4 80243E84 2A620014 */   slti     $v0, $s3, 0x14
/* 1646E8 80243E88 92820000 */  lbu       $v0, ($s4)
/* 1646EC 80243E8C 304200FB */  andi      $v0, $v0, 0xfb
/* 1646F0 80243E90 A2820000 */  sb        $v0, ($s4)
/* 1646F4 80243E94 00031040 */  sll       $v0, $v1, 1
/* 1646F8 80243E98 3C038025 */  lui       $v1, %hi(D_80249D34)
/* 1646FC 80243E9C 00621821 */  addu      $v1, $v1, $v0
/* 164700 80243EA0 84639D34 */  lh        $v1, %lo(D_80249D34)($v1)
/* 164704 80243EA4 8EA20000 */  lw        $v0, ($s5)
/* 164708 80243EA8 00431023 */  subu      $v0, $v0, $v1
/* 16470C 80243EAC AEA20000 */  sw        $v0, ($s5)
/* 164710 80243EB0 2A620014 */  slti      $v0, $s3, 0x14
.L80243EB4:
/* 164714 80243EB4 14400004 */  bnez      $v0, .L80243EC8
/* 164718 80243EB8 00000000 */   nop
/* 16471C 80243EBC 92820000 */  lbu       $v0, ($s4)
/* 164720 80243EC0 304200F7 */  andi      $v0, $v0, 0xf7
/* 164724 80243EC4 A2820000 */  sb        $v0, ($s4)
.L80243EC8:
/* 164728 80243EC8 8FBF0040 */  lw        $ra, 0x40($sp)
/* 16472C 80243ECC 8FB5003C */  lw        $s5, 0x3c($sp)
/* 164730 80243ED0 8FB40038 */  lw        $s4, 0x38($sp)
/* 164734 80243ED4 8FB30034 */  lw        $s3, 0x34($sp)
/* 164738 80243ED8 8FB20030 */  lw        $s2, 0x30($sp)
/* 16473C 80243EDC 8FB1002C */  lw        $s1, 0x2c($sp)
/* 164740 80243EE0 8FB00028 */  lw        $s0, 0x28($sp)
/* 164744 80243EE4 03E00008 */  jr        $ra
/* 164748 80243EE8 27BD0048 */   addiu    $sp, $sp, 0x48
