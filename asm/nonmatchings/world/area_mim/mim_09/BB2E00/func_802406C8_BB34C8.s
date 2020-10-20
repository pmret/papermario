.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406C8_BB34C8
/* BB34C8 802406C8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BB34CC 802406CC AFB40040 */  sw        $s4, 0x40($sp)
/* BB34D0 802406D0 0080A02D */  daddu     $s4, $a0, $zero
/* BB34D4 802406D4 AFBF0044 */  sw        $ra, 0x44($sp)
/* BB34D8 802406D8 AFB3003C */  sw        $s3, 0x3c($sp)
/* BB34DC 802406DC AFB20038 */  sw        $s2, 0x38($sp)
/* BB34E0 802406E0 AFB10034 */  sw        $s1, 0x34($sp)
/* BB34E4 802406E4 AFB00030 */  sw        $s0, 0x30($sp)
/* BB34E8 802406E8 8E920148 */  lw        $s2, 0x148($s4)
/* BB34EC 802406EC 00A0882D */  daddu     $s1, $a1, $zero
/* BB34F0 802406F0 86440008 */  lh        $a0, 8($s2)
/* BB34F4 802406F4 0C00EABB */  jal       get_npc_unsafe
/* BB34F8 802406F8 00C0982D */   daddu    $s3, $a2, $zero
/* BB34FC 802406FC 8E230014 */  lw        $v1, 0x14($s1)
/* BB3500 80240700 0460002D */  bltz      $v1, .L802407B8
/* BB3504 80240704 0040802D */   daddu    $s0, $v0, $zero
/* BB3508 80240708 0260202D */  daddu     $a0, $s3, $zero
/* BB350C 8024070C AFA00010 */  sw        $zero, 0x10($sp)
/* BB3510 80240710 8E260024 */  lw        $a2, 0x24($s1)
/* BB3514 80240714 8E270028 */  lw        $a3, 0x28($s1)
/* BB3518 80240718 0C01242D */  jal       func_800490B4
/* BB351C 8024071C 0240282D */   daddu    $a1, $s2, $zero
/* BB3520 80240720 10400025 */  beqz      $v0, .L802407B8
/* BB3524 80240724 0000202D */   daddu    $a0, $zero, $zero
/* BB3528 80240728 0200282D */  daddu     $a1, $s0, $zero
/* BB352C 8024072C 0000302D */  daddu     $a2, $zero, $zero
/* BB3530 80240730 860300A8 */  lh        $v1, 0xa8($s0)
/* BB3534 80240734 3C013F80 */  lui       $at, 0x3f80
/* BB3538 80240738 44810000 */  mtc1      $at, $f0
/* BB353C 8024073C 3C014000 */  lui       $at, 0x4000
/* BB3540 80240740 44811000 */  mtc1      $at, $f2
/* BB3544 80240744 3C01C1A0 */  lui       $at, 0xc1a0
/* BB3548 80240748 44812000 */  mtc1      $at, $f4
/* BB354C 8024074C 2402000F */  addiu     $v0, $zero, 0xf
/* BB3550 80240750 AFA2001C */  sw        $v0, 0x1c($sp)
/* BB3554 80240754 44833000 */  mtc1      $v1, $f6
/* BB3558 80240758 00000000 */  nop       
/* BB355C 8024075C 468031A0 */  cvt.s.w   $f6, $f6
/* BB3560 80240760 44073000 */  mfc1      $a3, $f6
/* BB3564 80240764 27A20028 */  addiu     $v0, $sp, 0x28
/* BB3568 80240768 AFA20020 */  sw        $v0, 0x20($sp)
/* BB356C 8024076C E7A00010 */  swc1      $f0, 0x10($sp)
/* BB3570 80240770 E7A20014 */  swc1      $f2, 0x14($sp)
/* BB3574 80240774 0C01BFA4 */  jal       fx_emote
/* BB3578 80240778 E7A40018 */   swc1     $f4, 0x18($sp)
/* BB357C 8024077C 0200202D */  daddu     $a0, $s0, $zero
/* BB3580 80240780 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BB3584 80240784 0C012530 */  jal       func_800494C0
/* BB3588 80240788 3C060020 */   lui      $a2, 0x20
/* BB358C 8024078C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BB3590 80240790 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BB3594 80240794 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BB3598 80240798 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BB359C 8024079C 8C460028 */  lw        $a2, 0x28($v0)
/* BB35A0 802407A0 0C00A720 */  jal       atan2
/* BB35A4 802407A4 8C470030 */   lw       $a3, 0x30($v0)
/* BB35A8 802407A8 2402000C */  addiu     $v0, $zero, 0xc
/* BB35AC 802407AC E600000C */  swc1      $f0, 0xc($s0)
/* BB35B0 802407B0 08090213 */  j         .L8024084C
/* BB35B4 802407B4 AE820070 */   sw       $v0, 0x70($s4)
.L802407B8:
/* BB35B8 802407B8 8602008C */  lh        $v0, 0x8c($s0)
/* BB35BC 802407BC 14400023 */  bnez      $v0, .L8024084C
/* BB35C0 802407C0 00000000 */   nop      
/* BB35C4 802407C4 9602008E */  lhu       $v0, 0x8e($s0)
/* BB35C8 802407C8 2442FFFF */  addiu     $v0, $v0, -1
/* BB35CC 802407CC A602008E */  sh        $v0, 0x8e($s0)
/* BB35D0 802407D0 00021400 */  sll       $v0, $v0, 0x10
/* BB35D4 802407D4 1C40001D */  bgtz      $v0, .L8024084C
/* BB35D8 802407D8 00000000 */   nop      
/* BB35DC 802407DC 8E820074 */  lw        $v0, 0x74($s4)
/* BB35E0 802407E0 2442FFFF */  addiu     $v0, $v0, -1
/* BB35E4 802407E4 18400018 */  blez      $v0, .L80240848
/* BB35E8 802407E8 AE820074 */   sw       $v0, 0x74($s4)
/* BB35EC 802407EC C600000C */  lwc1      $f0, 0xc($s0)
/* BB35F0 802407F0 3C014334 */  lui       $at, 0x4334
/* BB35F4 802407F4 44816000 */  mtc1      $at, $f12
/* BB35F8 802407F8 0C00A6C9 */  jal       clamp_angle
/* BB35FC 802407FC 460C0300 */   add.s    $f12, $f0, $f12
/* BB3600 80240800 240403E8 */  addiu     $a0, $zero, 0x3e8
/* BB3604 80240804 0C00A67F */  jal       rand_int
/* BB3608 80240808 E600000C */   swc1     $f0, 0xc($s0)
/* BB360C 8024080C 3C032E8B */  lui       $v1, 0x2e8b
/* BB3610 80240810 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* BB3614 80240814 00430018 */  mult      $v0, $v1
/* BB3618 80240818 00021FC3 */  sra       $v1, $v0, 0x1f
/* BB361C 8024081C 00004010 */  mfhi      $t0
/* BB3620 80240820 00082043 */  sra       $a0, $t0, 1
/* BB3624 80240824 00832023 */  subu      $a0, $a0, $v1
/* BB3628 80240828 00041840 */  sll       $v1, $a0, 1
/* BB362C 8024082C 00641821 */  addu      $v1, $v1, $a0
/* BB3630 80240830 00031880 */  sll       $v1, $v1, 2
/* BB3634 80240834 00641823 */  subu      $v1, $v1, $a0
/* BB3638 80240838 00431023 */  subu      $v0, $v0, $v1
/* BB363C 8024083C 24420005 */  addiu     $v0, $v0, 5
/* BB3640 80240840 08090213 */  j         .L8024084C
/* BB3644 80240844 A602008E */   sh       $v0, 0x8e($s0)
.L80240848:
/* BB3648 80240848 AE800070 */  sw        $zero, 0x70($s4)
.L8024084C:
/* BB364C 8024084C 8FBF0044 */  lw        $ra, 0x44($sp)
/* BB3650 80240850 8FB40040 */  lw        $s4, 0x40($sp)
/* BB3654 80240854 8FB3003C */  lw        $s3, 0x3c($sp)
/* BB3658 80240858 8FB20038 */  lw        $s2, 0x38($sp)
/* BB365C 8024085C 8FB10034 */  lw        $s1, 0x34($sp)
/* BB3660 80240860 8FB00030 */  lw        $s0, 0x30($sp)
/* BB3664 80240864 03E00008 */  jr        $ra
/* BB3668 80240868 27BD0048 */   addiu    $sp, $sp, 0x48
