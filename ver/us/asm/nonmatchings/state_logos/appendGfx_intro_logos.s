.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_800982C0
.word L800344A8_F8A8, L800344A8_F8A8, L800344A8_F8A8, L80034628_FA28, L80034628_FA28, L80034628_FA28, L800347A8_FBA8, L800347A8_FBA8, L800347A8_FBA8, L800347A8_FBA8

.section .text

glabel appendGfx_intro_logos
/* F7A4 800343A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F7A8 800343A8 3C05E200 */  lui       $a1, 0xe200
/* F7AC 800343AC 34A5001C */  ori       $a1, $a1, 0x1c
/* F7B0 800343B0 3C08FCFF */  lui       $t0, 0xfcff
/* F7B4 800343B4 3508FFFF */  ori       $t0, $t0, 0xffff
/* F7B8 800343B8 3C07FFFC */  lui       $a3, 0xfffc
/* F7BC 800343BC 34E7F87C */  ori       $a3, $a3, 0xf87c
/* F7C0 800343C0 3C09E300 */  lui       $t1, 0xe300
/* F7C4 800343C4 35290A01 */  ori       $t1, $t1, 0xa01
/* F7C8 800343C8 3C0AE739 */  lui       $t2, 0xe739
/* F7CC 800343CC 354AE739 */  ori       $t2, $t2, 0xe739
/* F7D0 800343D0 3C0BF64F */  lui       $t3, 0xf64f
/* F7D4 800343D4 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* F7D8 800343D8 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* F7DC 800343DC 356BC3BC */  ori       $t3, $t3, 0xc3bc
/* F7E0 800343E0 AFB50014 */  sw        $s5, 0x14($sp)
/* F7E4 800343E4 AFB40010 */  sw        $s4, 0x10($sp)
/* F7E8 800343E8 AFB3000C */  sw        $s3, 0xc($sp)
/* F7EC 800343EC AFB20008 */  sw        $s2, 8($sp)
/* F7F0 800343F0 AFB10004 */  sw        $s1, 4($sp)
/* F7F4 800343F4 AFB00000 */  sw        $s0, ($sp)
/* F7F8 800343F8 8C820000 */  lw        $v0, ($a0)
/* F7FC 800343FC 3C06E700 */  lui       $a2, 0xe700
/* F800 80034400 0040182D */  daddu     $v1, $v0, $zero
/* F804 80034404 24420008 */  addiu     $v0, $v0, 8
/* F808 80034408 AC820000 */  sw        $v0, ($a0)
/* F80C 8003440C AC660000 */  sw        $a2, ($v1)
/* F810 80034410 AC600004 */  sw        $zero, 4($v1)
/* F814 80034414 24430008 */  addiu     $v1, $v0, 8
/* F818 80034418 AC830000 */  sw        $v1, ($a0)
/* F81C 8003441C 24430010 */  addiu     $v1, $v0, 0x10
/* F820 80034420 AC450000 */  sw        $a1, ($v0)
/* F824 80034424 AC400004 */  sw        $zero, 4($v0)
/* F828 80034428 AC830000 */  sw        $v1, ($a0)
/* F82C 8003442C 24430018 */  addiu     $v1, $v0, 0x18
/* F830 80034430 AC480008 */  sw        $t0, 8($v0)
/* F834 80034434 AC47000C */  sw        $a3, 0xc($v0)
/* F838 80034438 AC830000 */  sw        $v1, ($a0)
/* F83C 8003443C 3C030030 */  lui       $v1, 0x30
/* F840 80034440 AC430014 */  sw        $v1, 0x14($v0)
/* F844 80034444 24430020 */  addiu     $v1, $v0, 0x20
/* F848 80034448 AC490010 */  sw        $t1, 0x10($v0)
/* F84C 8003444C AC830000 */  sw        $v1, ($a0)
/* F850 80034450 3C03F700 */  lui       $v1, 0xf700
/* F854 80034454 AC430018 */  sw        $v1, 0x18($v0)
/* F858 80034458 24430028 */  addiu     $v1, $v0, 0x28
/* F85C 8003445C AC4A001C */  sw        $t2, 0x1c($v0)
/* F860 80034460 AC830000 */  sw        $v1, ($a0)
/* F864 80034464 3C058007 */  lui       $a1, %hi(gGameStatusPtr)
/* F868 80034468 8CA5419C */  lw        $a1, %lo(gGameStatusPtr)($a1)
/* F86C 8003446C 24430030 */  addiu     $v1, $v0, 0x30
/* F870 80034470 AC4B0020 */  sw        $t3, 0x20($v0)
/* F874 80034474 AC400024 */  sw        $zero, 0x24($v0)
/* F878 80034478 AC830000 */  sw        $v1, ($a0)
/* F87C 8003447C AC460028 */  sw        $a2, 0x28($v0)
/* F880 80034480 AC40002C */  sw        $zero, 0x2c($v0)
/* F884 80034484 80A300AC */  lb        $v1, 0xac($a1)
/* F888 80034488 2C62000A */  sltiu     $v0, $v1, 0xa
/* F88C 8003448C 10400124 */  beqz      $v0, .L80034920
/* F890 80034490 00031080 */   sll      $v0, $v1, 2
/* F894 80034494 3C01800A */  lui       $at, %hi(jtbl_800982C0)
/* F898 80034498 00220821 */  addu      $at, $at, $v0
/* F89C 8003449C 8C2282C0 */  lw        $v0, %lo(jtbl_800982C0)($at)
/* F8A0 800344A0 00400008 */  jr        $v0
/* F8A4 800344A4 00000000 */   nop
glabel L800344A8_F8A8
/* F8A8 800344A8 0000502D */  daddu     $t2, $zero, $zero
/* F8AC 800344AC 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* F8B0 800344B0 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* F8B4 800344B4 0040482D */  daddu     $t1, $v0, $zero
/* F8B8 800344B8 3C19FD10 */  lui       $t9, 0xfd10
/* F8BC 800344BC 3739007F */  ori       $t9, $t9, 0x7f
/* F8C0 800344C0 3C15800A */  lui       $s5, %hi(D_800A0918)
/* F8C4 800344C4 26B50918 */  addiu     $s5, $s5, %lo(D_800A0918)
/* F8C8 800344C8 3C0DF510 */  lui       $t5, 0xf510
/* F8CC 800344CC 35AD4000 */  ori       $t5, $t5, 0x4000
/* F8D0 800344D0 3C140700 */  lui       $s4, 0x700
/* F8D4 800344D4 3C13E600 */  lui       $s3, 0xe600
/* F8D8 800344D8 3C12F400 */  lui       $s2, 0xf400
/* F8DC 800344DC 3C18071F */  lui       $t8, 0x71f
/* F8E0 800344E0 3718C03C */  ori       $t8, $t8, 0xc03c
/* F8E4 800344E4 3C0EE700 */  lui       $t6, 0xe700
/* F8E8 800344E8 3C11F200 */  lui       $s1, 0xf200
/* F8EC 800344EC 3C0F001F */  lui       $t7, 0x1f
/* F8F0 800344F0 35EFC03C */  ori       $t7, $t7, 0xc03c
/* F8F4 800344F4 3C10E438 */  lui       $s0, 0xe438
/* F8F8 800344F8 240C0100 */  addiu     $t4, $zero, 0x100
/* F8FC 800344FC 8D220000 */  lw        $v0, ($t1)
/* F900 80034500 240B0140 */  addiu     $t3, $zero, 0x140
/* F904 80034504 0040182D */  daddu     $v1, $v0, $zero
/* F908 80034508 24420008 */  addiu     $v0, $v0, 8
/* F90C 8003450C AD220000 */  sw        $v0, ($t1)
/* F910 80034510 3C02DE00 */  lui       $v0, 0xde00
/* F914 80034514 AC620000 */  sw        $v0, ($v1)
/* F918 80034518 3C028007 */  lui       $v0, %hi(D_80077908)
/* F91C 8003451C 24427908 */  addiu     $v0, $v0, %lo(D_80077908)
/* F920 80034520 AC620004 */  sw        $v0, 4($v1)
.L80034524:
/* F924 80034524 3C080400 */  lui       $t0, 0x400
/* F928 80034528 35080400 */  ori       $t0, $t0, 0x400
/* F92C 8003452C 31870FFF */  andi      $a3, $t4, 0xfff
/* F930 80034530 258C0040 */  addiu     $t4, $t4, 0x40
/* F934 80034534 31660FFF */  andi      $a2, $t3, 0xfff
/* F938 80034538 256B0040 */  addiu     $t3, $t3, 0x40
/* F93C 8003453C 000A2B00 */  sll       $a1, $t2, 0xc
/* F940 80034540 254A0001 */  addiu     $t2, $t2, 1
/* F944 80034544 00D03025 */  or        $a2, $a2, $s0
/* F948 80034548 8D230000 */  lw        $v1, ($t1)
/* F94C 8003454C 8EA20000 */  lw        $v0, ($s5)
/* F950 80034550 0060202D */  daddu     $a0, $v1, $zero
/* F954 80034554 24630008 */  addiu     $v1, $v1, 8
/* F958 80034558 00451021 */  addu      $v0, $v0, $a1
/* F95C 8003455C AD230000 */  sw        $v1, ($t1)
/* F960 80034560 AC820004 */  sw        $v0, 4($a0)
/* F964 80034564 24620008 */  addiu     $v0, $v1, 8
/* F968 80034568 AC990000 */  sw        $t9, ($a0)
/* F96C 8003456C AD220000 */  sw        $v0, ($t1)
/* F970 80034570 24620010 */  addiu     $v0, $v1, 0x10
/* F974 80034574 AC6D0000 */  sw        $t5, ($v1)
/* F978 80034578 AC740004 */  sw        $s4, 4($v1)
/* F97C 8003457C AD220000 */  sw        $v0, ($t1)
/* F980 80034580 24620018 */  addiu     $v0, $v1, 0x18
/* F984 80034584 AC730008 */  sw        $s3, 8($v1)
/* F988 80034588 AC60000C */  sw        $zero, 0xc($v1)
/* F98C 8003458C AD220000 */  sw        $v0, ($t1)
/* F990 80034590 24620020 */  addiu     $v0, $v1, 0x20
/* F994 80034594 AC720010 */  sw        $s2, 0x10($v1)
/* F998 80034598 AC780014 */  sw        $t8, 0x14($v1)
/* F99C 8003459C AD220000 */  sw        $v0, ($t1)
/* F9A0 800345A0 24620028 */  addiu     $v0, $v1, 0x28
/* F9A4 800345A4 AC6E0018 */  sw        $t6, 0x18($v1)
/* F9A8 800345A8 AC60001C */  sw        $zero, 0x1c($v1)
/* F9AC 800345AC AD220000 */  sw        $v0, ($t1)
/* F9B0 800345B0 24620030 */  addiu     $v0, $v1, 0x30
/* F9B4 800345B4 AC6D0020 */  sw        $t5, 0x20($v1)
/* F9B8 800345B8 AC600024 */  sw        $zero, 0x24($v1)
/* F9BC 800345BC AD220000 */  sw        $v0, ($t1)
/* F9C0 800345C0 24620038 */  addiu     $v0, $v1, 0x38
/* F9C4 800345C4 AC710028 */  sw        $s1, 0x28($v1)
/* F9C8 800345C8 AC6F002C */  sw        $t7, 0x2c($v1)
/* F9CC 800345CC AD220000 */  sw        $v0, ($t1)
/* F9D0 800345D0 3C020018 */  lui       $v0, 0x18
/* F9D4 800345D4 00E23825 */  or        $a3, $a3, $v0
/* F9D8 800345D8 24620040 */  addiu     $v0, $v1, 0x40
/* F9DC 800345DC AC660030 */  sw        $a2, 0x30($v1)
/* F9E0 800345E0 AC670034 */  sw        $a3, 0x34($v1)
/* F9E4 800345E4 AD220000 */  sw        $v0, ($t1)
/* F9E8 800345E8 3C02E100 */  lui       $v0, 0xe100
/* F9EC 800345EC AC620038 */  sw        $v0, 0x38($v1)
/* F9F0 800345F0 24620048 */  addiu     $v0, $v1, 0x48
/* F9F4 800345F4 AC60003C */  sw        $zero, 0x3c($v1)
/* F9F8 800345F8 AD220000 */  sw        $v0, ($t1)
/* F9FC 800345FC 3C02F100 */  lui       $v0, 0xf100
/* FA00 80034600 AC620040 */  sw        $v0, 0x40($v1)
/* FA04 80034604 24620050 */  addiu     $v0, $v1, 0x50
/* FA08 80034608 AC680044 */  sw        $t0, 0x44($v1)
/* FA0C 8003460C AD220000 */  sw        $v0, ($t1)
/* FA10 80034610 29420007 */  slti      $v0, $t2, 7
/* FA14 80034614 AC6E0048 */  sw        $t6, 0x48($v1)
/* FA18 80034618 1440FFC2 */  bnez      $v0, .L80034524
/* FA1C 8003461C AC60004C */   sw       $zero, 0x4c($v1)
/* FA20 80034620 0800D248 */  j         .L80034920
/* FA24 80034624 00000000 */   nop
glabel L80034628_FA28
/* FA28 80034628 0000502D */  daddu     $t2, $zero, $zero
/* FA2C 8003462C 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* FA30 80034630 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* FA34 80034634 0040482D */  daddu     $t1, $v0, $zero
/* FA38 80034638 3C19FD10 */  lui       $t9, 0xfd10
/* FA3C 8003463C 373900FF */  ori       $t9, $t9, 0xff
/* FA40 80034640 3C15800A */  lui       $s5, %hi(D_800A091C)
/* FA44 80034644 26B5091C */  addiu     $s5, $s5, %lo(D_800A091C)
/* FA48 80034648 3C0DF510 */  lui       $t5, 0xf510
/* FA4C 8003464C 35AD8000 */  ori       $t5, $t5, 0x8000
/* FA50 80034650 3C140700 */  lui       $s4, 0x700
/* FA54 80034654 3C13E600 */  lui       $s3, 0xe600
/* FA58 80034658 3C12F400 */  lui       $s2, 0xf400
/* FA5C 8003465C 3C18073F */  lui       $t8, 0x73f
/* FA60 80034660 3718C01C */  ori       $t8, $t8, 0xc01c
/* FA64 80034664 3C0EE700 */  lui       $t6, 0xe700
/* FA68 80034668 3C11F200 */  lui       $s1, 0xf200
/* FA6C 8003466C 3C0F003F */  lui       $t7, 0x3f
/* FA70 80034670 35EFC01C */  ori       $t7, $t7, 0xc01c
/* FA74 80034674 3C10E448 */  lui       $s0, 0xe448
/* FA78 80034678 240C0164 */  addiu     $t4, $zero, 0x164
/* FA7C 8003467C 8D220000 */  lw        $v0, ($t1)
/* FA80 80034680 240B0184 */  addiu     $t3, $zero, 0x184
/* FA84 80034684 0040182D */  daddu     $v1, $v0, $zero
/* FA88 80034688 24420008 */  addiu     $v0, $v0, 8
/* FA8C 8003468C AD220000 */  sw        $v0, ($t1)
/* FA90 80034690 3C02DE00 */  lui       $v0, 0xde00
/* FA94 80034694 AC620000 */  sw        $v0, ($v1)
/* FA98 80034698 3C028007 */  lui       $v0, %hi(D_80077908)
/* FA9C 8003469C 24427908 */  addiu     $v0, $v0, %lo(D_80077908)
/* FAA0 800346A0 AC620004 */  sw        $v0, 4($v1)
.L800346A4:
/* FAA4 800346A4 3C080400 */  lui       $t0, 0x400
/* FAA8 800346A8 35080400 */  ori       $t0, $t0, 0x400
/* FAAC 800346AC 31870FFF */  andi      $a3, $t4, 0xfff
/* FAB0 800346B0 258C0020 */  addiu     $t4, $t4, 0x20
/* FAB4 800346B4 31660FFF */  andi      $a2, $t3, 0xfff
/* FAB8 800346B8 256B0020 */  addiu     $t3, $t3, 0x20
/* FABC 800346BC 000A2B00 */  sll       $a1, $t2, 0xc
/* FAC0 800346C0 254A0001 */  addiu     $t2, $t2, 1
/* FAC4 800346C4 00D03025 */  or        $a2, $a2, $s0
/* FAC8 800346C8 8D230000 */  lw        $v1, ($t1)
/* FACC 800346CC 8EA20000 */  lw        $v0, ($s5)
/* FAD0 800346D0 0060202D */  daddu     $a0, $v1, $zero
/* FAD4 800346D4 24630008 */  addiu     $v1, $v1, 8
/* FAD8 800346D8 00451021 */  addu      $v0, $v0, $a1
/* FADC 800346DC AD230000 */  sw        $v1, ($t1)
/* FAE0 800346E0 AC820004 */  sw        $v0, 4($a0)
/* FAE4 800346E4 24620008 */  addiu     $v0, $v1, 8
/* FAE8 800346E8 AC990000 */  sw        $t9, ($a0)
/* FAEC 800346EC AD220000 */  sw        $v0, ($t1)
/* FAF0 800346F0 24620010 */  addiu     $v0, $v1, 0x10
/* FAF4 800346F4 AC6D0000 */  sw        $t5, ($v1)
/* FAF8 800346F8 AC740004 */  sw        $s4, 4($v1)
/* FAFC 800346FC AD220000 */  sw        $v0, ($t1)
/* FB00 80034700 24620018 */  addiu     $v0, $v1, 0x18
/* FB04 80034704 AC730008 */  sw        $s3, 8($v1)
/* FB08 80034708 AC60000C */  sw        $zero, 0xc($v1)
/* FB0C 8003470C AD220000 */  sw        $v0, ($t1)
/* FB10 80034710 24620020 */  addiu     $v0, $v1, 0x20
/* FB14 80034714 AC720010 */  sw        $s2, 0x10($v1)
/* FB18 80034718 AC780014 */  sw        $t8, 0x14($v1)
/* FB1C 8003471C AD220000 */  sw        $v0, ($t1)
/* FB20 80034720 24620028 */  addiu     $v0, $v1, 0x28
/* FB24 80034724 AC6E0018 */  sw        $t6, 0x18($v1)
/* FB28 80034728 AC60001C */  sw        $zero, 0x1c($v1)
/* FB2C 8003472C AD220000 */  sw        $v0, ($t1)
/* FB30 80034730 24620030 */  addiu     $v0, $v1, 0x30
/* FB34 80034734 AC6D0020 */  sw        $t5, 0x20($v1)
/* FB38 80034738 AC600024 */  sw        $zero, 0x24($v1)
/* FB3C 8003473C AD220000 */  sw        $v0, ($t1)
/* FB40 80034740 24620038 */  addiu     $v0, $v1, 0x38
/* FB44 80034744 AC710028 */  sw        $s1, 0x28($v1)
/* FB48 80034748 AC6F002C */  sw        $t7, 0x2c($v1)
/* FB4C 8003474C AD220000 */  sw        $v0, ($t1)
/* FB50 80034750 3C020008 */  lui       $v0, 8
/* FB54 80034754 00E23825 */  or        $a3, $a3, $v0
/* FB58 80034758 24620040 */  addiu     $v0, $v1, 0x40
/* FB5C 8003475C AC660030 */  sw        $a2, 0x30($v1)
/* FB60 80034760 AC670034 */  sw        $a3, 0x34($v1)
/* FB64 80034764 AD220000 */  sw        $v0, ($t1)
/* FB68 80034768 3C02E100 */  lui       $v0, 0xe100
/* FB6C 8003476C AC620038 */  sw        $v0, 0x38($v1)
/* FB70 80034770 24620048 */  addiu     $v0, $v1, 0x48
/* FB74 80034774 AC60003C */  sw        $zero, 0x3c($v1)
/* FB78 80034778 AD220000 */  sw        $v0, ($t1)
/* FB7C 8003477C 3C02F100 */  lui       $v0, 0xf100
/* FB80 80034780 AC620040 */  sw        $v0, 0x40($v1)
/* FB84 80034784 24620050 */  addiu     $v0, $v1, 0x50
/* FB88 80034788 AC680044 */  sw        $t0, 0x44($v1)
/* FB8C 8003478C AD220000 */  sw        $v0, ($t1)
/* FB90 80034790 29420006 */  slti      $v0, $t2, 6
/* FB94 80034794 AC6E0048 */  sw        $t6, 0x48($v1)
/* FB98 80034798 1440FFC2 */  bnez      $v0, .L800346A4
/* FB9C 8003479C AC60004C */   sw       $zero, 0x4c($v1)
/* FBA0 800347A0 0800D248 */  j         .L80034920
/* FBA4 800347A4 00000000 */   nop
glabel L800347A8_FBA8
/* FBA8 800347A8 0000502D */  daddu     $t2, $zero, $zero
/* FBAC 800347AC 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* FBB0 800347B0 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* FBB4 800347B4 0040482D */  daddu     $t1, $v0, $zero
/* FBB8 800347B8 3C19FD10 */  lui       $t9, 0xfd10
/* FBBC 800347BC 373900FF */  ori       $t9, $t9, 0xff
/* FBC0 800347C0 3C15800A */  lui       $s5, %hi(D_800A0914)
/* FBC4 800347C4 26B50914 */  addiu     $s5, $s5, %lo(D_800A0914)
/* FBC8 800347C8 3C0DF510 */  lui       $t5, 0xf510
/* FBCC 800347CC 35AD8000 */  ori       $t5, $t5, 0x8000
/* FBD0 800347D0 3C140700 */  lui       $s4, 0x700
/* FBD4 800347D4 3C13E600 */  lui       $s3, 0xe600
/* FBD8 800347D8 3C12F400 */  lui       $s2, 0xf400
/* FBDC 800347DC 3C18073F */  lui       $t8, 0x73f
/* FBE0 800347E0 3718C01C */  ori       $t8, $t8, 0xc01c
/* FBE4 800347E4 3C0EE700 */  lui       $t6, 0xe700
/* FBE8 800347E8 3C11F200 */  lui       $s1, 0xf200
/* FBEC 800347EC 3C0F003F */  lui       $t7, 0x3f
/* FBF0 800347F0 35EFC01C */  ori       $t7, $t7, 0xc01c
/* FBF4 800347F4 3C10E448 */  lui       $s0, 0xe448
/* FBF8 800347F8 240C00EC */  addiu     $t4, $zero, 0xec
/* FBFC 800347FC 8D220000 */  lw        $v0, ($t1)
/* FC00 80034800 240B010C */  addiu     $t3, $zero, 0x10c
/* FC04 80034804 0040182D */  daddu     $v1, $v0, $zero
/* FC08 80034808 24420008 */  addiu     $v0, $v0, 8
/* FC0C 8003480C AD220000 */  sw        $v0, ($t1)
/* FC10 80034810 3C02DE00 */  lui       $v0, 0xde00
/* FC14 80034814 AC620000 */  sw        $v0, ($v1)
/* FC18 80034818 3C028007 */  lui       $v0, %hi(D_80077908)
/* FC1C 8003481C 24427908 */  addiu     $v0, $v0, %lo(D_80077908)
/* FC20 80034820 AC620004 */  sw        $v0, 4($v1)
.L80034824:
/* FC24 80034824 3C080400 */  lui       $t0, 0x400
/* FC28 80034828 35080400 */  ori       $t0, $t0, 0x400
/* FC2C 8003482C 31870FFF */  andi      $a3, $t4, 0xfff
/* FC30 80034830 258C0020 */  addiu     $t4, $t4, 0x20
/* FC34 80034834 31660FFF */  andi      $a2, $t3, 0xfff
/* FC38 80034838 256B0020 */  addiu     $t3, $t3, 0x20
/* FC3C 8003483C 000A2B00 */  sll       $a1, $t2, 0xc
/* FC40 80034840 254A0001 */  addiu     $t2, $t2, 1
/* FC44 80034844 00D03025 */  or        $a2, $a2, $s0
/* FC48 80034848 8D230000 */  lw        $v1, ($t1)
/* FC4C 8003484C 8EA20000 */  lw        $v0, ($s5)
/* FC50 80034850 0060202D */  daddu     $a0, $v1, $zero
/* FC54 80034854 24630008 */  addiu     $v1, $v1, 8
/* FC58 80034858 00451021 */  addu      $v0, $v0, $a1
/* FC5C 8003485C AD230000 */  sw        $v1, ($t1)
/* FC60 80034860 AC820004 */  sw        $v0, 4($a0)
/* FC64 80034864 24620008 */  addiu     $v0, $v1, 8
/* FC68 80034868 AC990000 */  sw        $t9, ($a0)
/* FC6C 8003486C AD220000 */  sw        $v0, ($t1)
/* FC70 80034870 24620010 */  addiu     $v0, $v1, 0x10
/* FC74 80034874 AC6D0000 */  sw        $t5, ($v1)
/* FC78 80034878 AC740004 */  sw        $s4, 4($v1)
/* FC7C 8003487C AD220000 */  sw        $v0, ($t1)
/* FC80 80034880 24620018 */  addiu     $v0, $v1, 0x18
/* FC84 80034884 AC730008 */  sw        $s3, 8($v1)
/* FC88 80034888 AC60000C */  sw        $zero, 0xc($v1)
/* FC8C 8003488C AD220000 */  sw        $v0, ($t1)
/* FC90 80034890 24620020 */  addiu     $v0, $v1, 0x20
/* FC94 80034894 AC720010 */  sw        $s2, 0x10($v1)
/* FC98 80034898 AC780014 */  sw        $t8, 0x14($v1)
/* FC9C 8003489C AD220000 */  sw        $v0, ($t1)
/* FCA0 800348A0 24620028 */  addiu     $v0, $v1, 0x28
/* FCA4 800348A4 AC6E0018 */  sw        $t6, 0x18($v1)
/* FCA8 800348A8 AC60001C */  sw        $zero, 0x1c($v1)
/* FCAC 800348AC AD220000 */  sw        $v0, ($t1)
/* FCB0 800348B0 24620030 */  addiu     $v0, $v1, 0x30
/* FCB4 800348B4 AC6D0020 */  sw        $t5, 0x20($v1)
/* FCB8 800348B8 AC600024 */  sw        $zero, 0x24($v1)
/* FCBC 800348BC AD220000 */  sw        $v0, ($t1)
/* FCC0 800348C0 24620038 */  addiu     $v0, $v1, 0x38
/* FCC4 800348C4 AC710028 */  sw        $s1, 0x28($v1)
/* FCC8 800348C8 AC6F002C */  sw        $t7, 0x2c($v1)
/* FCCC 800348CC AD220000 */  sw        $v0, ($t1)
/* FCD0 800348D0 3C020008 */  lui       $v0, 8
/* FCD4 800348D4 00E23825 */  or        $a3, $a3, $v0
/* FCD8 800348D8 24620040 */  addiu     $v0, $v1, 0x40
/* FCDC 800348DC AC660030 */  sw        $a2, 0x30($v1)
/* FCE0 800348E0 AC670034 */  sw        $a3, 0x34($v1)
/* FCE4 800348E4 AD220000 */  sw        $v0, ($t1)
/* FCE8 800348E8 3C02E100 */  lui       $v0, 0xe100
/* FCEC 800348EC AC620038 */  sw        $v0, 0x38($v1)
/* FCF0 800348F0 24620048 */  addiu     $v0, $v1, 0x48
/* FCF4 800348F4 AC60003C */  sw        $zero, 0x3c($v1)
/* FCF8 800348F8 AD220000 */  sw        $v0, ($t1)
/* FCFC 800348FC 3C02F100 */  lui       $v0, 0xf100
/* FD00 80034900 AC620040 */  sw        $v0, 0x40($v1)
/* FD04 80034904 24620050 */  addiu     $v0, $v1, 0x50
/* FD08 80034908 AC680044 */  sw        $t0, 0x44($v1)
/* FD0C 8003490C AD220000 */  sw        $v0, ($t1)
/* FD10 80034910 2942000E */  slti      $v0, $t2, 0xe
/* FD14 80034914 AC6E0048 */  sw        $t6, 0x48($v1)
/* FD18 80034918 1440FFC2 */  bnez      $v0, .L80034824
/* FD1C 8003491C AC60004C */   sw       $zero, 0x4c($v1)
.L80034920:
/* FD20 80034920 8FB50014 */  lw        $s5, 0x14($sp)
/* FD24 80034924 8FB40010 */  lw        $s4, 0x10($sp)
/* FD28 80034928 8FB3000C */  lw        $s3, 0xc($sp)
/* FD2C 8003492C 8FB20008 */  lw        $s2, 8($sp)
/* FD30 80034930 8FB10004 */  lw        $s1, 4($sp)
/* FD34 80034934 8FB00000 */  lw        $s0, ($sp)
/* FD38 80034938 03E00008 */  jr        $ra
/* FD3C 8003493C 27BD0018 */   addiu    $sp, $sp, 0x18
