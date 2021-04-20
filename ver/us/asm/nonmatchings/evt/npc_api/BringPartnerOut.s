.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel BringPartnerOut
/* F3F68 802CF5B8 27BDFF98 */  addiu     $sp, $sp, -0x68
/* F3F6C 802CF5BC AFB10024 */  sw        $s1, 0x24($sp)
/* F3F70 802CF5C0 AFB20028 */  sw        $s2, 0x28($sp)
/* F3F74 802CF5C4 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* F3F78 802CF5C8 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* F3F7C 802CF5CC AFBF0034 */  sw        $ra, 0x34($sp)
/* F3F80 802CF5D0 AFB40030 */  sw        $s4, 0x30($sp)
/* F3F84 802CF5D4 AFB3002C */  sw        $s3, 0x2c($sp)
/* F3F88 802CF5D8 AFB00020 */  sw        $s0, 0x20($sp)
/* F3F8C 802CF5DC F7BE0060 */  sdc1      $f30, 0x60($sp)
/* F3F90 802CF5E0 F7BC0058 */  sdc1      $f28, 0x58($sp)
/* F3F94 802CF5E4 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* F3F98 802CF5E8 F7B80048 */  sdc1      $f24, 0x48($sp)
/* F3F9C 802CF5EC F7B60040 */  sdc1      $f22, 0x40($sp)
/* F3FA0 802CF5F0 F7B40038 */  sdc1      $f20, 0x38($sp)
/* F3FA4 802CF5F4 8C82000C */  lw        $v0, 0xc($a0)
/* F3FA8 802CF5F8 10A00089 */  beqz      $a1, .L802CF820
/* F3FAC 802CF5FC 27B10010 */   addiu    $s1, $sp, 0x10
/* F3FB0 802CF600 8C450000 */  lw        $a1, ($v0)
/* F3FB4 802CF604 0C0B1EAF */  jal       get_variable
/* F3FB8 802CF608 00000000 */   nop
/* F3FBC 802CF60C 3C038011 */  lui       $v1, %hi(gPlayerData)
/* F3FC0 802CF610 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* F3FC4 802CF614 80630012 */  lb        $v1, 0x12($v1)
/* F3FC8 802CF618 3C14802E */  lui       $s4, %hi(D_802DAE40)
/* F3FCC 802CF61C 2694AE40 */  addiu     $s4, $s4, %lo(D_802DAE40)
/* F3FD0 802CF620 14620004 */  bne       $v1, $v0, .L802CF634
/* F3FD4 802CF624 AE820000 */   sw       $v0, ($s4)
/* F3FD8 802CF628 AE800000 */  sw        $zero, ($s4)
/* F3FDC 802CF62C 080B3E54 */  j         .L802CF950
/* F3FE0 802CF630 24020002 */   addiu    $v0, $zero, 2
.L802CF634:
/* F3FE4 802CF634 0C00EABB */  jal       get_npc_unsafe
/* F3FE8 802CF638 2404FFFC */   addiu    $a0, $zero, -4
/* F3FEC 802CF63C 0040802D */  daddu     $s0, $v0, $zero
/* F3FF0 802CF640 2402FFFB */  addiu     $v0, $zero, -5
/* F3FF4 802CF644 A20200A4 */  sb        $v0, 0xa4($s0)
/* F3FF8 802CF648 8E830000 */  lw        $v1, ($s4)
/* F3FFC 802CF64C 24020100 */  addiu     $v0, $zero, 0x100
/* F4000 802CF650 AFA20010 */  sw        $v0, 0x10($sp)
/* F4004 802CF654 000310C0 */  sll       $v0, $v1, 3
/* F4008 802CF658 00431021 */  addu      $v0, $v0, $v1
/* F400C 802CF65C 00021080 */  sll       $v0, $v0, 2
/* F4010 802CF660 3C018010 */  lui       $at, %hi(gPartnerAnimations+0x10)
/* F4014 802CF664 00220821 */  addu      $at, $at, $v0
/* F4018 802CF668 8C228358 */  lw        $v0, %lo(gPartnerAnimations+0x10)($at)
/* F401C 802CF66C 0220202D */  daddu     $a0, $s1, $zero
/* F4020 802CF670 AFA00018 */  sw        $zero, 0x18($sp)
/* F4024 802CF674 AFA0001C */  sw        $zero, 0x1c($sp)
/* F4028 802CF678 0C00E211 */  jal       npc_create_basic
/* F402C 802CF67C AFA20014 */   sw       $v0, 0x14($sp)
/* F4030 802CF680 0040202D */  daddu     $a0, $v0, $zero
/* F4034 802CF684 3C01802E */  lui       $at, %hi(D_802DAE44)
/* F4038 802CF688 AC24AE44 */  sw        $a0, %lo(D_802DAE44)($at)
/* F403C 802CF68C 0C00E2B7 */  jal       get_npc_by_index
/* F4040 802CF690 2413000A */   addiu    $s3, $zero, 0xa
/* F4044 802CF694 0040882D */  daddu     $s1, $v0, $zero
/* F4048 802CF698 2402FFFC */  addiu     $v0, $zero, -4
/* F404C 802CF69C A63300A6 */  sh        $s3, 0xa6($s1)
/* F4050 802CF6A0 A63300A8 */  sh        $s3, 0xa8($s1)
/* F4054 802CF6A4 A22200A4 */  sb        $v0, 0xa4($s1)
/* F4058 802CF6A8 AE200054 */  sw        $zero, 0x54($s1)
/* F405C 802CF6AC AE200058 */  sw        $zero, 0x58($s1)
/* F4060 802CF6B0 AE20005C */  sw        $zero, 0x5c($s1)
/* F4064 802CF6B4 C61A0038 */  lwc1      $f26, 0x38($s0)
/* F4068 802CF6B8 3C0141F0 */  lui       $at, 0x41f0
/* F406C 802CF6BC 44810000 */  mtc1      $at, $f0
/* F4070 802CF6C0 E63A0060 */  swc1      $f26, 0x60($s1)
/* F4074 802CF6C4 C65E002C */  lwc1      $f30, 0x2c($s2)
/* F4078 802CF6C8 E63E0064 */  swc1      $f30, 0x64($s1)
/* F407C 802CF6CC C6160040 */  lwc1      $f22, 0x40($s0)
/* F4080 802CF6D0 4600B580 */  add.s     $f22, $f22, $f0
/* F4084 802CF6D4 4406D000 */  mfc1      $a2, $f26
/* F4088 802CF6D8 E6360068 */  swc1      $f22, 0x68($s1)
/* F408C 802CF6DC C6580028 */  lwc1      $f24, 0x28($s2)
/* F4090 802CF6E0 4407B000 */  mfc1      $a3, $f22
/* F4094 802CF6E4 E6380038 */  swc1      $f24, 0x38($s1)
/* F4098 802CF6E8 964200B0 */  lhu       $v0, 0xb0($s2)
/* F409C 802CF6EC C642002C */  lwc1      $f2, 0x2c($s2)
/* F40A0 802CF6F0 00021400 */  sll       $v0, $v0, 0x10
/* F40A4 802CF6F4 00021C03 */  sra       $v1, $v0, 0x10
/* F40A8 802CF6F8 000217C2 */  srl       $v0, $v0, 0x1f
/* F40AC 802CF6FC 00621821 */  addu      $v1, $v1, $v0
/* F40B0 802CF700 00031843 */  sra       $v1, $v1, 1
/* F40B4 802CF704 44830000 */  mtc1      $v1, $f0
/* F40B8 802CF708 00000000 */  nop
/* F40BC 802CF70C 46800020 */  cvt.s.w   $f0, $f0
/* F40C0 802CF710 46001700 */  add.s     $f28, $f2, $f0
/* F40C4 802CF714 3C014080 */  lui       $at, 0x4080
/* F40C8 802CF718 44810000 */  mtc1      $at, $f0
/* F40CC 802CF71C 3C013FCC */  lui       $at, 0x3fcc
/* F40D0 802CF720 3421CCCD */  ori       $at, $at, 0xcccd
/* F40D4 802CF724 44811000 */  mtc1      $at, $f2
/* F40D8 802CF728 E63C003C */  swc1      $f28, 0x3c($s1)
/* F40DC 802CF72C C6540030 */  lwc1      $f20, 0x30($s2)
/* F40E0 802CF730 4600C306 */  mov.s     $f12, $f24
/* F40E4 802CF734 E6200018 */  swc1      $f0, 0x18($s1)
/* F40E8 802CF738 E6220014 */  swc1      $f2, 0x14($s1)
/* F40EC 802CF73C 4600A386 */  mov.s     $f14, $f20
/* F40F0 802CF740 0C00A7B5 */  jal       dist2D
/* F40F4 802CF744 E6340040 */   swc1     $f20, 0x40($s1)
/* F40F8 802CF748 4600C306 */  mov.s     $f12, $f24
/* F40FC 802CF74C 4406D000 */  mfc1      $a2, $f26
/* F4100 802CF750 4407B000 */  mfc1      $a3, $f22
/* F4104 802CF754 4600A386 */  mov.s     $f14, $f20
/* F4108 802CF758 0C00A720 */  jal       atan2
/* F410C 802CF75C E6200010 */   swc1     $f0, 0x10($s1)
/* F4110 802CF760 C6220010 */  lwc1      $f2, 0x10($s1)
/* F4114 802CF764 C6240018 */  lwc1      $f4, 0x18($s1)
/* F4118 802CF768 3C108010 */  lui       $s0, %hi(gPartnerAnimations)
/* F411C 802CF76C 26108348 */  addiu     $s0, $s0, %lo(gPartnerAnimations)
/* F4120 802CF770 E620000C */  swc1      $f0, 0xc($s1)
/* F4124 802CF774 46041083 */  div.s     $f2, $f2, $f4
/* F4128 802CF778 4600118D */  trunc.w.s $f6, $f2
/* F412C 802CF77C 44023000 */  mfc1      $v0, $f6
/* F4130 802CF780 00000000 */  nop
/* F4134 802CF784 A622008E */  sh        $v0, 0x8e($s1)
/* F4138 802CF788 00021400 */  sll       $v0, $v0, 0x10
/* F413C 802CF78C 00021403 */  sra       $v0, $v0, 0x10
/* F4140 802CF790 2842000A */  slti      $v0, $v0, 0xa
/* F4144 802CF794 10400007 */  beqz      $v0, .L802CF7B4
/* F4148 802CF798 00000000 */   nop
/* F414C 802CF79C 3C014120 */  lui       $at, 0x4120
/* F4150 802CF7A0 44811000 */  mtc1      $at, $f2
/* F4154 802CF7A4 C6200010 */  lwc1      $f0, 0x10($s1)
/* F4158 802CF7A8 A633008E */  sh        $s3, 0x8e($s1)
/* F415C 802CF7AC 46020003 */  div.s     $f0, $f0, $f2
/* F4160 802CF7B0 E6200018 */  swc1      $f0, 0x18($s1)
.L802CF7B4:
/* F4164 802CF7B4 8622008E */  lh        $v0, 0x8e($s1)
/* F4168 802CF7B8 C6200014 */  lwc1      $f0, 0x14($s1)
/* F416C 802CF7BC 44822000 */  mtc1      $v0, $f4
/* F4170 802CF7C0 00000000 */  nop
/* F4174 802CF7C4 46802120 */  cvt.s.w   $f4, $f4
/* F4178 802CF7C8 46040002 */  mul.s     $f0, $f0, $f4
/* F417C 802CF7CC 00000000 */  nop
/* F4180 802CF7D0 46040002 */  mul.s     $f0, $f0, $f4
/* F4184 802CF7D4 00000000 */  nop
/* F4188 802CF7D8 3C013F00 */  lui       $at, 0x3f00
/* F418C 802CF7DC 44811000 */  mtc1      $at, $f2
/* F4190 802CF7E0 00000000 */  nop
/* F4194 802CF7E4 46020002 */  mul.s     $f0, $f0, $f2
/* F4198 802CF7E8 00000000 */  nop
/* F419C 802CF7EC 8E830000 */  lw        $v1, ($s4)
/* F41A0 802CF7F0 461CF081 */  sub.s     $f2, $f30, $f28
/* F41A4 802CF7F4 000310C0 */  sll       $v0, $v1, 3
/* F41A8 802CF7F8 00431021 */  addu      $v0, $v0, $v1
/* F41AC 802CF7FC 46001080 */  add.s     $f2, $f2, $f0
/* F41B0 802CF800 00021080 */  sll       $v0, $v0, 2
/* F41B4 802CF804 00501021 */  addu      $v0, $v0, $s0
/* F41B8 802CF808 46041083 */  div.s     $f2, $f2, $f4
/* F41BC 802CF80C E622001C */  swc1      $f2, 0x1c($s1)
/* F41C0 802CF810 8C430004 */  lw        $v1, 4($v0)
/* F41C4 802CF814 0000102D */  daddu     $v0, $zero, $zero
/* F41C8 802CF818 080B3E54 */  j         .L802CF950
/* F41CC 802CF81C AE230028 */   sw       $v1, 0x28($s1)
.L802CF820:
/* F41D0 802CF820 3C04802E */  lui       $a0, %hi(D_802DAE44)
/* F41D4 802CF824 8C84AE44 */  lw        $a0, %lo(D_802DAE44)($a0)
/* F41D8 802CF828 0C00E2B7 */  jal       get_npc_by_index
/* F41DC 802CF82C 00000000 */   nop
/* F41E0 802CF830 0040882D */  daddu     $s1, $v0, $zero
/* F41E4 802CF834 C620001C */  lwc1      $f0, 0x1c($s1)
/* F41E8 802CF838 C6220014 */  lwc1      $f2, 0x14($s1)
/* F41EC 802CF83C 46020001 */  sub.s     $f0, $f0, $f2
/* F41F0 802CF840 C622003C */  lwc1      $f2, 0x3c($s1)
/* F41F4 802CF844 46001080 */  add.s     $f2, $f2, $f0
/* F41F8 802CF848 4480A000 */  mtc1      $zero, $f20
/* F41FC 802CF84C 00000000 */  nop
/* F4200 802CF850 4614003E */  c.le.s    $f0, $f20
/* F4204 802CF854 E620001C */  swc1      $f0, 0x1c($s1)
/* F4208 802CF858 4500000A */  bc1f      .L802CF884
/* F420C 802CF85C E622003C */   swc1     $f2, 0x3c($s1)
/* F4210 802CF860 3C02802E */  lui       $v0, %hi(D_802DAE40)
/* F4214 802CF864 8C42AE40 */  lw        $v0, %lo(D_802DAE40)($v0)
/* F4218 802CF868 000218C0 */  sll       $v1, $v0, 3
/* F421C 802CF86C 00621821 */  addu      $v1, $v1, $v0
/* F4220 802CF870 00031880 */  sll       $v1, $v1, 2
/* F4224 802CF874 3C028010 */  lui       $v0, %hi(gPartnerAnimations+0x8)
/* F4228 802CF878 00431021 */  addu      $v0, $v0, $v1
/* F422C 802CF87C 8C428350 */  lw        $v0, %lo(gPartnerAnimations+0x8)($v0)
/* F4230 802CF880 AE220028 */  sw        $v0, 0x28($s1)
.L802CF884:
/* F4234 802CF884 8E250018 */  lw        $a1, 0x18($s1)
/* F4238 802CF888 8E26000C */  lw        $a2, 0xc($s1)
/* F423C 802CF88C 0C00EA95 */  jal       npc_move_heading
/* F4240 802CF890 0220202D */   daddu    $a0, $s1, $zero
/* F4244 802CF894 8622008E */  lh        $v0, 0x8e($s1)
/* F4248 802CF898 3C014120 */  lui       $at, 0x4120
/* F424C 802CF89C 44811000 */  mtc1      $at, $f2
/* F4250 802CF8A0 44820000 */  mtc1      $v0, $f0
/* F4254 802CF8A4 00000000 */  nop
/* F4258 802CF8A8 46800020 */  cvt.s.w   $f0, $f0
/* F425C 802CF8AC 4600103C */  c.lt.s    $f2, $f0
/* F4260 802CF8B0 00000000 */  nop
/* F4264 802CF8B4 45030001 */  bc1tl     .L802CF8BC
/* F4268 802CF8B8 46001006 */   mov.s    $f0, $f2
.L802CF8BC:
/* F426C 802CF8BC 9622008E */  lhu       $v0, 0x8e($s1)
/* F4270 802CF8C0 46001001 */  sub.s     $f0, $f2, $f0
/* F4274 802CF8C4 2442FFFF */  addiu     $v0, $v0, -1
/* F4278 802CF8C8 A622008E */  sh        $v0, 0x8e($s1)
/* F427C 802CF8CC 00021400 */  sll       $v0, $v0, 0x10
/* F4280 802CF8D0 46020003 */  div.s     $f0, $f0, $f2
/* F4284 802CF8D4 E6200054 */  swc1      $f0, 0x54($s1)
/* F4288 802CF8D8 46000086 */  mov.s     $f2, $f0
/* F428C 802CF8DC E6200058 */  swc1      $f0, 0x58($s1)
/* F4290 802CF8E0 04400003 */  bltz      $v0, .L802CF8F0
/* F4294 802CF8E4 E622005C */   swc1     $f2, 0x5c($s1)
/* F4298 802CF8E8 080B3E54 */  j         .L802CF950
/* F429C 802CF8EC 0000102D */   daddu    $v0, $zero, $zero
.L802CF8F0:
/* F42A0 802CF8F0 3C03802E */  lui       $v1, %hi(D_802DAE40)
/* F42A4 802CF8F4 8C63AE40 */  lw        $v1, %lo(D_802DAE40)($v1)
/* F42A8 802CF8F8 C6240064 */  lwc1      $f4, 0x64($s1)
/* F42AC 802CF8FC C622000C */  lwc1      $f2, 0xc($s1)
/* F42B0 802CF900 3C014334 */  lui       $at, 0x4334
/* F42B4 802CF904 44816000 */  mtc1      $at, $f12
/* F42B8 802CF908 3C013F80 */  lui       $at, 0x3f80
/* F42BC 802CF90C 44810000 */  mtc1      $at, $f0
/* F42C0 802CF910 000310C0 */  sll       $v0, $v1, 3
/* F42C4 802CF914 00431021 */  addu      $v0, $v0, $v1
/* F42C8 802CF918 00021080 */  sll       $v0, $v0, 2
/* F42CC 802CF91C 3C018010 */  lui       $at, %hi(gPartnerAnimations+0x14)
/* F42D0 802CF920 00220821 */  addu      $at, $at, $v0
/* F42D4 802CF924 8C22835C */  lw        $v0, %lo(gPartnerAnimations+0x14)($at)
/* F42D8 802CF928 460C1300 */  add.s     $f12, $f2, $f12
/* F42DC 802CF92C E634001C */  swc1      $f20, 0x1c($s1)
/* F42E0 802CF930 E624003C */  swc1      $f4, 0x3c($s1)
/* F42E4 802CF934 E6200054 */  swc1      $f0, 0x54($s1)
/* F42E8 802CF938 E6200058 */  swc1      $f0, 0x58($s1)
/* F42EC 802CF93C E620005C */  swc1      $f0, 0x5c($s1)
/* F42F0 802CF940 0C00A6C9 */  jal       clamp_angle
/* F42F4 802CF944 AE220028 */   sw       $v0, 0x28($s1)
/* F42F8 802CF948 24020002 */  addiu     $v0, $zero, 2
/* F42FC 802CF94C E620000C */  swc1      $f0, 0xc($s1)
.L802CF950:
/* F4300 802CF950 8FBF0034 */  lw        $ra, 0x34($sp)
/* F4304 802CF954 8FB40030 */  lw        $s4, 0x30($sp)
/* F4308 802CF958 8FB3002C */  lw        $s3, 0x2c($sp)
/* F430C 802CF95C 8FB20028 */  lw        $s2, 0x28($sp)
/* F4310 802CF960 8FB10024 */  lw        $s1, 0x24($sp)
/* F4314 802CF964 8FB00020 */  lw        $s0, 0x20($sp)
/* F4318 802CF968 D7BE0060 */  ldc1      $f30, 0x60($sp)
/* F431C 802CF96C D7BC0058 */  ldc1      $f28, 0x58($sp)
/* F4320 802CF970 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* F4324 802CF974 D7B80048 */  ldc1      $f24, 0x48($sp)
/* F4328 802CF978 D7B60040 */  ldc1      $f22, 0x40($sp)
/* F432C 802CF97C D7B40038 */  ldc1      $f20, 0x38($sp)
/* F4330 802CF980 03E00008 */  jr        $ra
/* F4334 802CF984 27BD0068 */   addiu    $sp, $sp, 0x68
