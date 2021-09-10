.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802410B0_D7DC00
/* D7DC00 802410B0 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* D7DC04 802410B4 AFB00030 */  sw        $s0, 0x30($sp)
/* D7DC08 802410B8 0080802D */  daddu     $s0, $a0, $zero
/* D7DC0C 802410BC 0000202D */  daddu     $a0, $zero, $zero
/* D7DC10 802410C0 3C05FD05 */  lui       $a1, 0xfd05
/* D7DC14 802410C4 34A50F80 */  ori       $a1, $a1, 0xf80
/* D7DC18 802410C8 AFBF003C */  sw        $ra, 0x3c($sp)
/* D7DC1C 802410CC AFB20038 */  sw        $s2, 0x38($sp)
/* D7DC20 802410D0 0C0B1EAF */  jal       evt_get_variable
/* D7DC24 802410D4 AFB10034 */   sw       $s1, 0x34($sp)
/* D7DC28 802410D8 0040902D */  daddu     $s2, $v0, $zero
/* D7DC2C 802410DC 2A420100 */  slti      $v0, $s2, 0x100
/* D7DC30 802410E0 10400017 */  beqz      $v0, .L80241140
/* D7DC34 802410E4 00101040 */   sll      $v0, $s0, 1
/* D7DC38 802410E8 00508821 */  addu      $s1, $v0, $s0
/* D7DC3C 802410EC 0220202D */  daddu     $a0, $s1, $zero
/* D7DC40 802410F0 27A50018 */  addiu     $a1, $sp, 0x18
/* D7DC44 802410F4 27A6001C */  addiu     $a2, $sp, 0x1c
/* D7DC48 802410F8 27B00020 */  addiu     $s0, $sp, 0x20
/* D7DC4C 802410FC 0C0470AC */  jal       mdl_get_copied_vertices
/* D7DC50 80241100 0200382D */   daddu    $a3, $s0, $zero
/* D7DC54 80241104 26240001 */  addiu     $a0, $s1, 1
/* D7DC58 80241108 27A50024 */  addiu     $a1, $sp, 0x24
/* D7DC5C 8024110C 27A60028 */  addiu     $a2, $sp, 0x28
/* D7DC60 80241110 0C0470AC */  jal       mdl_get_copied_vertices
/* D7DC64 80241114 0200382D */   daddu    $a3, $s0, $zero
/* D7DC68 80241118 8FA40024 */  lw        $a0, 0x24($sp)
/* D7DC6C 8024111C 8FA50018 */  lw        $a1, 0x18($sp)
/* D7DC70 80241120 8FA6001C */  lw        $a2, 0x1c($sp)
/* D7DC74 80241124 8FA70020 */  lw        $a3, 0x20($sp)
/* D7DC78 80241128 0C0903C8 */  jal       func_80240F20_D7DA70
/* D7DC7C 8024112C AFB20010 */   sw       $s2, 0x10($sp)
/* D7DC80 80241130 12400022 */  beqz      $s2, .L802411BC
/* D7DC84 80241134 00000000 */   nop
/* D7DC88 80241138 08090464 */  j         .L80241190
/* D7DC8C 8024113C 00000000 */   nop
.L80241140:
/* D7DC90 80241140 00108840 */  sll       $s1, $s0, 1
/* D7DC94 80241144 02308821 */  addu      $s1, $s1, $s0
/* D7DC98 80241148 0220202D */  daddu     $a0, $s1, $zero
/* D7DC9C 8024114C 27A50018 */  addiu     $a1, $sp, 0x18
/* D7DCA0 80241150 27A6001C */  addiu     $a2, $sp, 0x1c
/* D7DCA4 80241154 27B00020 */  addiu     $s0, $sp, 0x20
/* D7DCA8 80241158 0C0470AC */  jal       mdl_get_copied_vertices
/* D7DCAC 8024115C 0200382D */   daddu    $a3, $s0, $zero
/* D7DCB0 80241160 26240002 */  addiu     $a0, $s1, 2
/* D7DCB4 80241164 27A50024 */  addiu     $a1, $sp, 0x24
/* D7DCB8 80241168 27A60028 */  addiu     $a2, $sp, 0x28
/* D7DCBC 8024116C 0C0470AC */  jal       mdl_get_copied_vertices
/* D7DCC0 80241170 0200382D */   daddu    $a3, $s0, $zero
/* D7DCC4 80241174 8FA40018 */  lw        $a0, 0x18($sp)
/* D7DCC8 80241178 8FA50024 */  lw        $a1, 0x24($sp)
/* D7DCCC 8024117C 8FA6001C */  lw        $a2, 0x1c($sp)
/* D7DCD0 80241180 8FA70020 */  lw        $a3, 0x20($sp)
/* D7DCD4 80241184 2642FF00 */  addiu     $v0, $s2, -0x100
/* D7DCD8 80241188 0C0903C8 */  jal       func_80240F20_D7DA70
/* D7DCDC 8024118C AFA20010 */   sw       $v0, 0x10($sp)
.L80241190:
/* D7DCE0 80241190 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* D7DCE4 80241194 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* D7DCE8 80241198 8C620000 */  lw        $v0, ($v1)
/* D7DCEC 8024119C 0220202D */  daddu     $a0, $s1, $zero
/* D7DCF0 802411A0 0040802D */  daddu     $s0, $v0, $zero
/* D7DCF4 802411A4 24420008 */  addiu     $v0, $v0, 8
/* D7DCF8 802411A8 AC620000 */  sw        $v0, ($v1)
/* D7DCFC 802411AC 3C02DE00 */  lui       $v0, 0xde00
/* D7DD00 802411B0 0C0470BB */  jal       mdl_get_copied_gfx
/* D7DD04 802411B4 AE020000 */   sw       $v0, ($s0)
/* D7DD08 802411B8 AE020004 */  sw        $v0, 4($s0)
.L802411BC:
/* D7DD0C 802411BC 8FBF003C */  lw        $ra, 0x3c($sp)
/* D7DD10 802411C0 8FB20038 */  lw        $s2, 0x38($sp)
/* D7DD14 802411C4 8FB10034 */  lw        $s1, 0x34($sp)
/* D7DD18 802411C8 8FB00030 */  lw        $s0, 0x30($sp)
/* D7DD1C 802411CC 03E00008 */  jr        $ra
/* D7DD20 802411D0 27BD0040 */   addiu    $sp, $sp, 0x40
