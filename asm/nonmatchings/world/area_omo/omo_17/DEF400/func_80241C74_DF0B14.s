.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C74_DF0B14
/* DF0B14 80241C74 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DF0B18 80241C78 AFB3001C */  sw        $s3, 0x1c($sp)
/* DF0B1C 80241C7C 0080982D */  daddu     $s3, $a0, $zero
/* DF0B20 80241C80 AFBF0020 */  sw        $ra, 0x20($sp)
/* DF0B24 80241C84 AFB20018 */  sw        $s2, 0x18($sp)
/* DF0B28 80241C88 AFB10014 */  sw        $s1, 0x14($sp)
/* DF0B2C 80241C8C AFB00010 */  sw        $s0, 0x10($sp)
/* DF0B30 80241C90 8E720148 */  lw        $s2, 0x148($s3)
/* DF0B34 80241C94 86440008 */  lh        $a0, 8($s2)
/* DF0B38 80241C98 0C00EABB */  jal       get_npc_unsafe
/* DF0B3C 80241C9C 00A0802D */   daddu    $s0, $a1, $zero
/* DF0B40 80241CA0 0040882D */  daddu     $s1, $v0, $zero
/* DF0B44 80241CA4 C6420080 */  lwc1      $f2, 0x80($s2)
/* DF0B48 80241CA8 468010A0 */  cvt.s.w   $f2, $f2
/* DF0B4C 80241CAC 460010A1 */  cvt.d.s   $f2, $f2
/* DF0B50 80241CB0 C6400084 */  lwc1      $f0, 0x84($s2)
/* DF0B54 80241CB4 46800020 */  cvt.s.w   $f0, $f0
/* DF0B58 80241CB8 46000021 */  cvt.d.s   $f0, $f0
/* DF0B5C 80241CBC 3C014059 */  lui       $at, 0x4059
/* DF0B60 80241CC0 44812800 */  mtc1      $at, $f5
/* DF0B64 80241CC4 44802000 */  mtc1      $zero, $f4
/* DF0B68 80241CC8 8E4200CC */  lw        $v0, 0xcc($s2)
/* DF0B6C 80241CCC C62C0038 */  lwc1      $f12, 0x38($s1)
/* DF0B70 80241CD0 C62E0040 */  lwc1      $f14, 0x40($s1)
/* DF0B74 80241CD4 46241083 */  div.d     $f2, $f2, $f4
/* DF0B78 80241CD8 462010A0 */  cvt.s.d   $f2, $f2
/* DF0B7C 80241CDC 46240003 */  div.d     $f0, $f0, $f4
/* DF0B80 80241CE0 8C420020 */  lw        $v0, 0x20($v0)
/* DF0B84 80241CE4 46200020 */  cvt.s.d   $f0, $f0
/* DF0B88 80241CE8 E622001C */  swc1      $f2, 0x1c($s1)
/* DF0B8C 80241CEC E6200014 */  swc1      $f0, 0x14($s1)
/* DF0B90 80241CF0 AE220028 */  sw        $v0, 0x28($s1)
/* DF0B94 80241CF4 C6000018 */  lwc1      $f0, 0x18($s0)
/* DF0B98 80241CF8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DF0B9C 80241CFC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DF0BA0 80241D00 E6200018 */  swc1      $f0, 0x18($s1)
/* DF0BA4 80241D04 8C460028 */  lw        $a2, 0x28($v0)
/* DF0BA8 80241D08 0C00A720 */  jal       atan2
/* DF0BAC 80241D0C 8C470030 */   lw       $a3, 0x30($v0)
/* DF0BB0 80241D10 E620000C */  swc1      $f0, 0xc($s1)
/* DF0BB4 80241D14 8E420018 */  lw        $v0, 0x18($s2)
/* DF0BB8 80241D18 AE400074 */  sw        $zero, 0x74($s2)
/* DF0BBC 80241D1C 9442002A */  lhu       $v0, 0x2a($v0)
/* DF0BC0 80241D20 30420002 */  andi      $v0, $v0, 2
/* DF0BC4 80241D24 10400005 */  beqz      $v0, .L80241D3C
/* DF0BC8 80241D28 24020003 */   addiu    $v0, $zero, 3
/* DF0BCC 80241D2C A622008E */  sh        $v0, 0x8e($s1)
/* DF0BD0 80241D30 2402000D */  addiu     $v0, $zero, 0xd
/* DF0BD4 80241D34 08090763 */  j         .L80241D8C
/* DF0BD8 80241D38 AE620070 */   sw       $v0, 0x70($s3)
.L80241D3C:
/* DF0BDC 80241D3C 24030001 */  addiu     $v1, $zero, 1
/* DF0BE0 80241D40 2402000E */  addiu     $v0, $zero, 0xe
/* DF0BE4 80241D44 A623008E */  sh        $v1, 0x8e($s1)
/* DF0BE8 80241D48 AE620070 */  sw        $v0, 0x70($s3)
/* DF0BEC 80241D4C C6200038 */  lwc1      $f0, 0x38($s1)
/* DF0BF0 80241D50 4600018D */  trunc.w.s $f6, $f0
/* DF0BF4 80241D54 44023000 */  mfc1      $v0, $f6
/* DF0BF8 80241D58 00000000 */  nop
/* DF0BFC 80241D5C A6420010 */  sh        $v0, 0x10($s2)
/* DF0C00 80241D60 C620003C */  lwc1      $f0, 0x3c($s1)
/* DF0C04 80241D64 4600018D */  trunc.w.s $f6, $f0
/* DF0C08 80241D68 44023000 */  mfc1      $v0, $f6
/* DF0C0C 80241D6C 00000000 */  nop
/* DF0C10 80241D70 A6420012 */  sh        $v0, 0x12($s2)
/* DF0C14 80241D74 C6200040 */  lwc1      $f0, 0x40($s1)
/* DF0C18 80241D78 A2430007 */  sb        $v1, 7($s2)
/* DF0C1C 80241D7C 4600018D */  trunc.w.s $f6, $f0
/* DF0C20 80241D80 44023000 */  mfc1      $v0, $f6
/* DF0C24 80241D84 00000000 */  nop
/* DF0C28 80241D88 A6420014 */  sh        $v0, 0x14($s2)
.L80241D8C:
/* DF0C2C 80241D8C 8FBF0020 */  lw        $ra, 0x20($sp)
/* DF0C30 80241D90 8FB3001C */  lw        $s3, 0x1c($sp)
/* DF0C34 80241D94 8FB20018 */  lw        $s2, 0x18($sp)
/* DF0C38 80241D98 8FB10014 */  lw        $s1, 0x14($sp)
/* DF0C3C 80241D9C 8FB00010 */  lw        $s0, 0x10($sp)
/* DF0C40 80241DA0 03E00008 */  jr        $ra
/* DF0C44 80241DA4 27BD0028 */   addiu    $sp, $sp, 0x28
