.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241750_B2DBC0
/* B2DBC0 80241750 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* B2DBC4 80241754 AFB10024 */  sw        $s1, 0x24($sp)
/* B2DBC8 80241758 0080882D */  daddu     $s1, $a0, $zero
/* B2DBCC 8024175C 3C05F840 */  lui       $a1, 0xf840
/* B2DBD0 80241760 AFBF0044 */  sw        $ra, 0x44($sp)
/* B2DBD4 80241764 AFBE0040 */  sw        $fp, 0x40($sp)
/* B2DBD8 80241768 AFB7003C */  sw        $s7, 0x3c($sp)
/* B2DBDC 8024176C AFB60038 */  sw        $s6, 0x38($sp)
/* B2DBE0 80241770 AFB50034 */  sw        $s5, 0x34($sp)
/* B2DBE4 80241774 AFB40030 */  sw        $s4, 0x30($sp)
/* B2DBE8 80241778 AFB3002C */  sw        $s3, 0x2c($sp)
/* B2DBEC 8024177C AFB20028 */  sw        $s2, 0x28($sp)
/* B2DBF0 80241780 AFB00020 */  sw        $s0, 0x20($sp)
/* B2DBF4 80241784 8E3E0148 */  lw        $fp, 0x148($s1)
/* B2DBF8 80241788 0C0B1EAF */  jal       evt_get_variable
/* B2DBFC 8024178C 34A56268 */   ori      $a1, $a1, 0x6268
/* B2DC00 80241790 0040802D */  daddu     $s0, $v0, $zero
/* B2DC04 80241794 0220202D */  daddu     $a0, $s1, $zero
/* B2DC08 80241798 3C05F840 */  lui       $a1, 0xf840
/* B2DC0C 8024179C 0C0B1EAF */  jal       evt_get_variable
/* B2DC10 802417A0 34A56269 */   ori      $a1, $a1, 0x6269
/* B2DC14 802417A4 0040B82D */  daddu     $s7, $v0, $zero
/* B2DC18 802417A8 0220202D */  daddu     $a0, $s1, $zero
/* B2DC1C 802417AC 3C05F5DE */  lui       $a1, 0xf5de
/* B2DC20 802417B0 0C0B1EAF */  jal       evt_get_variable
/* B2DC24 802417B4 34A502DE */   ori      $a1, $a1, 0x2de
/* B2DC28 802417B8 0040B02D */  daddu     $s6, $v0, $zero
/* B2DC2C 802417BC 0220202D */  daddu     $a0, $s1, $zero
/* B2DC30 802417C0 3C05F5DE */  lui       $a1, 0xf5de
/* B2DC34 802417C4 0C0B1EAF */  jal       evt_get_variable
/* B2DC38 802417C8 34A502DF */   ori      $a1, $a1, 0x2df
/* B2DC3C 802417CC 0040A82D */  daddu     $s5, $v0, $zero
/* B2DC40 802417D0 93D3006D */  lbu       $s3, 0x6d($fp)
/* B2DC44 802417D4 32C2FFFF */  andi      $v0, $s6, 0xffff
/* B2DC48 802417D8 A7B30010 */  sh        $s3, 0x10($sp)
/* B2DC4C 802417DC 93D2006E */  lbu       $s2, 0x6e($fp)
/* B2DC50 802417E0 93C7006F */  lbu       $a3, 0x6f($fp)
/* B2DC54 802417E4 3274FFFF */  andi      $s4, $s3, 0xffff
/* B2DC58 802417E8 12820003 */  beq       $s4, $v0, .L802417F8
/* B2DC5C 802417EC A7A7001E */   sh       $a3, 0x1e($sp)
/* B2DC60 802417F0 0000B82D */  daddu     $s7, $zero, $zero
/* B2DC64 802417F4 02E0802D */  daddu     $s0, $s7, $zero
.L802417F8:
/* B2DC68 802417F8 3202FFFF */  andi      $v0, $s0, 0xffff
/* B2DC6C 802417FC 14400016 */  bnez      $v0, .L80241858
/* B2DC70 80241800 0220202D */   daddu    $a0, $s1, $zero
/* B2DC74 80241804 0C00A67F */  jal       rand_int
/* B2DC78 80241808 24040064 */   addiu    $a0, $zero, 0x64
/* B2DC7C 8024180C 2842001E */  slti      $v0, $v0, 0x1e
/* B2DC80 80241810 10400011 */  beqz      $v0, .L80241858
/* B2DC84 80241814 0220202D */   daddu    $a0, $s1, $zero
/* B2DC88 80241818 0C00A67F */  jal       rand_int
/* B2DC8C 8024181C 2644FFFF */   addiu    $a0, $s2, -1
/* B2DC90 80241820 0040A82D */  daddu     $s5, $v0, $zero
/* B2DC94 80241824 0260B02D */  daddu     $s6, $s3, $zero
/* B2DC98 80241828 0220202D */  daddu     $a0, $s1, $zero
/* B2DC9C 8024182C 3C05F5DE */  lui       $a1, 0xf5de
/* B2DCA0 80241830 34A502DE */  ori       $a1, $a1, 0x2de
/* B2DCA4 80241834 0C0B2026 */  jal       evt_set_variable
/* B2DCA8 80241838 0280302D */   daddu    $a2, $s4, $zero
/* B2DCAC 8024183C 0220202D */  daddu     $a0, $s1, $zero
/* B2DCB0 80241840 3C05F5DE */  lui       $a1, 0xf5de
/* B2DCB4 80241844 34A502DF */  ori       $a1, $a1, 0x2df
/* B2DCB8 80241848 0C0B2026 */  jal       evt_set_variable
/* B2DCBC 8024184C 32A6FFFF */   andi     $a2, $s5, 0xffff
/* B2DCC0 80241850 24100001 */  addiu     $s0, $zero, 1
/* B2DCC4 80241854 0220202D */  daddu     $a0, $s1, $zero
.L80241858:
/* B2DCC8 80241858 3C05F840 */  lui       $a1, 0xf840
/* B2DCCC 8024185C 34A56268 */  ori       $a1, $a1, 0x6268
/* B2DCD0 80241860 0C0B2026 */  jal       evt_set_variable
/* B2DCD4 80241864 3206FFFF */   andi     $a2, $s0, 0xffff
/* B2DCD8 80241868 0220202D */  daddu     $a0, $s1, $zero
/* B2DCDC 8024186C 3C05F840 */  lui       $a1, 0xf840
/* B2DCE0 80241870 34A56269 */  ori       $a1, $a1, 0x6269
/* B2DCE4 80241874 0C0B2026 */  jal       evt_set_variable
/* B2DCE8 80241878 32E6FFFF */   andi     $a2, $s7, 0xffff
/* B2DCEC 8024187C 0000202D */  daddu     $a0, $zero, $zero
/* B2DCF0 80241880 3C05F5DE */  lui       $a1, 0xf5de
/* B2DCF4 80241884 0C0B1EAF */  jal       evt_get_variable
/* B2DCF8 80241888 34A502E0 */   ori      $a1, $a1, 0x2e0
/* B2DCFC 8024188C 0000202D */  daddu     $a0, $zero, $zero
/* B2DD00 80241890 3C05F5DE */  lui       $a1, 0xf5de
/* B2DD04 80241894 34A50180 */  ori       $a1, $a1, 0x180
/* B2DD08 80241898 0C0B1EAF */  jal       evt_get_variable
/* B2DD0C 8024189C 0040802D */   daddu    $s0, $v0, $zero
/* B2DD10 802418A0 0040282D */  daddu     $a1, $v0, $zero
/* B2DD14 802418A4 0000182D */  daddu     $v1, $zero, $zero
/* B2DD18 802418A8 3C068024 */  lui       $a2, %hi(D_80243288_B2F6F8)
/* B2DD1C 802418AC 24C63288 */  addiu     $a2, $a2, %lo(D_80243288_B2F6F8)
/* B2DD20 802418B0 00C0202D */  daddu     $a0, $a2, $zero
.L802418B4:
/* B2DD24 802418B4 8C820000 */  lw        $v0, ($a0)
/* B2DD28 802418B8 00A2102A */  slt       $v0, $a1, $v0
/* B2DD2C 802418BC 14400006 */  bnez      $v0, .L802418D8
/* B2DD30 802418C0 000310C0 */   sll      $v0, $v1, 3
/* B2DD34 802418C4 24630001 */  addiu     $v1, $v1, 1
/* B2DD38 802418C8 28620008 */  slti      $v0, $v1, 8
/* B2DD3C 802418CC 1440FFF9 */  bnez      $v0, .L802418B4
/* B2DD40 802418D0 24840008 */   addiu    $a0, $a0, 8
/* B2DD44 802418D4 000310C0 */  sll       $v0, $v1, 3
.L802418D8:
/* B2DD48 802418D8 00461021 */  addu      $v0, $v0, $a2
/* B2DD4C 802418DC 8C420004 */  lw        $v0, 4($v0)
/* B2DD50 802418E0 97A30010 */  lhu       $v1, 0x10($sp)
/* B2DD54 802418E4 0202202A */  slt       $a0, $s0, $v0
/* B2DD58 802418E8 32C2FFFF */  andi      $v0, $s6, 0xffff
/* B2DD5C 802418EC 14620008 */  bne       $v1, $v0, .L80241910
/* B2DD60 802418F0 32A2FFFF */   andi     $v0, $s5, 0xffff
/* B2DD64 802418F4 97A7001E */  lhu       $a3, 0x1e($sp)
/* B2DD68 802418F8 14E20005 */  bne       $a3, $v0, .L80241910
/* B2DD6C 802418FC 32E2FFFF */   andi     $v0, $s7, 0xffff
/* B2DD70 80241900 14400003 */  bnez      $v0, .L80241910
/* B2DD74 80241904 00000000 */   nop
/* B2DD78 80241908 14800008 */  bnez      $a0, .L8024192C
/* B2DD7C 8024190C 24020001 */   addiu    $v0, $zero, 1
.L80241910:
/* B2DD80 80241910 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B2DD84 80241914 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B2DD88 80241918 80420075 */  lb        $v0, 0x75($v0)
/* B2DD8C 8024191C 10400005 */  beqz      $v0, .L80241934
/* B2DD90 80241920 00000000 */   nop
/* B2DD94 80241924 10800003 */  beqz      $a0, .L80241934
/* B2DD98 80241928 24020001 */   addiu    $v0, $zero, 1
.L8024192C:
/* B2DD9C 8024192C 08090650 */  j         .L80241940
/* B2DDA0 80241930 AE220084 */   sw       $v0, 0x84($s1)
.L80241934:
/* B2DDA4 80241934 0C00F9EB */  jal       kill_enemy
/* B2DDA8 80241938 03C0202D */   daddu    $a0, $fp, $zero
/* B2DDAC 8024193C AE200084 */  sw        $zero, 0x84($s1)
.L80241940:
/* B2DDB0 80241940 8FBF0044 */  lw        $ra, 0x44($sp)
/* B2DDB4 80241944 8FBE0040 */  lw        $fp, 0x40($sp)
/* B2DDB8 80241948 8FB7003C */  lw        $s7, 0x3c($sp)
/* B2DDBC 8024194C 8FB60038 */  lw        $s6, 0x38($sp)
/* B2DDC0 80241950 8FB50034 */  lw        $s5, 0x34($sp)
/* B2DDC4 80241954 8FB40030 */  lw        $s4, 0x30($sp)
/* B2DDC8 80241958 8FB3002C */  lw        $s3, 0x2c($sp)
/* B2DDCC 8024195C 8FB20028 */  lw        $s2, 0x28($sp)
/* B2DDD0 80241960 8FB10024 */  lw        $s1, 0x24($sp)
/* B2DDD4 80241964 8FB00020 */  lw        $s0, 0x20($sp)
/* B2DDD8 80241968 24020002 */  addiu     $v0, $zero, 2
/* B2DDDC 8024196C 03E00008 */  jr        $ra
/* B2DDE0 80241970 27BD0048 */   addiu    $sp, $sp, 0x48
