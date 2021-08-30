.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BD0_8437A0
/* 8437A0 80240BD0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 8437A4 80240BD4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 8437A8 80240BD8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 8437AC 80240BDC AFB00018 */  sw        $s0, 0x18($sp)
/* 8437B0 80240BE0 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 8437B4 80240BE4 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 8437B8 80240BE8 10A00060 */  beqz      $a1, .L80240D6C
/* 8437BC 80240BEC 0080882D */   daddu    $s1, $a0, $zero
/* 8437C0 80240BF0 3C05F4AC */  lui       $a1, 0xf4ac
/* 8437C4 80240BF4 0C0B1EAF */  jal       evt_get_variable
/* 8437C8 80240BF8 34A5D481 */   ori      $a1, $a1, 0xd481
/* 8437CC 80240BFC 0220202D */  daddu     $a0, $s1, $zero
/* 8437D0 80240C00 3C05F4AC */  lui       $a1, 0xf4ac
/* 8437D4 80240C04 4482B000 */  mtc1      $v0, $f22
/* 8437D8 80240C08 00000000 */  nop
/* 8437DC 80240C0C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 8437E0 80240C10 0C0B1EAF */  jal       evt_get_variable
/* 8437E4 80240C14 34A5D482 */   ori      $a1, $a1, 0xd482
/* 8437E8 80240C18 0220202D */  daddu     $a0, $s1, $zero
/* 8437EC 80240C1C 3C05F4AC */  lui       $a1, 0xf4ac
/* 8437F0 80240C20 4482A000 */  mtc1      $v0, $f20
/* 8437F4 80240C24 00000000 */  nop
/* 8437F8 80240C28 4680A520 */  cvt.s.w   $f20, $f20
/* 8437FC 80240C2C 0C0B1EAF */  jal       evt_get_variable
/* 843800 80240C30 34A5D483 */   ori      $a1, $a1, 0xd483
/* 843804 80240C34 44821000 */  mtc1      $v0, $f2
/* 843808 80240C38 00000000 */  nop
/* 84380C 80240C3C 468010A0 */  cvt.s.w   $f2, $f2
/* 843810 80240C40 4405B000 */  mfc1      $a1, $f22
/* 843814 80240C44 4406A000 */  mfc1      $a2, $f20
/* 843818 80240C48 44071000 */  mfc1      $a3, $f2
/* 84381C 80240C4C 0C01C574 */  jal       playFX_4E
/* 843820 80240C50 0000202D */   daddu    $a0, $zero, $zero
/* 843824 80240C54 0220202D */  daddu     $a0, $s1, $zero
/* 843828 80240C58 3C05F4AC */  lui       $a1, 0xf4ac
/* 84382C 80240C5C 34A5D481 */  ori       $a1, $a1, 0xd481
/* 843830 80240C60 3C108025 */  lui       $s0, %hi(D_8024F5C0)
/* 843834 80240C64 2610F5C0 */  addiu     $s0, $s0, %lo(D_8024F5C0)
/* 843838 80240C68 0C0B1EAF */  jal       evt_get_variable
/* 84383C 80240C6C AE020000 */   sw       $v0, ($s0)
/* 843840 80240C70 0220202D */  daddu     $a0, $s1, $zero
/* 843844 80240C74 3C05F4AC */  lui       $a1, 0xf4ac
/* 843848 80240C78 4482B000 */  mtc1      $v0, $f22
/* 84384C 80240C7C 00000000 */  nop
/* 843850 80240C80 4680B5A0 */  cvt.s.w   $f22, $f22
/* 843854 80240C84 0C0B1EAF */  jal       evt_get_variable
/* 843858 80240C88 34A5D482 */   ori      $a1, $a1, 0xd482
/* 84385C 80240C8C 0220202D */  daddu     $a0, $s1, $zero
/* 843860 80240C90 3C05F4AC */  lui       $a1, 0xf4ac
/* 843864 80240C94 4482A000 */  mtc1      $v0, $f20
/* 843868 80240C98 00000000 */  nop
/* 84386C 80240C9C 4680A520 */  cvt.s.w   $f20, $f20
/* 843870 80240CA0 0C0B1EAF */  jal       evt_get_variable
/* 843874 80240CA4 34A5D483 */   ori      $a1, $a1, 0xd483
/* 843878 80240CA8 44821000 */  mtc1      $v0, $f2
/* 84387C 80240CAC 00000000 */  nop
/* 843880 80240CB0 468010A0 */  cvt.s.w   $f2, $f2
/* 843884 80240CB4 4405B000 */  mfc1      $a1, $f22
/* 843888 80240CB8 4406A000 */  mfc1      $a2, $f20
/* 84388C 80240CBC 44071000 */  mfc1      $a3, $f2
/* 843890 80240CC0 0C01C604 */  jal       playFX_54
/* 843894 80240CC4 0000202D */   daddu    $a0, $zero, $zero
/* 843898 80240CC8 0220202D */  daddu     $a0, $s1, $zero
/* 84389C 80240CCC 3C05F4AC */  lui       $a1, 0xf4ac
/* 8438A0 80240CD0 3C018025 */  lui       $at, %hi(D_8024F5C4)
/* 8438A4 80240CD4 AC22F5C4 */  sw        $v0, %lo(D_8024F5C4)($at)
/* 8438A8 80240CD8 0C0B1EAF */  jal       evt_get_variable
/* 8438AC 80240CDC 34A5D481 */   ori      $a1, $a1, 0xd481
/* 8438B0 80240CE0 0220202D */  daddu     $a0, $s1, $zero
/* 8438B4 80240CE4 3C05F4AC */  lui       $a1, 0xf4ac
/* 8438B8 80240CE8 4482B000 */  mtc1      $v0, $f22
/* 8438BC 80240CEC 00000000 */  nop
/* 8438C0 80240CF0 4680B5A0 */  cvt.s.w   $f22, $f22
/* 8438C4 80240CF4 0C0B1EAF */  jal       evt_get_variable
/* 8438C8 80240CF8 34A5D482 */   ori      $a1, $a1, 0xd482
/* 8438CC 80240CFC 0220202D */  daddu     $a0, $s1, $zero
/* 8438D0 80240D00 3C05F4AC */  lui       $a1, 0xf4ac
/* 8438D4 80240D04 4482A000 */  mtc1      $v0, $f20
/* 8438D8 80240D08 00000000 */  nop
/* 8438DC 80240D0C 4680A520 */  cvt.s.w   $f20, $f20
/* 8438E0 80240D10 0C0B1EAF */  jal       evt_get_variable
/* 8438E4 80240D14 34A5D483 */   ori      $a1, $a1, 0xd483
/* 8438E8 80240D18 44821000 */  mtc1      $v0, $f2
/* 8438EC 80240D1C 00000000 */  nop
/* 8438F0 80240D20 468010A0 */  cvt.s.w   $f2, $f2
/* 8438F4 80240D24 4405B000 */  mfc1      $a1, $f22
/* 8438F8 80240D28 4406A000 */  mfc1      $a2, $f20
/* 8438FC 80240D2C 3C013F80 */  lui       $at, 0x3f80
/* 843900 80240D30 44810000 */  mtc1      $at, $f0
/* 843904 80240D34 44071000 */  mfc1      $a3, $f2
/* 843908 80240D38 0000202D */  daddu     $a0, $zero, $zero
/* 84390C 80240D3C AFA00014 */  sw        $zero, 0x14($sp)
/* 843910 80240D40 0C01CA24 */  jal       playFX_80
/* 843914 80240D44 E7A00010 */   swc1     $f0, 0x10($sp)
/* 843918 80240D48 8E030000 */  lw        $v1, ($s0)
/* 84391C 80240D4C 8C64000C */  lw        $a0, 0xc($v1)
/* 843920 80240D50 3C018025 */  lui       $at, %hi(D_8024F5C8)
/* 843924 80240D54 AC22F5C8 */  sw        $v0, %lo(D_8024F5C8)($at)
/* 843928 80240D58 AC800018 */  sw        $zero, 0x18($a0)
/* 84392C 80240D5C AC800020 */  sw        $zero, 0x20($a0)
/* 843930 80240D60 AC800024 */  sw        $zero, 0x24($a0)
/* 843934 80240D64 AC800028 */  sw        $zero, 0x28($a0)
/* 843938 80240D68 AC80001C */  sw        $zero, 0x1c($a0)
.L80240D6C:
/* 84393C 80240D6C 3C028025 */  lui       $v0, %hi(D_8024F5C0)
/* 843940 80240D70 8C42F5C0 */  lw        $v0, %lo(D_8024F5C0)($v0)
/* 843944 80240D74 8C44000C */  lw        $a0, 0xc($v0)
/* 843948 80240D78 8C820020 */  lw        $v0, 0x20($a0)
/* 84394C 80240D7C 8C830028 */  lw        $v1, 0x28($a0)
/* 843950 80240D80 2442000A */  addiu     $v0, $v0, 0xa
/* 843954 80240D84 AC820020 */  sw        $v0, 0x20($a0)
/* 843958 80240D88 8C820024 */  lw        $v0, 0x24($a0)
/* 84395C 80240D8C 2463000A */  addiu     $v1, $v1, 0xa
/* 843960 80240D90 AC830028 */  sw        $v1, 0x28($a0)
/* 843964 80240D94 8C830018 */  lw        $v1, 0x18($a0)
/* 843968 80240D98 2442000A */  addiu     $v0, $v0, 0xa
/* 84396C 80240D9C AC820024 */  sw        $v0, 0x24($a0)
/* 843970 80240DA0 8C82001C */  lw        $v0, 0x1c($a0)
/* 843974 80240DA4 2463000A */  addiu     $v1, $v1, 0xa
/* 843978 80240DA8 AC830018 */  sw        $v1, 0x18($a0)
/* 84397C 80240DAC 286300FF */  slti      $v1, $v1, 0xff
/* 843980 80240DB0 2442000A */  addiu     $v0, $v0, 0xa
/* 843984 80240DB4 AC82001C */  sw        $v0, 0x1c($a0)
/* 843988 80240DB8 14600004 */  bnez      $v1, .L80240DCC
/* 84398C 80240DBC 0000102D */   daddu    $v0, $zero, $zero
/* 843990 80240DC0 240200FF */  addiu     $v0, $zero, 0xff
/* 843994 80240DC4 AC820018 */  sw        $v0, 0x18($a0)
/* 843998 80240DC8 24020002 */  addiu     $v0, $zero, 2
.L80240DCC:
/* 84399C 80240DCC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8439A0 80240DD0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8439A4 80240DD4 8FB00018 */  lw        $s0, 0x18($sp)
/* 8439A8 80240DD8 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 8439AC 80240DDC D7B40028 */  ldc1      $f20, 0x28($sp)
/* 8439B0 80240DE0 03E00008 */  jr        $ra
/* 8439B4 80240DE4 27BD0038 */   addiu    $sp, $sp, 0x38
