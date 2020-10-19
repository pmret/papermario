.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241534
/* C62244 80241534 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C62248 80241538 AFB3003C */  sw        $s3, 0x3c($sp)
/* C6224C 8024153C 0080982D */  daddu     $s3, $a0, $zero
/* C62250 80241540 AFBF0040 */  sw        $ra, 0x40($sp)
/* C62254 80241544 AFB20038 */  sw        $s2, 0x38($sp)
/* C62258 80241548 AFB10034 */  sw        $s1, 0x34($sp)
/* C6225C 8024154C AFB00030 */  sw        $s0, 0x30($sp)
/* C62260 80241550 8E720148 */  lw        $s2, 0x148($s3)
/* C62264 80241554 00A0882D */  daddu     $s1, $a1, $zero
/* C62268 80241558 86440008 */  lh        $a0, 8($s2)
/* C6226C 8024155C 0C00EABB */  jal       get_npc_unsafe
/* C62270 80241560 00C0802D */   daddu    $s0, $a2, $zero
/* C62274 80241564 0200202D */  daddu     $a0, $s0, $zero
/* C62278 80241568 0240282D */  daddu     $a1, $s2, $zero
/* C6227C 8024156C AFA00010 */  sw        $zero, 0x10($sp)
/* C62280 80241570 8E26000C */  lw        $a2, 0xc($s1)
/* C62284 80241574 8E270010 */  lw        $a3, 0x10($s1)
/* C62288 80241578 0C01242D */  jal       func_800490B4
/* C6228C 8024157C 0040882D */   daddu    $s1, $v0, $zero
/* C62290 80241580 10400024 */  beqz      $v0, .L80241614
/* C62294 80241584 0220202D */   daddu    $a0, $s1, $zero
/* C62298 80241588 24050322 */  addiu     $a1, $zero, 0x322
/* C6229C 8024158C 0C012530 */  jal       func_800494C0
/* C622A0 80241590 0000302D */   daddu    $a2, $zero, $zero
/* C622A4 80241594 0000202D */  daddu     $a0, $zero, $zero
/* C622A8 80241598 0220282D */  daddu     $a1, $s1, $zero
/* C622AC 8024159C 0000302D */  daddu     $a2, $zero, $zero
/* C622B0 802415A0 2410000A */  addiu     $s0, $zero, 0xa
/* C622B4 802415A4 862300A8 */  lh        $v1, 0xa8($s1)
/* C622B8 802415A8 3C013F80 */  lui       $at, 0x3f80
/* C622BC 802415AC 44810000 */  mtc1      $at, $f0
/* C622C0 802415B0 3C014000 */  lui       $at, 0x4000
/* C622C4 802415B4 44811000 */  mtc1      $at, $f2
/* C622C8 802415B8 3C01C1A0 */  lui       $at, 0xc1a0
/* C622CC 802415BC 44812000 */  mtc1      $at, $f4
/* C622D0 802415C0 44833000 */  mtc1      $v1, $f6
/* C622D4 802415C4 00000000 */  nop       
/* C622D8 802415C8 468031A0 */  cvt.s.w   $f6, $f6
/* C622DC 802415CC 44073000 */  mfc1      $a3, $f6
/* C622E0 802415D0 27A20028 */  addiu     $v0, $sp, 0x28
/* C622E4 802415D4 AFB0001C */  sw        $s0, 0x1c($sp)
/* C622E8 802415D8 AFA20020 */  sw        $v0, 0x20($sp)
/* C622EC 802415DC E7A00010 */  swc1      $f0, 0x10($sp)
/* C622F0 802415E0 E7A20014 */  swc1      $f2, 0x14($sp)
/* C622F4 802415E4 0C01BFA4 */  jal       fx_emote
/* C622F8 802415E8 E7A40018 */   swc1     $f4, 0x18($sp)
/* C622FC 802415EC 0220202D */  daddu     $a0, $s1, $zero
/* C62300 802415F0 240502F4 */  addiu     $a1, $zero, 0x2f4
/* C62304 802415F4 0C012530 */  jal       func_800494C0
/* C62308 802415F8 3C060020 */   lui      $a2, 0x20
/* C6230C 802415FC 8E4200CC */  lw        $v0, 0xcc($s2)
/* C62310 80241600 8C420020 */  lw        $v0, 0x20($v0)
/* C62314 80241604 AE220028 */  sw        $v0, 0x28($s1)
/* C62318 80241608 9642008E */  lhu       $v0, 0x8e($s2)
/* C6231C 8024160C A622008E */  sh        $v0, 0x8e($s1)
/* C62320 80241610 AE700070 */  sw        $s0, 0x70($s3)
.L80241614:
/* C62324 80241614 8FBF0040 */  lw        $ra, 0x40($sp)
/* C62328 80241618 8FB3003C */  lw        $s3, 0x3c($sp)
/* C6232C 8024161C 8FB20038 */  lw        $s2, 0x38($sp)
/* C62330 80241620 8FB10034 */  lw        $s1, 0x34($sp)
/* C62334 80241624 8FB00030 */  lw        $s0, 0x30($sp)
/* C62338 80241628 03E00008 */  jr        $ra
/* C6233C 8024162C 27BD0048 */   addiu    $sp, $sp, 0x48
