.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00C8220
/* 3CF5C0 E00C8220 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3CF5C4 E00C8224 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3CF5C8 E00C8228 8C830000 */  lw        $v1, ($a0)
/* 3CF5CC E00C822C 8C85000C */  lw        $a1, 0xc($a0)
/* 3CF5D0 E00C8230 30620010 */  andi      $v0, $v1, 0x10
/* 3CF5D4 E00C8234 10400005 */  beqz      $v0, .LE00C824C
/* 3CF5D8 E00C8238 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3CF5DC E00C823C 00621024 */  and       $v0, $v1, $v0
/* 3CF5E0 E00C8240 AC820000 */  sw        $v0, ($a0)
/* 3CF5E4 E00C8244 24020010 */  addiu     $v0, $zero, 0x10
/* 3CF5E8 E00C8248 ACA20028 */  sw        $v0, 0x28($a1)
.LE00C824C:
/* 3CF5EC E00C824C 8CA30028 */  lw        $v1, 0x28($a1)
/* 3CF5F0 E00C8250 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3CF5F4 E00C8254 10400002 */  beqz      $v0, .LE00C8260
/* 3CF5F8 E00C8258 2462FFFF */   addiu    $v0, $v1, -1
/* 3CF5FC E00C825C ACA20028 */  sw        $v0, 0x28($a1)
.LE00C8260:
/* 3CF600 E00C8260 8CA2002C */  lw        $v0, 0x2c($a1)
/* 3CF604 E00C8264 8CA30028 */  lw        $v1, 0x28($a1)
/* 3CF608 E00C8268 24420001 */  addiu     $v0, $v0, 1
/* 3CF60C E00C826C 04610005 */  bgez      $v1, .LE00C8284
/* 3CF610 E00C8270 ACA2002C */   sw       $v0, 0x2c($a1)
/* 3CF614 E00C8274 0C080128 */  jal       shim_remove_effect
/* 3CF618 E00C8278 00000000 */   nop
/* 3CF61C E00C827C 080320FE */  j         .LE00C83F8
/* 3CF620 E00C8280 00000000 */   nop
.LE00C8284:
/* 3CF624 E00C8284 8CA30060 */  lw        $v1, 0x60($a1)
/* 3CF628 E00C8288 0040202D */  daddu     $a0, $v0, $zero
/* 3CF62C E00C828C 2C620007 */  sltiu     $v0, $v1, 7
/* 3CF630 E00C8290 1040001F */  beqz      $v0, .LE00C8310
/* 3CF634 E00C8294 00000000 */   nop
/* 3CF638 E00C8298 3C02E00D */  lui       $v0, %hi(D_E00C8718)
/* 3CF63C E00C829C 00431021 */  addu      $v0, $v0, $v1
/* 3CF640 E00C82A0 90428718 */  lbu       $v0, %lo(D_E00C8718)($v0)
/* 3CF644 E00C82A4 3C013C23 */  lui       $at, 0x3c23
/* 3CF648 E00C82A8 3421D70A */  ori       $at, $at, 0xd70a
/* 3CF64C E00C82AC 44811000 */  mtc1      $at, $f2
/* 3CF650 E00C82B0 44820000 */  mtc1      $v0, $f0
/* 3CF654 E00C82B4 00000000 */  nop
/* 3CF658 E00C82B8 46800020 */  cvt.s.w   $f0, $f0
/* 3CF65C E00C82BC 46020002 */  mul.s     $f0, $f0, $f2
/* 3CF660 E00C82C0 00000000 */  nop
/* 3CF664 E00C82C4 E4A00058 */  swc1      $f0, 0x58($a1)
/* 3CF668 E00C82C8 3C02E00D */  lui       $v0, %hi(D_E00C8720)
/* 3CF66C E00C82CC 00431021 */  addu      $v0, $v0, $v1
/* 3CF670 E00C82D0 90428720 */  lbu       $v0, %lo(D_E00C8720)($v0)
/* 3CF674 E00C82D4 44822000 */  mtc1      $v0, $f4
/* 3CF678 E00C82D8 00000000 */  nop
/* 3CF67C E00C82DC 46802120 */  cvt.s.w   $f4, $f4
/* 3CF680 E00C82E0 46022102 */  mul.s     $f4, $f4, $f2
/* 3CF684 E00C82E4 00000000 */  nop
/* 3CF688 E00C82E8 C4A00050 */  lwc1      $f0, 0x50($a1)
/* 3CF68C E00C82EC 3C014220 */  lui       $at, 0x4220
/* 3CF690 E00C82F0 44811000 */  mtc1      $at, $f2
/* 3CF694 E00C82F4 0060102D */  daddu     $v0, $v1, $zero
/* 3CF698 E00C82F8 46020001 */  sub.s     $f0, $f0, $f2
/* 3CF69C E00C82FC 24420001 */  addiu     $v0, $v0, 1
/* 3CF6A0 E00C8300 ACA20060 */  sw        $v0, 0x60($a1)
/* 3CF6A4 E00C8304 E4A00050 */  swc1      $f0, 0x50($a1)
/* 3CF6A8 E00C8308 080320D9 */  j         .LE00C8364
/* 3CF6AC E00C830C E4A4005C */   swc1     $f4, 0x5c($a1)
.LE00C8310:
/* 3CF6B0 E00C8310 C4A20048 */  lwc1      $f2, 0x48($a1)
/* 3CF6B4 E00C8314 3C01BE4C */  lui       $at, 0xbe4c
/* 3CF6B8 E00C8318 3421CCCD */  ori       $at, $at, 0xcccd
/* 3CF6BC E00C831C 44810000 */  mtc1      $at, $f0
/* 3CF6C0 E00C8320 C4A80004 */  lwc1      $f8, 4($a1)
/* 3CF6C4 E00C8324 46001080 */  add.s     $f2, $f2, $f0
/* 3CF6C8 E00C8328 C4A00044 */  lwc1      $f0, 0x44($a1)
/* 3CF6CC E00C832C C4A6000C */  lwc1      $f6, 0xc($a1)
/* 3CF6D0 E00C8330 46004200 */  add.s     $f8, $f8, $f0
/* 3CF6D4 E00C8334 C4A0004C */  lwc1      $f0, 0x4c($a1)
/* 3CF6D8 E00C8338 C4A40050 */  lwc1      $f4, 0x50($a1)
/* 3CF6DC E00C833C 46003180 */  add.s     $f6, $f6, $f0
/* 3CF6E0 E00C8340 C4A00054 */  lwc1      $f0, 0x54($a1)
/* 3CF6E4 E00C8344 46002100 */  add.s     $f4, $f4, $f0
/* 3CF6E8 E00C8348 C4A00008 */  lwc1      $f0, 8($a1)
/* 3CF6EC E00C834C E4A20048 */  swc1      $f2, 0x48($a1)
/* 3CF6F0 E00C8350 E4A80004 */  swc1      $f8, 4($a1)
/* 3CF6F4 E00C8354 46020000 */  add.s     $f0, $f0, $f2
/* 3CF6F8 E00C8358 E4A6000C */  swc1      $f6, 0xc($a1)
/* 3CF6FC E00C835C E4A40050 */  swc1      $f4, 0x50($a1)
/* 3CF700 E00C8360 E4A00008 */  swc1      $f0, 8($a1)
.LE00C8364:
/* 3CF704 E00C8364 8CA30068 */  lw        $v1, 0x68($a1)
/* 3CF708 E00C8368 2482FFFF */  addiu     $v0, $a0, -1
/* 3CF70C E00C836C 1443000A */  bne       $v0, $v1, .LE00C8398
/* 3CF710 E00C8370 00000000 */   nop
/* 3CF714 E00C8374 C4A00048 */  lwc1      $f0, 0x48($a1)
/* 3CF718 E00C8378 C4A20044 */  lwc1      $f2, 0x44($a1)
/* 3CF71C E00C837C 3C01C080 */  lui       $at, 0xc080
/* 3CF720 E00C8380 44812000 */  mtc1      $at, $f4
/* 3CF724 E00C8384 ACA00060 */  sw        $zero, 0x60($a1)
/* 3CF728 E00C8388 46000007 */  neg.s     $f0, $f0
/* 3CF72C E00C838C E4A00048 */  swc1      $f0, 0x48($a1)
/* 3CF730 E00C8390 080320FE */  j         .LE00C83F8
/* 3CF734 E00C8394 E4A40054 */   swc1     $f4, 0x54($a1)
.LE00C8398:
/* 3CF738 E00C8398 C4A40048 */  lwc1      $f4, 0x48($a1)
/* 3CF73C E00C839C 44800000 */  mtc1      $zero, $f0
/* 3CF740 E00C83A0 00000000 */  nop
/* 3CF744 E00C83A4 4600203C */  c.lt.s    $f4, $f0
/* 3CF748 E00C83A8 00000000 */  nop
/* 3CF74C E00C83AC 45000012 */  bc1f      .LE00C83F8
/* 3CF750 E00C83B0 00000000 */   nop
/* 3CF754 E00C83B4 C4A00008 */  lwc1      $f0, 8($a1)
/* 3CF758 E00C83B8 3C01E00D */  lui       $at, %hi(D_E00C8738)
/* 3CF75C E00C83BC D4228738 */  ldc1      $f2, %lo(D_E00C8738)($at)
/* 3CF760 E00C83C0 46000021 */  cvt.d.s   $f0, $f0
/* 3CF764 E00C83C4 4622003C */  c.lt.d    $f0, $f2
/* 3CF768 E00C83C8 00000000 */  nop
/* 3CF76C E00C83CC 4500000A */  bc1f      .LE00C83F8
/* 3CF770 E00C83D0 00000000 */   nop
/* 3CF774 E00C83D4 3C014164 */  lui       $at, 0x4164
/* 3CF778 E00C83D8 34219249 */  ori       $at, $at, 0x9249
/* 3CF77C E00C83DC 44810000 */  mtc1      $at, $f0
/* 3CF780 E00C83E0 3C01C1A0 */  lui       $at, 0xc1a0
/* 3CF784 E00C83E4 44811000 */  mtc1      $at, $f2
/* 3CF788 E00C83E8 46042101 */  sub.s     $f4, $f4, $f4
/* 3CF78C E00C83EC E4A00008 */  swc1      $f0, 8($a1)
/* 3CF790 E00C83F0 E4A20054 */  swc1      $f2, 0x54($a1)
/* 3CF794 E00C83F4 E4A40048 */  swc1      $f4, 0x48($a1)
.LE00C83F8:
/* 3CF798 E00C83F8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3CF79C E00C83FC 03E00008 */  jr        $ra
/* 3CF7A0 E00C8400 27BD0018 */   addiu    $sp, $sp, 0x18
