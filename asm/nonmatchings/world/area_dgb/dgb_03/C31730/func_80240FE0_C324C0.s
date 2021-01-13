.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FE0_C324C0
/* C324C0 80240FE0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C324C4 80240FE4 AFB40040 */  sw        $s4, 0x40($sp)
/* C324C8 80240FE8 0080A02D */  daddu     $s4, $a0, $zero
/* C324CC 80240FEC AFBF0044 */  sw        $ra, 0x44($sp)
/* C324D0 80240FF0 AFB3003C */  sw        $s3, 0x3c($sp)
/* C324D4 80240FF4 AFB20038 */  sw        $s2, 0x38($sp)
/* C324D8 80240FF8 AFB10034 */  sw        $s1, 0x34($sp)
/* C324DC 80240FFC AFB00030 */  sw        $s0, 0x30($sp)
/* C324E0 80241000 8E910148 */  lw        $s1, 0x148($s4)
/* C324E4 80241004 00A0902D */  daddu     $s2, $a1, $zero
/* C324E8 80241008 86240008 */  lh        $a0, 8($s1)
/* C324EC 8024100C 0C00EABB */  jal       get_npc_unsafe
/* C324F0 80241010 00C0982D */   daddu    $s3, $a2, $zero
/* C324F4 80241014 8E430014 */  lw        $v1, 0x14($s2)
/* C324F8 80241018 04600031 */  bltz      $v1, .L802410E0
/* C324FC 8024101C 0040802D */   daddu    $s0, $v0, $zero
/* C32500 80241020 0260202D */  daddu     $a0, $s3, $zero
/* C32504 80241024 AFA00010 */  sw        $zero, 0x10($sp)
/* C32508 80241028 8E460024 */  lw        $a2, 0x24($s2)
/* C3250C 8024102C 8E470028 */  lw        $a3, 0x28($s2)
/* C32510 80241030 0C01242D */  jal       func_800490B4
/* C32514 80241034 0220282D */   daddu    $a1, $s1, $zero
/* C32518 80241038 10400029 */  beqz      $v0, .L802410E0
/* C3251C 8024103C 0000202D */   daddu    $a0, $zero, $zero
/* C32520 80241040 0200282D */  daddu     $a1, $s0, $zero
/* C32524 80241044 0000302D */  daddu     $a2, $zero, $zero
/* C32528 80241048 860300A8 */  lh        $v1, 0xa8($s0)
/* C3252C 8024104C 3C013F80 */  lui       $at, 0x3f80
/* C32530 80241050 44810000 */  mtc1      $at, $f0
/* C32534 80241054 3C014000 */  lui       $at, 0x4000
/* C32538 80241058 44811000 */  mtc1      $at, $f2
/* C3253C 8024105C 3C01C1A0 */  lui       $at, 0xc1a0
/* C32540 80241060 44812000 */  mtc1      $at, $f4
/* C32544 80241064 2402000F */  addiu     $v0, $zero, 0xf
/* C32548 80241068 AFA2001C */  sw        $v0, 0x1c($sp)
/* C3254C 8024106C 44833000 */  mtc1      $v1, $f6
/* C32550 80241070 00000000 */  nop
/* C32554 80241074 468031A0 */  cvt.s.w   $f6, $f6
/* C32558 80241078 44073000 */  mfc1      $a3, $f6
/* C3255C 8024107C 27A20028 */  addiu     $v0, $sp, 0x28
/* C32560 80241080 AFA20020 */  sw        $v0, 0x20($sp)
/* C32564 80241084 E7A00010 */  swc1      $f0, 0x10($sp)
/* C32568 80241088 E7A20014 */  swc1      $f2, 0x14($sp)
/* C3256C 8024108C 0C01BFA4 */  jal       fx_emote
/* C32570 80241090 E7A40018 */   swc1     $f4, 0x18($sp)
/* C32574 80241094 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C32578 80241098 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C3257C 8024109C C60C0038 */  lwc1      $f12, 0x38($s0)
/* C32580 802410A0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C32584 802410A4 8C460028 */  lw        $a2, 0x28($v0)
/* C32588 802410A8 0C00A720 */  jal       atan2
/* C3258C 802410AC 8C470030 */   lw       $a3, 0x30($v0)
/* C32590 802410B0 0200202D */  daddu     $a0, $s0, $zero
/* C32594 802410B4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* C32598 802410B8 3C060020 */  lui       $a2, 0x20
/* C3259C 802410BC 0C012530 */  jal       func_800494C0
/* C325A0 802410C0 E480000C */   swc1     $f0, 0xc($a0)
/* C325A4 802410C4 8E220018 */  lw        $v0, 0x18($s1)
/* C325A8 802410C8 9442002A */  lhu       $v0, 0x2a($v0)
/* C325AC 802410CC 30420001 */  andi      $v0, $v0, 1
/* C325B0 802410D0 14400029 */  bnez      $v0, .L80241178
/* C325B4 802410D4 2402000A */   addiu    $v0, $zero, 0xa
/* C325B8 802410D8 0809045E */  j         .L80241178
/* C325BC 802410DC 2402000C */   addiu    $v0, $zero, 0xc
.L802410E0:
/* C325C0 802410E0 8602008C */  lh        $v0, 0x8c($s0)
/* C325C4 802410E4 14400025 */  bnez      $v0, .L8024117C
/* C325C8 802410E8 00000000 */   nop
/* C325CC 802410EC 9602008E */  lhu       $v0, 0x8e($s0)
/* C325D0 802410F0 2442FFFF */  addiu     $v0, $v0, -1
/* C325D4 802410F4 A602008E */  sh        $v0, 0x8e($s0)
/* C325D8 802410F8 00021400 */  sll       $v0, $v0, 0x10
/* C325DC 802410FC 1440001F */  bnez      $v0, .L8024117C
/* C325E0 80241100 00000000 */   nop
/* C325E4 80241104 8E820074 */  lw        $v0, 0x74($s4)
/* C325E8 80241108 2442FFFF */  addiu     $v0, $v0, -1
/* C325EC 8024110C 10400019 */  beqz      $v0, .L80241174
/* C325F0 80241110 AE820074 */   sw       $v0, 0x74($s4)
/* C325F4 80241114 8E220018 */  lw        $v0, 0x18($s1)
/* C325F8 80241118 9442002A */  lhu       $v0, 0x2a($v0)
/* C325FC 8024111C 30420010 */  andi      $v0, $v0, 0x10
/* C32600 80241120 14400007 */  bnez      $v0, .L80241140
/* C32604 80241124 00000000 */   nop
/* C32608 80241128 C600000C */  lwc1      $f0, 0xc($s0)
/* C3260C 8024112C 3C014334 */  lui       $at, 0x4334
/* C32610 80241130 44816000 */  mtc1      $at, $f12
/* C32614 80241134 0C00A6C9 */  jal       clamp_angle
/* C32618 80241138 460C0300 */   add.s    $f12, $f0, $f12
/* C3261C 8024113C E600000C */  swc1      $f0, 0xc($s0)
.L80241140:
/* C32620 80241140 8E440008 */  lw        $a0, 8($s2)
/* C32624 80241144 000417C2 */  srl       $v0, $a0, 0x1f
/* C32628 80241148 00822021 */  addu      $a0, $a0, $v0
/* C3262C 8024114C 00042043 */  sra       $a0, $a0, 1
/* C32630 80241150 0C00A67F */  jal       rand_int
/* C32634 80241154 24840001 */   addiu    $a0, $a0, 1
/* C32638 80241158 8E430008 */  lw        $v1, 8($s2)
/* C3263C 8024115C 000327C2 */  srl       $a0, $v1, 0x1f
/* C32640 80241160 00641821 */  addu      $v1, $v1, $a0
/* C32644 80241164 00031843 */  sra       $v1, $v1, 1
/* C32648 80241168 00621821 */  addu      $v1, $v1, $v0
/* C3264C 8024116C 0809045F */  j         .L8024117C
/* C32650 80241170 A603008E */   sh       $v1, 0x8e($s0)
.L80241174:
/* C32654 80241174 24020004 */  addiu     $v0, $zero, 4
.L80241178:
/* C32658 80241178 AE820070 */  sw        $v0, 0x70($s4)
.L8024117C:
/* C3265C 8024117C 8FBF0044 */  lw        $ra, 0x44($sp)
/* C32660 80241180 8FB40040 */  lw        $s4, 0x40($sp)
/* C32664 80241184 8FB3003C */  lw        $s3, 0x3c($sp)
/* C32668 80241188 8FB20038 */  lw        $s2, 0x38($sp)
/* C3266C 8024118C 8FB10034 */  lw        $s1, 0x34($sp)
/* C32670 80241190 8FB00030 */  lw        $s0, 0x30($sp)
/* C32674 80241194 03E00008 */  jr        $ra
/* C32678 80241198 27BD0048 */   addiu    $sp, $sp, 0x48
