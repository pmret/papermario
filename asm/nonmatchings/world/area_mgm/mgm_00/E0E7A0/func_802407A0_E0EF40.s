.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407A0_E0EF40
/* E0EF40 802407A0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* E0EF44 802407A4 AFB40040 */  sw        $s4, 0x40($sp)
/* E0EF48 802407A8 0080A02D */  daddu     $s4, $a0, $zero
/* E0EF4C 802407AC AFBF0044 */  sw        $ra, 0x44($sp)
/* E0EF50 802407B0 AFB3003C */  sw        $s3, 0x3c($sp)
/* E0EF54 802407B4 AFB20038 */  sw        $s2, 0x38($sp)
/* E0EF58 802407B8 AFB10034 */  sw        $s1, 0x34($sp)
/* E0EF5C 802407BC AFB00030 */  sw        $s0, 0x30($sp)
/* E0EF60 802407C0 8E910148 */  lw        $s1, 0x148($s4)
/* E0EF64 802407C4 00A0902D */  daddu     $s2, $a1, $zero
/* E0EF68 802407C8 86240008 */  lh        $a0, 8($s1)
/* E0EF6C 802407CC 0C00EABB */  jal       get_npc_unsafe
/* E0EF70 802407D0 00C0982D */   daddu    $s3, $a2, $zero
/* E0EF74 802407D4 8E430014 */  lw        $v1, 0x14($s2)
/* E0EF78 802407D8 04600031 */  bltz      $v1, .L802408A0
/* E0EF7C 802407DC 0040802D */   daddu    $s0, $v0, $zero
/* E0EF80 802407E0 0260202D */  daddu     $a0, $s3, $zero
/* E0EF84 802407E4 AFA00010 */  sw        $zero, 0x10($sp)
/* E0EF88 802407E8 8E460024 */  lw        $a2, 0x24($s2)
/* E0EF8C 802407EC 8E470028 */  lw        $a3, 0x28($s2)
/* E0EF90 802407F0 0C01242D */  jal       func_800490B4
/* E0EF94 802407F4 0220282D */   daddu    $a1, $s1, $zero
/* E0EF98 802407F8 10400029 */  beqz      $v0, .L802408A0
/* E0EF9C 802407FC 0000202D */   daddu    $a0, $zero, $zero
/* E0EFA0 80240800 0200282D */  daddu     $a1, $s0, $zero
/* E0EFA4 80240804 0000302D */  daddu     $a2, $zero, $zero
/* E0EFA8 80240808 860300A8 */  lh        $v1, 0xa8($s0)
/* E0EFAC 8024080C 3C013F80 */  lui       $at, 0x3f80
/* E0EFB0 80240810 44810000 */  mtc1      $at, $f0
/* E0EFB4 80240814 3C014000 */  lui       $at, 0x4000
/* E0EFB8 80240818 44811000 */  mtc1      $at, $f2
/* E0EFBC 8024081C 3C01C1A0 */  lui       $at, 0xc1a0
/* E0EFC0 80240820 44812000 */  mtc1      $at, $f4
/* E0EFC4 80240824 2402000F */  addiu     $v0, $zero, 0xf
/* E0EFC8 80240828 AFA2001C */  sw        $v0, 0x1c($sp)
/* E0EFCC 8024082C 44833000 */  mtc1      $v1, $f6
/* E0EFD0 80240830 00000000 */  nop       
/* E0EFD4 80240834 468031A0 */  cvt.s.w   $f6, $f6
/* E0EFD8 80240838 44073000 */  mfc1      $a3, $f6
/* E0EFDC 8024083C 27A20028 */  addiu     $v0, $sp, 0x28
/* E0EFE0 80240840 AFA20020 */  sw        $v0, 0x20($sp)
/* E0EFE4 80240844 E7A00010 */  swc1      $f0, 0x10($sp)
/* E0EFE8 80240848 E7A20014 */  swc1      $f2, 0x14($sp)
/* E0EFEC 8024084C 0C01BFA4 */  jal       fx_emote
/* E0EFF0 80240850 E7A40018 */   swc1     $f4, 0x18($sp)
/* E0EFF4 80240854 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* E0EFF8 80240858 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* E0EFFC 8024085C C60C0038 */  lwc1      $f12, 0x38($s0)
/* E0F000 80240860 C60E0040 */  lwc1      $f14, 0x40($s0)
/* E0F004 80240864 8C460028 */  lw        $a2, 0x28($v0)
/* E0F008 80240868 0C00A720 */  jal       atan2
/* E0F00C 8024086C 8C470030 */   lw       $a3, 0x30($v0)
/* E0F010 80240870 0200202D */  daddu     $a0, $s0, $zero
/* E0F014 80240874 240502F4 */  addiu     $a1, $zero, 0x2f4
/* E0F018 80240878 3C060020 */  lui       $a2, 0x20
/* E0F01C 8024087C 0C012530 */  jal       func_800494C0
/* E0F020 80240880 E480000C */   swc1     $f0, 0xc($a0)
/* E0F024 80240884 8E220018 */  lw        $v0, 0x18($s1)
/* E0F028 80240888 9442002A */  lhu       $v0, 0x2a($v0)
/* E0F02C 8024088C 30420001 */  andi      $v0, $v0, 1
/* E0F030 80240890 14400029 */  bnez      $v0, .L80240938
/* E0F034 80240894 2402000A */   addiu    $v0, $zero, 0xa
/* E0F038 80240898 0809024E */  j         .L80240938
/* E0F03C 8024089C 2402000C */   addiu    $v0, $zero, 0xc
.L802408A0:
/* E0F040 802408A0 8602008C */  lh        $v0, 0x8c($s0)
/* E0F044 802408A4 14400025 */  bnez      $v0, .L8024093C
/* E0F048 802408A8 00000000 */   nop      
/* E0F04C 802408AC 9602008E */  lhu       $v0, 0x8e($s0)
/* E0F050 802408B0 2442FFFF */  addiu     $v0, $v0, -1
/* E0F054 802408B4 A602008E */  sh        $v0, 0x8e($s0)
/* E0F058 802408B8 00021400 */  sll       $v0, $v0, 0x10
/* E0F05C 802408BC 1440001F */  bnez      $v0, .L8024093C
/* E0F060 802408C0 00000000 */   nop      
/* E0F064 802408C4 8E820074 */  lw        $v0, 0x74($s4)
/* E0F068 802408C8 2442FFFF */  addiu     $v0, $v0, -1
/* E0F06C 802408CC 10400019 */  beqz      $v0, .L80240934
/* E0F070 802408D0 AE820074 */   sw       $v0, 0x74($s4)
/* E0F074 802408D4 8E220018 */  lw        $v0, 0x18($s1)
/* E0F078 802408D8 9442002A */  lhu       $v0, 0x2a($v0)
/* E0F07C 802408DC 30420010 */  andi      $v0, $v0, 0x10
/* E0F080 802408E0 14400007 */  bnez      $v0, .L80240900
/* E0F084 802408E4 00000000 */   nop      
/* E0F088 802408E8 C600000C */  lwc1      $f0, 0xc($s0)
/* E0F08C 802408EC 3C014334 */  lui       $at, 0x4334
/* E0F090 802408F0 44816000 */  mtc1      $at, $f12
/* E0F094 802408F4 0C00A6C9 */  jal       clamp_angle
/* E0F098 802408F8 460C0300 */   add.s    $f12, $f0, $f12
/* E0F09C 802408FC E600000C */  swc1      $f0, 0xc($s0)
.L80240900:
/* E0F0A0 80240900 8E440008 */  lw        $a0, 8($s2)
/* E0F0A4 80240904 000417C2 */  srl       $v0, $a0, 0x1f
/* E0F0A8 80240908 00822021 */  addu      $a0, $a0, $v0
/* E0F0AC 8024090C 00042043 */  sra       $a0, $a0, 1
/* E0F0B0 80240910 0C00A67F */  jal       rand_int
/* E0F0B4 80240914 24840001 */   addiu    $a0, $a0, 1
/* E0F0B8 80240918 8E430008 */  lw        $v1, 8($s2)
/* E0F0BC 8024091C 000327C2 */  srl       $a0, $v1, 0x1f
/* E0F0C0 80240920 00641821 */  addu      $v1, $v1, $a0
/* E0F0C4 80240924 00031843 */  sra       $v1, $v1, 1
/* E0F0C8 80240928 00621821 */  addu      $v1, $v1, $v0
/* E0F0CC 8024092C 0809024F */  j         .L8024093C
/* E0F0D0 80240930 A603008E */   sh       $v1, 0x8e($s0)
.L80240934:
/* E0F0D4 80240934 24020004 */  addiu     $v0, $zero, 4
.L80240938:
/* E0F0D8 80240938 AE820070 */  sw        $v0, 0x70($s4)
.L8024093C:
/* E0F0DC 8024093C 8FBF0044 */  lw        $ra, 0x44($sp)
/* E0F0E0 80240940 8FB40040 */  lw        $s4, 0x40($sp)
/* E0F0E4 80240944 8FB3003C */  lw        $s3, 0x3c($sp)
/* E0F0E8 80240948 8FB20038 */  lw        $s2, 0x38($sp)
/* E0F0EC 8024094C 8FB10034 */  lw        $s1, 0x34($sp)
/* E0F0F0 80240950 8FB00030 */  lw        $s0, 0x30($sp)
/* E0F0F4 80240954 03E00008 */  jr        $ra
/* E0F0F8 80240958 27BD0048 */   addiu    $sp, $sp, 0x48
