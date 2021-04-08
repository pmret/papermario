.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BBE70_E307C0
/* E307C0 802BBE70 27BDFEE8 */  addiu     $sp, $sp, -0x118
/* E307C4 802BBE74 AFB000F0 */  sw        $s0, 0xf0($sp)
/* E307C8 802BBE78 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* E307CC 802BBE7C 8E10A66C */  lw        $s0, %lo(gMasterGfxPos)($s0)
/* E307D0 802BBE80 AFBF0114 */  sw        $ra, 0x114($sp)
/* E307D4 802BBE84 AFBE0110 */  sw        $fp, 0x110($sp)
/* E307D8 802BBE88 AFB7010C */  sw        $s7, 0x10c($sp)
/* E307DC 802BBE8C AFB60108 */  sw        $s6, 0x108($sp)
/* E307E0 802BBE90 AFB50104 */  sw        $s5, 0x104($sp)
/* E307E4 802BBE94 AFB40100 */  sw        $s4, 0x100($sp)
/* E307E8 802BBE98 AFB300FC */  sw        $s3, 0xfc($sp)
/* E307EC 802BBE9C AFB200F8 */  sw        $s2, 0xf8($sp)
/* E307F0 802BBEA0 0C04417A */  jal       get_entity_by_index
/* E307F4 802BBEA4 AFB100F4 */   sw       $s1, 0xf4($sp)
/* E307F8 802BBEA8 0040902D */  daddu     $s2, $v0, $zero
/* E307FC 802BBEAC 8E530040 */  lw        $s3, 0x40($s2)
/* E30800 802BBEB0 27A40010 */  addiu     $a0, $sp, 0x10
/* E30804 802BBEB4 0C019D28 */  jal       guMtxIdentF
/* E30808 802BBEB8 AFB30090 */   sw       $s3, 0x90($sp)
/* E3080C 802BBEBC 27B10050 */  addiu     $s1, $sp, 0x50
/* E30810 802BBEC0 0220202D */  daddu     $a0, $s1, $zero
/* E30814 802BBEC4 3C140001 */  lui       $s4, 1
/* E30818 802BBEC8 8E450048 */  lw        $a1, 0x48($s2)
/* E3081C 802BBECC 8E660010 */  lw        $a2, 0x10($s3)
/* E30820 802BBED0 8E470050 */  lw        $a3, 0x50($s2)
/* E30824 802BBED4 36941630 */  ori       $s4, $s4, 0x1630
/* E30828 802BBED8 0C019E40 */  jal       guTranslateF
/* E3082C 802BBEDC AFB40094 */   sw       $s4, 0x94($sp)
/* E30830 802BBEE0 0220202D */  daddu     $a0, $s1, $zero
/* E30834 802BBEE4 27A50010 */  addiu     $a1, $sp, 0x10
/* E30838 802BBEE8 0C019D80 */  jal       guMtxCatF
/* E3083C 802BBEEC 0220302D */   daddu    $a2, $s1, $zero
/* E30840 802BBEF0 0220202D */  daddu     $a0, $s1, $zero
/* E30844 802BBEF4 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* E30848 802BBEF8 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* E3084C 802BBEFC 96250000 */  lhu       $a1, ($s1)
/* E30850 802BBF00 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* E30854 802BBF04 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* E30858 802BBF08 00052980 */  sll       $a1, $a1, 6
/* E3085C 802BBF0C 00B42821 */  addu      $a1, $a1, $s4
/* E30860 802BBF10 0C019D40 */  jal       guMtxF2L
/* E30864 802BBF14 00452821 */   addu     $a1, $v0, $a1
/* E30868 802BBF18 0200202D */  daddu     $a0, $s0, $zero
/* E3086C 802BBF1C 26100008 */  addiu     $s0, $s0, 8
/* E30870 802BBF20 3C03DA38 */  lui       $v1, 0xda38
/* E30874 802BBF24 34630002 */  ori       $v1, $v1, 2
/* E30878 802BBF28 0200A82D */  daddu     $s5, $s0, $zero
/* E3087C 802BBF2C 26100008 */  addiu     $s0, $s0, 8
/* E30880 802BBF30 0200C02D */  daddu     $t8, $s0, $zero
/* E30884 802BBF34 26100008 */  addiu     $s0, $s0, 8
/* E30888 802BBF38 3C13D838 */  lui       $s3, 0xd838
/* E3088C 802BBF3C 36730002 */  ori       $s3, $s3, 2
/* E30890 802BBF40 0200B02D */  daddu     $s6, $s0, $zero
/* E30894 802BBF44 26100008 */  addiu     $s0, $s0, 8
/* E30898 802BBF48 0200C82D */  daddu     $t9, $s0, $zero
/* E3089C 802BBF4C 26100008 */  addiu     $s0, $s0, 8
/* E308A0 802BBF50 3C14E300 */  lui       $s4, 0xe300
/* E308A4 802BBF54 36941001 */  ori       $s4, $s4, 0x1001
/* E308A8 802BBF58 0200F02D */  daddu     $fp, $s0, $zero
/* E308AC 802BBF5C 26100008 */  addiu     $s0, $s0, 8
/* E308B0 802BBF60 AFB000E8 */  sw        $s0, 0xe8($sp)
/* E308B4 802BBF64 26100008 */  addiu     $s0, $s0, 8
/* E308B8 802BBF68 AFB000A0 */  sw        $s0, 0xa0($sp)
/* E308BC 802BBF6C 26100008 */  addiu     $s0, $s0, 8
/* E308C0 802BBF70 AFB30098 */  sw        $s3, 0x98($sp)
/* E308C4 802BBF74 3C13F500 */  lui       $s3, 0xf500
/* E308C8 802BBF78 36730100 */  ori       $s3, $s3, 0x100
/* E308CC 802BBF7C AFB000A8 */  sw        $s0, 0xa8($sp)
/* E308D0 802BBF80 26100008 */  addiu     $s0, $s0, 8
/* E308D4 802BBF84 AFB000AC */  sw        $s0, 0xac($sp)
/* E308D8 802BBF88 26100008 */  addiu     $s0, $s0, 8
/* E308DC 802BBF8C AFB4009C */  sw        $s4, 0x9c($sp)
/* E308E0 802BBF90 3C140703 */  lui       $s4, 0x703
/* E308E4 802BBF94 3694C000 */  ori       $s4, $s4, 0xc000
/* E308E8 802BBF98 AFB000EC */  sw        $s0, 0xec($sp)
/* E308EC 802BBF9C 26100008 */  addiu     $s0, $s0, 8
/* E308F0 802BBFA0 AFB000B4 */  sw        $s0, 0xb4($sp)
/* E308F4 802BBFA4 26100008 */  addiu     $s0, $s0, 8
/* E308F8 802BBFA8 AFB300A4 */  sw        $s3, 0xa4($sp)
/* E308FC 802BBFAC 3C13D700 */  lui       $s3, 0xd700
/* E30900 802BBFB0 36730002 */  ori       $s3, $s3, 2
/* E30904 802BBFB4 0200B82D */  daddu     $s7, $s0, $zero
/* E30908 802BBFB8 26100008 */  addiu     $s0, $s0, 8
/* E3090C 802BBFBC AFB400B0 */  sw        $s4, 0xb0($sp)
/* E30910 802BBFC0 3C14FC12 */  lui       $s4, 0xfc12
/* E30914 802BBFC4 36941824 */  ori       $s4, $s4, 0x1824
/* E30918 802BBFC8 AFB300B8 */  sw        $s3, 0xb8($sp)
/* E3091C 802BBFCC 3C13FF33 */  lui       $s3, 0xff33
/* E30920 802BBFD0 3673FFFF */  ori       $s3, $s3, 0xffff
/* E30924 802BBFD4 0200782D */  daddu     $t7, $s0, $zero
/* E30928 802BBFD8 26100008 */  addiu     $s0, $s0, 8
/* E3092C 802BBFDC AFB400BC */  sw        $s4, 0xbc($sp)
/* E30930 802BBFE0 3C14E300 */  lui       $s4, 0xe300
/* E30934 802BBFE4 36940D01 */  ori       $s4, $s4, 0xd01
/* E30938 802BBFE8 0200582D */  daddu     $t3, $s0, $zero
/* E3093C 802BBFEC 26100008 */  addiu     $s0, $s0, 8
/* E30940 802BBFF0 AFB300C0 */  sw        $s3, 0xc0($sp)
/* E30944 802BBFF4 3C13E300 */  lui       $s3, 0xe300
/* E30948 802BBFF8 36730F00 */  ori       $s3, $s3, 0xf00
/* E3094C 802BBFFC 0200602D */  daddu     $t4, $s0, $zero
/* E30950 802BC000 26100008 */  addiu     $s0, $s0, 8
/* E30954 802BC004 0200702D */  daddu     $t6, $s0, $zero
/* E30958 802BC008 26100008 */  addiu     $s0, $s0, 8
/* E3095C 802BC00C AFB400C4 */  sw        $s4, 0xc4($sp)
/* E30960 802BC010 3C140701 */  lui       $s4, 0x701
/* E30964 802BC014 36944170 */  ori       $s4, $s4, 0x4170
/* E30968 802BC018 0200502D */  daddu     $t2, $s0, $zero
/* E3096C 802BC01C 26100008 */  addiu     $s0, $s0, 8
/* E30970 802BC020 0200682D */  daddu     $t5, $s0, $zero
/* E30974 802BC024 26100008 */  addiu     $s0, $s0, 8
/* E30978 802BC028 AFB300C8 */  sw        $s3, 0xc8($sp)
/* E3097C 802BC02C 3C13073F */  lui       $s3, 0x73f
/* E30980 802BC030 3673F100 */  ori       $s3, $s3, 0xf100
/* E30984 802BC034 0200402D */  daddu     $t0, $s0, $zero
/* E30988 802BC038 AFB400CC */  sw        $s4, 0xcc($sp)
/* E3098C 802BC03C 3C14F540 */  lui       $s4, 0xf540
/* E30990 802BC040 36941000 */  ori       $s4, $s4, 0x1000
/* E30994 802BC044 AFB300D0 */  sw        $s3, 0xd0($sp)
/* E30998 802BC048 3C130001 */  lui       $s3, 1
/* E3099C 802BC04C 36734170 */  ori       $s3, $s3, 0x4170
/* E309A0 802BC050 AFB400D4 */  sw        $s4, 0xd4($sp)
/* E309A4 802BC054 3C14001F */  lui       $s4, 0x1f
/* E309A8 802BC058 3694C07C */  ori       $s4, $s4, 0xc07c
/* E309AC 802BC05C AFB300D8 */  sw        $s3, 0xd8($sp)
/* E309B0 802BC060 3C13E300 */  lui       $s3, 0xe300
/* E309B4 802BC064 36730C00 */  ori       $s3, $s3, 0xc00
/* E309B8 802BC068 AFB400DC */  sw        $s4, 0xdc($sp)
/* E309BC 802BC06C 3C14E300 */  lui       $s4, 0xe300
/* E309C0 802BC070 AFB300E0 */  sw        $s3, 0xe0($sp)
/* E309C4 802BC074 96220000 */  lhu       $v0, ($s1)
/* E309C8 802BC078 36941201 */  ori       $s4, $s4, 0x1201
/* E309CC 802BC07C AFB400E4 */  sw        $s4, 0xe4($sp)
/* E309D0 802BC080 AC830000 */  sw        $v1, ($a0)
/* E309D4 802BC084 24430001 */  addiu     $v1, $v0, 1
/* E309D8 802BC088 3042FFFF */  andi      $v0, $v0, 0xffff
/* E309DC 802BC08C 00021180 */  sll       $v0, $v0, 6
/* E309E0 802BC090 A6230000 */  sh        $v1, ($s1)
/* E309E4 802BC094 8FB30094 */  lw        $s3, 0x94($sp)
/* E309E8 802BC098 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* E309EC 802BC09C 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* E309F0 802BC0A0 00531021 */  addu      $v0, $v0, $s3
/* E309F4 802BC0A4 00621821 */  addu      $v1, $v1, $v0
/* E309F8 802BC0A8 3C02DE00 */  lui       $v0, 0xde00
/* E309FC 802BC0AC AC830004 */  sw        $v1, 4($a0)
/* E30A00 802BC0B0 AEA20000 */  sw        $v0, ($s5)
/* E30A04 802BC0B4 3C020A00 */  lui       $v0, 0xa00
/* E30A08 802BC0B8 24421148 */  addiu     $v0, $v0, 0x1148
/* E30A0C 802BC0BC 8E430044 */  lw        $v1, 0x44($s2)
/* E30A10 802BC0C0 3042FFFF */  andi      $v0, $v0, 0xffff
/* E30A14 802BC0C4 00621821 */  addu      $v1, $v1, $v0
/* E30A18 802BC0C8 24020040 */  addiu     $v0, $zero, 0x40
/* E30A1C 802BC0CC AEA30004 */  sw        $v1, 4($s5)
/* E30A20 802BC0D0 8FB40098 */  lw        $s4, 0x98($sp)
/* E30A24 802BC0D4 3C03E700 */  lui       $v1, 0xe700
/* E30A28 802BC0D8 AF140000 */  sw        $s4, ($t8)
/* E30A2C 802BC0DC AF020004 */  sw        $v0, 4($t8)
/* E30A30 802BC0E0 AEC30000 */  sw        $v1, ($s6)
/* E30A34 802BC0E4 AEC00004 */  sw        $zero, 4($s6)
/* E30A38 802BC0E8 8FB3009C */  lw        $s3, 0x9c($sp)
/* E30A3C 802BC0EC 34028000 */  ori       $v0, $zero, 0x8000
/* E30A40 802BC0F0 AF330000 */  sw        $s3, ($t9)
/* E30A44 802BC0F4 AF220004 */  sw        $v0, 4($t9)
/* E30A48 802BC0F8 3C02FD10 */  lui       $v0, 0xfd10
/* E30A4C 802BC0FC AFC20000 */  sw        $v0, ($fp)
/* E30A50 802BC100 3C020A00 */  lui       $v0, 0xa00
/* E30A54 802BC104 24420D08 */  addiu     $v0, $v0, 0xd08
/* E30A58 802BC108 AFC20004 */  sw        $v0, 4($fp)
/* E30A5C 802BC10C 8FB400E8 */  lw        $s4, 0xe8($sp)
/* E30A60 802BC110 3C02E800 */  lui       $v0, 0xe800
/* E30A64 802BC114 AE820000 */  sw        $v0, ($s4)
/* E30A68 802BC118 AE800004 */  sw        $zero, 4($s4)
/* E30A6C 802BC11C 8FB400A4 */  lw        $s4, 0xa4($sp)
/* E30A70 802BC120 8FB300A0 */  lw        $s3, 0xa0($sp)
/* E30A74 802BC124 3C020700 */  lui       $v0, 0x700
/* E30A78 802BC128 AE740000 */  sw        $s4, ($s3)
/* E30A7C 802BC12C AE620004 */  sw        $v0, 4($s3)
/* E30A80 802BC130 8FB300A8 */  lw        $s3, 0xa8($sp)
/* E30A84 802BC134 3C04E600 */  lui       $a0, 0xe600
/* E30A88 802BC138 AE640000 */  sw        $a0, ($s3)
/* E30A8C 802BC13C AE600004 */  sw        $zero, 4($s3)
/* E30A90 802BC140 8FB400AC */  lw        $s4, 0xac($sp)
/* E30A94 802BC144 3C02F000 */  lui       $v0, 0xf000
/* E30A98 802BC148 AE820000 */  sw        $v0, ($s4)
/* E30A9C 802BC14C 8FB300B0 */  lw        $s3, 0xb0($sp)
/* E30AA0 802BC150 26100008 */  addiu     $s0, $s0, 8
/* E30AA4 802BC154 AE930004 */  sw        $s3, 4($s4)
/* E30AA8 802BC158 8FB400EC */  lw        $s4, 0xec($sp)
/* E30AAC 802BC15C 0200482D */  daddu     $t1, $s0, $zero
/* E30AB0 802BC160 AE830000 */  sw        $v1, ($s4)
/* E30AB4 802BC164 AE800004 */  sw        $zero, 4($s4)
/* E30AB8 802BC168 8FB400B8 */  lw        $s4, 0xb8($sp)
/* E30ABC 802BC16C 8FB300B4 */  lw        $s3, 0xb4($sp)
/* E30AC0 802BC170 2402FFFF */  addiu     $v0, $zero, -1
/* E30AC4 802BC174 AE740000 */  sw        $s4, ($s3)
/* E30AC8 802BC178 AE620004 */  sw        $v0, 4($s3)
/* E30ACC 802BC17C 8FB300BC */  lw        $s3, 0xbc($sp)
/* E30AD0 802BC180 26100008 */  addiu     $s0, $s0, 8
/* E30AD4 802BC184 AEF30000 */  sw        $s3, ($s7)
/* E30AD8 802BC188 8FB400C0 */  lw        $s4, 0xc0($sp)
/* E30ADC 802BC18C 0200382D */  daddu     $a3, $s0, $zero
/* E30AE0 802BC190 AEF40004 */  sw        $s4, 4($s7)
/* E30AE4 802BC194 8FB300C4 */  lw        $s3, 0xc4($sp)
/* E30AE8 802BC198 26100008 */  addiu     $s0, $s0, 8
/* E30AEC 802BC19C ADF30000 */  sw        $s3, ($t7)
/* E30AF0 802BC1A0 ADE00004 */  sw        $zero, 4($t7)
/* E30AF4 802BC1A4 8FB400C8 */  lw        $s4, 0xc8($sp)
/* E30AF8 802BC1A8 3C02FD50 */  lui       $v0, 0xfd50
/* E30AFC 802BC1AC AD740000 */  sw        $s4, ($t3)
/* E30B00 802BC1B0 AD600004 */  sw        $zero, 4($t3)
/* E30B04 802BC1B4 AD820000 */  sw        $v0, ($t4)
/* E30B08 802BC1B8 3C020A00 */  lui       $v0, 0xa00
/* E30B0C 802BC1BC 24420508 */  addiu     $v0, $v0, 0x508
/* E30B10 802BC1C0 AD820004 */  sw        $v0, 4($t4)
/* E30B14 802BC1C4 3C02F550 */  lui       $v0, 0xf550
/* E30B18 802BC1C8 ADC20000 */  sw        $v0, ($t6)
/* E30B1C 802BC1CC 8FB300CC */  lw        $s3, 0xcc($sp)
/* E30B20 802BC1D0 3C02F300 */  lui       $v0, 0xf300
/* E30B24 802BC1D4 ADD30004 */  sw        $s3, 4($t6)
/* E30B28 802BC1D8 AD440000 */  sw        $a0, ($t2)
/* E30B2C 802BC1DC AD400004 */  sw        $zero, 4($t2)
/* E30B30 802BC1E0 ADA20000 */  sw        $v0, ($t5)
/* E30B34 802BC1E4 8FB400D0 */  lw        $s4, 0xd0($sp)
/* E30B38 802BC1E8 0200302D */  daddu     $a2, $s0, $zero
/* E30B3C 802BC1EC ADB40004 */  sw        $s4, 4($t5)
/* E30B40 802BC1F0 AD030000 */  sw        $v1, ($t0)
/* E30B44 802BC1F4 AD000004 */  sw        $zero, 4($t0)
/* E30B48 802BC1F8 8FB300D4 */  lw        $s3, 0xd4($sp)
/* E30B4C 802BC1FC 26100008 */  addiu     $s0, $s0, 8
/* E30B50 802BC200 AD330000 */  sw        $s3, ($t1)
/* E30B54 802BC204 8FB400D8 */  lw        $s4, 0xd8($sp)
/* E30B58 802BC208 3C03F200 */  lui       $v1, 0xf200
/* E30B5C 802BC20C AD340004 */  sw        $s4, 4($t1)
/* E30B60 802BC210 ACE30000 */  sw        $v1, ($a3)
/* E30B64 802BC214 8FB300DC */  lw        $s3, 0xdc($sp)
/* E30B68 802BC218 0200282D */  daddu     $a1, $s0, $zero
/* E30B6C 802BC21C ACF30004 */  sw        $s3, 4($a3)
/* E30B70 802BC220 8FB400E0 */  lw        $s4, 0xe0($sp)
/* E30B74 802BC224 3C020008 */  lui       $v0, 8
/* E30B78 802BC228 ACD40000 */  sw        $s4, ($a2)
/* E30B7C 802BC22C ACC20004 */  sw        $v0, 4($a2)
/* E30B80 802BC230 8FB300E4 */  lw        $s3, 0xe4($sp)
/* E30B84 802BC234 24022000 */  addiu     $v0, $zero, 0x2000
/* E30B88 802BC238 ACB30000 */  sw        $s3, ($a1)
/* E30B8C 802BC23C ACA20004 */  sw        $v0, 4($a1)
/* E30B90 802BC240 8FB40090 */  lw        $s4, 0x90($sp)
/* E30B94 802BC244 26100008 */  addiu     $s0, $s0, 8
/* E30B98 802BC248 82820005 */  lb        $v0, 5($s4)
/* E30B9C 802BC24C 0200202D */  daddu     $a0, $s0, $zero
/* E30BA0 802BC250 00021080 */  sll       $v0, $v0, 2
/* E30BA4 802BC254 30420FFF */  andi      $v0, $v0, 0xfff
/* E30BA8 802BC258 00021300 */  sll       $v0, $v0, 0xc
/* E30BAC 802BC25C 00431025 */  or        $v0, $v0, $v1
/* E30BB0 802BC260 AC820000 */  sw        $v0, ($a0)
/* E30BB4 802BC264 82820005 */  lb        $v0, 5($s4)
/* E30BB8 802BC268 26100008 */  addiu     $s0, $s0, 8
/* E30BBC 802BC26C 3C01800A */  lui       $at, %hi(gMasterGfxPos)
/* E30BC0 802BC270 AC30A66C */  sw        $s0, %lo(gMasterGfxPos)($at)
/* E30BC4 802BC274 2442007C */  addiu     $v0, $v0, 0x7c
/* E30BC8 802BC278 00021080 */  sll       $v0, $v0, 2
/* E30BCC 802BC27C 30420FFF */  andi      $v0, $v0, 0xfff
/* E30BD0 802BC280 00021300 */  sll       $v0, $v0, 0xc
/* E30BD4 802BC284 3442007C */  ori       $v0, $v0, 0x7c
/* E30BD8 802BC288 AC820004 */  sw        $v0, 4($a0)
/* E30BDC 802BC28C 8FBF0114 */  lw        $ra, 0x114($sp)
/* E30BE0 802BC290 8FBE0110 */  lw        $fp, 0x110($sp)
/* E30BE4 802BC294 8FB7010C */  lw        $s7, 0x10c($sp)
/* E30BE8 802BC298 8FB60108 */  lw        $s6, 0x108($sp)
/* E30BEC 802BC29C 8FB50104 */  lw        $s5, 0x104($sp)
/* E30BF0 802BC2A0 8FB40100 */  lw        $s4, 0x100($sp)
/* E30BF4 802BC2A4 8FB300FC */  lw        $s3, 0xfc($sp)
/* E30BF8 802BC2A8 8FB200F8 */  lw        $s2, 0xf8($sp)
/* E30BFC 802BC2AC 8FB100F4 */  lw        $s1, 0xf4($sp)
/* E30C00 802BC2B0 8FB000F0 */  lw        $s0, 0xf0($sp)
/* E30C04 802BC2B4 03E00008 */  jr        $ra
/* E30C08 802BC2B8 27BD0118 */   addiu    $sp, $sp, 0x118
